__int64 __fastcall ieee80211_link_use_channel(__int64 a1, __int64 *a2, unsigned int a3, char a4)
{
  unsigned __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x20
  __int64 result; // x0
  __int64 v11; // x3
  __int64 v12; // x10
  _QWORD *v13; // x9
  __int64 v14; // x12
  __int64 v15; // x13
  __int64 v16; // x10
  _QWORD *v17; // x11
  __int64 v18; // x12
  __int64 v19; // x13
  _QWORD *v20; // x9
  _QWORD *v21; // x10
  _QWORD *v22; // x11
  __int64 v23; // x12
  __int64 v24; // x14
  __int64 v25; // x15
  __int64 v26; // x12
  __int64 v27; // x14
  __int64 v28; // x15
  __int64 v29; // x8
  __int64 v30; // x12
  __int64 v31; // x10
  __int64 v32; // x11
  __int64 v33; // x8
  __int64 v34; // x9
  __int64 v35; // x12
  __int64 v36; // x14
  __int64 *v37; // x0
  __int64 *v38; // x10
  __int64 v39; // x9
  __int64 v40; // x8
  __int64 v41; // x11
  __int64 v42; // x9
  __int64 v43; // x10
  __int64 v44; // x8
  __int64 v45; // x9
  __int64 *v46; // x24
  __int64 *v47; // x25
  __int64 v48; // x8
  __int64 *v49; // x0
  __int64 v50; // x8
  __int64 v51; // x10
  __int64 v52; // x11
  __int64 *v53; // x8
  __int64 v54; // x9
  __int64 v55; // x10
  __int64 v56; // x8
  __int64 v57; // x11
  __int64 *v58; // x0
  __int64 *v59; // x2
  __int64 v60; // x24
  int v61; // w8
  __int64 v62; // x22
  _QWORD *v63; // x25
  int v64; // w26
  _QWORD *v65; // x8
  __int64 v66; // x9
  __int64 v67; // x0
  int v68; // w23
  __int64 v69; // x10
  __int64 v70; // x13
  __int64 v71; // x14
  __int64 v72; // x11
  __int64 v73; // x10
  __int64 v74; // x13
  __int64 v75; // x14
  _QWORD *v76; // x12
  __int64 v77; // x13
  __int64 v78; // x15
  __int64 v79; // x16
  __int64 v80; // x13
  __int64 v81; // x15
  __int64 v82; // x16
  _QWORD *v83; // x9
  __int64 *v84; // x8
  __int64 v85; // x10
  _QWORD *v86; // x8
  int v87; // w10
  _QWORD *v88; // x9
  _QWORD *v89; // x9
  _QWORD *v90; // x11
  int v91; // w10
  _QWORD *v92; // x11
  _QWORD *v93; // x8
  unsigned __int64 *v94; // x8
  unsigned int v95; // w21
  unsigned __int64 v96; // x9
  unsigned int v97; // w9
  _QWORD *v98; // [xsp+0h] [xbp-E0h]
  __int64 v100; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v101; // [xsp+18h] [xbp-C8h]
  __int64 v102; // [xsp+20h] [xbp-C0h]
  __int64 v103; // [xsp+28h] [xbp-B8h]
  __int64 v104; // [xsp+30h] [xbp-B0h] BYREF
  __int64 v105; // [xsp+38h] [xbp-A8h]
  __int64 v106; // [xsp+40h] [xbp-A0h]
  __int64 v107; // [xsp+48h] [xbp-98h]
  __int64 v108; // [xsp+50h] [xbp-90h]
  __int64 v109; // [xsp+58h] [xbp-88h]
  __int64 v110; // [xsp+60h] [xbp-80h]
  __int64 v111; // [xsp+68h] [xbp-78h]
  __int64 v112; // [xsp+70h] [xbp-70h]
  __int64 v113; // [xsp+78h] [xbp-68h]
  __int64 v114; // [xsp+80h] [xbp-60h]
  __int64 v115; // [xsp+88h] [xbp-58h]
  __int64 v116; // [xsp+90h] [xbp-50h]
  __int64 v117; // [xsp+98h] [xbp-48h]
  __int64 v118; // [xsp+A0h] [xbp-40h]
  __int64 v119; // [xsp+A8h] [xbp-38h]
  __int64 v120; // [xsp+B0h] [xbp-30h]
  __int64 v121; // [xsp+B8h] [xbp-28h]
  __int64 v122; // [xsp+C0h] [xbp-20h]
  __int64 v123; // [xsp+C8h] [xbp-18h]
  __int64 v124; // [xsp+D0h] [xbp-10h]

  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)a1;
  v8 = *(unsigned int *)(a1 + 8);
  v9 = *(_QWORD *)(*(_QWORD *)a1 + 1616LL);
  if ( *(_WORD *)(*(_QWORD *)a1 + 5800LL) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(v7 + 5802) >> v8) & 1) != 0 )
      goto LABEL_3;
