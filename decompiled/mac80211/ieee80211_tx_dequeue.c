__int64 __fastcall ieee80211_tx_dequeue(__int64 a1, __int64 *a2)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x13
  unsigned __int64 StatusReg; // x9
  __int64 v6; // x25
  __int64 *v7; // x27
  __int64 v8; // x24
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x10
  _DWORD *v12; // x10
  unsigned int v13; // t1
  __int64 v14; // x0
  __int64 v15; // x22
  __int64 v16; // x19
  __int64 *v17; // x26
  __int64 v18; // x23
  __int64 v19; // x8
  _QWORD *v20; // x9
  int v21; // w8
  __int64 v22; // x11
  __int64 *v23; // x24
  __int64 *v24; // x22
  int v25; // w8
  __int64 v26; // x9
  __int64 *v27; // x8
  __int64 v28; // x26
  __int64 v29; // x25
  __int64 v30; // x8
  __int64 v31; // x0
  char v32; // w21
  __int64 v33; // x1
  int v34; // w9
  __int64 **v35; // x8
  __int64 *v36; // x9
  __int64 **v37; // x1
  __int64 v38; // x2
  __int64 v39; // x8
  _QWORD *v40; // x9
  __int64 v41; // x0
  unsigned __int64 v42; // x19
  unsigned int v43; // w9
  int v44; // w8
  int v45; // w9
  int v46; // w9
  unsigned __int64 v47; // x8
  unsigned int v48; // w10
  __int64 v49; // x10
  __int64 v50; // x9
  __int64 v51; // x1
  __int64 v52; // x8
  __int64 v53; // x0
  int v54; // w9
  __int64 v55; // x2
  __int64 v56; // x9
  _QWORD *v57; // x10
  unsigned int v58; // w9
  int v59; // w8
  int v60; // w8
  char v61; // w10
  __int64 v62; // x10
  __int64 v63; // x9
  __int64 v64; // x1
  __int64 v65; // x8
  __int64 v66; // x2
  __int64 v67; // x9
  _QWORD *v68; // x10
  unsigned int v69; // w9
  int v70; // w8
  unsigned int v71; // w8
  __int64 v72; // x9
  unsigned __int64 v73; // x9
  __int64 v74; // x9
  int v75; // w8
  __int64 v76; // x9
  __int64 v77; // x25
  int v78; // w19
  int v79; // w21
  int v80; // w8
  int v81; // w9
  int *v82; // x8
  int v83; // w0
  __int64 v84; // x8
  __int64 v85; // x9
  unsigned int v86; // w10
  unsigned int v87; // w11
  __int64 v88; // x9
  unsigned int v89; // w10
  unsigned int v90; // w11
  __int64 **v91; // x8
  __int64 *v92; // x9
  __int64 **v93; // x8
  __int64 *v94; // x9
  int v95; // w9
  unsigned __int16 *v96; // x21
  __int64 v97; // x19
  _DWORD *v98; // x9
  __int64 v99; // x8
  _QWORD *v100; // x8
  __int64 v101; // x8
  _QWORD *v102; // x9
  _QWORD *v103; // x8
  _QWORD *v104; // x9
  __int64 **v105; // x10
  __int64 v106; // x3
  __int64 v107; // x22
  unsigned __int8 v108; // w2
  __int64 v109; // x0
  __int64 v110; // x21
  unsigned __int8 v111; // w0
  __int64 v112; // x8
  int v113; // w9
  _DWORD *v114; // x8
  __int64 v115; // x0
  __int64 v116; // x19
  __int64 v118; // x1
  int v119; // w0
  unsigned int v120; // w8
  unsigned __int64 v121; // x9
  unsigned __int64 v128; // x9
  __int64 v129; // [xsp+0h] [xbp-B0h]
  __int64 v130; // [xsp+8h] [xbp-A8h]
  __int64 v131; // [xsp+10h] [xbp-A0h]
  __int64 *v132; // [xsp+20h] [xbp-90h]
  __int64 v133; // [xsp+30h] [xbp-80h]
  __int64 *v134; // [xsp+38h] [xbp-78h]
  __int64 v135; // [xsp+40h] [xbp-70h]
  __int64 v136; // [xsp+50h] [xbp-60h] BYREF
  _QWORD *v137; // [xsp+58h] [xbp-58h] BYREF
  __int64 **v138; // [xsp+60h] [xbp-50h]
  __int64 v139; // [xsp+68h] [xbp-48h]
  __int64 v140; // [xsp+70h] [xbp-40h]
  _DWORD *v141; // [xsp+78h] [xbp-38h]
  __int64 v142; // [xsp+80h] [xbp-30h]
  __int64 v143; // [xsp+88h] [xbp-28h]
  __int64 v144; // [xsp+90h] [xbp-20h]
  int v145; // [xsp+9Ch] [xbp-14h] BYREF
  __int64 v146; // [xsp+A0h] [xbp-10h]

  v146 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((unsigned __int8 *)a2 + 17);
  v143 = 0;
  v144 = 0;
  v141 = nullptr;
  v142 = 0;
  v139 = 0;
  v140 = 0;
  v137 = nullptr;
  v138 = nullptr;
  v136 = 0;
  if ( v2 >= 4 )
    goto LABEL_212;
  v3 = *a2;
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = a1;
  v7 = a2 - 29;
  v8 = *(unsigned __int8 *)(v3 + v2 + 1130);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    __break(0x800u);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 117LL) & 1) != 0 )
  {
    v9 = a2[1];
    if ( v9 )
    {
      if ( *((_BYTE *)a2 + 16) != 16 )
      {
        if ( *((unsigned __int8 *)a2 + 17) >= 4uLL )
          goto LABEL_212;
        v10 = v9 - 2160;
        v11 = v10 + 40LL * *((unsigned __int8 *)a2 + 17);
        v13 = *(_DWORD *)(v11 + 28);
        v12 = (_DWORD *)(v11 + 28);
        if ( v13 >= v12[1]
          && (*(_DWORD *)(a1 + 444) >= *(_DWORD *)(a1 + 440)
           || *v12 >= *(_DWORD *)(v10 + 40LL * *((unsigned __int8 *)a2 + 17) + 36)) )
        {
          v18 = 0;
          goto LABEL_195;
        }
      }
    }
  }
  v129 = v3;
  v14 = raw_spin_lock_irqsave(a1 + 1312);
  if ( (unsigned int)v8 > 0xF )
