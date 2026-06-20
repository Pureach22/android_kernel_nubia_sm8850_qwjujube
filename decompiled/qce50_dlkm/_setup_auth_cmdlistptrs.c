__int64 __fastcall setup_auth_cmdlistptrs(__int64 result, __int64 a2, __int64 *a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  int v7; // w12
  int v8; // w14
  int v9; // w13
  int v10; // w16
  __int64 *v11; // x10
  int v12; // w14
  int v13; // w11
  char v14; // w15
  unsigned int v15; // w16
  int v16; // w17
  int v17; // w11
  int v18; // w11
  int v19; // w14
  int v20; // w15
  int v21; // w11
  int v22; // w14
  int v23; // w14
  __int64 v24; // x14
  __int64 v25; // x11
  __int64 v26; // x11
  int v27; // w13
  int v28; // w17
  int v29; // w16
  int v30; // w17
  int v31; // w1
  int v32; // w12
  int v33; // w12
  int v34; // w11
  int v35; // w15
  int v36; // w16
  int v37; // w16
  int v38; // w12
  __int64 v39; // x14
  int v40; // w4
  int v41; // w1
  __int64 v42; // x15
  int v43; // w16
  int v44; // w1
  int v45; // w3
  __int64 v46; // x4
  int v47; // w1
  __int64 v48; // x16
  int v49; // w1
  int v50; // w4
  __int64 v51; // x5
  __int64 v52; // x5
  int v53; // w3
  int v54; // w1
  __int64 v55; // x3
  int v56; // w17
  __int64 v57; // x15
  int v58; // w1
  int v59; // w3
  int v60; // w17
  int v61; // w1
  int v62; // w17
  int v63; // w14
  int v64; // w16
  int v65; // w14
  int v66; // w17
  __int64 v67; // x14
  int v68; // w17
  int v69; // w1
  int v70; // w15
  int v71; // w16
  int v72; // w13
  int v73; // w11
  int v74; // w16
  int v75; // w17
  int v76; // w16
  int v77; // w11
  int v78; // w13
  int v79; // w16
  int v80; // w1
  int v81; // w16
  int v82; // w1
  int v83; // w16
  int v84; // w1
  int v85; // w15
  int v86; // w16
  int v87; // w15
  int v88; // w16
  int v89; // w15
  int v90; // w16

  if ( (unsigned int)a2 >= 9 )
  {
    __break(0x5512u);
    return setup_aead_cmdlistptrs(result, a2, a3, a4, a5, a6);
  }
  v6 = (*a3 + *(int *)(result + 400) - 1) & -(__int64)*(int *)(result + 400);
  *a3 = v6;
  if ( (int)a4 <= 1 )
  {
    if ( (_DWORD)a4 )
    {
      v34 = *(_DWORD *)(result + 88);
      *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 5184) = v6;
      v9 = *(_DWORD *)(result + 232);
      v35 = *(_DWORD *)(result + 70256);
      *(_QWORD *)(v6 + 4) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v6 + 12) = 0;
      *(_DWORD *)v6 = v35 & (v34 + 106752) & 0xFFFFFF;
      v36 = *(_DWORD *)(result + 148);
      *(_DWORD *)(v6 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
      *(_DWORD *)(v6 + 20) = v36;
      v11 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 5184);
      *(_QWORD *)(v6 + 24) = 0xFFFFFFFFLL;
      if ( result + 7432LL * (unsigned int)a2 != -5192 )
        *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 5192) = v6 + 16;
      v37 = *(_DWORD *)(result + 88);
      v38 = *(_DWORD *)(result + 70256);
      v17 = 0;
      v14 = 0;
      *(_QWORD *)(v6 + 36) = 0xFFFFFFFF00000000LL;
      v16 = 1;
      *(_DWORD *)(v6 + 44) = 0;
      v33 = v38 & (v37 + 107012);
      v15 = 8;
      goto LABEL_29;
    }
    v18 = *(_DWORD *)(result + 88);
    *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 4960) = v6;
    v9 = *(_DWORD *)(result + 228);
    v19 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v6 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v6 + 12) = 0;
    v11 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 4960);
    *(_DWORD *)v6 = v19 & (v18 + 106752) & 0xFFFFFF;
    v20 = *(_DWORD *)(result + 148);
    *(_DWORD *)(v6 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
    *(_DWORD *)(v6 + 20) = v20;
    *(_QWORD *)(v6 + 24) = 0xFFFFFFFFLL;
    v17 = 0;
    if ( result + 7432LL * (unsigned int)a2 != -4968 )
      *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 4968) = v6 + 16;
    v15 = 5;
    v16 = 1;
  }
  else
  {
    if ( (_DWORD)a4 != 2 )
    {
      if ( (_DWORD)a4 == 3 )
      {
        v7 = *(_DWORD *)(result + 88);
        *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 5632) = v6;
        v8 = *(_DWORD *)(result + 70256);
        v9 = *(_DWORD *)(result + 240);
        *(_QWORD *)(v6 + 4) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v6 + 12) = 0;
        *(_DWORD *)v6 = v8 & (v7 + 106752) & 0xFFFFFF;
        v10 = *(_DWORD *)(result + 148);
        *(_DWORD *)(v6 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
        *(_DWORD *)(v6 + 20) = v10;
        v11 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 5632);
        *(_QWORD *)(v6 + 24) = 0xFFFFFFFFLL;
        if ( result + 7432LL * (unsigned int)a2 != -5640 )
          *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 5640) = v6 + 16;
        v12 = *(_DWORD *)(result + 88);
        v13 = *(_DWORD *)(result + 70256);
        v14 = 0;
        *(_QWORD *)(v6 + 36) = 0xFFFFFFFF00000000LL;
        v15 = 8;
        v16 = 1;
        *(_DWORD *)(v6 + 44) = 0;
        *(_DWORD *)(v6 + 32) = v13 & (v12 + 107012) & 0xFFFFFF;
        v17 = 16;
        goto LABEL_30;
      }
      v25 = 3360;
      if ( (a5 & 1) != 0 )
        v25 = 3136;
      v11 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 2720 + v25);
      v26 = 224;
      v27 = *(_DWORD *)(result + 88) + 107520;
      *v11 = v6;
      if ( (a5 & 1) != 0 )
        v26 = 220;
      v28 = *(_DWORD *)(result + 70256);
      v29 = v27 - 768;
      v9 = *(_DWORD *)(result + v26);
      *(_DWORD *)(v6 + 12) = 0;
      *(_QWORD *)(v6 + 4) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)v6 = v28 & v29 & 0xFFFFFF;
      v30 = *(_DWORD *)(result + 148);
      *(_DWORD *)(v6 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
      *(_DWORD *)(v6 + 20) = v30;
      if ( (a5 & 1) != 0 )
        v17 = 4;
      else
        v17 = 8;
      *(_QWORD *)(v6 + 24) = 0xFFFFFFFFLL;
      if ( v11 != (__int64 *)-8LL )
        v11[1] = v6 + 16;
      v31 = *(_DWORD *)(result + 88);
      v32 = *(_DWORD *)(result + 70256);
      v16 = 0;
      v14 = 0;
      v15 = 0;
      *(_QWORD *)(v6 + 36) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v6 + 44) = 0;
      v33 = v32 & (v31 + 107012);
