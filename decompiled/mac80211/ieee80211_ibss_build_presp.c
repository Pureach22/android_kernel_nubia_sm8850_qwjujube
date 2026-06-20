__int64 __fastcall ieee80211_ibss_build_presp(
        __int64 a1,
        __int16 a2,
        unsigned int a3,
        __int16 a4,
        __int64 a5,
        unsigned int **a6,
        _BYTE *a7,
        _BYTE *a8)
{
  __int64 v10; // x23
  __int64 v12; // x26
  __int64 v14; // x24
  __int64 v15; // x21
  unsigned __int64 v16; // x22
  __int64 v17; // x19
  __int16 v18; // w9
  size_t v19; // x2
  int v20; // w8
  __int16 v21; // w10
  int v22; // w8
  __int64 v23; // x8
  int v24; // w9
  __int64 v25; // x10
  unsigned __int64 v26; // x8
  __int64 v27; // x27
  int v28; // w9
  int v29; // w11
  unsigned __int64 v30; // x10
  __int64 v31; // x12
  __int64 v32; // x13
  int v33; // w23
  unsigned int v34; // w28
  __int64 v35; // x15
  unsigned __int64 v36; // x24
  int v37; // w14
  __int64 v38; // x25
  __int64 v39; // x11
  unsigned __int64 v40; // x26
  char v41; // w0
  unsigned __int64 v42; // x9
  char v43; // w0
  char v44; // w11
  __int64 v45; // x21
  _BYTE *v46; // x24
  int v47; // w14
  unsigned __int64 v48; // x9
  __int64 v49; // x12
  __int64 v50; // x13
  size_t v51; // x2
  bool v52; // cf
  size_t v53; // x8
  size_t v54; // x1
  unsigned int v55; // w8
  int v56; // w8
  __int64 v58; // x9
  __int64 v59; // x10
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v64; // x23
  __int64 v65; // x0
  __int64 v66; // [xsp+10h] [xbp-50h]
  int v67; // [xsp+18h] [xbp-48h]
  __int64 v68; // [xsp+20h] [xbp-40h]
  __int64 v69; // [xsp+20h] [xbp-40h]
  unsigned int **v70; // [xsp+28h] [xbp-38h]
  unsigned int **v71; // [xsp+28h] [xbp-38h]
  __int64 v74; // [xsp+40h] [xbp-20h] BYREF
  _BYTE v75[14]; // [xsp+48h] [xbp-18h]
  __int64 v76; // [xsp+58h] [xbp-8h]

  v10 = a1;
  LOWORD(v12) = a4;
  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 1616);
  v15 = *(unsigned __int8 *)(a1 + 2385);
  v16 = v15 + 263;
  v17 = _kmalloc_noprof(v15 + 263, 3520);
  if ( !v17 )
    goto LABEL_73;
  while ( 1 )
  {
    *(_WORD *)(v17 + 72) = 80;
    *(_QWORD *)v17 = v17 + 72;
    v18 = *(_WORD *)(v10 + 5846);
    v19 = *(unsigned __int8 *)(v10 + 2384);
    *(_DWORD *)(v17 + 76) = -1;
    *(_WORD *)(v17 + 80) = -1;
    v20 = *(_DWORD *)(v10 + 5842);
    v21 = *(_WORD *)(v10 + 2350);
    *(_WORD *)(v17 + 86) = v18;
    *(_DWORD *)(v17 + 82) = v20;
    v22 = *(_DWORD *)(v10 + 2346);
    *(_WORD *)(v17 + 92) = v21;
    *(_DWORD *)(v17 + 88) = v22;
    *(_WORD *)(v17 + 104) = a2;
    *(_QWORD *)(v17 + 96) = a5;
    *(_WORD *)(v17 + 106) = v12;
    *(_BYTE *)(v17 + 108) = 0;
    *(_BYTE *)(v17 + 109) = v19;
    if ( v16 - 110 < v19 )
      goto LABEL_78;
    v12 = v17 + 110;
    memcpy((void *)(v17 + 110), (const void *)(v10 + 2352), v19);
    v23 = **a6;
    if ( (unsigned int)v23 < 6 )
      break;
    __break(0x5512u);
    v16 = v15 + 263;
    v69 = v10;
    v71 = a6;
    StatusReg = _ReadStatusReg(SP_EL0);
    v64 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_ibss_build_presp__alloc_tag;
    v65 = _kmalloc_noprof(v15 + 263, 3520);
    *(_QWORD *)(StatusReg + 80) = v64;
    v10 = v69;
    a6 = v71;
    v17 = v65;
    if ( !v65 )
      goto LABEL_73;
  }
  v24 = *((_DWORD *)a6 + 2);
  v25 = *(_QWORD *)(v14 + 72) + 8 * v23;
  v26 = *(unsigned __int8 *)(v10 + 2384);
  v27 = *(_QWORD *)(v25 + 328);
  if ( v24 == 6 )
    v28 = 32;
  else
    v28 = (v24 == 7) << 6;
  if ( a7 )
    *a7 = 0;
  v29 = *(_DWORD *)(v27 + 24);
  v30 = v26 + 110;
  v68 = v10;
  if ( v29 < 1 )
  {
    v34 = 0;
    v33 = 0;
  }
  else
  {
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v34 = 0;
    do
    {
      v35 = *(_QWORD *)(v27 + 8);
      if ( (v28 & ~*(_DWORD *)(v35 + v31)) == 0 )
      {
        if ( a7 && *(unsigned __int16 *)(v35 + v31 + 4) >= 0x6Fu )
        {
          *a7 = 1;
          v29 = *(_DWORD *)(v27 + 24);
        }
        ++v33;
        v34 |= 1LL << v32;
      }
      ++v32;
      v31 += 12;
    }
    while ( v32 < v29 );
  }
  v70 = a6;
  if ( v16 <= v30 )
    goto LABEL_59;
  v30 = v26 + 111;
  v66 = v14;
  v67 = v15;
  *(_BYTE *)(v12 + v26) = 1;
  a6 = (unsigned int **)(v12 + v26 + 2);
  if ( v16 <= v26 + 111 )
    goto LABEL_59;
  v36 = v26 + 112;
  if ( v33 >= 8 )
    v30 = 8;
  else
    v30 = (unsigned int)v33;
  *(_BYTE *)(v12 + v26 + 1) = v30;
  v37 = *(_DWORD *)(v27 + 24);
  if ( v37 < 1 )
  {
    LODWORD(v38) = 0;
    v40 = v26 + 112;
    v26 = *(unsigned int *)(v27 + 16);
    if ( (_DWORD)v26 )
      goto LABEL_32;
LABEL_35:
    if ( v16 > v40 )
    {
      v26 = v40 + 1;
      *(_BYTE *)a6 = 3;
      if ( v16 > v40 + 1 )
      {
        *((_BYTE *)a6 + 1) = 1;
        v41 = ieee80211_freq_khz_to_channel(1000 * (*v70)[1]);
        if ( v16 > v40 + 2 )
        {
          *((_BYTE *)a6 + 2) = v41;
          a6 = (unsigned int **)((char *)a6 + 3);
          v40 += 3LL;
          v36 += 3LL;
          if ( v16 > v40 )
            goto LABEL_39;
        }
      }
    }
    goto LABEL_59;
  }
  v38 = 0;
  v26 = 0;
  v39 = 4;
  v30 = a3;
  v40 = v36;
  while ( 1 )
  {
    if ( ((1LL << v38) & v34) == 0 )
      goto LABEL_26;
    if ( v16 <= v40 )
      goto LABEL_59;
    v26 = (unsigned int)(v26 + 1);
    ++v36;
    ++v40;
    *(_BYTE *)a6 = ((858993460 * (unsigned __int64)((unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v27 + 8) + v39) + 4)) >> 32)
                 | ((((1LL << v38) & a3) != 0) << 7);
    if ( (_DWORD)v26 == 8 )
      break;
    v37 = *(_DWORD *)(v27 + 24);
    a6 = (unsigned int **)((char *)a6 + 1);
