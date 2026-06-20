__int64 __fastcall qmi_rmnet_check_stats_2(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x0
  __int64 v9; // x19
  _UNKNOWN **v10; // x21
  __int64 (__fastcall *v11)(_QWORD); // x8
  __int64 qmi_pt; // x0
  __int64 v13; // x0
  __int64 v14; // x20
  _UNKNOWN **v15; // x22
  void (__fastcall *v16)(_QWORD); // x8
  __int64 lock; // x0
  __int64 v18; // x20
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned __int64 v29; // x10
  unsigned __int8 v30[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = a1[13];
  if ( !result )
    goto LABEL_29;
  v31 = 0;
  v32[0] = 0;
  v30[0] = 0;
  result = rmnet_get_qmi_pt(result);
  if ( !result )
    goto LABEL_29;
  v3 = result;
  rmnet_get_packets(a1[13], v32, &v31);
  v4 = v31;
  v5 = v32[0];
  v7 = a1[14];
  v6 = a1[15];
  a1[14] = v32[0];
  a1[15] = v4;
  if ( *(_BYTE *)(v3 + 72) == 1 )
  {
    *(_BYTE *)(v3 + 74) = 0;
    if ( dfc_qmap )
    {
      if ( !(unsigned int)dfc_qmap_set_powersave(0, 0, nullptr) )
        goto LABEL_21;
    }
    else
    {
      qmi_pt = rmnet_get_qmi_pt(a1[13]);
      if ( qmi_pt )
      {
        v13 = *(_QWORD *)(qmi_pt + 8);
        if ( v13 )
        {
          if ( (wda_set_powersave_mode(v13, 0, 0, 0) & 0x80000000) == 0 )
          {
LABEL_21:
            *(_BYTE *)(v3 + 72) = 0;
            if ( (unsigned int)rmnet_get_powersave_notif(a1[13]) )
            {
              v14 = a1[13];
              v15 = (_UNKNOWN **)ps_list;
              if ( ps_list != (_UNKNOWN *)&ps_list )
              {
                do
                {
                  v16 = (void (__fastcall *)(_QWORD))*(v15 - 1);
                  if ( *((_DWORD *)v16 - 1) != 251140989 )
                    __break(0x8228u);
                  v16(v14);
                  v15 = (_UNKNOWN **)*v15;
                }
                while ( v15 != &ps_list );
              }
            }
            goto LABEL_26;
          }
          printk(&unk_2CD5B, "qmi_rmnet_set_powersave_mode");
        }
      }
    }
LABEL_26:
    lock = _rcu_read_lock();
    if ( (rmnet_work_quit & 1) == 0 )
    {
      v18 = rmnet_ps_wq;
      v19 = _msecs_to_jiffies((unsigned int)rmnet_wq_frequency);
      lock = queue_delayed_work_on(32, v18, a1, v19);
    }
    result = _rcu_read_unlock(lock);
    goto LABEL_29;
  }
  if ( v5 != v7 || v4 != v6 )
    goto LABEL_26;
  *(_BYTE *)(v3 + 74) = 1;
  *(_BYTE *)(v3 + 72) = 1;
  rmnet_module_hook_aps_data_inactive();
  _X8 = (unsigned __int64 *)(v3 + 64);
  __asm { PRFM            #0x11, [X8] }
  do
    v29 = __ldxr(_X8);
  while ( __stxr(v29 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  __dmb(0xBu);
  v8 = a1[13];
  v30[0] = 32;
  ps_bearer_id = 0;
  qword_2FD6A = 0;
  qword_2FD72 = 0;
  qword_2FD7A = 0;
  rmnet_prepare_ps_bearers(v8, v30, (__int64)&ps_bearer_id);
  if ( dfc_qmap )
  {
    dfc_qmap_set_powersave(1, v30[0], &ps_bearer_id);
  }
  else
  {
    v20 = v30[0];
    v21 = rmnet_get_qmi_pt(a1[13]);
    if ( v21 )
    {
      v22 = *(_QWORD *)(v21 + 8);
      if ( v22 )
      {
        if ( (wda_set_powersave_mode(v22, 1, v20, &ps_bearer_id) & 0x80000000) != 0 )
          printk(&unk_2CD5B, "qmi_rmnet_set_powersave_mode");
      }
    }
  }
  result = rmnet_get_powersave_notif(a1[13]);
  if ( (_DWORD)result )
  {
    v9 = a1[13];
    result = rmnet_mem_cb(0, 0);
    v10 = (_UNKNOWN **)ps_list;
    if ( ps_list != (_UNKNOWN *)&ps_list )
    {
      do
      {
        v11 = (__int64 (__fastcall *)(_QWORD))*(v10 - 2);
        if ( *((_DWORD *)v11 - 1) != 251140989 )
          __break(0x8228u);
        result = v11(v9);
        v10 = (_UNKNOWN **)*v10;
      }
      while ( v10 != &ps_list );
    }
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
