__int64 __fastcall ieee80211_register_hw(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 result; // x0
  _QWORD *v6; // x9
  __int64 v7; // x9
  __int64 v8; // x9
  unsigned int *v9; // x10
  unsigned int v10; // t1
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x13
  int v15; // w11
  __int64 v16; // x13
  bool v17; // w12
  int v18; // w14
  __int64 v19; // x15
  _WORD *v20; // x16
  int v21; // w9
  __int64 v22; // x8
  bool v23; // w10
  int v24; // w11
  __int64 v25; // x12
  _WORD *v26; // x13
  __int64 v27; // x27
  int v28; // w20
  int v29; // w23
  char v30; // w26
  char v31; // w25
  char v32; // w24
  char v33; // w22
  __int64 *v34; // x28
  __int64 v35; // x9
  __int64 v36; // x8
  __int64 v37; // x10
  char *v38; // x11
  char v39; // t1
  __int64 v40; // x9
  __int64 v41; // x9
  int v42; // w11
  __int64 v43; // x8
  __int64 v44; // x8
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x11
  int v48; // w8
  __int64 v49; // x10
  __int64 v50; // x11
  char v51; // w12
  unsigned int v52; // w10
  char v53; // w10
  unsigned __int8 v54; // w0
  unsigned int v55; // w8
  __int64 v56; // x8
  __int16 v57; // w9
  unsigned __int64 v58; // x20
  __int64 v59; // x0
  unsigned __int64 v60; // x1
  __int64 v61; // x8
  __int64 v62; // x8
  unsigned int v63; // w20
  __int64 v64; // x8
  int v65; // w8
  int v66; // w8
  __int64 v67; // x8
  __int64 v68; // x9
  __int64 v69; // x8
  int v70; // w9
  __int64 v71; // x0
  unsigned int v72; // w9
  int v73; // w8
  int v74; // w9
  __int64 v75; // x0
  __int64 inited; // x0
  __int64 v77; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v79; // x27
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  unsigned __int64 v93; // x10
  __int64 v94; // [xsp+0h] [xbp-60h]
  _QWORD *v95; // [xsp+8h] [xbp-58h]
  _QWORD *v96; // [xsp+10h] [xbp-50h]
  __int64 v97; // [xsp+18h] [xbp-48h] BYREF
  __int64 v98; // [xsp+20h] [xbp-40h]
  __int64 v99; // [xsp+28h] [xbp-38h]
  __int64 v100; // [xsp+30h] [xbp-30h]
  _QWORD v101[5]; // [xsp+38h] [xbp-28h] BYREF

  v101[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  if ( (*(_QWORD *)(a1 + 96) & 0x40000) != 0 )
  {
    v2 = *(unsigned __int8 *)(a1 + 141);
    if ( v2 == 255 || *(unsigned __int16 *)(a1 + 128) <= v2 )
      goto LABEL_116;
  }
  v3 = *(_QWORD *)(a1 + 72);
  if ( (*(_BYTE *)(v3 + 111) & 0x10) != 0 )
  {
    v6 = *(_QWORD **)(a1 + 464);
    if ( !v6[91] || !v6[92] || !v6[93] )
    {
      result = 4294967201LL;
      goto LABEL_117;
    }
  }
  if ( (*(_QWORD *)(a1 + 96) & 0x4000000000LL) != 0 && !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 248LL)
    || (*(_WORD *)(v3 + 96) & 0x1000) != 0
    && ((v4 = *(_QWORD *)(a1 + 464), !*(_QWORD *)(v4 + 768)) || !*(_QWORD *)(v4 + 776))
    || (*(_BYTE *)(v3 + 100) & 2) != 0
    && (*(_BYTE *)(a1 + 1400) == 1
     || !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 96LL)
     || (*(_QWORD *)(a1 + 96) & 1) == 0
     || (*(_QWORD *)(a1 + 96) & 0x80) == 0
     || (*(_QWORD *)(a1 + 96) & 4) != 0
     || (*(_QWORD *)(a1 + 96) & 0x100) != 0
     && ((*(_QWORD *)(a1 + 96) & 0x400) == 0 || (*(_QWORD *)(a1 + 96) & 0x200) != 0)
     || (*(_QWORD *)(a1 + 96) & 0x800) == 0
     || (*(_QWORD *)(a1 + 96) & 0x20000) == 0
     || (*(_QWORD *)(a1 + 96) & 0x20) != 0
     || (*(_QWORD *)(a1 + 96) & 0x1000000) != 0
     || (*(_QWORD *)(a1 + 96) & 0x100000) == 0) )
  {
LABEL_18:
    __break(0x800u);
    result = 4294967274LL;
    goto LABEL_117;
  }
  if ( *(_QWORD *)(v3 + 248) )
  {
    v7 = *(_QWORD *)(a1 + 464);
    if ( !*(_QWORD *)(v7 + 24) || !*(_QWORD *)(v7 + 32) )
    {
LABEL_116:
      result = 4294967274LL;
      goto LABEL_117;
    }
  }
  if ( *(_BYTE *)(a1 + 1400) == 1 )
  {
    v8 = *(unsigned int *)(v3 + 88);
    if ( (int)v8 >= 1 )
    {
      v9 = (unsigned int *)(*(_QWORD *)(v3 + 80) + 8LL);
      do
      {
        v10 = *v9;
        v9 += 6;
        if ( v10 >= 2 )
          goto LABEL_116;
      }
      while ( --v8 );
    }
  }
  v11 = *(unsigned int *)(v3 + 1496);
  if ( (_DWORD)v11 )
  {
    if ( (int)v11 >= 1 )
    {
      v12 = *(_QWORD *)(v3 + 1504);
      v13 = 0;
      do
      {
        v14 = v12 + 32 * v13;
        v15 = *(_DWORD *)(v14 + 24);
        if ( v15 >= 1 )
        {
          v16 = *(_QWORD *)(v14 + 16);
          v17 = 0;
          v18 = 0;
          while ( !*(_BYTE *)(v16 + 16) || *(_DWORD *)(v16 + 8) <= 1u )
          {
            v19 = *(unsigned __int8 *)(v16 + 14);
            if ( *(_BYTE *)(v16 + 14) )
            {
              v20 = (_WORD *)(*(_QWORD *)v16 + 2LL);
              while ( (*v20 & 2) == 0 || (unsigned __int16)*(v20 - 1) <= 1u )
              {
                --v19;
                v20 += 2;
                if ( !v19 )
                  goto LABEL_45;
              }
              break;
            }
LABEL_45:
            ++v18;
            v16 += 24;
            v17 = v18 >= v15;
            if ( v18 == v15 )
              break;
          }
          if ( !v17 )
            goto LABEL_116;
        }
      }
      while ( ++v13 != v11 );
    }
  }
  else
  {
    v21 = *(_DWORD *)(v3 + 88);
    if ( v21 >= 1 )
    {
      v22 = *(_QWORD *)(v3 + 80);
      v23 = 0;
      v24 = 0;
      while ( !*(_BYTE *)(v22 + 16) || *(_DWORD *)(v22 + 8) <= 1u )
      {
        v25 = *(unsigned __int8 *)(v22 + 14);
        if ( *(_BYTE *)(v22 + 14) )
        {
          v26 = (_WORD *)(*(_QWORD *)v22 + 2LL);
          while ( (*v26 & 2) == 0 || (unsigned __int16)*(v26 - 1) <= 1u )
          {
            --v25;
            v26 += 2;
            if ( !v25 )
              goto LABEL_56;
          }
          break;
        }
LABEL_56:
        ++v24;
        v22 += 24;
        v23 = v24 >= v21;
        if ( v24 == v21 )
          break;
      }
      if ( !v23 )
        goto LABEL_116;
    }
  }
  if ( (*(_QWORD *)(a1 + 160) & 0xFFFDFEF9BFE2FFC4LL) != 0 )
    goto LABEL_18;
  if ( !*(_BYTE *)(a1 + 134) )
    *(_BYTE *)(a1 + 134) = *(_BYTE *)(a1 + 133);
  v27 = 0;
  *(_BYTE *)(a1 + 1504) = 1;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v96 = (_QWORD *)(a1 + 5392);
  v94 = a1 + 4096;
  v95 = (_QWORD *)(a1 + 1368);
  do
  {
    v34 = *(__int64 **)(*(_QWORD *)(a1 + 72) + 8 * v27 + 328);
    if ( !v34 )
      goto LABEL_69;
    if ( !v97 )
    {
      v35 = *((unsigned int *)v34 + 5);
      v36 = *v34;
      if ( (int)v35 < 1 )
      {
        LODWORD(v37) = 0;
      }
      else
      {
        v37 = 0;
        v38 = (char *)(v36 + 12);
        while ( 1 )
        {
          v39 = *v38;
          v38 += 64;
          if ( (v39 & 1) == 0 )
            break;
          if ( v35 == ++v37 )
          {
            LODWORD(v37) = *((_DWORD *)v34 + 5);
            break;
          }
        }
      }
      if ( (_DWORD)v37 == (_DWORD)v35 )
        v40 = 0;
      else
        v40 = (unsigned int)v37;
      cfg80211_chandef_create(&v97, v36 + (v40 << 6), 0);
      v41 = v98;
      v42 = *(unsigned __int8 *)(a1 + 1400);
      *v96 = v97;
      v96[1] = v41;
      v43 = v100;
      v96[2] = v99;
      v96[3] = v43;
      if ( v42 == 1 )
      {
        v44 = v97;
        v45 = v98;
        v46 = v99;
        v47 = v100;
        *v95 = v97;
        v95[1] = v45;
        v95[2] = v46;
        v95[3] = v47;
        *(_QWORD *)(a1 + 24) = v44;
        *(_QWORD *)(a1 + 32) = v45;
        *(_QWORD *)(a1 + 40) = v46;
        *(_QWORD *)(a1 + 48) = v47;
      }
    }
    v48 = *((unsigned __int8 *)v34 + 30);
    if ( v48 == 1 && (*((_WORD *)v34 + 14) & 0x400) != 0 && (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 100LL) & 2) != 0 )
    {
LABEL_198:
      __break(0x800u);
      result = 4294967274LL;
      goto LABEL_117;
    }
    if ( v29 <= *((_DWORD *)v34 + 6) )
      v29 = *((_DWORD *)v34 + 6);
    if ( (v31 & 1) != 0 )
    {
      v31 = 1;
      v49 = *((unsigned __int16 *)v34 + 46);
      if ( *((_WORD *)v34 + 46) )
        goto LABEL_92;
      goto LABEL_107;
    }
    v31 = *((_BYTE *)v34 + 52);
    v49 = *((unsigned __int16 *)v34 + 46);
    if ( *((_WORD *)v34 + 46) )
    {
LABEL_92:
      v50 = v34[12];
      if ( v27 )
        v51 = 4;
      else
        v51 = 2;
      do
      {
        if ( (v32 & 1) != 0 )
        {
          v32 = 1;
          if ( (v33 & 1) != 0 )
            goto LABEL_100;
        }
        else
        {
          v32 = *(_BYTE *)(v50 + 2);
          if ( (v33 & 1) != 0 )
          {
LABEL_100:
            v33 = 1;
            goto LABEL_101;
          }
        }
        v33 = *(_BYTE *)(v50 + 59);
LABEL_101:
        if ( *(_BYTE *)(v50 + 2) == 1
          && (*(_WORD *)v50 & 0x104) != 0
          && *((_BYTE *)v34 + 30)
          && (*((_WORD *)v34 + 14) & 2) != 0
          && ((unsigned __int8)v51 & *(_BYTE *)(v50 + 9)) == 0 )
        {
          goto LABEL_116;
        }
        --v49;
        v50 += 128;
      }
      while ( v49 );
    }
