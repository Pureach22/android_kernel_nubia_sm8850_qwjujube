__int64 __fastcall qdf_nbuf_update_radiotap(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int64 v6; // x8
  __int64 v7; // x24
  __int64 v8; // x26
  __int64 v9; // x9
  char v10; // w13
  char v11; // w13
  int v12; // w27
  unsigned int v13; // w11
  _BYTE *v14; // x12
  __int16 v15; // w14
  char v16; // w15
  __int16 v17; // w11
  __int64 v18; // x22
  __int64 v19; // x8
  const char *v20; // x2
  __int16 v21; // w8
  __int64 v22; // x22
  __int64 v24; // x10
  _QWORD *v25; // x11
  __int64 v26; // x10
  _BYTE *v27; // x9
  char v28; // w12
  __int64 v29; // x11
  unsigned int v30; // w12
  _WORD *v31; // x11
  unsigned int v32; // w12
  int v33; // w12
  int v34; // w10
  __int64 v35; // x9
  __int16 v36; // w13
  __int64 v37; // x10
  _WORD *v38; // x12
  __int16 v39; // w11
  __int16 v40; // w13
  __int16 v41; // w11
  __int16 v42; // w13
  __int16 v43; // w11
  __int16 v44; // w13
  __int16 v45; // w11
  int v46; // w13
  int v47; // w14
  _BYTE *v48; // x12
  int v49; // w9
  __int64 v50; // x23
  _BYTE *v51; // x10
  char v52; // w9
  char v53; // w8
  char v54; // w9
  char v55; // w8
  char v56; // w9
  char v57; // w8
  char v58; // w9
  char v59; // w8
  char v60; // w9
  char v61; // w8
  char v62; // w9
  char v63; // w8
  char v64; // w9
  char v65; // w8
  char v66; // w9
  __int64 v67; // x20
  __int16 v68; // w10
  _BYTE *v69; // x11
  int v70; // w8
  int v71; // w9
  unsigned __int8 *v72; // x10
  __int64 v73; // x8
  __int64 v74; // x9
  _BYTE *v75; // x11
  unsigned __int8 v76; // w12
  _BYTE *v77; // x10
  __int16 v78; // w12
  _BYTE *v79; // x10
  char v80; // w11
  int v81; // w8
  __int64 v82; // x28
  _BYTE *v83; // x23
  int v84; // w9
  int v85; // w8
  int v86; // w10
  int v87; // w8
  int v88; // w25
  _BYTE *v89; // x26
  unsigned __int64 v90; // x8
  char v91; // w12
  int v92; // w11
  _BYTE *v93; // x9
  void *v94; // x0
  const void *v95; // x1
  unsigned int v96; // w11
  bool v97; // zf
  size_t v98; // x2
  __int16 v99; // w10
  int v100; // w24
  _DWORD *v101; // x23
  int v102; // w4
  int v103; // w5
  int v104; // w6
  __int64 v105; // x23
  _DWORD *v106; // x23
  _BYTE *v107; // x28
  int v108; // w20
  int v109; // w4
  int v110; // w5
  int v111; // w6
  int v112; // w8
  int v113; // w27
  int v114; // w20
  int v115; // w26
  int v116; // w24
  __int64 v117; // x28
  unsigned __int64 v118; // x8
  void *v119; // x0
  const void *v120; // x1
  int v121; // w21
  int v122; // w23
  int v123; // w28
  __int64 v124; // x21
  __int64 v125; // x8
  _BYTE *v126; // [xsp+20h] [xbp-130h]
  int v127; // [xsp+2Ch] [xbp-124h]
  int v128; // [xsp+30h] [xbp-120h]
  unsigned int v129; // [xsp+38h] [xbp-118h]
  _BYTE s[257]; // [xsp+3Fh] [xbp-111h] BYREF
  __int64 v131; // [xsp+140h] [xbp-10h]

  v131 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v6 = *(_QWORD *)(a1 + 20);
  v7 = *(_QWORD *)(a1 + 312);
  v8 = v6 & 0x500000000030LL;
  if ( (v6 & 0x500000000030LL) != 0 )
    v9 = 16;
  else
    v9 = 8;
  *(_QWORD *)&s[v9] = *(_QWORD *)a1;
  if ( (v6 & 0x2000000000LL) != 0 )
    *(_BYTE *)(a1 + 51) |= 0x40u;
  v10 = *(_BYTE *)(a1 + 51);
  if ( *(_BYTE *)(a1 + 325) == 1 )
  {
    v10 |= 0x10u;
    *(_BYTE *)(a1 + 51) = v10;
  }
  s[v9 + 8] = v10;
  if ( (v6 & 0x27) != 0 )
  {
    v11 = 0;
    v12 = 2155;
  }
  else
  {
    v11 = *(_BYTE *)(a1 + 50);
    v12 = 2159;
  }
  s[v9 + 9] = v11;
  v13 = *(_DWORD *)(a1 + 12);
  v14 = &s[v9];
  *(_WORD *)&s[v9 + 10] = v13;
  if ( v13 <= 0x141E )
    v15 = 128;
  else
    v15 = 256;
  v16 = *(_BYTE *)(a1 + 130);
  v14[14] = *(_BYTE *)(a1 + 72);
  v17 = v15 | (v6 >> 33) & 0x20 | (v6 >> 33) & 0x40;
  v14[15] = v16;
  *(_WORD *)(a1 + 18) = v17;
  *((_WORD *)v14 + 6) = v17;
  v14[16] = ((unsigned int)v6 >> 6) & 7;
  if ( (v6 & 0x100000000000LL) != 0 )
  {
    v19 = (v6 >> 53) & 0xF;
    v20 = "%s: length is greater than RADIOTAP_TX_FLAGS_LEN";
    if ( (_DWORD)v19 == 1 )
      v21 = 1;
    else
      v21 = 8 * ((_DWORD)v19 == 2);
    *(_WORD *)&s[v9 + 18] = v21;
    goto LABEL_26;
  }
  v18 = v9 + 17;
  v129 = a3;
  if ( (v6 & 1) != 0 )
  {
    s[v18] = 7;
    v24 = v9 + 18;
    if ( (v6 & 0x600000) != 0 )
      s[v24] |= 4u;
    v12 |= 0x80000u;
    if ( (v6 & 0xF0000) != 0 )
      s[v24] |= 1u;
    LODWORD(v18) = v9 + 20;
    s[(unsigned int)v9 + 19] = *(_BYTE *)(a1 + 53);
    if ( (*(_BYTE *)(a1 + 88) & 1) == 0 )
    {
LABEL_17:
      if ( (v6 & 2) == 0 )
        goto LABEL_18;
      goto LABEL_35;
    }
  }
  else if ( (*(_BYTE *)(a1 + 88) & 1) == 0 )
  {
    goto LABEL_17;
  }
  v12 |= 0x100000u;
  v25 = &s[((_BYTE)v18 + 3) & 0x7C];
  LODWORD(v18) = (((_BYTE)v18 + 3) & 0x7C) + 8;
  *v25 = *(unsigned __int16 *)(a1 + 126);
  if ( (v6 & 2) == 0 )
  {
LABEL_18:
    if ( (v6 & 4) == 0 )
      goto LABEL_19;
    goto LABEL_45;
  }
LABEL_35:
  v26 = ((_WORD)v18 + 1) & 0x1FE;
  v27 = &s[v26];
  v28 = s[v26 + 2];
  *(_WORD *)v27 = 245;
  v27[2] = v28 | ((unsigned int)v6 >> 20) & 0x31 | (4 * ((v6 & 0x600000) != 0));
  v29 = v26 + 3;
  if ( v7 )
  {
    v30 = *(unsigned __int8 *)(v7 + 36);
    if ( v30 <= 3 )
      s[v29] = 0xB040100u >> (8 * v30);
    v27[4] = *(_BYTE *)(v7 + 37);
    v27[5] = *(_BYTE *)(v7 + 38);
    v27[6] = *(_BYTE *)(v7 + 39);
    v27[7] = *(_BYTE *)(v7 + 40);
    v27[8] = *(_BYTE *)(v7 + 41);
    v27[9] = *(_BYTE *)(v7 + 42);
    v31 = (_WORD *)(v7 + 44);
  }
  else
  {
    v32 = *(unsigned __int8 *)(a1 + 61);
    if ( v32 <= 3 )
      s[v29] = 0xB040100u >> (8 * v32);
    v33 = *(_DWORD *)(a1 + 64);
    *((_WORD *)v27 + 2) = *(_WORD *)(a1 + 62);
    v31 = (_WORD *)(a1 + 32);
    *(_DWORD *)(v27 + 6) = v33;
  }
  v34 = v26 + 12;
  *((_WORD *)v27 + 5) = *v31;
  if ( (unsigned int)(v34 - v18) >= 0xE )
  {
    v20 = "%s: length is greater than RADIOTAP_VHT_FLAGS_LEN";
    goto LABEL_26;
  }
  v12 |= 0x200000u;
  LODWORD(v18) = v34;
  if ( (v6 & 4) == 0 )
  {
LABEL_19:
    if ( (v6 & 8) == 0 )
      goto LABEL_20;
    goto LABEL_51;
  }
LABEL_45:
  v35 = ((_WORD)v18 + 1) & 0x7FE;
  if ( v7 )
  {
    v36 = *(_WORD *)(a1 + 110);
    *(_WORD *)&s[v35] = *(_WORD *)(a1 + 108) | *(_WORD *)(v7 + 58);
    v37 = ((_WORD)v18 + 1) & 0x7FE;
    v38 = &s[v37];
    v39 = v36 | *(_WORD *)(v7 + 60);
    v40 = *(_WORD *)(a1 + 112);
    v38[1] = v39;
    v41 = v40 | *(_WORD *)(v7 + 62);
    v42 = *(_WORD *)(a1 + 114);
    v38[2] = v41;
    v43 = v42 | *(_WORD *)(v7 + 64);
    v44 = *(_WORD *)(a1 + 116);
    v38[3] = v43;
    v38[4] = v44 | *(_WORD *)(v7 + 66);
    v45 = *(_WORD *)(a1 + 118) | *(_WORD *)(v7 + 68);
  }
  else
  {
    v46 = *(_DWORD *)(a1 + 110);
    v37 = ((_WORD)v18 + 1) & 0x7FE;
    v47 = *(_DWORD *)(a1 + 114);
    *(_WORD *)&s[v35] = *(_WORD *)(a1 + 108);
    v48 = &s[v37];
    v45 = *(_WORD *)(a1 + 118);
    *(_DWORD *)(v48 + 2) = v46;
    *(_DWORD *)(v48 + 6) = v47;
  }
  v49 = v35 + 12;
  *(_WORD *)&s[v37 + 10] = v45;
  if ( (unsigned int)(v49 - v18) >= 0xE )
  {
    v20 = "%s: length is greater than RADIOTAP_HE_FLAGS_LEN";
    goto LABEL_26;
  }
  v12 |= 0x800000u;
  LODWORD(v18) = v49;
  if ( (v6 & 8) == 0 )
  {
LABEL_20:
    if ( !*(_WORD *)(a1 + 34) )
      goto LABEL_64;
    goto LABEL_58;
  }
LABEL_51:
  v50 = ((int)v18 + 1) & 0x1FFELL;
  if ( v7 )
  {
    *(_WORD *)&s[v50] = *(_WORD *)(a1 + 96) | *(_WORD *)(v7 + 46);
    v51 = &s[(unsigned int)v50];
    v52 = *(_BYTE *)(a1 + 100);
    *((_WORD *)v51 + 1) = *(_WORD *)(a1 + 98) | *(_WORD *)(v7 + 48);
    v53 = v52 | *(_BYTE *)(v7 + 50);
    v54 = *(_BYTE *)(a1 + 101);
    v51[4] = v53;
    v55 = v54 | *(_BYTE *)(v7 + 51);
    v56 = *(_BYTE *)(a1 + 102);
    v51[5] = v55;
    v57 = v56 | *(_BYTE *)(v7 + 52);
    v58 = *(_BYTE *)(a1 + 103);
    v51[6] = v57;
    v59 = v58 | *(_BYTE *)(v7 + 53);
    v60 = *(_BYTE *)(a1 + 104);
    v51[7] = v59;
    v61 = v60 | *(_BYTE *)(v7 + 54);
    v62 = *(_BYTE *)(a1 + 105);
    v51[8] = v61;
    v63 = v62 | *(_BYTE *)(v7 + 55);
    v64 = *(_BYTE *)(a1 + 106);
    v51[9] = v63;
    v65 = v64 | *(_BYTE *)(v7 + 56);
    v66 = *(_BYTE *)(a1 + 107);
    v51[10] = v65;
    v51[11] = v66 | *(_BYTE *)(v7 + 57);
    v67 = jiffies;
    if ( qdf_nbuf_update_radiotap_he_mu_flags___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        56,
        8,
        "%s: he_flags %x %x he-RU %x %x %x %x",
        "qdf_nbuf_update_radiotap_he_mu_flags",
        *(unsigned __int16 *)(v7 + 46),
        *(unsigned __int16 *)(v7 + 48),
        *(unsigned __int8 *)(v7 + 50),
        *(unsigned __int8 *)(v7 + 51),
        *(unsigned __int8 *)(v7 + 52),
        *(unsigned __int8 *)(v7 + 53));
      qdf_nbuf_update_radiotap_he_mu_flags___last_ticks = v67;
    }
  }
  else
  {
    v68 = *(_WORD *)(a1 + 98);
    v69 = &s[(unsigned int)v50];
    *(_WORD *)&s[v50] = *(_WORD *)(a1 + 96);
    v70 = *(_DWORD *)(a1 + 100);
    v71 = *(_DWORD *)(a1 + 104);
    *((_WORD *)v69 + 1) = v68;
    *((_DWORD *)v69 + 1) = v70;
    *((_DWORD *)v69 + 2) = v71;
  }
  if ( (unsigned int)(v50 + 12 - v18) >= 0xE )
  {
    v20 = "%s: length is greater than RADIOTAP_HE_MU_FLAGS_LEN";
    goto LABEL_26;
  }
  v12 |= 0x1000000u;
  LODWORD(v18) = v50 + 12;
  if ( *(_WORD *)(a1 + 34) )
  {
LABEL_58:
    v72 = *(unsigned __int8 **)(a1 + 312);
    v73 = ((_WORD)v18 + 1) & 0x7FFE;
    if ( v72 )
    {
      *(_WORD *)&s[v73] = v72[70];
      v74 = ((_WORD)v18 + 1) & 0x7FFE;
      v75 = &s[v74];
      *((_WORD *)v75 + 1) = v72[71];
      v76 = v72[72];
      v77 = v72 + 73;
      v75[4] = v76;
    }
    else
    {
      v74 = ((_WORD)v18 + 1) & 0x7FFE;
      v78 = *(_WORD *)(a1 + 92);
      *(_WORD *)&s[v73] = *(_WORD *)(a1 + 90);
      v79 = &s[v74];
      v80 = *(_BYTE *)(a1 + 94);
      *((_WORD *)v79 + 1) = v78;
      v79[4] = v80;
      v77 = (_BYTE *)(a1 + 95);
    }
    v81 = v73 + 6;
    s[v74 + 5] = *v77;
    if ( (unsigned int)(v81 - v18) >= 0x14 )
    {
      v20 = "%s: length is greater than RADIOTAP_HE_MU_OTHER_FLAGS_LEN";
      goto LABEL_26;
    }
    v12 |= 0x2000000u;
    LODWORD(v18) = v81;
  }
