__int64 __fastcall nan_disable_cleanup(
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
  __int64 comp_private_obj; // x0
  __int64 v11; // x20
  __int64 pdev_by_id; // x0
  __int64 v13; // x19
  _QWORD *first_vdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v51; // x2
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  void (__fastcall *v61)(_QWORD); // x24
  unsigned int v62; // w23
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int *v80; // x8
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned int *v89; // x8
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x0
  void (__fastcall *v99)(_QWORD); // x8

  if ( !a1 )
  {
    v51 = "%s: psoc is NULL";
LABEL_10:
    qdf_trace_msg(0x53u, 2u, v51, a2, a3, a4, a5, a6, a7, a8, a9, "nan_disable_cleanup");
    return 29;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
    v51 = "%s: psoc_nan_obj is NULL";
    goto LABEL_10;
  }
  v11 = comp_private_obj;
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 0x14u);
  if ( !pdev_by_id )
  {
    v51 = "%s: null pdev";
    goto LABEL_10;
  }
  v13 = pdev_by_id;
  first_vdev = wlan_objmgr_pdev_get_first_vdev(pdev_by_id, 0x14u);
  if ( !first_vdev )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: No vdev is up yet, unable to proceed!",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "nan_disable_cleanup");
    wlan_objmgr_pdev_release_ref(v13, 0x14u, v52, v53, v54, v55, v56, v57, v58, v59, v60);
    return 29;
  }
  v23 = (__int64)first_vdev;
  if ( (unsigned int)nan_set_discovery_state(a1, 0, v15, v16, v17, v18, v19, v20, v21, v22) )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Cannot set NAN state to disabled!",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "nan_disable_cleanup");
    wlan_objmgr_pdev_release_ref(v13, 0x14u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    wlan_objmgr_vdev_release_ref(v23, 0x14u, v41, v42, v43, v44, v45, v46, v47, v48, v49);
    return 16;
  }
  else
  {
    v61 = *(void (__fastcall **)(_QWORD))(v11 + 32);
    v62 = policy_mgr_mode_specific_vdev_id(a1, 5);
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: NAN vdev_id: %u",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "nan_disable_cleanup",
      (unsigned __int8)v62);
    policy_mgr_decr_session_set_pcl(a1, 0x10u, v62);
    if ( *(_BYTE *)(v11 + 285) == 1 && v61 )
    {
      v71 = *(_QWORD *)(v11 + 296);
      if ( *((_DWORD *)v61 - 1) != 251140989 )
        __break(0x8238u);
      v61(v71);
    }
    if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) == 0 || (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0 )
      wlan_handle_emlsr_sta_concurrency(a1, 0, 1);
    policy_mgr_nan_sap_post_disable_conc_check(a1);
    nan_cstats_log_nan_disable_resp_evt(v62, a1);
    if_mgr_deliver_event(v23, 0x17u, 0, v72, v73, v74, v75, v76, v77, v78, v79);
    wlan_objmgr_pdev_release_ref(v13, 0x14u, v80, v81, v82, v83, v84, v85, v86, v87, v88);
    v98 = wlan_objmgr_vdev_release_ref(v23, 0x14u, v89, v90, v91, v92, v93, v94, v95, v96, v97);
    v99 = *(void (__fastcall **)(_QWORD))(v11 + 144);
    if ( v99 )
    {
      if ( *((_DWORD *)v99 - 1) != -440107680 )
        __break(0x8228u);
      v99(v98);
    }
    return 0;
  }
}
