__int64 __fastcall ucfg_mc_cp_stats_send_stats_request(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
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
  __int64 v12; // x20
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // [xsp+7h] [xbp-9h] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 152);
  if ( v11 && (v12 = *(_QWORD *)(v11 + 80)) != 0 )
  {
    v15 = ucfg_mc_cp_stats_set_pending_req(*(_QWORD *)(v11 + 80));
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
        "ucfg_mc_cp_stats_send_stats_request",
        v15);
    }
    else
    {
      v24 = tgt_send_mc_cp_stats_req(v12, a2, v16, v17, v18, v19, v20, v21, v22, v23);
      if ( v24 )
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: send cp stats req type %d failed %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "ucfg_mc_cp_stats_send_stats_request",
          a2,
          v24);
        ucfg_mc_cp_stats_reset_pending_req(v12, a2, a3, &v34);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_mc_cp_stats_send_stats_request");
    v24 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v24;
}
