__int64 __fastcall ucfg_mc_cp_stats_resume_handler(
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
  __int64 comp_private_obj; // x0
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8

  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v10 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v10 + 16);
    }
    else
    {
      raw_spin_lock_bh(v10 + 16);
      *(_QWORD *)(v10 + 24) |= 1uLL;
    }
    **(_BYTE **)(v10 + 40) = 0;
    v12 = *(_QWORD *)(v10 + 24);
    if ( (v12 & 1) != 0 )
    {
      *(_QWORD *)(v10 + 24) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 16);
    }
    else
    {
      raw_spin_unlock(v10 + 16);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc cp stats object is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_mc_cp_stats_resume_req_handler");
    return 29;
  }
}
