__int64 __fastcall setup_aead_cmdlistptrs(
        __int64 result,
        __int64 a2,
        __int64 *a3,
        __int64 a4,
        unsigned int a5,
        char a6)
{
  __int64 v6; // x8
  __int64 v7; // x10
  char v8; // w14
  __int64 v9; // x12
  __int64 *v10; // x9
  int v11; // w13
  int v12; // w15
  int v13; // w12
  int v14; // w16
  __int64 v15; // x16
  int v16; // w13
  int v17; // w15
  int v18; // w13
  int v19; // w15
  __int64 v20; // x13
  int v21; // w17
  int v22; // w16
  int v23; // w3
  int v24; // w4
  int v25; // w3
  __int64 v26; // x13
  __int64 v27; // x17
  int v28; // w13
  int v29; // w14
  int v30; // w1
  __int64 v31; // x14
  int v32; // w1
  int v33; // w3
  int v34; // w4
  __int64 v35; // x6
  __int64 v36; // x16
  __int64 v37; // x1
  int v38; // w1
  int v39; // w3
  __int64 v40; // x16
  int v41; // w16
  int v42; // w3
  int v43; // w4
  int v44; // w1
  __int64 v45; // x3
  __int64 v46; // x15
  __int64 v47; // x16
  __int64 v48; // x15
  __int64 v49; // x12
  __int64 v50; // x16
  __int64 v51; // x12
  __int64 v52; // x15
  int v53; // w17
  __int64 v54; // x12
  __int64 v55; // x16
  __int64 v56; // x12
  int v57; // w17
  __int64 v58; // x12
  __int64 v59; // x15
  __int64 v60; // x12

  if ( (unsigned int)a2 >= 9 )
  {
    __break(0x5512u);
    return setup_aead_ccm_cmdlistptrs(result, a2, a3, a4);
  }
  v6 = (*a3 + *(int *)(result + 400) - 1) & -(__int64)*(int *)(result + 400);
  *a3 = v6;
  if ( (_DWORD)a4 == 2 )
  {
    if ( a5 == 32 )
    {
      v7 = 4704;
      if ( (a6 & 1) != 0 )
        v7 = 3808;
      v8 = 0;
      v9 = 160;
    }
    else
    {
      if ( a5 != 16 )
        return result;
      v7 = 4480;
      if ( (a6 & 1) != 0 )
        v7 = 3584;
      v8 = 0;
      v9 = 156;
    }
  }
  else if ( (_DWORD)a4 == 1 )
  {
    v7 = 5152;
    if ( (a6 & 1) != 0 )
      v7 = 4256;
    v8 = 1;
    v9 = 204;
  }
  else
  {
    v7 = 4928;
    if ( (a6 & 1) != 0 )
      v7 = 4032;
    v8 = 1;
    v9 = 196;
  }
  v10 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 2720 + v7);
  v11 = *(_DWORD *)(result + 88);
  *v10 = v6;
  v12 = *(_DWORD *)(result + 70256);
  v13 = *(_DWORD *)(result + v9);
  *(_QWORD *)(v6 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v6 + 12) = 0;
  *(_DWORD *)v6 = v12 & (v11 + 106752) & 0xFFFFFF;
  v14 = *(_DWORD *)(result + 148);
  *(_DWORD *)(v6 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
  *(_DWORD *)(v6 + 20) = v14;
  *(_QWORD *)(v6 + 24) = 0xFFFFFFFFLL;
  if ( v10 != (__int64 *)-8LL )
    v10[1] = v6 + 16;
  v15 = v6 + 32;
  if ( *(_BYTE *)(result + 73) == 1 )
  {
    v16 = *(_DWORD *)(result + 88);
    v17 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v6 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v6 + 44) = 0;
    *(_DWORD *)(v6 + 32) = v17 & (v16 + 107524) & 0xFFFFFF;
    if ( v10 != (__int64 *)-120LL )
      v10[15] = v15;
    v15 = v6 + 48;
  }
  v18 = *(_DWORD *)(result + 88);
  v19 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v15 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v15 + 12) = 0;
  *(_DWORD *)v15 = v19 & (v18 + 118784) & 0xFFFFFF;
  if ( v10 != (__int64 *)-48LL )
    v10[6] = v15;
  v20 = v15 + 16;
  if ( a5 >= 8 )
  {
    v21 = 118788;
    v22 = (a5 >> 2) - 1;
    do
    {
      v23 = *(_DWORD *)(result + 88);
      v24 = *(_DWORD *)(result + 70256);
      --v22;
      *(_QWORD *)(v20 + 4) = 0xFFFFFFFF00000000LL;
      v25 = v21 + v23;
      *(_DWORD *)(v20 + 12) = 0;
      v21 += 4;
      *(_DWORD *)v20 = v24 & v25 & 0xFFFFFF;
      v20 += 16;
    }
    while ( v22 );
    v15 = v20 - 16;
  }
  *(_DWORD *)v20 = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107020) & 0xFFFFFF;
  *(_QWORD *)(v15 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v15 + 28) = 0;
  if ( v10 != (__int64 *)-64LL )
    v10[8] = v20;
  *(_DWORD *)(v15 + 32) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107024) & 0xFFFFFF;
  v26 = v15 + 32;
  *(_QWORD *)(v15 + 36) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v15 + 44) = 0;
  if ( (v8 & 1) != 0 )
  {
    v27 = v15 + 48;
  }
  else
  {
    v28 = *(_DWORD *)(result + 88);
    v29 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v15 + 60) = 0;
    *(_QWORD *)(v15 + 52) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v15 + 48) = v29 & (v28 + 107028) & 0xFFFFFF;
    *(_DWORD *)(v15 + 64) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107032) & 0xFFFFFF;
    v26 = v15 + 64;
    *(_QWORD *)(v15 + 68) = 0xFFFFFFFF00000000LL;
    v27 = v15 + 80;
    *(_DWORD *)(v15 + 76) = 0;
  }
  if ( (a6 & 1) != 0 )
    v30 = 5;
  else
    v30 = 8;
  *(_DWORD *)v27 = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107280) & 0xFFFFFF;
  *(_QWORD *)(v26 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v26 + 28) = 0;
  if ( v10 != (__int64 *)-176LL )
    v10[22] = v27;
  v31 = 0;
  v32 = v30 - 1;
  v33 = 107284;
  do
  {
    --v32;
    v34 = v33 + *(_DWORD *)(result + 88);
    v33 += 4;
    v35 = v26 + v31;
    v31 += 16;
    *(_DWORD *)(v35 + 32) = *(_DWORD *)(result + 70256) & v34 & 0xFFFFFF;
    *(_QWORD *)(v27 + 20) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v27 + 28) = 0;
    v27 = v35 + 32;
  }
  while ( v32 );
  v36 = v26 + v31;
  *(_DWORD *)(v26 + v31 + 32) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107408) & 0xFFFFFF;
  v37 = v26 + v31 + 32;
  *(_QWORD *)(v37 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v37 + 12) = 0;
  if ( v10 != (__int64 *)-192LL )
    v10[24] = v37;
  v38 = *(_DWORD *)(result + 88);
  v39 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v36 + 52) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v36 + 60) = 0;
  *(_DWORD *)(v36 + 48) = v39 & (v38 + 107412) & 0xFFFFFF;
  *(_DWORD *)(v36 + 64) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 118848) & 0xFFFFFF;
  v40 = v36 + 64;
  *(_QWORD *)(v40 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v40 + 12) = 0;
  if ( v10 != (__int64 *)-168LL )
    v10[21] = v40;
  v41 = 0;
  do
  {
    v42 = v41 + 118784;
    v43 = *(_DWORD *)(result + 70256);
    v41 += 4;
    v44 = v42 + *(_DWORD *)(result + 88);
    v45 = v26 + v31;
    v31 += 16;
    *(_QWORD *)(v45 + 84) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v45 + 92) = 0;
    *(_DWORD *)(v45 + 80) = v43 & (v44 + 68) & 0xFFFFFF;
  }
  while ( v41 != 60 );
  v46 = v26 + v31;
  *(_DWORD *)(v26 + v31 + 80) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106768) & 0xFFFFFF;
  v47 = v26 + v31 + 80;
  *(_QWORD *)(v47 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v47 + 12) = 0;
  if ( v10 != (__int64 *)-200LL )
    v10[25] = v47;
  *(_DWORD *)(v46 + 96) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107008) & 0xFFFFFF;
  *(_DWORD *)(v46 + 100) = v13;
  v48 = v46 + 96;
  *(_QWORD *)(v48 + 8) = 0xFFFFFFFFLL;
  if ( v10 != (__int64 *)-24LL )
    v10[3] = v48;
  v49 = v26 + v31;
  *(_DWORD *)(v26 + v31 + 112) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107012) & 0xFFFFFF;
  v50 = v26 + v31 + 112;
  *(_QWORD *)(v50 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v50 + 12) = 0;
  if ( v10 != (__int64 *)-32LL )
    v10[4] = v50;
  *(_DWORD *)(v49 + 128) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107016) & 0xFFFFFF;
  v51 = v49 + 128;
  *(_QWORD *)(v51 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v51 + 12) = 0;
  if ( v10 != (__int64 *)-40LL )
    v10[5] = v51;
  v52 = v26 + v31;
  if ( (a6 & 1) != 0 )
    v53 = *(_DWORD *)(result + 252);
  else
    v53 = *(_DWORD *)(result + 256);
  *(_DWORD *)(v52 + 144) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107264) & 0xFFFFFF;
  *(_DWORD *)(v52 + 148) = v53;
  *(_QWORD *)(v52 + 152) = 0xFFFFFFFFLL;
  if ( v10 != (__int64 *)-144LL )
    v10[18] = v52 + 144;
  v54 = v26 + v31;
  *(_DWORD *)(v26 + v31 + 160) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107268) & 0xFFFFFF;
  v55 = v26 + v31 + 160;
  *(_QWORD *)(v55 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v55 + 12) = 0;
  if ( v10 != (__int64 *)-152LL )
    v10[19] = v55;
  *(_DWORD *)(v54 + 176) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107272) & 0xFFFFFF;
  v56 = v54 + 176;
  *(_QWORD *)(v56 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v56 + 12) = 0;
  if ( v10 != (__int64 *)-160LL )
    v10[20] = v56;
  v57 = *(_DWORD *)(result + 152);
  v58 = v26 + v31;
  v59 = v26 + v31;
  *(_DWORD *)(v59 + 192) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
  *(_DWORD *)(v59 + 196) = v57;
  *(_QWORD *)(v26 + v31 + 200) = 0xFFFFFFFFLL;
  if ( v10 != (__int64 *)-16LL )
    v10[2] = v26 + v31 + 192;
  *(_DWORD *)(v58 + 208) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106784) & 0xFFFFFF;
  v60 = v58 + 208;
  *(_QWORD *)(v60 + 4) = 0xFFFFFFFF00000007LL;
  *(_DWORD *)(v60 + 12) = 0;
  if ( v10 != (__int64 *)-208LL )
    v10[26] = v60;
  v10[27] = v26 - v6 + v31 + 224;
  *a3 = v26 + v31 + 224;
  return result;
}
