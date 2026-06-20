__int64 __fastcall wlan_ipa_uc_info(
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
  __int64 v9; // x9
  const char *v11; // x8
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  int v16; // w10
  int v17; // w13
  int v18; // w14
  int v19; // w15
  int v20; // w16
  bool v21; // zf
  __int64 v22; // x12
  __int64 v23; // x0
  int v24; // w17
  int v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w8
  __int64 v35; // x20
  unsigned int v36; // w8
  unsigned int v37; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 result; // x0
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  _QWORD *v151; // x8
  unsigned int v152; // w20
  __int64 v153; // x9
  const char *v154; // x5
  int v155; // [xsp+0h] [xbp-70h]
  __int64 v156; // [xsp+0h] [xbp-70h]
  __int64 v157; // [xsp+8h] [xbp-68h]
  int v158; // [xsp+10h] [xbp-60h]
  int v159; // [xsp+18h] [xbp-58h]
  int v160; // [xsp+20h] [xbp-50h]
  int v161; // [xsp+28h] [xbp-48h]
  int v162; // [xsp+30h] [xbp-40h]
  int v163; // [xsp+38h] [xbp-38h]
  int v164; // [xsp+40h] [xbp-30h]
  int v165; // [xsp+48h] [xbp-28h]
  _QWORD *v166; // [xsp+58h] [xbp-18h] BYREF
  _QWORD *v167[2]; // [xsp+60h] [xbp-10h] BYREF

  v9 = a1 + 4096;
  v167[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = "SCC";
  v12 = *(unsigned __int8 *)(a1 + 1448);
  v13 = *(unsigned int *)(a1 + 1472);
  v14 = *(unsigned __int8 *)(a1 + 3704);
  v15 = *(unsigned __int16 *)(a1 + 3706);
  v16 = *(unsigned __int8 *)(a1 + 3710);
  v17 = *(unsigned __int8 *)(a1 + 3720);
  v18 = *(unsigned __int8 *)(a1 + 3721);
  v19 = *(unsigned __int8 *)(a1 + 3722);
  v20 = *(unsigned __int8 *)(a1 + 3440);
  v21 = *(_BYTE *)(a1 + 7298) == 0;
  v22 = *(_QWORD *)(a1 + 3552);
  v23 = *(_QWORD *)(a1 + 3560);
  v24 = *(unsigned __int8 *)(v9 + 2888);
  v25 = *(unsigned __int8 *)(v9 + 2889);
  if ( !v21 )
    v11 = "MCC";
  v165 = v23;
  v166 = nullptr;
  v167[0] = nullptr;
  v164 = v22;
  v163 = v25;
  v162 = v24;
  v161 = v20;
  v160 = v19;
  v159 = v18;
  v158 = v17;
  v155 = v16;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \n"
    "==== IPA SESSION INFO ====\n"
    "NUM IFACE: %d\n"
    "RM STATE: %d\n"
    "ACTIVATED FW PIPE: %d\n"
    "SAP NUM STAs: %d\n"
    "STA CONNECTED: %d\n"
    "CONCURRENT MODE: %s\n"
    "RSC LOADING: %d\n"
    "RSC UNLOADING: %d\n"
    "PENDING CONS REQ: %d\n"
    "IPA PIPES DOWN: %d\n"
    "IPA UC LOADED: %d\n"
    "IPA WDI ENABLED: %d\n"
    "NUM SEND MSG: %d\n"
    "NUM FREE MSG: %d\n",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_print_session_info",
    v12,
    v13,
    v14,
    v15,
    v155,
    v11,
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    v164,
    v165);
  v34 = *(unsigned __int8 *)(a1 + 1116);
  v35 = a1 + 7293;
  if ( v34 != 5 )
  {
    if ( v34 > 4 )
      goto LABEL_18;
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: \nIFACE[%d]: mode:%d, offload:%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_ipa_print_session_info",
      0,
      *(unsigned int *)(a1 + 1096),
      *(unsigned __int8 *)(v35 + *(unsigned __int8 *)(a1 + 1116)));
  }
  v36 = *(unsigned __int8 *)(a1 + 1244);
  if ( v36 != 5 )
  {
    if ( v36 > 4 )
      goto LABEL_18;
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: \nIFACE[%d]: mode:%d, offload:%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_ipa_print_session_info",
      1,
      *(unsigned int *)(a1 + 1224),
      *(unsigned __int8 *)(v35 + *(unsigned __int8 *)(a1 + 1244)));
  }
  v37 = *(unsigned __int8 *)(a1 + 1372);
  if ( v37 == 5 )
    goto LABEL_12;
  if ( v37 > 4 )
LABEL_18:
    __break(0x5512u);
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nIFACE[%d]: mode:%d, offload:%d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_ipa_print_session_info",
    2,
    *(unsigned int *)(a1 + 1352),
    *(unsigned __int8 *)(v35 + *(unsigned __int8 *)(a1 + 1372)));
LABEL_12:
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wlan_ipa_print_session_info",
    0,
    *(unsigned int *)(a1 + 3496));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "wlan_ipa_print_session_info",
    1,
    *(unsigned int *)(a1 + 3500));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "wlan_ipa_print_session_info",
    2,
    *(unsigned int *)(a1 + 3504));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "wlan_ipa_print_session_info",
    3,
    *(unsigned int *)(a1 + 3508));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    "wlan_ipa_print_session_info",
    4,
    *(unsigned int *)(a1 + 3512));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    "wlan_ipa_print_session_info",
    5,
    *(unsigned int *)(a1 + 3516));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    "wlan_ipa_print_session_info",
    6,
    *(unsigned int *)(a1 + 3520));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    "wlan_ipa_print_session_info",
    7,
    *(unsigned int *)(a1 + 3524));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    v101,
    "wlan_ipa_print_session_info",
    8,
    *(unsigned int *)(a1 + 3528));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    "wlan_ipa_print_session_info",
    9,
    *(unsigned int *)(a1 + 3532));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    v116,
    v117,
    "wlan_ipa_print_session_info",
    10,
    *(unsigned int *)(a1 + 3536));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v118,
    v119,
    v120,
    v121,
    v122,
    v123,
    v124,
    v125,
    "wlan_ipa_print_session_info",
    11,
    *(unsigned int *)(a1 + 3540));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    "wlan_ipa_print_session_info",
    12,
    *(unsigned int *)(a1 + 3544));
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \nEVENT[%d]=%d",
    v134,
    v135,
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    "wlan_ipa_print_session_info",
    13,
    *(unsigned int *)(a1 + 3548));
  result = qdf_list_peek_front((_QWORD *)(a1 + 4016), v167);
  v151 = v167[0];
  if ( v167[0] )
  {
    v152 = 0;
    do
    {
      v153 = *((unsigned int *)v151 + 4);
      v154 = "UNKNOWN";
      if ( (unsigned int)v153 <= 0xC )
        v154 = off_B2D790[v153];
      LODWORD(v157) = *((unsigned __int8 *)v151 + 39);
      LODWORD(v156) = *((unsigned __int8 *)v151 + 36);
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: PENDING EVENT[%d]: EVT:%s, MAC:%02x:%02x:%02x:**:**:%02x",
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        "wlan_ipa_print_session_info",
        v152,
        v154,
        *((unsigned __int8 *)v151 + 34),
        *((unsigned __int8 *)v151 + 35),
        v156,
        v157);
      result = qdf_list_peek_next((_QWORD *)(a1 + 4016), v167[0], &v166);
      v151 = v166;
      ++v152;
      v166 = nullptr;
      v167[0] = v151;
    }
    while ( v151 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
