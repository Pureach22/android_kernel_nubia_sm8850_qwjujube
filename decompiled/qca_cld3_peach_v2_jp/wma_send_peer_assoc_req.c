__int64 __fastcall wma_send_peer_assoc_req(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w24
  unsigned int v38; // w20
  __int64 v39; // x25
  __int64 *v40; // x19
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  _QWORD *v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  __int64 (*v59)(void); // x8
  char v60; // w0
  __int64 v61; // x4
  __int64 v62; // x5
  __int64 v63; // x6
  __int64 v64; // x7
  const char *v65; // x2
  const char *v66; // x3
  unsigned int v67; // w0
  unsigned int v68; // w1
  __int64 v69; // x4
  __int64 v70; // x5
  __int64 v71; // x6
  __int64 v72; // x7
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v83; // x4
  __int64 v84; // x5
  __int64 v85; // x6
  __int64 v86; // x7
  double v87; // d0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x23
  unsigned int v97; // w22
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  _QWORD *v106; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v123; // x1
  unsigned int v124; // w0
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // x22
  char v134; // w6
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  __int64 cmpt_obj; // x0
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(53, (__int64)"wma_send_peer_assoc_req", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = _cds_get_context(71, (__int64)"wma_send_peer_assoc_req", v11, v12, v13, v14, v15, v16, v17, v18);
  v28 = _cds_get_context(54, (__int64)"wma_send_peer_assoc_req", v20, v21, v22, v23, v24, v25, v26, v27);
  v37 = 4;
  if ( !v28 || !context || !v19 )
    goto LABEL_31;
  v38 = a1[151];
  v39 = v28[65];
  v40 = v28;
  if ( (unsigned int)wma_update_iface_params((__int64)v28, (__int64)a1, v29, v30, v31, v32, v33, v34, v35, v36) )
  {
    v37 = 1;
    goto LABEL_29;
  }
  v49 = _cds_get_context(71, (__int64)"wma_cdp_find_peer_by_addr", v41, v42, v43, v44, v45, v46, v47, v48);
  if ( !v49 )
  {
    v65 = "%s: Failed to get pdev/soc";
    v66 = "wma_cdp_find_peer_by_addr";
    v67 = 54;
    v68 = 2;
    goto LABEL_21;
  }
  if ( !*v49 || (v58 = *(_QWORD *)(*v49 + 72LL)) == 0 )
  {
    v65 = "%s invalid instance";
    v66 = "cdp_find_peer_exist";
    v67 = 69;
    v68 = 1;
LABEL_21:
    qdf_trace_msg(v67, v68, v65, v50, v51, v52, v53, v54, v55, v56, v57, v66);
LABEL_22:
    if ( a1[292] )
      goto LABEL_23;
LABEL_25:
    v37 = 0;
    goto LABEL_29;
  }
  v59 = *(__int64 (**)(void))(v58 + 16);
  if ( !v59 )
    goto LABEL_22;
  if ( *((_DWORD *)v59 - 1) != 454466150 )
    __break(0x8228u);
  v60 = v59();
  if ( a1[300] )
  {
    v37 = 0;
    if ( (v60 & 1) != 0 )
      goto LABEL_29;
  }
  if ( !a1[292] )
    goto LABEL_25;
  if ( (v60 & 1) == 0 )
  {
LABEL_23:
    if ( a1 )
    {
      v69 = *a1;
      v70 = a1[1];
      v71 = a1[2];
      v72 = a1[5];
    }
    else
    {
      v71 = 0;
      v69 = 0;
      v70 = 0;
      v72 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to find peer %02x:%02x:%02x:**:**:%02x",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wma_send_peer_assoc_req",
      v69,
      v70,
      v71,
      v72);
    goto LABEL_28;
  }
  if ( *((_DWORD *)a1 + 32) )
  {
    if ( a1 )
    {
      v61 = *a1;
      v62 = a1[1];
      v63 = a1[2];
      v64 = a1[5];
    }
    else
    {
      v63 = 0;
      v61 = 0;
      v62 = 0;
      v64 = 0;
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Update peer(%02x:%02x:%02x:**:**:%02x) state into conn",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wma_send_peer_assoc_req",
      v61,
      v62,
      v63,
      v64);
    v87 = cdp_peer_state_update(v19, a1, 2);
    wma_set_cdp_vdev_pause_reason(v38, v87);
  }
  else
  {
    if ( a1 )
    {
      v83 = *a1;
      v84 = a1[1];
      v85 = a1[2];
      v86 = a1[5];
    }
    else
    {
      v85 = 0;
      v83 = 0;
      v84 = 0;
      v86 = 0;
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Update peer(%02x:%02x:%02x:**:**:%02x) state into auth",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wma_send_peer_assoc_req",
      v83,
      v84,
      v85,
      v86);
    v88 = cdp_peer_state_update(v19, a1, 3);
  }
  wmi_unified_send_txbf(v40, a1 + 20, v88, v89, v90, v91, v92, v93, v94, v95);
  v96 = *v40;
  v97 = (*(unsigned __int8 *)(context[1] + 3333LL) << 31) | 0x200;
  v106 = _cds_get_context(54, (__int64)"wma_is_vdev_valid", v98, v99, v100, v101, v102, v103, v104, v105);
  if ( !v106 )
    goto LABEL_44;
  if ( *((unsigned __int16 *)v106 + 81) <= v38 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id: %d is invalid, max_bssid: %d",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "wma_is_vdev_valid",
      v38);
    goto LABEL_44;
  }
  if ( (*(_BYTE *)(v106[65] + 488LL * v38 + 184) & 1) == 0 )
  {
LABEL_44:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev_id: %d is not active reject the req: param id %d val %d",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "wma_vdev_set_param",
      v38,
      46,
      v97);
    goto LABEL_45;
  }
  if ( !(unsigned int)wmi_unified_vdev_set_param_send(v96) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Sent packet power save %x",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "wma_send_peer_assoc_req",
      v97);
    goto LABEL_46;
  }
