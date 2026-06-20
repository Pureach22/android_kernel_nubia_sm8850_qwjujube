__int64 __fastcall dp_rx_desc_pool_alloc(
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
  unsigned int v12; // w1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w19

  v12 = *(_DWORD *)(a3 + 104);
  *(_WORD *)(a3 + 4) = 32;
  *(_QWORD *)(a3 + 32) = 4096;
  dp_desc_multi_pages_mem_alloc(a1, v12, a3 + 8, 0x20u, a2, 0, 1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( *(_WORD *)(a3 + 10) )
  {
    if ( (unsigned int)qdf_mem_multi_page_link(*(_QWORD *)(a1 + 24), (unsigned __int16 *)(a3 + 8), 0x20u, a2, 1) )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: overflow num link,size=%d, elem=%d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "dp_rx_desc_pool_alloc",
        32,
        a2);
      if ( *(_QWORD *)(a3 + 24) )
        dp_desc_multi_pages_mem_free(
          a1,
          *(_DWORD *)(a3 + 104),
          (_BYTE *)(a3 + 8),
          0,
          1,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38);
      return 5;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v39 = 2;
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Multi page alloc fail,size=%d, elem=%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_rx_desc_pool_alloc",
      32,
      a2);
  }
  return v39;
}
