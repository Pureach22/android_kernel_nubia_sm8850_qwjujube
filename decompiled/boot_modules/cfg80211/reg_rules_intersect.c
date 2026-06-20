__int64 __fastcall reg_rules_intersect(__int64 a1, __int64 a2, int *a3, int *a4, __int64 a5)
{
  unsigned int v5; // w8
  unsigned int v6; // w9
  int v7; // w11
  unsigned int v8; // w10
  unsigned int v9; // w11
  int v10; // w12
  unsigned __int64 v11; // x12
  __int64 v12; // x16
  __int64 v13; // x15
  unsigned __int64 v14; // x13
  __int64 v15; // x14
  __int64 v16; // x17
  bool v17; // zf
  unsigned int v18; // w12
  unsigned int *v19; // x16
  unsigned int *v20; // x5
  unsigned int v21; // w15
  __int64 v22; // x6
  unsigned __int64 v23; // x12
  unsigned int *v24; // x13
  unsigned __int64 v25; // x12
  unsigned int v26; // w14
  bool v27; // cc
  int v28; // w13
  int v29; // w13
  int v30; // w13
  int v31; // w13
  unsigned __int64 v32; // x10
  __int64 v33; // x16
  __int64 v34; // x15
  unsigned __int64 v35; // x13
  __int64 v36; // x14
  __int64 v37; // x17
  unsigned int *v38; // x16
  unsigned int *v39; // x0
  unsigned int v40; // w15
  __int64 v41; // x5
  unsigned __int64 v42; // x10
  unsigned int *v43; // x13
  unsigned __int64 v44; // x10
  unsigned int v45; // w14
  int v46; // w13
  int v47; // w13
  int v48; // w13
  int v49; // w13
  int v50; // w10
  unsigned int v51; // w12
  unsigned int v52; // w10
  unsigned int v53; // w11
  unsigned int v54; // w11
  unsigned int v55; // w11
  char v56; // w11
  __int64 v57; // x11
  int *v58; // x12
  int *v59; // x13
  __int64 v60; // x16
  unsigned int v61; // w14
  unsigned int v62; // w15
  unsigned int v63; // w14
  unsigned int v64; // w14
  unsigned int v65; // w14
  unsigned int v66; // w14
  unsigned int v67; // w14
  unsigned int v68; // w14
  unsigned int v69; // w12
  unsigned int v70; // w13
  __int64 *v71; // x11
  __int64 v72; // x13
  __int64 v73; // x14
  __int64 v74; // x15
  __int64 v75; // x12
  __int64 v76; // x13
  __int64 v77; // x11
  __int64 v78; // x14
  __int64 result; // x0

  v5 = *a3;
  if ( *a3 <= (unsigned int)*a4 )
    v5 = *a4;
  *(_DWORD *)a5 = v5;
  v6 = a3[1];
  if ( v6 >= a4[1] )
    v6 = a4[1];
  *(_DWORD *)(a5 + 4) = v6;
  v7 = a3[21];
  v8 = a4[2];
  if ( (v7 & 0x800) == 0 )
  {
    v9 = a3[2];
    v10 = a4[21];
    if ( (v10 & 0x800) == 0 )
      goto LABEL_86;
    goto LABEL_48;
  }
  v11 = *(unsigned int *)(a1 + 16);
  v12 = 0;
  v13 = a1 + 28;
  v14 = -1;
  v15 = 2;
  do
  {
    ++v14;
    v16 = v12 + 96;
    --v15;
    if ( v14 >= v11 )
      break;
    v17 = v13 + v12 == (_QWORD)a3;
    v12 += 96;
  }
  while ( !v17 );
  if ( (_DWORD)v11 == (_DWORD)v14 )
  {
    v18 = 0;
  }
  else
  {
    v19 = (unsigned int *)(v13 + v16);
    v20 = (unsigned int *)a3;
    do
    {
      v21 = *v20;
      if ( v16 == 96 )
        break;
      v22 = a1 + v16;
      v16 -= 96;
      v20 = (unsigned int *)(v22 - 164);
    }
    while ( *(_DWORD *)(v22 - 160) >= v21 );
    v23 = (unsigned int)(v11 - 1);
    if ( v14 > v23 )
      v23 = v14;
    v24 = (unsigned int *)a3;
    v25 = v23 + v15;
    while ( --v25 )
    {
      v26 = v24[1];
      v24 = v19;
      v27 = *v19 > v26;
      v19 += 24;
      if ( v27 )
        goto LABEL_25;
    }
    v26 = v24[1];
LABEL_25:
    v18 = v26 - v21;
  }
  if ( v18 >= 0x27100 )
    v28 = 160000;
  else
    v28 = v18;
  if ( (v7 & 0x40000) != 0 )
    v18 = v28;
  if ( v18 >= 0x13880 )
    v29 = 80000;
  else
    v29 = v18;
  if ( (v7 & 0x10000) != 0 )
    v18 = v29;
  if ( v18 >= 0x9C40 )
    v30 = 40000;
  else
    v30 = v18;
  if ( (v7 & 0x8000) != 0 )
    v18 = v30;
  if ( v18 >= 0x4E20 )
    v31 = 20000;
  else
    v31 = v18;
  if ( (~v7 & 0x6000) != 0 )
    v9 = v18;
  else
    v9 = v31;
  v10 = a4[21];
  if ( (v10 & 0x800) != 0 )
  {
LABEL_48:
    v32 = *(unsigned int *)(a2 + 16);
    v33 = 0;
    v34 = a2 + 28;
    v35 = -1;
    v36 = 2;
    do
    {
      ++v35;
      v37 = v33 + 96;
      --v36;
      if ( v35 >= v32 )
        break;
      v17 = v34 + v33 == (_QWORD)a4;
      v33 += 96;
    }
    while ( !v17 );
    if ( (_DWORD)v32 == (_DWORD)v35 )
    {
      v8 = 0;
    }
    else
    {
      v38 = (unsigned int *)(v34 + v37);
      v39 = (unsigned int *)a4;
      do
      {
        v40 = *v39;
        if ( v37 == 96 )
          break;
        v41 = a2 + v37;
        v37 -= 96;
        v39 = (unsigned int *)(v41 - 164);
      }
      while ( *(_DWORD *)(v41 - 160) >= v40 );
      v42 = (unsigned int)(v32 - 1);
      if ( v35 > v42 )
        v42 = v35;
      v43 = (unsigned int *)a4;
      v44 = v42 + v36;
      while ( --v44 )
      {
        v45 = v43[1];
        v43 = v38;
        v27 = *v38 > v45;
        v38 += 24;
        if ( v27 )
          goto LABEL_65;
      }
      v45 = v43[1];
LABEL_65:
      v8 = v45 - v40;
    }
    if ( v8 >= 0x27100 )
      v46 = 160000;
    else
      v46 = v8;
    if ( (v10 & 0x40000) != 0 )
      v8 = v46;
    if ( v8 >= 0x13880 )
      v47 = 80000;
    else
      v47 = v8;
    if ( (v10 & 0x10000) != 0 )
      v8 = v47;
    if ( v8 >= 0x9C40 )
      v48 = 40000;
    else
      v48 = v8;
    if ( (v10 & 0x8000) != 0 )
      v8 = v48;
    if ( v8 >= 0x4E20 )
      v49 = 20000;
    else
      v49 = v8;
    if ( (~v10 & 0x6000) == 0 )
      v8 = v49;
  }
LABEL_86:
  if ( v9 >= v8 )
    v9 = v8;
  *(_DWORD *)(a5 + 8) = v9;
  v50 = a4[21] | a3[21];
  *(_DWORD *)(a5 + 84) = v50;
  if ( (*((_BYTE *)a3 + 85) & 8) != 0 && (*((_BYTE *)a4 + 85) & 8) != 0 )
    v51 = v50 | 0x800;
  else
    v51 = v50 & 0xFFFFF7FF;
  v52 = v6 - v5;
  *(_DWORD *)(a5 + 84) = v51;
  if ( v9 > v6 - v5 )
    *(_DWORD *)(a5 + 8) = v52;
  v53 = a3[4];
  if ( v53 >= a4[4] )
    v53 = a4[4];
  *(_DWORD *)(a5 + 16) = v53;
  v54 = a3[3];
  if ( v54 >= a4[3] )
    v54 = a4[3];
  *(_DWORD *)(a5 + 12) = v54;
  v55 = a3[22];
  if ( v55 <= a4[22] )
    v55 = a4[22];
  *(_DWORD *)(a5 + 88) = v55;
  v56 = *((_BYTE *)a4 + 92);
  if ( *((_BYTE *)a3 + 92) != 1 )
  {
    if ( !*((_BYTE *)a4 + 92) )
      goto LABEL_125;
    v71 = (__int64 *)(a4 + 5);
LABEL_124:
    v72 = v71[2];
    v73 = *v71;
    v74 = v71[1];
    *(_QWORD *)(a5 + 44) = v71[3];
    *(_QWORD *)(a5 + 36) = v72;
    *(_QWORD *)(a5 + 28) = v74;
    *(_QWORD *)(a5 + 20) = v73;
    v76 = v71[6];
    v75 = v71[7];
    v78 = v71[4];
    v77 = v71[5];
    *(_QWORD *)(a5 + 76) = v75;
    *(_QWORD *)(a5 + 60) = v77;
    v56 = 1;
    *(_QWORD *)(a5 + 68) = v76;
    *(_QWORD *)(a5 + 52) = v78;
    goto LABEL_125;
  }
  if ( !*((_BYTE *)a4 + 92) )
  {
    v71 = (__int64 *)(a3 + 5);
    goto LABEL_124;
  }
  v57 = 0;
  do
  {
    v58 = &a3[v57];
    v59 = &a4[v57];
    v60 = a5 + v57 * 4;
    v61 = LOWORD(a3[v57 + 5]);
    v62 = LOWORD(a4[v57 + 5]);
    v57 += 2;
    if ( v61 <= v62 )
      LOWORD(v61) = v62;
    *(_WORD *)(v60 + 20) = v61;
    v63 = *((unsigned __int16 *)v58 + 11);
    if ( v63 <= *((unsigned __int16 *)v59 + 11) )
      LOWORD(v63) = *((_WORD *)v59 + 11);
    *(_WORD *)(v60 + 22) = v63;
    v64 = *((unsigned __int16 *)v58 + 12);
    if ( v64 >= *((unsigned __int16 *)v59 + 12) )
      LOWORD(v64) = *((_WORD *)v59 + 12);
    *(_WORD *)(v60 + 24) = v64;
    v65 = *((unsigned __int8 *)v58 + 26);
    if ( v65 <= *((unsigned __int8 *)v59 + 26) )
      LOBYTE(v65) = *((_BYTE *)v59 + 26);
    *(_BYTE *)(v60 + 26) = v65;
    v66 = *((unsigned __int16 *)v58 + 26);
    if ( v66 <= *((unsigned __int16 *)v59 + 26) )
      LOWORD(v66) = *((_WORD *)v59 + 26);
    *(_WORD *)(v60 + 52) = v66;
    v67 = *((unsigned __int16 *)v58 + 27);
    if ( v67 <= *((unsigned __int16 *)v59 + 27) )
      LOWORD(v67) = *((_WORD *)v59 + 27);
    *(_WORD *)(v60 + 54) = v67;
    v68 = *((unsigned __int16 *)v58 + 28);
    if ( v68 >= *((unsigned __int16 *)v59 + 28) )
      LOWORD(v68) = *((_WORD *)v59 + 28);
    *(_WORD *)(v60 + 56) = v68;
    v69 = *((unsigned __int8 *)v58 + 58);
    v70 = *((unsigned __int8 *)v59 + 58);
    if ( v69 <= v70 )
      LOBYTE(v69) = v70;
    *(_BYTE *)(v60 + 58) = v69;
  }
  while ( v57 != 8 );
  v56 = 1;
LABEL_125:
  result = 4294967274LL;
  *(_BYTE *)(a5 + 92) = v56;
  if ( v5 && v6 > v5 )
  {
    if ( *(_DWORD *)(a5 + 8) > v52 )
      return 4294967274LL;
    else
      return 0;
  }
  return result;
}
