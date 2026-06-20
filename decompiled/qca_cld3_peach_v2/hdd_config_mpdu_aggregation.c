__int64 __fastcall hdd_config_mpdu_aggregation(
        __int64 a1,
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
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned int v12; // w0
  const char *v14; // x4

  v10 = *(_QWORD *)(a2 + 64);
  v11 = *(_QWORD *)(a2 + 72);
  if ( *(_OWORD *)(a2 + 64) == 0 )
    return 0;
  if ( v10 && v11 )
  {
    if ( *(_BYTE *)(v11 + 4) )
    {
      v12 = wma_set_tx_rx_aggr_size(*(unsigned __int8 *)(a1 + 8), *(unsigned __int8 *)(v10 + 4));
      return qdf_status_to_os_return(v12);
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TX %d RX %d MPDU aggr size not in range",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_mpdu_aggregation",
      *(unsigned __int8 *)(v10 + 4),
      0);
  }
  else
  {
    if ( v10 )
      v14 = (const char *)&unk_A39F4F;
    else
      v14 = "TX";
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
      "hdd_config_mpdu_aggregation",
      v14);
  }
  return 4294967274LL;
}
