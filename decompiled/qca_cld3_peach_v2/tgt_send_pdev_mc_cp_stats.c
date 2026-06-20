__int64 __fastcall tgt_send_pdev_mc_cp_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  char is_force_inactive; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x4
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  __int64 v27; // x19
  __int64 v28; // x4
  unsigned int macid_by_vdev_id; // w20
  const char *v30; // x2
  const char *v31; // x2
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 comp_private_obj; // x0
  __int64 v42; // x21
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7

  result = 29;
  if ( a2 && a3 )
  {
    is_force_inactive = policy_mgr_vdev_is_force_inactive(a1, *(_DWORD *)(a3 + 16));
    v16 = *(unsigned int *)(a3 + 16);
    if ( (is_force_inactive & 1) != 0 )
    {
      qdf_trace_msg(
        0x62u,
        8u,
        "%s: Ignore pdev stats on inactive link vdev %d",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "tgt_send_pdev_mc_cp_stats",
        v16);
      return 0;
    }
    v17 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            (unsigned int)v16,
            38);
    if ( !v17 )
    {
      qdf_trace_msg(0x62u, 2u, "%s: vdev is null", v18, v19, v20, v21, v22, v23, v24, v25, "tgt_send_pdev_mc_cp_stats");
      return 29;
    }
    v26 = *(_QWORD *)(v17 + 216);
    v27 = v17;
    if ( v26 )
    {
      v28 = *(unsigned __int8 *)(v26 + 40);
      if ( *(_DWORD *)(a3 + 20) != (_DWORD)v28 )
      {
        v30 = "%s: pdev_id: %d invalid";
        goto LABEL_15;
      }
      macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(a1, *(_DWORD *)(a3 + 16));
      if ( macid_by_vdev_id >= 2 )
      {
        v30 = "%s: mac_id: %d invalid";
        v28 = macid_by_vdev_id;
LABEL_15:
        qdf_trace_msg(0x62u, 2u, v30, v18, v19, v20, v21, v22, v23, v24, v25, "tgt_send_pdev_mc_cp_stats", v28);
        goto LABEL_16;
      }
      comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(v26, 0x1Bu);
      if ( comp_private_obj )
      {
        v42 = comp_private_obj;
        qdf_spin_lock_bh_10(comp_private_obj + 24);
        qdf_mem_copy(*(void **)(a2 + 8), (const void *)(*(_QWORD *)(v42 + 8) + 12672LL * macid_by_vdev_id), 0x3180u);
        qdf_spin_unlock_bh_11(v42 + 24);
        wlan_objmgr_vdev_release_ref(v27, 0x26u, v43, v44, v45, v46, v47, v48, v49, v50, v51);
        return 0;
      }
      v31 = "%s: pdev_cp_stats_priv is null";
    }
    else
    {
      v31 = "%s: pdev is null";
    }
    qdf_trace_msg(0x62u, 2u, v31, v18, v19, v20, v21, v22, v23, v24, v25, "tgt_send_pdev_mc_cp_stats");
LABEL_16:
    wlan_objmgr_vdev_release_ref(v27, 0x26u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    return 29;
  }
  return result;
}
