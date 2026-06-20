__int64 __fastcall dp_print_tx_tid_stats_tlv(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char *v11; // x20
  int v12; // w22
  int v13; // w22
  int v14; // w22
  int v15; // w22
  int v16; // w22
  __int16 v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
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

  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_tid_stats_tlv", 893);
  if ( !v2 )
    return qdf_trace_msg(
             0x7Fu,
             2u,
             "%s: Output buffer not allocated",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "dp_print_tx_tid_stats_tlv");
  v11 = (char *)v2;
  DP_PRINT_STATS("HTT_TX_TID_STATS_TLV:", v3, v4, v5, v6, v7, v8, v9, v10);
  v12 = snprintf(v11, 0x3E8u, " %u:%u,", 0, *(unsigned __int8 *)(a1 + 4));
  v13 = v12
      + snprintf(
          &v11[(unsigned __int16)v12],
          1000LL - (unsigned __int16)v12,
          " %u:%u,",
          1,
          *(unsigned __int8 *)(a1 + 5));
  v14 = v13
      + snprintf(
          &v11[(unsigned __int16)v13],
          1000LL - (unsigned __int16)v13,
          " %u:%u,",
          2,
          *(unsigned __int8 *)(a1 + 6));
  v15 = v14
      + snprintf(
          &v11[(unsigned __int16)v14],
          1000LL - (unsigned __int16)v14,
          " %u:%u,",
          3,
          *(unsigned __int8 *)(a1 + 7));
  v16 = v15
      + snprintf(
          &v11[(unsigned __int16)v15],
          1000LL - (unsigned __int16)v15,
          " %u:%u,",
          4,
          *(unsigned __int8 *)(a1 + 8));
  LOWORD(v16) = v16
              + snprintf(
                  &v11[(unsigned __int16)v16],
                  1000LL - (unsigned __int16)v16,
                  " %u:%u,",
                  5,
                  *(unsigned __int8 *)(a1 + 9));
  v17 = snprintf(
          &v11[(unsigned __int16)v16],
          1000LL - (unsigned __int16)v16,
          " %u:%u,",
          6,
          *(unsigned __int8 *)(a1 + 10));
  snprintf(
    &v11[(unsigned __int16)(v16 + v17)],
    1000LL - (unsigned __int16)(v16 + v17),
    " %u:%u,",
    7,
    *(unsigned __int8 *)(a1 + 11));
  DP_PRINT_STATS("tid_name = %s ", v18, v19, v20, v21, v22, v23, v24, v25, v11);
  DP_PRINT_STATS("sw_peer_id__tid_num = %u", v26, v27, v28, v29, v30, v31, v32, v33, *(unsigned int *)(a1 + 12));
  DP_PRINT_STATS(
    "num_sched_pending__num_ppdu_in_hwq = %u",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    *(unsigned int *)(a1 + 16));
  DP_PRINT_STATS("tid_flags = %u", v42, v43, v44, v45, v46, v47, v48, v49, *(unsigned int *)(a1 + 20));
  DP_PRINT_STATS("hw_queued = %u", v50, v51, v52, v53, v54, v55, v56, v57, *(unsigned int *)(a1 + 24));
  DP_PRINT_STATS("hw_reaped = %u", v58, v59, v60, v61, v62, v63, v64, v65, *(unsigned int *)(a1 + 28));
  DP_PRINT_STATS("mpdus_hw_filter = %u", v66, v67, v68, v69, v70, v71, v72, v73, *(unsigned int *)(a1 + 32));
  DP_PRINT_STATS("qdepth_bytes = %u", v74, v75, v76, v77, v78, v79, v80, v81, *(unsigned int *)(a1 + 36));
  DP_PRINT_STATS("qdepth_num_msdu = %u", v82, v83, v84, v85, v86, v87, v88, v89, *(unsigned int *)(a1 + 40));
  DP_PRINT_STATS("qdepth_num_mpdu = %u", v90, v91, v92, v93, v94, v95, v96, v97, *(unsigned int *)(a1 + 44));
  DP_PRINT_STATS("last_scheduled_tsmp = %u", v98, v99, v100, v101, v102, v103, v104, v105, *(unsigned int *)(a1 + 48));
  DP_PRINT_STATS("pause_module_id = %u", v106, v107, v108, v109, v110, v111, v112, v113, *(unsigned int *)(a1 + 52));
  DP_PRINT_STATS("block_module_id = %u\n", v114, v115, v116, v117, v118, v119, v120, v121, *(unsigned int *)(a1 + 56));
  DP_PRINT_STATS("tid_tx_airtime = %u\n", v122, v123, v124, v125, v126, v127, v128, v129, *(unsigned int *)(a1 + 60));
  return _qdf_mem_free((__int64)v11);
}
