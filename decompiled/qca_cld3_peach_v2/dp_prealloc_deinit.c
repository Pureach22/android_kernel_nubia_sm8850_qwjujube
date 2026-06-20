__int64 __fastcall dp_prealloc_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x20
  _QWORD *v59; // x24
  __int64 v60; // x24
  unsigned int v61; // w20
  char *v62; // x26
  __int64 v63; // x20
  __int64 *v64; // x24
  __int64 v65; // x5
  __int64 v66; // [xsp+0h] [xbp-10h]

  result = (__int64)_cds_get_context(64, (__int64)"dp_prealloc_deinit", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !result )
    return result;
  v17 = result;
  if ( byte_16520 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: page pool %d mem type %d in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_page_pool_deinit",
      0,
      (unsigned int)g_dp_page_pool_allocs[0]);
  if ( qword_16500 )
  {
    _qdf_page_pool_destroy(qword_16500);
    byte_16520 = 0;
    qword_16500 = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: page pool %d type %d pre-alloc pool free succ",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dp_prealloc_page_pool_deinit",
      0,
      (unsigned int)g_dp_page_pool_allocs[0]);
  }
  if ( byte_16550 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: page pool %d mem type %d in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_page_pool_deinit",
      1,
      (unsigned int)dword_16528);
  if ( qword_16530 )
  {
    _qdf_page_pool_destroy(qword_16530);
    byte_16550 = 0;
    qword_16530 = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: page pool %d type %d pre-alloc pool free succ",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "dp_prealloc_page_pool_deinit",
      1,
      (unsigned int)dword_16528);
  }
  if ( byte_16580 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: page pool %d mem type %d in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_page_pool_deinit",
      2,
      (unsigned int)dword_16558);
  if ( qword_16560 )
  {
    _qdf_page_pool_destroy(qword_16560);
    byte_16580 = 0;
    qword_16560 = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: page pool %d type %d pre-alloc pool free succ",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "dp_prealloc_page_pool_deinit",
      2,
      (unsigned int)dword_16558);
  }
  if ( byte_165B0 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: page pool %d mem type %d in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_page_pool_deinit",
      3,
      (unsigned int)dword_16588);
  if ( qword_16590 )
  {
    _qdf_page_pool_destroy(qword_16590);
    byte_165B0 = 0;
    qword_16590 = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: page pool %d type %d pre-alloc pool free succ",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "dp_prealloc_page_pool_deinit",
      3,
      (unsigned int)dword_16588);
  }
  if ( byte_165E0 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: page pool %d mem type %d in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_page_pool_deinit",
      4,
      (unsigned int)dword_165B8);
  if ( qword_165C0 )
  {
    _qdf_page_pool_destroy(qword_165C0);
    byte_165E0 = 0;
    qword_165C0 = 0;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: page pool %d type %d pre-alloc pool free succ",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "dp_prealloc_page_pool_deinit",
      4,
      (unsigned int)dword_165B8);
  }
  v58 = 0;
  v59 = &unk_16600;
  do
  {
    if ( *((_BYTE *)v59 - 16) )
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: i %d: consistent_mem in use while free",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_prealloc_deinit",
        (unsigned int)v58);
    if ( *v59 )
    {
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: i %d: va aligned %pK pa aligned %pK size %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_prealloc_deinit",
        (unsigned int)v58,
        *v59,
        v59[2],
        *((unsigned int *)v59 - 5));
      _qdf_mem_free_consistent(v17, *(_QWORD *)(v17 + 40), *((_DWORD *)v59 - 5));
      *((_BYTE *)v59 - 16) = 0;
      *(v59 - 1) = 0;
      *v59 = 0;
      v59[1] = 0;
      v59[2] = 0;
    }
    ++v58;
    v59 += 6;
  }
  while ( v58 != 28 );
  v60 = 0;
  v61 = 0;
  do
  {
    v62 = (char *)&g_dp_multi_page_allocs + v60;
    if ( *((_BYTE *)&g_dp_multi_page_allocs + v60 + 20) == 1 )
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: i %d: multi-page mem in use while free",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_prealloc_deinit",
        v61);
    if ( *((_WORD *)v62 + 13) )
    {
      LODWORD(v66) = *((unsigned __int16 *)v62 + 13);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: i %d: type %d cacheable_pages %pK dma_pages %pK num_pages %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_prealloc_deinit",
        v61,
        *(unsigned int *)((char *)&g_dp_multi_page_allocs + v60),
        *(_QWORD *)((char *)&g_dp_multi_page_allocs + v60 + 40),
        *(_QWORD *)((char *)&g_dp_multi_page_allocs + v60 + 32),
        v66);
      qdf_mem_multi_pages_free(
        v17,
        (__int64)&g_dp_multi_page_allocs + v60 + 24,
        0,
        *((_BYTE *)&g_dp_multi_page_allocs + v60 + 21));
      v62[20] = 0;
      qdf_mem_set((char *)&g_dp_multi_page_allocs + v60 + 24, 0x28u, 0);
    }
    v60 += 64;
    ++v61;
  }
  while ( v60 != 2112 );
  v63 = 0;
  v64 = &qword_17378;
  do
  {
    if ( *((_BYTE *)v64 - 8) != 1 )
    {
      v65 = *v64;
      if ( !*v64 )
        goto LABEL_35;
LABEL_38:
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: i %d: va unalign %pK pa unalign %pK size %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_prealloc_deinit",
        (unsigned int)v63,
        v65,
        v64[1],
        *((unsigned int *)v64 - 3));
      _qdf_mem_free_consistent(v17, *(_QWORD *)(v17 + 40), *((_DWORD *)v64 - 3));
      *((_BYTE *)v64 - 8) = 0;
      *v64 = 0;
      v64[1] = 0;
      goto LABEL_35;
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: i %d: unaligned mem in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      (unsigned int)v63);
    v65 = *v64;
    if ( *v64 )
      goto LABEL_38;
LABEL_35:
    ++v63;
    v64 += 4;
  }
  while ( v63 != 9 );
  if ( byte_17490 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      0);
  if ( qword_17498 )
  {
    _qdf_mem_free(qword_17498);
    qword_17498 = 0;
  }
  if ( byte_174A8 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      1);
  if ( qword_174B0 )
  {
    _qdf_mem_free(qword_174B0);
    qword_174B0 = 0;
  }
  if ( byte_174C0 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      2);
  if ( qword_174C8 )
  {
    _qdf_mem_free(qword_174C8);
    qword_174C8 = 0;
  }
  if ( byte_174D8 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      3);
  if ( qword_174E0 )
  {
    _qdf_mem_free(qword_174E0);
    qword_174E0 = 0;
  }
  if ( byte_174F0 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      4);
  if ( qword_174F8 )
  {
    _qdf_mem_free(qword_174F8);
    qword_174F8 = 0;
  }
  if ( byte_17508 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      5);
  if ( qword_17510 )
  {
    _qdf_mem_free(qword_17510);
    qword_17510 = 0;
  }
  if ( byte_17520 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      6);
  if ( qword_17528 )
  {
    _qdf_mem_free(qword_17528);
    qword_17528 = 0;
  }
  if ( byte_17538 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      7);
  if ( qword_17540 )
  {
    _qdf_mem_free(qword_17540);
    qword_17540 = 0;
  }
  if ( byte_17550 == 1 )
    qdf_trace_msg(
      0x45u,
      3u,
      "%s: i %d: context in use while free",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_prealloc_deinit",
      8);
  result = qword_17558;
  if ( qword_17558 )
  {
    result = _qdf_mem_free(qword_17558);
    qword_17558 = 0;
  }
  return result;
}
