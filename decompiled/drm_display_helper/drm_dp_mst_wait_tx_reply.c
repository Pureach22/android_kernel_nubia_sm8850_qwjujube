__int64 __fastcall drm_dp_mst_wait_tx_reply(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x23
  __int64 v5; // x8
  int v6; // w9
  __int64 v7; // x8
  int v8; // w21
  __int64 v9; // x0
  __int64 v10; // x21
  unsigned int v11; // w8
  bool v12; // cf
  int v13; // w21
  void (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x21
  __int64 v16; // x8
  __int64 v17; // x1
  int v18; // w22
  int v19; // w8
  _QWORD *v20; // x8
  __int64 *v21; // x0
  __int64 v22; // x9
  __int64 v23; // x0
  unsigned int v24; // w20
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  __int64 v27; // [xsp+10h] [xbp-30h]
  __int64 v28; // [xsp+18h] [xbp-28h]
  __int64 v29; // [xsp+20h] [xbp-20h]
  __int64 v30; // [xsp+28h] [xbp-18h]
  __int64 v31; // [xsp+30h] [xbp-10h]
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 64);
  v4 = jiffies + 1000LL;
  while ( 1 )
  {
    v5 = *(_QWORD *)(v3 + 112);
    if ( *(_QWORD *)(v5 + 8) )
      v6 = 13;
    else
      v6 = 1000;
    if ( (unsigned int)(*(_DWORD *)(a2 + 340) - 3) >= 2 )
    {
      v29 = 0;
      v30 = 0;
      v27 = 0;
      v28 = 0;
      v7 = *(_QWORD *)(v5 + 8);
      v26 = 0;
      if ( v7 )
        v8 = 13;
      else
        v8 = 1000;
      init_wait_entry(&v26, 0);
      prepare_to_wait_event(v3 + 1000, &v26, 2);
      LODWORD(v9) = v8;
      if ( (unsigned int)(*(_DWORD *)(a2 + 340) - 3) >= 2 )
      {
        do
        {
          v10 = schedule_timeout();
          prepare_to_wait_event(v3 + 1000, &v26, 2);
          v11 = *(_DWORD *)(a2 + 340) - 3;
          if ( v10 )
            v12 = 1;
          else
            v12 = v11 >= 2;
          if ( v12 )
            v9 = v10;
          else
            v9 = 1;
        }
        while ( v11 >= 2 && v9 );
      }
      v13 = v9;
      finish_wait(v3 + 1000, &v26);
      v6 = v13;
    }
    if ( v6 )
      break;
    v14 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v3 + 112) + 8LL);
    if ( !v14 || v4 - jiffies < 0 )
    {
      v15 = v3 + 936;
      mutex_lock(v3 + 936);
      goto LABEL_26;
    }
    if ( *((_DWORD *)v14 - 1) != 1747835419 )
      __break(0x8228u);
    v14(v3);
  }
  v15 = v3 + 936;
  v18 = v6;
  mutex_lock(v3 + 936);
  v19 = v18;
  if ( v18 < 1 )
  {
LABEL_26:
    v16 = *(_QWORD *)(v3 + 104);
    if ( v16 )
      v17 = *(_QWORD *)(v16 + 8);
    else
      v17 = 0;
    _drm_dev_dbg(
      0,
      v17,
      2,
      "timedout msg send %p %d %d\n",
      (const void *)a2,
      *(_DWORD *)(a2 + 340),
      *(_DWORD *)(a2 + 336));
    if ( *(_DWORD *)(a2 + 340) <= 2u )
    {
      v20 = *(_QWORD **)(a2 + 328);
      v21 = (__int64 *)(a2 + 320);
      if ( *v20 == a2 + 320 && (v22 = *v21, *(__int64 **)(*v21 + 8) == v21) )
      {
        *(_QWORD *)(v22 + 8) = v20;
        *v20 = v22;
      }
      else
      {
        _list_del_entry_valid_or_report();
      }
      *(_QWORD *)(a2 + 320) = 0xDEAD000000000100LL;
      *(_QWORD *)(a2 + 328) = 0xDEAD000000000122LL;
    }
    goto LABEL_37;
  }
  if ( *(_DWORD *)(a2 + 340) != 4 )
    goto LABEL_40;
LABEL_37:
  if ( (*(&_drm_debug + 1) & 1) != 0 )
  {
    v23 = *(_QWORD *)(v3 + 104);
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    drm_dbg_printer(&v26, v23);
    drm_dp_mst_dump_sideband_msg_tx(&v26, a2);
  }
  v19 = -5;
LABEL_40:
  v24 = v19;
  mutex_unlock(v15);
  queue_work_on(32, system_long_wq, v3 + 1056);
  _ReadStatusReg(SP_EL0);
  return v24;
}
