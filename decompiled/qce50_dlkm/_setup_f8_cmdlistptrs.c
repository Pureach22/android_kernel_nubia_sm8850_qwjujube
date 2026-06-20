_DWORD *__fastcall setup_f8_cmdlistptrs(_DWORD *result, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 v4; // x9
  _DWORD *v5; // x11
  __int64 v6; // x10
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x8
  int v11; // w13
  __int64 v12; // x12
  int v13; // w15
  int v14; // w12
  int v15; // w17
  _QWORD *v16; // x14
  _QWORD *v17; // x11
  int v18; // w15
  int v19; // w12
  int v20; // w14
  int v21; // w14
  int v22; // w15
  int v23; // w14
  int v24; // w15
  int v25; // w13
  int v26; // w14
  int v27; // w14
  int v28; // w12
  int v29; // w10

  if ( (unsigned int)a2 >= 9 )
  {
    __break(0x5512u);
    return (_DWORD *)setup_f9_cmdlistptrs(result, a2, a3, a4);
  }
  else
  {
    v4 = (int)result[100];
    v5 = &result[1858 * (unsigned int)a2];
    v6 = 1568;
    v7 = *a3 + v4;
    v8 = -v4;
    v9 = v7 - 1;
    if ( !(_DWORD)a4 )
      v6 = 1512;
    v10 = v9 & v8;
    *a3 = v10;
    v11 = result[22];
    *(_QWORD *)&v5[v6 + 680] = v10;
    v12 = 53;
    v13 = result[17564];
    if ( (_DWORD)a4 )
      v12 = 54;
    v14 = result[v12];
    *(_QWORD *)(v10 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 12) = 0;
    *(_DWORD *)v10 = v13 & (v11 + 106752) & 0xFFFFFF;
    v15 = result[17564];
    v16 = v5 + 2248;
    v17 = v5 + 2192;
    v18 = result[22] + 107520;
    if ( (_DWORD)a4 )
      v17 = v16;
    *(_DWORD *)(v10 + 20) = result[37];
    *(_QWORD *)(v10 + 24) = 0xFFFFFFFFLL;
    *(_DWORD *)(v10 + 16) = v15 & v18 & 0xFFFFFF;
    if ( v17 != (_QWORD *)-8LL )
      v17[1] = v10 + 16;
    *(_DWORD *)(v10 + 32) = result[17564] & (result[22] + 106768) & 0xFFFFFF;
    *(_QWORD *)(v10 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 44) = 0;
    if ( v17 != (_QWORD *)-200LL )
      v17[25] = v10 + 32;
    *(_DWORD *)(v10 + 48) = result[17564] & (result[22] + 107008) & 0xFFFFFF;
    *(_DWORD *)(v10 + 52) = v14;
    *(_QWORD *)(v10 + 56) = 0xFFFFFFFFLL;
    if ( v17 != (_QWORD *)-24LL )
      v17[3] = v10 + 48;
    *(_DWORD *)(v10 + 64) = result[17564] & (result[22] + 107012) & 0xFFFFFF;
    *(_QWORD *)(v10 + 68) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 76) = 0;
    if ( v17 != (_QWORD *)-32LL )
      v17[4] = v10 + 64;
    *(_DWORD *)(v10 + 80) = result[17564] & (result[22] + 107016) & 0xFFFFFF;
    *(_QWORD *)(v10 + 84) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 92) = 0;
    if ( v17 != (_QWORD *)-40LL )
      v17[5] = v10 + 80;
    *(_DWORD *)(v10 + 96) = result[17564] & (result[22] + 107264) & 0xFFFFFF;
    *(_QWORD *)(v10 + 100) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 108) = 0;
    if ( v17 != (_QWORD *)-144LL )
      v17[18] = v10 + 96;
    *(_DWORD *)(v10 + 112) = result[17564] & (result[22] + 107268) & 0xFFFFFF;
    *(_QWORD *)(v10 + 116) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 124) = 0;
    if ( v17 != (_QWORD *)-152LL )
      v17[19] = v10 + 112;
    *(_DWORD *)(v10 + 128) = result[17564] & (result[22] + 107272) & 0xFFFFFF;
    *(_QWORD *)(v10 + 132) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 140) = 0;
    if ( v17 != (_QWORD *)-160LL )
      v17[20] = v10 + 128;
    *(_DWORD *)(v10 + 144) = result[17564] & (result[22] + 118784) & 0xFFFFFF;
    *(_QWORD *)(v10 + 148) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 156) = 0;
    if ( v17 != (_QWORD *)-48LL )
      v17[6] = v10 + 144;
    v19 = result[22];
    v20 = result[17564];
    *(_DWORD *)(v10 + 172) = 0;
    *(_QWORD *)(v10 + 164) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 160) = v20 & (v19 + 118788) & 0xFFFFFF;
    v21 = result[22];
    v22 = result[17564];
    *(_QWORD *)(v10 + 180) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 188) = 0;
    *(_DWORD *)(v10 + 176) = v22 & (v21 + 118792) & 0xFFFFFF;
    v23 = result[22];
    v24 = result[17564];
    *(_QWORD *)(v10 + 196) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 204) = 0;
    *(_DWORD *)(v10 + 192) = v24 & (v23 + 118796) & 0xFFFFFF;
    *(_DWORD *)(v10 + 208) = result[17564] & (result[22] + 107020) & 0xFFFFFF;
    *(_QWORD *)(v10 + 212) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 220) = 0;
    if ( v17 != (_QWORD *)-64LL )
      v17[8] = v10 + 208;
    v25 = result[22];
    v26 = result[17564];
    *(_QWORD *)(v10 + 228) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v10 + 236) = 0;
    *(_DWORD *)(v10 + 224) = v26 & (v25 + 107024) & 0xFFFFFF;
    v27 = result[38];
    *(_DWORD *)(v10 + 240) = result[17564] & (result[22] + 107520) & 0xFFFFFF;
    *(_DWORD *)(v10 + 244) = v27;
    *(_QWORD *)(v10 + 248) = 0xFFFFFFFFLL;
    if ( v17 != (_QWORD *)-16LL )
      v17[2] = v10 + 240;
    v28 = result[22];
    v29 = result[17564];
    *(_DWORD *)(v10 + 268) = 0;
    *(_QWORD *)(v10 + 260) = 0xFFFFFFFF00000007LL;
    *(_DWORD *)(v10 + 256) = v29 & (v28 + 106784) & 0xFFFFFF;
    if ( v17 != (_QWORD *)-208LL )
      v17[26] = v10 + 256;
    v17[27] = 272;
    *a3 = v10 + 272;
  }
  return result;
}
