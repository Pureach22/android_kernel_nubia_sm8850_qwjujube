__int64 __fastcall wiphy_update_regulatory(__int64 result, int a2)
{
  __int64 v2; // x23
  void *v3; // x11
  int v4; // w8
  __int64 (__fastcall *v5)(__int64, void *); // x8
  __int64 v6; // x10
  __int64 *v7; // x11
  unsigned __int64 v8; // x21
  __int64 v9; // x28
  __int64 v10; // x19
  _DWORD *v11; // x22
  unsigned int v12; // w20
  _UNKNOWN **v13; // x25
  unsigned __int64 v14; // x24
  _DWORD *v15; // x27
  _DWORD *v16; // x0
  _DWORD *v17; // x23
  unsigned int v18; // w10
  int v19; // w11
  unsigned int v20; // w9
  int v21; // w8
  _DWORD *v22; // x24
  __int64 *v23; // x8
  __int64 *v24; // x8
  int v25; // w8
  int v26; // w0
  __int64 v27; // x8
  __int64 v28; // x9
  signed int v29; // w11
  int v30; // w10
  signed int v31; // w9
  signed int v32; // w9
  int v33; // w11
  signed int v34; // w8
  __int64 v35; // x9
  unsigned int v36; // w8
  __int64 v37; // x9
  int v38; // w8
  unsigned int v39; // w10
  unsigned int v40; // w10
  int v41; // w10
  __int64 v42; // x27
  int v43; // w20
  int v44; // w0
  __int64 v45; // x22
  __int64 v46; // x8
  unsigned int v47; // w9
  __int64 v48; // x1
  char does_bw_fit_range; // w0
  int v50; // w8
  __int64 v51; // x9
  unsigned int v52; // w10
  unsigned int v53; // w10
  unsigned int v54; // w8
  unsigned int v55; // w11
  int v56; // w12
  unsigned int v57; // w8
  unsigned int v58; // w12
  int v59; // w8
  __int64 v60; // x9
  unsigned int v61; // w10
  unsigned int v62; // w10
  unsigned int v63; // w10
  unsigned int v64; // w11
  int v65; // w8
  void **i; // x21
  __int64 v67; // x8
  __int64 v68; // x20
  unsigned int v69; // w22
  void *v70; // [xsp+8h] [xbp-68h]
  __int64 v71; // [xsp+10h] [xbp-60h]
  __int64 v72; // [xsp+18h] [xbp-58h]
  __int64 *v73; // [xsp+28h] [xbp-48h]
  __int64 *v75; // [xsp+38h] [xbp-38h]
  int v76; // [xsp+44h] [xbp-2Ch]
  __int64 v77; // [xsp+48h] [xbp-28h]
  __int64 v78; // [xsp+50h] [xbp-20h]
  __int64 v79; // [xsp+58h] [xbp-18h] BYREF
  int v80; // [xsp+60h] [xbp-10h]
  __int64 v81; // [xsp+68h] [xbp-8h]

  v2 = result;
  v81 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = last_request;
  v4 = *(_DWORD *)(result + 104);
  if ( (v4 & 0x80) != 0 || !last_request )
    goto LABEL_13;
  if ( !a2 && (v4 & 1) != 0 )
  {
LABEL_14:
    v5 = *(__int64 (__fastcall **)(__int64, void *))(result + 376);
    if ( !v5 )
      goto LABEL_18;
    goto LABEL_15;
  }
  if ( (*(_DWORD *)(result + 104) & 3) == 2
    && a2 != 3
    && !*(_QWORD *)(result + 384)
    && (*((_BYTE *)last_request + 28) != 48 || *((_BYTE *)last_request + 29) != 48)
    || *((_DWORD *)last_request + 5) == 1 && *((_DWORD *)last_request + 6) == 1 )
  {
LABEL_13:
    if ( a2 || (*(_DWORD *)(result + 104) & 0x81) != 1 )
      goto LABEL_18;
    goto LABEL_14;
  }
  v6 = 0;
  v71 = result + 328;
  v77 = result;
  v73 = (__int64 *)(result + 384);
  v70 = last_request;
  *((_DWORD *)last_request + 8) = *(_DWORD *)(cfg80211_regdomain + 24);
  do
  {
    v72 = v6;
    v7 = *(__int64 **)(v71 + 8 * v6);
    if ( v7 && *((_DWORD *)v7 + 5) )
    {
      v8 = 0;
      v9 = 60;
      v75 = *(__int64 **)(v71 + 8 * v6);
      do
      {
        v78 = *v7;
        v10 = *v7 + v9;
        v11 = last_request;
        v12 = *(unsigned __int16 *)(v10 - 52) + 1000 * *(_DWORD *)(v10 - 56);
        v13 = wiphy_idx_to_wiphy(*((unsigned int *)last_request + 4));
        v76 = *(_DWORD *)(v10 - 28);
        v14 = freq_reg_info(v77, v12);
        if ( v14 < 0xFFFFFFFFFFFFF001LL )
        {
          if ( (*((_DWORD *)last_request + 5) | 2) == 3 || (v24 = v73, !*v73) )
            v24 = &cfg80211_regdomain;
          v26 = reg_rule_to_chan_bw_flags(*v24, v14, v10 - 60);
          if ( v13 == (_UNKNOWN **)v77 && v13 && v11[5] == 2 && ((_BYTE)v13[13] & 2) != 0 )
          {
            v36 = *(_DWORD *)(v14 + 84);
            v37 = v78 + v9;
            v38 = v36 & 0xE00000
                | (v36 << 6) & 0x240
                | (v36 >> 1) & 8
                | (v36 >> 2) & 0x400
                | (v36 >> 8) & 0x20
                | (v36 >> 10) & 0x10
                | (v36 >> 8) & 0x180
                | (v36 >> 4) & 0x2000
                | (2 * v36) & 0x180000
                | (v36 >> 18) & 4
                | (2 * v36) & 0x2000000
                | (2 * ((v36 & 0x180) != 0))
                | v26;
            *(_DWORD *)(v10 - 28) = v38;
            *(_DWORD *)(v37 - 48) = v38;
            v39 = *(_DWORD *)(v14 + 12) / 0x64u;
            *(_DWORD *)(v37 - 24) = v39;
            *(_DWORD *)(v37 - 44) = v39;
            v40 = *(_DWORD *)(v14 + 16) / 0x64u;
            *(_DWORD *)(v37 - 20) = v40;
            *(_DWORD *)(v37 - 40) = v40;
            *(_DWORD *)(v37 - 36) = v40;
            if ( (v38 & 8) != 0 )
            {
              *(_DWORD *)(v37 - 4) = 60000;
              v41 = *(_DWORD *)(v14 + 88);
              if ( !v41 )
                v41 = 60000;
              *(_DWORD *)(v37 - 4) = v41;
            }
            v7 = v75;
            if ( (v38 & 4) != 0 )
              *(_BYTE *)(v78 + v9) = *(_BYTE *)(v14 + 93);
            goto LABEL_25;
          }
          v27 = v78 + v9;
          *(_DWORD *)(v27 - 16) = 0;
          v28 = jiffies;
          *(_BYTE *)(v27 - 32) = 0;
          *(_QWORD *)(v27 - 12) = v28;
          LODWORD(v28) = *(_DWORD *)(v14 + 84);
          v29 = *(_DWORD *)(v78 + v9 - 24);
          v30 = v28 & 0xE00000
              | ((_DWORD)v28 << 6) & 0x240
              | ((unsigned int)v28 >> 1) & 8
              | ((unsigned int)v28 >> 2) & 0x400
              | ((unsigned int)v28 >> 8) & 0x20
              | ((unsigned int)v28 >> 10) & 0x10
              | ((unsigned int)v28 >> 8) & 0x180
              | ((unsigned int)v28 >> 4) & 0x2000
              | (2 * v28) & 0x180000
              | ((unsigned int)v28 >> 18) & 4
              | (2 * v28) & 0x2000000
              | (2 * ((v28 & 0x180) != 0))
              | v76
              | v26;
          *(_DWORD *)(v27 - 48) = v30;
          v31 = *(_DWORD *)(v14 + 12) / 0x64u;
          if ( v29 < v31 )
            v31 = v29;
          *(_DWORD *)(v27 - 44) = v31;
          v32 = *(_DWORD *)(v14 + 16) / 0x64u;
          *(_DWORD *)(v27 - 36) = v32;
          if ( (v30 & 8) != 0 )
          {
            v33 = *(_DWORD *)(v14 + 88);
            if ( !v33 )
              v33 = 60000;
            *(_DWORD *)(v27 - 4) = v33;
          }
          v7 = v75;
          if ( (v30 & 4) != 0 )
            *(_BYTE *)(v78 + v9) = *(_BYTE *)(v14 + 93);
          v34 = *(_DWORD *)(v78 + v9 - 20);
          if ( !v34 )
          {
            *(_DWORD *)(v78 + v9 - 40) = v32;
            goto LABEL_25;
          }
          if ( a2 == 3 && (*(_BYTE *)(v77 + 104) & 8) != 0 )
          {
            *(_DWORD *)(v78 + v9 - 40) = v32;
            goto LABEL_25;
          }
          if ( v34 >= v32 )
            v34 = v32;
          v35 = v78 + v9;
        }
        else
        {
          v15 = (_DWORD *)freq_reg_info(v77, v12 - 20000);
          v16 = (_DWORD *)freq_reg_info(v77, v12 + 20000);
          if ( (unsigned __int64)v15 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_38;
          v17 = v16;
          if ( (unsigned __int64)v16 > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_38;
          v80 = 0;
          v79 = 0;
          if ( v15[1] != *v16 )
            goto LABEL_38;
          v19 = v16[1];
          v18 = v16[2];
          v20 = v15[2];
          LODWORD(v79) = *v15;
          HIDWORD(v79) = v19;
          v21 = v20 >= v18 ? v18 : v20;
          v80 = v21;
          if ( (cfg80211_does_bw_fit_range(&v79, v12, 20000) & 1) == 0 )
          {
LABEL_38:
            v7 = v75;
            if ( a2 != 3 || v14 != -34 )
            {
              if ( v11[5] == 2 && v13 && v13 == (_UNKNOWN **)v77 && ((_BYTE)v13[13] & 2) != 0 )
              {
                v25 = *(_DWORD *)(v10 - 28) | 1;
                *(_DWORD *)(v10 - 28) = v25;
                *(_DWORD *)(v78 + v9 - 48) = v25;
              }
              else
              {
                *(_DWORD *)(v78 + v9 - 48) |= 1u;
              }
            }
            goto LABEL_25;
          }
          v22 = v15;
          if ( (*((_DWORD *)last_request + 5) | 2) == 3 || (v23 = v73, !*v73) )
            v23 = &cfg80211_regdomain;
          v42 = *v23;
          v43 = reg_rule_to_chan_bw_flags(*v23, v22, v10 - 60);
          v44 = reg_rule_to_chan_bw_flags(v42, v17, v10 - 60);
          if ( v13 == (_UNKNOWN **)v77 && v13 && v11[5] == 2 && ((_BYTE)v13[13] & 2) != 0 )
          {
            v57 = v22[21];
            v58 = v17[21];
            v59 = v57 & 0xE00000
                | (v57 << 6) & 0x240
                | (v57 >> 1) & 8
                | (v57 >> 2) & 0x400
                | (v57 >> 8) & 0x20
                | (v57 >> 10) & 0x10
                | (v57 >> 8) & 0x180
                | (v57 >> 4) & 0x2000
                | (2 * v57) & 0x180000
                | (v57 >> 18) & 4
                | (2 * v57) & 0x2000000
                | v58 & 0xE00000
                | (2 * ((v57 & 0x180) != 0))
                | (v58 >> 1) & 8
                | (v58 << 6) & 0x240
                | (v58 >> 2) & 0x400
                | (v58 >> 8) & 0x20
                | (v58 >> 10) & 0x10
                | (v58 >> 8) & 0x180
                | (v58 >> 4) & 0x2000
                | (2 * v58) & 0x180000
                | (v58 >> 18) & 4
                | (2 * v58) & 0x2000000
                | (2 * ((v58 & 0x180) != 0))
                | v43
                | v44;
            v60 = v78 + v9;
            *(_DWORD *)(v78 + v9 - 48) = v59;
            *(_DWORD *)(v10 - 28) = v59;
            v61 = v22[3] / 0x64u;
            if ( v61 >= v17[3] / 0x64u )
              v61 = v17[3] / 0x64u;
            *(_DWORD *)(v60 - 44) = v61;
            *(_DWORD *)(v60 - 24) = v61;
            v62 = v22[4] / 0x64u;
            if ( v62 >= v17[4] / 0x64u )
              v62 = v17[4] / 0x64u;
            *(_DWORD *)(v60 - 40) = v62;
            *(_DWORD *)(v60 - 36) = v62;
            *(_DWORD *)(v60 - 20) = v62;
            if ( (v59 & 8) != 0 )
            {
              *(_DWORD *)(v60 - 4) = 60000;
              v63 = v22[22];
              v64 = v17[22];
              if ( v63 | v64 )
              {
                if ( v63 <= v64 )
                  v63 = v17[22];
                *(_DWORD *)(v60 - 4) = v63;
              }
            }
            v7 = v75;
            if ( (*((_BYTE *)v22 + 86) & 0x10) != 0 && (*((_BYTE *)v17 + 86) & 0x10) != 0 )
            {
              v65 = *((char *)v22 + 93);
              if ( v65 >= *((char *)v17 + 93) )
                LOBYTE(v65) = *((_BYTE *)v17 + 93);
              *(_BYTE *)(v78 + v9) = v65;
            }
            else
            {
              *(_DWORD *)(v60 - 48) = v59 & 0xFFEFFFFF;
            }
            goto LABEL_25;
          }
          v45 = v78 + v9;
          *(_DWORD *)(v45 - 16) = 0;
          v46 = jiffies;
          *(_BYTE *)(v45 - 32) = 0;
          *(_QWORD *)(v45 - 12) = v46;
          v47 = v22[21];
          LODWORD(v46) = v17[21];
          v48 = (unsigned int)*(unsigned __int16 *)(v10 - 52) + 1000 * *(_DWORD *)(v10 - 56);
          *(_DWORD *)(v45 - 48) = v47 & 0xE00000
                                | (v47 << 6) & 0x240
                                | (v47 >> 1) & 8
                                | (v47 >> 2) & 0x400
                                | (v47 >> 8) & 0x20
                                | (v47 >> 10) & 0x10
                                | (v47 >> 8) & 0x180
                                | (v47 >> 4) & 0x2000
                                | (2 * v47) & 0x180000
                                | (v47 >> 18) & 4
                                | (2 * v47) & 0x2000000
                                | v46 & 0xE00000
                                | (2 * ((v47 & 0x180) != 0))
                                | ((unsigned int)v46 >> 1) & 8
                                | ((_DWORD)v46 << 6) & 0x240
                                | ((unsigned int)v46 >> 2) & 0x400
                                | ((unsigned int)v46 >> 8) & 0x20
                                | ((unsigned int)v46 >> 10) & 0x10
                                | ((unsigned int)v46 >> 8) & 0x180
                                | ((unsigned int)v46 >> 4) & 0x2000
                                | (2 * v46) & 0x180000
                                | ((unsigned int)v46 >> 18) & 4
                                | (2 * v46) & 0x2000000
                                | (2 * ((v46 & 0x180) != 0))
                                | v76
                                | v43
                                | v44;
          if ( (cfg80211_does_bw_fit_range(&v79, v48, 10000) & 1) != 0 )
            *(_DWORD *)(v45 - 48) &= ~0x1000u;
          does_bw_fit_range = cfg80211_does_bw_fit_range(
                                &v79,
                                (unsigned int)*(unsigned __int16 *)(v10 - 52) + 1000 * *(_DWORD *)(v10 - 56),
                                20000);
          v50 = *(_DWORD *)(v45 - 48);
          if ( (does_bw_fit_range & 1) != 0 )
          {
            v50 &= ~0x800u;
            *(_DWORD *)(v45 - 48) = v50;
          }
          v51 = v78 + v9;
          v52 = v17[3] / 0x64u;
          if ( v22[3] / 0x64u < v52 )
            v52 = v22[3] / 0x64u;
          if ( *(_DWORD *)(v78 + v9 - 24) < (signed int)v52 )
            v52 = *(_DWORD *)(v78 + v9 - 24);
          *(_DWORD *)(v51 - 44) = v52;
          v53 = v22[4] / 0x64u;
          if ( v53 >= v17[4] / 0x64u )
            v53 = v17[4] / 0x64u;
          *(_DWORD *)(v51 - 36) = v53;
          if ( (v50 & 8) != 0 )
          {
            v54 = v22[22];
            v55 = v17[22];
            v56 = v54 | v55;
            if ( v54 <= v55 )
              v54 = v17[22];
            if ( !v56 )
              v54 = 60000;
            *(_DWORD *)(v51 - 4) = v54;
          }
          v34 = *(_DWORD *)(v51 - 20);
          v7 = v75;
          if ( !v34 || a2 == 3 && (*(_BYTE *)(v77 + 104) & 8) != 0 )
          {
            *(_DWORD *)(v78 + v9 - 40) = v53;
            goto LABEL_25;
          }
          v35 = v78 + v9;
          if ( v34 >= (int)v53 )
            v34 = v53;
        }
        *(_DWORD *)(v35 - 40) = v34;
LABEL_25:
        ++v8;
        v9 += 64;
      }
      while ( v8 < *((unsigned int *)v7 + 5) );
    }
    v6 = v72 + 1;
  }
  while ( v72 != 5 );
  v2 = v77;
  if ( last_request )
  {
    for ( i = (void **)reg_beacon_list; i != (void **)&reg_beacon_list; i = (void **)*i )
    {
      v67 = *((unsigned int *)i + 4);
      if ( (unsigned int)v67 >= 6 )
        __break(0x5512u);
      v68 = *(_QWORD *)(v71 + 8 * v67);
      if ( v68 && *(_DWORD *)(v68 + 20) )
      {
        v69 = 0;
        do
          handle_reg_beacon(v77, v69++, i);
        while ( v69 < *(_DWORD *)(v68 + 20) );
      }
    }
  }
  result = ((__int64 (__fastcall *)(__int64))reg_process_ht_flags)(v77);
  v5 = *(__int64 (__fastcall **)(__int64, void *))(v77 + 376);
  v3 = v70;
  if ( v5 )
  {
LABEL_15:
    if ( *((_DWORD *)v5 - 1) != -1916906463 )
      __break(0x8228u);
    result = v5(v2, v3);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
