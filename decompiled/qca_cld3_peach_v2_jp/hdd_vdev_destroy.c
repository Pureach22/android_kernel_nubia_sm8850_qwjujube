__int64 __fastcall hdd_vdev_destroy(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v20; // x19
  __int64 vdev_by_user; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x23
  __int64 v32; // x21
  unsigned int v33; // w22
  int v34; // w25
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v44; // x8
  unsigned int *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w24
  __int64 link_info_by_vdev; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  __int64 v65; // x26
  __int64 v66; // x25
  unsigned int v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w23
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 adapter; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x20
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  unsigned __int64 v117; // x10

  v9 = *(unsigned __int8 *)(a1 + 8);
  qdf_trace_msg(0x33u, 8u, "destroying vdev %d", a2, a3, a4, a5, a6, a7, a8, a9, *(unsigned __int8 *)(a1 + 8));
  if ( (*(_QWORD *)(a1 + 4416) & 1) == 0 )
  {
    qdf_trace_msg(0x33u, 8u, "vdev %u does not exist", v11, v12, v13, v14, v15, v16, v17, v18, v9);
    return 4294967274LL;
  }
  v20 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_vdev_destroy");
  if ( !vdev_by_user )
    return 4294967274LL;
  v30 = *(_QWORD *)(vdev_by_user + 152);
  v31 = vdev_by_user;
  if ( !v30 || (v32 = *(_QWORD *)(v30 + 80)) == 0 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: invalid psoc", v22, v23, v24, v25, v26, v27, v28, v29, "hdd_vdev_destroy");
    return 4294967274LL;
  }
  v33 = *(_DWORD *)(vdev_by_user + 16);
  v34 = policy_mgr_qdf_opmode_to_pm_con_mode(
          *(_QWORD *)(v30 + 80),
          v33,
          *(_BYTE *)(vdev_by_user + 104),
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
  if ( (unsigned int)policy_mgr_get_connection_count(v32) == 1
    && (unsigned int)policy_mgr_mode_specific_connection_count(v32, v34, nullptr) == 1
    || !(unsigned int)policy_mgr_get_connection_count(v32)
    && (hdd_is_sta_connect_or_link_switch_in_prog((__int64)v20, v33, v35, v36, v37, v38, v39, v40, v41, v42) & 1) == 0 )
  {
    policy_mgr_check_and_stop_opportunistic_timer(v32, *(_BYTE *)(v31 + 104));
  }
  if ( !(unsigned int)_wlan_hdd_validate_context(
                        (__int64)v20,
                        (__int64)"hdd_check_wait_for_hw_mode_completion",
                        v35,
                        v36,
                        v37,
                        v38,
                        v39,
                        v40,
                        v41,
                        v42)
    && (unsigned int)policy_mgr_is_hw_mode_change_in_progress(*v20)
    && (unsigned int)policy_mgr_wait_for_connection_update(*v20) )
  {
    qdf_trace_msg(0x33u, 8u, "qdf wait for hw mode event failed!!", v77, v78, v79, v80, v81, v82, v83, v84);
  }
  ucfg_scan_vdev_set_disable(v31, 8);
  wlan_hdd_scan_abort(a1);
  ucfg_pmo_del_wow_pattern(v31);
  _hdd_objmgr_put_vdev_by_user(v31, 6, "hdd_vdev_destroy");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 16);
    v44 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(a1 + 32) = 0;
    if ( (v44 & 1) == 0 )
    {
LABEL_16:
      raw_spin_unlock(a1 + 16);
      goto LABEL_17;
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 16);
    v44 = *(_QWORD *)(a1 + 24) | 1LL;
    *(_QWORD *)(a1 + 24) = v44;
    *(_QWORD *)(a1 + 32) = 0;
    if ( (v44 & 1) == 0 )
      goto LABEL_16;
  }
  *(_QWORD *)(a1 + 24) = v44 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 16);
LABEL_17:
  osif_cm_osif_priv_deinit(v31);
  wlan_objmgr_vdev_release_ref(v31, 5u, v45, v46, v47, v48, v49, v50, v51, v52, v53);
  qdf_runtime_pm_prevent_suspend(v20 + 215);
  v54 = *(unsigned __int8 *)(v31 + 104);
  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)v20, v54);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid vdev", v56, v57, v58, v59, v60, v61, v62, v63, "hdd_vdev_destroy_event_wait");
LABEL_29:
    v76 = -22;
    goto LABEL_30;
  }
  v64 = *(_QWORD *)(v31 + 152);
  if ( !v64 || !*(_QWORD *)(v64 + 80) )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: Failed to get psoc",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "hdd_vdev_destroy_event_wait");
    v76 = 16;
    goto LABEL_30;
  }
  v65 = link_info_by_vdev;
  *(_DWORD *)(link_info_by_vdev + 40) = 0;
  v66 = link_info_by_vdev + 40;
  v67 = sme_vdev_delete(v20[2], v31);
  if ( v67 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d: failed to delete with status:%d",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "hdd_vdev_destroy_event_wait",
      v54,
      v67);
    v76 = -11;
    goto LABEL_30;
  }
  if ( !wait_for_completion_timeout(v66, 5001) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d: timed out waiting for delete",
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      "hdd_vdev_destroy_event_wait",
      v54);
    _X8 = (unsigned __int64 *)(v65 + 4416);
    __asm { PRFM            #0x11, [X8] }
    do
      v117 = __ldxr(_X8);
    while ( __stxr(v117 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    v103 = sme_cleanup_session(v20[2], v54);
    cds_flush_logs(1u, 2u, 15, 1, 1, v103, v104, v105, v106, v107, v108, v109, v110);
    goto LABEL_29;
  }
  qdf_trace_msg(0x33u, 4u, "vdev %d destroyed successfully", v95, v96, v97, v98, v99, v100, v101, v102, v54);
  v76 = 0;
LABEL_30:
  ucfg_reg_11d_vdev_delete_update(v32, v33, v9);
  if ( !v33 && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*v20) & 1) != 0 )
  {
    adapter = hdd_get_adapter((__int64)v20, 7);
    if ( adapter )
    {
      v94 = adapter;
      ucfg_p2p_set_sta_vdev_for_p2p_dev_operations(*v20, 0);
      hdd_vdev_create(*(_QWORD *)(v94 + 52824));
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to get p2p device adapter",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "hdd_create_p2p_device_vdev_during_sta_vdev_destroy");
    }
  }
  qdf_runtime_pm_allow_suspend(v20 + 215);
  return v76;
}
