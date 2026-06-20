void *__fastcall dp_tx_ext_desc_pool_free_by_id(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( a2 >= 7u )
  {
    __break(0x5512u);
    JUMPOUT(0x59DB8A0);
  }
  v10 = a1 + 136LL * a2;
  v12 = *(_QWORD *)(v10 + 4160);
  dp_desc_multi_pages_mem_free(a1, 4u, (_BYTE *)(v10 + 4096), 0, 1, a3, a4, a5, a6, a7, a8, a9, a10);
  return dp_desc_multi_pages_mem_free(a1, 3u, (_BYTE *)(v10 + 4048), v12, 0, v13, v14, v15, v16, v17, v18, v19, v20);
}
