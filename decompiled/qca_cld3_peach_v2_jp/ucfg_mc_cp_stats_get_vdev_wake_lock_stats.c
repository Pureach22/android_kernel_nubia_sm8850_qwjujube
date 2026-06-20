__int64 __fastcall ucfg_mc_cp_stats_get_vdev_wake_lock_stats(__int64 a1, void *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 comp_private_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  unsigned __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  const char *v22; // x2
  __int64 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1272);
    v5 = *(_QWORD *)(a1 + 152);
    if ( !v5 )
      goto LABEL_21;
  }
  else
  {
    raw_spin_lock_bh(a1 + 1272);
    *(_QWORD *)(a1 + 1280) |= 1uLL;
    v5 = *(_QWORD *)(a1 + 152);
    if ( !v5 )
      goto LABEL_21;
  }
  v6 = *(_QWORD *)(v5 + 80);
  if ( v6 )
  {
    v7 = *(_QWORD *)(a1 + 1280);
    if ( (v7 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1280) = v7 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1272);
    }
    else
    {
      raw_spin_unlock(a1 + 1272);
    }
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v6, 0x1Bu);
    if ( comp_private_obj && (v17 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v18 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v18 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v17 + 16);
        v19 = *(_QWORD *)(v17 + 40);
        if ( v19 )
        {
LABEL_14:
          qdf_mem_copy(a2, (const void *)(v19 + 244), 0x70u);
          v20 = *(_QWORD *)(v17 + 24);
          if ( (v20 & 1) != 0 )
          {
            *(_QWORD *)(v17 + 24) = v20 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v17 + 16);
          }
          else
          {
            raw_spin_unlock(v17 + 16);
          }
          return 0;
        }
      }
      else
      {
        raw_spin_lock_bh(v17 + 16);
        *(_QWORD *)(v17 + 24) |= 1uLL;
        v19 = *(_QWORD *)(v17 + 40);
        if ( v19 )
          goto LABEL_14;
      }
      v22 = "%s: psoc mc stats is null";
    }
    else
    {
      v22 = "%s: psoc cp stats object is null";
    }
    qdf_trace_msg(0x62u, 2u, v22, v9, v10, v11, v12, v13, v14, v15, v16, "ucfg_mc_cp_stats_get_vdev_wake_lock_stats");
    return 29;
  }
LABEL_21:
  v23 = *(_QWORD *)(a1 + 1280);
  if ( (v23 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1280) = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1272);
  }
  else
  {
    raw_spin_unlock(a1 + 1272);
  }
  qdf_trace_msg(
    0x62u,
    2u,
    "%s: psoc NULL",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "ucfg_mc_cp_stats_get_vdev_wake_lock_stats");
  return 4;
}
