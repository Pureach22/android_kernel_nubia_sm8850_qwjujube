__int64 __fastcall ucfg_mc_cp_stats_set_rate_flags(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  __int64 v12; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8

  if ( a1 && (comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x1Bu)) != 0 )
  {
    v12 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 24);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 24);
      *(_QWORD *)(v12 + 32) |= 1uLL;
    }
    *(_DWORD *)(*(_QWORD *)(v12 + 8) + 4LL) = a2;
    v14 = *(_QWORD *)(v12 + 32);
    if ( (v14 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 32) = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 24);
    }
    else
    {
      raw_spin_unlock(v12 + 24);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev cp stats object is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_mc_cp_stats_set_rate_flags");
    return 29;
  }
}
