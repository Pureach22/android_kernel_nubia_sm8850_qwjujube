__int64 __fastcall dp_print_tx_pdev_mu_mimo_mpdu_stats_tlv(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8
  unsigned int *v10; // x19
  unsigned int v11; // w1
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
  unsigned int v60; // w1
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
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  unsigned int v109; // w1
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
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7

  v9 = *(_DWORD *)(result + 36);
  v10 = (unsigned int *)result;
  if ( v9 == 1 )
  {
    v11 = *(_DWORD *)(result + 32);
    if ( v11 )
    {
      if ( v11 > 3 )
      {
LABEL_5:
        v9 = v10[9];
        goto LABEL_6;
      }
    }
    else
    {
      result = DP_PRINT_STATS("\nHTT_TX_PDEV_MU_MIMO_AC_MPDU_STATS:\n", a2, a3, a4, a5, a6, a7, a8, a9);
      if ( v10[8] > 3 )
        goto LABEL_5;
    }
    DP_PRINT_STATS("ac_mu_mimo_mpdus_queued_usr_%u = %u", a2, a3, a4, a5, a6, a7, a8, a9);
    DP_PRINT_STATS("ac_mu_mimo_mpdus_tried_usr_%u = %u", v12, v13, v14, v15, v16, v17, v18, v19, v10[8], v10[2]);
    DP_PRINT_STATS("ac_mu_mimo_mpdus_failed_usr_%u = %u", v20, v21, v22, v23, v24, v25, v26, v27, v10[8], v10[3]);
    DP_PRINT_STATS("ac_mu_mimo_mpdus_requeued_usr_%u = %u", v28, v29, v30, v31, v32, v33, v34, v35, v10[8], v10[4]);
    DP_PRINT_STATS("ac_mu_mimo_err_no_ba_usr_%u = %u", v36, v37, v38, v39, v40, v41, v42, v43, v10[8], v10[5]);
    DP_PRINT_STATS("ac_mu_mimo_mpdu_underrun_usr_%u = %u", v44, v45, v46, v47, v48, v49, v50, v51, v10[8], v10[6]);
    result = DP_PRINT_STATS(
               "ac_mu_mimo_ampdu_underrun_usr_%u = %u\n",
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               v59,
               v10[8],
               v10[7]);
    goto LABEL_5;
  }
LABEL_6:
  if ( v9 != 2 )
    goto LABEL_10;
  v60 = v10[8];
  if ( v60 )
  {
    if ( v60 > 7 )
      goto LABEL_10;
    goto LABEL_9;
  }
  result = DP_PRINT_STATS("\nHTT_TX_PDEV_MU_MIMO_AX_MPDU_STATS:\n", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v10[8] <= 7 )
  {
LABEL_9:
    DP_PRINT_STATS("ax_mu_mimo_mpdus_queued_usr_%u = %u", a2, a3, a4, a5, a6, a7, a8, a9);
    DP_PRINT_STATS("ax_mu_mimo_mpdus_tried_usr_%u = %u", v61, v62, v63, v64, v65, v66, v67, v68, v10[8], v10[2]);
    DP_PRINT_STATS("ax_mu_mimo_mpdus_failed_usr_%u = %u", v69, v70, v71, v72, v73, v74, v75, v76, v10[8], v10[3]);
    DP_PRINT_STATS("ax_mu_mimo_mpdus_requeued_usr_%u = %u", v77, v78, v79, v80, v81, v82, v83, v84, v10[8], v10[4]);
    DP_PRINT_STATS("ax_mu_mimo_err_no_ba_usr_%u = %u", v85, v86, v87, v88, v89, v90, v91, v92, v10[8], v10[5]);
    DP_PRINT_STATS("ax_mu_mimo_mpdu_underrun_usr_%u = %u", v93, v94, v95, v96, v97, v98, v99, v100, v10[8], v10[6]);
    result = DP_PRINT_STATS(
               "ax_mu_mimo_ampdu_underrun_usr_%u = %u\n",
               v101,
               v102,
               v103,
               v104,
               v105,
               v106,
               v107,
               v108,
               v10[8],
               v10[7]);
  }
LABEL_10:
  if ( v10[9] != 3 )
    return result;
  v109 = v10[8];
  if ( v109 )
  {
    if ( v109 > 0x49 )
      return result;
  }
  else
  {
    result = DP_PRINT_STATS("\nHTT_TX_PDEV_AX_MU_OFDMA_MPDU_STATS:\n", a2, a3, a4, a5, a6, a7, a8, a9);
    if ( v10[8] > 0x49 )
      return result;
  }
  DP_PRINT_STATS("ax_mu_ofdma_mpdus_queued_usr_%u = %u", a2, a3, a4, a5, a6, a7, a8, a9);
  DP_PRINT_STATS("ax_mu_ofdma_mpdus_tried_usr_%u = %u", v110, v111, v112, v113, v114, v115, v116, v117, v10[8], v10[2]);
  DP_PRINT_STATS("ax_mu_ofdma_mpdus_failed_usr_%u = %u", v118, v119, v120, v121, v122, v123, v124, v125, v10[8], v10[3]);
  DP_PRINT_STATS(
    "ax_mu_ofdma_mpdus_requeued_usr_%u = %u",
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    v10[8],
    v10[4]);
  DP_PRINT_STATS("ax_mu_ofdma_err_no_ba_usr_%u = %u", v134, v135, v136, v137, v138, v139, v140, v141, v10[8], v10[5]);
  DP_PRINT_STATS(
    "ax_mu_ofdma_mpdu_underrun_usr_%u = %u",
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    v10[8],
    v10[6]);
  return DP_PRINT_STATS(
           "ax_mu_ofdma_ampdu_underrun_usr_%u = %u\n",
           v150,
           v151,
           v152,
           v153,
           v154,
           v155,
           v156,
           v157,
           v10[8],
           v10[7]);
}
