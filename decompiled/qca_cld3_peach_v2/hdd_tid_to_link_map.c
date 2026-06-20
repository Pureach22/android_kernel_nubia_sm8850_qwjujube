__int64 __fastcall hdd_tid_to_link_map(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w8
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
  __int64 v77; // x5
  __int64 v78; // x6
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
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
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: default mapping: %d direction:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_print_vendor_t2lm_info",
    *((unsigned __int8 *)a2 + 4),
    *a2);
  v20 = *a2;
  if ( *a2 == 2 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_print_vendor_t2lm_info",
      0,
      *((unsigned __int16 *)a2 + 8),
      *((unsigned __int16 *)a2 + 8));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      "wlan_hdd_print_vendor_t2lm_info",
      1,
      *((unsigned __int16 *)a2 + 9),
      *((unsigned __int16 *)a2 + 9));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      "wlan_hdd_print_vendor_t2lm_info",
      2,
      *((unsigned __int16 *)a2 + 10),
      *((unsigned __int16 *)a2 + 10));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v143,
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      "wlan_hdd_print_vendor_t2lm_info",
      3,
      *((unsigned __int16 *)a2 + 11),
      *((unsigned __int16 *)a2 + 11));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      v157,
      v158,
      "wlan_hdd_print_vendor_t2lm_info",
      4,
      *((unsigned __int16 *)a2 + 12),
      *((unsigned __int16 *)a2 + 12));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      "wlan_hdd_print_vendor_t2lm_info",
      5,
      *((unsigned __int16 *)a2 + 13),
      *((unsigned __int16 *)a2 + 13));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v167,
      v168,
      v169,
      v170,
      v171,
      v172,
      v173,
      v174,
      "wlan_hdd_print_vendor_t2lm_info",
      6,
      *((unsigned __int16 *)a2 + 14),
      *((unsigned __int16 *)a2 + 14));
    v77 = *((unsigned __int16 *)a2 + 15);
    v78 = v77;
  }
  else if ( v20 == 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_print_vendor_t2lm_info",
      0,
      0,
      *((unsigned __int16 *)a2 + 8));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      "wlan_hdd_print_vendor_t2lm_info",
      1,
      0,
      *((unsigned __int16 *)a2 + 9));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "wlan_hdd_print_vendor_t2lm_info",
      2,
      0,
      *((unsigned __int16 *)a2 + 10));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      "wlan_hdd_print_vendor_t2lm_info",
      3,
      0,
      *((unsigned __int16 *)a2 + 11));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      "wlan_hdd_print_vendor_t2lm_info",
      4,
      0,
      *((unsigned __int16 *)a2 + 12));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      "wlan_hdd_print_vendor_t2lm_info",
      5,
      0,
      *((unsigned __int16 *)a2 + 13));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "wlan_hdd_print_vendor_t2lm_info",
      6,
      0,
      *((unsigned __int16 *)a2 + 14));
    v78 = *((unsigned __int16 *)a2 + 15);
    v77 = 0;
  }
  else
  {
    if ( v20 )
      goto LABEL_8;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_print_vendor_t2lm_info",
      0,
      *((unsigned __int16 *)a2 + 8),
      0);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_hdd_print_vendor_t2lm_info",
      1,
      *((unsigned __int16 *)a2 + 9),
      0);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_hdd_print_vendor_t2lm_info",
      2,
      *((unsigned __int16 *)a2 + 10),
      0);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_hdd_print_vendor_t2lm_info",
      3,
      *((unsigned __int16 *)a2 + 11),
      0);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "wlan_hdd_print_vendor_t2lm_info",
      4,
      *((unsigned __int16 *)a2 + 12),
      0);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wlan_hdd_print_vendor_t2lm_info",
      5,
      *((unsigned __int16 *)a2 + 13),
      0);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TID[%d]: Downlink: %d Uplink: %d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "wlan_hdd_print_vendor_t2lm_info",
      6,
      *((unsigned __int16 *)a2 + 14),
      0);
    v77 = *((unsigned __int16 *)a2 + 15);
    v78 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: TID[%d]: Downlink: %d Uplink: %d",
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    "wlan_hdd_print_vendor_t2lm_info",
    7,
    v77,
    v78);
LABEL_8:
  if ( !(unsigned __int8)wlan_hdd_send_t2lm_event(a1, a2) )
    return 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: failed to send t2lm info to userspace",
    v175,
    v176,
    v177,
    v178,
    v179,
    v180,
    v181,
    v182,
    "hdd_tid_to_link_map");
  return 16;
}
