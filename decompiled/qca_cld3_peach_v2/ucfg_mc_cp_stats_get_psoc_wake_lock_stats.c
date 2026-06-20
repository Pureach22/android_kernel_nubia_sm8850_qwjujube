__int64 __fastcall ucfg_mc_cp_stats_get_psoc_wake_lock_stats(
        __int64 a1,
        __int64 a2,
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
  __int64 v13; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8

  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v13 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 16);
    }
    else
    {
      raw_spin_lock_bh(v13 + 16);
      *(_QWORD *)(v13 + 24) |= 1uLL;
    }
    wlan_objmgr_iterate_obj_list(a1, 2, vdev_iterator, a2, 1, 0x26u);
    v15 = *(_QWORD *)(v13 + 24);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 24) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 16);
    }
    else
    {
      raw_spin_unlock(v13 + 16);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc cp stats object is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_mc_cp_stats_get_psoc_wake_lock_stats");
    return 29;
  }
}
