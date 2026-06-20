__int64 __fastcall ucfg_mc_cp_stats_is_req_pending(
        __int64 a1,
        char a2,
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
  __int64 v12; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8
  unsigned int v15; // w21

  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v12 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v12 + 16);
      v14 = *(_QWORD *)(v12 + 24);
    }
    else
    {
      raw_spin_lock_bh(v12 + 16);
      v14 = *(_QWORD *)(v12 + 24) | 1LL;
      *(_QWORD *)(v12 + 24) = v14;
    }
    v15 = *(_DWORD *)(*(_QWORD *)(v12 + 40) + 8LL);
    if ( (v14 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 24) = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 16);
    }
    else
    {
      raw_spin_unlock(v12 + 16);
    }
    return (v15 >> a2) & 1;
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
      "ucfg_mc_cp_stats_is_req_pending");
    return 0;
  }
}
