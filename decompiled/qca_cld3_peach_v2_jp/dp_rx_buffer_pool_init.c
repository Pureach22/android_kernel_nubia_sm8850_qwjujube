__int64 __fastcall dp_rx_buffer_pool_init(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 v5; // x20
  __int64 v6; // x23
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int16 rx_refill_buf_pool_size; // w0
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  const char *v26; // x2
  unsigned int v27; // w4
  int v28; // w26
  unsigned __int16 v29; // w25
  __int64 v30; // x9
  __int64 v31; // x0
  __int64 v32; // x22
  char v33; // w8
  __int64 v34; // x0
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w22
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // [xsp+8h] [xbp-48h]

  if ( a2 > 1u )
  {
    __break(0x5512u);
    JUMPOUT(0x5B12F20);
  }
  v54 = v3;
  v5 = a1 + 32LL * a2 + 18768;
  v6 = a1 + 120LL * a2 + 12368;
  if ( (wlan_cfg_is_rx_refill_buffer_pool_enabled(*(_QWORD *)(a1 + 40)) & 1) == 0 )
  {
    v26 = "%s: RX refill buffer pool support is disabled";
LABEL_17:
    qdf_trace_msg(0x45u, 2u, v26, v7, v8, v9, v10, v11, v12, v13, v14, "dp_rx_refill_buff_pool_init", v2, v54);
    v33 = 0;
    goto LABEL_20;
  }
  rx_refill_buf_pool_size = wlan_cfg_get_rx_refill_buf_pool_size(*(_QWORD *)(a1 + 40));
  *(_WORD *)(a1 + 18816) = rx_refill_buf_pool_size;
  v16 = _qdf_mem_malloc(8 * (unsigned int)rx_refill_buf_pool_size, "dp_rx_refill_buff_pool_init", 304);
  *(_QWORD *)(a1 + 18824) = v16;
  if ( !v16 )
  {
    v26 = "%s: Failed to allocate memory for RX refill buf element";
    goto LABEL_17;
  }
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), 0) )
  {
    v25 = 0;
  }
  else
  {
    v25 = *(_QWORD *)(a1 + 72);
  }
  v27 = *(unsigned __int16 *)(a1 + 18816);
  *(_QWORD *)(a1 + 18808) = v25;
  *(_WORD *)(a1 + 18804) = 0;
  if ( v27 < 2 )
  {
    v29 = 0;
  }
  else
  {
    v28 = 0;
    v29 = 0;
    do
    {
      v31 = _qdf_nbuf_alloc(
              *(_QWORD *)(a1 + 24),
              *(unsigned __int16 *)(v6 + 74),
              0,
              *(unsigned __int8 *)(v6 + 76),
              0,
              "dp_rx_refill_buff_pool_init",
              317);
      if ( v31 )
      {
        v32 = v31;
        if ( (unsigned int)qdf_nbuf_map_nbytes_single_0(*(_QWORD *)(a1 + 24), v31, *(unsigned __int16 *)(v6 + 74)) )
        {
          _qdf_nbuf_free(v32);
        }
        else
        {
          v30 = v29++;
          *(_QWORD *)(*(_QWORD *)(a1 + 18824) + 8 * v30) = v32;
        }
      }
      ++v28;
    }
    while ( v28 < *(unsigned __int16 *)(a1 + 18816) - 1 );
  }
  *(_WORD *)(a1 + 18802) = v29;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: RX refill buffer pool required allocation: %u actual allocation: %u",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "dp_rx_refill_buff_pool_init",
    v2,
    v54);
  v33 = 1;
LABEL_20:
  v34 = *(_QWORD *)(a1 + 40);
  *(_BYTE *)(a1 + 18800) = v33;
  result = wlan_cfg_is_rx_buffer_pool_enabled(v34);
  if ( (result & 1) != 0 )
  {
    if ( (*(_BYTE *)(v5 + 28) & 1) == 0 )
    {
      v44 = 128;
      *(_QWORD *)v5 = v5;
      *(_QWORD *)(v5 + 8) = v5;
      *(_QWORD *)(v5 + 16) = 0;
      do
      {
        v45 = _qdf_nbuf_alloc(
                *(_QWORD *)(a1 + 24),
                *(unsigned __int16 *)(v6 + 74),
                0,
                *(unsigned __int8 *)(v6 + 76),
                0,
                "dp_rx_buffer_pool_init",
                365);
        if ( v45 )
          skb_queue_tail(v5, v45);
        --v44;
      }
      while ( v44 );
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: RX buffer pool required allocation: %u actual allocation: %u",
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 v51,
                 v52,
                 v53,
                 "dp_rx_buffer_pool_init",
                 128,
                 *(unsigned int *)(v5 + 16));
      *(_BYTE *)(v5 + 28) = 1;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: RX buffer pool support is disabled",
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               "dp_rx_buffer_pool_init");
    *(_BYTE *)(v5 + 28) = 0;
  }
  return result;
}