LABEL_64:
  v82 = ((_DWORD)v18 + 1) & 0x1FFFE;
  v83 = &s[v82];
  qdf_mem_copy(&s[v82], &ATH_OUI, 3u);
  v84 = *(unsigned __int16 *)(a1 + 128);
  v22 = v82 + 22;
  *((_WORD *)v83 + 2) = 16;
  v85 = *(_DWORD *)(a1 + 40);
  v86 = *(_DWORD *)(a1 + 44);
  v83[3] = 0;
  *(_DWORD *)(v83 + 10) = v84;
  *(_DWORD *)(v83 + 6) = v85;
  v87 = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(v83 + 14) = v86;
  *(_DWORD *)(v83 + 18) = v87;
  if ( v8 )
  {
    v88 = 0;
    v89 = &s[8];
    *(_DWORD *)&s[4] = v12 | 0xC0000000;
    v90 = *(_QWORD *)(a1 + 20);
    if ( (v90 & 0x100000000000LL) == 0 )
      goto LABEL_67;
    goto LABEL_66;
  }
  v89 = &s[4];
  v88 = v12 | 0x40000000;
  v90 = *(_QWORD *)(a1 + 20);
  if ( (v90 & 0x100000000000LL) != 0 )
  {
LABEL_66:
    v91 = *(_BYTE *)(a1 + 198);
    s[v22] = (v90 >> 53) & 0xF;
    v88 |= 3u;
    LODWORD(v22) = v82 + 24;
    s[(unsigned int)v82 + 23] = v91;
  }
