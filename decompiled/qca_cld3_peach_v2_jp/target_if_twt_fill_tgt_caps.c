__int64 __fastcall target_if_twt_fill_tgt_caps(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  unsigned __int8 *v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  char v93; // w0
  __int64 v94; // x4
  __int64 v95; // x5
  __int64 v96; // x6
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
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  const char *v130; // x2

  if ( a1 && a2 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
    if ( comp_private_obj )
    {
      v12 = (unsigned __int8 *)comp_private_obj;
      *(_BYTE *)(comp_private_obj + 20) = wmi_service_enabled(a2, 0x9Au, a3, a4, a5, a6, a7, a8, a9, a10) & 1;
      v12[21] = wmi_service_enabled(a2, 0x9Bu, v13, v14, v15, v16, v17, v18, v19, v20) & 1;
      v12[22] = wmi_service_enabled(a2, 0xB0u, v21, v22, v23, v24, v25, v26, v27, v28) & 1;
      v12[23] = wmi_service_enabled(a2, 0xDFu, v29, v30, v31, v32, v33, v34, v35, v36) & 1;
      v12[24] = wmi_service_enabled(a2, 0xE0u, v37, v38, v39, v40, v41, v42, v43, v44) & 1;
      v12[25] = wmi_service_enabled(a2, 0xE2u, v45, v46, v47, v48, v49, v50, v51, v52) & 1;
      v12[26] = wmi_service_enabled(a2, 0xE3u, v53, v54, v55, v56, v57, v58, v59, v60) & 1;
      v12[27] = wmi_service_enabled(a2, 0xE4u, v61, v62, v63, v64, v65, v66, v67, v68) & 1;
      v12[29] = wmi_service_enabled(a2, 0xE5u, v69, v70, v71, v72, v73, v74, v75, v76) & 1;
      v12[30] = wmi_service_enabled(a2, 0x144u, v77, v78, v79, v80, v81, v82, v83, v84) & 1;
      v93 = wmi_service_enabled(a2, 0x147u, v85, v86, v87, v88, v89, v90, v91, v92);
      v94 = v12[20];
      v95 = v12[21];
      v96 = v12[22];
      v12[40] = v93 & 1;
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: req:%d res:%d legacy_bcast_twt_support:%d",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "target_if_twt_fill_tgt_caps",
        v94,
        v95,
        v96);
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: twt_bcast_req_support:%d twt_bcast_res_support:%d",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "target_if_twt_fill_tgt_caps",
        v12[23],
        v12[24]);
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: nudge_enabled:%d all_twt_enabled:%d stats_enabled:%d",
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        "target_if_twt_fill_tgt_caps",
        v12[25],
        v12[26],
        v12[27]);
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: restricted_twt_support:%d p2p_go_concurrency_support %d twt_resp_disable_per_vdev %d",
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        "target_if_twt_fill_tgt_caps",
        v12[29],
        v12[30],
        v12[40]);
      return 0;
    }
    v130 = "%s: null twt psoc priv obj";
  }
  else
  {
    v130 = "%s: null wmi_handle or psoc";
  }
  qdf_trace_msg(0x49u, 2u, v130, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_twt_fill_tgt_caps");
  return 16;
}
