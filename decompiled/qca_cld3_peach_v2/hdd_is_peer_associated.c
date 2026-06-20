__int64 __fastcall hdd_is_peer_associated(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  unsigned __int64 v15; // x25
  int v16; // w21
  __int64 v17; // x8
  __int64 result; // x0
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20[0] = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid adapter or mac_addr",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_is_peer_associated");
    goto LABEL_28;
  }
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
  hdd_get_front_sta_info_no_lock(a1 + 38848, v20);
  if ( v20[0] )
    hdd_take_sta_info_ref(a1 + 38848, v20[0], 0, 19);
  hdd_get_next_sta_info_no_lock(a1 + 38848);
  if ( v19 )
    hdd_take_sta_info_ref(a1 + 38848, v19, 0, 19);
  v13 = *(_QWORD *)(a1 + 38880);
  if ( (v13 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 38872);
    v14 = v20[0];
    if ( v20[0] )
      goto LABEL_13;
LABEL_28:
    result = 0;
    goto LABEL_29;
  }
  *(_QWORD *)(a1 + 38880) = v13 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 38872);
  v14 = v20[0];
  if ( !v20[0] )
    goto LABEL_28;
LABEL_13:
  v15 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v16 = qdf_mem_cmp((const void *)(v14 + 32), a2, 6u);
    hdd_put_sta_info_ref(a1 + 38848, v20, 1, 19);
    if ( !v16 )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v15 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 38872);
    }
    else
    {
      raw_spin_lock_bh(a1 + 38872);
      *(_QWORD *)(a1 + 38880) |= 1uLL;
    }
    v20[0] = v19;
    hdd_get_next_sta_info_no_lock(a1 + 38848);
    if ( v19 )
      hdd_take_sta_info_ref(a1 + 38848, v19, 0, 19);
    v17 = *(_QWORD *)(a1 + 38880);
    if ( (v17 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 38880) = v17 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 38872);
      v14 = v20[0];
      if ( !v20[0] )
        goto LABEL_28;
    }
    else
    {
      raw_spin_unlock(a1 + 38872);
      v14 = v20[0];
      if ( !v20[0] )
        goto LABEL_28;
    }
  }
  if ( v19 )
    hdd_put_sta_info_ref(a1 + 38848, &v19, 1, 19);
  result = 1;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
