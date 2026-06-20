__int64 __fastcall wma_set_force_sleep(
        __int64 *a1,
        unsigned int a2,
        unsigned __int8 a3,
        unsigned int *a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _QWORD *context; // x21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _BOOL4 v35; // w26
  unsigned int v36; // w25
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int8 max_ps_poll; // w23
  unsigned int v46; // w27
  __int64 v47; // x27
  unsigned int v48; // w28
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x4
  __int64 v58; // x27
  unsigned int v59; // w28
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x27
  unsigned int v77; // w28
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x24
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
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
  unsigned int v111; // w0
  const char *v112; // x2
  const char *v113; // x4
  __int64 v115; // x5
  const char *v116; // x2
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  unsigned int v125; // w0
  __int64 v126; // x0
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  __int64 v135; // x22
  double listen_interval; // d0
  int v137; // w0
  int v138; // w23
  unsigned int *v139; // x8
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  __int64 v147; // x0
  unsigned int v148; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v149; // [xsp+Ch] [xbp-14h]
  int v150; // [xsp+10h] [xbp-10h]
  _BOOL4 v151; // [xsp+14h] [xbp-Ch]
  __int64 v152; // [xsp+18h] [xbp-8h]

  v152 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_set_force_sleep", a6, a7, a8, a9, a10, a11, a12, a13);
  v148 = 0;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Force Sleep vdevId %d val %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wma_set_force_sleep",
    a2,
    a3);
  if ( !context )
  {
    v46 = 2;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Unable to get PE context",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wma_set_force_sleep");
    goto LABEL_29;
  }
  v35 = a3 != 0;
  v36 = a3 == 0;
  if ( (unsigned __int8)ucfg_pmo_get_max_ps_poll(context[2703]) )
  {
    max_ps_poll = ucfg_pmo_get_max_ps_poll(context[2703]);
    v36 = 0;
    v35 = 1;
  }
  else
  {
    max_ps_poll = a3 != 0;
  }
  v47 = *a1;
  v48 = *a4;
  if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v37, v38, v39, v40, v41, v42, v43, v44) )
  {
    v46 = 16;
    goto LABEL_25;
  }
  if ( (wma_is_vdev_valid(a2, v49, v50, v51, v52, v53, v54, v55, v56) & 1) == 0 )
  {
    v46 = 4;
    goto LABEL_25;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Sta Ps param vdevId %d Param %d val %d",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "wma_unified_set_sta_ps_param",
    a2,
    6,
    v48);
  v149 = a2;
  v150 = 6;
  v151 = v48;
  v46 = wmi_unified_sta_ps_cmd_send(v47);
  if ( v46 )
  {
LABEL_25:
    if ( *a4 )
      v113 = "Enable";
    else
      v113 = "Disable";
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: %s(%d) Power Failed vdevId %d",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "wma_set_force_sleep",
      v113);
    goto LABEL_29;
  }
  if ( *a4 )
    v57 = "Enabled";
  else
    v57 = "Disabled";
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Power %s(%d) vdevId %d",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "wma_set_force_sleep",
    v57);
  v58 = *a1;
  v59 = *((unsigned __int16 *)a4 + 2);
  if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v60, v61, v62, v63, v64, v65, v66, v67) )
  {
    v46 = 16;
    goto LABEL_32;
  }
  if ( (wma_is_vdev_valid(a2, v68, v69, v70, v71, v72, v73, v74, v75) & 1) == 0 )
  {
    v46 = 4;
    goto LABEL_32;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Sta Ps param vdevId %d Param %d val %d",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "wma_unified_set_sta_ps_param",
    a2,
    3,
    v59);
  v149 = a2;
  v150 = 3;
  v151 = v59;
  v46 = wmi_unified_sta_ps_cmd_send(v58);
  if ( v46 )
  {
LABEL_32:
    v115 = *((unsigned __int16 *)a4 + 2);
    v116 = "%s: Setting Tx/Rx InActivity Failed vdevId %d InAct %d";
LABEL_33:
    qdf_trace_msg(0x36u, 2u, v116, v68, v69, v70, v71, v72, v73, v74, v75, "wma_set_force_sleep", a2, v115);
    goto LABEL_29;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Tx/Rx InActivity vdevId %d InAct %d",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "wma_set_force_sleep",
    a2,
    *((unsigned __int16 *)a4 + 2));
  v76 = *a1;
  v77 = *((unsigned __int16 *)a4 + 3);
  if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v78, v79, v80, v81, v82, v83, v84, v85) )
  {
    v46 = 16;
    goto LABEL_36;
  }
  if ( (wma_is_vdev_valid(a2, v68, v69, v70, v71, v72, v73, v74, v75) & 1) == 0 )
  {
    v46 = 4;
    goto LABEL_36;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Sta Ps param vdevId %d Param %d val %d",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "wma_unified_set_sta_ps_param",
    a2,
    12,
    v77);
  v149 = a2;
  v150 = 12;
  v151 = v77;
  v46 = wmi_unified_sta_ps_cmd_send(v76);
  if ( v46 )
  {
LABEL_36:
    v115 = *((unsigned __int16 *)a4 + 3);
    v116 = "%s: Setting Spec wake Failed vdevId %d InAct %d";
    goto LABEL_33;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Spec wake vdevId %d InAct %d",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "wma_set_force_sleep",
    a2,
    *((unsigned __int16 *)a4 + 3));
  v86 = *a1;
  if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v87, v88, v89, v90, v91, v92, v93, v94) )
  {
    v46 = 16;
    goto LABEL_39;
  }
  if ( (wma_is_vdev_valid(a2, v95, v96, v97, v98, v99, v100, v101, v102) & 1) == 0 )
  {
    v46 = 4;
    goto LABEL_39;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Sta Ps param vdevId %d Param %d val %d",
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    "wma_unified_set_sta_ps_param",
    a2,
    0,
    v35);
  v149 = a2;
  v150 = 0;
  v151 = v35;
  v46 = wmi_unified_sta_ps_cmd_send(v86);
  if ( v46 )
  {
LABEL_39:
    v112 = "%s: Setting wake policy Failed vdevId %d";
    goto LABEL_40;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Setting wake policy to %d vdevId %d",
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    "wma_set_force_sleep",
    v35,
    a2);
  v111 = wma_unified_set_sta_ps_param(*a1, a2, 1u, v36, v103, v104, v105, v106, v107, v108, v109, v110);
  if ( v111 )
  {
    v46 = v111;
    v112 = "%s: Setting TxWake Threshold vdevId %d";
LABEL_40:
    qdf_trace_msg(0x36u, 2u, v112, v95, v96, v97, v98, v99, v100, v101, v102, "wma_set_force_sleep", a2);
    goto LABEL_29;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Setting TxWake Threshold to %d vdevId %d",
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    "wma_set_force_sleep",
    v36,
    a2);
  v125 = wma_unified_set_sta_ps_param(*a1, a2, 2u, max_ps_poll, v117, v118, v119, v120, v121, v122, v123, v124);
  if ( v125 )
  {
    v46 = v125;
    v116 = "%s: Set Ps Poll Count Failed vdevId %d ps poll cnt %d";
    v115 = max_ps_poll;
    goto LABEL_33;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Ps Poll Count vdevId %d ps poll cnt %d",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "wma_set_force_sleep",
    a2,
    max_ps_poll);
  if ( (a5 & 1) != 0 )
    wmi_unified_set_sta_ps(*a1, a2, 1);
  v126 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(context[2703], a2, 8);
  if ( !v126
    || (v135 = v126,
        listen_interval = wlan_pmo_get_listen_interval(v126, &v148),
        v138 = v137,
        wlan_objmgr_vdev_release_ref(v135, 8u, v139, listen_interval, v140, v141, v142, v143, v144, v145, v146),
        !v148)
    || v138 )
  {
    v147 = *a1;
    v148 = *(unsigned __int16 *)(context[1] + 3404LL);
    if ( (unsigned int)wma_vdev_set_param(v147, a2, 4u, v148, v127, v128, v129, v130, v131, v132, v133, v134) )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to Set Listen Interval vdevId %d",
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        "wma_set_force_sleep",
        a2);
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Set Listen Interval vdevId %d Listen Intv %d",
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    v134,
    "wma_set_force_sleep",
    a2,
    v148);
  v46 = 0;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v46;
}
