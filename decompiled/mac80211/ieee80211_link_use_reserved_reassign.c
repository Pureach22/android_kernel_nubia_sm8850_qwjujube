__int64 __fastcall ieee80211_link_use_reserved_reassign(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x23
  char v3; // w9
  __int64 v4; // x8
  __int64 v5; // x28
  bool v6; // zf
  _QWORD *v7; // x8
  _QWORD *v8; // x10
  _BYTE *v9; // x21
  __int64 v10; // x19
  __int64 *v11; // x26
  _QWORD *v12; // x22
  __int64 *v13; // x24
  _QWORD *v14; // x25
  __int64 v15; // x8
  __int64 v16; // x9
  _QWORD *v17; // x20
  __int64 v18; // x10
  __int64 v19; // x9
  _QWORD *v20; // x12
  __int64 v21; // x8
  __int64 v22; // x11
  _QWORD *v23; // x9
  __int64 v24; // x10
  __int64 v25; // x11
  __int64 v26; // x8
  __int64 v27; // x9
  _QWORD *v28; // t2
  __int64 v29; // x12
  __int64 v30; // x20
  __int64 v31; // x13
  __int64 v32; // x14
  _QWORD *v33; // x9
  int v34; // w17
  __int64 v35; // x10
  int v36; // w16
  __int64 v37; // x8
  __int64 v38; // x11
  __int64 v39; // x13
  __int64 v40; // x14
  _QWORD *v41; // x9
  _QWORD *v42; // x10
  _QWORD *v43; // x11
  __int64 v44; // x12
  __int64 v45; // x14
  __int64 v46; // x15
  __int64 v47; // x12
  __int64 v48; // x14
  __int64 v49; // x15
  __int64 v50; // x0
  int v51; // w28
  __int64 v52; // x9
  _QWORD *v53; // x8
  __int64 v54; // x0
  __int64 v55; // x9
  unsigned int v56; // w24
  int v57; // w9
  _QWORD *v58; // x8
  _QWORD *v59; // x8
  _QWORD *v60; // x10
  int v61; // w9
  _QWORD *v62; // x10
  _QWORD *v63; // x10
  _QWORD *v64; // x8
  __int64 v65; // x9
  _QWORD *v66; // x8
  _QWORD *v67; // x9
  __int64 v68; // x10
  _QWORD *v69; // x2
  __int64 v70; // x11
  __int64 v71; // x9
  unsigned __int64 v72; // x8
  _QWORD *v73; // x10
  _QWORD *v74; // x11
  __int64 v75; // x12
  _QWORD *v76; // x8
  int v77; // w10
  _QWORD *v78; // x9
  _QWORD *v79; // x9
  _QWORD *v80; // x11
  int v81; // w10
  _QWORD *v82; // x11
  _QWORD *v83; // x8
  _QWORD *v84; // x8
  __int64 v85; // x9
  __int64 v86; // x8
  unsigned int v87; // w9
  int v88; // w9
  int v90; // [xsp+4h] [xbp-7Ch]
  _QWORD *v91; // [xsp+8h] [xbp-78h]
  __int64 v92; // [xsp+10h] [xbp-70h]
  __int64 v93; // [xsp+18h] [xbp-68h] BYREF
  __int64 v94; // [xsp+20h] [xbp-60h]
  __int64 v95; // [xsp+28h] [xbp-58h]
  __int64 v96; // [xsp+30h] [xbp-50h]
  __int64 v97; // [xsp+38h] [xbp-48h]
  __int64 v98; // [xsp+40h] [xbp-40h]
  __int64 v99; // [xsp+48h] [xbp-38h]
  __int64 v100; // [xsp+50h] [xbp-30h]
  __int64 v101; // [xsp+58h] [xbp-28h] BYREF
  __int64 v102; // [xsp+60h] [xbp-20h]
  _QWORD *v103; // [xsp+68h] [xbp-18h]
  _BYTE *v104; // [xsp+70h] [xbp-10h]
  __int64 v105; // [xsp+78h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 944);
  v2 = *(_QWORD *)a1;
  v3 = *(_BYTE *)(a1 + 441);
  v103 = nullptr;
  v104 = nullptr;
  v92 = v1;
  v93 = 0;
  v4 = *(_QWORD *)(v1 + 832);
  v5 = *(_QWORD *)(v2 + 1616);
  v101 = 0;
  v102 = 0;
  v6 = v4 == 0;
  v7 = (_QWORD *)(v4 - 152);
  v99 = 0;
  v100 = 0;
  if ( v6 )
    v8 = nullptr;
  else
    v8 = v7;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v94 = 0;
  if ( (v3 & 1) == 0 )
  {
    __break(0x800u);
    v56 = -16;
LABEL_101:
    _ReadStatusReg(SP_EL0);
    return v56;
  }
  v9 = *(_BYTE **)(a1 + 368);
  v10 = a1;
  if ( !v9 || !v8 || *((_DWORD *)v9 + 16) == 2 )
  {
    __break(0x800u);
    v56 = -22;
    goto LABEL_101;
  }
  v11 = (__int64 *)(a1 + 376);
  v12 = v9 + 32;
  v13 = (__int64 *)(a1 + 376);
  v14 = v9 + 32;
  v91 = v8;
  while ( 1 )
  {
    v14 = (_QWORD *)*v14;
    if ( v14 == v12 )
      break;
    if ( !v14[44] )
    {
      v15 = v14[116];
      v17 = (_QWORD *)(v15 + 168);
      v16 = *(_QWORD *)(v15 + 168);
      if ( v16 )
      {
        v18 = v13[4];
        if ( v18 )
        {
          if ( v16 != v18
            || *(_DWORD *)(v15 + 176) != *((_DWORD *)v13 + 10)
            || *(_DWORD *)(v15 + 180) != *((_DWORD *)v13 + 11)
            || *(unsigned __int16 *)(v15 + 196) != *((unsigned __int16 *)v13 + 30)
            || *(_DWORD *)(v15 + 184) != *((_DWORD *)v13 + 12)
            || *(unsigned __int16 *)(v15 + 198) != *((unsigned __int16 *)v13 + 31) )
          {
            goto LABEL_70;
          }
        }
      }
      a1 = cfg80211_chandef_compatible(v15 + 136, v13);
      if ( !a1 )
        goto LABEL_70;
      v19 = *(_QWORD *)(a1 + 24);
      v20 = v13 + 4;
      v13 = &v93;
      v6 = *v17 == 0;
      v21 = *(_QWORD *)a1;
      v22 = *(_QWORD *)(a1 + 8);
      v95 = *(_QWORD *)(a1 + 16);
      v96 = v19;
      if ( v6 )
        v23 = v20;
      else
        v23 = v17;
      v93 = v21;
      v94 = v22;
      v25 = v23[2];
      v24 = v23[3];
      v28 = v23;
      v27 = *v23;
      v26 = v28[1];
      v99 = v25;
      v100 = v24;
      v97 = v27;
      v98 = v26;
    }
  }
  if ( !v13 )
  {
LABEL_70:
    __break(0x800u);
    v56 = -22;
    goto LABEL_101;
  }
  v29 = *(_QWORD *)(v10 + 432);
  v30 = v5;
  v32 = *(_QWORD *)(v10 + 408);
  v31 = *(_QWORD *)(v10 + 416);
  v33 = *(_QWORD **)(v10 + 944);
  v34 = *(_DWORD *)(v10 + 384);
  v35 = *(_QWORD *)v10;
  v36 = *(_DWORD *)(v92 + 144);
  v37 = *(unsigned int *)(v10 + 8);
  v33[23] = *(_QWORD *)(v10 + 424);
  v33[24] = v29;
  v33[21] = v32;
  v33[22] = v31;
  v38 = *(_QWORD *)(v10 + 400);
  v39 = *v11;
  v40 = *(_QWORD *)(v10 + 384);
  v33[19] = *(_QWORD *)(v10 + 392);
  v33[20] = v38;
  v33[17] = v39;
  v33[18] = v40;
  if ( *(_DWORD *)(v35 + 4720) == 3 )
  {
    v41 = *(_QWORD **)(v35 + 2264);
    v42 = (_QWORD *)(v35 + 2264);
    if ( v41 != v42 )
    {
      if ( (unsigned int)v37 > 0xE )
        goto LABEL_104;
      do
      {
        v43 = (_QWORD *)v41[v37 + 427];
        if ( v43 )
        {
          v44 = *(_QWORD *)(v10 + 400);
          v45 = *v11;
          v46 = *(_QWORD *)(v10 + 384);
          v43[19] = *(_QWORD *)(v10 + 392);
          v43[20] = v44;
          v43[17] = v45;
          v43[18] = v46;
          v47 = *(_QWORD *)(v10 + 432);
          v48 = *(_QWORD *)(v10 + 408);
          v49 = *(_QWORD *)(v10 + 416);
          v43[23] = *(_QWORD *)(v10 + 424);
          v43[24] = v47;
          v43[21] = v48;
          v43[22] = v49;
        }
        else
        {
          __break(0x800u);
        }
        v41 = (_QWORD *)*v41;
      }
      while ( v41 != v42 );
    }
  }
  v50 = v5;
  v90 = v34;
  v51 = v36;
  ieee80211_change_chanctx(v50, v9, v91, v13, v10);
  v52 = *(_QWORD *)(v10 + 944);
  v103 = v91 + 19;
  v104 = v9 + 152;
  v53 = *(_QWORD **)(v10 + 40);
  v54 = v10 + 32;
  v101 = v2 + 4720;
  v102 = v52;
  if ( *v53 == v10 + 32 && (v55 = *(_QWORD *)v54, *(_QWORD *)(*(_QWORD *)v54 + 8LL) == v54) )
  {
    *(_QWORD *)(v55 + 8) = v53;
    *v53 = v55;
  }
  else
  {
    _list_del_entry_valid_or_report(v54);
  }
  *(_QWORD *)(v10 + 368) = 0;
  *(_QWORD *)(v10 + 32) = 0xDEAD000000000100LL;
  *(_QWORD *)(v10 + 40) = 0xDEAD000000000122LL;
  a1 = drv_switch_vif_chanctx(v30, &v101, 1, 0);
  v56 = a1;
  if ( (_DWORD)a1 )
  {
    v57 = 2;
    v58 = v9 + 32;
    do
    {
      v58 = (_QWORD *)*v58;
      --v57;
    }
    while ( v58 != v12 );
    v59 = v9 + 48;
    v60 = v9 + 48;
    do
    {
      v60 = (_QWORD *)*v60;
      --v57;
    }
    while ( v60 != v59 );
    if ( !v57 )
    {
      v61 = 2;
      v62 = v9 + 32;
      do
      {
        v62 = (_QWORD *)*v62;
        --v61;
      }
      while ( v62 != v12 );
      v63 = v9 + 48;
      do
      {
        v63 = (_QWORD *)*v63;
        --v61;
      }
      while ( v63 != v59 );
      if ( v61 )
        __break(0x800u);
      v64 = *((_QWORD **)v9 + 1);
      if ( (_BYTE *)*v64 == v9 && (v65 = *(_QWORD *)v9, *(_BYTE **)(*(_QWORD *)v9 + 8LL) == v9) )
      {
        *(_QWORD *)(v65 + 8) = v64;
        *v64 = v65;
      }
      else
      {
        _list_del_entry_valid_or_report(v9);
      }
      *((_QWORD *)v9 + 1) = 0xDEAD000000000122LL;
      ieee80211_del_chanctx(v30, v9, 0);
      kvfree_call_rcu(v9 + 16, v9);
    }
LABEL_96:
    v86 = *(_QWORD *)v10;
    v87 = *(_DWORD *)(*(_QWORD *)v10 + 4720LL);
    if ( v87 <= 0xD )
    {
      v88 = 1 << v87;
      if ( (v88 & 0x3771) != 0 )
      {
        __break(0x800u);
      }
      else if ( (v88 & 0x88A) != 0 )
      {
        wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v86 + 1616) + 72LL), v10 + 144);
      }
      else
      {
        wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(v86 + 1616) + 72LL), v10 + 568, 0);
      }
    }
    goto LABEL_101;
  }
  v66 = *(_QWORD **)(v10 + 24);
  v67 = (_QWORD *)(v10 + 16);
  if ( *v66 == v10 + 16 && (v68 = *v67, *(_QWORD **)(*v67 + 8LL) == v67) )
  {
    *(_QWORD *)(v68 + 8) = v66;
    *v66 = v68;
  }
  else
  {
    a1 = _list_del_entry_valid_or_report(v10 + 16);
  }
  v69 = (_QWORD *)*v12;
  if ( *(_QWORD **)(*v12 + 8LL) != v12 || v67 == v12 || v69 == v67 )
  {
    a1 = _list_add_valid_or_report(v67, v9 + 32);
  }
  else
  {
    v69[1] = v67;
    *(_QWORD *)(v10 + 16) = v69;
    *(_QWORD *)(v10 + 24) = v12;
    *v12 = v67;
  }
  atomic_store((unsigned __int64)(v9 + 152), (unsigned __int64 *)(v92 + 832));
  if ( *(_DWORD *)(v2 + 4720) != 3 )
  {
LABEL_79:
    ieee80211_check_fast_xmit_iface(v2);
    v76 = v91 + 4;
    v77 = 2;
    v78 = v91 + 4;
    do
    {
      v78 = (_QWORD *)*v78;
      --v77;
    }
    while ( v78 != v76 );
    v79 = v91 + 6;
    v80 = v91 + 6;
    do
    {
      v80 = (_QWORD *)*v80;
      --v77;
    }
    while ( v80 != v79 );
    if ( !v77 )
    {
      v81 = 2;
      v82 = v91 + 4;
      do
      {
        v82 = (_QWORD *)*v82;
        --v81;
      }
      while ( v82 != v76 );
      v83 = v91 + 6;
      do
      {
        v83 = (_QWORD *)*v83;
        --v81;
      }
      while ( v83 != v79 );
      if ( v81 )
        __break(0x800u);
      v84 = (_QWORD *)v91[1];
      if ( (_QWORD *)*v84 == v91 && (v85 = *v91, *(_QWORD **)(*v91 + 8LL) == v91) )
      {
        *(_QWORD *)(v85 + 8) = v84;
        *v84 = v85;
      }
      else
      {
        _list_del_entry_valid_or_report(v91);
      }
      v91[1] = 0xDEAD000000000122LL;
      ieee80211_del_chanctx(v30, v91, 0);
      kvfree_call_rcu(v91 + 2, v91);
    }
    ieee80211_recalc_chanctx_min_def(v30, (__int64)v9);
    ieee80211_recalc_smps_chanctx(v30, v9);
    ieee80211_recalc_radar_chanctx(v30, (__int64)v9);
    if ( v51 != v90 )
      ieee80211_link_info_change_notify(v2, v10, 0x200000);
    goto LABEL_96;
  }
  v70 = *(_QWORD *)v10;
  if ( *(_DWORD *)(*(_QWORD *)v10 + 4720LL) != 3 )
  {
    __break(0x800u);
    goto LABEL_79;
  }
  v71 = *(unsigned int *)(v10 + 8);
  v72 = *(_QWORD *)(*(_QWORD *)(v10 + 944) + 832LL);
  if ( !v72 )
    __break(0x800u);
  v73 = *(_QWORD **)(v70 + 2264);
  v74 = (_QWORD *)(v70 + 2264);
  if ( v73 == v74 )
    goto LABEL_79;
  if ( (unsigned int)v71 <= 0xE )
  {
    do
    {
      v75 = v73[v71 + 427];
      if ( v75 )
        atomic_store(v72, (unsigned __int64 *)(v75 + 832));
      else
        __break(0x800u);
      v73 = (_QWORD *)*v73;
    }
    while ( v73 != v74 );
    goto LABEL_79;
  }
LABEL_104:
  __break(0x5512u);
  return ieee80211_link_use_reserved_assign(a1);
}
