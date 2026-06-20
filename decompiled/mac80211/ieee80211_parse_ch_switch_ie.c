__int64 __fastcall ieee80211_parse_ch_switch_ie(
        __int64 a1,
        _QWORD *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5,
        __int64 a6,
        char a7,
        unsigned int **a8)
{
  unsigned int v13; // w8
  _BYTE *v14; // x27
  unsigned __int8 *v15; // x9
  unsigned __int8 *v16; // x20
  __int64 v17; // x22
  unsigned __int8 *v18; // x24
  unsigned int v19; // w25
  __int64 v20; // x3
  __int64 v21; // x0
  _BYTE *v22; // x8
  __int64 v23; // x8
  unsigned int v24; // w28
  __int64 channel_khz; // x0
  unsigned int *v26; // x27
  int v27; // w8
  unsigned int v28; // w28
  unsigned int **v29; // x0
  unsigned int *v30; // x1
  __int64 v31; // x2
  __int64 result; // x0
  __int64 v33; // x8
  unsigned int *v34; // x8
  unsigned int *v35; // x8
  unsigned int *v36; // x9
  unsigned int *v37; // x9
  unsigned int *v38; // x10
  int v39; // w26
  unsigned int v40; // w28
  unsigned int v41; // w0
  int v42; // w9
  unsigned int v43; // w8
  int v44; // w8
  int v45; // w8
  unsigned int v46; // w9
  unsigned int *v47; // x9
  unsigned int *v48; // x10
  int v49; // w27
  unsigned int v50; // w22
  int v51; // w24
  unsigned int v52; // w26
  char v53; // w25
  char v54; // w0
  int v55; // w26
  unsigned int v56; // w22
  unsigned int v57; // w24
  int v58; // w27
  char v59; // w8
  unsigned __int8 v60; // w25
  unsigned __int8 v61; // w0
  char v62; // w8
  char v63; // w8
  char v64; // w8
  unsigned int v65; // w9
  __int64 *v66; // x2
  unsigned int *v67; // x9
  unsigned int *v68; // x10
  unsigned int v69; // w8
  __int64 v70; // x3
  unsigned int *v71; // x9
  unsigned int *v72; // x10
  unsigned __int16 *v73; // x8
  char v74; // w8
  __int16 v75; // w8
  __int64 v76; // x0
  unsigned int v77; // [xsp+0h] [xbp-70h]
  unsigned int v78; // [xsp+8h] [xbp-68h]
  __int64 v79; // [xsp+8h] [xbp-68h]
  unsigned int *v82; // [xsp+20h] [xbp-50h] BYREF
  unsigned int *v83; // [xsp+28h] [xbp-48h]
  unsigned int *v84; // [xsp+30h] [xbp-40h]
  unsigned int *v85; // [xsp+38h] [xbp-38h]
  unsigned int v86; // [xsp+44h] [xbp-2Ch] BYREF
  __int64 v87; // [xsp+48h] [xbp-28h] BYREF
  _BYTE v88[18]; // [xsp+50h] [xbp-20h] BYREF
  int v89; // [xsp+62h] [xbp-Eh]
  __int64 v90; // [xsp+68h] [xbp-8h]

  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a8 = nullptr;
  a8[1] = nullptr;
  a8[2] = nullptr;
  a8[3] = nullptr;
  a8[4] = nullptr;
  a8[5] = nullptr;
  a8[6] = nullptr;
  a8[7] = nullptr;
  a8[8] = nullptr;
  a8[9] = nullptr;
  v13 = *a5;
  v14 = (_BYTE *)a2[35];
  v86 = a3;
  v84 = nullptr;
  v85 = nullptr;
  v82 = nullptr;
  v83 = nullptr;
  if ( v13 >= 2 && a5[1] )
  {
    v15 = (unsigned __int8 *)a2[36];
    v16 = (unsigned __int8 *)a2[43];
  }
  else
  {
    v15 = nullptr;
    v16 = nullptr;
  }
  v17 = a2[58];
  if ( v13 >= 3 )
    v18 = v15;
  else
    v18 = nullptr;
  if ( !v14 )
    goto LABEL_44;
  v19 = (unsigned __int8)v14[1];
  if ( (ieee80211_operating_class_to_band((unsigned __int8)v14[1], &v86) & 1) == 0 )
  {
    if ( (a7 & 1) != 0 )
    {
      v21 = 0;
LABEL_26:
      v33 = a2[34];
      if ( v33 )
        goto LABEL_27;
      goto LABEL_45;
    }
    printk(&unk_BC208, a1 + 1640, (unsigned __int8)v14[1], v20);
LABEL_44:
    v21 = 0;
    v33 = a2[34];
    if ( v33 )
    {
LABEL_27:
      v21 = *(unsigned __int8 *)(v33 + 1);
      v19 = 0;
      *((_BYTE *)a8 + 65) = *(_BYTE *)(v33 + 2);
      *((_BYTE *)a8 + 64) = *(_BYTE *)a2[34];
      if ( (_DWORD)v21 )
        goto LABEL_12;
LABEL_28:
      result = 1;
      goto LABEL_108;
    }
LABEL_45:
    v19 = 0;
    if ( (_DWORD)v21 )
      goto LABEL_12;
    goto LABEL_28;
  }
  v21 = (unsigned __int8)v14[2];
  *((_BYTE *)a8 + 65) = v14[3];
  *((_BYTE *)a8 + 64) = *v14;
  if ( !v19 )
    goto LABEL_26;
  if ( !(_DWORD)v21 )
    goto LABEL_28;
LABEL_12:
  v22 = (_BYTE *)a2[44];
  v78 = a4;
  if ( v22 )
  {
    *((_BYTE *)a8 + 66) = *v22;
    *((_BYTE *)a8 + 64) = *(_BYTE *)(a2[44] + 1LL);
    *((_WORD *)a8 + 34) = *(_WORD *)(a2[44] + 4LL);
    v23 = a2[44];
    if ( (*(_BYTE *)(v23 + 1) & 4) != 0 )
      *((_WORD *)a8 + 35) = *(_WORD *)(v23 + 2);
  }
  v24 = (unsigned int)ieee80211_channel_to_freq_khz(v21, v86) / 0x3E8;
  channel_khz = ieee80211_get_channel_khz(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), 1000 * v24);
  if ( !channel_khz || (v26 = (unsigned int *)channel_khz, (*(_BYTE *)(channel_khz + 12) & 1) != 0) )
  {
    if ( (a7 & 1) == 0 )
      printk(&unk_BBA68, a1 + 1640, a6, v24);
    result = 4294967274LL;
    goto LABEL_108;
  }
  if ( v16 )
  {
    v27 = *v16;
    v28 = v78;
    if ( v27 == 1 )
    {
      v29 = a8;
      v30 = v26;
      v31 = 3;
      goto LABEL_32;
    }
    if ( v27 == 3 )
    {
      v29 = a8;
      v30 = v26;
      v31 = 2;
LABEL_32:
      cfg80211_chandef_create(v29, v30, v31);
      goto LABEL_33;
    }
LABEL_30:
    v29 = a8;
    v30 = v26;
    v31 = 1;
    goto LABEL_32;
  }
  v28 = v78;
  if ( *a5 > 1 )
    goto LABEL_30;
  cfg80211_chandef_create(a8, channel_khz, 0);
  v45 = *(_DWORD *)(a1 + 4952);
  if ( (v45 & 0xFFFFFFFE) == 6 )
    *((_DWORD *)a8 + 2) = v45;
