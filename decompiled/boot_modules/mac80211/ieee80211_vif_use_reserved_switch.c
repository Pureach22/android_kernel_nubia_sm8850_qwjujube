__int64 __fastcall ieee80211_vif_use_reserved_switch(__int64 a1)
{
  __int64 v1; // x8
  __int64 *v2; // x25
  int v4; // w9
  __int64 v5; // x20
  __int64 v6; // x23
  __int64 *v7; // x24
  __int64 v8; // x11
  __int64 *v9; // x11
  __int64 *v10; // x12
  __int64 *v11; // t1
  int v12; // w15
  int v13; // w13
  int v14; // w14
  __int64 *v15; // x12
  __int64 v16; // x13
  bool v17; // zf
  __int64 v18; // x14
  __int64 i; // x21
  _QWORD *v20; // x22
  _QWORD *v21; // x26
  __int64 v22; // x8
  bool v23; // zf
  __int64 v24; // x9
  __int64 result; // x0
  __int64 v26; // x19
  unsigned int v27; // w20
  _QWORD *v28; // x27
  _QWORD *v29; // x26
  __int64 v30; // x8
  unsigned int v31; // w9
  int v32; // w9
  unsigned __int64 v33; // x21
  __int64 v34; // x22
  __int64 v35; // x8
  int v36; // w9
  _QWORD *v37; // x12
  __int64 v38; // x14
  bool v39; // zf
  __int64 v40; // x15
  unsigned __int64 v41; // x15
  _QWORD *v42; // x16
  unsigned int v43; // w20
  bool v44; // cc
  int v45; // w0
  __int64 v46; // x20
  int v47; // w8
  __int64 *v48; // x22
  __int64 v49; // x28
  __int64 v50; // x8
  bool v51; // zf
  __int64 v52; // x9
  __int64 v53; // x11
  __int64 v54; // x9
  unsigned __int64 v55; // x8
  _QWORD *v56; // x10
  _QWORD *v57; // x11
  __int64 v58; // x12
  __int64 v59; // x13
  __int64 v60; // x15
  __int64 v61; // x14
  __int64 v62; // x16
  _QWORD *v63; // x11
  int v64; // w8
  __int64 v65; // x12
  int v66; // w9
  __int64 v67; // x10
  __int64 v68; // x13
  __int64 v69; // x15
  __int64 v70; // x16
  _QWORD *v71; // x11
  _QWORD *v72; // x12
  _QWORD *v73; // x13
  __int64 v74; // x14
  __int64 v75; // x16
  __int64 v76; // x17
  __int64 v77; // x14
  __int64 v78; // x16
  __int64 v79; // x17
  __int64 *v80; // x23
  __int64 v81; // x24
  __int64 *v82; // x21
  __int64 v83; // x8
  __int64 v84; // x8
  __int64 **v85; // x8
  __int64 **v86; // x8
  __int64 *v87; // x9
  __int64 *v88; // x10
  __int64 *v89; // x2
  __int64 v90; // x8
  unsigned int v91; // w9
  int v92; // w9
  unsigned int v93; // w0
  __int64 v94; // x3
  __int64 *v95; // x21
  __int64 v96; // x9
  __int64 v97; // x8
  bool v98; // zf
  __int64 *v99; // x24
  __int64 v100; // x8
  unsigned int v101; // w0
  __int64 v102; // x8
  __int64 v103; // x20
  __int64 *v104; // x19
  __int64 **v105; // x8
  __int64 *v106; // x9
  unsigned __int64 StatusReg; // x26
  __int64 v108; // x27

  v1 = *(_QWORD *)(a1 + 4984);
  v2 = (__int64 *)(a1 + 4984);
  if ( v1 == a1 + 4984 )
    goto LABEL_55;
  v4 = 0;
  v5 = 0;
  LODWORD(v6) = 0;
  LODWORD(v7) = 0;
  do
  {
    if ( *(_DWORD *)(v1 + 64) == 2 )
    {
      v8 = *(_QWORD *)(v1 + 72);
      if ( !v8 )
        goto LABEL_55;
      v11 = *(__int64 **)(v8 + 32);
      v9 = (__int64 *)(v8 + 32);
      v10 = v11;
      if ( v11 != v9 )
      {
        v12 = 0;
        v13 = 0;
        v14 = 0;
        do
        {
          if ( v10[44] )
          {
            ++v13;
            v14 += *((unsigned __int8 *)v10 + 425);
          }
          v10 = (__int64 *)*v10;
          ++v12;
        }
        while ( v10 != v9 );
        if ( v12 != v13 )
        {
          if ( v14 == v13 )
          {
            dev_info(
              *(_QWORD *)(a1 + 72) + 392LL,
              "channel context reservation cannot be finalized because some interfaces aren't switching\n");
            result = 4294967280LL;
            goto LABEL_57;
          }
          return 4294967285LL;
        }
      }
      ++v4;
      v15 = *(__int64 **)(v1 + 48);
      *(_BYTE *)(v1 + 254) = 0;
      if ( v15 != (__int64 *)(v1 + 48) )
      {
        while ( 1 )
        {
          v16 = *(_QWORD *)(v15[114] + 832);
          if ( v16 )
            v17 = v16 == 152;
          else
            v17 = 1;
          if ( v17 )
            goto LABEL_23;
          v18 = v15[42];
          if ( v18 )
            break;
          __break(0x800u);
          v16 = *(_QWORD *)(v15[114] + 832);
          if ( !v16 )
            goto LABEL_29;
LABEL_24:
          if ( v16 != 152 )
          {
            if ( *(_DWORD *)(v16 - 88) == 1 )
              v5 = (unsigned int)(v5 + 1);
            else
              LODWORD(v6) = v6 + 1;
            goto LABEL_30;
          }
LABEL_29:
          LODWORD(v7) = (_DWORD)v7 + 1;
LABEL_30:
          if ( *((_BYTE *)v15 + 408) == 1 )
            *(_BYTE *)(v1 + 254) = 1;
          v15 = (__int64 *)*v15;
          if ( v15 == (__int64 *)(v1 + 48) )
            goto LABEL_3;
        }
        if ( *(_DWORD *)(v16 - 88) == 1 && *(_DWORD *)(v18 + 64) == 2 && *((_BYTE *)v15 + 409) != 1 )
          return 4294967285LL;
LABEL_23:
        if ( !v16 )
          goto LABEL_29;
        goto LABEL_24;
      }
    }
LABEL_3:
    v1 = *(_QWORD *)v1;
  }
  while ( (__int64 *)v1 != v2 );
  if ( !v4 || !(_DWORD)v5 && !(_DWORD)v6 && !(_DWORD)v7 )
  {
LABEL_55:
    __break(0x800u);
LABEL_56:
    result = 4294967274LL;
    goto LABEL_57;
  }
  for ( i = *v2; (__int64 *)i != v2; i = *(_QWORD *)i )
  {
    if ( *(_DWORD *)(i + 64) == 2 )
    {
      if ( !*(_QWORD *)(i + 72) )
        goto LABEL_55;
      v20 = (_QWORD *)(i + 48);
      v21 = *(_QWORD **)(i + 48);
      if ( v21 == (_QWORD *)(i + 48) )
      {
LABEL_37:
        ieee80211_recalc_chanctx_min_def(a1, i);
        continue;
      }
      while ( 1 )
      {
LABEL_45:
        v22 = *(_QWORD *)(v21[114] + 832LL);
        if ( v22 )
          v23 = v22 == 152;
        else
          v23 = 1;
        if ( v23 )
          goto LABEL_44;
        v24 = v21[42];
        if ( v24 )
          break;
        __break(0x800u);
        v21 = (_QWORD *)*v21;
        if ( v21 == v20 )
          goto LABEL_37;
      }
      if ( *(_DWORD *)(v22 - 88) == 1 && *(_DWORD *)(v24 + 64) == 2 )
        ((void (__fastcall *)(__int64, __int64, __int64, __int64))ieee80211_chan_bw_change)(a1, v22 - 152, 1, 1);
LABEL_44:
      v21 = (_QWORD *)*v21;
      if ( v21 == v20 )
        goto LABEL_37;
      goto LABEL_45;
    }
  }
  if ( (int)v5 >= 1 )
  {
    v33 = 32LL * (unsigned int)v5;
    v34 = _kmalloc_noprof(v33, 3520);
    if ( !v34 )
      goto LABEL_226;
    goto LABEL_73;
  }
  while ( 1 )
  {
    v5 = *v2;
    v44 = (int)v7 < 1 && (int)v6 < 1;
    if ( !v44 && (__int64 *)v5 != v2 )
    {
      do
      {
        if ( *(_DWORD *)(v5 + 64) == 2 && *(_QWORD *)(*(_QWORD *)(v5 + 72) + 32LL) == *(_QWORD *)(v5 + 72) + 32LL )
        {
          ieee80211_del_chanctx(a1, *(_QWORD *)(v5 + 72), 0);
          v45 = ieee80211_add_chanctx(a1, v5);
          if ( v45 )
          {
            LODWORD(v33) = v45;
            if ( (unsigned int)ieee80211_add_chanctx(a1, v5) )
              goto LABEL_224;
            goto LABEL_106;
          }
        }
        v5 = *(_QWORD *)v5;
      }
      while ( (__int64 *)v5 != v2 );
      v5 = *v2;
    }
    if ( (__int64 *)v5 == v2 )
      return 0;
    while ( *(_DWORD *)(v5 + 64) != 2 )
    {
LABEL_118:
      v5 = *(_QWORD *)v5;
      if ( (__int64 *)v5 == v2 )
      {
        v103 = *v2;
        if ( (__int64 *)*v2 == v2 )
          return 0;
        while ( 1 )
        {
          v104 = *(__int64 **)v103;
          if ( *(_DWORD *)(v103 + 64) != 1 )
            goto LABEL_211;
          *(_QWORD *)(*(_QWORD *)(v103 + 72) + 72LL) = 0;
          *(_DWORD *)(*(_QWORD *)(v103 + 72) + 64LL) = 0;
          v105 = *(__int64 ***)(v103 + 8);
          if ( *v105 == (__int64 *)v103 )
          {
            v106 = *(__int64 **)v103;
            if ( *(_QWORD *)(*(_QWORD *)v103 + 8LL) == v103 )
              break;
          }
          _list_del_entry_valid_or_report(v103);
          *(_QWORD *)(v103 + 8) = 0xDEAD000000000122LL;
          if ( v103 )
            goto LABEL_210;
LABEL_211:
          v103 = (__int64)v104;
          if ( v104 == v2 )
            return 0;
        }
        v106[1] = (__int64)v105;
        *v105 = v106;
        *(_QWORD *)(v103 + 8) = 0xDEAD000000000122LL;
        if ( !v103 )
          goto LABEL_211;
LABEL_210:
        kvfree_call_rcu(v103 + 16, v103);
        goto LABEL_211;
      }
    }
    if ( !*(_QWORD *)(v5 + 72) )
      goto LABEL_55;
    v48 = (__int64 *)(v5 + 48);
    v7 = *(__int64 **)(v5 + 48);
    if ( v7 == (__int64 *)(v5 + 48) )
    {
LABEL_155:
      ((void (__fastcall *)(__int64, __int64))ieee80211_recalc_chanctx_chantype)(a1, v5);
      ieee80211_recalc_smps_chanctx(a1, (_BYTE *)v5);
      ieee80211_recalc_radar_chanctx(a1, v5);
      ieee80211_recalc_chanctx_min_def(a1, v5);
      v80 = *(__int64 **)(v5 + 48);
      if ( v80 != v48 )
      {
        v81 = v5 + 32;
        do
        {
          v82 = (__int64 *)*v80;
          v83 = *(_QWORD *)(v80[114] + 832);
          if ( v83 )
            v84 = v83 - 152;
          else
            v84 = 0;
          if ( v84 == v5 )
          {
            v85 = (__int64 **)v80[1];
            if ( *v85 == v80 && (__int64 *)v82[1] == v80 )
            {
              v82[1] = (__int64)v85;
              *v85 = v82;
            }
            else
            {
              _list_del_entry_valid_or_report(v80);
            }
            v86 = (__int64 **)*(v80 - 1);
            *v80 = 0xDEAD000000000100LL;
            v80[1] = 0xDEAD000000000122LL;
            v87 = v80 - 2;
            if ( *v86 == v80 - 2 && (v88 = (__int64 *)*v87, *(__int64 **)(*v87 + 8) == v87) )
            {
              v88[1] = (__int64)v86;
              *v86 = v88;
            }
            else
            {
              _list_del_entry_valid_or_report(v80 - 2);
            }
            v89 = *(__int64 **)v81;
            if ( *(_QWORD *)(*(_QWORD *)v81 + 8LL) != v81 || v87 == (__int64 *)v81 || v89 == v87 )
            {
              _list_add_valid_or_report(v87, v5 + 32);
            }
            else
            {
              v89[1] = (__int64)v87;
              *(v80 - 2) = (__int64)v89;
              *(v80 - 1) = v81;
              *(_QWORD *)v81 = v87;
            }
            v90 = *(v80 - 4);
            v80[42] = 0;
            v91 = *(_DWORD *)(v90 + 4720);
            if ( v91 <= 0xD )
            {
              v92 = 1 << v91;
              if ( (v92 & 0x3771) != 0 )
              {
                __break(0x800u);
              }
              else if ( (v92 & 0x88A) != 0 )
              {
                wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v90 + 1616) + 72LL), v80 + 14);
              }
              else
              {
                wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(v90 + 1616) + 72LL), v80 + 67, 0);
              }
            }
            ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ieee80211_chan_bw_change)(a1, v5, 0, 0);
          }
          v80 = v82;
        }
        while ( v82 != v48 );
        v80 = (__int64 *)*v48;
      }
      if ( v80 == v48 )
        goto LABEL_118;
      while ( 1 )
      {
        v95 = (__int64 *)*v80;
        v96 = *(_QWORD *)(v80[114] + 832);
        v97 = v80[42];
        if ( v96 )
          v98 = v96 == 152;
        else
          v98 = 1;
        if ( v98 )
          goto LABEL_194;
        if ( v97 )
          break;
        __break(0x800u);
        if ( v80[42] != v5 )
          goto LABEL_205;
LABEL_195:
        if ( *((_BYTE *)v80 + 409) == 1 )
        {
          v99 = v80 - 4;
          v100 = *(_QWORD *)(v80[114] + 832);
          if ( !v100 || v100 == 152 )
          {
            v93 = ieee80211_link_use_reserved_assign(v80 - 4);
            v94 = v93;
            if ( v93 )
              goto LABEL_199;
          }
          else
          {
            v101 = ieee80211_link_use_reserved_reassign(v80 - 4);
            v94 = v101;
            if ( v101 )
            {
LABEL_199:
              v102 = *v99;
              if ( *(_WORD *)(*v99 + 5800) )
                printk(&unk_B88A6, v102 + 1640, *((unsigned int *)v80 - 6), v94);
              else
                printk(&unk_BCCB0, v102 + 1640, (unsigned int)v94, v94);
              ieee80211_link_unreserve_chanctx(v80 - 4);
              cfg80211_stop_iface(*(_QWORD *)(a1 + 72), *v99 + 16, 3264);
            }
          }
        }
LABEL_186:
        v80 = v95;
        if ( v95 == v48 )
          goto LABEL_118;
      }
      if ( *(_DWORD *)(v96 - 88) == 1 && *(_DWORD *)(v97 + 64) == 2 )
      {
LABEL_205:
        __break(0x800u);
        goto LABEL_186;
      }
