unsigned __int16 *__fastcall tkip_mixing_phase2(unsigned __int16 *result, unsigned __int16 *a2, int a3, __int64 a4)
{
  int v4; // w9
  int v5; // w8
  unsigned int v6; // w12
  int v7; // w10
  unsigned int v8; // w12
  unsigned int v9; // w14
  int v10; // w13
  unsigned int v11; // w14
  int v12; // w9
  int v13; // w8
  int v14; // w11
  int v15; // w15
  int v16; // w10
  unsigned int v17; // w11
  int v18; // w12
  unsigned int v19; // w13
  int v20; // w9
  unsigned int v21; // w15
  int v22; // w8

  v4 = a2[4];
  v5 = v4 + a3;
  v6 = bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(*result ^ (v4 + a3)) >> 8)]);
  v7 = (tkip_sbox[(unsigned __int8)(*result ^ (v4 + a3))] ^ HIWORD(v6)) + *a2;
  v8 = (tkip_sbox[(unsigned __int8)(((tkip_sbox[(unsigned __int8)(*result ^ (v4 + a3))] ^ BYTE2(v6)) + *a2) ^ result[1])]
      ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v7 ^ result[1]) >> 8)]) >> 16))
     + a2[1];
  v9 = bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v8 ^ result[2]) >> 8)]);
  v10 = (tkip_sbox[(unsigned __int8)(v8 ^ result[2])] ^ HIWORD(v9)) + a2[2];
  v11 = (tkip_sbox[(unsigned __int8)(((tkip_sbox[(unsigned __int8)(v8 ^ result[2])] ^ BYTE2(v9)) + a2[2]) ^ result[3])]
       ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v10 ^ result[3]) >> 8)]) >> 16))
      + a2[3];
  v12 = (tkip_sbox[(unsigned __int8)(v11 ^ result[4])]
       ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v11 ^ result[4]) >> 8)]) >> 16))
      + v4;
  v13 = (tkip_sbox[(unsigned __int8)(v12 ^ result[5])]
       ^ (bswap32(tkip_sbox[(unsigned __int8)((unsigned __int16)(v12 ^ result[5]) >> 8)]) >> 16))
      + v5;
  v14 = ((unsigned __int16)(v13 ^ result[6]) >> 1) | ((v13 ^ result[6]) << 15);
  v15 = result[7];
  *(_BYTE *)(a4 + 2) = a3;
  v16 = v14 + v7;
  v17 = (((unsigned __int16)(v16 ^ v15) >> 1) | ((v16 ^ v15) << 15)) + v8;
  *(_BYTE *)a4 = BYTE1(a3);
  v18 = (((unsigned __int16)v17 >> 1) | (v17 << 15)) + v10;
  v19 = (((unsigned __int16)((((unsigned __int16)v17 >> 1) | ((_WORD)v17 << 15)) + v10) >> 1) | (v18 << 15)) + v11;
  v20 = (((unsigned __int16)v19 >> 1) | (v19 << 15)) + v12;
  *(_BYTE *)(a4 + 1) = BYTE1(a3) & 0x5F | 0x20;
  v21 = *result;
  *(_WORD *)(a4 + 4) = v16;
  *(_WORD *)(a4 + 6) = v17;
  v22 = (((unsigned __int16)v20 >> 1) | (v20 << 15)) + v13;
  *(_WORD *)(a4 + 8) = v18;
  *(_WORD *)(a4 + 10) = v19;
  *(_WORD *)(a4 + 12) = v20;
  *(_WORD *)(a4 + 14) = v22;
  *(_BYTE *)(a4 + 3) = (v22 ^ v21) >> 1;
  return result;
}
