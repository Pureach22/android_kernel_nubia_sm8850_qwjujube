unsigned __int8 *__fastcall dp_dump_srng_high_wm_stats(__int64 a1, __int64 a2)
{
  unsigned __int8 *result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x25
  unsigned __int8 **v22; // x26
  unsigned __int8 *v23; // t1
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w8
  unsigned __int64 v33; // x25
  unsigned __int8 **v34; // x26
  __int64 v35; // x27
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int8 *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned __int8 *v53; // x8
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
  __int64 v70; // x8
  __int64 v71; // x8
  _DWORD *v72; // x8
  unsigned __int8 *v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x8
  __int64 v91; // x8
  __int64 (__fastcall *v92)(__int64, __int64, __int64); // x8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  const char *v101; // x2
  const char *v102; // x2
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x8
  __int64 v112; // x8
  _DWORD *v113; // x8
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  const char *v122; // x2
  _BYTE s[512]; // [xsp+28h] [xbp-208h] BYREF
  __int64 v124; // [xsp+228h] [xbp-8h]

  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (unsigned __int8 *)memset(s, 0, sizeof(s));
  if ( !a2 )
    goto LABEL_51;
  result = (unsigned __int8 *)qdf_trace_msg(
                                0x45u,
                                5u,
                                "%s: %8s %7s %12s %10s %10s %10s %10s %10s %10s",
                                v5,
                                v6,
                                v7,
                                v8,
                                v9,
                                v10,
                                v11,
                                v12,
                                "dp_dump_srng_high_wm_stats",
                                "ring_id",
                                "high_wm",
                                "time",
                                "<50",
                                "50-60",
                                "60-70",
                                "70-80",
                                "80-90",
                                "90-100");
  if ( (a2 & 1) != 0 && *(_BYTE *)(a1 + 12848) )
  {
    v21 = 0;
    v22 = (unsigned __int8 **)(a1 + 5712);
    do
    {
      if ( v21 == 8 )
LABEL_52:
        __break(0x5512u);
      v23 = *v22;
      v22 += 10;
      v24 = scnprintf(
              s,
              512,
              "%8u %7u %12llu %10u %10u %10u %10u %10u %10u",
              *v23,
              *((_DWORD *)v23 + 60),
              *((_QWORD *)v23 + 31),
              *((_DWORD *)v23 + 70),
              *((_DWORD *)v23 + 71),
              *((_DWORD *)v23 + 72),
              *((_DWORD *)v23 + 73),
              *((_DWORD *)v23 + 74),
              *((_DWORD *)v23 + 75));
      result = (unsigned __int8 *)qdf_trace_msg(
                                    0x45u,
                                    5u,
                                    "%s: %s",
                                    v24,
                                    v25,
                                    v26,
                                    v27,
                                    v28,
                                    v29,
                                    v30,
                                    v31,
                                    "dp_dump_srng_high_wm_stats",
                                    s);
      ++v21;
    }
    while ( v21 < *(unsigned __int8 *)(a1 + 12848) );
  }
  if ( (a2 & 0x2000) != 0 )
  {
    v32 = *(unsigned __int8 *)(a1 + 7153);
    if ( *(_BYTE *)(a1 + 7153) )
    {
      v33 = 0;
      v34 = (unsigned __int8 **)(a1 + 7320);
      v35 = 1;
      do
      {
        if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 776LL) + v35) != 15 )
        {
          if ( v33 > 4 )
            goto LABEL_52;
          v36 = scnprintf(
                  s,
                  512,
                  "%8u %7u %12llu %10u %10u %10u %10u %10u %10u",
                  **v34,
                  *((_DWORD *)*v34 + 60),
                  *((_QWORD *)*v34 + 31),
                  *((_DWORD *)*v34 + 70),
                  *((_DWORD *)*v34 + 71),
                  *((_DWORD *)*v34 + 72),
                  *((_DWORD *)*v34 + 73),
                  *((_DWORD *)*v34 + 74),
                  *((_DWORD *)*v34 + 75));
          result = (unsigned __int8 *)qdf_trace_msg(
                                        0x45u,
                                        5u,
                                        "%s: %s",
                                        v36,
                                        v37,
                                        v38,
                                        v39,
                                        v40,
                                        v41,
                                        v42,
                                        v43,
                                        "dp_dump_srng_high_wm_stats",
                                        s);
          v32 = *(unsigned __int8 *)(a1 + 7153);
        }
        ++v33;
        v34 += 10;
        v35 += 4;
      }
      while ( v33 < v32 );
    }
  }
  if ( (a2 & 0x20000) != 0 )
  {
    result = (unsigned __int8 *)qdf_trace_msg(
                                  0x45u,
                                  5u,
                                  "%s: RX MON status ring",
                                  v13,
                                  v14,
                                  v15,
                                  v16,
                                  v17,
                                  v18,
                                  v19,
                                  v20,
                                  "dp_dump_lpc_coc_srng_high_wm_stats");
    v44 = *(unsigned __int8 **)(a1 + 800);
    if ( v44 )
    {
      v45 = scnprintf(
              s,
              512,
              "%8u %7u %12llu %10u %10u %10u %10u %10u %10u",
              *v44,
              *((_DWORD *)v44 + 60),
              *((_QWORD *)v44 + 31),
              *((_DWORD *)v44 + 70),
              *((_DWORD *)v44 + 71),
              *((_DWORD *)v44 + 72),
              *((_DWORD *)v44 + 73),
              *((_DWORD *)v44 + 74),
              *((_DWORD *)v44 + 75));
      result = (unsigned __int8 *)qdf_trace_msg(
                                    0x45u,
                                    5u,
                                    "%s: %s",
                                    v45,
                                    v46,
                                    v47,
                                    v48,
                                    v49,
                                    v50,
                                    v51,
                                    v52,
                                    "dp_dump_lpc_coc_srng_high_wm_stats",
                                    s);
    }
    v53 = *(unsigned __int8 **)(a1 + 880);
    if ( v53 )
    {
      v54 = scnprintf(
              s,
              512,
              "%8u %7u %12llu %10u %10u %10u %10u %10u %10u",
              *v53,
              *((_DWORD *)v53 + 60),
              *((_QWORD *)v53 + 31),
              *((_DWORD *)v53 + 70),
              *((_DWORD *)v53 + 71),
              *((_DWORD *)v53 + 72),
              *((_DWORD *)v53 + 73),
              *((_DWORD *)v53 + 74),
              *((_DWORD *)v53 + 75));
      result = (unsigned __int8 *)qdf_trace_msg(
                                    0x45u,
                                    5u,
                                    "%s: %s",
                                    v54,
                                    v55,
                                    v56,
                                    v57,
                                    v58,
                                    v59,
                                    v60,
                                    v61,
                                    "dp_dump_lpc_coc_srng_high_wm_stats",
                                    s);
    }
  }
  if ( (a2 & 0x2000000) != 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: TX MON Dest ring",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_dump_lpc_coc_srng_high_wm_stats");
    v70 = *(_QWORD *)(a1 + 20056);
    if ( v70 )
    {
      v71 = *(_QWORD *)(v70 + 416);
      if ( v71 )
      {
        v72 = *(_DWORD **)(v71 + 264);
        if ( v72 )
        {
          if ( *(v72 - 1) != -231840865 )
            __break(0x8228u);
          v73 = (unsigned __int8 *)((__int64 (__fastcall *)(__int64, _QWORD, __int64))v72)(a1, 0, 25);
          if ( v73 )
          {
            v82 = scnprintf(
                    s,
                    512,
                    "%8u %7u %12llu %10u %10u %10u %10u %10u %10u",
                    *v73,
                    *((_DWORD *)v73 + 60),
                    *((_QWORD *)v73 + 31),
                    *((_DWORD *)v73 + 70),
                    *((_DWORD *)v73 + 71),
                    *((_DWORD *)v73 + 72),
                    *((_DWORD *)v73 + 73),
                    *((_DWORD *)v73 + 74),
                    *((_DWORD *)v73 + 75));
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: %s",
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              "dp_dump_lpc_coc_srng_high_wm_stats",
              s);
          }
          v90 = *(_QWORD *)(a1 + 20056);
          if ( v90 )
            goto LABEL_28;
          goto LABEL_38;
        }
      }
      v101 = "%s: callback not registered";
    }
    else
    {
      v101 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(0x92u, 8u, v101, v62, v63, v64, v65, v66, v67, v68, v69, "dp_tx_mon_get_hal_ring");
    v90 = *(_QWORD *)(a1 + 20056);
    if ( v90 )
    {
LABEL_28:
      v91 = *(_QWORD *)(v90 + 416);
      if ( v91 )
      {
        v92 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v91 + 264);
        if ( v92 )
        {
          if ( *((_DWORD *)v92 - 1) != -231840865 )
            __break(0x8228u);
          result = (unsigned __int8 *)v92(a1, 1, 25);
          if ( result )
          {
            v93 = scnprintf(
                    s,
                    512,
                    "%8u %7u %12llu %10u %10u %10u %10u %10u %10u",
                    *result,
                    *((_DWORD *)result + 60),
                    *((_QWORD *)result + 31),
                    *((_DWORD *)result + 70),
                    *((_DWORD *)result + 71),
                    *((_DWORD *)result + 72),
                    *((_DWORD *)result + 73),
                    *((_DWORD *)result + 74),
                    *((_DWORD *)result + 75));
            result = (unsigned __int8 *)qdf_trace_msg(
                                          0x45u,
                                          5u,
                                          "%s: %s",
                                          v93,
                                          v94,
                                          v95,
                                          v96,
                                          v97,
                                          v98,
                                          v99,
                                          v100,
                                          "dp_dump_lpc_coc_srng_high_wm_stats",
                                          s);
          }
          goto LABEL_40;
        }
      }
      v102 = "%s: callback not registered";
LABEL_39:
      result = (unsigned __int8 *)qdf_trace_msg(
                                    0x92u,
                                    8u,
                                    v102,
                                    v74,
                                    v75,
                                    v76,
                                    v77,
                                    v78,
                                    v79,
                                    v80,
                                    v81,
                                    "dp_tx_mon_get_hal_ring");
      goto LABEL_40;
    }