LABEL_33:
  v34 = *a8;
  v84 = nullptr;
  v85 = nullptr;
  v82 = v26;
  v83 = nullptr;
  a8[4] = v34;
  v35 = a8[1];
  v36 = a8[2];
  a8[7] = a8[3];
  a8[5] = v35;
  a8[6] = v36;
  if ( v17 )
  {
    v37 = a8[1];
    v82 = *a8;
    v83 = v37;
    v38 = a8[3];
    v84 = a8[2];
    v85 = v38;
    ieee80211_chandef_eht_oper(v17 + 1, &v82);
    if ( (*(_BYTE *)v17 & 2) != 0 )
      HIWORD(v85) = *(_WORD *)(v17 + 4);
    goto LABEL_59;
  }
  if ( v18 )
  {
    v39 = v18[1];
    v40 = v18[2];
    v77 = (unsigned int)ieee80211_channel_to_freq_khz(v18[1], *v26) / 0x3E8;
    v41 = ieee80211_channel_to_freq_khz(v40, *v82);
    v42 = *v18;
    v43 = v41 / 0x3E8;
    if ( v42 == 1 )
    {
      LODWORD(v83) = 3;
      HIDWORD(v83) = v77;
      if ( !v40 )
        goto LABEL_56;
      v46 = v39 - v40;
      if ( (int)(v39 - v40) < 0 )
        v46 = v40 - v39;
      if ( v46 != 8 )
      {
        if ( v46 >= 9 )
        {
          LODWORD(v84) = v41 / 0x3E8;
          LODWORD(v83) = 4;
        }
LABEL_56:
        v28 = v78;
        if ( (cfg80211_chandef_valid(&v82) & 1) != 0 )
          goto LABEL_59;
        goto LABEL_57;
      }
      LODWORD(v83) = 5;
    }
    else
    {
      if ( v42 == 3 )
      {
        LODWORD(v84) = v41 / 0x3E8;
        LODWORD(v83) = 4;
        HIDWORD(v83) = v77;
        goto LABEL_56;
      }
      if ( v42 == 2 )
        v44 = 5;
      else
        v44 = 2;
      LODWORD(v83) = v44;
      v43 = v77;
    }
    HIDWORD(v83) = v43;
    goto LABEL_56;
  }