LABEL_45:
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Failed to send wmi packet power save cmd",
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    "wma_send_peer_assoc_req");
LABEL_46:
  v123 = *((unsigned int *)a1 + 2);
  a1[263] = a1[308];
  v124 = wma_send_peer_assoc(v40, v123, a1 + 20);
  if ( v124 )
  {
    v37 = v124;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send peer assoc status:%d",
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      "wma_send_peer_assoc_req",
      v124);
    goto LABEL_29;
  }
  v133 = v39 + 488LL * v38;
  if ( *((_DWORD *)a1 + 32) )
    *(_BYTE *)(v133 + 432) = 1;
  if ( a1[18] )
    wma_set_mgmt_frame_protection(v40);
  if ( (wlan_reg_is_ext_tpc_supported(v40[3], v125, v126, v127, v128, v129, v130, v131, v132) & 1) != 0 )
  {
    v134 = 0;
    a1[293] = 0;
  }
  else
  {
    v134 = a1[293];
  }
  if ( (unsigned int)wma_vdev_set_bss_params(v40, a1[151], *((_WORD *)a1 + 7), a1[16], a1[12], a1[13], v134) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to set bss params",
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      "wma_send_peer_assoc_req");
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v133, v135, v136, v137, v138, v139, v140, v141, v142);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to mlme obj",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "wma_send_peer_assoc_req");
LABEL_28:
    v37 = 16;
    goto LABEL_29;
  }
  qdf_mem_copy((void *)(cmpt_obj + 168), a1, 6u);
  wma_save_bss_params((__int64)v40, a1);
  if ( (wmi_service_enabled(*v40, 0x68u, v152, v153, v154, v155, v156, v157, v158, v159) & 1) != 0 )
  {
    if ( wma_fill_hold_req(v40, v38, 0x1025u, 1u, nullptr, 0, 0xFA0u) )
    {
      v37 = 0;
      goto LABEL_31;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to allocate request for vdev_id %d",
      v168,
      v169,
      v170,
      v171,
      v172,
      v173,
      v174,
      v175,
      "wma_send_peer_assoc_req",
      v38);
    wma_remove_req((__int64)v40, v38, 1u, v176, v177, v178, v179, v180, v181, v182, v183);
    goto LABEL_28;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMI_SERVICE_PEER_ASSOC_CONF not enabled",
    v160,
    v161,
    v162,
    v163,
    v164,
    v165,
    v166,
    v167,
    "wma_send_peer_assoc_req");
  v37 = 0;
LABEL_29:
  v73 = _qdf_mem_malloc(0x10u, "wma_send_add_bss_resp", 4863);
  if ( v73 )
  {
    *(_BYTE *)v73 = v38;
    *(_DWORD *)(v73 + 4) = v37;
    lim_handle_add_bss_rsp(v40[2], (unsigned __int8 *)v73, v74, v75, v76, v77, v78, v79, v80, v81);
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v37;
}