LABEL_29:
      *(_DWORD *)(v6 + 32) = v33 & 0xFFFFFF;
LABEL_30:
      v24 = 48;
      goto LABEL_31;
    }
    v21 = *(_DWORD *)(result + 88);
    *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 5408) = v6;
    v9 = *(_DWORD *)(result + 236);
    v22 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v6 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v6 + 12) = 0;
    *(_DWORD *)v6 = v22 & (v21 + 106752) & 0xFFFFFF;
    v23 = *(_DWORD *)(result + 148);
    *(_DWORD *)(v6 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520) & 0xFFFFFF;
    *(_DWORD *)(v6 + 20) = v23;
    v11 = (__int64 *)(result + 7432LL * (unsigned int)a2 + 5408);
    *(_QWORD *)(v6 + 24) = 0xFFFFFFFFLL;
    if ( result + 7432LL * (unsigned int)a2 != -5416 )
      *(_QWORD *)(result + 7432LL * (unsigned int)a2 + 5416) = v6 + 16;
    v15 = 5;
    v16 = 1;
    v17 = 16;
  }
  v24 = 32;
  v14 = 1;
LABEL_31:
  v39 = v6 + v24;
  v40 = *(_DWORD *)(result + 70256);
  v41 = *(_DWORD *)(result + 88) + 107520;
  *(_DWORD *)(v39 + 12) = 0;
  *(_QWORD *)(v39 + 4) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)v39 = v40 & (v41 - 752) & 0xFFFFFF;
  if ( v11 != (__int64 *)-200LL )
    v11[25] = v39;
  *(_DWORD *)(v39 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107008) & 0xFFFFFF;
  *(_QWORD *)(v39 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v39 + 28) = 0;
  if ( v11 != (__int64 *)-24LL )
    v11[3] = v39 + 16;
  *(_DWORD *)(v39 + 32) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107264) & 0xFFFFFF;
  *(_DWORD *)(v39 + 36) = v9;
  *(_QWORD *)(v39 + 40) = 0xFFFFFFFFLL;
  if ( v11 != (__int64 *)-144LL )
    v11[18] = v39 + 32;
  *(_DWORD *)(v39 + 48) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107268) & 0xFFFFFF;
  *(_QWORD *)(v39 + 52) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v39 + 60) = 0;
  if ( v11 != (__int64 *)-152LL )
    v11[19] = v39 + 48;
  *(_DWORD *)(v39 + 64) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107272) & 0xFFFFFF;
  *(_QWORD *)(v39 + 68) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v39 + 76) = 0;
  if ( v11 != (__int64 *)-160LL )
    v11[20] = v39 + 64;
  if ( (_DWORD)a4 == 4 )
  {
    v42 = 0;
    v43 = 107280;
    do
    {
      v44 = *(_DWORD *)(result + 88);
      v45 = *(_DWORD *)(result + 70256);
      v46 = v39 + v42;
      v42 += 16;
      *(_QWORD *)(v46 + 84) = 0xFFFFFFFF00000000LL;
      v47 = v43 + v44;
      v43 += 4;
      *(_DWORD *)(v46 + 92) = 0;
      *(_DWORD *)(v46 + 80) = v45 & v47 & 0xFFFFFF;
    }
    while ( (_DWORD)v42 != 256 );
    v48 = 0;
    v49 = 118848;
    do
    {
      v50 = *(_DWORD *)(result + 70256);
      v51 = v39 + v48;
      v48 += 16;
      v52 = v51 + v42;
      v53 = v49 + *(_DWORD *)(result + 88);
      v49 += 4;
      *(_QWORD *)(v52 + 84) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v52 + 92) = 0;
      *(_DWORD *)(v52 + 80) = v50 & v53 & 0xFFFFFF;
    }
    while ( (_DWORD)v48 != 256 );
    v54 = *(_DWORD *)(result + 70256);
    v55 = v39 + v48 + v42;
    v56 = *(_DWORD *)(result + 88) + 107520;
    *(_QWORD *)(v55 + 84) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v55 + 92) = 0;
    *(_DWORD *)(v55 + 80) = v54 & (v56 - 112) & 0xFFFFFF;
    v57 = v39 + v42 + v48 + 80;
  }
  else
  {
    v58 = *(_DWORD *)(result + 88);
    v59 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v39 + 84) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v39 + 92) = 0;
    *(_DWORD *)(v39 + 80) = v59 & (v58 + 107280) & 0xFFFFFF;
    if ( v11 != (__int64 *)-176LL )
      v11[22] = v39 + 80;
    if ( v16 )
    {
      v60 = *(_DWORD *)(result + 88);
      v61 = *(_DWORD *)(result + 70256);
      *(_DWORD *)(v39 + 108) = 0;
      v62 = v60 + 107520;
      if ( v15 <= 2 )
        v15 = 2;
      *(_QWORD *)(v39 + 100) = 0xFFFFFFFF00000000LL;
      *(_DWORD *)(v39 + 96) = v61 & (v62 - 236) & 0xFFFFFF;
      if ( v15 == 2 )
      {
        v57 = v39 + 112;
      }
      else
      {
        v79 = *(_DWORD *)(result + 88);
        v80 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v39 + 116) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v39 + 124) = 0;
        *(_DWORD *)(v39 + 112) = v80 & (v79 + 107288) & 0xFFFFFF;
        v81 = *(_DWORD *)(result + 88);
        v82 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v39 + 132) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v39 + 140) = 0;
        *(_DWORD *)(v39 + 128) = v82 & (v81 + 107292) & 0xFFFFFF;
        v83 = *(_DWORD *)(result + 88);
        v84 = *(_DWORD *)(result + 70256);
        *(_QWORD *)(v39 + 148) = 0xFFFFFFFF00000000LL;
        *(_DWORD *)(v39 + 156) = 0;
        *(_DWORD *)(v39 + 144) = v84 & (v83 + 107296) & 0xFFFFFF;
        if ( (v14 & 1) != 0 )
        {
          v57 = v39 + 160;
        }
        else
        {
          v85 = *(_DWORD *)(result + 88);
          v86 = *(_DWORD *)(result + 70256);
          *(_DWORD *)(v39 + 172) = 0;
          *(_QWORD *)(v39 + 164) = 0xFFFFFFFF00000000LL;
          *(_DWORD *)(v39 + 160) = v86 & (v85 + 107300) & 0xFFFFFF;
          v87 = *(_DWORD *)(result + 88);
          v88 = *(_DWORD *)(result + 70256);
          *(_QWORD *)(v39 + 180) = 0xFFFFFFFF00000000LL;
          *(_DWORD *)(v39 + 188) = 0;
          *(_DWORD *)(v39 + 176) = v88 & (v87 + 107304) & 0xFFFFFF;
          v89 = *(_DWORD *)(result + 88);
          v90 = *(_DWORD *)(result + 70256);
          *(_QWORD *)(v39 + 196) = 0xFFFFFFFF00000000LL;
          *(_DWORD *)(v39 + 204) = 0;
          *(_DWORD *)(v39 + 192) = v90 & (v89 + 107308) & 0xFFFFFF;
          v57 = v39 + 208;
        }
      }
    }
    else
    {
      v57 = v39 + 96;
    }
    v63 = *(_DWORD *)(result + 88);
    v64 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v57 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v57 + 12) = 0;
    *(_DWORD *)v57 = v64 & (v63 + 107408) & 0xFFFFFF;
    if ( v11 != (__int64 *)-192LL )
      v11[24] = v57;
  }
  v65 = *(_DWORD *)(result + 88);
  v66 = *(_DWORD *)(result + 70256);
  *(_QWORD *)(v57 + 20) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v57 + 28) = 0;
  *(_DWORD *)(v57 + 16) = v66 & (v65 + 107412) & 0xFFFFFF;
  v67 = v57 + 32;
  if ( *(_BYTE *)(result + 73) == 1 )
  {
    v68 = *(_DWORD *)(result + 88);
    v69 = *(_DWORD *)(result + 70256);
    *(_QWORD *)(v57 + 36) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)(v57 + 44) = 0;
    *(_DWORD *)(v57 + 32) = v69 & (v68 + 107524) & 0xFFFFFF;
    if ( v11 != (__int64 *)-120LL )
      v11[15] = v67;
    v67 = v57 + 48;
  }
  if ( v17 )
  {
    v70 = *(_DWORD *)(result + 88);
    v71 = *(_DWORD *)(result + 70256);
    *(_DWORD *)(v67 + 12) = 0;
    *(_QWORD *)(v67 + 4) = 0xFFFFFFFF00000000LL;
    *(_DWORD *)v67 = v71 & (v70 + 118848) & 0xFFFFFF;
    if ( v11 != (__int64 *)-168LL )
      v11[21] = v67;
    v67 += 16;
    v72 = 118852;
    v73 = v17 - 1;
    do
    {
      v74 = *(_DWORD *)(result + 88);
      v75 = *(_DWORD *)(result + 70256);
      --v73;
      *(_QWORD *)(v67 + 4) = 0xFFFFFFFF00000000LL;
      v76 = v72 + v74;
      *(_DWORD *)(v67 + 12) = 0;
      v72 += 4;
      *(_DWORD *)v67 = v75 & v76 & 0xFFFFFF;
      v67 += 16;
    }
    while ( v73 );
  }
  v77 = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 107520);
  v78 = *(_DWORD *)(result + 152);
  *(_QWORD *)(v67 + 8) = 0xFFFFFFFFLL;
  *(_DWORD *)v67 = v77 & 0xFFFFFF;
  *(_DWORD *)(v67 + 4) = v78;
  if ( v11 != (__int64 *)-16LL )
    v11[2] = v67;
  *(_DWORD *)(v67 + 16) = *(_DWORD *)(result + 70256) & (*(_DWORD *)(result + 88) + 106784) & 0xFFFFFF;
  *(_QWORD *)(v67 + 20) = 0xFFFFFFFF00000007LL;
  *(_DWORD *)(v67 + 28) = 0;
  if ( v11 != (__int64 *)-208LL )
    v11[26] = v67 + 16;
  v11[27] = v67 + 32 - v6;
  *a3 = v67 + 32;
  return result;
}