LABEL_57:
  if ( (ieee80211_operating_class_to_chandef(v19, v26, &v82) & 1) == 0 )
  {
    v47 = a8[1];
    v82 = *a8;
    v83 = v47;
    v48 = a8[3];
    v84 = a8[2];
    v85 = v48;
  }
LABEL_59:
  if ( v86 != 3 )
  {
    if ( *a5 < 2 || !a5[1] )
      goto LABEL_96;
    BYTE4(v87) = 0;
    v55 = (int)v83;
    v89 = 0;
    *(_OWORD *)&v88[2] = 0u;
    v56 = v82[1];
    LODWORD(v87) = 0;
    v57 = HIDWORD(v83);
    v58 = (int)v84;
    v88[0] = ieee80211_freq_khz_to_channel(1000 * v56);
    if ( v56 <= v57 )
      v59 = 1;
    else
      v59 = 3;
    if ( v56 == v57 )
      v59 = 0;
    v88[1] = v59;
    ieee80211_chandef_ht_oper(v88, &v82);
    if ( *a5 < 3 )
      goto LABEL_97;
    v60 = ieee80211_freq_khz_to_channel(1000 * v57);
    BYTE1(v87) = v60;
    if ( v58 )
      v61 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * v58));
    else
      v61 = 0;
    BYTE2(v87) = v61;
    if ( v55 > 4 )
    {
      if ( v55 == 5 )
      {
        LOBYTE(v87) = 1;
        if ( v56 < v57 )
          v74 = -8;
        else
          v74 = 8;
        v61 = v60;
        BYTE2(v87) = v60;
        BYTE1(v87) = v74 + v60;
LABEL_125:
        v75 = 32 * v61;
        v76 = *(_QWORD *)(a1 + 1616);
        *(_WORD *)&v88[2] = v75;
        if ( (ieee80211_chandef_vht_oper(v76, v28) & 1) != 0 )
          goto LABEL_97;
        goto LABEL_96;
      }
      if ( v55 == 13 )
      {
        __break(0x800u);
        goto LABEL_125;
      }
    }
    else if ( v55 == 3 || v55 == 4 )
    {
      LOBYTE(v87) = 1;
      goto LABEL_125;
    }
    LOBYTE(v87) = 0;
    goto LABEL_125;
  }
  if ( *a5 >= 4 )
  {
    *(_DWORD *)&v88[7] = 0;
    v49 = (int)v83;
    v87 = 0;
    *(_QWORD *)v88 = 0x20000;
    v50 = v82[1];
    v52 = HIDWORD(v83);
    v51 = (int)v84;
    v79 = *(_QWORD *)(a1 + 1616);
    v88[6] = ieee80211_freq_khz_to_channel(1000 * v50);
    v53 = ieee80211_freq_khz_to_channel(1000 * v52);
    v88[8] = v53;
    if ( v51 )
      v54 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * v51));
    else
      v54 = 0;
    v88[9] = v54;
    if ( v49 <= 3 )
    {
      if ( v49 == 2 )
      {
        v63 = 1;
        goto LABEL_92;
      }
      if ( v49 == 3 )
      {
        v63 = 2;
        goto LABEL_92;
      }
    }
    else
    {
      switch ( v49 )
      {
        case 4:
          v63 = 3;
          goto LABEL_92;
        case 5:
          v88[9] = v53;
          if ( v50 < v52 )
            v64 = -8;
          else
            v64 = 8;
          v54 = v53;
          v53 += v64;
          v63 = 3;
          v88[8] = v53;
LABEL_92:
          v65 = *a5;
          v88[7] = v63;
          if ( v65 >= 5 )
          {
            v66 = &v87;
            BYTE5(v87) = v63;
            LOBYTE(v87) = 1;
            BYTE6(v87) = v53;
            HIBYTE(v87) = v54;
          }
          else
          {
            v66 = nullptr;
          }
          if ( (ieee80211_chandef_he_6ghz_oper(v79, v88, v66, &v82) & 1) != 0 )
            goto LABEL_97;
          goto LABEL_96;
        case 13:
          v88[9] = v53;
          if ( v50 < v52 )
            v62 = -16;
          else
            v62 = 16;
          v54 = v53;
          v53 += v62;
          v63 = 4;
          v88[8] = v53;
          goto LABEL_92;
      }
    }
    v63 = 0;
    goto LABEL_92;
  }
