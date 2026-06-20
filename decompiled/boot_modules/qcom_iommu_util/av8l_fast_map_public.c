__int64 __fastcall av8l_fast_map_public(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned __int64 a4, char a5)
{
  unsigned __int64 v5; // x8
  __int64 v6; // x10
  unsigned __int64 v7; // x11
  unsigned __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x12
  unsigned __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x14
  __int64 v15; // x13
  __int64 v16; // x12
  __int64 *v17; // x15
  __int64 v18; // x16
  __int64 v19; // x2
  __int64 v20; // x17
  __int64 v21; // x14
  unsigned __int64 v22; // x11
  __int64 *v23; // x10
  __int64 v24; // x13

  v5 = *(_QWORD *)(a1 + 136);
  if ( v5 <= a2 )
  {
    v6 = *(_QWORD *)(a1 + 112);
    v7 = (a2 - (v5 & 0xFFFFFFFFFFE00000LL)) >> 12;
    v8 = v6 + 8 * v7;
    if ( v8 < 0xFFFFFFFFFFFFF001LL )
    {
      v9 = 0x60000000000E03LL;
      if ( (a5 & 4) != 0 )
        v9 = 0x60000000000E07LL;
      if ( (a5 & 0x10) != 0 )
        v10 = 0x60000000000E0BLL;
      else
        v10 = v9;
      v11 = 64;
      v12 = a4 >> 12;
      if ( (a5 & 2) == 0 )
        v11 = 192;
      if ( a4 < 0x1000 )
        goto LABEL_18;
      v13 = v10 | v11;
      v14 = a3 & 0xFFFFFFFFF000LL;
      if ( a4 >= 0x2000 )
      {
        v15 = v12 & 0xFFFFFFFFFFFFELL;
        v17 = (__int64 *)(v8 + 8);
        v16 = v14 + ((v12 & 0xFFFFFFFFFFFFELL) << 12);
        v18 = v12 & 0xFFFFFFFFFFFFELL;
        do
        {
          v19 = v13 | v14;
          v18 -= 2;
          v20 = v13 | (v14 + 4096);
          v14 += 0x2000;
          *(v17 - 1) = v19;
          *v17 = v20;
          v17 += 2;
        }
        while ( v18 );
        if ( v12 == v15 )
          goto LABEL_18;
      }
      else
      {
        v15 = 0;
        v16 = a3 & 0xFFFFFFFFF000LL;
      }
      v21 = 8 * v15 + 8 * v7;
      v22 = v12 - v15;
      v23 = (__int64 *)(v6 + v21);
      do
      {
        v24 = v13 | v16;
        --v22;
        v16 += 4096;
        *v23++ = v24;
      }
      while ( v22 );
LABEL_18:
      av8l_clean_range(a1 - 112, v8, v8 + 8 * v12);
      return 0;
    }
  }
  printk(&unk_11667);
  return 4294967274LL;
}
