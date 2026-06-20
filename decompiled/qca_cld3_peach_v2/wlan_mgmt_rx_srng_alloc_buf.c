__int64 __fastcall wlan_mgmt_rx_srng_alloc_buf(__int64 a1, unsigned int a2, __int64 *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w23
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x9

  v6 = _qdf_nbuf_alloc(*(_QWORD *)(a1 + 16), 3520, 0, 4, 0, "wlan_mgmt_rx_srng_alloc_buf", 42);
  if ( v6 )
  {
    v15 = v6;
    if ( (unsigned int)_qdf_nbuf_map_single(*(_QWORD *)(a1 + 16), v6, 2u) )
    {
      _qdf_nbuf_free(v15);
      qdf_trace_msg(
        0xA5u,
        2u,
        "%s: Nbuf map failure for id %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_mgmt_rx_srng_alloc_buf",
        a2);
      return 16;
    }
    else
    {
      v25 = 80;
      if ( (*(_BYTE *)(v15 + 68) & 4) == 0 )
        v25 = 40;
      *a3 = *(_QWORD *)(v15 + v25);
      qdf_mem_dma_sync_single_for_device(*(_QWORD *)(a1 + 16));
      v24 = 0;
      v26 = *(_QWORD *)(a1 + 80) + 24LL * *(int *)(a1 + 92);
      *(_QWORD *)v26 = v15;
      v27 = *a3;
      *(_BYTE *)(v26 + 16) = a2;
      *(_BYTE *)(v26 + 17) = 1;
      *(_QWORD *)(v26 + 8) = v27;
    }
  }
  else
  {
    v24 = 2;
    qdf_trace_msg(
      0xA5u,
      2u,
      "%s: Nbuf alloc failed",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_mgmt_rx_srng_alloc_buf");
  }
  return v24;
}
