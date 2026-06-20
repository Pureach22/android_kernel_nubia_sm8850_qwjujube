__int64 __fastcall epping_rx(
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
  _QWORD *v10; // x20
  __int64 v11; // x19
  unsigned int v12; // w21
  __int64 v13; // x22
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x9
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v10 = *(_QWORD **)(a1 + 48);
  v11 = *(_QWORD *)(a2 + 16);
  v12 = *(_DWORD *)(a2 + 52);
  v13 = v10[2];
  result = qdf_trace_msg(
             0x33u,
             4u,
             "%s: adapter = 0x%pK eid=%d, skb=0x%pK, data=0x%pK, len=0x%x status:%d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "epping_rx",
             v10,
             *(unsigned int *)(a2 + 48),
             v11,
             *(_QWORD *)(a2 + 32),
             *(_DWORD *)(a2 + 44),
             v12);
  if ( v12 )
  {
    if ( v12 != 9 )
      result = qdf_trace_msg(0x33u, 2u, "%s: RX ERR (%d)", v15, v16, v17, v18, v19, v20, v21, v22, "epping_rx", v12);
    if ( v11 )
      return _qdf_nbuf_free(v11);
  }
  else if ( v11 )
  {
    *(_QWORD *)(v11 + 16) = v13;
    if ( (*(_BYTE *)(v13 + 176) & 1) == 0 )
    {
      ++v10[23];
      return _qdf_nbuf_free(v11);
    }
    *(_WORD *)(v11 + 180) = eth_type_trans(v11, v13);
    v23 = v10[19];
    ++v10[17];
    v10[19] = v23 + *(unsigned int *)(v11 + 112);
    if ( (unsigned int)hdd_napi_enabled(0xFFFFFFFFLL) )
      result = netif_receive_skb(v11);
    else
      result = netif_rx(v11);
    if ( __ROR8__(0x5D4E8FB00BCBE61DLL * v10[17], 4) <= 0x14F8B588E368FuLL )
      return qdf_trace_msg(0x33u, 1u, "%s: total_rx_pkts = %lu", v24, v25, v26, v27, v28, v29, v30, v31, "epping_rx");
  }
  return result;
}
