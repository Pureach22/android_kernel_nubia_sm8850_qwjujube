__int64 __fastcall ieee80211_he_cap_ie_to_sta_he_cap(
        __int64 result,
        __int64 a2,
        __int64 *a3,
        unsigned __int8 a4,
        _WORD *a5,
        __int64 a6)
{
  __int64 v6; // x20
  int v7; // w8
  unsigned int v8; // w8
  __int64 v9; // x9
  char v10; // w10
  __int64 v11; // x8
  unsigned int v12; // w23
  __int64 v13; // x10
  unsigned int v14; // w9
  char v15; // w21
  unsigned int v16; // w26
  unsigned int v17; // w27
  unsigned int v18; // w24
  unsigned int v19; // w25
  unsigned int v20; // w10
  int v21; // w9
  size_t v22; // x19
  size_t v23; // x9
  unsigned int v24; // w22
  char v25; // w21
  _WORD *v26; // x22
  __int64 v27; // x24
  __int64 *v28; // x25
  char v29; // w8
  __int64 v30; // x9
  __int64 v31; // x10
  __int64 v32; // x23
  size_t v33; // x2
  __int64 v34; // x9
  int v35; // w10
  int v36; // w10
  __int16 v37; // w11
  __int16 v38; // w10
  unsigned int v39; // w9
  unsigned int v40; // w10
  int i; // w8
  unsigned int v42; // w13
  unsigned int v43; // w14
  unsigned int v44; // w15
  int v45; // w17
  bool v46; // zf
  unsigned int v47; // w13
  int v48; // w16
  int v49; // w14
  int v50; // w16
  int v51; // w14
  int v52; // w15
  int v53; // w13
  int v54; // w13
  int v55; // w15
  char v56; // w8
  unsigned int v57; // w10
  unsigned int v58; // w13
  int j; // w9
  unsigned int v60; // w14
  unsigned int v61; // w15
  unsigned int v62; // w16
  unsigned int v63; // w14
  int v64; // w17
  int v65; // w15
  int v66; // w17
  int v67; // w15
  int v68; // w16
  int v69; // w14
  int v70; // w14
  int v71; // w16
  unsigned int v72; // w9
  unsigned int v73; // w12
  int k; // w8
  unsigned int v75; // w13
  unsigned int v76; // w14
  unsigned int v77; // w15
  int v78; // w17
  unsigned int v79; // w13
  int v80; // w16
  int v81; // w14
  int v82; // w16
  int v83; // w14
  int v84; // w15
  int v85; // w13
  int v86; // w13
  int v87; // w15
  char v88; // [xsp+4h] [xbp-2Ch]
  unsigned int v89; // [xsp+8h] [xbp-28h]
  __int64 *v90; // [xsp+8h] [xbp-28h]
  unsigned int v91; // [xsp+10h] [xbp-20h]
  _WORD *v92; // [xsp+10h] [xbp-20h]
  unsigned int v93; // [xsp+18h] [xbp-18h]
  unsigned int v94; // [xsp+1Ch] [xbp-14h]
  size_t v95; // [xsp+20h] [xbp-10h]
  __int64 v96; // [xsp+28h] [xbp-8h]
  __int64 v97; // [xsp+28h] [xbp-8h]

  v6 = *(_QWORD *)(a6 + 920);
  *(_QWORD *)(v6 + 131) = 0;
  *(_QWORD *)(v6 + 124) = 0;
  *(_QWORD *)(v6 + 116) = 0;
  *(_QWORD *)(v6 + 108) = 0;
  *(_QWORD *)(v6 + 84) = 0;
  *(_QWORD *)(v6 + 100) = 0;
  *(_QWORD *)(v6 + 92) = 0;
  if ( !a3 )
    return result;
  v7 = *(_DWORD *)(result + 4720);
  if ( *(_BYTE *)(result + 5848) == 1 )
  {
    if ( v7 == 2 )
    {
      v8 = 8;
      v9 = *(unsigned __int16 *)(a2 + 92);
      if ( !*(_WORD *)(a2 + 92) )
        return result;
      goto LABEL_9;
    }
    if ( v7 == 3 )
    {
      v8 = 9;
      v9 = *(unsigned __int16 *)(a2 + 92);
      if ( !*(_WORD *)(a2 + 92) )
        return result;
      goto LABEL_9;
    }
  }
  v8 = (unsigned __int8)*(_DWORD *)(result + 4720);
  if ( v8 >= 0xC )
  {
    __break(0x800u);
    return result;
  }
  v9 = *(unsigned __int16 *)(a2 + 92);
  if ( *(_WORD *)(a2 + 92) )
  {
LABEL_9:
    if ( v8 == 4 )
      v10 = 3;
    else
      v10 = v8;
    v11 = *(_QWORD *)(a2 + 96);
    v12 = a4;
    v13 = 1LL << v10;
    while ( ((unsigned __int16)v13 & *(_WORD *)v11) == 0 )
    {
      --v9;
      v11 += 128;
      if ( !v9 )
        return result;
    }
    if ( v11 && v11 != -2 && (*(_BYTE *)(v11 + 2) & 1) != 0 )
    {
      v14 = *((unsigned __int8 *)a3 + 6);
      v15 = *(_BYTE *)(v11 + 9);
      v16 = *(unsigned __int16 *)(v11 + 20);
      v17 = *(unsigned __int16 *)(v11 + 22);
      v94 = *(unsigned __int16 *)(v11 + 24);
      v18 = *(unsigned __int16 *)(v11 + 28);
      v19 = *(unsigned __int16 *)(v11 + 30);
      v93 = *(unsigned __int16 *)(v11 + 26);
      v20 = v14 >> 2;
      v21 = (v14 & 8) != 0 ? 8 : 4;
      v22 = v21 + (v20 & 4);
      v23 = v22 + 17;
      if ( *((char *)a3 + 12) < 0 )
      {
        v88 = *(_BYTE *)(v11 + 9);
        v25 = *((_BYTE *)a3 + v23);
        v26 = a5;
        v91 = *(unsigned __int16 *)(v11 + 28);
        v27 = a6;
        v96 = a2;
        v89 = *(unsigned __int16 *)(v11 + 30);
        v28 = a3;
        result = _sw_hweight8(v25 & 0x78);
        v29 = 6 * (v25 & 7) + 6;
        a3 = v28;
        v15 = v88;
        v19 = v89;
        a6 = v27;
        v18 = v91;
        a5 = v26;
        v23 = v22 + 17;
        a2 = v96;
        v24 = ((unsigned int)(unsigned __int8)(result * v29 + 7) + 7) >> 3;
      }
      else
      {
        v24 = 0;
      }
      if ( v24 + (unsigned int)v23 <= v12 )
      {
        v95 = v23;
        v97 = a2;
        v31 = *a3;
        v30 = a3[1];
        v90 = a3;
        v92 = a5;
        v32 = a6;
        *(_BYTE *)(v6 + 101) = *((_BYTE *)a3 + 16);
        *(_QWORD *)(v6 + 93) = v30;
        *(_QWORD *)(v6 + 85) = v31;
        memcpy((void *)(v6 + 102), (char *)a3 + 17, v22);
        if ( *(char *)(v6 + 97) < 0 )
        {
          v33 = v24;
          if ( v24 >= 0x1A && (ieee80211_he_cap_ie_to_sta_he_cap___already_done_4 & 1) == 0 )
          {
            ieee80211_he_cap_ie_to_sta_he_cap___already_done_4 = 1;
            _warn_printk(
              "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
              v24,
              "field \"he_cap->ppe_thres\" at ../soc-repo/net/mac80211/he.c:159",
              0x19u);
            v33 = v24;
            __break(0x800u);
          }
          memcpy((void *)(v6 + 114), (char *)v90 + v95, v33);
        }
        *(_BYTE *)(v6 + 84) = 1;
        *(_DWORD *)(v32 + 912) = ((__int64 (__fastcall *)(__int64, _QWORD))ieee80211_sta_cap_rx_bw)(v32, 0);
        result = ieee80211_sta_cur_vht_bw(v32, 0);
        *(_DWORD *)(*(_QWORD *)(v32 + 920) + 232LL) = result;
        if ( v92 && *(_DWORD *)(v97 + 16) == 3 )
        {
          v34 = *(_QWORD *)(v32 + 32);
          if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(v34 + 80) + 4720LL) - 3) > 1 )
            v35 = 1;
          else
            v35 = dword_C1530[((unsigned __int64)(unsigned __int16)*v92 >> 9) & 3];
          *(_DWORD *)(*(_QWORD *)(v32 + 920) + 16LL) = v35;
          v36 = *(unsigned __int8 *)v92 >> 6;
          if ( v36 == 1 )
            v37 = 7991;
          else
            v37 = 3895;
          if ( v36 == 2 )
            v38 = 11454;
          else
            v38 = v37;
          *(_WORD *)(*(_QWORD *)(v32 + 920) + 194LL) = v38;
          result = ieee80211_sta_recalc_aggregates(v34 + 2688);
          *(_WORD *)(*(_QWORD *)(v32 + 920) + 139LL) = *v92;
        }
        v39 = *(unsigned __int16 *)(v6 + 104);
        v40 = *(unsigned __int16 *)(v6 + 102);
        for ( i = 0; i != 16; i += 2 )
        {
          v42 = (v16 >> i) & 3;
          v43 = (v39 >> i) & 3;
          v44 = (v17 >> i) & 3;
          if ( v42 >= v43 )
            v45 = (v39 >> i) & 3;
          else
            v45 = (v16 >> i) & 3;
          v46 = v42 == 3;
          v47 = (v40 >> i) & 3;
          if ( v46 )
            v48 = 3;
          else
            v48 = v45;
          if ( v43 == 3 )
            v49 = 3;
          else
            v49 = v48;
          if ( v44 >= v47 )
            v50 = (v40 >> i) & 3;
          else
            v50 = (v17 >> i) & 3;
          v51 = v49 << i;
          if ( v44 == 3 )
            v52 = 3;
          else
            v52 = v50;
          if ( v47 == 3 )
            v53 = 3;
          else
            v53 = v52;
          v54 = v53 << i;
          v55 = (unsigned __int16)~(3 << i);
          v39 = v39 & v55 | (unsigned __int16)v51;
          v40 = v40 & v55 | (unsigned __int16)v54;
        }
        v56 = *(_BYTE *)(v6 + 91);
        *(_WORD *)(v6 + 102) = v40;
        *(_WORD *)(v6 + 104) = v39;
        if ( (v56 & 8) != 0 && (v15 & 8) != 0 )
        {
          v57 = *(unsigned __int16 *)(v6 + 108);
          v58 = *(unsigned __int16 *)(v6 + 106);
          for ( j = 0; j != 16; j += 2 )
          {
            v60 = (v94 >> j) & 3;
            v61 = (v57 >> j) & 3;
            v62 = (v93 >> j) & 3;
            if ( v60 >= v61 )
              result = v61;
            else
              result = v60;
            v46 = v60 == 3;
            v63 = (v58 >> j) & 3;
            if ( v46 )
              v64 = 3;
            else
              v64 = result;
            if ( v61 == 3 )
              v65 = 3;
            else
              v65 = v64;
            if ( v62 >= v63 )
              v66 = (v58 >> j) & 3;
            else
              v66 = (v93 >> j) & 3;
            v67 = v65 << j;
            if ( v62 == 3 )
              v68 = 3;
            else
              v68 = v66;
            if ( v63 == 3 )
              v69 = 3;
            else
              v69 = v68;
            v70 = v69 << j;
            v71 = (unsigned __int16)~(3 << j);
            v57 = v57 & v71 | (unsigned __int16)v67;
            v58 = v58 & v71 | (unsigned __int16)v70;
          }
          *(_WORD *)(v6 + 106) = v58;
          *(_WORD *)(v6 + 108) = v57;
        }
        else if ( (v56 & 8) != 0 && (v15 & 8) == 0 )
        {
          v56 &= ~8u;
          *(_DWORD *)(v6 + 106) = -1;
          *(_BYTE *)(v6 + 91) = v56;
        }
        if ( (v56 & 0x10) != 0 && (v15 & 0x10) != 0 )
        {
          v72 = *(unsigned __int16 *)(v6 + 112);
          v73 = *(unsigned __int16 *)(v6 + 110);
          for ( k = 0; k != 16; k += 2 )
          {
            v75 = (v18 >> k) & 3;
            v76 = (v72 >> k) & 3;
            v77 = (v19 >> k) & 3;
            if ( v75 >= v76 )
              v78 = (v72 >> k) & 3;
            else
              v78 = (v18 >> k) & 3;
            v46 = v75 == 3;
            v79 = (v73 >> k) & 3;
            if ( v46 )
              v80 = 3;
            else
              v80 = v78;
            if ( v76 == 3 )
              v81 = 3;
            else
              v81 = v80;
            if ( v77 >= v79 )
              v82 = (v73 >> k) & 3;
            else
              v82 = (v19 >> k) & 3;
            v83 = v81 << k;
            if ( v77 == 3 )
              v84 = 3;
            else
              v84 = v82;
            if ( v79 == 3 )
              v85 = 3;
            else
              v85 = v84;
            v86 = v85 << k;
            v87 = (unsigned __int16)~(3 << k);
            v72 = v72 & v87 | (unsigned __int16)v83;
            v73 = v73 & v87 | (unsigned __int16)v86;
          }
          *(_WORD *)(v6 + 110) = v73;
          *(_WORD *)(v6 + 112) = v72;
        }
        else if ( (v56 & 0x10) != 0 && (v15 & 0x10) == 0 )
        {
          *(_DWORD *)(v6 + 110) = -1;
          *(_BYTE *)(v6 + 91) = v56 & 0xEF;
        }
      }
    }
  }
  return result;
}
