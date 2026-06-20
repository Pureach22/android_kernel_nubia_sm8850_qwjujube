__int64 __fastcall av8l_fast_map_pages(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        char a6,
        __int64 a7,
        unsigned __int64 *a8)
{
  unsigned __int64 v8; // x9
  __int64 v9; // x10
  unsigned __int64 v10; // x11
  unsigned __int64 v11; // x1
  unsigned __int64 v12; // x20
  __int64 v13; // x12
  __int64 v14; // x9
  unsigned __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x14
  __int64 v19; // x13
  __int64 v20; // x12
  __int64 *v21; // x15
  __int64 v22; // x16
  __int64 v23; // x2
  __int64 v24; // x17
  __int64 v25; // x14
  unsigned __int64 v26; // x11
  __int64 *v27; // x10
  __int64 v28; // x13

  v8 = *(_QWORD *)(a1 + 136);
  if ( v8 <= a2 )
  {
    v9 = *(_QWORD *)(a1 + 112);
    v10 = (a2 - (v8 & 0xFFFFFFFFFFE00000LL)) >> 12;
    v11 = v9 + 8 * v10;
    if ( v11 <= 0xFFFFFFFFFFFFF000LL )
    {
      v12 = a5 * a4;
      v13 = 64;
      v14 = 0x60000000000E07LL;
      if ( (a6 & 4) == 0 )
        v14 = 0x60000000000E03LL;
      if ( (a6 & 0x10) != 0 )
        v14 = 0x60000000000E0BLL;
      v16 = v12 >> 12;
      if ( (a6 & 2) == 0 )
        v13 = 192;
      if ( v12 < 0x1000 )
        goto LABEL_17;
      v17 = v14 | v13;
      v18 = a3 & 0xFFFFFFFFF000LL;
      if ( v12 >= 0x2000 )
      {
        v19 = v16 & 0xFFFFFFFFFFFFELL;
        v21 = (__int64 *)(v11 + 8);
        v20 = v18 + ((v16 & 0xFFFFFFFFFFFFELL) << 12);
        v22 = v16 & 0xFFFFFFFFFFFFELL;
        do
        {
          v23 = v17 | v18;
          v22 -= 2;
          v24 = v17 | (v18 + 4096);
          v18 += 0x2000;
          *(v21 - 1) = v23;
          *v21 = v24;
          v21 += 2;
        }
        while ( v22 );
        if ( v16 == v19 )
          goto LABEL_17;
      }
      else
      {
        v19 = 0;
        v20 = a3 & 0xFFFFFFFFF000LL;
      }
      v25 = 8 * v19 + 8 * v10;
      v26 = v16 - v19;
      v27 = (__int64 *)(v9 + v25);
      do
      {
        v28 = v17 | v20;
        --v26;
        v20 += 4096;
        *v27++ = v28;
      }
      while ( v26 );
LABEL_17:
      av8l_clean_range(a1 - 112, v11, v11 + 8 * v16);
      *a8 = v12;
      return 0;
    }
  }
  printk(&unk_11667);
  return 4294967274LL;
}
