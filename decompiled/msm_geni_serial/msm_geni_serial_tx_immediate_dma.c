__int64 __fastcall msm_geni_serial_tx_immediate_dma(_QWORD *a1, __int64 a2, unsigned __int64 a3)
{
  unsigned int v3; // w19
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x10
  unsigned __int64 v7; // x8
  int v8; // w9
  int v9; // w10
  int v10; // w9
  __int64 v11; // x11
  __int64 v12; // x11
  unsigned __int64 v14; // x10
  __int64 v15; // x12
  __int64 v16; // x11
  unsigned __int8 *v17; // x13
  unsigned __int64 v18; // x14
  __int64 v19; // x15
  unsigned int v20; // t1
  char v21; // w17

  v3 = a3;
  v5 = a3;
  if ( a3 )
  {
    v6 = a3 - 1;
    if ( a3 == 1 )
    {
      v7 = 0;
      v8 = 0;
      v5 = 0;
      goto LABEL_4;
    }
    v8 = 0;
    v7 = 0;
    if ( (unsigned int)v6 > 0x7FFFFFFE )
    {
      v5 = 0;
LABEL_4:
      v9 = 8 * v8;
      v10 = v8 + 1;
      do
      {
        v11 = *(unsigned __int8 *)(a2 + v7);
        v7 = v10++;
        v12 = v11 << v9;
        v9 += 8;
        v5 |= v12;
      }
      while ( v7 < a3 );
      goto LABEL_6;
    }
    v14 = v6 >> 31;
    v5 = 0;
    if ( v14 )
      goto LABEL_4;
    v7 = (unsigned int)a3 & 0xFFFFFFFE;
    v15 = 0;
    v16 = 0;
    v8 = a3 & 0xFFFFFFFE;
    v17 = (unsigned __int8 *)(a2 + 1);
    v18 = v7;
    do
    {
      v19 = *(v17 - 1);
      v20 = *v17;
      v17 += 2;
      v21 = v15 & 0xF0;
      v18 -= 2LL;
      v15 += 16;
      v14 |= v19 << v21;
      v16 |= (unsigned __int64)v20 << (v21 | 8u);
    }
    while ( v18 );
    v5 = v16 | v14;
    if ( v7 != a3 )
      goto LABEL_4;
  }
LABEL_6:
  writel_relaxed(3, *a1 + 3148LL);
  writel_relaxed((unsigned int)v5, *a1 + 3120LL);
  writel_relaxed(HIDWORD(v5), *a1 + 3124LL);
  writel_relaxed(3, *a1 + 3128LL);
  return writel(v3, *a1 + 3132LL);
}
