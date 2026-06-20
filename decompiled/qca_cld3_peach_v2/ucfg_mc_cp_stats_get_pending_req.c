__int64 __fastcall ucfg_mc_cp_stats_get_pending_req(
        __int64 a1,
        unsigned int a2,
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
  __int64 v14; // x21
  unsigned __int64 StatusReg; // x8
  _QWORD *v17; // x8
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x8
  __int64 v22; // x11
  __int64 v23; // x8

  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v14 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
  {
    if ( a2 < 7 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v14 + 16);
      }
      else
      {
        raw_spin_lock_bh(v14 + 16);
        *(_QWORD *)(v14 + 24) |= 1uLL;
      }
      v17 = (_QWORD *)(*(_QWORD *)(v14 + 40) + 48LL * a2);
      v18 = v17[3];
      *a3 = v17[2];
      a3[1] = v18;
      v20 = v17[6];
      v19 = v17[7];
      v22 = v17[4];
      v21 = v17[5];
      a3[4] = v20;
      a3[5] = v19;
      a3[2] = v22;
      a3[3] = v21;
      v23 = *(_QWORD *)(v14 + 24);
      if ( (v23 & 1) != 0 )
      {
        *(_QWORD *)(v14 + 24) = v23 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v14 + 16);
      }
      else
      {
        raw_spin_unlock(v14 + 16);
      }
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Invalid type index: %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "ucfg_mc_cp_stats_get_pending_req",
        a2);
      return 4;
    }
  }
  else
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
      "ucfg_mc_cp_stats_get_pending_req");
    return 29;
  }
}
