__int64 __fastcall dp_print_ring_if_stats_tlv(unsigned int *a1)
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
  char *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
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
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
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
  unsigned __int16 v100; // w0
  unsigned __int16 v101; // w22
  unsigned __int16 v102; // w22
  __int16 v103; // w0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  int v112; // w22
  int v113; // w22
  __int16 v114; // w0
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7

  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_ring_if_stats_tlv", 3024);
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
             "dp_print_ring_if_stats_tlv");
  v11 = (char *)v2;
  DP_PRINT_STATS("HTT_RING_IF_STATS_TLV:", v3, v4, v5, v6, v7, v8, v9, v10);
  DP_PRINT_STATS("base_addr = %u", v12, v13, v14, v15, v16, v17, v18, v19, *a1);
  DP_PRINT_STATS("elem_size = %u", v20, v21, v22, v23, v24, v25, v26, v27, a1[1]);
  DP_PRINT_STATS("num_elems__prefetch_tail_idx = %u", v28, v29, v30, v31, v32, v33, v34, v35, a1[2]);
  DP_PRINT_STATS("head_idx__tail_idx = %u", v36, v37, v38, v39, v40, v41, v42, v43, a1[3]);
  DP_PRINT_STATS("shadow_head_idx__shadow_tail_idx = %u", v44, v45, v46, v47, v48, v49, v50, v51, a1[4]);
  DP_PRINT_STATS("num_tail_incr = %u", v52, v53, v54, v55, v56, v57, v58, v59, a1[5]);
  DP_PRINT_STATS("lwm_thresh__hwm_thresh = %u", v60, v61, v62, v63, v64, v65, v66, v67, a1[6]);
  DP_PRINT_STATS("overrun_hit_count = %u", v68, v69, v70, v71, v72, v73, v74, v75, a1[7]);
  DP_PRINT_STATS("underrun_hit_count = %u", v76, v77, v78, v79, v80, v81, v82, v83, a1[8]);
  DP_PRINT_STATS("prod_blockwait_count = %u", v84, v85, v86, v87, v88, v89, v90, v91, a1[9]);
  DP_PRINT_STATS("cons_blockwait_count = %u", v92, v93, v94, v95, v96, v97, v98, v99, a1[10]);
  v100 = snprintf(v11, 0x3E8u, " %u:%u,", 0, a1[11]);
  v101 = v100 + snprintf(&v11[v100], 1000LL - v100, " %u:%u,", 1, a1[12]);
  v102 = v101 + snprintf(&v11[v101], 1000LL - v101, " %u:%u,", 2, a1[13]);
  v103 = snprintf(&v11[v102], 1000LL - v102, " %u:%u,", 3, a1[14]);
  snprintf(&v11[(unsigned __int16)(v102 + v103)], 1000LL - (unsigned __int16)(v102 + v103), " %u:%u,", 4, a1[15]);
  DP_PRINT_STATS("low_wm_hit_count = %s ", v104, v105, v106, v107, v108, v109, v110, v111, v11);
  qdf_mem_set(v11, 0x3E8u, 0);
  v112 = snprintf(v11, 0x3E8u, " %u:%u,", 0, a1[16]);
  v113 = v112 + snprintf(&v11[(unsigned __int16)v112], 1000LL - (unsigned __int16)v112, " %u:%u,", 1, a1[17]);
  LOWORD(v113) = v113 + snprintf(&v11[(unsigned __int16)v113], 1000LL - (unsigned __int16)v113, " %u:%u,", 2, a1[18]);
  v114 = snprintf(&v11[(unsigned __int16)v113], 1000LL - (unsigned __int16)v113, " %u:%u,", 3, a1[19]);
  snprintf(&v11[(unsigned __int16)(v113 + v114)], 1000LL - (unsigned __int16)(v113 + v114), " %u:%u,", 4, a1[20]);
  DP_PRINT_STATS("high_wm_hit_count = %s\n", v115, v116, v117, v118, v119, v120, v121, v122, v11);
  return _qdf_mem_free((__int64)v11);
}