LABEL_26:
    ++v38;
    v39 += 12;
    if ( v38 >= v37 )
      goto LABEL_31;
  }
  LODWORD(v38) = v38 + 1;
  a6 = (unsigned int **)((char *)a6 + 1);
LABEL_31:
  v26 = *(unsigned int *)(v27 + 16);
  if ( !(_DWORD)v26 )
    goto LABEL_35;
LABEL_32:
  if ( v16 <= v40 )
    goto LABEL_59;
LABEL_39:
  v26 = v40 + 1;
  *(_BYTE *)a6 = 6;
  if ( v16 <= v40 + 1 )
    goto LABEL_59;
  v26 = v40 + 2;
  *((_BYTE *)a6 + 1) = 2;
  if ( v16 <= v40 + 2 )
    goto LABEL_59;
  v26 = v40 + 3;
  *((_BYTE *)a6 + 2) = 0;
  if ( v16 <= v40 + 3 )
    goto LABEL_59;
  v26 = (unsigned __int64)a8;
  v42 = v40 + 4;
  *((_BYTE *)a6 + 3) = 0;
  if ( a8 )
  {
    if ( v16 > v42 )
    {
      v26 = v40 + 5;
      *((_BYTE *)a6 + 4) = 37;
      if ( v16 > v40 + 5 )
      {
        v26 = v40 + 6;
        *((_BYTE *)a6 + 5) = 3;
        if ( v16 > v40 + 6 )
        {
          *((_BYTE *)a6 + 6) = a8[409];
          v43 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(*(_QWORD *)a8 + 4LL)));
          if ( v16 > v40 + 7 )
          {
            *((_BYTE *)a6 + 7) = v43;
            v30 = v40 + 8;
            v26 = (unsigned int)((_DWORD)a6 + 8 - *(_DWORD *)v17);
            *(_WORD *)(v17 + 32) = (_WORD)a6 + 8 - *(_WORD *)v17;
            if ( v16 > v40 + 8 )
            {
              v30 = (unsigned __int64)a6 + 9;
              v42 = v40 + 9;
              v44 = a8[410];
              v26 = v36 + 9;
              *((_BYTE *)a6 + 8) = v44;
              *(_BYTE *)(v17 + 36) = v44;
              goto LABEL_50;
            }
          }
        }
      }
    }
