__int64 __fastcall hdd_config_msdu_aggregation(
        unsigned __int8 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x9
  __int64 v11; // x10
  unsigned int v12; // w19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19
  const char *v33; // x4

  if ( !*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL) )
  {
    qdf_trace_msg(0x33u, 2u, "%s: NULL Mac handle", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_msdu_aggregation");
    return 4294967274LL;
  }
  v10 = *(_QWORD *)(a2 + 520);
  v11 = *(_QWORD *)(a2 + 528);
  if ( *(_OWORD *)(a2 + 520) == 0 )
    return 0;
  if ( !v10 || !v11 )
  {
    if ( v10 )
      v33 = (const char *)&unk_956283;
    else
      v33 = "TX";
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Missing attribute for %s",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_msdu_aggregation",
      v33);
    return 4294967274LL;
  }
  v12 = *(unsigned __int8 *)(v10 + 4);
  if ( !*(_BYTE *)(v11 + 4) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TX %d RX %d MSDU aggr size not in range",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_msdu_aggregation",
      *(unsigned __int8 *)(v10 + 4),
      0);
    return 4294967274LL;
  }
  sme_set_amsdu(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL), v12 > 1);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: tx size: %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "hdd_config_msdu_aggregation",
    v12);
  v22 = wma_cli_set_command(a1[8], 2, v12, 3);
  if ( v22 )
  {
    v31 = v22;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set AMSDU param to FW, status %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_config_msdu_aggregation",
      v22);
    v22 = v31;
  }
  return qdf_status_to_os_return(v22);
}