LABEL_67:
  if ( (v90 & 0x400000000000LL) == 0 )
  {
    if ( (v90 & 0x10) == 0 )
      goto LABEL_69;
LABEL_80:
    v100 = (v22 + 3) & 0xFFFFC;
    v101 = &s[v100];
    qdf_mem_set(v101, 0x10u, 0);
    v102 = *(_DWORD *)(a1 + 240);
    v103 = *(_DWORD *)(a1 + 244);
    v104 = *(_DWORD *)(a1 + 248);
    *v101 = 786465;
    v101[1] = v102;
    v101[2] = v103;
    v101[3] = v104;
    v105 = jiffies;
    if ( qdf_nbuf_update_radiotap_usig_flags___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 8, "%s: U-SIG data %x %x %x", "qdf_nbuf_update_radiotap_usig_flags", v102, v103, v104);
      qdf_nbuf_update_radiotap_usig_flags___last_ticks = v105;
    }
    if ( (unsigned int)(v100 + 16 - v22) > 0x13 )
    {
      v20 = "%s: length is greater than RADIOTAP_U_SIG_FLAGS_LEN";
      goto LABEL_26;
    }
    v88 |= 0x10000000u;
    LODWORD(v22) = v100 + 16;
    if ( (*(_QWORD *)(a1 + 20) & 0x20) == 0 )
      goto LABEL_103;
    goto LABEL_85;
  }
  v92 = *(unsigned __int16 *)(a1 + 124);
  v93 = &s[(unsigned int)v22];
  v88 |= 4u;
  *(_DWORD *)v93 = *(unsigned __int16 *)(a1 + 126);
  *((_DWORD *)v93 + 1) = v92;
  if ( v7 )
  {
    v94 = v93 + 12;
    v95 = (const void *)(v7 + 176);
    v96 = 4 * (unsigned __int8)*(_WORD *)(v7 + 24);
    v97 = (unsigned __int8)*(_WORD *)(v7 + 24) == 0;
    v93[8] = *(_BYTE *)(v7 + 20) & 0xF;
    if ( v97 )
      v98 = 32;
    else
      v98 = v96;
    *((_WORD *)v93 + 5) = *(_WORD *)(v7 + 170);
  }
  else
  {
    v99 = *(_WORD *)(a1 + 200);
    v94 = v93 + 12;
    v95 = (const void *)(a1 + 204);
    v98 = 32;
    v93[8] = BYTE4(v90) & 0x1F;
    *((_WORD *)v93 + 5) = v99;
  }
  qdf_mem_copy(v94, v95, v98);
  v90 = *(_QWORD *)(a1 + 20);
  LODWORD(v22) = v22 + 44;
  if ( (v90 & 0x10) != 0 )
    goto LABEL_80;
