__int64 __fastcall setup_cipher_des_cmdlistptrs(__int64 result, __int64 a2, __int64 *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x10
  __int64 v6; // x11
  __int64 v7; // x13
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x8
  __int64 v12; // x14
  __int64 v13; // x8
  __int64 v14; // x11
  int v15; // w12
  int v16; // w15
  int v17; // w12
  int v18; // w14
  int v19; // w15
  int v20; // w16
  int v21; // w16
  bool v22; // zf
  _QWORD *v23; // x15
  _QWORD *v24; // x11
  __int64 v25; // x12
  int v26; // w13
  int v27; // w14
  int v28; // w13
  int v29; // w14
  __int64 v30; // x14
  int v31; // w14
  int v32; // w15
  int v33; // w14
  int v34; // w15
  int v35; // w14
  int v36; // w15
  __int64 v37; // x12
  __int64 v38; // x13
  int v39; // w13
  int v40; // w15
  int v41; // w12
  int v42; // w12
  int v43; // w14

  if ( (unsigned int)a2 >= 9 )
  {
    __break(0x5512u);
    return setup_auth_cmdlistptrs(result, a2, a3, a4, a5);
  }
  v5 = *(int *)(result + 400);
  v6 = 1568;
  v7 = 196;
  if ( (a5 & 1) != 0 )
    v6 = 1344;
  v8 = *a3 + v5;
  if ( (a5 & 1) == 0 )
    v7 = 200;
  v9 = 2016;
  v10 = -v5;
  v11 = v8 - 1;
  if ( (a5 & 1) != 0 )
    v9 = 1792;
  v12 = 208;
  v13 = v11 & v10;
  if ( (a5 & 1) != 0 )
    v12 = 204;
  *a3 = v13;
  if ( !(_DWORD)a4 )
  {
    v9 = v6;
    v12 = v7;
  }
  v14 = result + 7432LL * (unsigned int)a2 + v9;
  v15 = *(_DWORD *)(result + 88);
  *(_QWORD *)(v14 + 2720) = v13;
  v16 = *(_DWORD *)(result + 70256) & (v15 + 106752);
  v17 = *(_DWORD *)(result + v12);
  *(_QWORD *)(v13 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v13 + 12) = 0;
  *(_DWORD *)v13 = v16 & 0xFFFFFF;
  v18 = *(_DWORD *)(result + 88);
  v19 = *(_DWORD *)(result + 70256);
  v20 = *(_DWORD *)(result + 148);
  *(_QWORD *)(v13 + 24) = 0xFFFFFFFFLL;
  *(_DWORD *)(v13 + 20) = v20;
  v21 = v19 & (v18 + 107520) & 0xFFFFFF;
  v23 = (_QWORD *)(v14 + 2728);
  v22 = v14 == -2728;
  v24 = (_QWORD *)(v14 + 2720);
  *(_DWORD *)(v13 + 16) = v21;
  if ( !v22 )
    *v23 = v13 + 16;
  *(_DWORD *)(v13 + 32) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106768) & 0xFFFFFF;
  *(_QWORD *)(v13 + 36) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v13 + 44) = 0;
  if ( v24 != (_QWORD *)-200LL )
    v24[25] = v13 + 32;
  *(_DWORD *)(v13 + 48) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107008) & 0xFFFFFF;
  *(_DWORD *)(v13 + 52) = v17;
  *(_QWORD *)(v13 + 56) = 0xFFFFFFFFLL;
  if ( v24 != (_QWORD *)-24LL )
    v24[3] = v13 + 48;
  *(_DWORD *)(v13 + 64) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107012) & 0xFFFFFF;
  *(_QWORD *)(v13 + 68) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v13 + 76) = 0;
  if ( v24 != (_QWORD *)-32LL )
    v24[4] = v13 + 64;
  *(_DWORD *)(v13 + 80) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107016) & 0xFFFFFF;
  *(_QWORD *)(v13 + 84) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v13 + 92) = 0;
  if ( v24 != (_QWORD *)-40LL )
    v24[5] = v13 + 80;
  *(_DWORD *)(v13 + 96) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107264) & 0xFFFFFF;
  *(_QWORD *)(v13 + 100) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v13 + 108) = 0;
  if ( v24 != (_QWORD *)-144LL )
    v24[18] = v13 + 96;
  v25 = v13 + 112;
  if ( *(_BYTE *)(result + 73) == 1 )
  {
    v26 = *(_DWORD *)(result + 88);
    v27 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v13 + 116) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v13 + 124) = 0;
    *(_DWORD *)(v13 + 112) = v27 & (v26 + 107524) & 0xFFFFFF;
    if ( v24 != (_QWORD *)-120LL )
      v24[15] = v25;
    v25 = v13 + 128;
  }
  v28 = *(_DWORD *)(result + 88);
  v29 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v25 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v25 + 12) = 0;
  *(_DWORD *)v25 = v29 & (v28 + 118784) & 0xFFFFFF;
  if ( v24 != (_QWORD *)-48LL )
    v24[6] = v25;
  *(_DWORD *)(v25 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 118788) & 0xFFFFFF;
  v30 = v25 + 16;
  *(_QWORD *)(v25 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v25 + 28) = 0;
  if ( (_DWORD)a4 )
  {
    v31 = *(_DWORD *)(result + 88);
    v32 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v25 + 44) = 0;
    *(_QWORD *)(v25 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v25 + 32) = v32 & (v31 + 118792) & 0xFFFFFF;
    v33 = *(_DWORD *)(result + 88);
    v34 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v25 + 52) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v25 + 60) = 0;
    *(_DWORD *)(v25 + 48) = v34 & (v33 + 118796) & 0xFFFFFF;
    v35 = *(_DWORD *)(result + 88);
    v36 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v25 + 68) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v25 + 76) = 0;
    *(_DWORD *)(v25 + 64) = v36 & (v35 + 118800) & 0xFFFFFF;
    *(_DWORD *)(v25 + 80) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 118804) & 0xFFFFFF;
    v37 = v25 + 80;
    v38 = v37 + 16;
    v30 = v37;
    *(_QWORD *)(v37 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v37 + 12) = 0;
    if ( (a5 & 1) == 0 )
      goto LABEL_37;
