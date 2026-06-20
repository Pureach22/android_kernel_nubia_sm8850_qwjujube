__int64 __fastcall ucfg_send_big_data_stats_request(
        __int64 a1,
        unsigned int a2,
        __int64 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v14; // x0
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w22
  __int64 v25; // x8
  __int64 v26; // x0

  v11 = *(_QWORD *)(a1 + 152);
  if ( v11 )
    v14 = *(_QWORD *)(v11 + 80);
  else
    v14 = 0;
  v15 = ucfg_mc_cp_stats_set_pending_req(v14, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v15 )
  {
    v24 = v15;
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: ucfg_mc_cp_stats_set_pending_req pdev failed: %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ucfg_send_big_data_stats_request",
      v15);
  }
  else
  {
    v25 = *(_QWORD *)(a1 + 152);
    if ( v25 )
      v26 = *(_QWORD *)(v25 + 80);
    else
      v26 = 0;
    return (unsigned int)tgt_send_mc_cp_stats_req(v26, a2, v16, v17, v18, v19, v20, v21, v22, v23);
  }
  return v24;
}