LABEL_194:
      if ( v97 != v5 )
        goto LABEL_205;
      goto LABEL_195;
    }
    while ( 1 )
    {
      v6 = *(v7 - 4);
      v49 = v7[114];
      v50 = *(_QWORD *)(v49 + 832);
      if ( v50 )
        v51 = v50 == 152;
      else
        v51 = 1;
      if ( v51 )
        goto LABEL_124;
      v52 = v7[42];
      if ( v52 )
        break;
      __break(0x800u);
LABEL_124:
      v7 = (__int64 *)*v7;
      if ( v7 == v48 )
        goto LABEL_155;
    }
    if ( *(_DWORD *)(v50 - 88) != 1 || *(_DWORD *)(v52 + 64) != 2 )
      goto LABEL_124;
    atomic_store(v5 + 152, (unsigned __int64 *)(v49 + 832));
    if ( *(_DWORD *)(v6 + 4720) == 3 )
    {
      v53 = *(v7 - 4);
      if ( *(_DWORD *)(v53 + 4720) == 3 )
      {
        v54 = *((unsigned int *)v7 - 6);
        v55 = *(_QWORD *)(v7[114] + 832);
        if ( !v55 )
          __break(0x800u);
        v56 = *(_QWORD **)(v53 + 2264);
        v57 = (_QWORD *)(v53 + 2264);
        if ( v56 != v57 )
        {
          if ( (unsigned int)v54 > 0xE )
            goto LABEL_225;
          do
          {
            v58 = v56[v54 + 427];
            if ( v58 )
              atomic_store(v55, (unsigned __int64 *)(v58 + 832));
            else
              __break(0x800u);
            v56 = (_QWORD *)*v56;
          }
          while ( v56 != v57 );
        }
      }
      else
      {
        __break(0x800u);
      }
    }
    ieee80211_check_fast_xmit_iface(v6);
    v60 = v7[45];
    v59 = v7[46];
    v62 = v7[43];
    v61 = v7[44];
    v63 = (_QWORD *)v7[114];
    *((_BYTE *)v7 + 424) = *((_BYTE *)v7 + 408);
    v64 = *((_DWORD *)v7 + 88);
    v65 = *(v7 - 4);
    v66 = *(_DWORD *)(v49 + 144);
    v67 = *((unsigned int *)v7 - 6);
    v63[19] = v60;
    v63[20] = v59;
    v63[17] = v62;
    v63[18] = v61;
    v68 = v7[50];
    v69 = v7[47];
    v70 = v7[48];
    v63[23] = v7[49];
    v63[24] = v68;
    v63[21] = v69;
    v63[22] = v70;
    if ( *(_DWORD *)(v65 + 4720) != 3 )
      goto LABEL_151;
    v71 = *(_QWORD **)(v65 + 2264);
    v72 = (_QWORD *)(v65 + 2264);
    if ( v71 == v72 )
      goto LABEL_151;
    if ( (unsigned int)v67 <= 0xE )
    {
      do
      {
        v73 = (_QWORD *)v71[v67 + 427];
        if ( v73 )
        {
          v74 = v7[46];
          v75 = v7[43];
          v76 = v7[44];
          v73[19] = v7[45];
          v73[20] = v74;
          v73[17] = v75;
          v73[18] = v76;
          v77 = v7[50];
          v78 = v7[47];
          v79 = v7[48];
          v73[23] = v7[49];
          v73[24] = v77;
          v73[21] = v78;
          v73[22] = v79;
        }
        else
        {
          __break(0x800u);
        }
        v71 = (_QWORD *)*v71;
      }
      while ( v71 != v72 );
LABEL_151:
      if ( v66 != v64 )
        ieee80211_link_info_change_notify(v6, v7 - 4, 0x200000);
      ieee80211_recalc_txpower(v6, 0);
      goto LABEL_124;
    }