LABEL_59:
    __break(1u);
LABEL_60:
    v45 = v68;
    v46 = (_BYTE *)v30;
  }
  else
  {
    v30 = (unsigned __int64)a6 + 4;
    v26 = v36 + 4;
LABEL_50:
    a6 = v70;
    if ( v33 < 9 )
      goto LABEL_60;
    v45 = v68;
    if ( v16 <= v42 )
      goto LABEL_59;
    *(_BYTE *)v30 = 50;
    v46 = (_BYTE *)(v30 + 2);
    if ( v16 <= v42 + 1 )
      goto LABEL_59;
    v26 += 2LL;
    *(_BYTE *)(v30 + 1) = v33 - 8;
    v47 = *(_DWORD *)(v27 + 24);
    if ( (int)v38 < v47 )
    {
      v48 = v42 + 2;
      v30 = v34;
      v49 = (unsigned int)v38;
      v50 = 12LL * (unsigned int)v38 + 4;
      do
      {
        if ( ((1LL << v49) & v34) != 0 )
        {
          if ( v16 <= v48 )
            goto LABEL_59;
          ++v48;
          ++v26;
          *v46++ = ((858993460 * (unsigned __int64)((unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v27 + 8) + v50) + 4)) >> 32)
                 | ((((1LL << v49) & a3) != 0) << 7);
          v47 = *(_DWORD *)(v27 + 24);
        }
        ++v49;
        v50 += 12;
      }
      while ( v49 < v47 );
    }
  }
  v51 = *(unsigned __int8 *)(v45 + 2385);
  if ( *(_BYTE *)(v45 + 2385) )
  {
    v52 = v16 >= v26;
    v53 = v16 - v26;
    if ( v52 )
      v54 = v53;
    else
      v54 = 0;
    if ( v54 >= v51 )
    {
      memcpy(v46, *(const void **)(v45 + 2392), v51);
      v46 += *(unsigned __int8 *)(v45 + 2385);
      goto LABEL_67;
    }
LABEL_78:
    _fortify_panic(17);
  }
LABEL_67:
  v55 = *((_DWORD *)a6 + 2);
  if ( (v55 > 7 || ((1 << v55) & 0xC1) == 0) && *(_BYTE *)(v27 + 30) == 1 )
  {
    v58 = *(_QWORD *)(v27 + 36);
    v59 = *(_QWORD *)(v27 + 42);
    v74 = *(_QWORD *)(v27 + 28);
    *(_QWORD *)v75 = v58;
    *(_QWORD *)&v75[6] = v59;
    ieee80211_apply_htcap_overrides(v45, (__int64)&v74);
    v60 = ieee80211_ie_build_ht_cap(v46, &v74, (unsigned __int16)v74);
    v61 = ieee80211_ie_build_ht_oper(v60, v27 + 28, a6, 0, 0);
    v46 = (_BYTE *)v61;
    if ( (unsigned int)(*((_DWORD *)a6 + 2) - 1) >= 2 && *(_BYTE *)(v27 + 52) == 1 )
    {
      v62 = ieee80211_ie_build_vht_cap(v61, v27 + 52, *(unsigned int *)(v27 + 56));
      v46 = (_BYTE *)ieee80211_ie_build_vht_oper(v62, v27 + 52, a6);
    }
  }
  if ( *(unsigned __int16 *)(v66 + 128) >= 4u )
    LODWORD(v46) = ieee80211_add_wmm_info_ie(v46, 0);
  v56 = (_DWORD)v46 - *(_DWORD *)v17;
  *(_DWORD *)(v17 + 16) = v56;
  if ( v67 + 191 < v56 )
  {
    __break(0x800u);
    kfree(v17);
    v17 = 0;
  }
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return v17;
}
