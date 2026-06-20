__int64 __fastcall dp_fim_display_stats(
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
  unsigned __int8 *v9; // x20
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

  v9 = *(unsigned __int8 **)(a1 + 3720);
  qdf_trace_msg(0x45u, 5u, "%s: FIM Stats:", a2, a3, a4, a5, a6, a7, a8, a9, "dp_fim_display_stats");
  qdf_trace_msg(0x45u, 5u, "%s: fim_enable:%d", v10, v11, v12, v13, v14, v15, v16, v17, "dp_fim_display_stats", *v9);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: policy_added:%d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "dp_fim_display_stats",
    *((unsigned int *)v9 + 526));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: policy_removed:%d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "dp_fim_display_stats",
    *((unsigned int *)v9 + 527));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: policy_update:%d",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "dp_fim_display_stats",
    *((unsigned int *)v9 + 528));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: flow_node:%d",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "dp_fim_display_stats",
    *((unsigned int *)v9 + 529));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: pkt_not_support:%d",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "dp_fim_display_stats",
    *((unsigned int *)v9 + 530));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: sk_valid_cnt:%d",
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    "dp_fim_display_stats",
    *((unsigned int *)v9 + 531));
  return qdf_trace_msg(
           0x45u,
           5u,
           "%s: sk_invalid_cnt:%d",
           v66,
           v67,
           v68,
           v69,
           v70,
           v71,
           v72,
           v73,
           "dp_fim_display_stats",
           *((unsigned int *)v9 + 532));
}
