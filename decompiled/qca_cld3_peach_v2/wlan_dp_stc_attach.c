__int64 __fastcall wlan_dp_stc_attach(
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
  __int64 v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x22
  __int64 v39; // x8
  __int64 v40; // x9
  char v41; // w10
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x23
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x25
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x26
  __int64 v72; // x8
  _DWORD *v73; // x9
  unsigned int v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w24
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  int v133; // w8
  __int64 v134; // x8

  if ( (*(_BYTE *)(a1 + 224) & 1) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 240);
    qdf_trace_msg(0x45u, 5u, "%s: STC: attach", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_dp_stc_attach");
    v19 = dp_context_alloc_mem(v10, 0xFu, 0x2520u, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( v19 )
    {
      v28 = v19;
      v29 = dp_context_alloc_mem(v10, 0x10u, 0x3A810u, v20, v21, v22, v23, v24, v25, v26, v27);
      if ( !v29 )
      {
        v83 = 2;
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: STC sampling flow table alloc failed",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wlan_dp_stc_attach");
LABEL_22:
        dp_context_free_mem(v10, 0xFu, v28, v100, v101, v102, v103, v104, v105, v106, v107);
        *(_QWORD *)(a1 + 2936) = 0;
        return v83;
      }
      v38 = v29;
      v39 = 0;
      v40 = v29;
      *(_QWORD *)(v28 + 6400) = v29;
      do
      {
        v41 = v39 | 1;
        *(_BYTE *)(v40 + 40) = v39;
        v39 += 2;
        *(_BYTE *)(v40 + 1912) = v41;
        *(_DWORD *)(v40 + 16) = 0;
        *(_DWORD *)(v40 + 1888) = 0;
        v40 += 3744;
      }
      while ( v39 != 128 );
      v42 = dp_context_alloc_mem(v10, 0x11u, 0x18800u, v30, v31, v32, v33, v34, v35, v36, v37);
      if ( !v42 )
      {
        v83 = 2;
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: STC RX flow table alloc failed",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "wlan_dp_stc_attach");
LABEL_21:
        dp_context_free_mem(v10, 0x10u, v38, v108, v109, v110, v111, v112, v113, v114, v115);
        goto LABEL_22;
      }
      v51 = v42;
      *(_QWORD *)(v28 + 6408) = v42;
      v52 = dp_context_alloc_mem(v10, 0x12u, 0x18800u, v43, v44, v45, v46, v47, v48, v49, v50);
      if ( !v52 )
      {
        v83 = 2;
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: STC TX flow table alloc failed",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "wlan_dp_stc_attach");
LABEL_20:
        dp_context_free_mem(v10, 0x11u, v51, v116, v117, v118, v119, v120, v121, v122, v123);
        goto LABEL_21;
      }
      v61 = v52;
      *(_QWORD *)(v28 + 6416) = v52;
      v62 = dp_context_alloc_mem(v10, 0x13u, 0x8008u, v53, v54, v55, v56, v57, v58, v59, v60);
      if ( !v62 )
      {
        v83 = 2;
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: STC classified flow table alloc failed",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "wlan_dp_stc_attach");
        goto LABEL_19;
      }
      v71 = v62;
      v72 = 0;
      v73 = (_DWORD *)(v62 + 100);
      *(_QWORD *)(v28 + 6424) = v62;
      do
      {
        *((_WORD *)v73 - 42) = v72++;
        *v73 = 0;
        v73 += 32;
      }
      while ( v72 != 256 );
      *(_QWORD *)(a1 + 2936) = v28;
      *(_QWORD *)v28 = a1;
      v74 = _qdf_periodic_work_create(v28 + 16, (__int64)wlan_dp_stc_flow_monitor_work_handler, v28);
      if ( v74 )
      {
        v83 = v74;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: STC flow monitor work creation failed",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "wlan_dp_stc_attach");
        dp_context_free_mem(v10, 0x13u, v71, v84, v85, v86, v87, v88, v89, v90, v91);
LABEL_19:
        dp_context_free_mem(v10, 0x12u, v61, v92, v93, v94, v95, v96, v97, v98, v99);
        goto LABEL_20;
      }
      *(_DWORD *)(v28 + 152) = 0;
      *(_DWORD *)(v28 + 144) = 100;
      *(_BYTE *)(v28 + 255) = wlan_dp_stc_is_traffic_context_supported(*(_QWORD *)a1) & 1;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: STC: TCAM client support: %u",
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        "wlan_dp_stc_attach");
      v133 = *(unsigned __int8 *)(a1 + 225);
      *(_BYTE *)(v28 + 254) = v133;
      if ( v133 == 1 )
        hif_rtpm_register(0xAu, 0);
      *(_DWORD *)(v28 + 224) = 0;
      *(_QWORD *)(v28 + 232) = v28 + 160;
      *(_QWORD *)(v28 + 240) = wlan_dp_stc_flow_sampling_timer;
      hrtimer_init(v28 + 160, 1, 1);
      *(_DWORD *)(v28 + 248) = 0;
      *(_QWORD *)(v28 + 200) = _qdf_hrtimer_cb_3;
      v134 = *(_QWORD *)(a1 + 1480);
      if ( v134 )
        *(_BYTE *)(v134 + 634) = 1;
      v83 = 0;
      *(_DWORD *)(v28 + 148) = 4;
    }
    else
    {
      v83 = 2;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: STC context alloc failed",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "wlan_dp_stc_attach");
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STC: feature not enabled via cfg",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_dp_stc_attach");
    *(_QWORD *)(a1 + 2936) = 0;
    return 11;
  }
  return v83;
}
