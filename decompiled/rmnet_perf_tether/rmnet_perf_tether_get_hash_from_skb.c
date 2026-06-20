__int64 __fastcall rmnet_perf_tether_get_hash_from_skb(__int64 a1, _DWORD *a2, int a3, int a4)
{
  int v4; // w9
  __int64 v5; // x10
  unsigned __int16 *v6; // x9
  __int64 v7; // x9
  unsigned __int16 *v8; // x11
  __int64 v9; // x14
  __int64 v10; // x10
  __int64 v11; // x11
  unsigned int v12; // w14
  __int128 *v13; // x12
  char *v14; // x13
  unsigned int v15; // w8
  int v16; // w10
  int v17; // w14
  int v18; // w8
  __int64 v19; // x12
  __int64 v20; // x14
  __int64 v21; // x9
  unsigned __int64 *v22; // x10
  __int64 *v23; // x12
  int v24; // w9
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x13
  __int64 v27; // x13
  __int64 v28; // x15
  int v29; // w15
  int v30; // w11
  int v31; // w10
  int v32; // w16
  int v33; // w9
  int v34; // w17
  int v35; // w9
  int v36; // w15
  int v37; // w17
  int v38; // w16
  int v39; // w15
  int v40; // w9
  int v41; // w2
  int v42; // w17
  int v43; // w15
  int v44; // w17
  int v45; // w12
  int v46; // w13
  __int64 result; // x0
  int v48; // w12
  int v49; // w12
  int v50; // w13
  int v51; // w16
  int v52; // w12
  int v53; // w16
  int v54; // w15
  int v55; // w12
  int v56; // w15
  int v57; // w13
  int v58; // w12
  int v59; // w13
  int v60; // w16
  int v61; // w12
  int v62; // w16
  int v63; // w13
  int v64; // w0
  int v65; // w12
  int v66; // w13
  int v67; // w16
  int v68; // w12
  int v69; // w16
  int v70; // w15
  int v71; // w12
  int v72; // w15
  int v73; // w13
  int v74; // w12
  int v75; // w13
  int v76; // w16
  int v77; // w12
  int v78; // w16
  unsigned int v79; // w15
  char *v80; // x15
  unsigned int v81; // w14
  char *v82; // x8
  unsigned __int64 v83; // t2
  int v84; // w8
  int v85; // w9
  int v86; // w10
  int v87; // w8
  unsigned __int64 v88; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v89; // [xsp+10h] [xbp-30h] BYREF
  __int128 v90; // [xsp+18h] [xbp-28h] BYREF
  __int64 v91; // [xsp+28h] [xbp-18h] BYREF
  int v92; // [xsp+30h] [xbp-10h] BYREF
  __int64 v93; // [xsp+38h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int16 *)(a1 + 180);
  v92 = 0;
  v91 = 0;
  v89 = 0;
  v90 = 0u;
  v88 = 0;
  if ( v4 != 56710 )
  {
    if ( v4 != 8 )
      goto LABEL_31;
    v5 = *(_QWORD *)(a1 + 216);
    v6 = (unsigned __int16 *)(v5 + *(unsigned __int16 *)(a1 + 182));
    if ( (v6[6] & 0x200) == 0 )
      goto LABEL_31;
    if ( a3 )
    {
      if ( (v6[6] & 0x1000) == 0 )
        goto LABEL_31;
      goto LABEL_12;
    }
    if ( (v6[6] & 0x1000) == 0 )
    {
LABEL_12:
      if ( a4 )
        v9 = 16;
      else
        v9 = 12;
      v10 = v5 + *(unsigned __int16 *)(a1 + 184);
      if ( a4 )
        v11 = 12;
      else
        v11 = 16;
      v12 = *(_DWORD *)(v10 + v9);
      v13 = &v90;
      v14 = (char *)&v89 + 4;
      v15 = *(_DWORD *)(v10 + v11);
      v16 = *(unsigned __int8 *)(v10 + 9);
      v88 = __PAIR64__(v15, v12);
      v17 = v6[a4 != 0];
      if ( a4 )
        v8 = v6;
      else
        v8 = v6 + 1;
      LODWORD(v89) = v16;
      v18 = 5;
      goto LABEL_29;
    }
LABEL_31:
    result = 0;
    *a2 = 0;
LABEL_32:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v7 = *(_QWORD *)(a1 + 216);
  v8 = (unsigned __int16 *)(v7 + *(unsigned __int16 *)(a1 + 182));
  if ( (v8[6] & 0x200) == 0 )
    goto LABEL_31;
  if ( a3 )
  {
    if ( (v8[6] & 0x1000) == 0 )
      goto LABEL_31;
  }
  else if ( (v8[6] & 0x1000) != 0 )
  {
    goto LABEL_31;
  }
  v19 = 24;
  if ( a4 )
    v20 = 24;
  else
    v20 = 8;
  v21 = v7 + *(unsigned __int16 *)(a1 + 184);
  if ( a4 )
    v19 = 8;
  v22 = (unsigned __int64 *)(v21 + v20);
  v23 = (__int64 *)(v21 + v19);
  v24 = *(unsigned __int8 *)(v21 + 6);
  v26 = *v22;
  v25 = v22[1];
  v17 = v8[1];
  v88 = v26;
  v89 = v25;
  v28 = *v23;
  v27 = v23[1];
  v13 = (__int128 *)&v92;
  HIDWORD(v90) = v27;
  v14 = (char *)&v91 + 4;
  v18 = 11;
  *(_QWORD *)((char *)&v90 + 4) = v28;
  LODWORD(v91) = v24;
LABEL_29:
  v29 = v88;
  v30 = *v8;
  *(_DWORD *)v14 = v17;
  v32 = HIDWORD(v88);
  v31 = v89;
  v33 = 4 * v18 - 559038737;
  *(_DWORD *)v13 = v30;
  *a2 = 1;
  v34 = v31 + v33;
  v35 = v32 + v33;
  v36 = (v29 - v31) ^ __ROR4__(v34, 28);
  v37 = v34 + v35;
  v38 = (v35 - v36) ^ __ROR4__(v36, 26);
  v39 = v36 + v37;
  v40 = (unsigned __int8)(v18 - 4);
  v41 = (v37 - v38) ^ __ROR4__(v38, 24);
  v42 = v39 - v41;
  v43 = v38 + v39;
  v44 = v42 ^ __ROR4__(v41, 16);
  v45 = (v43 - v44) ^ __ROR4__(v44, 13);
  v46 = v44 + v41 + v43;
  result = (unsigned int)(v41 + v43 - v45) ^ __ROR4__(v45, 28);
  v48 = v45 + v46;
  if ( (unsigned int)(v18 - 7) > 0xFFFFFFFB )
  {
    v80 = (char *)&v89 + 4;
  }
  else
  {
    v49 = v90 + v48;
    v50 = (HIDWORD(v89) + v46 - (DWORD1(v90) + result)) ^ __ROR4__(DWORD1(v90) + result, 28);
    v51 = v49 - v50;
    v52 = DWORD1(v90) + result + v49;
    v53 = v51 ^ __ROR4__(v50, 26);
    v54 = v52 - v53;
    v55 = v50 + v52;
    v56 = v54 ^ __ROR4__(v53, 24);
    v57 = v55 - v56;
    v58 = v53 + v55;
    v59 = v57 ^ __ROR4__(v56, 16);
    v60 = v58 - v59;
    v61 = v56 + v58;
    v62 = v60 ^ __ROR4__(v59, 13);
    v63 = v59 + v61;
    v64 = (v61 - v62) ^ __ROR4__(v62, 28);
    v65 = HIDWORD(v90) + v62 + v63;
    v66 = (DWORD2(v90) + v63 - (v91 + v64)) ^ __ROR4__(v91 + v64, 28);
    v67 = v65 - v66;
    v68 = v91 + v64 + v65;
    v69 = v67 ^ __ROR4__(v66, 26);
    v70 = v68 - v69;
    v71 = v66 + v68;
    v72 = v70 ^ __ROR4__(v69, 24);
    v73 = v71 - v72;
    v74 = v69 + v71;
    v75 = v73 ^ __ROR4__(v72, 16);
    v76 = v74 - v75;
    v77 = v72 + v74;
    v78 = v76 ^ __ROR4__(v75, 13);
    v46 = v75 + v77;
    v79 = v77 - v78;
    v48 = v78 + v46;
    result = v79 ^ __ROR4__(v78, 28);
    v80 = (char *)&v91 + 4;
  }
  v81 = (unsigned __int8)(v18 - 4) % 3u + 4;
  if ( !((unsigned __int8)(v18 - 4) % 3u) )
    goto LABEL_40;
  v82 = (char *)&v88 + 12 * ((unsigned __int8)(v18 - 4) / 3LL);
  if ( v81 == 5 )
  {
LABEL_39:
    v48 += *((_DWORD *)v82 + 4);
LABEL_40:
    HIDWORD(v83) = v48;
    LODWORD(v83) = v48;
    v84 = (result ^ v48) - (v83 >> 18);
    HIDWORD(v83) = v84;
    LODWORD(v83) = v84;
    v85 = ((*(_DWORD *)v80 + v46) ^ v84) - (v83 >> 21);
    HIDWORD(v83) = v85;
    LODWORD(v83) = v85;
    v86 = (v85 ^ v48) - (v83 >> 7);
    HIDWORD(v83) = v86;
    LODWORD(v83) = v86;
    v87 = (v86 ^ v84) - (v83 >> 16);
    HIDWORD(v83) = v87;
    LODWORD(v83) = v87;
    HIDWORD(v83) = (v87 ^ v85) - (v83 >> 28);
    LODWORD(v83) = HIDWORD(v83);
    HIDWORD(v83) = (HIDWORD(v83) ^ v86) - (v83 >> 18);
    LODWORD(v83) = HIDWORD(v83);
    result = (HIDWORD(v83) ^ v87) - (unsigned int)(v83 >> 8);
    goto LABEL_32;
  }
  if ( v81 != 6 )
    goto LABEL_32;
  if ( (unsigned int)(v40 - 6) >= 3 )
  {
    LODWORD(result) = *((_DWORD *)v82 + 5) + result;
    goto LABEL_39;
  }
  __break(1u);
  return rmnet_perf_tether_egress(result);
}
