__int64 __fastcall ucfg_mc_cp_stats_inc_wake_lock_stats_by_dst_addr(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned __int8 *a11)
{
  __int64 comp_private_obj; // x0
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  int v16; // w9
  __int64 v17; // x9
  const char *v18; // x2
  __int64 v20; // x8

  if ( !a1
    || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) == 0
    || (v13 = *(_QWORD *)(comp_private_obj + 24)) == 0 )
  {
    v18 = "%s: psoc cp stats object is null";
LABEL_13:
    qdf_trace_msg(0x62u, 2u, v18, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_mc_cp_stats_inc_wake_lock_stats_by_dst_addr");
    return 29;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v13 + 16);
      *(_QWORD *)(v13 + 24) |= 1uLL;
      v15 = *(_QWORD *)(v13 + 40);
      if ( v15 )
        goto LABEL_8;
      goto LABEL_23;
    }
  }
  raw_spin_lock(v13 + 16);
  v15 = *(_QWORD *)(v13 + 40);
  if ( !v15 )
  {
LABEL_23:
    v18 = "%s: psoc mc stats is null";
    goto LABEL_13;
  }
LABEL_8:
  v16 = *a11;
  switch ( v16 )
  {
    case 255:
      v17 = 360;
      break;
    case 51:
      v17 = 368;
      break;
    case 1:
      v17 = 364;
      break;
    default:
      v17 = 356;
      break;
  }
  ++*(_DWORD *)(v15 + v17);
  v20 = *(_QWORD *)(v13 + 24);
  if ( (v20 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 24) = v20 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 16);
  }
  else
  {
    raw_spin_unlock(v13 + 16);
  }
  return 0;
}
