__int64 __fastcall dp_print_peer_details_tlv(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
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

  DP_PRINT_STATS("HTT_PEER_DETAILS_TLV:", a2, a3, a4, a5, a6, a7, a8, a9);
  DP_PRINT_STATS("peer_type = %u", v10, v11, v12, v13, v14, v15, v16, v17, a1[1]);
  DP_PRINT_STATS("sw_peer_id = %u", v18, v19, v20, v21, v22, v23, v24, v25, a1[2]);
  DP_PRINT_STATS("vdev_pdev_ast_idx = %u", v26, v27, v28, v29, v30, v31, v32, v33, a1[3]);
  DP_PRINT_STATS("mac_addr(upper 4 bytes) = %u", v34, v35, v36, v37, v38, v39, v40, v41, a1[4]);
  DP_PRINT_STATS("mac_addr(lower 2 bytes) = %u", v42, v43, v44, v45, v46, v47, v48, v49, a1[5]);
  DP_PRINT_STATS("peer_flags = %u", v50, v51, v52, v53, v54, v55, v56, v57, a1[6]);
  return DP_PRINT_STATS("qpeer_flags = %u\n", v58, v59, v60, v61, v62, v63, v64, v65, a1[7]);
}
