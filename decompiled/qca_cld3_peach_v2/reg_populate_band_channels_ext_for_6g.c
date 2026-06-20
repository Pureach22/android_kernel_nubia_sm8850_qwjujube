unsigned __int16 *__fastcall reg_populate_band_channels_ext_for_6g(
        unsigned __int16 *result,
        int a2,
        unsigned __int16 a3,
        __int64 a4)
{
  __int64 v4; // x8
  unsigned int v5; // w11
  __int64 v6; // x16
  int v7; // w5
  unsigned int v8; // w16
  unsigned int v9; // w2
  __int64 v10; // x17
  unsigned int v11; // w5
  int v12; // w19
  unsigned __int16 *v13; // x4
  unsigned int v14; // w5
  char v15; // w6
  unsigned __int16 v16; // w6

  v4 = 0;
  v5 = a3;
  do
  {
    v6 = channel_map + 12 * (v4 + 42);
    v7 = *(unsigned __int8 *)(v6 + 4);
    if ( *(unsigned __int16 *)(v6 + 6) <= v5 )
      v8 = v5;
    else
      v8 = *(unsigned __int16 *)(v6 + 6);
    if ( v7 )
    {
      v9 = *(unsigned __int16 *)(channel_map + 12 * (v4 + 42) + 8) >= 0x14u
         ? 20
         : *(unsigned __int16 *)(channel_map + 12 * (v4 + 42) + 8);
      if ( v9 >= v8 )
      {
        v10 = a4 + 36 * v4;
        while ( 1 )
        {
          v11 = v9 >> 1;
          if ( a2 )
          {
            v12 = a2;
            v13 = result;
            while ( *(_DWORD *)v10 - v11 < *v13 || *(_DWORD *)v10 + v11 > v13[1] )
            {
              --v12;
              v13 += 7;
              if ( !v12 )
                goto LABEL_12;
            }
            if ( v13 )
              break;
          }
LABEL_12:
          v9 >>= 1;
          if ( v11 < v8 )
            goto LABEL_2;
        }
        v14 = *(_DWORD *)(v10 + 12) & 0xFFFFFFFE;
        *(_DWORD *)(v10 + 12) = v14;
        *(_WORD *)(a4 + 36 * v4 + 22) = v9;
        *(_BYTE *)(v10 + 27) = *((_BYTE *)v13 + 10);
        *(_WORD *)(v10 + 28) = v13[6];
        *(_DWORD *)(v10 + 16) = *((unsigned __int8 *)v13 + 6);
        v15 = *((_BYTE *)v13 + 7);
        *(_DWORD *)(v10 + 8) = 3;
        *(_BYTE *)(v10 + 24) = v15;
        v16 = v13[4];
        if ( (v16 & 2) != 0 )
        {
          v14 |= 2u;
          *(_DWORD *)(v10 + 8) = 2;
          *(_DWORD *)(v10 + 12) = v14;
          v16 = v13[4];
          if ( (v16 & 8) == 0 )
          {
LABEL_21:
            if ( (v16 & 0x200) == 0 )
              goto LABEL_22;
            goto LABEL_28;
          }
        }
        else if ( (v16 & 8) == 0 )
        {
          goto LABEL_21;
        }
        v14 |= 8u;
        *(_DWORD *)(v10 + 8) = 2;
        *(_DWORD *)(v10 + 12) = v14;
        v16 = v13[4];
        if ( (v16 & 0x200) == 0 )
        {
LABEL_22:
          if ( (v16 & 0x40) == 0 )
            goto LABEL_24;
          goto LABEL_23;
        }
LABEL_28:
        v14 |= 0x200u;
        *(_DWORD *)(v10 + 12) = v14;
        if ( (v13[4] & 0x40) == 0 )
        {
LABEL_24:
          *(_WORD *)(v10 + 20) = v8;
          if ( (unsigned __int16)v9 == 20 )
            *(_WORD *)(v10 + 22) = v13[2];
          goto LABEL_2;
        }
LABEL_23:
        *(_DWORD *)(v10 + 12) = v14 | 0x40;
        goto LABEL_24;
      }
    }
LABEL_2:
    ++v4;
  }
  while ( v4 != 60 );
  return result;
}
