__int64 __fastcall hdd_clear_all_sta(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  __int64 result; // x0
  unsigned __int64 v14; // x23
  __int64 v15; // x0
  int v16; // t1
  __int64 v18; // x8
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v20[4]; // [xsp+10h] [xbp-20h] BYREF

  v20[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 32);
  v19 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_clear_all_sta", v10 + 296);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 38872);
  }
  else
  {
    raw_spin_lock_bh(a1 + 38872);
    *(_QWORD *)(a1 + 38880) |= 1uLL;
  }
  hdd_get_front_sta_info_no_lock(a1 + 38848, &v19);
  if ( v19 )
    hdd_take_sta_info_ref(a1 + 38848, v19, 0, 15);
  hdd_get_next_sta_info_no_lock(a1 + 38848);
  v12 = *(_QWORD *)(a1 + 38880);
  if ( (v12 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 38880) = v12 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 38872);
    result = v19;
    if ( !v19 )
      goto LABEL_26;
  }
  else
  {
    raw_spin_unlock(a1 + 38872);
    result = v19;
    if ( !v19 )
      goto LABEL_26;
  }
  v14 = _ReadStatusReg(SP_EL0);
  do
  {
    while ( 1 )
    {
      v20[0] = 0;
      v20[1] = 0;
      v16 = *(_DWORD *)(result + 32);
      v15 = result + 32;
      if ( v16 != -1 || *(__int16 *)(v15 + 4) != -1 )
      {
        wlansap_populate_del_sta_params(v15, 3, 10, (int)v20);
        hdd_softap_sta_disassoc(a1, v20);
      }
      hdd_put_sta_info_ref(a1 + 38848, &v19, 1, 15);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v14 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 38872);
      }
      else
      {
        raw_spin_lock_bh(a1 + 38872);
        *(_QWORD *)(a1 + 38880) |= 1uLL;
      }
      v19 = 0;
      hdd_get_next_sta_info_no_lock(a1 + 38848);
      v18 = *(_QWORD *)(a1 + 38880);
      if ( (v18 & 1) != 0 )
        break;
      raw_spin_unlock(a1 + 38872);
      result = v19;
      if ( !v19 )
        goto LABEL_26;
    }
    *(_QWORD *)(a1 + 38880) = v18 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 38872);
    result = v19;
  }
  while ( v19 );
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