LABEL_69:
  if ( (v90 & 0x20) != 0 )
  {
LABEL_85:
    v106 = *(_DWORD **)(a1 + 312);
    v107 = &s[((_DWORD)v22 + 3) & 0x3FFFFC];
    if ( v106 )
      v108 = 44;
    else
      v108 = 56;
    v128 = (v22 + 3) & 0x3FFFFC;
    v127 = v108 + 4;
    qdf_mem_set(&s[v128], (unsigned int)(v108 + 4), 0);
    v109 = *(_DWORD *)(a1 + 252);
    *((_WORD *)v107 + 1) = v108;
    *(_WORD *)v107 = 34;
    v126 = v89;
    v110 = *(_DWORD *)(a1 + 256);
    v111 = *(_DWORD *)(a1 + 260);
    if ( v106 )
    {
      *((_DWORD *)v107 + 1) = v106[19] | v109;
      *((_DWORD *)v107 + 2) = v106[20] | v110;
      v112 = v106[21] | v111;
    }
    else
    {
      *((_DWORD *)v107 + 1) = v109;
      *((_DWORD *)v107 + 2) = v110;
      v112 = v111;
    }
    v113 = *(_DWORD *)(a1 + 264);
    v114 = *(_DWORD *)(a1 + 268);
    v115 = *(_DWORD *)(a1 + 272);
    v116 = *(_DWORD *)(a1 + 276);
    *((_DWORD *)v107 + 3) = v112;
    *((_DWORD *)v107 + 4) = v113;
    *((_DWORD *)v107 + 5) = v114;
    *((_DWORD *)v107 + 6) = v115;
    *((_DWORD *)v107 + 7) = v116;
    if ( v106 )
    {
      *((_DWORD *)v107 + 11) = v106[29];
      v117 = jiffies;
      if ( qdf_nbuf_update_radiotap_eht_flags___last_ticks_70 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          56,
          8,
          "%s: EHT data %x %x %x %x %x %x %x",
          "qdf_nbuf_update_radiotap_eht_flags",
          v106[19] | v109,
          v106[20] | v110,
          v106[21] | v111,
          v113,
          v114,
          v115,
          v116);
        qdf_nbuf_update_radiotap_eht_flags___last_ticks_70 = v117;
      }
    }
    else
    {
      if ( *(_BYTE *)(a1 + 48) )
      {
        v118 = *(unsigned __int8 *)(a1 + 48) - 1LL;
        v119 = v107 + 44;
        v120 = (const void *)(a1 + 296);
        v121 = v109;
        if ( v118 >= 3 )
          v118 = 3;
        v122 = v110;
        v123 = v111;
        memcpy(v119, v120, 4 * v118 + 4);
        v111 = v123;
        v110 = v122;
        v109 = v121;
      }
      v124 = jiffies;
      if ( qdf_nbuf_update_radiotap_eht_flags___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          56,
          8,
          "%s: EHT data %x %x %x %x %x %x %x",
          "qdf_nbuf_update_radiotap_eht_flags",
          v109,
          v110,
          v111,
          v113,
          v114,
          v115,
          v116);
        qdf_nbuf_update_radiotap_eht_flags___last_ticks = v124;
      }
    }
    if ( (unsigned int)(v127 + v128 - v22) < 0x40 )
    {
      v89 = v126;
      v88 |= 0x10000000u;
      LODWORD(v22) = v127 + v128;
      goto LABEL_103;
    }
    v20 = "%s: length is greater than RADIOTAP_EHT_FLAGS_LEN";
LABEL_26:
    qdf_trace_msg(56, 2, v20, "qdf_nbuf_update_radiotap");
LABEL_27:
    LODWORD(v22) = 0;
    goto LABEL_28;
  }
LABEL_103:
  *(_DWORD *)v89 = v88;
  *(_WORD *)&s[2] = v22;
  if ( (unsigned int)v22 > v129 )
  {
    qdf_trace_msg(56, 8, "%s: DEBUG: Not enough space to update radiotap", "qdf_nbuf_update_radiotap");
    goto LABEL_27;
  }
  v125 = *(_QWORD *)(a2 + 40);
  if ( v125 )
    *(_QWORD *)(a2 + 40) = v125 - (unsigned int)v22;
  skb_push(a2, (unsigned int)v22);
  qdf_mem_copy(*(void **)(a2 + 224), s, (unsigned int)v22);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v22;
}
