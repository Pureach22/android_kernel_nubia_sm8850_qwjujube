__int64 __fastcall setup_cipher_aes_cmdlistptrs(__int64 result, __int64 a2, __int64 *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x8
  __int64 *v6; // x9
  int v7; // w17
  char v8; // w15
  unsigned int v9; // w16
  int v10; // w14
  unsigned int v11; // w12
  char v12; // w4
  __int64 v13; // x5
  char v14; // w1
  char v15; // w13
  int v16; // w5
  int v17; // w7
  int v18; // w19
  int v19; // w7
  int v20; // w19
  int v21; // w7
  int v22; // w19
  int v23; // w7
  int v24; // w19
  int v25; // w7
  int v26; // w19
  int v27; // w7
  int v28; // w19
  int v29; // w20
  int v30; // w7
  int v31; // w7
  int v32; // w7
  int v33; // w7
  int v34; // w6
  int v35; // w7
  int v36; // w5
  int v37; // w6
  __int64 v38; // x7
  int v39; // w5
  int v40; // w6
  int v41; // w5
  int v42; // w6
  int v43; // w6
  int v44; // w20
  int v45; // w6
  int v46; // w20
  __int64 v47; // x6
  __int64 v48; // x4
  int v49; // w4
  int v50; // w6
  int v51; // w4
  int v52; // w6
  int v53; // w4
  int v54; // w6
  __int64 v55; // x7
  int v56; // w17
  int v57; // w1
  int v58; // w17
  __int64 v59; // x15
  int v60; // w16
  int v61; // w17
  int v62; // w13
  int v63; // w15
  int v64; // w13
  int v65; // w14
  int v66; // w13
  int v67; // w16
  int v68; // w1
  int v69; // w16
  int v70; // w1
  int v71; // w12
  int v72; // w14
  int v73; // w12
  int v74; // w14
  int v75; // w12
  int v76; // w13
  __int64 *v77; // x12
  __int64 v78; // x13
  __int64 v79; // x14
  int v80; // w15
  __int64 v81; // x12
  int v82; // w15
  int v83; // w16
  int v84; // w15
  int v85; // w16
  int v86; // w15
  int v87; // w16
  int v88; // w15
  int v89; // w16

  if ( (unsigned int)a2 >= 9 )
  {
    __break(0x5512u);
    return setup_cipher_des_cmdlistptrs(result, a2, a3, a4, a5);
  }
  v5 = (*a3 + *(int *)(result + 400) - 1) & -(__int64)*(int *)(result + 400);
  v6 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 2720);
  *a3 = v5;
  if ( (int)a4 > 1 )
  {
    if ( (_DWORD)a4 == 3 )
    {
      if ( (a5 & 1) != 0 )
      {
        v14 = 0;
        v15 = 0;
        v6[112] = v5;
        v6 += 112;
        v9 = 4;
        v12 = 1;
        v13 = 172;
        v7 = 1;
        v8 = 1;
        v10 = 1;
        v11 = 4;
        goto LABEL_22;
      }
      v12 = 0;
      v14 = 0;
      v8 = 0;
      v15 = 0;
      v6[140] = v5;
      v6 += 140;
      v11 = 4;
      v9 = 8;
      v7 = 1;
      v13 = 176;
      goto LABEL_21;
    }
LABEL_10:
    if ( (a5 & 1) != 0 )
    {
      v7 = 0;
      v8 = 0;
      v9 = 0;
      v15 = 0;
      *v6 = v5;
      if ( (_DWORD)a4 )
        v13 = 180;
      else
        v13 = 156;
      v11 = 4;
      v12 = 1;
      v14 = 1;
    }
    else
    {
      v12 = 0;
      v7 = 0;
      v8 = 0;
      v9 = 0;
      v15 = 0;
      if ( (_DWORD)a4 )
        v13 = 184;
      else
        v13 = 160;
      *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 2944) = v5;
      v6 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 2944);
      v11 = 4;
      v14 = 1;
    }
LABEL_21:
    v10 = 1;
    goto LABEL_22;
  }
  if ( !(_DWORD)a4 )
    goto LABEL_10;
  if ( (a5 & 1) != 0 )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 3168) = v5;
    v6 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 3168);
    v12 = 1;
    v13 = 164;
    v14 = 1;
  }
  else
  {
    v12 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 3392) = v5;
    v6 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 3392);
    v14 = 1;
    v13 = 168;
  }
  v15 = 1;
