__int64 __fastcall _qdf_mem_map_page(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 *a5)
{
  unsigned __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x0
  __int64 v9; // x4
  __int64 v10; // x0

  v6 = ((unsigned __int64)((a2 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL;
  v7 = *(_QWORD *)(((unsigned __int64)((a2 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x13FFFFFF8LL);
  if ( (v7 & 1) != 0 )
    v6 = v7 - 1;
  v8 = *(_QWORD *)(a1 + 40);
  if ( a3 >= 3 )
    v9 = 3;
  else
    v9 = a3;
  v10 = dma_map_page_attrs(
          v8,
          v6,
          a2 - (((v6 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL) + 0x100000000000000LL,
          a4,
          v9,
          0);
  *a5 = v10;
  return 16 * (unsigned int)(v10 == -1);
}