LABEL_212:
    __break(0x5512u);
  v15 = v6 + 480;
  v16 = *(_QWORD *)(v6 + 480 + 8 * v8);
  raw_spin_unlock_irqrestore(v6 + 1312, v14);
  if ( v16 )
  {
LABEL_192:
    _X8 = (unsigned __int64 *)(a2 - 1);
    __asm { PRFM            #0x11, [X8] }
    do
      v128 = __ldxr(_X8);
    while ( __stxr(v128 | 8, _X8) );
    v18 = 0;
    goto LABEL_195;
  }
  v17 = a2 - 27;
  v133 = v6 + 288;
  v134 = a2 - 27;
  v135 = v6;
  v132 = a2 - 4;
  v130 = v8;
  v131 = v6 + 480;
  while ( 2 )
  {
    raw_spin_lock_bh(v6 + 240);
    v18 = *v132;
    if ( (__int64 *)*v132 != v132 && v18 )
    {
      --*((_DWORD *)a2 - 4);
      v19 = *(_QWORD *)v18;
      v20 = *(_QWORD **)(v18 + 8);
      *(_QWORD *)v18 = 0;
      *(_QWORD *)(v18 + 8) = 0;
      *(_QWORD *)(v19 + 8) = v20;
      *v20 = v19;
      v21 = *(_DWORD *)(v18 + 80);
      if ( (v21 & 0x40) != 0 )
      {
        *(_DWORD *)(v18 + 80) = v21 & 0xFFFFFFBF;
        goto LABEL_148;
      }
      goto LABEL_194;
    }
    if ( (*(a2 - 1) & 1) != 0 )
    {
LABEL_193:
      v18 = 0;
LABEL_194:
      raw_spin_unlock_bh(v6 + 240);
      goto LABEL_195;
    }
    v22 = (__int64)(a2 - 23);
    while ( 1 )
    {
      while ( 1 )
      {
        v23 = (__int64 *)*v7;
        v24 = v7;
        if ( (__int64 *)*v7 == v7 )
        {
          v23 = (__int64 *)*v17;
          v24 = v17;
          if ( (__int64 *)*v17 == v17 )
            goto LABEL_193;
        }
        v25 = *((_DWORD *)v23 + 11);
        if ( v25 > 0 )
          break;
        v34 = *(_DWORD *)(v6 + 260) + v25;
        v35 = (__int64 **)v23[1];
        *((_DWORD *)v23 + 11) = v34;
        if ( *v35 == v23 && (v36 = (__int64 *)*v23, *(__int64 **)(*v23 + 8) == v23) )
        {
          v36[1] = (__int64)v35;
          *v35 = v36;
        }
        else
        {
          _list_del_entry_valid_or_report(v23);
        }
        v37 = (__int64 **)*(a2 - 26);
        if ( v23 == v17 )
          goto LABEL_145;
LABEL_132:
        if ( v37 == (__int64 **)v23 || *v37 != v17 )
          goto LABEL_145;
        *(a2 - 26) = (__int64)v23;
        *v23 = (__int64)v17;
        v23[1] = (__int64)v37;
        *v37 = v23;
      }
      v26 = a2[1];
      v27 = v23 - 1;
      if ( v26 )
        v28 = v26 - 1376;
      else
        v28 = v133;
      if ( (__int64 *)v22 == v27 )
      {
        v29 = (__int64)(a2 - 12);
        v32 = 1;
        v33 = v22;
        v31 = *(_QWORD *)(*a2 - 3104) + 208LL;
      }
      else
      {
        v29 = *(_QWORD *)(v6 + 280) + 0x4924924924924928LL * (((__int64)v27 - *(_QWORD *)(v6 + 208)) >> 3);
        v30 = *(_QWORD *)(*a2 - 3104);
        v31 = v30 + 208;
        if ( a2 - 12 == (__int64 *)v29 )
        {
          v32 = 1;
          v33 = v22;
        }
        else
        {
          v32 = 0;
          v33 = *(_QWORD *)(v30 + 208) + 0x5555555555555568LL * ((v29 - *(_QWORD *)(v30 + 280)) >> 3);
        }
      }
      v18 = *(_QWORD *)(v33 + 24);
      if ( v18 == v33 + 24 || !v18 )
      {
        *(_BYTE *)(v29 + 8) = 0;
        goto LABEL_122;
      }
      v38 = *(_QWORD *)(v33 + 24);
      --*(_DWORD *)(v33 + 40);
      v39 = *(_QWORD *)v18;
      v40 = *(_QWORD **)(v18 + 8);
      *(_QWORD *)v18 = 0;
      *(_QWORD *)(v18 + 8) = 0;
      *(_QWORD *)(v39 + 8) = v40;
      *v40 = v39;
      v41 = fq_adjust_removal(v31, v33, v38);
      v42 = (unsigned __int64)ktime_get(v41) >> 10;
      v43 = *(_DWORD *)(v18 + 112);
      v44 = v42 - *(_DWORD *)(v18 + 84);
      *(_DWORD *)(v29 + 20) = v44;
      if ( v43 > *((_DWORD *)a2 - 18) )
      {
        *((_DWORD *)a2 - 18) = v43;
        v44 = *(_DWORD *)(v29 + 20);
      }
      if ( *(_DWORD *)v28 - v44 > 0 || *((_DWORD *)v23 + 10) <= *(_DWORD *)(v28 + 12) )
      {
        v45 = 0;
        *(_DWORD *)(v29 + 12) = 0;
      }
      else
      {
        v45 = *(_DWORD *)(v29 + 12);
        if ( v45 )
          v45 = (int)v42 - v45 > 0;
        else
          *(_DWORD *)(v29 + 12) = *(_DWORD *)(v28 + 8) + v42;
      }
      if ( *(_BYTE *)(v29 + 8) == 1 )
        break;
      if ( !v45 )
        goto LABEL_92;
      if ( *(_BYTE *)(v28 + 16) == 1 && (unsigned int)INET_ECN_set_ce(v18) )
      {
        ++*((_DWORD *)a2 - 15);
      }
      else
      {
        v62 = *a2;
        *((_DWORD *)a2 - 16) += *(_DWORD *)(v18 + 112);
        ieee80211_free_txskb(*(_QWORD *)(v62 - 3104), v18);
        v63 = *a2;
        v64 = (__int64)(a2 - 23);
        ++*((_DWORD *)a2 - 17);
        v65 = *(_QWORD *)(v63 - 3104);
        if ( (v32 & 1) == 0 )
          v64 = *(_QWORD *)(v65 + 208) + 0x5555555555555568LL * ((v29 - *(_QWORD *)(v65 + 280)) >> 3);
        v18 = *(_QWORD *)(v64 + 24);
        if ( v18 == v64 + 24 || !v18 )
        {
          v18 = 0;
LABEL_78:
          *(_DWORD *)(v29 + 12) = 0;
          goto LABEL_79;
        }
        v66 = *(_QWORD *)(v64 + 24);
        --*(_DWORD *)(v64 + 40);
        v67 = *(_QWORD *)v18;
        v68 = *(_QWORD **)(v18 + 8);
        *(_QWORD *)v18 = 0;
        *(_QWORD *)(v18 + 8) = 0;
        *(_QWORD *)(v67 + 8) = v68;
        *v68 = v67;
        fq_adjust_removal(v65 + 208, v64, v66);
        v69 = *(_DWORD *)(v18 + 112);
        v70 = v42 - *(_DWORD *)(v18 + 84);
        *(_DWORD *)(v29 + 20) = v70;
        if ( v69 > *((_DWORD *)a2 - 18) )
        {
          *((_DWORD *)a2 - 18) = v69;
          v70 = *(_DWORD *)(v29 + 20);
        }
        if ( *(_DWORD *)v28 - v70 > 0 || *((_DWORD *)v23 + 10) <= *(_DWORD *)(v28 + 12) )
          goto LABEL_78;
        if ( !*(_DWORD *)(v29 + 12) )
          *(_DWORD *)(v29 + 12) = *(_DWORD *)(v28 + 8) + v42;
      }
LABEL_79:
      v71 = *(_DWORD *)v29 - *(_DWORD *)(v29 + 4);
      *(_BYTE *)(v29 + 8) = 1;
      if ( v71 < 2 || *(_DWORD *)(v29 + 16) - (int)v42 + 16 * *(_DWORD *)(v28 + 8) < 1 )
      {
        v71 = 1;
        *(_WORD *)(v29 + 10) = -1;
        LODWORD(v74) = -65536;
        *(_DWORD *)v29 = 1;
      }
      else
      {
        v72 = *(unsigned __int16 *)(v29 + 10);
        *(_DWORD *)v29 = v71;
        v73 = ((0x300000000LL
              - (((unsigned int)((_DWORD)v72 << 16) * (unsigned __int64)(unsigned int)((_DWORD)v72 << 16)) >> 32) * v71) >> 2)
            * (v72 << 16);
        *(_WORD *)(v29 + 10) = v73 >> 47;
        v74 = (v73 >> 31) & 0xFFFF0000;
      }
      *(_DWORD *)(v29 + 4) = v71;
      *(_DWORD *)(v29 + 16) = (((unsigned int)v74 * (unsigned __int64)*(unsigned int *)(v28 + 8)) >> 32) + v42;
      if ( v18 )
        goto LABEL_91;
LABEL_122:
      v17 = a2 - 27;
      if ( v24 != v7 || (__int64 *)*v134 == v134 )
      {
        v91 = (__int64 **)v23[1];
        v22 = (__int64)(a2 - 23);
        if ( *v91 == v23 && (v92 = (__int64 *)*v23, *(__int64 **)(*v23 + 8) == v23) )
        {
          v92[1] = (__int64)v91;
          *v91 = v92;
        }
        else
        {
          _list_del_entry_valid_or_report(v23);
        }
        *v23 = (__int64)v23;
        v23[1] = (__int64)v23;
        v6 = v135;
        *(v23 - 1) = 0;
      }
      else
      {
        v93 = (__int64 **)v23[1];
        v22 = (__int64)(a2 - 23);
        if ( *v93 == v23 && (v94 = (__int64 *)*v23, *(__int64 **)(*v23 + 8) == v23) )
        {
          v94[1] = (__int64)v93;
          *v93 = v94;
        }
        else
        {
          _list_del_entry_valid_or_report(v23);
        }
        v37 = (__int64 **)*(a2 - 26);
        v6 = v135;
        if ( v23 != v134 )
          goto LABEL_132;
LABEL_145:
        _list_add_valid_or_report(v23, v37);
      }
    }
    if ( (v45 & 1) == 0 )
    {
      *(_BYTE *)(v29 + 8) = 0;
      goto LABEL_92;
    }
    v46 = *(_DWORD *)(v29 + 16);
    if ( (int)v42 - v46 < 0 )
      goto LABEL_92;
    while ( 1 )
    {
      if ( (int)v42 - v46 < 0 )
        goto LABEL_91;
      v47 = (unsigned __int64)*(unsigned __int16 *)(v29 + 10) << 16;
      v48 = *(_DWORD *)v29 + 1;
      *(_DWORD *)v29 = v48;
      *(_WORD *)(v29 + 10) = (((0x300000000LL - (((unsigned int)v47 * (unsigned __int64)(unsigned int)v47) >> 32) * v48) >> 2)
                            * v47) >> 47;
      if ( *(_BYTE *)(v28 + 16) == 1 && (unsigned int)INET_ECN_set_ce(v18) )
      {
        ++*((_DWORD *)a2 - 15);
        *(_DWORD *)(v29 + 16) += (*(unsigned int *)(v28 + 8) * (unsigned __int64)*(unsigned __int16 *)(v29 + 10)) >> 16;
        goto LABEL_91;
      }
      v49 = *a2;
      *((_DWORD *)a2 - 16) += *(_DWORD *)(v18 + 112);
      ieee80211_free_txskb(*(_QWORD *)(v49 - 3104), v18);
      v50 = *a2;
      v51 = (__int64)(a2 - 23);
      ++*((_DWORD *)a2 - 17);
      v52 = *(_QWORD *)(v50 - 3104);
      if ( (v32 & 1) == 0 )
        v51 = *(_QWORD *)(v52 + 208) + 0x5555555555555568LL * ((v29 - *(_QWORD *)(v52 + 280)) >> 3);
      v53 = 0;
      v18 = *(_QWORD *)(v51 + 24);
      v54 = 0;
      if ( v18 == v51 + 24 || !v18 )
        goto LABEL_90;
      v55 = *(_QWORD *)(v51 + 24);
      --*(_DWORD *)(v51 + 40);
      v56 = *(_QWORD *)v18;
      v57 = *(_QWORD **)(v18 + 8);
      *(_QWORD *)v18 = 0;
      *(_QWORD *)(v18 + 8) = 0;
      *(_QWORD *)(v56 + 8) = v57;
      *v57 = v56;
      fq_adjust_removal(v52 + 208, v51, v55);
      v58 = *(_DWORD *)(v18 + 112);
      v59 = v42 - *(_DWORD *)(v18 + 84);
      *(_DWORD *)(v29 + 20) = v59;
      if ( v58 > *((_DWORD *)a2 - 18) )
      {
        *((_DWORD *)a2 - 18) = v58;
        v59 = *(_DWORD *)(v29 + 20);
      }
      if ( *(_DWORD *)v28 - v59 > 0 || *((_DWORD *)v23 + 10) <= *(_DWORD *)(v28 + 12) )
        break;
      v60 = *(_DWORD *)(v29 + 12);
      if ( !v60 )
      {
        v54 = *(_DWORD *)(v28 + 8) + v42;
        goto LABEL_89;
      }
      if ( (int)v42 - v60 <= 0 )
      {
        *(_BYTE *)(v29 + 8) = 0;
        goto LABEL_91;
      }
      v61 = *(_BYTE *)(v29 + 8);
      v46 = *(_DWORD *)(v29 + 16)
          + ((*(unsigned int *)(v28 + 8) * (unsigned __int64)*(unsigned __int16 *)(v29 + 10)) >> 16);
      *(_DWORD *)(v29 + 16) = v46;
      if ( (v61 & 1) == 0 )
        goto LABEL_91;
    }
    v54 = 0;
LABEL_89:
    v53 = v18;
LABEL_90:
    *(_DWORD *)(v29 + 12) = v54;
    v18 = v53;
    *(_BYTE *)(v29 + 8) = 0;
    if ( !v53 )
      goto LABEL_122;
LABEL_91:
    v44 = *(_DWORD *)(v29 + 20);
LABEL_92:
    if ( v44 - *(_DWORD *)(v28 + 4) < 1 )
      goto LABEL_147;
    if ( !*(_BYTE *)(v28 + 18) )
      goto LABEL_119;
    v75 = *(unsigned __int16 *)(v18 + 180);
    v76 = *(unsigned __int16 *)(v18 + 120);
    if ( v75 != 43144 && v75 != 129 )
      goto LABEL_112;
    if ( !*(_WORD *)(v18 + 120) )
    {
      v77 = 14;
      goto LABEL_100;
    }
    if ( (unsigned int)v76 > 3 )
    {
      v77 = v76 - 4;
LABEL_100:
      v78 = 0;
      v79 = -(int)v77;
      while ( 1 )
      {
        v80 = *(_DWORD *)(v18 + 112);
        v81 = *(_DWORD *)(v18 + 116);
        v145 = 0;
        if ( v79 + v78 + v80 - v81 < 4 )
        {
          v83 = skb_copy_bits(v18, (unsigned int)v77, &v145, 4);
          v82 = &v145;
          if ( v83 < 0 )
            v82 = nullptr;
          if ( !v82 )
            goto LABEL_121;
        }
        else
        {
          v82 = (int *)(*(_QWORD *)(v18 + 224) + v77);
          if ( !v82 )
            goto LABEL_121;
        }
        if ( v78 == -28 )
          goto LABEL_121;
        v75 = *((unsigned __int16 *)v82 + 1);
        if ( v75 != 43144 && v75 != 129 )
          break;
        v77 += 4;
        v78 -= 4;
      }
LABEL_112:
      if ( v75 != 56710 )
      {
        if ( v75 == 8 )
        {
          v84 = *(_QWORD *)(v18 + 216);
          v85 = *(unsigned __int16 *)(v18 + 184);
          v86 = *(_DWORD *)(v18 + 112);
          v87 = v84 + v85 - *(_DWORD *)(v18 + 224) + 20;
          if ( v87 <= v86 - *(_DWORD *)(v18 + 116) )
            goto LABEL_115;
          if ( v86 >= v87 && _pskb_pull_tail(v18) )
          {
            v84 = *(_QWORD *)(v18 + 216);
            v85 = *(unsigned __int16 *)(v18 + 184);
LABEL_115:
            LOBYTE(v84) = *(_BYTE *)(v84 + v85 + 1);
LABEL_118:
            if ( (unsigned __int8)(v84 & *(_BYTE *)(v28 + 18)) == *(unsigned __int8 *)(v28 + 17) )
            {
LABEL_119:
              if ( (unsigned int)INET_ECN_set_ce(v18) )
                ++*((_DWORD *)a2 - 14);
            }
          }
        }
LABEL_121:
        if ( v18 )
          goto LABEL_147;
        goto LABEL_122;
      }
      v84 = *(_QWORD *)(v18 + 216);
      v88 = *(unsigned __int16 *)(v18 + 184);
      v89 = *(_DWORD *)(v18 + 112);
      v90 = v84 + v88 - *(_DWORD *)(v18 + 224) + 40;
      if ( v90 > v89 - *(_DWORD *)(v18 + 116) )
      {
        if ( v89 < v90 || !_pskb_pull_tail(v18) )
          goto LABEL_121;
        v84 = *(_QWORD *)(v18 + 216);
        v88 = *(unsigned __int16 *)(v18 + 184);
      }
      LODWORD(v84) = bswap32(*(unsigned __int16 *)(v84 + v88)) >> 20;
      goto LABEL_118;
    }
    __break(0x800u);
LABEL_147:
    v17 = a2 - 27;
    v6 = v135;
    *((_DWORD *)v23 + 11) -= *(_DWORD *)(v18 + 112);
    v8 = v130;
    v15 = v131;
    v95 = *((_DWORD *)a2 - 26) + 1;
    *((_DWORD *)a2 - 27) += *(_DWORD *)(v18 + 112);
    *((_DWORD *)a2 - 26) = v95;
LABEL_148:
    raw_spin_unlock_bh(v6 + 240);
    v96 = *(unsigned __int16 **)(v18 + 224);
    v143 = 0;
    v144 = 0;
    v97 = v18 + 40;
    v98 = *(_DWORD **)(v18 + 64);
    v141 = nullptr;
    v142 = 0;
    v139 = 0;
    v140 = 0;
    v99 = a2[1];
    v137 = &v137;
    v138 = &v137;
    v136 = v18;
    v140 = v6;
    v141 = v98 - 1180;
    if ( v99 )
    {
      v142 = v99 - 2688;
      if ( (*(_BYTE *)v97 & 0x80) == 0
        && (*v96 & 0xC) == 8
        && *v98 != 11
        && (v96[2] & 1) == 0
        && (*(_QWORD *)(v99 - 2472) & 8) == 0
        && ((*(_BYTE *)(v18 + 80) & 1) == 0
         || (ieee80211_is_our_addr((__int64)(v98 - 1180), (__int64)(v96 + 5), nullptr) & 1) == 0) )
      {
        goto LABEL_190;
      }
    }
    if ( (unsigned int)ieee80211_tx_h_select_key(&v136) )
      goto LABEL_190;
    if ( (*(a2 - 1) & 2) != 0 )
      *(_DWORD *)v97 |= 0x40000040u;
    if ( (*(_BYTE *)(v18 + 41) & 0x40) != 0 )
    {
      if ( (*(_QWORD *)(v6 + 96) & 1) == 0 && (unsigned int)ieee80211_tx_h_rate_ctrl(&v136) )
        goto LABEL_190;
      v118 = v129;
LABEL_203:
      *(_QWORD *)(v97 + 24) = v118;
      if ( v142 )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(v6 + 72) + 117LL) & 1) != 0 )
        {
          v119 = ieee80211_calc_expected_tx_airtime(v6, v118, a2[1], *(_DWORD *)(v18 + 112), *((_BYTE *)a2 + 17) != 0);
          if ( v119 )
          {
            v120 = (unsigned __int16)v119;
            if ( (unsigned __int16)v119 >= 0xFFFu )
              v120 = 4095;
            *(_DWORD *)(v97 + 4) = *(_DWORD *)(v97 + 4) & 0x801FFFFF | (((v120 >> 2) & 0x3FF) << 21);
            ieee80211_sta_update_pending_airtime(v6, v142, *((_BYTE *)a2 + 17), v120 & 0xFFC, 0);
          }
        }
      }
      goto LABEL_195;
    }
    if ( (*(_BYTE *)(v18 + 80) & 0x10) != 0 )
    {
      v106 = v143;
      v107 = a2[1];
      if ( v143 && (*(_WORD *)(v143 + 552) & 2) != 0 )
      {
        v109 = *v96;
        v110 = v143;
        v111 = ieee80211_hdrlen(v109);
        v106 = v110;
        v108 = v111;
      }
      else
      {
        v108 = 0;
      }
      if ( !(unsigned int)ieee80211_xmit_fast_finish(*(_QWORD *)(v107 - 2608), v107 - 2688, v108, v106, &v136) )
      {
        v15 = v131;
        goto LABEL_181;
      }
      ieee80211_free_txskb(v6, v18);
      v15 = v131;
LABEL_191:
      v115 = raw_spin_lock_irqsave(v6 + 1312);
      v116 = *(_QWORD *)(v15 + 8 * v8);
      raw_spin_unlock_irqrestore(v6 + 1312, v115);
      if ( v116 )
        goto LABEL_192;
      continue;
    }
    break;
  }
  if ( (unsigned int)invoke_tx_handlers_late(&v136) )
    goto LABEL_191;
  v100 = v137;
  if ( v137 == &v137 )
    v18 = 0;
  else
    v18 = (__int64)v137;
  if ( v18 )
  {
    LODWORD(v139) = v139 - 1;
    v101 = *(_QWORD *)v18;
    v102 = *(_QWORD **)(v18 + 8);
    *(_QWORD *)v18 = 0;
    *(_QWORD *)(v18 + 8) = 0;
    *(_QWORD *)(v101 + 8) = v102;
    *v102 = v101;
    v100 = v137;
  }
  v97 = v18 + 40;
  if ( v100 != &v137 )
  {
    raw_spin_lock_bh(v6 + 240);
    v103 = v137;
    if ( v137 != &v137 )
    {
      v104 = (_QWORD *)*(a2 - 3);
      v105 = v138;
      v137[1] = v104;
      *v104 = v103;
      *v105 = v132;
      *(a2 - 3) = (__int64)v105;
      *((_DWORD *)a2 - 4) += v139;
    }
    raw_spin_unlock_bh(v6 + 240);
  }