LABEL_225:
    __break(0x5512u);
    v33 = 32LL * (unsigned int)v5;
    StatusReg = _ReadStatusReg(SP_EL0);
    v108 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_chsw_switch_vifs__alloc_tag;
    v34 = _kmalloc_noprof(v33, 3520);
    *(_QWORD *)(StatusReg + 80) = v108;
    if ( !v34 )
    {
LABEL_226:
      result = 4294967284LL;
      goto LABEL_57;
    }
LABEL_73:
    v35 = *v2;
    if ( (__int64 *)*v2 != v2 )
      break;
LABEL_94:
    v43 = drv_switch_vif_chanctx(a1, v34, (unsigned int)v5, 1);
    kfree(v34);
    result = v43;
    if ( v43 )
      goto LABEL_57;
  }
  v36 = 0;
  while ( *(_DWORD *)(v35 + 64) != 2 )
  {
LABEL_75:
    v35 = *(_QWORD *)v35;
    if ( (__int64 *)v35 == v2 )
      goto LABEL_94;
  }
  if ( !*(_QWORD *)(v35 + 72) )
  {
    __break(0x800u);
    kfree(v34);
    goto LABEL_56;
  }
  v37 = *(_QWORD **)(v35 + 48);
  if ( v37 == (_QWORD *)(v35 + 48) )
    goto LABEL_75;
  while ( 1 )
  {
    v38 = *(_QWORD *)(v37[114] + 832LL);
    if ( v38 )
      v39 = v38 == 152;
    else
      v39 = 1;
    if ( v39 )
      goto LABEL_81;
    v40 = v37[42];
    if ( v40 )
      break;
    __break(0x800u);
LABEL_81:
    v37 = (_QWORD *)*v37;
    if ( v37 == (_QWORD *)(v35 + 48) )
      goto LABEL_75;
  }
  if ( *(_DWORD *)(v38 - 88) != 1 || *(_DWORD *)(v40 + 64) != 2 )
    goto LABEL_81;
  v41 = 32LL * v36;
  if ( v33 > v41 )
  {
    v42 = (_QWORD *)(v34 + v41);
    *(_QWORD *)(v34 + 32LL * v36) = *(v37 - 4) + 4720LL;
    if ( v33 >= (v41 | 0x10) )
    {
      v42[2] = v38;
      if ( v33 >= (v41 | 0x18) )
      {
        v42[3] = v35 + 152;
        if ( v33 >= (v41 | 8) )
        {
          ++v36;
          v42[1] = v37[114];
          goto LABEL_81;
        }
      }
    }
  }
  __break(1u);
