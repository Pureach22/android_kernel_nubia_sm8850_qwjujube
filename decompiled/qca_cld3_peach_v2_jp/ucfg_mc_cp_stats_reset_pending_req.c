__int64 __fastcall ucfg_mc_cp_stats_reset_pending_req(
        __int64 a1,
        unsigned int a2,
        _QWORD *a3,
        char *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  __int64 v16; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x8
  _QWORD *v20; // x10
  __int64 v21; // x11
  __int64 v22; // x13
  __int64 v23; // x14
  char v24; // w11
  __int64 v25; // x8

  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v16 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
  {
    if ( a2 < 7 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v16 + 16);
      }
      else
      {
        raw_spin_lock_bh(v16 + 16);
        *(_QWORD *)(v16 + 24) |= 1uLL;
      }
      v19 = *(_QWORD *)(v16 + 40);
      v20 = (_QWORD *)(v19 + 32LL * a2);
      if ( (*(_DWORD *)(v19 + 8) & (1 << a2)) != 0 )
      {
        v21 = v20[5];
        v22 = v20[2];
        v23 = v20[3];
        a3[2] = v20[4];
        a3[3] = v21;
        v24 = 1;
        *a3 = v22;
        a3[1] = v23;
      }
      else
      {
        v24 = 0;
      }
      *a4 = v24;
      *(_DWORD *)(v19 + 8) &= ~(1 << a2);
      qdf_mem_set(v20 + 2, 0x20u, 0);
      v25 = *(_QWORD *)(v16 + 24);
      if ( (v25 & 1) != 0 )
      {
        *(_QWORD *)(v16 + 24) = v25 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 16);
      }
      else
      {
        raw_spin_unlock(v16 + 16);
      }
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Invalid type index: %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "ucfg_mc_cp_stats_reset_pending_req",
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
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "ucfg_mc_cp_stats_reset_pending_req");
    return 29;
  }
}
