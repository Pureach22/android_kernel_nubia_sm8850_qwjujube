__int64 __fastcall ucfg_nan_disable_ndi(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x22
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w23
  unsigned int *v87; // x8
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int *v96; // x8
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  _QWORD v121[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a2;
  v121[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v121[0] = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 20);
  if ( !v4 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Cannot obtain NDI vdev object!",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "ucfg_nan_disable_ndi");
    result = 4;
    goto LABEL_19;
  }
  v13 = v4;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v4, 0xFu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: ndi vdev priv object is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ucfg_nan_disable_ndi");
    wlan_objmgr_vdev_release_ref(v13, 0x14u, v34, v35, v36, v37, v38, v39, v40, v41, v42);
    result = 4;
    goto LABEL_19;
  }
  v23 = comp_private_obj;
  if ( (unsigned int)wlan_nan_get_ndi_state(v13) == 8 )
  {
    wlan_objmgr_vdev_release_ref(v13, 0x14u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
    result = 0;
    goto LABEL_19;
  }
  _ucfg_nan_set_ndi_state(v13, 8u, (__int64)"ucfg_nan_disable_ndi", v25, v26, v27, v28, v29, v30, v31, v32);
  if ( (cds_get_driver_state(v43, v44, v45, v46, v47, v48, v49, v50) & 8) != 0 )
  {
    nan_clean_up_all_ndp_peers(a1, v2, v51, v52, v53, v54, v55, v56, v57, v58);
    wlan_objmgr_vdev_release_ref(v13, 0x14u, v96, v97, v98, v99, v100, v101, v102, v103, v104);
    v68 = 0;
LABEL_12:
    v86 = 0;
    goto LABEL_16;
  }
  v59 = osif_request_alloc(ucfg_nan_disable_ndi_params);
  v68 = v59;
  if ( !v59 )
  {
    v86 = 2;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Request allocation failure",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "ucfg_nan_disable_ndi");
    goto LABEL_16;
  }
  *(_QWORD *)(v23 + 48) = osif_request_cookie(v59);
  v121[0] = v13;
  v77 = ucfg_nan_req_processor(0, v121, 0x10u, v69, v70, v71, v72, v73, v74, v75, v76);
  if ( !v77 )
  {
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: Disabling all NDP's on NDI vdev id - %d",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "ucfg_nan_disable_ndi",
      v2);
    if ( (unsigned int)osif_request_wait_for_response(v68) )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: Disabling NDP's timed out waiting for confirmation",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "ucfg_nan_disable_ndi");
      v86 = 15;
      goto LABEL_16;
    }
    goto LABEL_12;
  }
  v86 = v77;
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: Unable to disable NDP's on NDI",
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    "ucfg_nan_disable_ndi");
  wlan_objmgr_vdev_release_ref(v13, 0x14u, v87, v88, v89, v90, v91, v92, v93, v94, v95);
LABEL_16:
  policy_mgr_decr_session_set_pcl(a1, 0xBu, v2);
  _ucfg_nan_set_ndi_state(v13, 9u, (__int64)"ucfg_nan_disable_ndi", v113, v114, v115, v116, v117, v118, v119, v120);
  if ( v68 )
    osif_request_put(v68);
  result = v86;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
