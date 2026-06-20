__int64 __fastcall dp_rx_pkt_thread_enqueue_cbk(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  __int64 (__fastcall *v13)(__int64, __int64 *); // x8
  char v15; // w8
  __int64 *v16; // x9
  __int64 context; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 (*v26)(void); // x8
  __int64 v27; // x0
  __int64 v28; // x20

  if ( !a1 || !a2 )
  {
    v28 = jiffies;
    if ( dp_rx_pkt_thread_enqueue_cbk___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Null params being passed",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "dp_rx_pkt_thread_enqueue_cbk");
      dp_rx_pkt_thread_enqueue_cbk___last_ticks = v28;
    }
    return 16;
  }
  if ( (is_dp_link_valid(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
    return 16;
  v12 = *(_QWORD *)(a1 + 32);
  if ( ((*(_BYTE *)(v12 + 3614) & 1) != 0
     || (dp_rx_is_ring_latency_sensitive_reo((*((_DWORD *)a2 + 18) >> 18) & 0xF) & 1) != 0)
    && (v13 = *(__int64 (__fastcall **)(__int64, __int64 *))(v12 + 120)) != nullptr )
  {
    if ( *((_DWORD *)v13 - 1) != 424933381 )
      __break(0x8228u);
    return v13(a1, a2);
  }
  else
  {
    v15 = *(_BYTE *)(a1 + 24);
    v16 = a2;
    do
    {
      *((_BYTE *)v16 + 86) = v15;
      v16 = (__int64 *)*v16;
    }
    while ( v16 );
    context = _cds_get_context(71, "dp_rx_pkt_thread_enqueue_cbk");
    if ( context )
    {
      if ( *(_QWORD *)context )
      {
        v26 = *(__int64 (**)(void))(**(_QWORD **)context + 624LL);
        if ( v26 )
        {
          if ( *((_DWORD *)v26 - 1) != -1355198606 )
            __break(0x8228u);
          v27 = v26();
          if ( v27 )
            return dp_rx_tm_enqueue_pkt(v27 + 16, a2);
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "cdp_soc_get_dp_txrx_handle");
      }
      return 5;
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: invalid input params soc %pK nbuf %pK",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "dp_rx_enqueue_pkt",
        0,
        a2);
      return 4;
    }
  }
}
