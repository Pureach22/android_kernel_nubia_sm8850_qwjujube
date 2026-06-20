__int64 __fastcall tkip_mixing_phase1(__int64 result, __int64 a2, unsigned __int16 *a3, unsigned int a4)
{
  unsigned int v4; // w12
  int v5; // w8
  int v6; // w10
  int v7; // w9
  int v8; // w11
  int v9; // w14
  unsigned int v10; // w2
  __int64 v11; // x4
  __int16 v12; // w5
  int v13; // w14

  *(_DWORD *)a2 = a4;
  v4 = HIWORD(a4);
  v5 = 0;
  v6 = *a3;
  v7 = 0;
  *(_WORD *)(a2 + 4) = v6;
  v8 = a3[1];
  *(_WORD *)(a2 + 6) = v8;
  v9 = a3[2];
  v10 = a4;
  *(_WORD *)(a2 + 8) = v9;
  do
  {
    v11 = v5 & 2;
    v5 += 2;
    v12 = *(_WORD *)(result + v11) ^ v9;
    v13 = v9 + v7++;
    v10 += tkip_sbox[(unsigned __int8)v12] ^ (bswap32(tkip_sbox[HIBYTE(v12)]) >> 16);
    *(_WORD *)a2 = v10;
    v4 += tkip_sbox[(unsigned __int8)(v10 ^ *(_WORD *)(result + 4 + v11))]
        ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v10 ^ *(_WORD *)(result + 4 + v11)) >> 8)]) >> 16);
    *(_WORD *)(a2 + 2) = v4;
    v6 += tkip_sbox[(unsigned __int8)(v4 ^ *(_WORD *)(result + 8 + v11))]
        ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v4 ^ *(_WORD *)(result + 8 + v11)) >> 8)]) >> 16);
    *(_WORD *)(a2 + 4) = v6;
    v8 += tkip_sbox[(unsigned __int8)(v6 ^ *(_WORD *)(result + 12 + v11))]
        ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v6 ^ *(_WORD *)(result + 12 + v11)) >> 8)]) >> 16);
    *(_WORD *)(a2 + 6) = v8;
    v9 = v13
       + (tkip_sbox[(unsigned __int8)(v8 ^ *(_BYTE *)(result + v11))]
        ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v8 ^ *(_WORD *)(result + v11)) >> 8)]) >> 16));
    *(_WORD *)(a2 + 8) = v9;
  }
  while ( v7 != 8 );
  *(_DWORD *)(a2 + 12) = a4;
  *(_DWORD *)(a2 + 16) = 1;
  return result;
}
