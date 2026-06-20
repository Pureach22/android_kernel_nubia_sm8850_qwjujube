__int64 __fastcall hdd_wlan_dump_stats(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v12; // x21
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 **v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  unsigned int (*v41)(void); // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
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
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  _QWORD *context; // x0
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7

  v12 = *(__int64 **)(a1 + 24);
  v13 = qdf_trace_msg(
          0x33u,
          8u,
          "%s: stats_id %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_wlan_dump_stats",
          (unsigned int)a2);
  if ( a2 <= 8 )
  {
    switch ( a2 )
    {
      case 2:
        ucfg_wlan_dp_display_tx_rx_histogram(*v12);
        return 0;
      case 4:
        wlan_hdd_display_adapter_netif_queue_stats(a1);
        return 0;
      case 7:
        hdd_display_hif_stats(v13);
        return 0;
    }
    goto LABEL_13;
  }
  if ( a2 != 9 )
  {
    if ( a2 == 13 )
    {
      context = _cds_get_context(71, (__int64)"hdd_wlan_dump_stats", v14, v15, v16, v17, v18, v19, v20, v21);
      ucfg_dp_txrx_ext_dump_stats((__int64)context, 13, v147, v148, v149, v150, v151, v152, v153, v154);
      return 0;
    }
    if ( a2 == 25 )
    {
      sme_display_disconnect_stats(v12[2], *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL));
      return 0;
    }
LABEL_13:
    v31 = (__int64 **)_cds_get_context(71, (__int64)"hdd_wlan_dump_stats", v14, v15, v16, v17, v18, v19, v20, v21);
    if ( v31 && *v31 )
    {
      v40 = **v31;
      if ( v40 )
      {
        v41 = *(unsigned int (**)(void))(v40 + 528);
        if ( v41 )
        {
          if ( *((_DWORD *)v41 - 1) != 358154616 )
            __break(0x8228u);
          if ( v41() == 4 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "iwpriv wlan0 dumpStats [option] - dump statistics",
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49);
            qdf_trace_msg(
              0x33u,
              8u,
              "iwpriv wlan0 clearStats [option] - clear statistics",
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57);
            qdf_trace_msg(0x33u, 8u, "options:", v58, v59, v60, v61, v62, v63, v64, v65);
            qdf_trace_msg(0x33u, 8u, "%u -- %s", v66, v67, v68, v69, v70, v71, v72, v73, 1, "CDP_TXRX_PATH_STATS");
            qdf_trace_msg(0x33u, 8u, "%u -- %s", v74, v75, v76, v77, v78, v79, v80, v81, 2, "CDP_TXRX_HIST_STATS");
            qdf_trace_msg(0x33u, 8u, "%u -- %s", v82, v83, v84, v85, v86, v87, v88, v89, 3, "CDP_TXRX_TSO_STATS");
            qdf_trace_msg(
              0x33u,
              8u,
              "%u -- %s",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              4,
              "CDP_HDD_NETIF_OPER_HISTORY");
            qdf_trace_msg(
              0x33u,
              8u,
              "%u -- %s",
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              5,
              "CDP_DUMP_TX_FLOW_POOL_INFO");
            qdf_trace_msg(
              0x33u,
              8u,
              "%u -- %s",
              v106,
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              6,
              "CDP_TXRX_DESC_STATS");
            qdf_trace_msg(0x33u, 8u, "%u -- %s", v114, v115, v116, v117, v118, v119, v120, v121, 7, "CDP_HIF_STATS");
            qdf_trace_msg(0x33u, 8u, "%u -- %s", v122, v123, v124, v125, v126, v127, v128, v129, 9, "CDP_NAPI_STATS");
            qdf_trace_msg(
              0x33u,
              8u,
              "%u -- %s",
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              12,
              "CDP_DP_NAPI_STATS");
            qdf_trace_msg(
              0x33u,
              8u,
              "%u -- %s",
              v138,
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              13,
              "CDP_DP_RX_THREAD_STATS");
            return 4294967274LL;
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v32, v33, v34, v35, v36, v37, v38, v39, "cdp_display_stats");
    }
    return 0;
  }
  result = hdd_display_napi_stats(v13);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: error displaying napi stats",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_wlan_dump_stats");
    return 4294967282LL;
  }
  return result;
}