LABEL_22:
  v16 = *(_DWORD *)(result + v13);
  v17 = *(_DWORD *)(result + 70256);
  v18 = *(_DWORD *)(result + 88) + 106752;
  *(_QWORD *)(v5 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)v5 = v17 & v18 & 0xFFFFFF;
  v19 = *(_DWORD *)(result + 88);
  v20 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v5 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 28) = 0;
  *(_DWORD *)(v5 + 16) = v20 & (v19 + 106756) & 0xFFFFFF;
  v21 = *(_DWORD *)(result + 88);
  v22 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v5 + 36) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 44) = 0;
  *(_DWORD *)(v5 + 32) = v22 & (v21 + 106780) & 0xFFFFFF;
  v23 = *(_DWORD *)(result + 88);
  v24 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v5 + 52) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 60) = 0;
  *(_DWORD *)(v5 + 48) = v24 & (v23 + 106788) & 0xFFFFFF;
  v25 = *(_DWORD *)(result + 88);
  v26 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v5 + 68) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 76) = 0;
  *(_DWORD *)(v5 + 64) = v26 & (v25 + 106792) & 0xFFFFFF;
  v27 = *(_DWORD *)(result + 88);
  v28 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v5 + 84) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 92) = 0;
  *(_DWORD *)(v5 + 80) = v28 & (v27 + 106812) & 0xFFFFFF;
  v29 = *(_DWORD *)(result + 148);
  *(_DWORD *)(v5 + 96) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
  *(_DWORD *)(v5 + 100) = v29;
  *(_QWORD *)(v5 + 104) = 0xFFFFFFFFLL;
  if ( v6 != (__int64 *)-8LL )
    v6[1] = v5 + 96;
  *(_DWORD *)(v5 + 112) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106768) & 0xFFFFFF;
  *(_QWORD *)(v5 + 116) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 124) = 0;
  if ( v6 != (__int64 *)-200LL )
    v6[25] = v5 + 112;
  *(_DWORD *)(v5 + 128) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107008) & 0xFFFFFF;
  *(_DWORD *)(v5 + 132) = v16;
  *(_QWORD *)(v5 + 136) = 0xFFFFFFFFLL;
  if ( v6 != (__int64 *)-24LL )
    v6[3] = v5 + 128;
  *(_DWORD *)(v5 + 144) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107012) & 0xFFFFFF;
  *(_QWORD *)(v5 + 148) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 156) = 0;
  if ( v6 != (__int64 *)-32LL )
    v6[4] = v5 + 144;
  *(_DWORD *)(v5 + 160) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107016) & 0xFFFFFF;
  *(_QWORD *)(v5 + 164) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 172) = 0;
  if ( v6 != (__int64 *)-40LL )
    v6[5] = v5 + 160;
  v30 = *(_DWORD *)(result + 280);
  *(_DWORD *)(v5 + 176) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107036) & 0xFFFFFF;
  *(_DWORD *)(v5 + 180) = v30;
  *(_QWORD *)(v5 + 184) = 0xFFFFFFFFLL;
  if ( v6 != (__int64 *)-104LL )
    v6[13] = v5 + 176;
  v31 = *(_DWORD *)(result + 276);
  *(_DWORD *)(v5 + 192) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107060) & 0xFFFFFF;
  *(_DWORD *)(v5 + 196) = v31;
  *(_QWORD *)(v5 + 200) = 0xFFFFFFFFLL;
  if ( v6 != (__int64 *)-96LL )
    v6[12] = v5 + 192;
  v32 = *(_DWORD *)(result + 272);
  *(_DWORD *)(v5 + 208) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107064) & 0xFFFFFF;
  *(_DWORD *)(v5 + 212) = v32;
  *(_QWORD *)(v5 + 216) = 0xFFFFFFFFLL;
  if ( v6 != (__int64 *)-88LL )
    v6[11] = v5 + 208;
  v33 = *(_DWORD *)(result + 268);
  *(_DWORD *)(v5 + 224) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107068) & 0xFFFFFF;
  *(_DWORD *)(v5 + 228) = v33;
  *(_QWORD *)(v5 + 232) = 0xFFFFFFFFLL;
  if ( v6 != (__int64 *)-80LL )
    v6[10] = v5 + 224;
  *(_DWORD *)(v5 + 240) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107264) & 0xFFFFFF;
  *(_QWORD *)(v5 + 244) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 252) = 0;
  if ( v6 != (__int64 *)-144LL )
    v6[18] = v5 + 240;
  v34 = *(_DWORD *)(result + 88);
  v35 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v5 + 260) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 268) = 0;
  *(_DWORD *)(v5 + 256) = v35 & (v34 + 107776) & 0xFFFFFF;
  if ( v6 != (__int64 *)-128LL )
    v6[16] = v5 + 256;
  v36 = *(_DWORD *)(result + 88);
  v37 = *(_DWORD *)(result + 70256);
  *(_DWORD *)(v5 + 284) = 0;
  *(_QWORD *)(v5 + 276) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v5 + 272) = v37 & (v36 + 107780) & 0xFFFFFF;
  if ( v6 != (__int64 *)-136LL )
    v6[17] = v5 + 272;
  v38 = v5 + 288;
  if ( *(_BYTE *)(result + 73) == 1 )
  {
    v39 = *(_DWORD *)(result + 88);
    v40 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v5 + 300) = 0;
    *(_DWORD *)(v5 + 288) = v40 & (v39 + 107524) & 0xFFFFFF;
    *(_QWORD *)(v5 + 292) = 0xFFFFFFFF00000000LL;
    if ( v6 != (__int64 *)-120LL )
      v6[15] = v38;
    v38 = v5 + 304;
  }
  v41 = *(_DWORD *)(result + 88);
  v42 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v38 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v38 + 12) = 0;
  *(_DWORD *)v38 = v42 & (v41 + 118784) & 0xFFFFFF;
  if ( v6 != (__int64 *)-48LL )
    v6[6] = v38;
  v43 = *(_DWORD *)(result + 88);
  v44 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v38 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v38 + 28) = 0;
  *(_DWORD *)(v38 + 16) = v44 & (v43 + 118788) & 0xFFFFFF;
  v45 = *(_DWORD *)(result + 88);
  v46 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v38 + 36) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v38 + 44) = 0;
  *(_DWORD *)(v38 + 32) = v46 & (v45 + 118792) & 0xFFFFFF;
  *(_DWORD *)(v38 + 48) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 118796) & 0xFFFFFF;
  v47 = v38 + 48;
  *(_QWORD *)(v38 + 52) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v38 + 60) = 0;
  if ( (v12 & 1) != 0 )
  {
    v48 = v38 + 64;
    if ( (v14 & 1) != 0 )
      goto LABEL_67;
  }
  else
  {
    v49 = *(_DWORD *)(result + 88);
    v50 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v38 + 76) = 0;
    *(_QWORD *)(v38 + 68) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v38 + 64) = v50 & (v49 + 118800) & 0xFFFFFF;
    v51 = *(_DWORD *)(result + 88);
    v52 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v38 + 84) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v38 + 92) = 0;
    *(_DWORD *)(v38 + 80) = v52 & (v51 + 118804) & 0xFFFFFF;
    v53 = *(_DWORD *)(result + 88);
    v54 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v38 + 100) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v38 + 108) = 0;
    *(_DWORD *)(v38 + 96) = v54 & (v53 + 118808) & 0xFFFFFF;
    *(_DWORD *)(v38 + 112) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 118812) & 0xFFFFFF;
    v55 = v38 + 112;
    v48 = v55 + 16;
    v47 = v55;
    *(_QWORD *)(v55 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v55 + 12) = 0;
    if ( (v14 & 1) != 0 )
      goto LABEL_67;
  }
  *(_DWORD *)v48 = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 118816) & 0xFFFFFF;
  *(_QWORD *)(v47 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v47 + 28) = 0;
  if ( v6 != (__int64 *)-56LL )
    v6[7] = v48;
  if ( v7 )
  {
    v56 = *(_DWORD *)(result + 88);
    v57 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v47 + 44) = 0;
    v58 = v56 + 118784;
    if ( v9 <= 2 )
      v9 = 2;
    *(_QWORD *)(v47 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v47 + 32) = v57 & (v58 + 36) & 0xFFFFFF;
    if ( v9 == 2 )
    {
      v59 = v47 + 48;
    }
    else
    {
      v67 = *(_DWORD *)(result + 88);
      v68 = *(_DWORD *)(result + 70256);
      *(_QWORD *)(v47 + 52) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v47 + 60) = 0;
      *(_DWORD *)(v47 + 48) = v68 & (v67 + 118824) & 0xFFFFFF;
      v69 = *(_DWORD *)(result + 88);
      v70 = *(_DWORD *)(result + 70256);
      *(_QWORD *)(v47 + 68) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v47 + 76) = 0;
      *(_DWORD *)(v47 + 64) = v70 & (v69 + 118828) & 0xFFFFFF;
      if ( (v8 & 1) != 0 )
      {
        v59 = v47 + 80;
      }
      else
      {
        v82 = *(_DWORD *)(result + 88);
        v83 = *(_DWORD *)(result + 70256);
        *(_DWORD *)(v47 + 92) = 0;
        *(_QWORD *)(v47 + 84) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v47 + 80) = v83 & (v82 + 118832) & 0xFFFFFF;
        v84 = *(_DWORD *)(result + 88);
        v85 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v47 + 100) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v47 + 108) = 0;
        *(_DWORD *)(v47 + 96) = v85 & (v84 + 118836) & 0xFFFFFF;
        v86 = *(_DWORD *)(result + 88);
        v87 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v47 + 116) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v47 + 124) = 0;
        *(_DWORD *)(v47 + 112) = v87 & (v86 + 118840) & 0xFFFFFF;
        v88 = *(_DWORD *)(result + 88);
        v89 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v47 + 132) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v47 + 140) = 0;
        *(_DWORD *)(v47 + 128) = v89 & (v88 + 118844) & 0xFFFFFF;
        v59 = v47 + 144;
      }
    }
  }
  else
  {
    v59 = v47 + 32;
  }
  v60 = *(_DWORD *)(result + 88);
  v61 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v59 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v59 + 12) = 0;
  *(_DWORD *)v59 = v61 & (v60 + 107056) & 0xFFFFFF;
  if ( v6 != (__int64 *)-112LL )
    v6[14] = v59;
  v48 = v59 + 16;