LABEL_224:
  __break(0x800u);
LABEL_106:
  v46 = *(_QWORD *)(v5 + 8);
  for ( result = (unsigned int)v33; (__int64 *)v46 != v2; v46 = *(_QWORD *)(v46 + 8) )
  {
    if ( *(_DWORD *)(v46 + 64) == 2 && *(_QWORD *)(*(_QWORD *)(v46 + 72) + 32LL) == *(_QWORD *)(v46 + 72) + 32LL )
    {
      ieee80211_del_chanctx(a1, v46, 0);
      v47 = ieee80211_add_chanctx(a1, *(_QWORD *)(v46 + 72));
      result = (unsigned int)v33;
      if ( v47 )
        __break(0x800u);
    }
  }
LABEL_57:
  v26 = *v2;
  if ( (__int64 *)*v2 != v2 )
  {
    v27 = result;
    do
    {
      if ( *(_DWORD *)(v26 + 64) == 2 )
      {
        v28 = *(_QWORD **)(v26 + 48);
        if ( v28 != (_QWORD *)(v26 + 48) )
        {
          do
          {
            v29 = (_QWORD *)*v28;
            ieee80211_link_unreserve_chanctx(v28 - 4);
            v30 = *(v28 - 4);
            v31 = *(_DWORD *)(v30 + 4720);
            if ( v31 <= 0xD )
            {
              v32 = 1 << v31;
              if ( (v32 & 0x3771) != 0 )
              {
                __break(0x800u);
              }
              else if ( (v32 & 0x88A) != 0 )
              {
                wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v30 + 1616) + 72LL), v28 + 14);
              }
              else
              {
                wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(v30 + 1616) + 72LL), v28 + 67, 0);
              }
            }
            v28 = v29;
          }
          while ( v29 != (_QWORD *)(v26 + 48) );
        }
      }
      v26 = *(_QWORD *)v26;
    }
    while ( (__int64 *)v26 != v2 );
    return v27;
  }
  return result;
}
