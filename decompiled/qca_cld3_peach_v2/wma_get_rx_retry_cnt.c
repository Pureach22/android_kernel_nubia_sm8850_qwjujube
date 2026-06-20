__int64 __fastcall wma_get_rx_retry_cnt(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  _QWORD *context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  unsigned int (*v25)(void); // x8
  int v26; // w8

  result = _qdf_mem_malloc(0x11C0u, "wma_get_rx_retry_cnt", 272);
  if ( result )
  {
    v14 = result;
    context = _cds_get_context(71, (__int64)"wma_get_rx_retry_cnt", v6, v7, v8, v9, v10, v11, v12, v13);
    if ( context && *context )
    {
      v24 = *(_QWORD *)(*context + 32LL);
      if ( v24 )
      {
        v25 = *(unsigned int (**)(void))(v24 + 144);
        if ( v25 )
        {
          if ( *((_DWORD *)v25 - 1) != -1642106733 )
            __break(0x8228u);
          if ( !v25() )
          {
            *(_DWORD *)(a1 + 21684) = *(_DWORD *)(v14 + 4080);
            if ( a3 )
              v26 = *(unsigned __int8 *)(a3 + 5);
            else
              v26 = 0;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Rx retry count %d, Peer %02x:%02x:%02x:**:**:%02x",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "wma_get_rx_retry_cnt",
              v26);
            return _qdf_mem_free(v14);
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "cdp_host_get_peer_stats");
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get peer stats",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wma_get_rx_retry_cnt");
    return _qdf_mem_free(v14);
  }
  return result;
}