LABEL_67:
  if ( (v15 & 1) == 0 )
  {
    v62 = *(_DWORD *)(result + 88);
    v63 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v48 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v48 + 12) = 0;
    *(_DWORD *)v48 = v63 & (v62 + 107020) & 0xFFFFFF;
    if ( v6 != (__int64 *)-64LL )
      v6[8] = v48;
    if ( v10 )
    {
      v64 = *(_DWORD *)(result + 88);
      v65 = *(_DWORD *)(result + 70256);
      *(_DWORD *)(v48 + 28) = 0;
      v66 = v64 + 107520;
      if ( v11 <= 2 )
        v11 = 2;
      *(_QWORD *)(v48 + 20) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v48 + 16) = v65 & (v66 - 496) & 0xFFFFFF;
      if ( v11 == 2 )
      {
        v48 += 32;
      }
      else
      {
        v71 = *(_DWORD *)(result + 88);
        v72 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v48 + 36) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v48 + 44) = 0;
        *(_DWORD *)(v48 + 32) = v72 & (v71 + 107028) & 0xFFFFFF;
        v73 = *(_DWORD *)(result + 88);
        v74 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v48 + 52) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v48 + 60) = 0;
        *(_DWORD *)(v48 + 48) = v74 & (v73 + 107032) & 0xFFFFFF;
        v48 += 64;
      }
    }
    else
    {
      v48 += 16;
    }
  }
  v75 = *(_DWORD *)(result + 88);
  v76 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v48 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v48 + 12) = 0;
  *(_DWORD *)v48 = v76 & (v75 + 107268) & 0xFFFFFF;
  v77 = v6 + 19;
  if ( (_DWORD)a4 == 3 )
  {
    v78 = 16;
    v79 = v48;
    if ( v6 == (__int64 *)-152LL )
      goto LABEL_86;
  }
  else
  {
    if ( v6 != (__int64 *)-152LL )
      *v77 = v48;
    *(_DWORD *)(v48 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107272) & 0xFFFFFF;
    v79 = v48 + 16;
    v78 = 32;
    *(_QWORD *)(v48 + 20) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v48 + 28) = 0;
    if ( v6 == (__int64 *)-152LL )
      goto LABEL_86;
  }
  *v77 = v79;
LABEL_86:
  v80 = *(_DWORD *)(result + 152);
  v81 = v48 + v78;
  *(_DWORD *)v81 = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
  *(_DWORD *)(v81 + 4) = v80;
  *(_QWORD *)(v81 + 8) = 0xFFFFFFFFLL;
  if ( v6 != (__int64 *)-16LL )
    v6[2] = v81;
  *(_DWORD *)(v81 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106784) & 0xFFFFFF;
  *(_QWORD *)(v81 + 20) = 0xFFFFFFFF00000007LL;
  *(_DWORD *)(v81 + 28) = 0;
  if ( v6 != (__int64 *)-208LL )
    v6[26] = v81 + 16;
  v6[27] = v81 + 32 - v5;
  *a3 = v81 + 32;
  return result;
}
