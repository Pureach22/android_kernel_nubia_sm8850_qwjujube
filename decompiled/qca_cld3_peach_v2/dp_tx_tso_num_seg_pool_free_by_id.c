void *__fastcall dp_tx_tso_num_seg_pool_free_by_id(
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
  if ( a2 >= 7u )
  {
    __break(0x5512u);
    JUMPOUT(0x5A44914);
  }
  return dp_desc_multi_pages_mem_free(a1, 6u, (_BYTE *)(a1 + 72LL * a2 + 5344), 0, 1, a3, a4, a5, a6, a7, a8, a9, a10);
}
