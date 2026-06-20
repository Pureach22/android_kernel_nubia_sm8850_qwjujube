__int64 __fastcall altmode_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned int v7; // w23
  _QWORD *v8; // x20
  _UNKNOWN **v9; // x23
  __int64 device_by_node; // x0
  __int64 v11; // x0
  void (__fastcall *v12)(_QWORD); // x8
  _QWORD *v13; // x8
  _UNKNOWN **v14; // x9
  const char *v16; // [xsp+0h] [xbp-30h] BYREF
  __int64 v17; // [xsp+8h] [xbp-28h]
  _QWORD *v18; // [xsp+10h] [xbp-20h]
  __int64 (__fastcall *v19)(); // [xsp+18h] [xbp-18h]
  __int64 (__fastcall *v20)(); // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v1 = a1 + 16;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = nullptr;
  v20 = nullptr;
  v17 = 0;
  v18 = nullptr;
  v16 = nullptr;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 384, 3520);
  if ( v3 )
  {
    v4 = v3;
    *v3 = v1;
    _mutex_init(v3 + 5, "&amdev->client_lock", &altmode_probe___key);
    v4[3] = 0;
    v4[4] = 0;
    v4[2] = 0x1000000400000000LL;
    *((_DWORD *)v4 + 86) = 0;
    _init_swait_queue_head(v4 + 44, "&x->wait", &init_completion___key);
    v4[16] = 0xFFFFFFFE00000LL;
    v4[17] = v4 + 17;
    v4[18] = v4 + 17;
    v4[19] = altmode_send_pan_en;
    init_timer_key(v4 + 20, &delayed_work_timer_fn, 0x200000, 0, 0);
    v4[29] = 0xFFFFFFFE00000LL;
    v4[30] = v4 + 30;
    v4[31] = v4 + 30;
    v4[32] = altmode_send_pan_ack;
    init_timer_key(v4 + 33, &delayed_work_timer_fn, 0x200000, 0, 0);
    v4[11] = v4 + 11;
    v4[12] = v4 + 11;
    v4[13] = v4 + 13;
    v4[14] = v4 + 13;
    LODWORD(v17) = 32780;
    v5 = *v4;
    v16 = "altmode";
    v18 = v4;
    v19 = altmode_callback;
    v20 = altmode_state_cb;
    v6 = pmic_glink_register_client(v5, &v16);
    v4[1] = v6;
    if ( v6 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(a1 + 168) = v4;
      altmode_ipc_log = ipc_log_context_create(10, "altmode", 0);
      if ( !altmode_ipc_log )
        dev_warn(v1, "Error in creating ipc_log_context\n");
      mutex_lock(&notify_lock);
      v8 = probe_notify_list;
      if ( probe_notify_list != (_UNKNOWN *)&probe_notify_list )
      {
        do
        {
          v9 = (_UNKNOWN **)*v8;
          device_by_node = of_find_device_by_node(v8[2]);
          if ( device_by_node && *(_QWORD **)(device_by_node + 168) == v4 )
          {
            v12 = (void (__fastcall *)(_QWORD))v8[3];
            v11 = v8[4];
            if ( *((_DWORD *)v12 - 1) != 251140989 )
              __break(0x8228u);
            v12(v11);
            v13 = (_QWORD *)v8[1];
            if ( (_QWORD *)*v13 == v8 && (v14 = (_UNKNOWN **)*v8, *(_QWORD **)(*v8 + 8LL) == v8) )
            {
              v14[1] = v13;
              *v13 = v14;
            }
            else
            {
              _list_del_entry_valid_or_report(v8);
            }
            *v8 = 0xDEAD000000000100LL;
            v8[1] = 0xDEAD000000000122LL;
            kfree(v8);
          }
          v8 = v9;
        }
        while ( v9 != &probe_notify_list );
      }
      mutex_unlock(&notify_lock);
      v7 = 0;
    }
    else
    {
      v7 = v6;
      if ( (_DWORD)v6 != -517 )
        dev_err(v1, "Error in pmic_glink registration: %d\n", v6);
      idr_destroy(v4 + 2);
    }
  }
  else
  {
    v7 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
