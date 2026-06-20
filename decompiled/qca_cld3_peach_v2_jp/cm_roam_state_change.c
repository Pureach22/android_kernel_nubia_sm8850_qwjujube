__int64 __fastcall cm_roam_state_change(__int64 a1, unsigned int a2, int a3, unsigned int a4, __int64 a5, char a6)
{
  __int64 v6; // x24
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v14; // x25
  int is_up; // w23
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int64 v34; // x4
  unsigned int v35; // w25
  _QWORD *v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x26
  unsigned int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w0
  char roam_state; // w0
  __int64 v66; // x26
  char v67; // w24
  char v68; // w27
  unsigned __int8 rso_disabled_bitmap; // w28
  char supplicant_disabled_roaming; // w26
  char v71; // w0
  int v72; // w8
  int v73; // w7

  v6 = *(_QWORD *)(a1 + 80);
  if ( !v6 )
    return 4;
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 2u);
  if ( !vdev_by_id_from_pdev )
    return 0;
  v14 = (__int64)vdev_by_id_from_pdev;
  is_up = wlan_vdev_is_up();
  wlan_objmgr_vdev_release_ref(v14, 2u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( is_up )
  {
    if ( a3 && a3 != 3 )
    {
      v33 = "%s: ROAM: roam state(%d) change requested in non-connected state";
      v34 = (unsigned int)a3;
LABEL_13:
      qdf_trace_msg(0x68u, 8u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "cm_roam_state_change", v34);
      v35 = 0;
      goto LABEL_35;
    }
  }
  else if ( a3 == 2
         && ((policy_mgr_is_chan_switch_in_progress(v6) & 1) != 0
          || policy_mgr_is_conc_sap_ready_for_mcc_to_scc_trans(v6)) )
  {
    v33 = "%s: ROAM: roam state(%d) change requested when a concurrent SAP is in MCC or CSA is in progress";
    v34 = 2;
    goto LABEL_13;
  }
  v36 = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
  if ( !v36 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Invalid vdev:%d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "cm_roam_state_change",
      (unsigned __int8)a2);
    v35 = 11;
    goto LABEL_35;
  }
  v45 = (__int64)v36;
  v46 = cm_roam_acquire_lock();
  if ( !v46 )
  {
    if ( a3 > 2 )
    {
      switch ( a3 )
      {
        case 3:
          v64 = cm_roam_switch_to_rso_stop(a1, a2, a4, a5, a6 & 1);
          goto LABEL_32;
        case 4:
          v64 = cm_roam_switch_to_roam_start(a1, a2);
          goto LABEL_32;
        case 5:
          v64 = cm_roam_switch_to_roam_sync(a1, a2);
          goto LABEL_32;
      }
    }
    else
    {
      switch ( a3 )
      {
        case 0:
          v64 = cm_roam_switch_to_deinit(a1, a2, a4);
          goto LABEL_32;
        case 1:
          v64 = cm_roam_switch_to_init(a1, a2, a4);
          goto LABEL_32;
        case 2:
          v64 = cm_roam_switch_to_rso_enable(a1, a2, a4);
LABEL_32:
          v35 = v64;
          goto LABEL_33;
      }
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: ROAM: Invalid roam state %d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "cm_roam_state_change",
      (unsigned int)a3);
    v35 = 0;
LABEL_33:
    v56 = cm_roam_release_lock(v45);
    goto LABEL_34;
  }
  v35 = v46;
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: Fail to acquire lock, status: %d",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "cm_roam_state_change",
    v46);
LABEL_34:
  wlan_objmgr_vdev_release_ref(v45, 0x4Du, v55, v56, v57, v58, v59, v60, v61, v62, v63);
LABEL_35:
  roam_state = mlme_get_roam_state(v6, a2);
  v66 = *(_QWORD *)(a1 + 80);
  if ( v66 )
  {
    v67 = roam_state;
    v68 = mlme_get_roam_state(*(_QWORD *)(a1 + 80), a2);
    rso_disabled_bitmap = mlme_get_rso_disabled_bitmap(v66, a2);
    supplicant_disabled_roaming = mlme_get_supplicant_disabled_roaming(v66, a2);
    v71 = wlan_cm_roaming_in_progress(a1, a2);
    if ( is_up )
      v72 = 2;
    else
      v72 = 3;
    if ( (supplicant_disabled_roaming & 1) == 0 )
      v72 = is_up == 0;
    if ( (v71 & 1) != 0 )
      v73 = v72 | 4;
    else
      v73 = v72;
    wlan_rec_debug_log(
      (char *)&off_0 + 1,
      a2,
      0x19u,
      0,
      nullptr,
      0,
      a3 & 0xF | ((unsigned __int8)v35 << 12) | (unsigned __int8)(16 * (v67 & 0xF)) | ((v68 & 0xF) << 8),
      v73 & 0xFFF80007 | (8 * rso_disabled_bitmap) & 0x7FF | ((unsigned __int8)a4 << 11));
  }
  return v35;
}
