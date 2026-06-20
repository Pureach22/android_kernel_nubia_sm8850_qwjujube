__int64 __fastcall dp_mon_dest_rings_alloc(__int64 a1, signed int a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x20
  __int64 dma_mon_buf_ring_size; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x2
  unsigned int dma_rx_mon_dest_ring_size; // w0
  unsigned int dma_mon_desc_ring_size; // w0
  _QWORD *v20; // x4
  unsigned int v21; // w19

  v2 = *(_QWORD **)(a1 + 8);
  if ( *(_BYTE *)(v2[5] + 633LL) != 1 )
    return 0;
  v3 = *(_QWORD *)(a1 + 288);
  dma_mon_buf_ring_size = wlan_cfg_get_dma_mon_buf_ring_size(v3);
  if ( (unsigned int)a2 < 3 )
  {
    if ( (unsigned int)dp_srng_alloc(v2, (__int64)&v2[10 * a2 + 60], 0x10u, dma_mon_buf_ring_size, 0) )
    {
      v17 = "%s: %pK: SRNG setup failed forrxdma_mon_buf_ring ";
LABEL_9:
      v20 = v2;
      v21 = 2;
      qdf_trace_msg(0x92u, 2u, v17, v9, v10, v11, v12, v13, v14, v15, v16, "dp_mon_dest_rings_alloc", v20);
      return v21;
    }
    dma_rx_mon_dest_ring_size = wlan_cfg_get_dma_rx_mon_dest_ring_size(v3);
    if ( (unsigned int)dp_srng_alloc(v2, (__int64)&v2[10 * a2 + 80], 0x12u, dma_rx_mon_dest_ring_size, 0) )
    {
      v17 = "%s: %pK: SRNG setup failed forrxdma_mon_dst_ring";
      goto LABEL_9;
    }
    dma_mon_desc_ring_size = wlan_cfg_get_dma_mon_desc_ring_size(v3);
    if ( (unsigned int)dp_srng_alloc(v2, (__int64)&v2[10 * a2 + 20], 0x13u, dma_mon_desc_ring_size, 0) )
    {
      v17 = "%s: %pK: SRNG setup failed forrxdma_mon_desc_ring";
      goto LABEL_9;
    }
    return 0;
  }
  __break(0x5512u);
  return hal_rx_msdu_list_get_0(dma_mon_buf_ring_size, v6, v7, v8);
}
