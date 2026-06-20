__int64 __fastcall cm_roam_control_restore_default_config(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 psoc_ext_obj_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x23
  _QWORD *vdev_by_id_from_pdev; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 rso_config_fl; // x0
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x22
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x22
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 result; // x0
  unsigned int v58; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+8h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 80);
  if ( !v2 )
    goto LABEL_18;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 80));
  if ( !psoc_ext_obj_fl )
    goto LABEL_18;
  if ( (*(_BYTE *)(psoc_ext_obj_fl + 1708) & 1) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: roam_scan_offload_enabled is not supported",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_roam_control_restore_default_config");
LABEL_18:
    result = 4;
    goto LABEL_19;
  }
  v14 = psoc_ext_obj_fl;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( !vdev_by_id_from_pdev )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "cm_roam_control_restore_default_config",
      (unsigned __int8)a2);
    goto LABEL_18;
  }
  v24 = (__int64)vdev_by_id_from_pdev;
  rso_config_fl = wlan_cm_get_rso_config_fl(vdev_by_id_from_pdev, "cm_roam_control_restore_default_config", 5872);
  if ( !rso_config_fl )
  {
    wlan_objmgr_vdev_release_ref(v24, 0x4Du, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    goto LABEL_18;
  }
  v35 = rso_config_fl;
  v36 = *(_QWORD *)(rso_config_fl + 176);
  if ( v36 )
  {
    _qdf_mem_free(v36);
    *(_QWORD *)(v35 + 176) = 0;
    *(_BYTE *)(v35 + 168) = 0;
  }
  v37 = *(_QWORD *)(v35 + 120);
  if ( v37 )
  {
    _qdf_mem_free(v37);
    *(_QWORD *)(v35 + 120) = 0;
    *(_BYTE *)(v35 + 112) = 0;
  }
  mlme_reinit_control_config_lfr_params(v2, v14 + 1480);
  v58 = 7;
  v38 = wlan_cm_get_rso_config_fl(v24, "cm_restore_default_roaming_params", 5800);
  if ( v38 )
  {
    v48 = v38;
    *(_BYTE *)(v38 + 188) = *(_BYTE *)(v14 + 3412);
    *(_WORD *)(v38 + 146) = *(_DWORD *)(v14 + 1744);
    *(_DWORD *)(v38 + 184) = *(_DWORD *)(v14 + 1944);
    *(_DWORD *)(v38 + 104) = *(_DWORD *)(v14 + 1712);
    *(_BYTE *)(v38 + 128) = *(_DWORD *)(v14 + 1720);
    *(_BYTE *)(v38 + 129) = *(_DWORD *)(v14 + 1720);
    *(_BYTE *)(v38 + 189) = *(_BYTE *)(v14 + 1704);
    *(_BYTE *)(v38 + 190) = *(_BYTE *)(v14 + 1705);
    *(_BYTE *)(v38 + 224) = *(_BYTE *)(v14 + 1706);
    *(_BYTE *)(v38 + 191) = *(_BYTE *)(v14 + 1707);
    *(_DWORD *)(v38 + 136) = *(unsigned __int16 *)(v14 + 1734);
    *(_DWORD *)(v38 + 140) = *(_DWORD *)(v14 + 1736);
    *(_WORD *)(v38 + 192) = *(_WORD *)(v14 + 1778);
    *(_BYTE *)(v38 + 194) = *(_DWORD *)(v14 + 1780);
    *(_DWORD *)(v38 + 196) = *(_DWORD *)(v14 + 1932);
    *(_DWORD *)(v38 + 200) = *(_DWORD *)(v14 + 1936);
    wlan_mlme_reinit_real_time_roam_parms();
    ucfg_reg_get_band(*(_QWORD *)(v24 + 152), &v58, v49, v50, v51, v52, v53, v54, v55, v56);
    v39 = (unsigned int *)v58;
    *(_DWORD *)(v48 + 944) = v58;
  }
  wlan_objmgr_vdev_release_ref(v24, 0x4Du, v39, v40, v41, v42, v43, v44, v45, v46, v47);
  if ( (unsigned int)mlme_get_roam_state(v2, a2) == 2 )
  {
    cm_roam_send_rso_cmd(v2, a2, 4u, 9u);
    cm_roam_send_rso_cmd(v2, a2, 4u, 0x2Du);
  }
  result = 0;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