LABEL_38:
    v102 = "%s: monitor soc is NULL";
    goto LABEL_39;
  }
LABEL_40:
  if ( (a2 & 0x1000000) == 0 )
    goto LABEL_51;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: TX MON source buffer ring",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "dp_dump_lpc_coc_srng_high_wm_stats");
  v111 = *(_QWORD *)(a1 + 20056);
  if ( !v111 )
  {
    v122 = "%s: monitor soc is NULL";
    goto LABEL_50;
  }
  v112 = *(_QWORD *)(v111 + 416);
  if ( !v112 || (v113 = *(_DWORD **)(v112 + 264)) == nullptr )
  {
    v122 = "%s: callback not registered";
LABEL_50:
    result = (unsigned __int8 *)qdf_trace_msg(
                                  0x92u,
                                  8u,
                                  v122,
                                  v103,
                                  v104,
                                  v105,
                                  v106,
                                  v107,
                                  v108,
                                  v109,
                                  v110,
                                  "dp_tx_mon_get_hal_ring");
    goto LABEL_51;
  }
  if ( *(v113 - 1) != -231840865 )
    __break(0x8228u);
  result = (unsigned __int8 *)((__int64 (__fastcall *)(__int64, _QWORD, __int64))v113)(a1, 0, 24);
  if ( result )
  {
    v114 = scnprintf(
             s,
             512,
             "%8u %7u %12llu %10u %10u %10u %10u %10u %10u",
             *result,
             *((_DWORD *)result + 60),
             *((_QWORD *)result + 31),
             *((_DWORD *)result + 70),
             *((_DWORD *)result + 71),
             *((_DWORD *)result + 72),
             *((_DWORD *)result + 73),
             *((_DWORD *)result + 74),
             *((_DWORD *)result + 75));
    result = (unsigned __int8 *)qdf_trace_msg(
                                  0x45u,
                                  5u,
                                  "%s: %s",
                                  v114,
                                  v115,
                                  v116,
                                  v117,
                                  v118,
                                  v119,
                                  v120,
                                  v121,
                                  "dp_dump_lpc_coc_srng_high_wm_stats",
                                  s);
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