LABEL_96:
  v82 = nullptr;
LABEL_97:
  if ( v82 )
  {
    v67 = v83;
    a8[4] = v82;
    a8[5] = v67;
    v68 = v85;
    a8[6] = v84;
    a8[7] = v68;
    v69 = a5[1];
    if ( v69 <= 3 && (_DWORD)v83 == 13 )
    {
      ieee80211_chandef_downgrade(&v82, 0);
      v69 = a5[1];
    }
    if ( v69 <= 2 && ((unsigned int)v83 & 0xFFFFFFFE) == 4 )
      ieee80211_chandef_downgrade(&v82, 0);
    if ( !cfg80211_chandef_compatible(&v82, a8) )
    {
      printk(&unk_B7E27, a1 + 1640, a6, v70);
      result = 4294967274LL;
      goto LABEL_108;
    }
    v71 = v83;
    *a8 = v82;
    a8[1] = v71;
    v72 = v85;
    a8[2] = v84;
    a8[3] = v72;
  }
  v73 = (unsigned __int16 *)a2[37];
  result = 0;
  if ( v73 )
    *((_DWORD *)a8 + 18) = *v73 | (*((unsigned __int8 *)v73 + 2) << 16);
LABEL_108:
  _ReadStatusReg(SP_EL0);
  return result;
}