LABEL_107:
    v52 = *(unsigned __int16 *)(a1 + 128);
    v30 |= v48;
    if ( (v52 > 3) | v30 & 1 )
      v53 = v52 < 4;
    else
      v53 = v31 | v32;
    if ( (v53 & 1) != 0 || !(v32 & 1 | ((v33 & 1) == 0)) )
      goto LABEL_198;
    v28 += *((_DWORD *)v34 + 5);
    if ( *((_BYTE *)v34 + 30) )
    {
      v54 = ieee80211_mcs_to_chains((char *)v34 + 33);
      v55 = *(unsigned __int8 *)(a1 + 1504);
      v30 = 1;
      if ( v54 > v55 )
        LOBYTE(v55) = v54;
      *(_BYTE *)(a1 + 1504) = v55;
      *((_WORD *)v34 + 14) |= 0xCu;
    }
LABEL_69:
    ++v27;
  }
  while ( v27 != 6 );
  v56 = *(_QWORD *)(a1 + 72);
  v57 = *(_WORD *)(v56 + 96);
  if ( (v57 & 8) != 0 && (*(_QWORD *)(a1 + 96) & 0x4000) == 0 )
  {
    *(_WORD *)(v56 + 96) = v57 | 0x10;
    *(_WORD *)(*(_QWORD *)(a1 + 72) + 92LL) |= 0x10u;
    v56 = *(_QWORD *)(a1 + 72);
    v57 = *(_WORD *)(v56 + 96);
  }
  *(_WORD *)(v56 + 96) = v57 | 0x40;
  *(_WORD *)(*(_QWORD *)(a1 + 72) + 92LL) |= 0x40u;
  v58 = 8LL * v28 + 160;
  v59 = _kmalloc_noprof(v58, 3520);
  *(_QWORD *)(a1 + 4744) = v59;
  if ( !v59 )
  {
LABEL_212:
    result = 4294967284LL;
    goto LABEL_117;
  }
  while ( 1 )
  {
    v60 = v58 >= 0x54 ? v58 - 84 : 0LL;
    if ( v60 > 5 )
      break;
    _fortify_panic(15);
    StatusReg = _ReadStatusReg(SP_EL0);
    v79 = *(_QWORD *)(StatusReg + 80);
    v58 = 8LL * (int)v58 + 160;
    *(_QWORD *)(StatusReg + 80) = &ieee80211_register_hw__alloc_tag;
    v59 = _kmalloc_noprof(v58, 3520);
    *(_QWORD *)(StatusReg + 80) = v79;
    *(_QWORD *)(a1 + 4744) = v59;
    if ( !v59 )
      goto LABEL_212;
  }
  v61 = *(_QWORD *)(a1 + 72);
  *(_WORD *)(v59 + 88) = -1;
  *(_DWORD *)(v59 + 84) = -1;
  if ( *(_QWORD *)(v61 + 328) )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 4744) + 40LL) = -1;
    v61 = *(_QWORD *)(a1 + 72);
  }
  if ( *(_QWORD *)(v61 + 336) )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 4744) + 44LL) = -1;
    v61 = *(_QWORD *)(a1 + 72);
  }
  if ( *(_QWORD *)(v61 + 344) )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 4744) + 48LL) = -1;
    v61 = *(_QWORD *)(a1 + 72);
  }
  if ( *(_QWORD *)(v61 + 352) )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 4744) + 52LL) = -1;
    v61 = *(_QWORD *)(a1 + 72);
  }
  if ( *(_QWORD *)(v61 + 360) )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 4744) + 56LL) = -1;
    v61 = *(_QWORD *)(a1 + 72);
  }
  if ( *(_QWORD *)(v61 + 368) )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 4744) + 60LL) = -1;
    v61 = *(_QWORD *)(a1 + 72);
  }
  *(_WORD *)(v61 + 96) &= ~0x80u;
  v62 = *(_QWORD *)(a1 + 72);
  if ( (*(_WORD *)(v62 + 96) & 0x80) != 0 )
  {
    *(_DWORD *)(v62 + 100) |= 0x400u;
    v62 = *(_QWORD *)(a1 + 72);
  }
  *(_DWORD *)(v62 + 100) |= 0x80u;
  if ( (*(_QWORD *)(a1 + 96) & 0x10) != 0 )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 72) + 128LL) = 1;
    goto LABEL_145;
  }
  if ( (*(_QWORD *)(a1 + 96) & 8) == 0 || (*(_DWORD *)(*(_QWORD *)(a1 + 72) + 128LL) = 2, *(char *)(a1 + 132) >= 1) )
  {
LABEL_145:
    if ( !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 152LL) )
    {
      *(_BYTE *)(*(_QWORD *)(a1 + 72) + 115LL) |= 0x80u;
      *(_BYTE *)(*(_QWORD *)(a1 + 72) + 116LL) |= 0x10u;
    }
    v64 = *(_QWORD *)(a1 + 72);
    if ( (*(_WORD *)(v64 + 96) & 2) != 0 )
      *(_BYTE *)(v64 + 117) |= 0x10u;
    if ( (v30 & 1) != 0 )
      v65 = 35;
    else
      v65 = 7;
    v66 = v29 + v65;
    if ( (v31 & 1) != 0 )
      v66 += 14;
    *(_DWORD *)(a1 + 4808) = v66;
    if ( (v32 & 1) != 0 )
    {
      *(_DWORD *)(a1 + 4808) = v66 + 57;
      if ( (v33 & 1) != 0 )
        *(_DWORD *)(a1 + 4808) = v66 + 112;
    }
    v67 = *(_QWORD *)(a1 + 72);
    if ( !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 184LL) )
    {
      *(_BYTE *)(v67 + 136) = 4;
      *(_WORD *)(*(_QWORD *)(a1 + 72) + 140LL) = 2304;
      v67 = *(_QWORD *)(a1 + 72);
    }
    if ( *(_WORD *)(v67 + 140) )
      *(_WORD *)(v67 + 140) -= *(_WORD *)(a1 + 4808);
    v68 = *(_QWORD *)(a1 + 96);
    v69 = *(_QWORD *)(a1 + 72);
    if ( (v68 & 0x4000) == 0 && !*(_QWORD *)(v69 + 160) )
    {
      *(_QWORD *)(v69 + 160) = &ieee80211_init_cipher_suites_cipher_suites;
      *(_DWORD *)(*(_QWORD *)(a1 + 72) + 156LL) = 11;
      v69 = *(_QWORD *)(a1 + 72);
      if ( (v68 & 0x800) == 0 )
      {
        *(_DWORD *)(v69 + 156) -= 4;
        v69 = *(_QWORD *)(a1 + 72);
      }
    }
    if ( *(_QWORD *)(*(_QWORD *)(a1 + 464) + 472LL) )
    {
      v70 = *(_DWORD *)(v69 + 100);
      if ( (v70 & 0x8000) == 0 )
        goto LABEL_167;
    }
    else
    {
      *(_WORD *)(v69 + 264) = 5000;
      v69 = *(_QWORD *)(a1 + 72);
      v70 = *(_DWORD *)(v69 + 100);
      if ( (v70 & 0x8000) == 0 )
      {
LABEL_167:
        if ( (*(_QWORD *)(a1 + 96) & 0x4000000) == 0 )
          goto LABEL_168;
        goto LABEL_172;
      }
    }
    *(_DWORD *)(v69 + 100) = v70 | 0x10000;
    if ( (*(_QWORD *)(a1 + 96) & 0x4000000) == 0 )
    {
LABEL_168:
      if ( (*(_QWORD *)(a1 + 96) & 0x200000000000LL) == 0 )
        goto LABEL_176;
      goto LABEL_173;
    }