LABEL_7:
    v12 = a2[3];
    v13 = *(_QWORD **)(a1 + 944);
    v14 = *a2;
    v15 = a2[1];
    v13[19] = a2[2];
    v13[20] = v12;
    v13[17] = v14;
    v13[18] = v15;
    v17 = (_QWORD *)a2[6];
    v16 = a2[7];
    v18 = a2[4];
    v19 = a2[5];
    v13[23] = v17;
    v13[24] = v16;
    v13[21] = v18;
    v13[22] = v19;
    if ( *(_DWORD *)(v7 + 4720) == 3 )
    {
      v20 = *(_QWORD **)(v7 + 2264);
      v21 = (_QWORD *)(v7 + 2264);
      if ( v20 != (_QWORD *)(v7 + 2264) )
      {
        if ( (unsigned int)v8 > 0xE )
        {
LABEL_87:
          __break(0x5512u);
LABEL_88:
          __break(0x800u);
          while ( 1 )
          {
            v21 = (_QWORD *)*v21;
            if ( v21 == v17 )
              goto LABEL_92;
LABEL_89:
            v76 = (_QWORD *)v21[v8 + 427];
            if ( !v76 )
              goto LABEL_88;
            v77 = a2[3];
            v78 = *a2;
            v79 = a2[1];
            v76[19] = a2[2];
            v76[20] = v77;
            v76[17] = v78;
            v76[18] = v79;
            v80 = a2[7];
            v81 = a2[4];
            v82 = a2[5];
            v76[23] = a2[6];
            v76[24] = v80;
            v76[21] = v81;
            v76[22] = v82;
          }
        }
        do
        {
          v22 = (_QWORD *)v20[v8 + 427];
          if ( v22 )
          {
            v23 = a2[3];
            v24 = *a2;
            v25 = a2[1];
            v22[19] = a2[2];
            v22[20] = v23;
            v22[17] = v24;
            v22[18] = v25;
            v26 = a2[7];
            v27 = a2[4];
            v28 = a2[5];
            v22[23] = a2[6];
            v22[24] = v26;
            v22[21] = v27;
            v22[22] = v28;
          }
          else
          {
            __break(0x800u);
          }
          v20 = (_QWORD *)*v20;
        }
        while ( v20 != v21 );
      }
    }
    result = 0;
    goto LABEL_118;
  }
  if ( (_DWORD)v8 )
    goto LABEL_7;
