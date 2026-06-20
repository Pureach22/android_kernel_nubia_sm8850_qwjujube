__int64 __fastcall dp_rx_defrag_save_info_from_ring_desc(
        __int64 a1,
        const void *a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5)
{
  unsigned int entrysize; // w0
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  void *v20; // x24
  unsigned int v21; // w0
  unsigned int v22; // w22
  __int64 v23; // x8

  entrysize = hal_srng_get_entrysize(*(_QWORD *)(a1 + 1128), 0);
  v11 = _qdf_mem_malloc(entrysize, "dp_rx_defrag_save_info_from_ring_desc", 1808);
  if ( v11 )
  {
    v20 = (void *)v11;
    v21 = hal_srng_get_entrysize(*(_QWORD *)(a1 + 1128), 0);
    qdf_mem_copy(v20, a2, v21);
    v22 = 0;
    v23 = a4 + 120LL * a5;
    *(_QWORD *)(v23 + 200) = v20;
    *(_QWORD *)(v23 + 208) = a3;
  }
  else
  {
    v22 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Memory alloc failed !",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_rx_defrag_save_info_from_ring_desc");
  }
  return v22;
}
