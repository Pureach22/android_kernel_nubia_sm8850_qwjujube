_QWORD *__fastcall ieee802_11_parse_elems_full(int *a1)
{
  unsigned __int64 v2; // x21
  __int64 v3; // x0
  _QWORD *v4; // x0
  _QWORD *v5; // x19
  __int64 v6; // x8
  __int64 v7; // x9
  _QWORD *v8; // x24
  __int64 v9; // x28
  void *v10; // x21
  signed __int64 v11; // x22
  _BYTE *v12; // x25
  unsigned __int64 v13; // x9
  _BYTE *v14; // x23
  unsigned int v15; // w22
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w8
  int v19; // w8
  char v20; // w9
  int v21; // w8
  __int64 v22; // x3
  unsigned __int8 v23; // w10
  __int64 v24; // x9
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x2
  unsigned __int64 v28; // x0
  unsigned __int16 *v29; // x1
  int v30; // w8
  unsigned __int64 v31; // x2
  unsigned int v32; // w9
  unsigned int v33; // w10
  unsigned __int64 v34; // x9
  int v35; // w9
  bool v36; // zf
  unsigned int v37; // w10
  int v38; // w10
  __int64 v39; // x8
  __int64 v40; // x10
  unsigned __int64 v41; // x9
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  _BYTE *v45; // x8
  __int64 v46; // x8
  unsigned int v47; // w9
  __int64 v49; // x9
  _BYTE *v50; // x0
  unsigned int v51; // w9
  unsigned __int8 v52; // w11
  char *v53; // x12
  unsigned __int8 v54; // w11
  char *v55; // x12
  unsigned __int64 v56; // x13
  unsigned __int64 v57; // x11
  unsigned __int16 *v58; // x12
  unsigned int v59; // w13
  int v60; // w14
  char v61; // w14
  __int64 v62; // x15
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x8
  _BYTE *v66; // x27
  _BYTE *v67; // x24
  unsigned __int8 *v68; // x26
  __int64 v69; // x9
  __int64 elem_match; // x0
  unsigned __int8 *v71; // x10
  unsigned __int64 v72; // x11
  unsigned __int64 v73; // x12
  unsigned __int64 v74; // x9
  __int64 v75; // x10
  char v76; // [xsp+Ch] [xbp-64h]
  _BYTE *v77; // [xsp+10h] [xbp-60h]
  __int64 v78; // [xsp+18h] [xbp-58h]
  __int64 v79; // [xsp+20h] [xbp-50h] BYREF
  __int64 v80; // [xsp+28h] [xbp-48h]
  unsigned __int64 v81; // [xsp+30h] [xbp-40h]
  _QWORD v82[4]; // [xsp+38h] [xbp-38h] BYREF
  int v83; // [xsp+58h] [xbp-18h]
  int v84; // [xsp+5Ch] [xbp-14h]
  char v85[4]; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v86; // [xsp+68h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 3LL * *((_QWORD *)a1 + 2);
  if ( v2 >= 0xFFFFFFFFFFFFFCE0LL )
    v3 = -1;
  else
    v3 = v2 + 800;
  v4 = (_QWORD *)_kmalloc_noprof(v3, 2336);
  v5 = v4;
  if ( !v4 )
    goto LABEL_50;
  v6 = *((_QWORD *)a1 + 1);
  v7 = *((_QWORD *)a1 + 2);
  v8 = v4 + 100;
  v4[98] = v2;
  v4[99] = v4 + 100;
  *v4 = v6;
  v4[1] = v7;
  ieee80211_clear_tpe(v4 + 61);
  ieee80211_clear_tpe(v5 + 74);
  v9 = *((_QWORD *)a1 + 6);
  v10 = (void *)v5[99];
  if ( v9 && *(_QWORD *)(v9 + 40) && (v11 = *((_QWORD *)a1 + 2), v11 >= 2) )
  {
    v12 = *((_BYTE **)a1 + 1);
    v13 = *((_QWORD *)a1 + 2);
    v76 = 0;
    v14 = &v12[v11];
    v77 = v12;
    LODWORD(v78) = 0;
    do
    {
      v65 = (unsigned __int8)v12[1];
      if ( v13 < v65 + 2 )
        break;
      if ( (unsigned int)v65 >= 2 && *v12 == 71 )
      {
        v66 = v12 + 2;
        v67 = v12 + 3;
        if ( v65 - 1 >= 2 && (unsigned int)(unsigned __int8)v12[2] - 1 <= 7 )
        {
          v68 = v12 + 4;
          if ( v65 - 1 >= (unsigned __int64)(unsigned __int8)v12[4] + 2 )
          {
            LODWORD(v69) = (unsigned __int8)v12[4];
            while ( 1 )
            {
              if ( (unsigned int)v69 >= 4 && !*v67 && v67[2] == 83 && v67[3] == 2 )
              {
                memset(v10, 0, v11);
                v78 = cfg80211_merge_profile(v77, v11, v12, v67, v10, v11);
                elem_match = cfg80211_find_elem_match(85, v10, v78, 0, 0, 0);
                if ( elem_match )
                {
                  if ( *(_BYTE *)(elem_match + 1) )
                  {
                    if ( *(_BYTE *)(elem_match + 2) )
                    {
                      v71 = *(unsigned __int8 **)(v9 + 40);
                      v72 = ((unsigned __int64)v71[72] << 16) | ((unsigned __int64)v71[73] << 8);
                      v73 = ((unsigned __int64)v71[75] << 16) | ((unsigned __int64)v71[76] << 8);
                      v74 = (((v73 | ((v72 | v71[74]) << 24) | v71[77]) & (0xFFFFFFFFFFFFFFFFLL >> -*v66))
                           + *(unsigned __int8 *)(elem_match + 2))
                          & (0xFFFFFFFFFFFFFFFFLL >> -*v66)
                          | (v73 | ((v72 | v71[74]) << 24) | v71[77]) & ~(0xFFFFFFFFFFFFFFFFLL >> -*v66);
                      if ( !((((unsigned int)v74 >> 8) & 0xFF0000
                            | (BYTE2(v74) << 24)
                            | (v74 >> 24) & 0xFF00
                            | BYTE5(v74))
                           ^ *(_DWORD *)(v9 + 72)
                           | *(unsigned __int16 *)(v9 + 76) ^ (bswap32(v74) >> 16)) )
                        break;
                    }
                  }
                }
              }
              v65 = (unsigned __int8)v12[1];
              v67 += *v68 + 2;
              v75 = &v66[v65] - v67;
              if ( v75 > 1 )
              {
                v68 = v67 + 1;
                v69 = (unsigned __int8)v67[1];
                if ( v75 >= (unsigned __int64)(v69 + 2) )
                  continue;
              }
              goto LABEL_85;
            }
            *((_BYTE *)v5 + 712) = *(_BYTE *)(elem_match + 1);
            v5[47] = elem_match + 2;
            v65 = (unsigned __int8)v12[1];
            v76 = 1;
          }
        }
      }
LABEL_85:
      v12 += v65 + 2;
      v13 = v14 - v12;
    }
    while ( v14 - v12 > 1 );
    v8 = v5 + 100;
    v16 = v5[99];
    if ( (v76 & 1) != 0 )
      v15 = v78;
    else
      v15 = 0;
  }
  else
  {
    v15 = 0;
    v16 = v5[99];
  }
  v5[99] = v16 + (int)v15;
  LOBYTE(v79) = 56;
  v17 = cfg80211_find_elem_match(255, v10, v15, &v79, 1, 0);
  *((_DWORD *)v5 + 4) = ieee802_11_parse_elems_full(a1, v5, v17);
  if ( v15 )
  {
    v18 = *a1;
    v80 = (__int64)v10;
    v81 = (int)v15;
    v79 = v18;
    LOBYTE(v18) = *((_BYTE *)a1 + 24);
    memset((char *)v82 + 1, 0, 24);
    LOBYTE(v82[0]) = v18;
    v19 = a1[14];
    v82[3] = 0;
    v83 = v19;
    v84 = 0;
    ieee802_11_parse_elems_full(&v79, v5, 0);
  }
  v20 = *((_BYTE *)a1 + 24);
  v21 = *a1;
  v81 = 0;
  memset(v82, 0, sizeof(v82));
  v22 = v5[99];
  v23 = *((_BYTE *)a1 + 60);
  LOBYTE(v82[0]) = v20;
  v24 = v5[98];
  v25 = v5[96];
  v79 = 0;
  v26 = *v5;
  v27 = v5[1];
  LODWORD(v79) = v21;
  v83 = -1;
  v84 = v23;
  v80 = 0;
  v28 = cfg80211_defragment_element(v25, v26, v27, v22, (char *)v8 + v24 - v22, 242);
  if ( (v28 & 0x8000000000000000LL) == 0 )
  {
    v29 = (unsigned __int16 *)v5[99];
    v30 = a1[14];
    v31 = v28;
    v5[90] = v28;
    v5[56] = v29;
    v5[99] = (char *)v29 + v28;
    if ( v30 != -1 )
    {
      if ( v28 < 2 || !v29 )
        goto LABEL_37;
      v32 = *v29;
      v33 = v32 & 7;
      if ( v33 <= 1 )
      {
        if ( (v32 & 7) != 0 )
        {
          if ( v33 != 1 )
            goto LABEL_52;
          if ( (v32 & 0x10) != 0 )
            LOBYTE(v35) = 2;
          else
            LOBYTE(v35) = 1;
        }
        else
        {
          if ( (v32 & 0x10) != 0 )
            v38 = 8;
          else
            v38 = 7;
          v35 = v38
              + (((unsigned __int8)(v32 & 0xE0) >> 5) & 1)
              + (((unsigned __int8)v32 >> 5) & 2)
              + ((v32 >> 6) & 2)
              + ((v32 >> 7) & 2)
              + ((v32 >> 9) & 1);
        }
      }
      else
      {
        if ( v33 == 2 )
        {
          v36 = (v32 & 0x10) == 0;
          v34 = 8;
          if ( v36 )
            v34 = 2;
LABEL_28:
          if ( v34 <= v28 )
          {
            LOBYTE(v37) = *((_BYTE *)v29 + 2);
LABEL_51:
            v49 = (unsigned __int8)(v37 + 2);
            goto LABEL_53;
          }
LABEL_37:
          v39 = v5[93];
          if ( v39 )
          {
            v40 = *(unsigned __int8 *)(v39 + 2);
            v41 = v5[94];
            if ( v41 >= v40 + 6 )
            {
              v80 = v39 + v40 + 6;
              v81 = v41 - (v40 + 6);
              v85[0] = 56;
              v42 = cfg80211_find_elem_match(255, v80, v81, v85, 1, 0);
              ieee802_11_parse_elems_full(&v79, v5, v42);
            }
            else
            {
              v5[93] = 0;
              v5[94] = 0;
            }
          }
          goto LABEL_41;
        }
        if ( v33 != 3 )
        {
          if ( v33 == 4 )
          {
            v34 = 9;
            goto LABEL_28;
          }
LABEL_52:
          v49 = 0;
          __break(0x800u);
LABEL_53:
          v50 = (char *)v29 + v49;
          v51 = *v29 & 7;
          while ( 1 )
          {
            if ( v51 > 4 )
            {
              __break(0x800u);
              if ( (*v29 & 7u) > 4 )
              {
                v52 = 0;
                __break(0x800u);
              }
              else
              {
                v52 = *((_BYTE *)v29 + 2) + 2;
              }
              v53 = (char *)v29;
            }
            else
            {
              v52 = *((_BYTE *)v29 + 2) + 2;
              v53 = (char *)v29 + v52;
            }
            if ( &v53[v31 - v52] - v50 < 2 )
              goto LABEL_37;
            if ( (*v29 & 7u) > 4 )
            {
              __break(0x800u);
              if ( (*v29 & 7u) > 4 )
              {
                v54 = 0;
                __break(0x800u);
              }
              else
              {
                v54 = *((_BYTE *)v29 + 2) + 2;
              }
              v55 = (char *)v29;
            }
            else
            {
              v54 = *((_BYTE *)v29 + 2) + 2;
              v55 = (char *)v29 + v54;
            }
            v56 = v31 - v54;
            v57 = (unsigned __int8)v50[1];
            if ( &v55[v56] - v50 < (__int64)(v57 + 2) )
              goto LABEL_37;
            v58 = (unsigned __int16 *)(v50 + 2);
            if ( !*v50 )
            {
              if ( (unsigned int)v57 < 3 )
                goto LABEL_37;
              v59 = *v58;
              v60 = ((v59 >> 4) & 8 | (v59 >> 5) & 2) + ((v59 >> 7) & 2);
              if ( (v59 & 0x20) != 0 )
                v61 = v60 + 7;
              else
                v61 = v60 + 1;
              if ( (~v59 & 0x210) == 0 )
              {
                if ( (v59 & 0x400) != 0 )
                  v61 += 2;
                else
                  ++v61;
              }
              v62 = (unsigned __int8)v50[4];
              if ( (unsigned int)v62 < (unsigned __int8)(v61 + ((v59 & 0x800) != 0)) || v62 + 2 > v57 )
                goto LABEL_37;
              if ( (v59 & 0xF) == (unsigned __int8)v30 )
              {
                if ( (v59 & 0x10) != 0 )
                {
                  v63 = cfg80211_defragment_element(v50, v29, v31, v5[99], (char *)v8 + v5[98] - v5[99], 254);
                  if ( (v63 & 0x8000000000000000LL) == 0 )
                  {
                    v64 = v5[99];
                    v5[94] = v63;
                    v5[93] = v64;
                    v5[99] = v64 + v63;
                  }
                }
                goto LABEL_37;
              }
            }
            v50 = (char *)v58 + v57;
          }
        }
        LOBYTE(v35) = 7;
      }
      if ( (unsigned __int64)(unsigned __int8)v35 + 2 <= v28 )
      {
        v37 = *((unsigned __int8 *)v29 + 2);
        if ( v37 >= (unsigned __int8)v35 )
          goto LABEL_51;
      }
      goto LABEL_37;
    }
  }
LABEL_41:
  v43 = cfg80211_defragment_element(v5[97], *v5, v5[1], v5[99], (char *)v8 + v5[98] - v5[99], 242);
  if ( (v43 & 0x8000000000000000LL) == 0 )
  {
    v44 = v5[99];
    v5[91] = v43;
    v5[57] = v44;
    v5[99] = v44 + v43;
  }
  v45 = (_BYTE *)v5[9];
  if ( v45 && !*((_BYTE *)v5 + 760) )
  {
    *((_BYTE *)v5 + 386) = v45[1];
    *((_BYTE *)v5 + 385) = *v45;
  }
  v46 = v5[47];
  if ( v46 )
  {
    v47 = *((unsigned __int8 *)v5 + 712);
    if ( v47 >= 2 )
    {
      *((_BYTE *)v5 + 386) = *(_BYTE *)(v46 + 1);
      if ( v47 != 2 )
        *((_BYTE *)v5 + 385) = *(_BYTE *)(v46 + 2);
    }
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return v5;
}
