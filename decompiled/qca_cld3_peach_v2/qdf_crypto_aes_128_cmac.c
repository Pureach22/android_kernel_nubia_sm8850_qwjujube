__int64 __fastcall qdf_crypto_aes_128_cmac(__int64 a1, __int64 a2, unsigned __int16 a3, _QWORD *a4)
{
  int v8; // w0
  unsigned int v9; // w22
  unsigned int v10; // w19
  unsigned int v11; // w11
  unsigned __int64 v12; // t2
  unsigned int v13; // w12
  int v14; // w10
  int v15; // w13
  int v16; // w14
  int v17; // w16
  int v18; // w0
  int v19; // w17
  int v20; // w2
  int v21; // w25
  unsigned int v22; // w15
  int v23; // w1
  int v24; // w3
  int v25; // w4
  int v26; // w6
  unsigned __int64 v27; // t2
  char v28; // w9
  int v29; // w7
  unsigned int v30; // w8
  __int64 v31; // x9
  char v32; // w30
  char v33; // w21
  char v34; // w6
  char v35; // w24
  char v36; // w7
  char v37; // w22
  char v38; // w25
  char v39; // w26
  char v40; // w27
  char v41; // w28
  char *v42; // x10
  unsigned int v43; // w19
  unsigned int v44; // w22
  __int64 v45; // x5
  int v46; // w10
  unsigned __int64 v47; // t2
  int v48; // w11
  int v49; // w15
  int v50; // w12
  int v51; // w13
  int v52; // w14
  int v53; // w16
  int v54; // w17
  int v55; // w0
  int v56; // w1
  int v57; // w2
  int v58; // w3
  int v59; // w4
  int v60; // w6
  int v61; // w7
  unsigned int v62; // w22
  char v63; // w10
  char v64; // w19
  __int64 v65; // x21
  char *v66; // x20
  char v67; // w13
  char v68; // w9
  char v69; // w9
  char v70; // w10
  char v71; // w12
  char v72; // w8
  char v73; // w10
  char v74; // w14
  char v75; // w8
  char v76; // w10
  char v77; // w16
  char v78; // w8
  char v79; // w10
  char v80; // w8
  char v81; // w10
  char v82; // w8
  char v83; // w10
  char v84; // w8
  char v85; // w10
  char v86; // w9
  char v87; // w8
  char v88; // w5
  char v89; // w4
  char v90; // w3
  char v91; // w2
  char v92; // w1
  char v93; // w0
  char v94; // w17
  char v95; // w16
  char v96; // w15
  char v97; // w14
  char v98; // w13
  char v99; // w12
  char v100; // w11
  char v101; // w10
  char v102; // w9
  char v103; // w8
  char v105; // [xsp+Ch] [xbp-264h]
  char v106; // [xsp+10h] [xbp-260h]
  char v107; // [xsp+14h] [xbp-25Ch]
  char v108; // [xsp+18h] [xbp-258h]
  char v109; // [xsp+1Ch] [xbp-254h]
  char v110; // [xsp+20h] [xbp-250h]
  char v111; // [xsp+24h] [xbp-24Ch]
  char v112; // [xsp+28h] [xbp-248h]
  char v113; // [xsp+2Ch] [xbp-244h]
  _QWORD *v114; // [xsp+30h] [xbp-240h]
  _BYTE s[484]; // [xsp+3Ch] [xbp-234h] BYREF
  __int64 v116; // [xsp+220h] [xbp-50h]
  __int64 v117; // [xsp+228h] [xbp-48h] BYREF
  __int64 v118; // [xsp+230h] [xbp-40h] BYREF
  __int64 v119; // [xsp+238h] [xbp-38h]
  _QWORD v120[2]; // [xsp+240h] [xbp-30h] BYREF
  __int64 v121; // [xsp+250h] [xbp-20h] BYREF
  __int64 v122; // [xsp+258h] [xbp-18h]
  __int64 v123; // [xsp+260h] [xbp-10h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v118 = 0;
  v119 = 0;
  v116 = 0;
  v117 = 0;
  memset(s, 0, sizeof(s));
  v8 = aes_expandkey(s, a1, 16);
  if ( v8 )
  {
    v9 = v8;
    qdf_trace_msg(56, 2, "%s: aes_expandkey failed (%d)", "qdf_crypto_aes_128_cmac", v8);
  }
  else
  {
    v114 = a4;
    v10 = a3 + 15;
    v121 = 0;
    v122 = 0;
    v120[0] = 0;
    v120[1] = 0;
    aes_encrypt(s, &v121, v120);
    HIDWORD(v12) = BYTE5(v122);
    LODWORD(v12) = BYTE6(v122) << 24;
    v11 = v12 >> 31;
    HIDWORD(v12) = BYTE4(v122);
    LODWORD(v12) = BYTE5(v122) << 24;
    v13 = v12 >> 31;
    HIDWORD(v12) = BYTE6(v122);
    LODWORD(v12) = HIBYTE(v122) << 24;
    v14 = v12 >> 31;
    HIDWORD(v12) = BYTE3(v122);
    LODWORD(v12) = BYTE4(v122) << 24;
    v15 = v12 >> 31;
    v16 = __PAIR64__(BYTE2(v122), BYTE3(v122) << 24) >> 31;
    HIDWORD(v12) = BYTE1(v122);
    LODWORD(v12) = BYTE2(v122) << 24;
    v17 = v12 >> 31;
    HIDWORD(v12) = HIBYTE(v121);
    LODWORD(v12) = (unsigned __int8)v122 << 24;
    v18 = v12 >> 31;
    v19 = __PAIR64__((unsigned __int8)v122, BYTE1(v122) << 24) >> 31;
    HIDWORD(v12) = BYTE5(v121);
    LODWORD(v12) = BYTE6(v121) << 24;
    v20 = v12 >> 31;
    HIDWORD(v12) = (char)v121;
    LODWORD(v12) = BYTE1(v121) << 24;
    v21 = v12 >> 31;
    v22 = (2 * HIBYTE(v122)) ^ 0xFFFFFF87;
    v23 = __PAIR64__(BYTE6(v121), HIBYTE(v121) << 24) >> 31;
    if ( (v121 & 0x80u) == 0LL )
      v22 = 2 * HIBYTE(v122);
    v24 = __PAIR64__(BYTE4(v121), BYTE5(v121) << 24) >> 31;
    v25 = __PAIR64__(BYTE3(v121), BYTE4(v121) << 24) >> 31;
    HIDWORD(v27) = BYTE2(v121);
    LODWORD(v27) = BYTE3(v121) << 24;
    v26 = v27 >> 31;
    v28 = (2 * v22) ^ 0x87;
    HIDWORD(v27) = BYTE1(v121);
    LODWORD(v27) = BYTE2(v121) << 24;
    v29 = v27 >> 31;
    if ( (v21 & 0x80u) == 0 )
      v28 = 2 * v22;
    if ( a3 )
      v30 = v10 >> 4;
    else
      v30 = 1;
    if ( !a3 || (a3 & 0xF) != 0 )
    {
      v43 = v14 << 24;
      v44 = v11 << 24;
      v45 = 0;
      HIDWORD(v47) = v14;
      LODWORD(v47) = v22 << 24;
      v46 = v47 >> 31;
      v48 = __PAIR64__(v11, v43) >> 31;
      HIDWORD(v47) = v15;
      LODWORD(v47) = v13 << 24;
      v49 = v47 >> 31;
      v50 = __PAIR64__(v13, v44) >> 31;
      HIDWORD(v47) = __PAIR64__(BYTE2(v122), BYTE3(v122) << 24) >> 31;
      LODWORD(v47) = v15 << 24;
      v51 = v47 >> 31;
      HIDWORD(v47) = v17;
      LODWORD(v47) = v16 << 24;
      v52 = v47 >> 31;
      HIDWORD(v47) = __PAIR64__((unsigned __int8)v122, BYTE1(v122) << 24) >> 31;
      LODWORD(v47) = v17 << 24;
      v53 = v47 >> 31;
      HIDWORD(v47) = v18;
      LODWORD(v47) = v19 << 24;
      v54 = v47 >> 31;
      HIDWORD(v47) = __PAIR64__(BYTE6(v121), HIBYTE(v121) << 24) >> 31;
      LODWORD(v47) = v18 << 24;
      v55 = v47 >> 31;
      HIDWORD(v47) = v20;
      LODWORD(v47) = v23 << 24;
      v56 = v47 >> 31;
      HIDWORD(v47) = __PAIR64__(BYTE4(v121), BYTE5(v121) << 24) >> 31;
      LODWORD(v47) = v20 << 24;
      v57 = v47 >> 31;
      HIDWORD(v47) = __PAIR64__(BYTE3(v121), BYTE4(v121) << 24) >> 31;
      LODWORD(v47) = v24 << 24;
      v58 = v47 >> 31;
      HIDWORD(v47) = v26;
      LODWORD(v47) = v25 << 24;
      v59 = v47 >> 31;
      HIDWORD(v47) = v29;
      LODWORD(v47) = v26 << 24;
      v60 = v47 >> 31;
      HIDWORD(v47) = v21;
      LODWORD(v47) = v29 << 24;
      v61 = v47 >> 31;
      v62 = a3 & 0xF;
      do
      {
        if ( (unsigned int)v45 < v62 )
        {
          *((_BYTE *)&v116 + v45) = *(_BYTE *)(a2 + 16 * v30 - 16 + v45);
        }
        else if ( v62 == (_DWORD)v45 )
        {
          *((_BYTE *)&v116 + v45) = 0x80;
        }
        else
        {
          *((_BYTE *)&v116 + v45) = 0;
        }
        ++v45;
      }
      while ( v45 != 16 );
      v32 = v116 ^ v61;
      v33 = BYTE2(v116) ^ v59;
      v36 = BYTE3(v116) ^ v58;
      v34 = BYTE1(v116) ^ v60;
      v113 = BYTE4(v116) ^ v57;
      v111 = BYTE6(v116) ^ v55;
      v112 = BYTE5(v116) ^ v56;
      v109 = v117 ^ v53;
      v110 = HIBYTE(v116) ^ v54;
      v37 = BYTE1(v117) ^ v52;
      v35 = BYTE2(v117) ^ v51;
      v39 = BYTE4(v117) ^ v50;
      v38 = BYTE3(v117) ^ v49;
      v40 = BYTE5(v117) ^ v48;
      v41 = BYTE6(v117) ^ v46;
      v42 = (char *)&v117 + 7;
    }
    else
    {
      v31 = a2 + ((unsigned __int16)v10 & 0xFFF0);
      v32 = *(_BYTE *)(v31 - 16) ^ v21;
      v33 = *(_BYTE *)(v31 - 14) ^ v26;
      v113 = *(_BYTE *)(v31 - 12) ^ v24;
      v34 = *(_BYTE *)(v31 - 15) ^ v29;
      v109 = *(_BYTE *)(v31 - 8) ^ v19;
      v110 = *(_BYTE *)(v31 - 9) ^ v18;
      v111 = *(_BYTE *)(v31 - 10) ^ v23;
      v112 = *(_BYTE *)(v31 - 11) ^ v20;
      v35 = *(_BYTE *)(v31 - 6) ^ v16;
      v36 = *(_BYTE *)(v31 - 13) ^ v25;
      v37 = *(_BYTE *)(v31 - 7) ^ v17;
      v38 = *(_BYTE *)(v31 - 5) ^ v15;
      v39 = *(_BYTE *)(v31 - 4) ^ v13;
      v40 = *(_BYTE *)(v31 - 3) ^ v11;
      v41 = *(_BYTE *)(v31 - 2) ^ v14;
      v42 = (char *)(v31 - 1);
      v28 = v22;
    }
    v63 = *v42;
    v121 = 0;
    v122 = 0;
    v64 = v63 ^ v28;
    if ( v30 < 2 )
    {
      v103 = 0;
      v102 = 0;
      v101 = 0;
      v100 = 0;
      v99 = 0;
      v98 = 0;
      v97 = 0;
      v96 = 0;
      v95 = 0;
      v94 = 0;
      v93 = 0;
      v92 = 0;
      v91 = 0;
      v90 = 0;
      v89 = 0;
      v88 = 0;
    }
    else
    {
      v105 = v36;
      v106 = v33;
      v65 = v30 - 1;
      v66 = (char *)(a2 + 7);
      v107 = v34;
      v108 = v32;
      do
      {
        v67 = *(v66 - 5);
        v68 = *(v66 - 6) ^ BYTE1(v121);
        LOBYTE(v118) = *(v66 - 7) ^ v121;
        BYTE1(v118) = v68;
        v69 = *(v66 - 4);
        BYTE2(v118) = v67 ^ BYTE2(v121);
        v70 = *(v66 - 3);
        BYTE3(v118) = v69 ^ BYTE3(v121);
        v71 = v66[4];
        v72 = v70 ^ BYTE4(v121);
        v73 = *(v66 - 2);
        BYTE4(v118) = v72;
        v74 = v66[5];
        v75 = v73 ^ BYTE5(v121);
        v76 = *(v66 - 1);
        BYTE5(v118) = v75;
        v77 = v66[6];
        v78 = v76 ^ BYTE6(v121);
        v79 = *v66;
        BYTE6(v118) = v78;
        v80 = v79 ^ HIBYTE(v121);
        v81 = v66[1];
        HIBYTE(v118) = v80;
        v82 = v81 ^ v122;
        v83 = v66[2];
        LOBYTE(v119) = v82;
        v84 = v83 ^ BYTE1(v122);
        v85 = v66[3];
        BYTE1(v119) = v84;
        BYTE4(v119) = v74 ^ BYTE4(v122);
        BYTE2(v119) = v85 ^ BYTE2(v122);
        BYTE3(v119) = v71 ^ BYTE3(v122);
        v86 = v66[7] ^ BYTE6(v122);
        v87 = v66[8] ^ HIBYTE(v122);
        BYTE5(v119) = v77 ^ BYTE5(v122);
        BYTE6(v119) = v86;
        HIBYTE(v119) = v87;
        aes_encrypt(s, &v121, &v118);
        --v65;
        v66 += 16;
      }
      while ( v65 );
      v34 = v107;
      v32 = v108;
      v36 = v105;
      v33 = v106;
      v88 = v121;
      v89 = BYTE1(v121);
      v90 = BYTE2(v121);
      v91 = BYTE3(v121);
      v92 = BYTE4(v121);
      v93 = BYTE5(v121);
      v94 = BYTE6(v121);
      v95 = HIBYTE(v121);
      v96 = v122;
      v97 = BYTE1(v122);
      v98 = BYTE2(v122);
      v99 = BYTE3(v122);
      v100 = BYTE4(v122);
      v101 = BYTE5(v122);
      v102 = BYTE6(v122);
      v103 = HIBYTE(v122);
    }
    BYTE3(v118) = v91 ^ v36;
    BYTE4(v118) = v92 ^ v113;
    LOBYTE(v118) = v88 ^ v32;
    BYTE1(v118) = v89 ^ v34;
    BYTE5(v118) = v93 ^ v112;
    BYTE2(v118) = v90 ^ v33;
    BYTE1(v119) = v97 ^ v37;
    BYTE6(v118) = v94 ^ v111;
    BYTE2(v119) = v98 ^ v35;
    BYTE3(v119) = v99 ^ v38;
    HIBYTE(v118) = v95 ^ v110;
    BYTE4(v119) = v100 ^ v39;
    BYTE5(v119) = v101 ^ v40;
    LOBYTE(v119) = v96 ^ v109;
    BYTE6(v119) = v102 ^ v41;
    HIBYTE(v119) = v103 ^ v64;
    aes_encrypt(s, &v121, &v118);
    memset(s, 0, sizeof(s));
    v9 = 0;
    *v114 = v121;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