LABEL_3:
  result = cfg80211_chandef_dfs_required(*(_QWORD *)(v9 + 72), a2, *(unsigned int *)(v7 + 24));
  if ( (result & 0x80000000) != 0 )
    goto LABEL_117;
  v11 = (_DWORD)result ? 1LL << *((_DWORD *)a2 + 2) : 0LL;
  *(_BYTE *)(a1 + 456) = (_DWORD)result != 0;
  result = ieee80211_check_combinations(v7, a2, a3, v11, 0xFFFFFFFFLL);
  if ( (result & 0x80000000) != 0 )
    goto LABEL_117;
  _ieee80211_link_release_channel((__int64 *)a1, 0);
  if ( a3 == 1 )
    goto LABEL_57;
  v29 = *(_QWORD *)(a1 + 368);
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  if ( v29 )
  {
    __break(0x800u);
    goto LABEL_57;
  }
  v7 = *(_QWORD *)(v9 + 4984);
  if ( v7 == v9 + 4984 )
    goto LABEL_57;
  v98 = a2 + 4;
  while ( 1 )
  {
    if ( !*(_DWORD *)(v7 + 64) && *(_DWORD *)(v7 + 80) != 1 )
    {
      v30 = *(_QWORD *)(v7 + 224);
      v31 = *(_QWORD *)(v7 + 168);
      v32 = *(_QWORD *)(v7 + 176);
      v33 = *(_QWORD *)(v7 + 152);
      v34 = *(_QWORD *)(v7 + 160);
      v112 = *(_QWORD *)(v7 + 216);
      v113 = v30;
      v36 = *(_QWORD *)(v7 + 232);
      v35 = *(_QWORD *)(v7 + 240);
      v110 = v31;
      v111 = v32;
      v102 = v31;
      v103 = v32;
      v114 = v36;
      v115 = v35;
      v108 = v33;
      v109 = v34;
      v100 = v33;
      v101 = v34;
      v104 = v112;
      v105 = v113;
      v106 = v36;
      v107 = v35;
      if ( !v112
        || !*v98
        || v112 == *v98
        && (_DWORD)v105 == *((_DWORD *)a2 + 10)
        && HIDWORD(v105) == *((_DWORD *)a2 + 11)
        && WORD2(v107) == *((unsigned __int16 *)a2 + 30)
        && (_DWORD)v106 == *((_DWORD *)a2 + 12)
        && HIWORD(v107) == *((unsigned __int16 *)a2 + 31) )
      {
        v37 = (__int64 *)cfg80211_chandef_compatible(&v100, a2);
        if ( v37 )
          break;
      }
    }
LABEL_22:
    v7 = *(_QWORD *)v7;
    if ( v7 == v9 + 4984 )
      goto LABEL_57;
  }
  v38 = a2 + 4;
  v39 = v37[1];
  if ( v104 )
    v38 = &v104;
  v116 = *v37;
  v117 = v39;
  v40 = v38[1];
  v41 = v38[2];
  v42 = *v38;
  v43 = v38[3];
  v121 = v40;
  v122 = v41;
  v120 = v42;
  v44 = v37[2];
  v45 = v37[3];
  v123 = v43;
  v118 = v44;
  v119 = v45;
  v106 = v41;
  v107 = v43;
  v46 = (__int64 *)(v7 + 48);
  v47 = *(__int64 **)(v7 + 48);
  v102 = v44;
  v103 = v45;
  v100 = v116;
  v101 = v117;
  v104 = v120;
  v105 = v121;
  if ( v47 != (__int64 *)(v7 + 48) )
  {
    do
    {
      v48 = v47[47];
      if ( v48 )
      {
        if ( v104
          && (v48 != v104
           || *((_DWORD *)v47 + 96) != (_DWORD)v105
           || *((_DWORD *)v47 + 97) != HIDWORD(v105)
           || *((unsigned __int16 *)v47 + 202) != WORD2(v107)
           || *((_DWORD *)v47 + 98) != (_DWORD)v106
           || *((unsigned __int16 *)v47 + 203) != HIWORD(v107)) )
        {
          goto LABEL_22;
        }
      }
      v49 = (__int64 *)cfg80211_chandef_compatible(v47 + 43, &v100);
      if ( !v49 )
        goto LABEL_22;
      v50 = v49[3];
      v51 = *v49;
      v52 = v49[1];
      v102 = v49[2];
      v103 = v50;
      v100 = v51;
      v101 = v52;
      if ( v47[47] )
        v53 = v47 + 47;
      else
        v53 = &v104;
      v55 = v53[2];
      v54 = v53[3];
      v57 = *v53;
      v56 = v53[1];
      v106 = v55;
      v107 = v54;
      v104 = v57;
      v105 = v56;
      v47 = (__int64 *)*v47;
    }
    while ( v47 != v46 );
  }
  *(_QWORD *)(a1 + 368) = v7;
  v58 = (__int64 *)(a1 + 32);
  v59 = *(__int64 **)(v7 + 48);
  if ( (__int64 *)v59[1] != v46 || v58 == v46 || v59 == v58 )
  {
    _list_add_valid_or_report(v58, v46);
  }
  else
  {
    v59[1] = (__int64)v58;
    *(_QWORD *)(a1 + 32) = v59;
    *(_QWORD *)(a1 + 40) = v46;
    *v46 = (__int64)v58;
  }
  ieee80211_change_chanctx(v9, v7, v7, &v100, 0);
  if ( v7 )
  {
    a3 = 1;
    goto LABEL_82;
  }
LABEL_57:
  v60 = *(_QWORD *)(v9 + 72);
  v61 = *(_DWORD *)(v60 + 1496);
  if ( !v61 )
  {
    LODWORD(v62) = -1;
    goto LABEL_72;
  }
  if ( v61 < 1 )
  {
LABEL_70:
    result = 4294967280LL;
    goto LABEL_117;
  }
  v62 = 0;
  v63 = (_QWORD *)(v9 + 4984);
  while ( 1 )
  {
    if ( (cfg80211_radio_chandef_valid(*(_QWORD *)(v60 + 1504) + 32 * v62, a2) & 1) != 0 )
    {
      v65 = (_QWORD *)*v63;
      if ( (_QWORD *)*v63 == v63 )
      {
        v64 = 0;
      }
      else
      {
        v64 = 0;
        do
        {
          v66 = *((unsigned int *)v65 + 62);
          v65 = (_QWORD *)*v65;
          if ( v62 == v66 )
            ++v64;
        }
        while ( v65 != v63 );
      }
      if ( v64 < (int)ieee80211_max_num_channels(v9, (unsigned int)v62) )
        break;
    }
    if ( ++v62 >= *(int *)(v60 + 1496) )
      goto LABEL_70;
  }
