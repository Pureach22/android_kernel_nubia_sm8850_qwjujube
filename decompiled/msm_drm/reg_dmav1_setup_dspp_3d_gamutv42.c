__int64 __fastcall reg_dmav1_setup_dspp_3d_gamutv42(unsigned int *a1, _QWORD *a2)
{
  __int64 v2; // x2
  unsigned int v3; // w4
  __int64 v4; // x19
  int v5; // w9
  unsigned int v6; // w23
  unsigned int v7; // w24
  unsigned int v8; // w25
  unsigned int v9; // w26
  unsigned int v10; // w27
  unsigned int v11; // w28
  unsigned int v12; // w20
  unsigned int v13; // w21
  unsigned int v14; // w22
  __int64 result; // x0
  unsigned int v16; // w10
  unsigned int v17; // w12
  unsigned int v18; // w13
  unsigned int v19; // w14
  int v20; // w11
  int v21; // w12
  unsigned int v22; // w10
  unsigned int v23; // w13
  unsigned int v24; // w14
  unsigned int v25; // w15
  int v26; // w11
  int v27; // w12
  unsigned int v28; // w10
  unsigned int v29; // w13
  unsigned int v30; // w14
  unsigned int v31; // w15
  int v32; // w11
  int v33; // w12
  unsigned int v34; // w13
  unsigned int v35; // w14
  unsigned int v36; // w15
  unsigned int v37; // w16
  unsigned int v38; // w11
  unsigned int v39; // w12
  unsigned int v40; // w11
  unsigned int v41; // w12
  unsigned int v42; // w14
  unsigned int v43; // w15
  int v44; // w13
  int v45; // w11
  unsigned int v46; // w14
  unsigned int v47; // w15
  int v48; // w13
  unsigned int v49; // w14
  unsigned int v50; // [xsp+4h] [xbp-9Ch]
  __int64 v51; // [xsp+8h] [xbp-98h]
  unsigned __int64 v52; // [xsp+10h] [xbp-90h]
  __int64 v53; // [xsp+18h] [xbp-88h]
  unsigned __int64 v54; // [xsp+20h] [xbp-80h]
  __int64 v55; // [xsp+28h] [xbp-78h]
  __int64 v56; // [xsp+30h] [xbp-70h]
  unsigned __int64 v57; // [xsp+38h] [xbp-68h]
  __int64 v58; // [xsp+40h] [xbp-60h]
  unsigned __int64 v59; // [xsp+48h] [xbp-58h]
  unsigned int v60; // [xsp+50h] [xbp-50h]
  unsigned int v61; // [xsp+54h] [xbp-4Ch]
  unsigned __int64 v62; // [xsp+58h] [xbp-48h]
  unsigned __int64 v63; // [xsp+60h] [xbp-40h]
  unsigned __int64 v64; // [xsp+68h] [xbp-38h]
  unsigned __int64 v65; // [xsp+70h] [xbp-30h]
  unsigned __int64 v66; // [xsp+78h] [xbp-28h]
  unsigned __int64 v67; // [xsp+80h] [xbp-20h]
  unsigned __int64 v68; // [xsp+88h] [xbp-18h]
  __int64 v69; // [xsp+90h] [xbp-10h]
  __int64 v70; // [xsp+98h] [xbp-8h]

  if ( !a1 || !a2 )
    return _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
  v2 = a1[16];
  v3 = a1[374];
  if ( !a2[2] || (unsigned int)v2 > 4 || v3 >= 2 )
    return _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v2, 1, v3);
  if ( &dspp_buf[2 * v2] == (unsigned __int64 *)-80LL )
    return _drm_err("invalid dma_buf\n");
  v4 = *a2;
  if ( !*a2 )
    return reg_dmav1_setup_dspp_3d_gamutv4_common((__int64)a1, a2, 64);
  v5 = *((_DWORD *)a2 + 2);
  if ( v5 != 39536 )
    return _drm_err("invalid payload len actual %d expected %zd", v5, 0x9A70u);
  if ( (*(_BYTE *)v4 & 1) != 0 )
  {
    v7 = *(_DWORD *)(v4 + 172);
    v8 = *(_DWORD *)(v4 + 176);
    LODWORD(v70) = *(_DWORD *)(v4 + 16);
    HIDWORD(v70) = *(_DWORD *)(v4 + 12);
    LODWORD(v69) = *(_DWORD *)(v4 + 24);
    HIDWORD(v69) = *(_DWORD *)(v4 + 20);
    *(_DWORD *)(v4 + 12) = WORD2(v70) & 0xFFF | (HIDWORD(v70) >> 12 << 15);
    *(_DWORD *)(v4 + 16) = v70 & 0xFFF | ((unsigned int)v70 >> 12 << 15);
    v16 = *(_DWORD *)(v4 + 28);
    v17 = *(_DWORD *)(v4 + 32);
    v18 = *(_DWORD *)(v4 + 36);
    v19 = *(_DWORD *)(v4 + 40);
    *(_DWORD *)(v4 + 20) = WORD2(v69) & 0xFFF | (HIDWORD(v69) >> 12 << 15);
    *(_DWORD *)(v4 + 24) = v69 & 0xFFF | ((unsigned int)v69 >> 12 << 15);
    v68 = __PAIR64__(v16, v17);
    v67 = __PAIR64__(v18, v19);
    v20 = v18 & 0xFFF | (v18 >> 12 << 15);
    *(_DWORD *)(v4 + 28) = v16 & 0xFFF | (v16 >> 12 << 15);
    *(_DWORD *)(v4 + 32) = v17 & 0xFFF | (v17 >> 12 << 15);
    v21 = v19 & 0xFFF | (v19 >> 12 << 15);
    v22 = *(_DWORD *)(v4 + 44);
    v23 = *(_DWORD *)(v4 + 48);
    v24 = *(_DWORD *)(v4 + 52);
    v25 = *(_DWORD *)(v4 + 56);
    *(_DWORD *)(v4 + 36) = v20;
    *(_DWORD *)(v4 + 40) = v21;
    v66 = __PAIR64__(v22, v23);
    v65 = __PAIR64__(v24, v25);
    v26 = v24 & 0xFFF | (v24 >> 12 << 15);
    *(_DWORD *)(v4 + 44) = v22 & 0xFFF | (v22 >> 12 << 15);
    *(_DWORD *)(v4 + 48) = v23 & 0xFFF | (v23 >> 12 << 15);
    v27 = v25 & 0xFFF | (v25 >> 12 << 15);
    v28 = *(_DWORD *)(v4 + 60);
    v29 = *(_DWORD *)(v4 + 64);
    v30 = *(_DWORD *)(v4 + 68);
    v31 = *(_DWORD *)(v4 + 72);
    *(_DWORD *)(v4 + 52) = v26;
    *(_DWORD *)(v4 + 56) = v27;
    v64 = __PAIR64__(v28, v29);
    v63 = __PAIR64__(v30, v31);
    v32 = v30 & 0xFFF | (v30 >> 12 << 15);
    v33 = v31 & 0xFFF | (v31 >> 12 << 15);
    *(_DWORD *)(v4 + 60) = v28 & 0xFFF | (v28 >> 12 << 15);
    *(_DWORD *)(v4 + 64) = v29 & 0xFFF | (v29 >> 12 << 15);
    v34 = *(_DWORD *)(v4 + 76);
    v35 = *(_DWORD *)(v4 + 80);
    v36 = *(_DWORD *)(v4 + 84);
    v37 = *(_DWORD *)(v4 + 88);
    *(_DWORD *)(v4 + 68) = v32;
    *(_DWORD *)(v4 + 72) = v33;
    v62 = __PAIR64__(v34, v35);
    v61 = v36;
    *(_DWORD *)(v4 + 76) = v34 & 0xFFF | (v34 >> 12 << 15);
    *(_DWORD *)(v4 + 80) = v35 & 0xFFF | (v35 >> 12 << 15);
    v38 = *(_DWORD *)(v4 + 92);
    v39 = *(_DWORD *)(v4 + 96);
    *(_DWORD *)(v4 + 84) = v36 & 0xFFF | (v36 >> 12 << 15);
    *(_DWORD *)(v4 + 88) = v37 & 0xFFF | (v37 >> 12 << 15);
    v60 = v37;
    HIDWORD(v58) = *(_DWORD *)(v4 + 100);
    v59 = __PAIR64__(v38, v39);
    LODWORD(v58) = *(_DWORD *)(v4 + 104);
    *(_DWORD *)(v4 + 92) = v38 & 0xFFF | (v38 >> 12 << 15);
    *(_DWORD *)(v4 + 96) = v39 & 0xFFF | (v39 >> 12 << 15);
    v40 = *(_DWORD *)(v4 + 108);
    v41 = *(_DWORD *)(v4 + 112);
    *(_DWORD *)(v4 + 100) = WORD2(v58) & 0xFFF | (HIDWORD(v58) >> 12 << 15);
    *(_DWORD *)(v4 + 104) = v58 & 0xFFF | ((unsigned int)v58 >> 12 << 15);
    v57 = __PAIR64__(v40, v41);
    LODWORD(v56) = *(_DWORD *)(v4 + 120);
    HIDWORD(v56) = *(_DWORD *)(v4 + 116);
    *(_DWORD *)(v4 + 108) = v40 & 0xFFF | (v40 >> 12 << 15);
    *(_DWORD *)(v4 + 112) = v41 & 0xFFF | (v41 >> 12 << 15);
    v42 = *(_DWORD *)(v4 + 132);
    v43 = *(_DWORD *)(v4 + 136);
    *(_DWORD *)(v4 + 116) = WORD2(v56) & 0xFFF | (HIDWORD(v56) >> 12 << 15);
    *(_DWORD *)(v4 + 120) = v56 & 0xFFF | ((unsigned int)v56 >> 12 << 15);
    v54 = __PAIR64__(v42, v43);
    v9 = *(_DWORD *)(v4 + 180);
    v10 = *(_DWORD *)(v4 + 184);
    LODWORD(v55) = *(_DWORD *)(v4 + 128);
    HIDWORD(v55) = *(_DWORD *)(v4 + 124);
    v44 = v42 & 0xFFF | (v42 >> 12 << 15);
    v11 = *(_DWORD *)(v4 + 188);
    v12 = *(_DWORD *)(v4 + 192);
    *(_DWORD *)(v4 + 124) = WORD2(v55) & 0xFFF | (HIDWORD(v55) >> 12 << 15);
    *(_DWORD *)(v4 + 128) = v55 & 0xFFF | ((unsigned int)v55 >> 12 << 15);
    v45 = v43 & 0xFFF | (v43 >> 12 << 15);
    v46 = *(_DWORD *)(v4 + 148);
    v47 = *(_DWORD *)(v4 + 152);
    *(_DWORD *)(v4 + 132) = v44;
    *(_DWORD *)(v4 + 136) = v45;
    v52 = __PAIR64__(v46, v47);
    v13 = *(_DWORD *)(v4 + 196);
    v14 = *(_DWORD *)(v4 + 200);
    LODWORD(v53) = *(_DWORD *)(v4 + 144);
    HIDWORD(v53) = *(_DWORD *)(v4 + 140);
    v48 = v46 & 0xFFF | (v46 >> 12 << 15);
    v49 = *(_DWORD *)(v4 + 164);
    v6 = *(_DWORD *)(v4 + 168);
    *(_DWORD *)(v4 + 140) = WORD2(v53) & 0xFFF | (HIDWORD(v53) >> 12 << 15);
    *(_DWORD *)(v4 + 144) = v53 & 0xFFF | ((unsigned int)v53 >> 12 << 15);
    v50 = v49;
    *(_DWORD *)(v4 + 148) = v48;
    *(_DWORD *)(v4 + 152) = v47 & 0xFFF | (v47 >> 12 << 15);
    LODWORD(v51) = *(_DWORD *)(v4 + 160);
    HIDWORD(v51) = *(_DWORD *)(v4 + 156);
    *(_DWORD *)(v4 + 156) = WORD2(v51) & 0xFFF | (HIDWORD(v51) >> 12 << 15);
    *(_DWORD *)(v4 + 160) = v51 & 0xFFF | ((unsigned int)v51 >> 12 << 15);
    *(_DWORD *)(v4 + 164) = v49 & 0xFFF | (v49 >> 12 << 15);
    *(_DWORD *)(v4 + 168) = v6 & 0xFFF | (v6 >> 12 << 15);
    *(_DWORD *)(v4 + 172) = v7 & 0xFFF | (v7 >> 12 << 15);
    *(_DWORD *)(v4 + 176) = v8 & 0xFFF | (v8 >> 12 << 15);
    *(_DWORD *)(v4 + 180) = v9 & 0xFFF | (v9 >> 12 << 15);
    *(_DWORD *)(v4 + 184) = v10 & 0xFFF | (v10 >> 12 << 15);
    *(_DWORD *)(v4 + 188) = v11 & 0xFFF | (v11 >> 12 << 15);
    *(_DWORD *)(v4 + 192) = v12 & 0xFFF | (v12 >> 12 << 15);
    *(_DWORD *)(v4 + 196) = v13 & 0xFFF | (v13 >> 12 << 15);
    *(_DWORD *)(v4 + 200) = v14 & 0xFFF | (v14 >> 12 << 15);
  }
  else
  {
    v69 = 0;
    v70 = 0;
    v6 = 0;
    v7 = 0;
    v67 = 0;
    v68 = 0;
    v8 = 0;
    v9 = 0;
    v65 = 0;
    v66 = 0;
    v10 = 0;
    v11 = 0;
    v63 = 0;
    v64 = 0;
    v12 = 0;
    v13 = 0;
    v62 = 0;
    v14 = 0;
    v61 = 0;
    v60 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    v51 = 0;
    v50 = 0;
  }
  result = reg_dmav1_setup_dspp_3d_gamutv4_common((__int64)a1, a2, 64);
  if ( (*(_BYTE *)v4 & 1) != 0 )
  {
    *(_DWORD *)(v4 + 172) = v7;
    *(_DWORD *)(v4 + 176) = v8;
    *(_DWORD *)(v4 + 12) = HIDWORD(v70);
    *(_DWORD *)(v4 + 16) = v70;
    *(_DWORD *)(v4 + 180) = v9;
    *(_DWORD *)(v4 + 184) = v10;
    *(_DWORD *)(v4 + 188) = v11;
    *(_DWORD *)(v4 + 192) = v12;
    *(_DWORD *)(v4 + 20) = HIDWORD(v69);
    *(_DWORD *)(v4 + 24) = v69;
    *(_DWORD *)(v4 + 196) = v13;
    *(_DWORD *)(v4 + 200) = v14;
    *(_DWORD *)(v4 + 28) = HIDWORD(v68);
    *(_DWORD *)(v4 + 32) = v68;
    *(_DWORD *)(v4 + 36) = HIDWORD(v67);
    *(_DWORD *)(v4 + 40) = v67;
    *(_DWORD *)(v4 + 44) = HIDWORD(v66);
    *(_DWORD *)(v4 + 48) = v66;
    *(_DWORD *)(v4 + 52) = HIDWORD(v65);
    *(_DWORD *)(v4 + 56) = v65;
    *(_DWORD *)(v4 + 60) = HIDWORD(v64);
    *(_DWORD *)(v4 + 64) = v64;
    *(_DWORD *)(v4 + 68) = HIDWORD(v63);
    *(_DWORD *)(v4 + 72) = v63;
    *(_DWORD *)(v4 + 76) = HIDWORD(v62);
    *(_DWORD *)(v4 + 80) = v62;
    *(_DWORD *)(v4 + 84) = v61;
    *(_DWORD *)(v4 + 88) = v60;
    *(_DWORD *)(v4 + 92) = HIDWORD(v59);
    *(_DWORD *)(v4 + 96) = v59;
    *(_DWORD *)(v4 + 100) = HIDWORD(v58);
    *(_DWORD *)(v4 + 104) = v58;
    *(_DWORD *)(v4 + 108) = HIDWORD(v57);
    *(_DWORD *)(v4 + 112) = v57;
    *(_DWORD *)(v4 + 116) = HIDWORD(v56);
    *(_DWORD *)(v4 + 120) = v56;
    *(_DWORD *)(v4 + 124) = HIDWORD(v55);
    *(_DWORD *)(v4 + 128) = v55;
    *(_DWORD *)(v4 + 132) = HIDWORD(v54);
    *(_DWORD *)(v4 + 136) = v54;
    *(_DWORD *)(v4 + 140) = HIDWORD(v53);
    *(_DWORD *)(v4 + 144) = v53;
    *(_DWORD *)(v4 + 148) = HIDWORD(v52);
    *(_DWORD *)(v4 + 152) = v52;
    *(_DWORD *)(v4 + 156) = HIDWORD(v51);
    *(_DWORD *)(v4 + 160) = v51;
    *(_DWORD *)(v4 + 164) = v50;
    *(_DWORD *)(v4 + 168) = v6;
  }
  return result;
}
