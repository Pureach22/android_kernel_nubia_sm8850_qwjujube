__int64 __fastcall nan_discovery_pre_enable(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  const char *v23; // x2
  const char *v24; // x3
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w0
  const char *v51; // x2
  const char *v52; // x3
  unsigned int v53; // w1
  __int64 pdev_by_id; // x0
  __int64 v55; // x22
  _QWORD *first_vdev; // x0
  unsigned int *v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int8 v66; // w23
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int *v84; // x8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int *v93; // x8
  __int64 v94; // x21
  unsigned int v95; // w0
  _QWORD *v96; // x0
  __int64 v97; // x19
  unsigned int *v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7

  v10 = *(_QWORD *)(a1 + 80);
  if ( v10 )
  {
    v13 = nan_set_discovery_state(*(_QWORD *)(a1 + 80), 1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( v13 )
    {
      v22 = v13;
      v23 = "%s: Unable to set NAN Disc State to ENABLE_IN_PROGRESS";
LABEL_4:
      v24 = "nan_discovery_pre_enable";
LABEL_5:
      qdf_trace_msg(0x53u, 2u, v23, v14, v15, v16, v17, v18, v19, v20, v21, v24);
LABEL_6:
      nan_set_discovery_state(v10, 0, v25, v26, v27, v28, v29, v30, v31, v32);
      return v22;
    }
    if ( (unsigned int)policy_mgr_get_sap_mode_count(v10, nullptr)
      && (policy_mgr_nan_sap_pre_enable_conc_check(v10, 5u, a2) & 1) == 0 )
    {
      v51 = "%s: NAN not enabled due to concurrency constraints";
      v52 = "nan_discovery_pre_enable";
      v53 = 8;
LABEL_18:
      qdf_trace_msg(0x53u, v53, v51, v34, v35, v36, v37, v38, v39, v40, v41, v52);
      v22 = 4;
      goto LABEL_6;
    }
    if ( (unsigned int)policy_mgr_mode_specific_connection_count(v10, 0, nullptr) >= 2 )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: STA+STA+NAN concurrency is not allowed",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "nan_discovery_pre_enable");
      v22 = 16;
      goto LABEL_6;
    }
    wlan_p2p_abort_scan(a1);
    if ( (policy_mgr_is_hw_dbs_capable(v10) & 1) != 0 )
    {
      policy_mgr_stop_opportunistic_timer(v10);
      if ( (unsigned int)policy_mgr_is_hw_mode_change_in_progress(v10) )
      {
        v50 = policy_mgr_wait_for_connection_update(v10);
        if ( v50 )
        {
          v22 = v50;
          v23 = "%s: Failed to wait for connection update";
          v24 = "nan_set_hw_mode";
          goto LABEL_5;
        }
      }
      pdev_by_id = wlan_objmgr_get_pdev_by_id(v10, 0, 0x14u);
      if ( !pdev_by_id )
      {
        v51 = "%s: null pdev";
        v52 = "nan_set_hw_mode";
LABEL_36:
        v53 = 2;
        goto LABEL_18;
      }
      v55 = pdev_by_id;
      first_vdev = wlan_objmgr_pdev_get_first_vdev(pdev_by_id, 0x14u);
      if ( !first_vdev )
      {
        qdf_trace_msg(
          0x53u,
          2u,
          "%s: No vdev is up yet, unable to proceed!",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "nan_set_hw_mode");
        v22 = 4;
        goto LABEL_29;
      }
      v66 = *((_BYTE *)first_vdev + 104);
      wlan_objmgr_vdev_release_ref((__int64)first_vdev, 0x14u, v57, v58, v59, v60, v61, v62, v63, v64, v65);
      v75 = policy_mgr_update_and_wait_for_connection_update(v10, v66, a2, 0xBu, v67, v68, v69, v70, v71, v72, v73, v74);
      if ( v75 )
      {
        v22 = v75;
        qdf_trace_msg(
          0x53u,
          2u,
          "%s: Failed to set or wait for HW mode change",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "nan_set_hw_mode");
LABEL_29:
        wlan_objmgr_pdev_release_ref(v55, 0x14u, v84, v85, v86, v87, v88, v89, v90, v91, v92);
        goto LABEL_6;
      }
      if ( (wlan_util_is_vdev_in_cac_wait(v55, 0x14u) & 1) != 0 )
      {
        v94 = jiffies;
        v84 = (unsigned int *)(nan_set_hw_mode___last_ticks - jiffies);
        if ( nan_set_hw_mode___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(0x53u, 2u, "%s: cac is in progress", v85, v86, v87, v88, v89, v90, v91, v92, "nan_set_hw_mode");
          nan_set_hw_mode___last_ticks = v94;
        }
        v22 = 16;
        goto LABEL_29;
      }
      wlan_objmgr_pdev_release_ref(v55, 0x14u, v93, v85, v86, v87, v88, v89, v90, v91, v92);
    }
    v95 = ucfg_tdls_teardown_links(v10);
    if ( v95 )
    {
      v22 = v95;
      v23 = "%s: Failed to teardown TDLS links";
      goto LABEL_4;
    }
    v96 = wlan_objmgr_pdev_get_first_vdev(a1, 0x14u);
    if ( v96 )
    {
      v97 = (__int64)v96;
      if_mgr_deliver_event((__int64)v96, 0x15u, 0, v34, v35, v36, v37, v38, v39, v40, v41);
      wlan_objmgr_vdev_release_ref(v97, 0x14u, v98, v99, v100, v101, v102, v103, v104, v105, v106);
      return 0;
    }
    v51 = "%s: No vdev is up yet, unable to proceed!";
    v52 = "nan_discovery_pre_enable";
    goto LABEL_36;
  }
  qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_discovery_pre_enable");
  return 4;
}
