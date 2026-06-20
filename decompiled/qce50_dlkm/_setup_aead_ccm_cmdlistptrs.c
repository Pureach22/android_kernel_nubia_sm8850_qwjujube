__int64 __fastcall setup_aead_ccm_cmdlistptrs(__int64 result, __int64 a2, __int64 *a3, __int64 a4)
{
  __int64 v4; // x14
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  int v8; // w13
  __int64 v9; // x12
  int v10; // w16
  int v11; // w1
  int v12; // w13
  int v13; // w14
  int v14; // w17
  int v15; // w12
  int v16; // w4
  int v17; // w12
  int v18; // w3
  bool v19; // zf
  _QWORD *v20; // x17
  _QWORD *v21; // x11
  int v22; // w16
  int v23; // w17
  int v24; // w16
  int v25; // w17
  int v26; // w16
  int v27; // w16
  int v28; // w16
  int v29; // w16
  int v30; // w14
  int v31; // w15
  __int64 v32; // x13
  int v33; // w15
  int v34; // w16
  int v35; // w15
  int v36; // w16
  int v37; // w15
  int v38; // w16
  int v39; // w15
  int v40; // w16
  int v41; // w15
  int v42; // w16
  int v43; // w15
  int v44; // w16
  int v45; // w15
  int v46; // w16
  int v47; // w15
  int v48; // w16
  int v49; // w15
  int v50; // w16
  int v51; // w15
  __int64 v52; // x16
  int v53; // w17
  int v54; // w1
  int v55; // w3
  int v56; // w13
  int v57; // w14
  int v58; // w14
  __int64 v59; // x13
  int v60; // w12
  int v61; // w16
  int v62; // w1
  int v63; // w3
  int v64; // w1
  int v65; // w12
  int v66; // w16
  int v67; // w16
  int v68; // w17
  int v69; // w16
  int v70; // w17
  int v71; // w16
  int v72; // w17
  __int64 v73; // x12
  int v74; // w16
  int v75; // w17
  int v76; // w13
  int v77; // w17
  __int64 v78; // x13
  int v79; // w15
  int v80; // w17
  int v81; // w1
  __int64 v82; // x3
  int v83; // w17
  __int64 v84; // x14
  __int64 v85; // x16
  int v86; // w16
  int v87; // w17
  int v88; // w16
  int v89; // w17
  int v90; // w16
  int v91; // w17
  __int64 v92; // x14
  int v93; // w15
  __int64 v94; // x14
  int v95; // w16
  int v96; // w15
  int v97; // w16
  int v98; // w15
  int v99; // w16
  int v100; // w17
  __int64 v101; // x15
  __int64 v102; // x14

  if ( (unsigned int)a2 >= 9 )
  {
    __break(0x5512u);
    return setup_f8_cmdlistptrs(result, a2, a3, a4);
  }
  else
  {
    v4 = 248;
    v5 = (*a3 + *(int *)(result + 400) - 1) & -(__int64)*(int *)(result + 400);
    if ( (a4 & 1) != 0 )
      v6 = 5376;
    else
      v6 = 5600;
    *a3 = v5;
    v7 = result + 7432LL * (unsigned int)a2 + v6;
    v8 = *(_DWORD *)(result + 88);
    *(_QWORD *)(v7 + 2720) = v5;
    v9 = 188;
    if ( (a4 & 1) != 0 )
      v4 = 244;
    v10 = *(_DWORD *)(result + 70256);
    v11 = v8 + 107008;
    if ( (a4 & 1) == 0 )
      v9 = 192;
    v12 = *(_DWORD *)(result + v4);
    v13 = *(_DWORD *)(result + v9);
    *(_QWORD *)(v5 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 12) = 0;
    *(_DWORD *)v5 = v10 & (v11 - 256) & 0xFFFFFF;
    v14 = *(_DWORD *)(result + 70256);
    v15 = *(_DWORD *)(result + 88) + 107008;
    *(_DWORD *)(v5 + 20) = *(_DWORD *)(result + 148);
    v16 = v15 + 512;
    if ( (a4 & 1) != 0 )
      v17 = 4;
    else
      v17 = 8;
    *(_QWORD *)(v5 + 24) = 0xFFFFFFFFLL;
    v18 = v14 & v16 & 0xFFFFFF;
    v20 = (_QWORD *)(v7 + 2728);
    v19 = v7 == -2728;
    v21 = (_QWORD *)(v7 + 2720);
    *(_DWORD *)(v5 + 16) = v18;
    if ( !v19 )
      *v20 = v5 + 16;
    v22 = *(_DWORD *)(result + 88);
    v23 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 44) = 0;
    *(_DWORD *)(v5 + 32) = v23 & (v22 + 107008) & 0xFFFFFF;
    v24 = *(_DWORD *)(result + 88);
    v25 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 52) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 60) = 0;
    *(_DWORD *)(v5 + 48) = v25 & (v24 + 107016) & 0xFFFFFF;
    *(_DWORD *)(v5 + 64) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106768) & 0xFFFFFF;
    *(_QWORD *)(v5 + 68) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 76) = 0;
    if ( v21 != (_QWORD *)-200LL )
      v21[25] = v5 + 64;
    *(_DWORD *)(v5 + 80) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107008) & 0xFFFFFF;
    *(_DWORD *)(v5 + 84) = v13;
    *(_QWORD *)(v5 + 88) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-24LL )
      v21[3] = v5 + 80;
    *(_DWORD *)(v5 + 96) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107012) & 0xFFFFFF;
    *(_QWORD *)(v5 + 100) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 108) = 0;
    if ( v21 != (_QWORD *)-32LL )
      v21[4] = v5 + 96;
    *(_DWORD *)(v5 + 112) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107016) & 0xFFFFFF;
    *(_QWORD *)(v5 + 116) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 124) = 0;
    if ( v21 != (_QWORD *)-40LL )
      v21[5] = v5 + 112;
    v26 = *(_DWORD *)(result + 280);
    *(_DWORD *)(v5 + 128) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107036) & 0xFFFFFF;
    *(_DWORD *)(v5 + 132) = v26;
    *(_QWORD *)(v5 + 136) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-104LL )
      v21[13] = v5 + 128;
    v27 = *(_DWORD *)(result + 276);
    *(_DWORD *)(v5 + 144) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107068) & 0xFFFFFF;
    *(_DWORD *)(v5 + 148) = v27;
    *(_QWORD *)(v5 + 152) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-96LL )
      v21[12] = v5 + 144;
    v28 = *(_DWORD *)(result + 272);
    *(_DWORD *)(v5 + 160) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107064) & 0xFFFFFF;
    *(_DWORD *)(v5 + 164) = v28;
    *(_QWORD *)(v5 + 168) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-88LL )
      v21[11] = v5 + 160;
    v29 = *(_DWORD *)(result + 268);
    *(_DWORD *)(v5 + 176) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107060) & 0xFFFFFF;
    *(_DWORD *)(v5 + 180) = v29;
    *(_QWORD *)(v5 + 184) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-80LL )
      v21[10] = v5 + 176;
    *(_DWORD *)(v5 + 192) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107264) & 0xFFFFFF;
    *(_DWORD *)(v5 + 196) = v12;
    *(_QWORD *)(v5 + 200) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-144LL )
      v21[18] = v5 + 192;
    *(_DWORD *)(v5 + 208) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107268) & 0xFFFFFF;
    *(_QWORD *)(v5 + 212) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 220) = 0;
    if ( v21 != (_QWORD *)-152LL )
      v21[19] = v5 + 208;
    *(_DWORD *)(v5 + 224) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107272) & 0xFFFFFF;
    *(_QWORD *)(v5 + 228) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 236) = 0;
    if ( v21 != (_QWORD *)-160LL )
      v21[20] = v5 + 224;
    v30 = *(_DWORD *)(result + 88);
    v31 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v5 + 252) = 0;
    v32 = 0;
    *(_QWORD *)(v5 + 244) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 240) = v31 & (v30 + 107280) & 0xFFFFFF;
    v33 = *(_DWORD *)(result + 88);
    v34 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 260) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 268) = 0;
    *(_DWORD *)(v5 + 256) = v34 & (v33 + 107284) & 0xFFFFFF;
    v35 = *(_DWORD *)(result + 88);
    v36 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 276) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 284) = 0;
    *(_DWORD *)(v5 + 272) = v36 & (v35 + 107288) & 0xFFFFFF;
    v37 = *(_DWORD *)(result + 88);
    v38 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 292) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 300) = 0;
    *(_DWORD *)(v5 + 288) = v38 & (v37 + 107292) & 0xFFFFFF;
    v39 = *(_DWORD *)(result + 88);
    v40 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 308) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 316) = 0;
    *(_DWORD *)(v5 + 304) = v40 & (v39 + 107296) & 0xFFFFFF;
    v41 = *(_DWORD *)(result + 88);
    v42 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 324) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 332) = 0;
    *(_DWORD *)(v5 + 320) = v42 & (v41 + 107300) & 0xFFFFFF;
    v43 = *(_DWORD *)(result + 88);
    v44 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 340) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 348) = 0;
    *(_DWORD *)(v5 + 336) = v44 & (v43 + 107304) & 0xFFFFFF;
    v45 = *(_DWORD *)(result + 88);
    v46 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 356) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 364) = 0;
    *(_DWORD *)(v5 + 352) = v46 & (v45 + 107308) & 0xFFFFFF;
    v47 = *(_DWORD *)(result + 88);
    v48 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v5 + 372) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v5 + 380) = 0;
    *(_DWORD *)(v5 + 368) = v48 & (v47 + 107408) & 0xFFFFFF;
    v49 = *(_DWORD *)(result + 88);
    v50 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v5 + 396) = 0;
    v51 = v50 & (v49 + 107412);
    *(_QWORD *)(v5 + 388) = 0xFFFFFFFF00000000LL;
    v52 = v5 + 400;
    *(_DWORD *)(v5 + 384) = v51 & 0xFFFFFF;
    do
    {
      v53 = *(_DWORD *)(result + 88);
      v54 = v32 + 118848;
      v55 = *(_DWORD *)(result + 70256);
      v32 += 4;
      *(_QWORD *)(v52 + 4) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v52 + 12) = 0;
      *(_DWORD *)v52 = v55 & (v54 + v53) & 0xFFFFFF;
      v52 += 16;
    }
    while ( (_DWORD)v32 != 64 );
    v56 = *(_DWORD *)(result + 88);
    v57 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v52 + 12) = 0;
    *(_QWORD *)(v52 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)v52 = v57 & (v56 + 118848) & 0xFFFFFF;
    if ( v21 != (_QWORD *)-168LL )
      v21[21] = v52;
    v58 = v17 - 1;
    v59 = v52 + 16;
    v60 = 118852;
    v61 = v58;
    do
    {
      v62 = *(_DWORD *)(result + 88);
      v63 = *(_DWORD *)(result + 70256);
      --v61;
      *(_QWORD *)(v59 + 4) = 0xFFFFFFFF00000000LL;
      v64 = v60 + v62;
      *(_DWORD *)(v59 + 12) = 0;
      v60 += 4;
      *(_DWORD *)v59 = v63 & v64 & 0xFFFFFF;
      v59 += 16;
    }
    while ( v61 );
    v65 = *(_DWORD *)(result + 88);
    v66 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v59 + 12) = 0;
    *(_QWORD *)(v59 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)v59 = v66 & (v65 + 107344) & 0xFFFFFF;
    if ( v21 != (_QWORD *)-184LL )
      v21[23] = v59;
    v67 = *(_DWORD *)(result + 88);
    v68 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v59 + 20) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v59 + 28) = 0;
    *(_DWORD *)(v59 + 16) = v68 & (v67 + 107348) & 0xFFFFFF;
    v69 = *(_DWORD *)(result + 88);
    v70 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v59 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v59 + 44) = 0;
    *(_DWORD *)(v59 + 32) = v70 & (v69 + 107352) & 0xFFFFFF;
    v71 = *(_DWORD *)(result + 88);
    v72 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v59 + 52) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v59 + 60) = 0;
    *(_DWORD *)(v59 + 48) = v72 & (v71 + 107356) & 0xFFFFFF;
    v73 = v59 + 64;
    if ( *(_BYTE *)(result + 73) == 1 )
    {
      v74 = *(_DWORD *)(result + 88);
      v75 = *(_DWORD *)(result + 70256);
      *(_QWORD *)(v59 + 68) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v59 + 76) = 0;
      *(_DWORD *)(v59 + 64) = v75 & (v74 + 107524) & 0xFFFFFF;
      if ( v21 != (_QWORD *)-120LL )
        v21[15] = v73;
      v73 = v59 + 80;
    }
    v76 = *(_DWORD *)(result + 88);
    v77 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v73 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v73 + 12) = 0;
    *(_DWORD *)v73 = v77 & (v76 + 118784) & 0xFFFFFF;
    if ( v21 != (_QWORD *)-48LL )
      v21[6] = v73;
    v78 = 0;
    v79 = 118788;
    do
    {
      v80 = *(_DWORD *)(result + 88);
      v81 = *(_DWORD *)(result + 70256);
      v82 = v73 + v78;
      --v58;
      v78 += 16;
      *(_QWORD *)(v82 + 20) = 0xFFFFFFFF00000000LL;
      v83 = v79 + v80;
      v79 += 4;
      *(_DWORD *)(v82 + 28) = 0;
      *(_DWORD *)(v82 + 16) = v81 & v83 & 0xFFFFFF;
    }
    while ( v58 );
    v84 = v73 + v78;
    *(_DWORD *)(v73 + v78 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107020) & 0xFFFFFF;
    v85 = v73 + v78 + 16;
    *(_QWORD *)(v85 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v85 + 12) = 0;
    if ( v21 != (_QWORD *)-64LL )
      v21[8] = v85;
    v86 = *(_DWORD *)(result + 88);
    v87 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v84 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v84 + 44) = 0;
    *(_DWORD *)(v84 + 32) = v87 & (v86 + 107024) & 0xFFFFFF;
    v88 = *(_DWORD *)(result + 88);
    v89 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v84 + 52) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v84 + 60) = 0;
    *(_DWORD *)(v84 + 48) = v89 & (v88 + 107028) & 0xFFFFFF;
    v90 = *(_DWORD *)(result + 88);
    v91 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v84 + 68) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v84 + 76) = 0;
    *(_DWORD *)(v84 + 64) = v91 & (v90 + 107032) & 0xFFFFFF;
    *(_DWORD *)(v84 + 80) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107040) & 0xFFFFFF;
    v92 = v84 + 80;
    *(_QWORD *)(v92 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v92 + 12) = 0;
    if ( v21 != (_QWORD *)-72LL )
      v21[9] = v92;
    v93 = *(_DWORD *)(result + 70256);
    v94 = v73 + v78;
    v95 = *(_DWORD *)(result + 88) + 107044;
    *(_QWORD *)(v94 + 100) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v94 + 108) = 0;
    *(_DWORD *)(v94 + 96) = v93 & v95 & 0xFFFFFF;
    v96 = *(_DWORD *)(result + 88);
    v97 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v94 + 116) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v94 + 124) = 0;
    *(_DWORD *)(v94 + 112) = v97 & (v96 + 107048) & 0xFFFFFF;
    v98 = *(_DWORD *)(result + 88);
    v99 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v94 + 132) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v94 + 140) = 0;
    *(_DWORD *)(v94 + 128) = v99 & (v98 + 107052) & 0xFFFFFF;
    v100 = *(_DWORD *)(result + 152);
    v101 = v73 + v78;
    *(_DWORD *)(v101 + 144) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
    *(_DWORD *)(v101 + 148) = v100;
    *(_QWORD *)(v73 + v78 + 152) = 0xFFFFFFFFLL;
    if ( v21 != (_QWORD *)-16LL )
      v21[2] = v73 + v78 + 144;
    *(_DWORD *)(v94 + 160) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106784) & 0xFFFFFF;
    v102 = v94 + 160;
    *(_QWORD *)(v102 + 4) = 0xFFFFFFFF00000007LL;
    *(_DWORD *)(v102 + 12) = 0;
    if ( v21 != (_QWORD *)-208LL )
      v21[26] = v102;
    v21[27] = v73 - v5 + v78 + 176;
    *a3 = v73 + v78 + 176;
  }
  return result;
}
