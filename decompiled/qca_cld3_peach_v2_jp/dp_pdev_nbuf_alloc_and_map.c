__int64 __fastcall dp_pdev_nbuf_alloc_and_map(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 result; // x0
  unsigned int v11; // w24
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  __int64 v22; // x22
  __int64 v23; // x21
  __int64 v24; // x24
  const char **v25; // x23
  char v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  const char *v36; // x0
  const char *v37; // x2
  __int64 v38; // x0
  __int64 v39; // x20
  __int64 v40; // x8
  __int64 v41; // x9
  char v42; // [xsp+Ch] [xbp-4h]

  result = dp_rx_page_pool_nbuf_alloc_and_map(a1, a2, a6, 0);
  if ( !(_DWORD)result )
    return result;
  v11 = result;
  v12 = _qdf_nbuf_alloc(
          *(_QWORD *)(a1 + 24),
          *(unsigned __int16 *)(a4 + 74),
          0,
          *(unsigned __int8 *)(a4 + 76),
          0,
          "dp_rx_nbuf_alloc_for_frag_info",
          3215);
  a2[1] = v12;
  if ( v12 )
  {
    v21 = *(_QWORD *)(a1 + 24);
    v22 = *(unsigned __int16 *)(a4 + 74);
    v23 = v12;
    if ( (_qdf_is_pp_nbuf(v12) & 1) != 0 && *(_QWORD *)(v23 + 40) )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(v21 + 40) + 844LL) & 0x40) == 0 )
        _dma_sync_single_for_device();
      goto LABEL_24;
    }
    v24 = *(_QWORD *)(v23 + 224);
    v25 = *(const char ***)(v21 + 40);
    v26 = is_vmalloc_addr(v24);
    if ( (v26 & 1) != 0 && (dma_map_single_attrs___already_done_0 & 1) == 0 )
    {
      v42 = v26;
      dma_map_single_attrs___already_done_0 = 1;
      v36 = (const char *)dev_driver_string(v25);
      v37 = v25[14];
      if ( !v37 )
        v37 = *v25;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v36, v37);
      __break(0x800u);
      if ( (v42 & 1) != 0 )
        goto LABEL_10;
    }
    else if ( (v26 & 1) != 0 )
    {
LABEL_10:
      *(_QWORD *)(v23 + 40) = -1;
LABEL_11:
      v35 = a2[1];
      if ( v35 )
        _qdf_nbuf_free(v35);
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: nbuf map failed",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "dp_pdev_nbuf_alloc_and_map");
      if ( a3 )
        ++*(_DWORD *)(a3 + 444);
      return 5;
    }
    v38 = dma_map_page_attrs(
            v25,
            ((unsigned __int64)((v24 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v24 & 0xFFF,
            v22,
            2,
            0);
    *(_QWORD *)(v23 + 40) = v38;
    if ( v38 != -1 )
    {
      v39 = *(int *)(v23 + 212);
      qdf_mem_dp_rx_skb_cnt_inc();
      qdf_mem_dp_rx_skb_inc(v39);
      qdf_mem_skb_total_inc(v39);
LABEL_24:
      v40 = a2[1];
      result = 0;
      v41 = 80;
      if ( (*(_BYTE *)(v40 + 68) & 4) == 0 )
        v41 = 40;
      *a2 = *(_QWORD *)(v40 + v41);
      return result;
    }
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: nbuf alloc failed",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "dp_pdev_nbuf_alloc_and_map");
  if ( a3 )
    ++*(_DWORD *)(a3 + 436);
  return v11;
}
