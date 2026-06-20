__int64 __fastcall dp_tx_desc_pool_alloc(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v15; // w1
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x8
  const char *v26; // x2
  unsigned int v27; // w19

  if ( (a4 & 1) != 0 )
  {
    if ( (unsigned __int8)a2 < 7u )
    {
      v15 = 1;
      goto LABEL_6;
    }
  }
  else if ( (unsigned __int8)a2 < 7u )
  {
    v15 = 0;
LABEL_6:
    v16 = a1 + 296LL * (unsigned __int8)a2;
    *(_QWORD *)(v16 + 2296) = 4096;
    dp_desc_multi_pages_mem_alloc(a1, v15, v16 + 2272, 0x100u, a3, 0, 1, a5, a6, a7, a8, a9, a10, a11, a12);
    if ( *(_WORD *)(v16 + 2274) )
    {
      v25 = *(_DWORD **)(a1 + 1728);
      if ( *(v25 - 1) != 509597639 )
        __break(0x8228u);
      if ( !((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v25)(a1, a3, a2) )
        return 0;
      v26 = "%s: failed to allocate arch specific descriptors";
    }
    else
    {
      v26 = "%s: Multi page alloc fail, tx desc";
    }
    v27 = 2;
    qdf_trace_msg(0x45u, 2u, v26, v17, v18, v19, v20, v21, v22, v23, v24, "dp_tx_desc_pool_alloc");
    return v27;
  }
  __break(0x5512u);
  return dp_tx_desc_pool_free();
}
