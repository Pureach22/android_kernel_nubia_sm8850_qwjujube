__int64 __fastcall ucfg_mc_cp_stats_get_tx_power(
        __int64 a1,
        _DWORD *a2,
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
  int v16; // w22
  __int64 v18; // x21
  __int64 v19; // x0
  unsigned int macid_by_vdev_id; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  const char *v30; // x2
  __int64 v31; // x0
  __int64 v32; // x21
  unsigned __int64 v33; // x8
  __int64 v34; // x8

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x1Bu);
    if ( comp_private_obj )
    {
      v13 = comp_private_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 24);
        v15 = *(_QWORD *)(v13 + 32);
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 24);
        v15 = *(_QWORD *)(v13 + 32) | 1LL;
        *(_QWORD *)(v13 + 32) = v15;
      }
      v16 = *(_DWORD *)(*(_QWORD *)(v13 + 8) + 136LL);
      if ( (v15 & 1) != 0 )
      {
        *(_QWORD *)(v13 + 32) = v15 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v13 + 24);
        if ( v16 )
          goto LABEL_9;
      }
      else
      {
        raw_spin_unlock(v13 + 24);
        if ( v16 )
        {
LABEL_9:
          *a2 = v16;
          return 0;
        }
      }
    }
  }
  v18 = *(_QWORD *)(a1 + 152);
  if ( !v18 )
  {
    v30 = "%s: pdev is null";
LABEL_28:
    qdf_trace_msg(0x62u, 2u, v30, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_mc_cp_stats_get_tx_power");
    return 29;
  }
  v19 = *(_QWORD *)(v18 + 80);
  if ( !v19 )
  {
    v30 = "%s: psoc is null";
    goto LABEL_28;
  }
  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(v19, *(unsigned __int8 *)(a1 + 104));
  if ( macid_by_vdev_id >= 2 )
  {
    v29 = jiffies;
    if ( ucfg_mc_cp_stats_get_tx_power___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: invalid mac_id %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "ucfg_mc_cp_stats_get_tx_power",
        macid_by_vdev_id);
      ucfg_mc_cp_stats_get_tx_power___last_ticks = v29;
    }
    return 4;
  }
  v31 = wlan_objmgr_pdev_get_comp_private_obj(v18, 0x1Bu);
  if ( !v31 )
  {
    v30 = "%s: pdev cp stats object is null";
    goto LABEL_28;
  }
  v32 = v31;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v33 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v33 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v33 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v31 + 24);
  }
  else
  {
    raw_spin_lock_bh(v31 + 24);
    *(_QWORD *)(v32 + 32) |= 1uLL;
  }
  *a2 = *(_DWORD *)(*(_QWORD *)(v32 + 8) + 12672LL * macid_by_vdev_id);
  v34 = *(_QWORD *)(v32 + 32);
  if ( (v34 & 1) != 0 )
  {
    *(_QWORD *)(v32 + 32) = v34 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v32 + 24);
  }
  else
  {
    raw_spin_unlock(v32 + 24);
  }
  return 0;
}