LABEL_34:
    *(_DWORD *)v38 = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107020) & 0xFFFFFF;
    *(_QWORD *)(v30 + 20) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v30 + 28) = 0;
    if ( v24 != (_QWORD *)-64LL )
      v24[8] = v38;
    v39 = *(_DWORD *)(result + 88);
    v40 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v30 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v30 + 44) = 0;
    v41 = v40 & (v39 + 107024) & 0xFFFFFF;
    v38 = v30 + 48;
    *(_DWORD *)(v30 + 32) = v41;
    goto LABEL_37;
  }
  v38 = v25 + 32;
  if ( (a5 & 1) != 0 )
    goto LABEL_34;
LABEL_37:
  v42 = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520);
  v43 = *(_DWORD *)(result + 152);
  *(_QWORD *)(v38 + 8) = 0xFFFFFFFFLL;
  *(_DWORD *)v38 = v42 & 0xFFFFFF;
  *(_DWORD *)(v38 + 4) = v43;
  if ( v24 != (_QWORD *)-16LL )
    v24[2] = v38;
  *(_DWORD *)(v38 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106784) & 0xFFFFFF;
  *(_QWORD *)(v38 + 20) = 0xFFFFFFFF00000007LL;
  *(_DWORD *)(v38 + 28) = 0;
  if ( v24 != (_QWORD *)-208LL )
    v24[26] = v38 + 16;
  v24[27] = v38 + 32 - v13;
  *a3 = v38 + 32;
  return result;
}
