__int64 __fastcall ieee80211_assoc_success(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v6; // x24
  __int64 *v7; // x25
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x23
  __int64 v11; // x20
  unsigned int v12; // w26
  __int64 *v13; // x22
  int v14; // w8
  __int64 v15; // x27
  __int64 *v16; // x20
  __int64 v17; // x19
  __int64 v18; // x28
  __int64 v19; // x0
  __int64 dtim; // x0
  unsigned int v21; // w8
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x23
  int **v25; // x24
  __int64 v26; // x25
  __int64 v27; // x21
  int v28; // w8
  __int64 v29; // x26
  int v30; // w9
  __int64 v32; // x9
  int v33; // w8
  int v34; // w22
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x2
  __int64 v38; // x3
  __int64 v39; // x20
  __int16 v40; // w16
  _WORD *v41; // x8
  __int64 v42; // x9
  __int64 v43; // x8
  __int64 v44; // x9
  __int64 v45; // x8
  _WORD *v46; // x8
  unsigned __int16 *v47; // x10
  unsigned __int64 v48; // x9
  char v49; // w9
  __int64 v50; // x14
  char *v51; // x10
  __int64 v52; // x9
  __int64 v53; // x8
  __int64 v54; // x8
  unsigned int v55; // w8
  _QWORD *v56; // x19
  __int64 v57; // x0
  __int64 v58; // x1
  unsigned int *v59; // x8
  __int64 v60; // x8
  __int64 v61; // x25
  __int64 v62; // x2
  __int64 v63; // x21
  int *v64; // x8
  __int64 elem_match; // x0
  __int64 v66; // x3
  int *v67; // x0
  unsigned __int64 v68; // x19
  __int64 v69; // x24
  __int64 v70; // x8
  _QWORD *v71; // x0
  __int64 v72; // x2
  __int64 v73; // x3
  __int64 v74; // x8
  __int64 v75; // x8
  __int64 v76; // x8
  __int64 v77; // x8
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 *v80; // x2
  _BYTE *v81; // x8
  bool v82; // w8
  __int64 v83; // x8
  __int64 *v84; // x4
  int v85; // w8
  unsigned int v86; // w8
  __int64 v87; // x9
  __int64 v88; // x10
  _BYTE *v89; // x8
  int v90; // w9
  int v91; // w8
  _BYTE *v92; // x8
  int *v93; // x8
  char *v94; // x8
  int v95; // w8
  char v96; // w0
  _WORD *v97; // x8
  __int64 v98; // x8
  _QWORD *v99; // x19
  _QWORD *v100; // x19
  _QWORD *v101; // x19
  _QWORD *v102; // x19
  _QWORD *v103; // x19
  __int64 v104; // x19
  __int64 v105; // x11
  char v106; // w8
  __int64 v107; // x8
  __int64 v108; // x3
  __int64 v109; // x19
  void (__fastcall *v110)(_QWORD); // x8
  __int64 v111; // x23
  __int64 v112; // x19
  __int64 *v113; // x22
  __int64 v114; // x26
  __int64 *v115; // x20
  __int64 v116; // x19
  __int64 v117; // x24
  __int64 v118; // x21
  __int64 v119; // x25
  __int64 v120; // x0
  __int64 v121; // x1
  int v122; // w9
  __int64 lock; // x0
  __int64 v124; // x8
  __int64 v125; // x8
  __int64 v126; // x0
  int v127; // w8
  int v128; // w9
  __int64 v129; // x20
  __int64 *v130; // x23
  __int64 *v131; // x19
  __int64 v132; // x22
  __int64 v133; // x1
  __int64 v134; // x1
  __int64 v135; // x0
  __int64 v136; // x0
  __int64 result; // x0
  __int64 v138; // x19
  __int64 v139; // x8
  void *v140; // x0
  __int64 v141; // x9
  __int64 v142; // x1
  unsigned __int64 v148; // x9
  int **v150; // [xsp+10h] [xbp-150h]
  __int64 v151; // [xsp+18h] [xbp-148h]
  unsigned int v153; // [xsp+2Ch] [xbp-134h]
  __int64 v154; // [xsp+30h] [xbp-130h]
  __int64 *v155; // [xsp+38h] [xbp-128h]
  __int64 v156; // [xsp+40h] [xbp-120h]
  __int64 v157; // [xsp+48h] [xbp-118h]
  __int64 v159; // [xsp+58h] [xbp-108h]
  __int64 v160; // [xsp+60h] [xbp-100h]
  __int16 v161; // [xsp+6Ch] [xbp-F4h]
  __int64 v162; // [xsp+70h] [xbp-F0h]
  __int64 *v163; // [xsp+78h] [xbp-E8h]
  __int64 v164; // [xsp+80h] [xbp-E0h]
  __int64 v165; // [xsp+88h] [xbp-D8h]
  unsigned int v166; // [xsp+90h] [xbp-D0h]
  __int64 v167; // [xsp+90h] [xbp-D0h]
  _DWORD v168[2]; // [xsp+98h] [xbp-C8h] BYREF
  __int64 v169; // [xsp+A0h] [xbp-C0h]
  __int64 v170; // [xsp+A8h] [xbp-B8h]
  __int64 v171; // [xsp+B0h] [xbp-B0h]
  __int64 v172; // [xsp+B8h] [xbp-A8h]
  __int64 v173; // [xsp+C0h] [xbp-A0h]
  int **v174; // [xsp+C8h] [xbp-98h]
  int v175; // [xsp+D0h] [xbp-90h]
  char v176; // [xsp+D4h] [xbp-8Ch]
  __int16 v177; // [xsp+D5h] [xbp-8Bh]
  char v178; // [xsp+D7h] [xbp-89h]
  _QWORD v179[17]; // [xsp+D8h] [xbp-88h] BYREF

  v6 = a1;
  v179[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(__int64 **)(a1 + 2488);
  v151 = *(_QWORD *)(a1 + 1616);
  memset(v179, 0, 120);
  v8 = sta_info_get(a1, v7 + 120);
  if ( !v8 )
  {
    __break(0x800u);
    goto LABEL_287;
  }
  v10 = v8;
  *(_BYTE *)(v8 + 2716) = *((_BYTE *)v7 + 1042);
  if ( *(_WORD *)(v6 + 5800) )
  {
    v11 = 0;
    v12 = 0;
    v13 = v7;
    v166 = 0;
    do
    {
      if ( *v13 )
      {
        v14 = *((_BYTE *)v13 + 58) ? 1LL << v11 : 0;
        v12 |= v14;
        v166 |= 1LL << v11;
        if ( v11 != *((_DWORD *)v7 + 261) )
        {
          if ( (unsigned int)ieee80211_sta_allocate_link(v10, (unsigned int)v11) )
            goto LABEL_287;
        }
      }
      ++v11;
      v13 += 8;
    }
    while ( v11 != 15 );
    v8 = ieee80211_vif_set_links((unsigned __int16 *)v6, v166, v12);
  }
  else
  {
    v12 = 0;
    v166 = 0;
  }
  v15 = 0;
  v154 = v10;
  v155 = v7;
  v159 = v6;
  v160 = v6 + 4568;
  v156 = a5;
  v157 = v10 + 2568;
  _ReadStatusReg(SP_EL0);
  v153 = v12;
  while ( 1 )
  {
    v16 = &v7[8 * v15];
    v17 = *v16;
    if ( *v16 )
      break;
LABEL_16:
    if ( ++v15 == 15 )
    {
      ieee80211_vif_set_links((unsigned __int16 *)v6, v166, v12);
      rate_control_rate_init(v10);
      if ( (*(_BYTE *)(v6 + 2500) & 0x40) != 0 )
      {
        v104 = v151;
        v105 = a3;
        _X8 = (unsigned __int64 *)(v10 + 216);
        __asm { PRFM            #0x11, [X8] }
        do
          v148 = __ldxr(_X8);
        while ( __stxr(v148 | 0x80, _X8) );
        v106 = 1;
      }
      else
      {
        v104 = v151;
        v105 = a3;
        v106 = 0;
      }
      *(_BYTE *)(v10 + 2714) = v106;
      ieee80211_sta_set_max_amsdu_subframes(v10, *(_QWORD *)(v105 + 40), *(unsigned __int8 *)(a3 + 696));
      if ( *(_QWORD *)(a3 + 120) || (v107 = *(_QWORD *)(a3 + 400)) != 0 )
        LOBYTE(v107) = *(unsigned __int16 *)(v104 + 128) > 3u;
      *(_BYTE *)(v10 + 2698) = v107;
      if ( (unsigned int)sta_info_move_state(v10, 3)
        || (*(_BYTE *)(v6 + 2500) & 4) == 0 && (unsigned int)sta_info_move_state(v10, 4) )
      {
        printk(&unk_B8A14, v6 + 1640, v10 + 2688, v108);
        if ( (unsigned int)_sta_info_destroy(v10) )
LABEL_273:
          __break(0x800u);
        goto LABEL_287;
      }
      if ( *(_BYTE *)(v6 + 81) == 1 )
      {
        if ( v6 )
        {
          v109 = v6;
          if ( *(_DWORD *)(v6 + 4720) == 4 )
            v109 = *(_QWORD *)(v6 + 2032) - 2264LL;
        }
        else
        {
          v109 = 0;
        }
        if ( (*(_BYTE *)(*(_QWORD *)(v109 + 1616) + 1471LL) & 1) != 0
          || (*(_DWORD *)(v109 + 1624) & 0x20) != 0
          || (drv_sta_set_4addr___already_done_0 & 1) != 0 )
        {
          if ( (*(_BYTE *)(v109 + 1624) & 0x20) == 0 )
            goto LABEL_221;
        }
        else
        {
          v141 = *(_QWORD *)(v109 + 1608);
          drv_sta_set_4addr___already_done_0 = 1;
          if ( v141 )
            v142 = v141 + 296;
          else
            v142 = v109 + 1640;
          _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v142);
          __break(0x800u);
          if ( (*(_BYTE *)(v109 + 1624) & 0x20) == 0 )
            goto LABEL_221;
        }
        v110 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v151 + 464) + 864LL);
        if ( v110 )
        {
          if ( *((_DWORD *)v110 - 1) != 1437441928 )
            __break(0x8228u);
          v110(v151);
        }
      }
LABEL_221:
      v111 = 0;
      v112 = v151;
      v113 = v7;
      v167 = *(_QWORD *)(v6 + 1616);
      *(_BYTE *)(v6 + 2477) |= 8u;
      do
      {
        v114 = *v113;
        if ( *v113
          && !*((_WORD *)v113 + 28)
          && (!*(_WORD *)(v6 + 5800)
           || (((unsigned __int64)(*(unsigned __int16 *)(v6 + 5800) & (*(unsigned __int16 *)(v6 + 5804) ^ 0xFFFFu)) >> v111)
             & 1) != 0) )
        {
          v115 = *(__int64 **)(v160 + 8 * v111);
          if ( !v115 )
          {
            __break(0x800u);
            if ( !*(_BYTE *)(v6 + 2524) )
              goto LABEL_261;
            goto LABEL_260;
          }
          v116 = v115[118];
          v117 = *v115;
          *(_QWORD *)(v117 + 2456) = _usecs_to_jiffies((beacon_loss_count
                                                      * (unsigned int)*(unsigned __int16 *)(v116 + 50)) << 10);
          v118 = ieee80211_handle_bss_capability(
                   v115,
                   *(unsigned __int16 *)(v116 + 52),
                   *(_BYTE *)(v114 + 164),
                   *(unsigned __int8 *)(v114 + 165));
          v119 = v118 | 0x2000;
          v120 = ((__int64 (__fastcall *)(__int64 *))ieee80211_check_rate_mask)(v115);
          *(_QWORD *)(v115[118] + 8) = v114;
          v122 = *(_DWORD *)(v114 + 72);
          *((_WORD *)v115 + 270) = *(_WORD *)(v114 + 76);
          *((_DWORD *)v115 + 134) = v122;
          if ( (*(_BYTE *)(v117 + 5848) & 1) != 0 || (*(_BYTE *)(v117 + 5872) & 8) != 0 )
          {
            lock = _rcu_read_lock(v120, v121);
            v124 = *(_QWORD *)(v114 + 8);
            if ( v124 )
            {
              lock = cfg80211_get_p2p_attr(v124 + 29, *(unsigned int *)(v124 + 24), 12, v116 + 236, 54);
              if ( (int)lock >= 2 )
              {
                *((_WORD *)v115 + 280) = *(unsigned __int8 *)(v116 + 236);
                v119 = v118 | 0x82000;
              }
            }
            _rcu_read_unlock(lock);
          }
          if ( *((_BYTE *)v115 + 563) == 1 )
          {
            v125 = *(_QWORD *)(v114 + 152);
            v119 |= 0x100000uLL;
          }
          else
          {
            v125 = 0;
          }
          *(_QWORD *)(v116 + 80) = v125;
          if ( (*(_BYTE *)(v117 + 5872) & 2) != 0 && *(_DWORD *)(v116 + 116) )
            v119 |= 0x400uLL;
          v6 = v159;
          v112 = v151;
          v179[v111] |= v119;
        }
        ++v111;
        v113 += 8;
      }
      while ( v111 != 15 );
      v126 = *(_QWORD *)(v6 + 1616);
      *(_DWORD *)(v6 + 2500) &= ~2u;
      ieee80211_run_deferred_scan(v126);
      v127 = *(_DWORD *)(v6 + 4756);
      v128 = *(unsigned __int16 *)(v6 + 5800);
      *(_BYTE *)(v6 + 4728) = 1;
      if ( v127 )
        v129 = 4097;
      else
        v129 = 1;
      if ( v128 )
      {
        v130 = v155;
        v131 = v179;
        v132 = 571;
        while ( 1 )
        {
          if ( *v130
            && (((unsigned __int64)(unsigned __int16)(*(_WORD *)(v6 + 5800) & ~*(_WORD *)(v6 + 5804)) >> ((unsigned __int8)v132 - 59))
              & 1) != 0
            && !*((_WORD *)v130 + 28) )
          {
            if ( !*(_QWORD *)(v6 + 8 * v132) )
            {
              __break(0x800u);
              v112 = v151;
              if ( *(_BYTE *)(v6 + 2524) )
                goto LABEL_260;
              goto LABEL_261;
            }
            ieee80211_link_info_change_notify(v6, *(_QWORD *)(v6 + 8 * v132), *v131);
            ieee80211_recalc_smps(v6);
          }
          ++v132;
          ++v131;
          v130 += 8;
          if ( v132 == 586 )
          {
            ieee80211_vif_cfg_change_notify(v6, v129);
            v112 = v151;
            goto LABEL_257;
          }
        }
      }
      ieee80211_bss_info_change_notify(v6, v179[0] | v129);
LABEL_257:
      ieee80211_recalc_ps(v167, v133);
      if ( !*(_WORD *)(v6 + 5800) )
        ieee80211_recalc_smps(v6);
      ieee80211_recalc_ps_vif(v6, v134);
      netif_carrier_on(*(_QWORD *)(v6 + 1608));
      if ( *(_BYTE *)(v6 + 2524) )
LABEL_260:
        ieee80211_send_4addr_nullfunc(v112, v6);
LABEL_261:
      if ( (*(_BYTE *)(v6 + 5872) & 1) == 0 && (*(_QWORD *)(*(_QWORD *)(v6 + 1616) + 96LL) & 0x20000) == 0 )
      {
        v135 = round_jiffies_up(*(_QWORD *)(v6 + 2456) + jiffies);
        mod_timer(v6 + 2344, v135);
      }
      if ( (*(_BYTE *)(v6 + 2477) & 8) != 0 )
      {
        if ( *(_DWORD *)(v6 + 2472) )
          *(_DWORD *)(v6 + 2472) = 0;
        if ( (*(_QWORD *)(*(_QWORD *)(v6 + 1616) + 96LL) & 0x20000) == 0 )
        {
          v136 = round_jiffies_up(jiffies + 7500LL);
          mod_timer(v6 + 2304, v136);
        }
      }
      result = 1;
      goto LABEL_288;
    }
  }
  v18 = *(_QWORD *)(v160 + 8 * v15);
  if ( !v18 )
    goto LABEL_273;
  if ( *(_WORD *)(v6 + 5800) )
  {
    v52 = *(_QWORD *)v18;
    v53 = *(_QWORD *)(v18 + 944);
    if ( *(_WORD *)(*(_QWORD *)v18 + 5800LL) )
      v8 = printk(&unk_BAC7E, v52 + 1640, *(unsigned int *)(v18 + 8), v53 + 28);
    else
      v8 = printk(&unk_B9343, v52 + 1640, v53 + 28, v17 + 72);
  }
  v165 = *(_QWORD *)(v157 + 8 * v15);
  if ( !v165 )
    goto LABEL_273;
  if ( (*(_BYTE *)(v18 + 563) & 1) == 0 )
  {
    _rcu_read_lock(v8, v9);
    v19 = *(_QWORD *)(v17 + 16);
    if ( v19 )
      *(_BYTE *)(v18 + 563) = 1;
    else
      v19 = *(_QWORD *)(v17 + 8);
    dtim = ieee80211_get_dtim(v19, *(_QWORD *)(v18 + 944) + 68LL, v18 + 542);
    *(_WORD *)(*(_QWORD *)(v18 + 944) + 50LL) = *(_WORD *)(v17 + 68);
    _rcu_read_unlock(dtim);
  }
  v21 = *(unsigned __int8 *)(v18 + 542);
  if ( v21 <= 1 )
    LOBYTE(v21) = 1;
  *(_BYTE *)(*(_QWORD *)(v18 + 944) + 49LL) = v21;
  if ( v15 != *((_DWORD *)v7 + 261) )
  {
    *(_QWORD *)(v18 + 552) = v16[6];
    if ( (unsigned int)ieee80211_prep_channel(v6, v18, (unsigned int **)v17, 1, (unsigned int *)(v18 + 552)) )
    {
      v139 = *(_QWORD *)v18;
      if ( *(_WORD *)(*(_QWORD *)v18 + 5800LL) )
        printk(&unk_B7A85, v139 + 1640, *(unsigned int *)(v18 + 8), v23);
      else
        printk(&unk_BC1ED, v139 + 1640, v22, v23);
      goto LABEL_287;
    }
  }
  if ( (unsigned int)ieee80211_mgd_setup_link_sta(v18, v10, v165, *v16) )
    goto LABEL_287;
  v24 = *(_QWORD *)v18;
  v25 = (int **)*v16;
  v26 = *(_QWORD *)(*(_QWORD *)v18 + 2488LL);
  v27 = *(unsigned int *)(v18 + 8);
  v171 = 0;
  v172 = 0;
  v169 = a4;
  v170 = v156;
  v28 = *(_DWORD *)(v18 + 552);
  v29 = *(_QWORD *)(v18 + 944);
  v30 = *(_DWORD *)(v26 + 1044);
  v173 = 0;
  v174 = nullptr;
  v168[0] = v28;
  v168[1] = 0;
  _ZF = (_DWORD)v27 == v30;
  v176 = 1;
  v32 = *(_QWORD *)(v24 + 1616);
  if ( _ZF )
    v33 = -1;
  else
    v33 = v27;
  v177 = 0;
  v175 = v33;
  v178 = 0;
  v163 = v16;
  v164 = v32;
  v34 = **v25;
  v35 = ieee802_11_parse_elems_full(v168);
  if ( !v35 )
    goto LABEL_286;
  v39 = v35;
  if ( (_DWORD)v27 == *(_DWORD *)(v26 + 1044) )
  {
    if ( (unsigned int)v27 >= 0xF )
      goto LABEL_297;
    v40 = *(_WORD *)(a2 + 24);
    *(_WORD *)(v26 + (v27 << 6) + 56) = 0;
    v41 = *(_WORD **)(v35 + 448);
    if ( v41 )
    {
      if ( (*v41 & 0x20) == 0 )
        goto LABEL_271;
      v42 = 9;
      if ( (*v41 & 0x10) != 0 )
        v42 = 10;
      *(_BYTE *)(v18 + 880) = *((_BYTE *)v41 + v42);
    }
  }
  else
  {
    if ( (*(_BYTE *)(v35 + 760) & 0x10) != 0 )
      goto LABEL_271;
    v43 = *(_QWORD *)(v35 + 744);
    if ( !v43 || (*(_WORD *)v43 & 0x800) == 0 )
      goto LABEL_271;
    if ( (unsigned int)v27 > 0xE )
      goto LABEL_297;
    v44 = v43 + *(unsigned __int8 *)(v43 + 2);
    v45 = v26 + (v27 << 6);
    v40 = *(_WORD *)(v44 + 2);
    *(_WORD *)(v45 + 56) = *(_WORD *)(v44 + 4);
    v46 = (_WORD *)(v45 + 56);
    v47 = *(unsigned __int16 **)(v35 + 744);
    v48 = *v47;
    if ( (v48 & 0x800) != 0 )
    {
      v50 = 9;
      if ( (v48 & 0x20) == 0 )
        v50 = 3;
      v51 = (char *)v47 + v50 + ((v48 >> 5) & 2) + ((v48 >> 4) & 8) + ((v48 >> 7) & 2);
      if ( (~(_DWORD)v48 & 0x210) == 0 )
      {
        if ( (v48 & 0x400) != 0 )
          v51 += 2;
        else
          ++v51;
      }
      v49 = *v51;
    }
    else
    {
      v49 = 0;
    }
    *(_BYTE *)(v18 + 880) = v49;
    v38 = (unsigned __int16)*v46;
    if ( *v46 )
    {
      v98 = *(_QWORD *)v18;
      if ( *(_WORD *)(*(_QWORD *)v18 + 5800LL) )
        printk(&unk_BB164, v98 + 1640, *(unsigned int *)(v18 + 8), v38);
      else
        printk(&unk_B83E6, v98 + 1640, (unsigned int)v38, v38);
      v10 = v154;
      v7 = v155;
      v6 = v159;
      v12 = v153;
      v162 = 0;
      goto LABEL_179;
    }
  }
  if ( v34 == 4 || *(_QWORD *)(v35 + 56) )
  {
    v54 = *(_QWORD *)(v35 + 40);
    if ( v54 )
      LOBYTE(v54) = *(unsigned __int8 *)(v35 + 696) >= 5u && *(char *)(v54 + 4) < 0;
    *(_BYTE *)(v18 + 562) = v54;
    v161 = v40;
    if ( v34 != 3 )
    {
      if ( *(_BYTE *)(v26 + 1035) == 1 && !*(_QWORD *)(v35 + 120) )
        goto LABEL_90;
      v55 = *(_DWORD *)(v18 + 552);
      if ( v55 >= 2 )
      {
        if ( *(_QWORD *)(v35 + 128) && *(_QWORD *)(v35 + 136) )
        {
          if ( v34 != 1 || v55 == 2 )
          {
            v162 = 0;
            if ( !*(_QWORD *)(v35 + 120) )
              goto LABEL_277;
            goto LABEL_115;
          }
          if ( *(_QWORD *)(v35 + 144) && *(_QWORD *)(v35 + 152) )
          {
            v162 = 0;
            if ( !*(_QWORD *)(v35 + 120) )
              goto LABEL_277;
            goto LABEL_115;
          }
        }
LABEL_90:
        _rcu_read_lock(v35, v36);
        v67 = v25[1];
        if ( !v67 )
        {
          _rcu_read_unlock(0);
          goto LABEL_271;
        }
        v150 = v25;
        v68 = v67[6] + 32LL;
        v69 = kmemdup_noprof(v67, v68);
        _rcu_read_unlock(v69);
        if ( !v69 )
          goto LABEL_271;
        v169 = v69 + 29;
        if ( v68 < 0x18 || (v68 & 0xFFFFFFFFFFFFFFFCLL) == 0x18 )
          goto LABEL_298;
        v162 = v69;
        v70 = *(int *)(v69 + 24);
        v25 = v150;
        v174 = v150;
        v170 = v70;
        v71 = (_QWORD *)ieee802_11_parse_elems_full(v168);
        if ( !v71 )
          goto LABEL_284;
        if ( *(_BYTE *)(v26 + 1035) == 1 && !*(_QWORD *)(v39 + 120) && (v74 = v71[15]) != 0 )
        {
          v101 = v71;
          *(_QWORD *)(v39 + 120) = v74;
          printk(&unk_BBF8D, v24 + 1640, v72, v73);
          v71 = v101;
          if ( *(_QWORD *)(v39 + 128) )
            goto LABEL_102;
        }
        else if ( *(_QWORD *)(v39 + 128) )
        {
          goto LABEL_102;
        }
        v75 = v71[16];
        if ( v75 && *(_DWORD *)(v18 + 552) >= 2u )
        {
          v99 = v71;
          *(_QWORD *)(v39 + 128) = v75;
          printk(&unk_BC612, v24 + 1640, v72, v73);
          v71 = v99;
        }
LABEL_102:
        if ( !*(_QWORD *)(v39 + 136) && (v76 = v71[17]) != 0 && *(_DWORD *)(v18 + 552) >= 2u )
        {
          v100 = v71;
          *(_QWORD *)(v39 + 136) = v76;
          printk(&unk_B9AC0, v24 + 1640, v72, v73);
          v71 = v100;
          if ( v34 != 1 )
            goto LABEL_113;
        }
        else if ( v34 != 1 )
        {
          goto LABEL_113;
        }
        if ( !*(_QWORD *)(v39 + 144) && (v77 = v71[18]) != 0 && *(_DWORD *)(v18 + 552) >= 3u )
        {
          v102 = v71;
          *(_QWORD *)(v39 + 144) = v77;
          printk(&unk_B8696, v24 + 1640, v72, v73);
          v71 = v102;
          if ( !*(_QWORD *)(v39 + 152) )
            goto LABEL_110;
        }
        else if ( !*(_QWORD *)(v39 + 152) )
        {
LABEL_110:
          v78 = v71[19];
          if ( v78 && *(_DWORD *)(v18 + 552) >= 3u )
          {
            v103 = v71;
            *(_QWORD *)(v39 + 152) = v78;
            printk(&unk_BAFA9, v24 + 1640, v72, v73);
            v71 = v103;
          }
        }
LABEL_113:
        kfree(v71);
        v55 = *(_DWORD *)(v18 + 552);
        if ( v55 < 2 )
          goto LABEL_77;
        if ( !*(_QWORD *)(v39 + 120) )
          goto LABEL_277;
LABEL_115:
        if ( !*(_QWORD *)(v39 + 128) || !*(_QWORD *)(v39 + 136) )
        {
LABEL_277:
          v140 = &unk_BC646;
          goto LABEL_283;
        }
        if ( v34 == 1 && v55 >= 3 && (!*(_QWORD *)(v39 + 144) || !*(_QWORD *)(v39 + 152)) )
        {
          v140 = &unk_B9373;
LABEL_283:
          printk(v140, v24 + 1640, v37, v38);
LABEL_284:
          v138 = v162;
          goto LABEL_285;
        }
LABEL_77:
        v56 = &v179[v15];
        v57 = ieee80211_config_bw((__int64 *)v18, (_QWORD *)v39, (_DWORD)v27 == *(_DWORD *)(v26 + 1044), v56);
        if ( (_DWORD)v57 )
          goto LABEL_284;
        v59 = *(unsigned int **)(*(_QWORD *)(v18 + 944) + 136LL);
        if ( !v59 )
        {
          __break(0x800u);
          goto LABEL_284;
        }
        v60 = *v59;
        if ( (unsigned int)v60 > 5 )
        {
LABEL_297:
          __break(0x5512u);
LABEL_298:
          __break(1u);
        }
        v61 = v164;
        v62 = *(_QWORD *)(v39 + 128);
        v63 = *(_QWORD *)(*(_QWORD *)(v164 + 72) + 8 * v60 + 328);
        if ( v62 && *(_DWORD *)(v18 + 552) >= 2u )
          v57 = ieee80211_ht_cap_ie_to_sta_ht_cap(v24, v63, v62, v165);
        if ( *(_QWORD *)(v39 + 144) && *(_DWORD *)(v18 + 552) >= 3u )
        {
          _rcu_read_lock(v57, v58);
          v64 = v25[1];
          if ( v64 && (elem_match = cfg80211_find_elem_match(191, (char *)v64 + 29, (unsigned int)v64[6], 0, 0, 0)) != 0 )
          {
            if ( *(unsigned __int8 *)(elem_match + 1) <= 0xBu )
              v66 = 0;
            else
              v66 = elem_match + 2;
          }
          else
          {
            v66 = 0;
          }
          v79 = ieee80211_vht_cap_ie_to_sta_vht_cap(v24, v63, *(_QWORD *)(v39 + 144), v66, v165);
          _rcu_read_unlock(v79);
        }
        if ( *(_QWORD *)(v39 + 176) && *(_DWORD *)(v18 + 552) >= 4u && (v80 = *(__int64 **)(v39 + 168)) != nullptr )
        {
          ieee80211_he_cap_ie_to_sta_he_cap(v24, v63, v80, *(_BYTE *)(v39 + 705), *(_WORD **)(v39 + 200), v165);
          v61 = v164;
          *(_BYTE *)(v29 + 40) = *(_BYTE *)(*(_QWORD *)(v165 + 920) + 84LL);
          v81 = *(_BYTE **)(v39 + 88);
          v82 = v81
             && *(_BYTE *)(v39 + 701)
             && (*v81 & 0x10) != 0
             && (*(_BYTE *)(*(_QWORD *)(v164 + 72) + 117LL) & 8) != 0;
          *(_BYTE *)(v29 + 43) = v82;
          *v56 |= ieee80211_recalc_twt_req(v24, v63, v18, v165, v39);
          v83 = *(_QWORD *)(v39 + 440);
          if ( v83 )
          {
            v84 = *(__int64 **)(v39 + 432);
            if ( v84 && *(_DWORD *)(v18 + 552) >= 5u )
            {
              ieee80211_eht_cap_ie_to_sta_eht_cap(
                v24,
                v63,
                *(_QWORD *)(v39 + 168),
                *(unsigned __int8 *)(v39 + 705),
                v84,
                *(_BYTE *)(v39 + 713),
                v165);
              v61 = v164;
              LOBYTE(v83) = *(_BYTE *)(*(_QWORD *)(v165 + 920) + 141LL);
            }
            else
            {
              LOBYTE(v83) = 0;
            }
          }
        }
        else
        {
          LOBYTE(v83) = 0;
          *(_WORD *)(v29 + 40) = 0;
          *(_BYTE *)(v29 + 43) = 0;
        }
        *(_BYTE *)(v29 + 829) = v83;
        v85 = *(_DWORD *)(v24 + 4720);
        if ( *(_BYTE *)(v24 + 5848) == 1 )
        {
          if ( v85 == 2 )
          {
            v86 = 8;
            v87 = *(unsigned __int16 *)(v63 + 92);
            if ( *(_WORD *)(v63 + 92) )
              goto LABEL_144;
            goto LABEL_154;
          }
          if ( v85 == 3 )
          {
            v86 = 9;
            v87 = *(unsigned __int16 *)(v63 + 92);
            if ( !*(_WORD *)(v63 + 92) )
              goto LABEL_154;
LABEL_144:
            if ( v86 == 4 )
              LOBYTE(v86) = 3;
            v88 = 1LL << v86;
            v89 = (_BYTE *)(*(_QWORD *)(v63 + 96) + 2LL);
            while ( ((unsigned __int16)v88 & *((_WORD *)v89 - 1)) == 0 )
            {
              --v87;
              v89 += 128;
              if ( !v87 )
                goto LABEL_154;
            }
            if ( v89 != byte_2 && (*v89 & 1) != 0 )
              goto LABEL_155;
            goto LABEL_154;
          }
        }
        v86 = (unsigned __int8)*(_DWORD *)(v24 + 4720);
        if ( v86 >= 0xC )
        {
          __break(0x800u);
        }
        else
        {
          v87 = *(unsigned __int16 *)(v63 + 92);
          if ( *(_WORD *)(v63 + 92) )
            goto LABEL_144;
        }
LABEL_154:
        v89 = nullptr;
LABEL_155:
        if ( *(_BYTE *)(v29 + 40) == 1 )
        {
          LOBYTE(v90) = 0;
          if ( v89 && (*(_BYTE *)(*(_QWORD *)(v165 + 920) + 87LL) & 0x10) != 0 )
            v90 = ((unsigned __int8)v89[3] >> 4) & 1;
          *(_BYTE *)(v29 + 44) = v90;
          *(_BYTE *)(v29 + 345) = *(_BYTE *)(*(_QWORD *)(v39 + 176) + 3LL) & 0x3F;
          *(_BYTE *)(v29 + 347) = (**(_DWORD **)(v39 + 176) & 0x40000000) != 0;
          v91 = **(_DWORD **)(v39 + 176);
          *(_BYTE *)(v29 + 346) = v91 >= 0;
          if ( (v91 & 0x80000000) == 0 )
            *v56 |= 0x20000000uLL;
          *(_BYTE *)(v29 + 34) = **(_BYTE **)(v39 + 176) & 7;
          *(_WORD *)(v29 + 38) = (**(_WORD **)(v39 + 176) >> 4) & 0x3FF;
          *(_BYTE *)(v29 + 35) = *(_QWORD *)(v39 + 208) != 0;
          v92 = *(_BYTE **)(v39 + 208);
          if ( v92 )
            *(_BYTE *)(v29 + 36) = *v92;
          ieee80211_he_op_ie_to_bss_conf(v24 + 4720, *(_QWORD *)(v39 + 176));
          ieee80211_he_spr_ie_to_bss_conf(v24 + 4720, *(char **)(v39 + 184));
        }
        else
        {
          *(_BYTE *)(v29 + 44) = 0;
        }
        v10 = v154;
        if ( v25[5] )
        {
          *(_BYTE *)(v29 + 304) = 1;
          v93 = v25[5];
          *(_DWORD *)(v29 + 305) = v93[18];
          *(_WORD *)(v29 + 309) = *((_WORD *)v93 + 38);
          *(_BYTE *)(v29 + 312) = *((_BYTE *)v25 + 85);
          *(_BYTE *)(v29 + 311) = *((_BYTE *)v25 + 84);
        }
        v94 = *(char **)(v39 + 336);
        if ( v94 )
        {
          v95 = *v94;
          if ( (v95 & 0x80000000) == 0 )
            *(_BYTE *)(*(_QWORD *)(v165 + 920) + 230LL) = ((unsigned __int8)v95 >> 4) + 1;
        }
        v6 = v159;
        _ZF = *(_BYTE *)(v18 + 565) == 1;
        *(_QWORD *)(v18 + 872) = -1;
        if ( _ZF )
        {
          ieee80211_set_wmm_default(v18, 0, 0);
        }
        else
        {
          v96 = ieee80211_sta_wmm_params(
                  v61,
                  (unsigned int *)v18,
                  *(_BYTE **)(v39 + 120),
                  *(unsigned __int8 *)(v39 + 704),
                  *(_QWORD *)(v39 + 192));
          if ( (v96 & 1) == 0 )
          {
            ieee80211_set_wmm_default(v18, 0, 1);
            *(_BYTE *)(v18 + 565) = 1;
          }
        }
        v97 = *(_WORD **)(v39 + 360);
        if ( v97 )
        {
          *(_WORD *)(v29 + 292) = *v97;
          *(_BYTE *)(v29 + 294) = *(_BYTE *)(*(_QWORD *)(v39 + 360) + 2LL) & 1;
          *v56 |= 0x1000000uLL;
        }
        else
        {
          *(_WORD *)(v29 + 292) = 0;
          *(_BYTE *)(v29 + 294) = 0;
        }
        v7 = v155;
        *(_WORD *)(v29 + 52) = v161;
        v12 = v153;
LABEL_179:
        kfree(v39);
        v8 = kfree(v162);
        if ( *((_WORD *)v163 + 28) )
        {
          v166 &= ~(unsigned int)(1LL << v15);
          v8 = ieee80211_sta_remove_link(v10, (unsigned int)v15);
        }
        else if ( v15 != *((_DWORD *)v7 + 261) )
        {
          v8 = ieee80211_sta_activate_link(v10, (unsigned int)v15);
          if ( (_DWORD)v8 )
            goto LABEL_287;
        }
        goto LABEL_16;
      }
    }
    v162 = 0;
    goto LABEL_77;
  }
  printk(&unk_BC5E9, v24 + 1640, v37, v38);
LABEL_271:
  v138 = 0;
LABEL_285:
  kfree(v39);
  kfree(v138);
LABEL_286:
  v6 = v159;
LABEL_287:
  result = 0;
  *(_WORD *)(v6 + 4806) = 0;
  *(_DWORD *)(v6 + 4802) = 0;
LABEL_288:
  _ReadStatusReg(SP_EL0);
  return result;
}