LABEL_181:
  if ( *(_QWORD *)(*(_QWORD *)(v18 + 216) + *(unsigned int *)(v18 + 212) + 8LL)
    && (*(_QWORD *)(v6 + 96) & 0x1000000000LL) == 0
    && *(_DWORD *)(v18 + 116)
    && !_pskb_pull_tail(v18) )
  {
LABEL_190:
    ieee80211_free_txskb(v6, v18);
    goto LABEL_191;
  }
  v112 = (__int64)v141;
  v113 = v141[1180];
  if ( v113 != 6 )
  {
    if ( v113 == 4 )
    {
      v112 = *((_QWORD *)v141 + 254) - 2264LL;
      v141 = (_DWORD *)v112;
    }
    goto LABEL_202;
  }
  if ( (v141[566] & 0x40) != 0 )
  {
LABEL_202:
    v118 = v112 + 4720;
    goto LABEL_203;
  }
  v114 = *(_DWORD **)(v6 + 5384);
  v141 = v114;
  if ( v114 && (*(_QWORD *)(v6 + 96) & 0x1000) != 0 )
  {
    v121 = *(unsigned __int16 *)(v18 + 124);
    if ( v121 <= 3 )
    {
      v118 = (__int64)(v114 + 1180);
      *(_DWORD *)(v97 + 4) = *(_DWORD *)(v97 + 4) & 0xFFE1FFFF | ((*((_BYTE *)v114 + v121 + 5850) & 0xF) << 17);
      goto LABEL_203;
    }
    goto LABEL_212;
  }
  if ( (*(_QWORD *)(v6 + 96) & 0x40000) != 0 )
    goto LABEL_190;
  *(_QWORD *)(v97 + 24) = 0;
LABEL_195:
  _ReadStatusReg(SP_EL0);
  return v18;
}
