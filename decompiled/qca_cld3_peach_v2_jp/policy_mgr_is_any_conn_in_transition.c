__int64 __fastcall policy_mgr_is_any_conn_in_transition(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned int v11; // w20
  _QWORD *vdev_by_id_from_pdev; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  bool is_vdev_connected; // w22
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  _QWORD *v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x21
  bool v51; // w22
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _QWORD *v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x21
  bool v71; // w22
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _QWORD *v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x21
  bool v91; // w22
  unsigned int *v92; // x8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  _QWORD *v101; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x21
  bool v111; // w22
  unsigned int *v112; // x8
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_81C458) == 1 && ((unsigned int)pm_conc_connection_list | 2) == 2 )
    {
      v11 = (unsigned __int8)qword_81C458;
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v10 + 8), qword_81C458, 0x18u);
      if ( vdev_by_id_from_pdev )
      {
        v21 = (__int64)vdev_by_id_from_pdev;
        is_vdev_connected = wlan_cm_is_vdev_connected(
                              (__int64)vdev_by_id_from_pdev,
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20);
        wlan_objmgr_vdev_release_ref(v21, 0x18u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
        if ( !is_vdev_connected )
          goto LABEL_31;
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: vdev %d: not found",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "policy_mgr_is_any_conn_in_transition",
          v11);
      }
    }
    if ( BYTE4(qword_81C47C) == 1 && ((unsigned int)qword_81C464 | 2) == 2 )
    {
      v11 = (unsigned __int8)qword_81C47C;
      v41 = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v10 + 8), qword_81C47C, 0x18u);
      if ( v41 )
      {
        v50 = (__int64)v41;
        v51 = wlan_cm_is_vdev_connected((__int64)v41, v42, v43, v44, v45, v46, v47, v48, v49);
        wlan_objmgr_vdev_release_ref(v50, 0x18u, v52, v53, v54, v55, v56, v57, v58, v59, v60);
        if ( !v51 )
          goto LABEL_31;
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: vdev %d: not found",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "policy_mgr_is_any_conn_in_transition",
          v11);
      }
    }
    if ( BYTE4(qword_81C4A0) == 1 && ((unsigned int)qword_81C488 | 2) == 2 )
    {
      v11 = (unsigned __int8)qword_81C4A0;
      v61 = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v10 + 8), qword_81C4A0, 0x18u);
      if ( v61 )
      {
        v70 = (__int64)v61;
        v71 = wlan_cm_is_vdev_connected((__int64)v61, v62, v63, v64, v65, v66, v67, v68, v69);
        wlan_objmgr_vdev_release_ref(v70, 0x18u, v72, v73, v74, v75, v76, v77, v78, v79, v80);
        if ( !v71 )
          goto LABEL_31;
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: vdev %d: not found",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "policy_mgr_is_any_conn_in_transition",
          v11);
      }
    }
    if ( BYTE4(qword_81C4C4) == 1 && ((unsigned int)qword_81C4AC | 2) == 2 )
    {
      v11 = (unsigned __int8)qword_81C4C4;
      v81 = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v10 + 8), qword_81C4C4, 0x18u);
      if ( v81 )
      {
        v90 = (__int64)v81;
        v91 = wlan_cm_is_vdev_connected((__int64)v81, v82, v83, v84, v85, v86, v87, v88, v89);
        wlan_objmgr_vdev_release_ref(v90, 0x18u, v92, v93, v94, v95, v96, v97, v98, v99, v100);
        if ( !v91 )
          goto LABEL_31;
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: vdev %d: not found",
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          "policy_mgr_is_any_conn_in_transition",
          v11);
      }
    }
    if ( BYTE4(qword_81C4E8) == 1 && ((unsigned int)qword_81C4D0 | 2) == 2 )
    {
      v11 = (unsigned __int8)qword_81C4E8;
      v101 = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v10 + 8), qword_81C4E8, 0x18u);
      if ( v101 )
      {
        v110 = (__int64)v101;
        v111 = wlan_cm_is_vdev_connected((__int64)v101, v102, v103, v104, v105, v106, v107, v108, v109);
        wlan_objmgr_vdev_release_ref(v110, 0x18u, v112, v113, v114, v115, v116, v117, v118, v119, v120);
        if ( !v111 )
        {
LABEL_31:
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: vdev %d: is in transition state",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "policy_mgr_is_any_conn_in_transition",
            v11);
          v40 = 1;
LABEL_34:
          qdf_mutex_release(v10 + 56);
          return v40;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: vdev %d: not found",
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          "policy_mgr_is_any_conn_in_transition",
          v11);
      }
    }
    v40 = 0;
    goto LABEL_34;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid pm context",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "policy_mgr_is_any_conn_in_transition");
  return 0;
}