LABEL_172:
    *(_BYTE *)(v94 + 1360) |= 4u;
    if ( (*(_QWORD *)(a1 + 96) & 0x200000000000LL) == 0 )
      goto LABEL_176;
LABEL_173:
    *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1424LL) |= 1u;
    if ( (*(_QWORD *)(a1 + 96) & 0x400000000000LL) != 0 )
      *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1424LL) |= 2u;
    else
      *(_BYTE *)(v94 + 1362) |= 0x40u;
LABEL_176:
    *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1394LL) = 2;
    if ( *(unsigned __int16 *)(a1 + 128) >= 0x11u )
      *(_WORD *)(a1 + 128) = 16;
    v71 = alloc_workqueue("%s", byte_20002);
    *(_QWORD *)(a1 + 472) = v71;
    if ( v71 )
    {
      v72 = *(_DWORD *)(a1 + 104);
      v73 = *(unsigned __int16 *)(a1 + 130);
      if ( v72 <= 0x10 )
        v72 = 16;
      *(_DWORD *)(a1 + 1508) = v72;
      if ( !v73 )
      {
        LOWORD(v73) = 5;
        *(_WORD *)(a1 + 130) = 5;
      }
      v74 = *(unsigned __int8 *)(a1 + 170);
      *(_WORD *)(a1 + 12) = v73;
      *(_DWORD *)(a1 + 5152) = -1;
      if ( !v74 )
        *(_BYTE *)(a1 + 170) = -1;
      if ( !*(_BYTE *)(a1 + 172) )
        *(_BYTE *)(a1 + 172) = 1;
      ieee80211_wep_init(a1);
      *(_DWORD *)a1 = 4;
      v75 = ieee80211_txq_setup_flows(a1);
      v63 = v75;
      if ( !(_DWORD)v75 )
      {
        rtnl_lock(v75);
        inited = ieee80211_init_rate_ctrl_alg(a1, *(_QWORD *)(a1 + 80));
        v63 = inited;
        rtnl_unlock(inited);
        if ( (v63 & 0x80000000) != 0 )
        {
          dev_printk(&unk_BBEF5, *(_QWORD *)(a1 + 72) + 392LL, "Failed to initialize rate control algorithm\n");
        }
        else
        {
          if ( *(_QWORD *)(a1 + 2536) )
          {
            _X8 = (unsigned __int64 *)(a1 + 96);
            __asm { PRFM            #0x11, [X8] }
            do
              v93 = __ldxr(_X8);
            while ( __stxr(v93 & 0xFFFFFBFFFFFFFFFFLL, _X8) );
            if ( (***(_BYTE ***)(a1 + 2536) & 1) != 0 )
              *(_QWORD *)(a1 + 96) |= 0x40000000000uLL;
          }
          v77 = 41;
          _ReadStatusReg(SP_EL0);
          do
          {
            v80 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8 * v77);
            if ( v80
              && *(_BYTE *)(v80 + 52) == 1
              && ((*(_QWORD *)(a1 + 96) >> 42) & 1) == ((*(_WORD *)(v80 + 66) & 0x2000) == 0) )
            {
              v81 = kmemdup_noprof(v80, 104, 3264);
              if ( !v81 )
              {
                v63 = -12;
                goto LABEL_232;
              }
              *(_WORD *)(v81 + 66) ^= 0x2000u;
              *(_QWORD *)(*(_QWORD *)(a1 + 72) + 8 * v77) = v81;
              *(_BYTE *)(a1 + 1505) |= 1LL << ((unsigned __int8)v77 - 41);
            }
            ++v77;
          }
          while ( v77 != 47 );
          v82 = wiphy_register(*(_QWORD *)(a1 + 72));
          if ( (v82 & 0x80000000) != 0 )
          {
            v63 = v82;
          }
          else
          {
            v83 = ieee80211_check_wbrf_support(a1);
            rtnl_lock(v83);
            mutex_lock(*(_QWORD *)(a1 + 72));
            v84 = *(_QWORD *)(a1 + 72);
            if ( (*(_WORD *)(v84 + 96) & 4) != 0 && (*(_QWORD *)(a1 + 96) & 0x2000) == 0 )
            {
              memset(v101, 0, 32);
              if ( (unsigned int)ieee80211_if_add(a1, "wlan%d", 1u, nullptr, 2u, (__int64)v101) )
                dev_warn(*(_QWORD *)(a1 + 72) + 392LL, "Failed to add default virtual iface\n");
              v84 = *(_QWORD *)(a1 + 72);
            }
            v85 = mutex_unlock(v84);
            rtnl_unlock(v85);
            *(_QWORD *)(a1 + 5104) = ieee80211_ifa_changed;
            v63 = register_inetaddr_notifier(a1 + 5104);
            if ( !v63 )
            {
              *(_QWORD *)(a1 + 5128) = ieee80211_ifa6_changed;
              result = register_inet6addr_notifier(a1 + 5128);
              if ( !(_DWORD)result )
                goto LABEL_117;
              v63 = result;
              unregister_inetaddr_notifier(a1 + 5104);
            }
            v82 = wiphy_unregister(*(_QWORD *)(a1 + 72));
          }
          rtnl_lock(v82);
          rate_control_deinitialize(a1);
          v86 = ieee80211_remove_interfaces(a1);
          rtnl_unlock(v86);
        }
LABEL_232:
        ieee80211_txq_teardown_flows(a1);
      }
      destroy_workqueue(*(_QWORD *)(a1 + 472));
    }
    else
    {
      v63 = -12;
    }
    goto LABEL_234;
  }
  v63 = -22;
LABEL_234:
  if ( *(_BYTE *)(a1 + 1360) == 1 )
  {
    kfree(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 160LL));
    *(_BYTE *)(a1 + 1360) = 0;
  }
  kfree(*(_QWORD *)(a1 + 4744));
  result = v63;
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return result;
}
