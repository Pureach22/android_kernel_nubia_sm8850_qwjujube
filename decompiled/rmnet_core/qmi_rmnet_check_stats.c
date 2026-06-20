__int64 __fastcall qmi_rmnet_check_stats(__int64 result)
{
  __int64 *v1; // x19
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 v6; // x11
  int v7; // w13
  char v8; // w12
  __int64 qmi_pt; // x0
  __int64 v10; // x0
  __int64 *v11; // x0
  int v12; // w8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x19
  _UNKNOWN **v16; // x21
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 *v18; // x0
  __int64 v19; // x20
  _UNKNOWN **v20; // x22
  void (__fastcall *v21)(_QWORD); // x8
  __int64 lock; // x0
  __int64 v23; // x20
  __int64 v24; // x0
  unsigned __int64 v31; // x10
  __int64 v32; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v33[2]; // [xsp+10h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_39;
  v1 = (__int64 *)result;
  result = *(_QWORD *)(result + 104);
  if ( !result )
    goto LABEL_39;
  v32 = 0;
  v33[0] = 0;
  result = rmnet_get_qmi_pt(result);
  if ( !result )
    goto LABEL_39;
  v2 = result;
  rmnet_get_packets(v1[13], v33, &v32);
  v3 = v32;
  v4 = v33[0];
  v6 = v1[14];
  v5 = v1[15];
  v1[14] = v33[0];
  v1[15] = v3;
  v7 = *(unsigned __int8 *)(v2 + 72);
  v8 = *(_BYTE *)(v2 + 73);
  *(_BYTE *)(v2 + 73) = 0;
  if ( v7 == 1 )
  {
    *(_BYTE *)(v2 + 74) = 0;
    qmi_pt = rmnet_get_qmi_pt(v1[13]);
    if ( !qmi_pt )
      goto LABEL_36;
    v10 = *(_QWORD *)(qmi_pt + 8);
    if ( !v10 )
      goto LABEL_36;
    if ( (wda_set_powersave_mode(v10, 0, 0, 0) & 0x80000000) == 0 )
    {
      v11 = *(__int64 **)(v2 + 24);
      *(_BYTE *)(v2 + 72) = 0;
      v12 = dfc_qmap;
      if ( v11 && !dfc_qmap )
      {
        if ( (*(_BYTE *)(v2 + 56) & 1) != 0 )
        {
          v12 = 0;
        }
        else
        {
          dfc_qmi_query_flow(v11);
          v12 = dfc_qmap;
        }
      }
      v18 = *(__int64 **)(v2 + 32);
      if ( v18 && !v12 && (*(_BYTE *)(v2 + 57) & 1) == 0 )
        dfc_qmi_query_flow(v18);
      if ( (unsigned int)rmnet_get_powersave_notif(v1[13]) )
      {
        v19 = v1[13];
        v20 = (_UNKNOWN **)ps_list;
        if ( ps_list != (_UNKNOWN *)&ps_list )
        {
          do
          {
            v21 = (void (__fastcall *)(_QWORD))*(v20 - 1);
            if ( *((_DWORD *)v21 - 1) != 251140989 )
              __break(0x8228u);
            v21(v19);
            v20 = (_UNKNOWN **)*v20;
          }
          while ( v20 != &ps_list );
        }
      }
      goto LABEL_36;
    }
    goto LABEL_40;
  }
  if ( v4 != v6
    || v3 != v5
    || (v8 & 1) == 0 && !rmnet_all_flows_enabled(v1[13])
    || (v13 = rmnet_get_qmi_pt(v1[13])) == 0
    || (v14 = *(_QWORD *)(v13 + 8)) == 0 )
  {
LABEL_36:
    lock = _rcu_read_lock();
    if ( (rmnet_work_quit & 1) == 0 )
    {
      v23 = rmnet_ps_wq;
      v24 = _msecs_to_jiffies((unsigned int)rmnet_wq_frequency);
      lock = queue_delayed_work_on(32, v23, v1, v24);
    }
    result = _rcu_read_unlock(lock);
    goto LABEL_39;
  }
  if ( (wda_set_powersave_mode(v14, 1, 0, 0) & 0x80000000) != 0 )
  {
LABEL_40:
    printk(&unk_2CD5B, "qmi_rmnet_set_powersave_mode");
    goto LABEL_36;
  }
  *(_BYTE *)(v2 + 72) = 1;
  *(_BYTE *)(v2 + 74) = 1;
  _X8 = (unsigned __int64 *)(v2 + 64);
  __asm { PRFM            #0x11, [X8] }
  do
    v31 = __ldxr(_X8);
  while ( __stxr(v31 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  rmnet_enable_all_flows(v1[13]);
  result = rmnet_get_powersave_notif(v1[13]);
  if ( (_DWORD)result )
  {
    v15 = v1[13];
    result = rmnet_mem_cb(0, 0);
    v16 = (_UNKNOWN **)ps_list;
    if ( ps_list != (_UNKNOWN *)&ps_list )
    {
      do
      {
        v17 = (__int64 (__fastcall *)(_QWORD))*(v16 - 2);
        if ( *((_DWORD *)v17 - 1) != 251140989 )
          __break(0x8228u);
        result = v17(v15);
        v16 = (_UNKNOWN **)*v16;
      }
      while ( v16 != &ps_list );
    }
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
