__int64 __fastcall cm_roam_triggers(__int64 a1, __int64 a2, _DWORD *a3)
{
  unsigned int v3; // w23
  unsigned int v5; // w21
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  int v44; // w23
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v3 = (unsigned __int8)a2;
  v5 = a2;
  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a3 = (unsigned __int8)a2;
  a3[1] = mlme_get_roam_trigger_bitmap(a1, a2);
  if ( (cm_roam_is_per_roam_allowed(a1, v5) & 1) == 0 )
    a3[1] &= ~2u;
  v53 = 0;
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v5, 77);
  if ( !v7 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Vdev is null for vdev_id:%d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "cm_is_only_2g_band_supported",
      v3);
    goto LABEL_10;
  }
  v16 = v7;
  v17 = *(_QWORD *)(v7 + 152);
  if ( !v17 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: pdev is null for vdev_id:%d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "cm_is_only_2g_band_supported",
      v3);
    goto LABEL_9;
  }
  if ( (unsigned int)ucfg_reg_get_band(v17, &v53, v8, v9, v10, v11, v12, v13, v14, v15) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Failed to get band",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "cm_is_only_2g_band_supported");
LABEL_9:
    wlan_objmgr_vdev_release_ref(v16, 0x4Du, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Current band bitmap:%d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "cm_is_only_2g_band_supported",
    v53);
  v44 = v53 & 7;
  wlan_objmgr_vdev_release_ref(v16, 0x4Du, (unsigned int *)v53, v45, v46, v47, v48, v49, v50, v51, v52);
  if ( v44 == 1 )
    a3[1] &= 0xFFF7BFFF;
LABEL_10:
  if ( (policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id(a1, v5) & 1) != 0 )
    a3[1] &= 0xFFFFDFFB;
  a3[3] = wlan_cm_get_roam_scan_scheme_bitmap(a1, v5);
  wlan_cm_roam_get_vendor_btm_params(a1, a3 + 4);
  wlan_cm_roam_get_score_delta_params(a1, a3);
  wlan_cm_roam_get_min_rssi_params(a1, a3);
  result = qdf_trace_msg(
             0x68u,
             8u,
             "%s: triggers_bitmap:0x%x",
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             "cm_roam_triggers",
             (unsigned int)a3[1]);
  _ReadStatusReg(SP_EL0);
  return result;
}