LABEL_72:
  v67 = ieee80211_alloc_chanctx(v9, a2, a3, (unsigned int)v62);
  if ( !v67 )
  {
    result = 4294967284LL;
    goto LABEL_117;
  }
  v7 = v67;
  v68 = ieee80211_add_chanctx(v9, v67);
  if ( (a4 & 1) != 0 || !v68 )
  {
    if ( v68 && (*(_BYTE *)(v9 + 1470) & 1) == 0 )
      __break(0x800u);
    list_add_rcu(v7, v9 + 4984);
  }
  else
  {
    kfree(v7);
    v7 = v68;
  }
  a3 = 0;
LABEL_82:
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = (unsigned int)v7;
    goto LABEL_117;
  }
  v69 = a2[7];
  v20 = *(_QWORD **)(a1 + 944);
  v71 = a2[4];
  v70 = a2[5];
  v72 = *(_QWORD *)a1;
  v8 = *(unsigned int *)(a1 + 8);
  v20[23] = a2[6];
  v20[24] = v69;
  v20[21] = v71;
  v20[22] = v70;
  v73 = a2[3];
  v74 = *a2;
  v75 = a2[1];
  v20[19] = a2[2];
  v20[20] = v73;
  v20[17] = v74;
  v20[18] = v75;
  LOBYTE(v20) = a4;
  if ( *(_DWORD *)(v72 + 4720) == 3 )
  {
    v21 = *(_QWORD **)(v72 + 2264);
    v17 = (_QWORD *)(v72 + 2264);
    if ( v21 != v17 )
    {
      if ( (unsigned int)v8 <= 0xE )
        goto LABEL_89;
      goto LABEL_87;
    }
  }
LABEL_92:
  result = ieee80211_assign_link_chanctx((_QWORD *)a1, v7, (unsigned __int8)v20 & 1);
  if ( a3 )
  {
    if ( *(_QWORD *)(a1 + 368) != v7 )
      __break(0x800u);
    v83 = *(_QWORD **)(a1 + 40);
    *(_QWORD *)(a1 + 368) = 0;
    v84 = (__int64 *)(a1 + 32);
    if ( *v83 == a1 + 32 && (v85 = *v84, *(__int64 **)(*v84 + 8) == v84) )
    {
      *(_QWORD *)(v85 + 8) = v83;
      *v83 = v85;
    }
    else
    {
      _list_del_entry_valid_or_report(a1 + 32);
      result = v97;
    }
    *(_QWORD *)(a1 + 32) = 0xDEAD000000000100LL;
    *(_QWORD *)(a1 + 40) = 0xDEAD000000000122LL;
  }
  if ( (_DWORD)result )
  {
    v86 = (_QWORD *)(v7 + 32);
    v87 = 2;
    v88 = (_QWORD *)(v7 + 32);
    do
    {
      v88 = (_QWORD *)*v88;
      --v87;
    }
    while ( v88 != v86 );
    v89 = (_QWORD *)(v7 + 48);
    v90 = (_QWORD *)(v7 + 48);
    do
    {
      v90 = (_QWORD *)*v90;
      --v87;
    }
    while ( v90 != v89 );
    if ( !v87 )
    {
      v91 = 2;
      v92 = (_QWORD *)(v7 + 32);
      do
      {
        v92 = (_QWORD *)*v92;
        --v91;
      }
      while ( v92 != v86 );
      v93 = (_QWORD *)(v7 + 48);
      do
      {
        v93 = (_QWORD *)*v93;
        --v91;
      }
      while ( v93 != v89 );
      if ( v91 )
        __break(0x800u);
      v94 = *(unsigned __int64 **)(v7 + 8);
      v95 = result;
      if ( *v94 == v7 && (v96 = *(_QWORD *)v7, *(_QWORD *)(*(_QWORD *)v7 + 8LL) == v7) )
      {
        *(_QWORD *)(v96 + 8) = v94;
        *v94 = v96;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
      }
      *(_QWORD *)(v7 + 8) = 0xDEAD000000000122LL;
      ieee80211_del_chanctx(v9, v7, 0);
      if ( v7 )
        kvfree_call_rcu(v7 + 16, v7);
      result = v95;
    }
LABEL_117:
    *(_BYTE *)(a1 + 456) = 0;
  }
  else
  {
    ieee80211_recalc_smps_chanctx(v9, (_BYTE *)v7);
    ieee80211_recalc_radar_chanctx(v9, v7);
    result = 0;
  }
LABEL_118:
  _ReadStatusReg(SP_EL0);
  return result;
}
