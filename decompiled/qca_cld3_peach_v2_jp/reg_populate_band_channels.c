__int64 __fastcall reg_populate_band_channels(
        __int64 result,
        unsigned int a2,
        unsigned __int16 *a3,
        int a4,
        unsigned __int16 a5,
        __int64 a6)
{
  __int64 v6; // x8
  unsigned int v7; // w9
  unsigned int v8; // w12
  __int64 v9; // x1
  int v10; // w6
  unsigned int v11; // w1
  unsigned int v12; // w4
  __int64 v13; // x17
  unsigned int v14; // w7
  int v15; // w21
  unsigned __int16 *v16; // x6
  int v17; // w7
  unsigned int v18; // w7
  char v19; // w19
  unsigned __int16 v20; // w19

  if ( (unsigned int)result <= a2 )
  {
    v6 = (unsigned int)result;
    v7 = a2 + 1;
    v8 = a5;
    while ( 1 )
    {
      v9 = channel_map + 12 * v6;
      v10 = *(unsigned __int8 *)(v9 + 4);
      v11 = *(unsigned __int16 *)(v9 + 6) <= v8 ? v8 : *(unsigned __int16 *)(v9 + 6);
      if ( v10 )
      {
        v12 = *(unsigned __int16 *)(channel_map + 12 * v6 + 8) >= 0x14u
            ? 20
            : *(unsigned __int16 *)(channel_map + 12 * v6 + 8);
        if ( v12 >= v11 )
          break;
      }
LABEL_3:
      if ( v7 == (_DWORD)++v6 )
        return result;
    }
    v13 = a6 + 36 * v6;
    while ( 1 )
    {
      v14 = v12 >> 1;
      if ( a4 )
      {
        v15 = a4;
        v16 = a3;
        while ( *(_DWORD *)v13 - v14 < *v16 || *(_DWORD *)v13 + v14 > v16[1] )
        {
          --v15;
          v16 += 7;
          if ( !v15 )
            goto LABEL_13;
        }
        if ( v16 )
          break;
      }
LABEL_13:
      v12 >>= 1;
      if ( v14 < v11 )
        goto LABEL_3;
    }
    v17 = *(_DWORD *)(v13 + 12);
    *(_WORD *)(v13 + 22) = v12;
    v18 = v17 & 0xFFFFFFFE;
    *(_DWORD *)(v13 + 12) = v18;
    *(_BYTE *)(v13 + 27) = *((_BYTE *)v16 + 10);
    *(_WORD *)(v13 + 28) = v16[6];
    *(_DWORD *)(v13 + 16) = *((unsigned __int8 *)v16 + 6);
    v19 = *((_BYTE *)v16 + 7);
    *(_DWORD *)(v13 + 8) = 3;
    *(_BYTE *)(v13 + 24) = v19;
    v20 = v16[4];
    if ( (v20 & 2) != 0 )
    {
      v18 |= 2u;
      *(_DWORD *)(v13 + 8) = 2;
      *(_DWORD *)(v13 + 12) = v18;
      v20 = v16[4];
      if ( (v20 & 8) == 0 )
      {
LABEL_22:
        if ( (v20 & 0x200) == 0 )
          goto LABEL_23;
        goto LABEL_32;
      }
    }
    else if ( (v20 & 8) == 0 )
    {
      goto LABEL_22;
    }
    v18 |= 8u;
    *(_DWORD *)(v13 + 8) = 2;
    *(_DWORD *)(v13 + 12) = v18;
    v20 = v16[4];
    if ( (v20 & 0x200) == 0 )
    {
LABEL_23:
      if ( (v20 & 0x40) == 0 )
      {
LABEL_25:
        v12 = (unsigned __int16)v12;
        *(_WORD *)(v13 + 20) = v11;
        if ( (unsigned __int16)v12 == 20 )
        {
          v12 = v16[2];
          *(_WORD *)(v13 + 22) = v12;
        }
        if ( !(_DWORD)result && v12 <= 0x13 )
        {
          *(_DWORD *)(v13 + 8) = 0;
          *(_DWORD *)(v13 + 12) = v18 | 1;
        }
        goto LABEL_3;
      }
LABEL_24:
      v18 |= 0x40u;
      *(_DWORD *)(v13 + 12) = v18;
      goto LABEL_25;
    }
LABEL_32:
    v18 |= 0x200u;
    *(_DWORD *)(v13 + 12) = v18;
    if ( (v16[4] & 0x40) == 0 )
      goto LABEL_25;
    goto LABEL_24;
  }
  return result;
}
