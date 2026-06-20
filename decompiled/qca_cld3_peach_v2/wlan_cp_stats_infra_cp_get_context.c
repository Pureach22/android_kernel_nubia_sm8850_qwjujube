__int64 __fastcall wlan_cp_stats_infra_cp_get_context(
        __int64 a1,
        _QWORD *a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  _QWORD *v14; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8

  if ( !a1
    || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) == 0
    || (v14 = *(_QWORD **)(comp_private_obj + 24)) == nullptr )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc cp stats object is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_cp_stats_infra_cp_get_context");
    return 29;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v14 + 2);
      v14[3] |= 1uLL;
      v16 = v14[7];
      if ( !v16 )
        goto LABEL_9;
      goto LABEL_8;
    }
  }
  raw_spin_lock(v14 + 2);
  v16 = v14[7];
  if ( v16 )
LABEL_8:
    *a2 = v16;
LABEL_9:
  v17 = v14[8];
  if ( v17 )
    *a3 = v17;
  v18 = v14[3];
  if ( (v18 & 1) != 0 )
  {
    v14[3] = v18 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v14 + 2);
  }
  else
  {
    raw_spin_unlock(v14 + 2);
  }
  return 0;
}
