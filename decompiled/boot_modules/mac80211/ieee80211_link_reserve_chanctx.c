__int64 __fastcall ieee80211_link_reserve_chanctx(_QWORD *a1, _QWORD *a2, unsigned int a3, char a4)
{
  __int64 v5; // x8
  _QWORD *v6; // x23
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x24
  __int64 *v9; // x19
  __int64 *v10; // x22
  __int64 v11; // x8
  __int64 *v12; // x0
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 *v16; // x8
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 v20; // x11
  __int64 v21; // x8
  __int64 *v22; // x0
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x11
  _DWORD *v26; // x11
  __int64 *v27; // x12
  __int64 *v28; // x9
  unsigned __int16 *v29; // x10
  __int64 *v30; // x1
  __int64 *v31; // x19
  unsigned __int16 *v32; // x8
  _QWORD *v33; // x27
  __int64 v34; // x13
  __int64 v35; // x14
  __int64 *v36; // x26
  __int64 *v37; // x0
  __int64 v38; // x8
  __int64 v39; // x11
  __int64 v40; // x12
  bool v41; // zf
  __int64 *v42; // x8
  __int64 v43; // x9
  __int64 v44; // x10
  __int64 v45; // x8
  __int64 v46; // x13
  __int64 *v47; // t2
  __int64 *v48; // x19
  __int64 v49; // x8
  __int64 *v50; // x0
  __int64 v51; // x8
  __int64 v52; // x10
  __int64 v53; // x11
  __int64 *v54; // x8
  __int64 v55; // x9
  __int64 v56; // x10
  __int64 v57; // x8
  __int64 v58; // x11
  __int64 v59; // x8
  __int64 *v60; // x0
  __int64 v61; // x8
  __int64 v62; // x10
  __int64 v63; // x11
  unsigned __int64 *v64; // x8
  unsigned __int64 *v65; // x25
  int v66; // w19
  __int64 v67; // x19
  int v68; // w8
  __int64 v69; // x24
  int v70; // w21
  unsigned __int64 v71; // x8
  __int64 v72; // x9
  __int64 v73; // x19
  unsigned __int64 v74; // x22
  unsigned __int64 i; // x21
  __int64 v76; // x8
  __int64 v77; // x0
  int v78; // w0
  int v79; // w22
  unsigned __int64 v81; // x0
  unsigned __int64 v82; // x2
  _QWORD *v83; // x13
  _QWORD *v84; // x1
  _QWORD *v85; // x2
  _QWORD *v86; // x0
  char v87; // w9
  __int64 v88; // x8
  __int64 v89; // x11
  __int64 v90; // x12
  __int64 v91; // x8
  __int64 v92; // x10
  __int64 v93; // x11
  __int64 v94; // x12
  unsigned __int64 v95; // [xsp+0h] [xbp-D0h]
  unsigned __int16 *v99; // [xsp+48h] [xbp-88h]
  __int64 *v100; // [xsp+50h] [xbp-80h]
  unsigned __int16 *v101; // [xsp+58h] [xbp-78h]
  _DWORD *v102; // [xsp+60h] [xbp-70h]
  __int64 *v103; // [xsp+68h] [xbp-68h]
  unsigned __int64 v104; // [xsp+70h] [xbp-60h]
  __int64 *v105; // [xsp+78h] [xbp-58h]
  __int64 v106; // [xsp+80h] [xbp-50h] BYREF
  __int64 v107; // [xsp+88h] [xbp-48h]
  __int64 v108; // [xsp+90h] [xbp-40h]
  __int64 v109; // [xsp+98h] [xbp-38h]
  __int64 v110; // [xsp+A0h] [xbp-30h] BYREF
  __int64 v111; // [xsp+A8h] [xbp-28h] BYREF
  __int64 v112; // [xsp+B0h] [xbp-20h] BYREF
  _QWORD v113[3]; // [xsp+B8h] [xbp-18h] BYREF

  v113[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1[118] + 832LL);
  v6 = *(_QWORD **)(*a1 + 1616LL);
  if ( v5 )
    v7 = v5 - 152;
  else
    v7 = 0;
  if ( v7 && !*(_QWORD *)(v6[58] + 632LL) )
  {
    LODWORD(v8) = -95;
    goto LABEL_123;
  }
  v95 = v5 - 152;
  v104 = v7;
  if ( a3 == 1 )
    goto LABEL_82;
  v8 = v6[623];
  if ( (_QWORD *)v8 == v6 + 623 )
    goto LABEL_82;
  v105 = a2 + 4;
  v102 = (_DWORD *)a2 + 11;
  v103 = a2 + 5;
  v100 = a2 + 6;
  v101 = (unsigned __int16 *)a2 + 30;
  v99 = (unsigned __int16 *)a2 + 31;
  while ( 1 )
  {
    if ( *(_DWORD *)(v8 + 64) == 1 || *(_DWORD *)(v8 + 80) == 1 )
      goto LABEL_11;
    v112 = 0;
    v113[0] = 0;
    v110 = 0;
    v111 = 0;
    v108 = 0;
    v109 = 0;
    v106 = 0;
    v107 = 0;
    if ( !a2 )
    {
      __break(0x800u);
      goto LABEL_11;
    }
    v10 = (__int64 *)(v8 + 48);
    v9 = *(__int64 **)(v8 + 48);
    if ( v9 == (__int64 *)(v8 + 48) )
      goto LABEL_40;
    v11 = v9[47];
    if ( !v11
      || !*v105
      || v11 == *v105
      && *((_DWORD *)v9 + 96) == *(_DWORD *)v103
      && *((_DWORD *)v9 + 97) == *v102
      && *((unsigned __int16 *)v9 + 202) == *v101
      && *((_DWORD *)v9 + 98) == *(_DWORD *)v100
      && *((unsigned __int16 *)v9 + 203) == *v99 )
    {
      v12 = (__int64 *)cfg80211_chandef_compatible(v9 + 43, a2);
      if ( v12 )
        break;
    }
LABEL_11:
    v8 = *(_QWORD *)v8;
    if ( (_QWORD *)v8 == v6 + 623 )
      goto LABEL_82;
  }
  v13 = v12[3];
  v14 = *v12;
  v15 = v12[1];
  v108 = v12[2];
  v109 = v13;
  v106 = v14;
  v107 = v15;
  v16 = v105;
  if ( v9[47] )
    v16 = v9 + 47;
  while ( 1 )
  {
    v18 = v16[2];
    v17 = v16[3];
    v20 = *v16;
    v19 = v16[1];
    v112 = v18;
    v113[0] = v17;
    v110 = v20;
    v111 = v19;
    v9 = (__int64 *)*v9;
    if ( v9 == v10 )
      break;
    v21 = v9[47];
    if ( v21
      && v110
      && (v21 != v110
       || *((_DWORD *)v9 + 96) != (_DWORD)v111
       || *((_DWORD *)v9 + 97) != HIDWORD(v111)
       || *((unsigned __int16 *)v9 + 202) != WORD2(v113[0])
       || *((_DWORD *)v9 + 98) != (_DWORD)v112
       || *((unsigned __int16 *)v9 + 203) != HIWORD(v113[0])) )
    {
      goto LABEL_11;
    }
    v22 = (__int64 *)cfg80211_chandef_compatible(v9 + 43, &v106);
    if ( !v22 )
      goto LABEL_11;
    v23 = v22[3];
    v24 = *v22;
    v25 = v22[1];
    v108 = v22[2];
    v109 = v23;
    v106 = v24;
    v107 = v25;
    if ( v9[47] )
      v16 = v9 + 47;
    else
      v16 = &v110;
  }
LABEL_40:
  v26 = v102;
  v27 = v103;
  v28 = v100;
  v29 = v101;
  v30 = a2;
  v31 = v105;
  v32 = v99;
  v33 = (_QWORD *)(v8 + 32);
  while ( 1 )
  {
    v33 = (_QWORD *)*v33;
    if ( v33 == (_QWORD *)(v8 + 32) )
      break;
    if ( !v33[44] )
    {
      v34 = v33[116];
      v36 = (__int64 *)(v34 + 168);
      v35 = *(_QWORD *)(v34 + 168);
      if ( v35
        && *v31
        && (v35 != *v31
         || *(_DWORD *)(v34 + 176) != *(_DWORD *)v27
         || *(_DWORD *)(v34 + 180) != *v26
         || *(unsigned __int16 *)(v34 + 196) != *v29
         || *(_DWORD *)(v34 + 184) != *(_DWORD *)v28
         || *(unsigned __int16 *)(v34 + 198) != *v32) )
      {
        goto LABEL_11;
      }
      v37 = (__int64 *)cfg80211_chandef_compatible(v34 + 136, v30);
      if ( !v37 )
        goto LABEL_11;
      v38 = v37[3];
      v30 = &v106;
      v39 = *v37;
      v40 = v37[1];
      v41 = *v36 == 0;
      v108 = v37[2];
      v109 = v38;
      if ( v41 )
        v42 = v31;
      else
        v42 = v36;
      v106 = v39;
      v107 = v40;
      v31 = &v110;
      v44 = v42[2];
      v43 = v42[3];
      v47 = v42;
      v45 = *v42;
      v46 = v47[1];
      v26 = (_DWORD *)&v111 + 1;
      v27 = &v111;
      v112 = v44;
      v113[0] = v43;
      v28 = &v112;
      v29 = (unsigned __int16 *)v113 + 2;
      v110 = v45;
      v111 = v46;
      v32 = (unsigned __int16 *)v113 + 3;
    }
  }
  v48 = (__int64 *)*v10;
  if ( (__int64 *)*v10 == v10 )
    goto LABEL_11;
  v49 = v48[47];
  if ( v49 )
  {
    if ( *v105
      && (v49 != *v105
       || *((_DWORD *)v48 + 96) != *(_DWORD *)v103
       || *((_DWORD *)v48 + 97) != *v102
       || *((unsigned __int16 *)v48 + 202) != *v101
       || *((_DWORD *)v48 + 98) != *(_DWORD *)v100
       || *((unsigned __int16 *)v48 + 203) != *v99) )
    {
      goto LABEL_11;
    }
  }
  v50 = (__int64 *)cfg80211_chandef_compatible(v48 + 43, a2);
  if ( !v50 )
    goto LABEL_11;
  v51 = v50[3];
  v52 = *v50;
  v53 = v50[1];
  v108 = v50[2];
  v109 = v51;
  v106 = v52;
  v107 = v53;
  v54 = v105;
  if ( v48[47] )
    v54 = v48 + 47;
  while ( 1 )
  {
    v56 = v54[2];
    v55 = v54[3];
    v58 = *v54;
    v57 = v54[1];
    v112 = v56;
    v113[0] = v55;
    v110 = v58;
    v111 = v57;
    v48 = (__int64 *)*v48;
    if ( v48 == v10 )
      break;
    v59 = v48[47];
    if ( v59
      && v110
      && (v59 != v110
       || *((_DWORD *)v48 + 96) != (_DWORD)v111
       || *((_DWORD *)v48 + 97) != HIDWORD(v111)
       || *((unsigned __int16 *)v48 + 202) != WORD2(v113[0])
       || *((_DWORD *)v48 + 98) != (_DWORD)v112
       || *((unsigned __int16 *)v48 + 203) != HIWORD(v113[0])) )
    {
      goto LABEL_11;
    }
    v60 = (__int64 *)cfg80211_chandef_compatible(v48 + 43, &v106);
    if ( !v60 )
      goto LABEL_11;
    v61 = v60[3];
    v62 = *v60;
    v63 = v60[1];
    v108 = v60[2];
    v109 = v61;
    v106 = v62;
    v107 = v63;
    if ( v48[47] )
      v54 = v48 + 47;
    else
      v54 = &v110;
  }
  if ( v8 )
    goto LABEL_135;
LABEL_82:
  v64 = (unsigned __int64 *)v6[623];
  v65 = v6 + 623;
  if ( v64 == v6 + 623 )
  {
    v66 = 0;
  }
  else
  {
    v66 = 0;
    do
    {
      v64 = (unsigned __int64 *)*v64;
      ++v66;
    }
    while ( v64 != v65 );
  }
  if ( v66 >= (int)ieee80211_max_num_channels(v6, 0xFFFFFFFFLL) )
    goto LABEL_101;
  v67 = v6[9];
  v68 = *(_DWORD *)(v67 + 1496);
  if ( !v68 )
  {
    LODWORD(v69) = -1;
    goto LABEL_116;
  }
  if ( v68 < 1 )
  {
LABEL_101:
    v73 = v6[9];
    v74 = v104;
    if ( v104 && *(_DWORD *)(v104 + 64) != 1 && *(_QWORD *)(v104 + 48) == v104 + 48 )
    {
      v74 = v95;
    }
    else
    {
      for ( i = *v65; (unsigned __int64 *)i != v65; i = *(_QWORD *)i )
      {
        if ( !*(_DWORD *)(i + 64) && *(_QWORD *)(i + 48) == i + 48 )
        {
          v76 = *(unsigned int *)(i + 248);
          if ( (v76 & 0x80000000) != 0
            || (cfg80211_radio_chandef_valid(*(_QWORD *)(v73 + 1504) + 32 * v76, a2) & 1) != 0 )
          {
            v74 = i;
            break;
          }
        }
      }
      if ( !v74 || *(_DWORD *)(v74 + 64) == 1 )
        goto LABEL_122;
    }
    if ( *(_QWORD *)(v74 + 48) == v74 + 48 )
    {
      v81 = ieee80211_alloc_chanctx(v6, a2, a3, 0xFFFFFFFFLL);
      if ( v81 )
      {
        *(_QWORD *)(v81 + 72) = v74;
        v8 = v81;
        *(_DWORD *)(v81 + 64) = 2;
        *(_QWORD *)(v74 + 72) = v81;
        *(_DWORD *)(v74 + 64) = 1;
        v82 = *v65;
        if ( *(unsigned __int64 **)(*v65 + 8) == v65 && (unsigned __int64 *)v81 != v65 && v82 != v81 )
        {
          *(_QWORD *)v81 = v82;
          *(_QWORD *)(v81 + 8) = v65;
          atomic_store(v81, v65);
          goto LABEL_134;
        }
LABEL_141:
        _list_add_valid_or_report(v8, v6 + 623);
        if ( v8 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_123;
        goto LABEL_135;
      }
LABEL_129:
      LODWORD(v8) = -12;
      goto LABEL_123;
    }
LABEL_122:
    LODWORD(v8) = -16;
    goto LABEL_123;
  }
  v69 = 0;
  while ( 1 )
  {
    if ( (cfg80211_radio_chandef_valid(*(_QWORD *)(v67 + 1504) + 32 * v69, a2) & 1) != 0 )
    {
      v71 = *v65;
      if ( (unsigned __int64 *)*v65 == v65 )
      {
        v70 = 0;
      }
      else
      {
        v70 = 0;
        do
        {
          v72 = *(unsigned int *)(v71 + 248);
          v71 = *(_QWORD *)v71;
          if ( v69 == v72 )
            ++v70;
        }
        while ( (unsigned __int64 *)v71 != v65 );
      }
      if ( v70 < (int)ieee80211_max_num_channels(v6, (unsigned int)v69) )
        break;
    }
    if ( ++v69 >= *(int *)(v67 + 1496) )
      goto LABEL_101;
  }
LABEL_116:
  v77 = ieee80211_alloc_chanctx(v6, a2, a3, (unsigned int)v69);
  if ( !v77 )
    goto LABEL_129;
  v8 = v77;
  v78 = ieee80211_add_chanctx(v6, v77);
  if ( !v78 )
  {
    v82 = *v65;
    if ( *(unsigned __int64 **)(*v65 + 8) == v65 && (unsigned __int64 *)v8 != v65 && v82 != v8 )
    {
      *(_QWORD *)v8 = v82;
      *(_QWORD *)(v8 + 8) = v65;
      atomic_store(v8, v65);
LABEL_134:
      *(_QWORD *)(v82 + 8) = v8;
      if ( v8 < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_135;
      goto LABEL_123;
    }
    goto LABEL_141;
  }
  v79 = v78;
  kfree(v8);
  v8 = v79;
  if ( (unsigned __int64)v79 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_123;
LABEL_135:
  v83 = a1;
  v84 = (_QWORD *)(v8 + 48);
  v85 = *(_QWORD **)(v8 + 48);
  v86 = a1 + 4;
  v87 = a4 & 1;
  if ( v85[1] != v8 + 48 || v86 == v84 || v85 == v86 )
  {
    _list_add_valid_or_report(v86, v84);
  }
  else
  {
    v85[1] = v86;
    a1[4] = v85;
    a1[5] = v84;
    *v84 = v86;
  }
  v83[46] = v8;
  LODWORD(v8) = 0;
  v88 = a2[3];
  v89 = *a2;
  v90 = a2[1];
  v83[49] = a2[2];
  v83[50] = v88;
  v83[47] = v89;
  v83[48] = v90;
  v92 = a2[6];
  v91 = a2[7];
  v93 = a2[4];
  v94 = a2[5];
  *((_BYTE *)v83 + 440) = v87;
  *((_BYTE *)v83 + 441) = 0;
  v83[53] = v92;
  v83[54] = v91;
  v83[51] = v93;
  v83[52] = v94;
LABEL_123:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v8;
}
