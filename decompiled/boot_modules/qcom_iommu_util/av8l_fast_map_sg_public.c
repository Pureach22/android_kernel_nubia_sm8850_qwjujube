__int64 __fastcall av8l_fast_map_sg_public(__int64 a1, unsigned __int64 a2, __int64 a3, int a4, char a5, _QWORD *a6)
{
  __int64 v6; // x9
  __int64 v7; // x8
  int v13; // w26
  __int64 v14; // x24
  __int64 v15; // x28
  __int64 v16; // x8
  unsigned __int64 v17; // x2
  __int64 v18; // x9
  unsigned __int64 v19; // x10
  unsigned __int64 v20; // x1
  unsigned __int64 v21; // x11
  unsigned __int64 v22; // x8
  __int64 v23; // x13
  __int64 v24; // x12
  __int64 v25; // x11
  __int64 *v26; // x14
  __int64 v27; // x13
  __int64 v28; // x15
  __int64 v29; // x17
  __int64 v30; // x16
  __int64 v31; // x13
  unsigned __int64 v32; // x10
  __int64 *v33; // x9
  __int64 v34; // x12

  if ( a4 )
  {
    v6 = 64;
    v7 = 0x60000000000E03LL;
    if ( (a5 & 4) != 0 )
      v7 = 0x60000000000E07LL;
    if ( (a5 & 0x10) != 0 )
      v7 = 0x60000000000E0BLL;
    if ( (a5 & 2) == 0 )
      v6 = 192;
    v13 = 0;
    v14 = a1 - 112;
    v15 = v7 | v6;
    do
    {
      v17 = *(_QWORD *)(a1 + 136);
      if ( v17 > a2
        || (v18 = *(_QWORD *)(a1 + 112),
            v19 = (a2 - (v17 & 0xFFFFFFFFFFE00000LL)) >> 12,
            v20 = v18 + 8 * v19,
            v20 >= 0xFFFFFFFFFFFFF001LL) )
      {
        printk(&unk_11667);
        goto LABEL_10;
      }
      v21 = *(unsigned int *)(a3 + 12);
      v22 = v21 >> 12;
      if ( (unsigned int)v21 >= 0x1000 )
      {
        v23 = (*(unsigned int *)(a3 + 8)
             + (((*(_QWORD *)a3 & 0x3FFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
             + 0x5000000000LL)
            & 0xFFFFFFFFF000LL;
        if ( (unsigned int)v21 >= 0x2000 )
        {
          v24 = v22 & 0xFFFFE;
          v26 = (__int64 *)(v20 + 8);
          v25 = v23 + ((v22 & 0xFFFFE) << 12);
          v27 = v23 + 4096;
          v28 = v22 & 0xFFFFE;
          do
          {
            v29 = v15 | v27;
            v28 -= 2;
            v30 = v15 | (v27 - 4096);
            v27 += 0x2000;
            *(v26 - 1) = v30;
            *v26 = v29;
            v26 += 2;
          }
          while ( v28 );
          if ( v24 == v22 )
            goto LABEL_9;
        }
        else
        {
          v24 = 0;
          v25 = (*(unsigned int *)(a3 + 8)
               + (((*(_QWORD *)a3 & 0x3FFFFFFFFFCLL) - -64LL * (memstart_addr >> 12)) << 6)
               + 0x5000000000LL)
              & 0xFFFFFFFFF000LL;
        }
        v31 = 8 * v24 + 8 * v19;
        v32 = v22 - v24;
        v33 = (__int64 *)(v18 + v31);
        do
        {
          v34 = v15 | v25;
          --v32;
          v25 += 4096;
          *v33++ = v34;
        }
        while ( v32 );
      }
LABEL_9:
      av8l_clean_range(v14, v20, v20 + 8 * v22);
LABEL_10:
      v16 = *(unsigned int *)(a3 + 12);
      ++v13;
      a2 += v16;
      *a6 += v16;
      a3 = sg_next(a3);
    }
    while ( v13 != a4 );
  }
  return 0;
}
