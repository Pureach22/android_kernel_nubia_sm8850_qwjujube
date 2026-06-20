__int64 __fastcall async_si_buffer(__int64 a1)
{
  char v2; // w9
  __int64 result; // x0
  unsigned int v4; // w11
  int v5; // w12
  __int64 v6; // x13
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x9
  int *v9; // x14
  int v10; // t1
  unsigned __int64 v11; // x11
  unsigned __int64 v12; // x12
  unsigned __int64 v13; // x12
  __int64 v14; // x15
  __int64 v15; // x13
  unsigned __int64 v16; // x16
  int *v17; // x15
  int v18; // w17
  int v19; // t1
  int *v20; // x12
  int v21; // t1
  unsigned __int64 v22; // x8

  v2 = *(_BYTE *)(a1 + 4);
  result = *(_QWORD *)(a1 + 1648);
  if ( (v2 & 1) != 0 )
  {
    v4 = *(_DWORD *)(result + 12);
    v5 = (unsigned __int8)v4 >> 4;
    v6 = v4 & 0xF;
    v7 = v5 + (v4 & 0xF);
    v8 = (8 * (((unsigned __int16)v4 >> 12) + ((v4 >> 8) & 0xF) + (_WORD)v5 + (v4 & 0xF)) + 23) & 0x3F8;
    if ( (v4 & 0xF) != 0 )
    {
      v9 = (int *)(result + 20);
      do
      {
        v10 = *v9;
        v9 += 2;
        --v6;
        v8 += (v10 + 7) & 0xFFFFFFF8;
      }
      while ( v6 );
    }
    if ( (unsigned __int8)v4 >> 4 )
    {
      v11 = v4 & 0xF;
      if ( v11 + 1 > v7 )
        v12 = v11 + 1;
      else
        v12 = v5 + (*(_DWORD *)(result + 12) & 0xFu);
      v13 = v12 - v11;
      if ( v13 < 2 )
        goto LABEL_13;
      v14 = result + 8 * v11;
      v15 = 0;
      v11 += v13 & 0xFFFFFFFFFFFFFFFELL;
      v16 = v13 & 0xFFFFFFFFFFFFFFFELL;
      v17 = (int *)(v14 + 28);
      do
      {
        v18 = *(v17 - 2);
        v19 = *v17;
        v17 += 4;
        v16 -= 2LL;
        v8 += (v18 + 7) & 0xFFFFFFF8;
        v15 += (v19 + 7) & 0xFFFFFFF8;
      }
      while ( v16 );
      v8 += v15;
      if ( v13 != (v13 & 0xFFFFFFFFFFFFFFFELL) )
      {
LABEL_13:
        v20 = (int *)(result + 8 * v11 + 20);
        do
        {
          v21 = *v20;
          v20 += 2;
          ++v11;
          v8 += (v21 + 7) & 0xFFFFFFF8;
        }
        while ( v11 < v7 );
      }
    }
    v22 = *(_QWORD *)(a1 + 1656);
    if ( v22 <= v8 )
    {
      printk(&unk_B40E, v22 - v8);
      return 0;
    }
    else
    {
      result += v8;
    }
  }
  return result;
}
