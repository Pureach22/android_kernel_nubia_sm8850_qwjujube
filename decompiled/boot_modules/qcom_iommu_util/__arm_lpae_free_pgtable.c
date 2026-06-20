__int64 __fastcall _arm_lpae_free_pgtable(__int64 a1, int a2, __int64 *a3, char a4)
{
  __int64 v4; // x8
  __int64 v9; // x24
  __int64 v10; // x26
  __int64 *v11; // x19
  __int64 v12; // x8
  __int64 v13; // t1
  bool v14; // zf
  __int64 v15; // x10
  __int64 v16; // x10
  __int64 v17; // x8
  __int64 v18; // x8
  unsigned __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x1
  void (__fastcall *v23)(__int64, __int64 *); // x8
  __int64 v24; // x0
  __int64 v25; // x3
  _DWORD *v26; // x8
  __int64 v28; // [xsp+8h] [xbp-8h]

  v4 = 208;
  if ( *(_DWORD *)(a1 + 204) == a2 )
    v4 = 200;
  v9 = 8LL << *(_DWORD *)(a1 + v4);
  if ( a2 == 3 )
    v10 = 0;
  else
    v10 = 8LL << *(_DWORD *)(a1 + v4);
  v28 = *(_QWORD *)(a1 + 8);
  if ( v10 )
  {
    v11 = a3;
    do
    {
      v13 = *v11++;
      v12 = v13;
      if ( v13 )
      {
        v14 = *(_DWORD *)a1 != 5 && a2 == 3;
        v15 = v14 ? 3LL : 1LL;
        if ( (v12 & 3) != v15 )
        {
          v16 = v12 & 0xFFFFFFFFF000LL;
          v17 = v12 & 0x7FFFFF0000LL;
          if ( (unsigned __int64)(8LL << *(_DWORD *)(a1 + 208)) < 0x10000 )
            v17 = v16;
          _arm_lpae_free_pgtable(a1, (unsigned int)(a2 + 1), (v17 - memstart_addr) | 0xFFFFFF8000000000LL, a4 & 1);
        }
      }
      v10 -= 8;
    }
    while ( v10 );
  }
  if ( (*(_BYTE *)(a1 + 48) & 1) == 0 )
  {
    v18 = (__int64)((_QWORD)a3 << 8) >> 8;
    v19 = (unsigned __int64)(v18 + 0x8000000000LL) >> 38;
    v20 = memstart_addr + v18 + 0x8000000000LL;
    v21 = v18 - kimage_voffset;
    if ( v19 )
      v22 = v21;
    else
      v22 = v20;
    dma_unmap_page_attrs(*(_QWORD *)(a1 + 64), v22, v9, 1, 0);
  }
  if ( (a4 & 1) != 0 )
  {
    v23 = **(void (__fastcall ***)(__int64, __int64 *))(a1 + 232);
    if ( *((_DWORD *)v23 - 1) != -72220 )
      __break(0x8228u);
    v23(v28, a3);
  }
  else
  {
    qcom_io_pgtable_free_page(((unsigned __int64)(((__int64)((_QWORD)a3 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
  }
  v24 = *(_QWORD *)(a1 + 8);
  v25 = 1LL << (*(_DWORD *)(a1 + 208) * (5 - (unsigned __int8)a2) + 3);
  v26 = *(_DWORD **)(*(_QWORD *)(a1 + 240) + 8LL);
  if ( *(v26 - 1) != -716079766 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD, __int64))v26)(v24, a3, 0, v25);
}
