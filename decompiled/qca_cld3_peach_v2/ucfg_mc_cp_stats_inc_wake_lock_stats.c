__int64 __fastcall ucfg_mc_cp_stats_inc_wake_lock_stats(
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
        unsigned int a11)
{
  __int64 comp_private_obj; // x0
  __int64 v14; // x21
  unsigned __int64 StatusReg; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  unsigned int v25; // w0
  __int64 v26; // x8
  unsigned int v27; // w19
  __int64 v29; // x8

  if ( !a1
    || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) == 0
    || (v14 = *(_QWORD *)(comp_private_obj + 24)) == 0 )
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
      "ucfg_mc_cp_stats_inc_wake_lock_stats");
    return 29;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(v14 + 16);
      *(_QWORD *)(v14 + 24) |= 1uLL;
      v24 = *(_QWORD *)(v14 + 40);
      if ( v24 )
        goto LABEL_8;
      goto LABEL_16;
    }
  }
  raw_spin_lock(v14 + 16);
  v24 = *(_QWORD *)(v14 + 40);
  if ( !v24 )
  {
LABEL_16:
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc mc stats is null",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ucfg_mc_cp_stats_inc_wake_lock_stats");
    v29 = *(_QWORD *)(v14 + 24);
    if ( (v29 & 1) != 0 )
    {
      *(_QWORD *)(v14 + 24) = v29 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v14 + 16);
    }
    else
    {
      raw_spin_unlock(v14 + 16);
    }
    return 29;
  }
LABEL_8:
  v25 = tgt_mc_cp_stats_inc_wake_lock_stats(a1, a11, v24 + 356, v24 + 352, v16, v17, v18, v19, v20, v21, v22, v23);
  v26 = *(_QWORD *)(v14 + 24);
  v27 = v25;
  if ( (v26 & 1) != 0 )
  {
    *(_QWORD *)(v14 + 24) = v26 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v14 + 16);
  }
  else
  {
    raw_spin_unlock(v14 + 16);
  }
  return v27;
}
