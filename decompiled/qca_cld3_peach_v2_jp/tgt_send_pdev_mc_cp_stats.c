__int64 __fastcall tgt_send_pdev_mc_cp_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x20
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  __int64 v18; // x19
  __int64 v19; // x4
  unsigned int macid_by_vdev_id; // w20
  const char *v21; // x2
  const char *v22; // x2
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 comp_private_obj; // x0
  __int64 v33; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v35; // x8
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  result = 29;
  if ( !a2 || !a3 )
    return result;
  v7 = a1;
  v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         a1,
         *(unsigned int *)(a3 + 16),
         38);
  if ( !v8 )
  {
    qdf_trace_msg(0x62u, 2u, "%s: vdev is null", v9, v10, v11, v12, v13, v14, v15, v16, "tgt_send_pdev_mc_cp_stats");
    return 29;
  }
  v17 = *(_QWORD *)(v8 + 152);
  v18 = v8;
  if ( !v17 )
  {
    v22 = "%s: pdev is null";
LABEL_10:
    qdf_trace_msg(0x62u, 2u, v22, v9, v10, v11, v12, v13, v14, v15, v16, "tgt_send_pdev_mc_cp_stats");
LABEL_13:
    wlan_objmgr_vdev_release_ref(v18, 0x26u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
    return 29;
  }
  v19 = *(unsigned __int8 *)(v17 + 40);
  if ( *(_DWORD *)(a3 + 20) != (_DWORD)v19 )
  {
    v21 = "%s: pdev_id: %d invalid";
    goto LABEL_12;
  }
  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(v7, *(_DWORD *)(a3 + 16));
  if ( macid_by_vdev_id >= 2 )
  {
    v21 = "%s: mac_id: %d invalid";
    v19 = macid_by_vdev_id;
LABEL_12:
    qdf_trace_msg(0x62u, 2u, v21, v9, v10, v11, v12, v13, v14, v15, v16, "tgt_send_pdev_mc_cp_stats", v19);
    goto LABEL_13;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(v17, 0x1Bu);
  if ( !comp_private_obj )
  {
    v22 = "%s: pdev_cp_stats_priv is null";
    goto LABEL_10;
  }
  v33 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 24);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 24);
    *(_QWORD *)(v33 + 32) |= 1uLL;
  }
  qdf_mem_copy(*(void **)(a2 + 8), (const void *)(*(_QWORD *)(v33 + 8) + 12672LL * macid_by_vdev_id), 0x3180u);
  v35 = *(_QWORD *)(v33 + 32);
  if ( (v35 & 1) != 0 )
  {
    *(_QWORD *)(v33 + 32) = v35 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v33 + 24);
  }
  else
  {
    raw_spin_unlock(v33 + 24);
  }
  wlan_objmgr_vdev_release_ref(v18, 0x26u, v36, v37, v38, v39, v40, v41, v42, v43, v44);
  return 0;
}
