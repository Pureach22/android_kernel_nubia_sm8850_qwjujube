__int64 __fastcall dp_print_tx_selfgen_ax_stats_tlv(
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

  DP_PRINT_STATS("HTT_TX_SELFGEN_AX_STATS_TLV:", a2, a3, a4, a5, a6, a7, a8, a9);
  DP_PRINT_STATS("ax_su_ndpa = %u", v10, v11, v12, v13, v14, v15, v16, v17, a1[1]);
  DP_PRINT_STATS("ax_su_ndp = %u", v18, v19, v20, v21, v22, v23, v24, v25, a1[2]);
  DP_PRINT_STATS("ax_mu_mimo_ndpa = %u", v26, v27, v28, v29, v30, v31, v32, v33, a1[3]);
  DP_PRINT_STATS("ax_mu_mimo_ndp = %u", v34, v35, v36, v37, v38, v39, v40, v41, a1[4]);
  DP_PRINT_STATS("ax_mu_mimo_brpoll_1 = %u", v42, v43, v44, v45, v46, v47, v48, v49, a1[5]);
  DP_PRINT_STATS("ax_mu_mimo_brpoll_2 = %u", v50, v51, v52, v53, v54, v55, v56, v57, a1[6]);
  DP_PRINT_STATS("ax_mu_mimo_brpoll_3 = %u", v58, v59, v60, v61, v62, v63, v64, v65, a1[7]);
  DP_PRINT_STATS("ax_mu_mimo_brpoll_4 = %u", v66, v67, v68, v69, v70, v71, v72, v73, a1[8]);
  DP_PRINT_STATS("ax_mu_mimo_brpoll_5 = %u", v74, v75, v76, v77, v78, v79, v80, v81, a1[9]);
  DP_PRINT_STATS("ax_mu_mimo_brpoll_6 = %u", v82, v83, v84, v85, v86, v87, v88, v89, a1[10]);
  DP_PRINT_STATS("ax_mu_mimo_brpoll_7 = %u", v90, v91, v92, v93, v94, v95, v96, v97, a1[11]);
  DP_PRINT_STATS("ax_basic_trigger = %u", v98, v99, v100, v101, v102, v103, v104, v105, a1[12]);
  DP_PRINT_STATS("ax_bsr_trigger = %u", v106, v107, v108, v109, v110, v111, v112, v113, a1[13]);
  DP_PRINT_STATS("ax_mu_bar_trigger = %u", v114, v115, v116, v117, v118, v119, v120, v121, a1[14]);
  return DP_PRINT_STATS("ax_mu_rts_trigger = %u\n", v122, v123, v124, v125, v126, v127, v128, v129, a1[15]);
}
