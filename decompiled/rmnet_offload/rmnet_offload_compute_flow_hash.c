__int64 __fastcall rmnet_offload_compute_flow_hash(
        __int64 a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7)
{
  int v7; // w9
  int v8; // w11
  int v9; // w12
  int v10; // w8
  int v11; // w15
  __int64 v12; // x13
  char *v13; // x14
  __int64 v14; // x15
  int v15; // w16
  __int128 *v16; // x13
  __int64 *v17; // x10
  int v18; // w8
  int v19; // w15
  int v20; // w10
  int v21; // w16
  int v22; // w9
  int v23; // w17
  int v24; // w9
  int v25; // w15
  int v26; // w17
  int v27; // w16
  int v28; // w15
  int v29; // w9
  int v30; // w1
  int v31; // w17
  int v32; // w15
  int v33; // w17
  int v34; // w12
  int v35; // w13
  __int64 result; // x0
  int v37; // w12
  int v38; // w12
  int v39; // w13
  int v40; // w16
  int v41; // w12
  int v42; // w16
  int v43; // w15
  int v44; // w12
  int v45; // w15
  int v46; // w13
  int v47; // w12
  int v48; // w13
  int v49; // w16
  int v50; // w12
  int v51; // w16
  int v52; // w13
  int v53; // w0
  int v54; // w12
  int v55; // w13
  int v56; // w16
  int v57; // w12
  int v58; // w16
  int v59; // w15
  int v60; // w12
  int v61; // w15
  int v62; // w13
  int v63; // w12
  int v64; // w13
  int v65; // w16
  int v66; // w12
  int v67; // w16
  unsigned int v68; // w15
  char *v69; // x15
  unsigned int v70; // w14
  char *v71; // x8
  unsigned __int64 v72; // t2
  int v73; // w8
  int v74; // w9
  int v75; // w10
  int v76; // w8
  __int64 v77; // [xsp+8h] [xbp-38h] BYREF
  __int64 v78; // [xsp+10h] [xbp-30h] BYREF
  __int128 v79; // [xsp+18h] [xbp-28h] BYREF
  __int64 v80; // [xsp+28h] [xbp-18h] BYREF
  int v81; // [xsp+30h] [xbp-10h] BYREF
  __int64 v82; // [xsp+38h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(unsigned __int8 *)(a1 + 57);
  if ( v7 == 17 || v7 == 6 )
  {
    v8 = *(unsigned __int16 *)(a1 + 8);
    v9 = *(unsigned __int16 *)(a1 + 10);
  }
  else
  {
    v9 = 0;
    v8 = 0;
  }
  v10 = *(unsigned __int8 *)(a1 + 56);
  v81 = 0;
  v80 = 0;
  v78 = 0;
  v79 = 0u;
  v77 = 0;
  if ( v10 == 4 )
  {
    v11 = *(_DWORD *)(a1 + 12);
    v16 = &v79;
    v13 = (char *)&v78 + 4;
    LODWORD(v77) = *(_DWORD *)(a1 + 28);
    HIDWORD(v77) = v11;
    v17 = &v78;
    v18 = 5;
  }
  else
  {
    v12 = *(_QWORD *)(a1 + 36);
    v13 = (char *)&v80 + 4;
    v14 = *(_QWORD *)(a1 + 12);
    v15 = *(_DWORD *)(a1 + 20);
    v77 = *(_QWORD *)(a1 + 28);
    v78 = v12;
    v16 = (__int128 *)&v81;
    v17 = &v80;
    v18 = 11;
    *(_QWORD *)((char *)&v79 + 4) = v14;
    HIDWORD(v79) = v15;
  }
  *(_DWORD *)v17 = v7;
  v19 = v77;
  *(_DWORD *)v13 = v9;
  v21 = HIDWORD(v77);
  v20 = v78;
  v22 = 4 * v18 - 559038737;
  *(_DWORD *)v16 = v8;
  v23 = v20 + v22;
  v24 = v21 + v22;
  v25 = (v19 - v20) ^ __ROR4__(v23, 28);
  v26 = v23 + v24;
  v27 = (v24 - v25) ^ __ROR4__(v25, 26);
  v28 = v25 + v26;
  v29 = (unsigned __int8)(v18 - 4);
  v30 = (v26 - v27) ^ __ROR4__(v27, 24);
  v31 = v28 - v30;
  v32 = v27 + v28;
  v33 = v31 ^ __ROR4__(v30, 16);
  v34 = (v32 - v33) ^ __ROR4__(v33, 13);
  v35 = v33 + v30 + v32;
  result = (unsigned int)(v30 + v32 - v34) ^ __ROR4__(v34, 28);
  v37 = v34 + v35;
  if ( (unsigned int)(v18 - 7) > 0xFFFFFFFB )
  {
    v69 = (char *)&v78 + 4;
  }
  else
  {
    v38 = v79 + v37;
    v39 = (HIDWORD(v78) + v35 - (DWORD1(v79) + result)) ^ __ROR4__(DWORD1(v79) + result, 28);
    v40 = v38 - v39;
    v41 = DWORD1(v79) + result + v38;
    v42 = v40 ^ __ROR4__(v39, 26);
    v43 = v41 - v42;
    v44 = v39 + v41;
    v45 = v43 ^ __ROR4__(v42, 24);
    v46 = v44 - v45;
    v47 = v42 + v44;
    v48 = v46 ^ __ROR4__(v45, 16);
    v49 = v47 - v48;
    v50 = v45 + v47;
    v51 = v49 ^ __ROR4__(v48, 13);
    v52 = v48 + v50;
    v53 = (v50 - v51) ^ __ROR4__(v51, 28);
    v54 = HIDWORD(v79) + v51 + v52;
    v55 = (DWORD2(v79) + v52 - (v80 + v53)) ^ __ROR4__(v80 + v53, 28);
    v56 = v54 - v55;
    v57 = v80 + v53 + v54;
    v58 = v56 ^ __ROR4__(v55, 26);
    v59 = v57 - v58;
    v60 = v55 + v57;
    v61 = v59 ^ __ROR4__(v58, 24);
    v62 = v60 - v61;
    v63 = v58 + v60;
    v64 = v62 ^ __ROR4__(v61, 16);
    v65 = v63 - v64;
    v66 = v61 + v63;
    v67 = v65 ^ __ROR4__(v64, 13);
    v35 = v64 + v66;
    v68 = v66 - v67;
    v37 = v67 + v35;
    result = v68 ^ __ROR4__(v67, 28);
    v69 = (char *)&v80 + 4;
  }
  v70 = (unsigned __int8)(v18 - 4) % 3u + 4;
  if ( !((unsigned __int8)(v18 - 4) % 3u) )
    goto LABEL_17;
  v71 = (char *)&v77 + 12 * ((unsigned __int8)(v18 - 4) / 3LL);
  if ( v70 == 5 )
  {
LABEL_16:
    v37 += *((_DWORD *)v71 + 4);
LABEL_17:
    HIDWORD(v72) = v37;
    LODWORD(v72) = v37;
    v73 = (result ^ v37) - (v72 >> 18);
    HIDWORD(v72) = v73;
    LODWORD(v72) = v73;
    v74 = ((*(_DWORD *)v69 + v35) ^ v73) - (v72 >> 21);
    HIDWORD(v72) = v74;
    LODWORD(v72) = v74;
    v75 = (v74 ^ v37) - (v72 >> 7);
    HIDWORD(v72) = v75;
    LODWORD(v72) = v75;
    v76 = (v75 ^ v73) - (v72 >> 16);
    HIDWORD(v72) = v76;
    LODWORD(v72) = v76;
    HIDWORD(v72) = (v76 ^ v74) - (v72 >> 28);
    LODWORD(v72) = HIDWORD(v72);
    HIDWORD(v72) = (HIDWORD(v72) ^ v75) - (v72 >> 18);
    LODWORD(v72) = HIDWORD(v72);
    result = (HIDWORD(v72) ^ v76) - (unsigned int)(v72 >> 8);
    goto LABEL_18;
  }
  if ( v70 != 6 )
  {
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)(v29 - 6) >= 3 )
  {
    LODWORD(result) = *((_DWORD *)v71 + 5) + result;
    goto LABEL_16;
  }
  __break(1u);
  return rmnet_offload_state_get(result, a2, a3, a4, a5, a6, a7, MEMORY[0xFFFFFFFFFFF61AC0]);
}
