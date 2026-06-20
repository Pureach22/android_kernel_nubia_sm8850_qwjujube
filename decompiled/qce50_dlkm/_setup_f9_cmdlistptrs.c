_DWORD *__fastcall setup_f9_cmdlistptrs(_DWORD *result, unsigned int a2, __int64 *a3, int a4)
{
  __int64 v4; // x20
  __int64 v5; // x9
  _DWORD *v6; // x11
  __int64 v7; // x10
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w13
  __int64 v13; // x12
  int v14; // w16
  int v15; // w13
  int v16; // w15
  int v17; // w13
  int v18; // w15
  int v19; // w17
  _QWORD *v20; // x12
  _QWORD *v21; // x11
  int v22; // w16
  int v23; // w15
  int v24; // w14
  int v25; // w15
  int v26; // w14
  int v27; // w15
  int v28; // w14
  int v29; // w15
  int v30; // w14
  int v31; // w15
  int v32; // w13
  int v33; // w14
  int v34; // w15

  if ( a2 >= 9 )
  {
    __break(0x5512u);
    if ( v4 )
      JUMPOUT(0xD233C);
    return (_DWORD *)qce_recovery_complete();
  }
  else
  {
    v5 = (int)result[100];
    v6 = &result[1858 * a2];
    v7 = 1680;
    v8 = *a3 + v5;
    v9 = -v5;
    v10 = v8 - 1;
    if ( !a4 )
      v7 = 1624;
    v11 = v10 & v9;
    *a3 = v11;
    v12 = result[22];
    *(_QWORD *)&v6[v7 + 680] = v11;
    v13 = 65;
    v14 = result[17564];
    v15 = v12 + 107520;
    if ( a4 )
      v13 = 66;
    v16 = v15 - 768;
    v17 = result[v13];
    *(_QWORD *)(v11 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 12) = 0;
    *(_DWORD *)v11 = v14 & v16 & 0xFFFFFF;
    v18 = result[22];
    v19 = result[17564];
    v20 = v6 + 2360;
    v21 = v6 + 2304;
    v22 = result[37];
    *(_QWORD *)(v11 + 24) = 0xFFFFFFFFLL;
    v23 = v18 + 107520;
    if ( a4 )
      v21 = v20;
    *(_DWORD *)(v11 + 20) = v22;
    *(_DWORD *)(v11 + 16) = v19 & v23 & 0xFFFFFF;
    if ( v21 != (_QWORD *)-8LL )
      v21[1] = v11 + 16;
    *(_DWORD *)(v11 + 32) = result[17564] & (result[22] + 106768) & 0xFFFFFF;
    *(_QWORD *)(v11 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 44) = 0;
    if ( v21 != (_QWORD *)-200LL )
      v21[25] = v11 + 32;
    *(_DWORD *)(v11 + 48) = result[17564] & (result[22] + 107008) & 0xFFFFFF;
    *(_QWORD *)(v11 + 52) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 60) = 0;
    if ( v21 != (_QWORD *)-24LL )
      v21[3] = v11 + 48;
    *(_DWORD *)(v11 + 64) = result[17564] & (result[22] + 107264) & 0xFFFFFF;
    *(_DWORD *)(v11 + 68) = v17;
    *(_QWORD *)(v11 + 72) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-144LL )
      v21[18] = v11 + 64;
    *(_DWORD *)(v11 + 80) = result[17564] & (result[22] + 107268) & 0xFFFFFF;
    *(_QWORD *)(v11 + 84) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 92) = 0;
    if ( v21 != (_QWORD *)-152LL )
      v21[19] = v11 + 80;
    *(_DWORD *)(v11 + 96) = result[17564] & (result[22] + 107272) & 0xFFFFFF;
    *(_QWORD *)(v11 + 100) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 108) = 0;
    if ( v21 != (_QWORD *)-160LL )
      v21[20] = v11 + 96;
    *(_DWORD *)(v11 + 112) = result[17564] & (result[22] + 107280) & 0xFFFFFF;
    *(_QWORD *)(v11 + 116) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 124) = 0;
    if ( v21 != (_QWORD *)-176LL )
      v21[22] = v11 + 112;
    v24 = result[22];
    v25 = result[17564];
    *(_QWORD *)(v11 + 132) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 140) = 0;
    *(_DWORD *)(v11 + 128) = v25 & (v24 + 107284) & 0xFFFFFF;
    v26 = result[22];
    v27 = result[17564];
    *(_QWORD *)(v11 + 148) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 156) = 0;
    *(_DWORD *)(v11 + 144) = v27 & (v26 + 107288) & 0xFFFFFF;
    v28 = result[22];
    v29 = result[17564];
    *(_QWORD *)(v11 + 164) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 172) = 0;
    *(_DWORD *)(v11 + 160) = v29 & (v28 + 107292) & 0xFFFFFF;
    v30 = result[22];
    v31 = result[17564];
    *(_QWORD *)(v11 + 180) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 188) = 0;
    *(_DWORD *)(v11 + 176) = v31 & (v30 + 107296) & 0xFFFFFF;
    *(_DWORD *)(v11 + 192) = result[17564] & (result[22] + 107408) & 0xFFFFFF;
    *(_QWORD *)(v11 + 196) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 204) = 0;
    if ( v21 != (_QWORD *)-192LL )
      v21[24] = v11 + 192;
    v32 = result[22];
    v33 = result[17564];
    *(_DWORD *)(v11 + 220) = 0;
    *(_QWORD *)(v11 + 212) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v11 + 208) = v33 & (v32 + 107412) & 0xFFFFFF;
    v34 = result[38];
    *(_DWORD *)(v11 + 224) = result[17564] & (result[22] + 107520) & 0xFFFFFF;
    *(_DWORD *)(v11 + 228) = v34;
    *(_QWORD *)(v11 + 232) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-16LL )
      v21[2] = v11 + 224;
    *(_DWORD *)(v11 + 240) = result[17564] & (result[22] + 106784) & 0xFFFFFF;
    *(_QWORD *)(v11 + 244) = 0xFFFFFFFF00000007LL;
    *(_DWORD *)(v11 + 252) = 0;
    if ( v21 != (_QWORD *)-208LL )
      v21[26] = v11 + 240;
    v21[27] = 256;
    *a3 = v11 + 256;
  }
  return result;
}
