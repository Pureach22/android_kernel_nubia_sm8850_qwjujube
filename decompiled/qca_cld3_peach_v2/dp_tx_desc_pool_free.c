__int64 __fastcall dp_tx_desc_pool_free(
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
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 (*v12)(void); // x8

  if ( a2 >= 7u )
  {
    __break(0x5512u);
    return dp_tx_desc_pool_init();
  }
  else
  {
    v10 = a1 + 296LL * a2;
    if ( *(_WORD *)(v10 + 2322) )
    {
      v11 = a1;
      dp_desc_multi_pages_mem_free(a1, 0, (_BYTE *)(v10 + 2320), 0, 1, a3, a4, a5, a6, a7, a8, a9, a10);
      a1 = v11;
    }
    v12 = *(__int64 (**)(void))(a1 + 1784);
    if ( *((_DWORD *)v12 - 1) != 357773931 )
      __break(0x8228u);
    return v12();
  }
}
