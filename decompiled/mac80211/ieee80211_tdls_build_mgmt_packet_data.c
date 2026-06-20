_WORD *__fastcall ieee80211_tdls_build_mgmt_packet_data(
        __int64 a1,
        _WORD *a2,
        int a3,
        unsigned __int8 a4,
        char a5,
        __int16 a6,
        char a7,
        char *a8,
        __int64 a9,
        char a10,
        __int64 a11)
{
  __int64 v17; // x20
  __int64 lock; // x0
  __int64 v19; // x22
  unsigned int v20; // w21
  _WORD *v21; // x19
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x20
  __int64 v25; // x0
  int v26; // w9
  __int64 v27; // x27
  int v28; // w10
  __int16 v29; // w8
  __int64 v30; // x23
  char v31; // w0
  __int64 v32; // x23
  void *v33; // x0
  void *v34; // x0
  char *v35; // x1
  __int64 v36; // x1
  __int64 v37; // x23
  __int64 v38; // x27
  __int64 v39; // x0
  unsigned int **v40; // x8
  __int64 v41; // x20
  unsigned __int64 v42; // x26
  _QWORD *v43; // x8
  __int64 v44; // x9
  __int64 v45; // x10
  __int64 v46; // x8
  __int64 v47; // x11
  __int64 v48; // x28
  void *v49; // x0
  __int64 v50; // x20
  __int64 v51; // x0
  __int64 v52; // x27
  __int16 v53; // w10
  int v54; // w8
  int v55; // w9
  __int64 v56; // x1
  __int16 v57; // w8
  void *v58; // x0
  __int64 v59; // x27
  __int64 v60; // x26
  unsigned int **v61; // x8
  __int64 v62; // x20
  __int64 v63; // x8
  __int64 v64; // x20
  _BYTE *v65; // x28
  char v66; // w26
  void *v67; // x0
  __int64 v68; // x1
  __int64 v69; // x26
  void *v70; // x0
  __int64 v71; // x20
  __int64 v72; // x0
  unsigned int **v73; // x8
  __int64 v74; // x28
  __int64 v75; // x8
  __int64 v76; // x20
  __int64 v77; // x0
  unsigned int **v78; // x8
  __int64 v79; // x28
  __int64 v80; // x8
  __int64 v81; // x20
  __int64 v82; // x0
  unsigned int **v83; // x8
  __int64 v84; // x28
  __int64 v85; // x8
  __int64 v86; // x28
  unsigned int v87; // w25
  unsigned __int8 v88; // w20
  unsigned __int64 v89; // x27
  __int64 v90; // x0
  unsigned int **v91; // x8
  __int64 v92; // x26
  __int64 v93; // x8
  char v94; // w28
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x27
  __int64 v98; // x28
  __int64 v99; // x0
  unsigned int v100; // w28
  __int64 v101; // x26
  void *v102; // x0
  size_t v103; // x2
  _QWORD *v104; // x8
  __int64 v105; // x20
  __int64 v106; // x9
  __int64 v107; // x10
  __int64 v108; // x8
  __int64 v109; // x11
  __int64 v110; // x8
  __int64 v111; // x0
  char v112; // w8
  __int64 v113; // x10
  __int64 v114; // x11
  __int64 v115; // x0
  __int64 v116; // x10
  __int64 v117; // x8
  __int64 v118; // x0
  __int64 v119; // x0
  unsigned int v120; // w25
  __int64 v121; // x24
  void *v122; // x0
  __int64 v123; // x12
  int v124; // w10
  int v125; // w9
  int v126; // w12
  __int64 v127; // x11
  char v128; // w8
  __int64 v129; // x12
  _BYTE *v130; // x8
  int v131; // w10
  __int64 v132; // x0
  char v133; // w8
  char v134; // w8
  char v135; // w8
  char v136; // w8
  __int64 v137; // x0
  unsigned int v138; // w28
  void *v139; // x0
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x9
  char v143; // w11
  __int64 v144; // x10
  __int64 v145; // x11
  _BOOL4 v146; // w8
  __int64 v147; // x0
  __int64 v148; // x8
  __int64 v149; // x0
  __int64 v150; // x0
  unsigned int v151; // w25
  __int64 v152; // x24
  void *v153; // x0
  __int64 v154; // x0
  unsigned int v155; // w24
  __int64 v156; // x22
  void *v157; // x0
  __int64 v159; // [xsp+8h] [xbp-68h]
  __int64 v160; // [xsp+8h] [xbp-68h]
  __int64 v161; // [xsp+10h] [xbp-60h]
  __int64 v162; // [xsp+10h] [xbp-60h]
  __int64 v163; // [xsp+18h] [xbp-58h]
  __int64 v164; // [xsp+20h] [xbp-50h]
  __int64 v165; // [xsp+20h] [xbp-50h]
  __int64 v168; // [xsp+38h] [xbp-38h] BYREF
  __int64 v169; // [xsp+40h] [xbp-30h]
  char v170[4]; // [xsp+4Ch] [xbp-24h] BYREF
  _QWORD v171[4]; // [xsp+50h] [xbp-20h] BYREF

  v171[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a1 + 1616);
  lock = _rcu_read_lock(a1, a2);
  if ( a3 >= 16 )
    goto LABEL_202;
  v19 = *(_QWORD *)(a1 + 8LL * (a3 & (unsigned int)~(a3 >> 31)) + 4568);
  if ( !v19 )
  {
    v21 = nullptr;
    __break(0x800u);
    goto LABEL_198;
  }
  v20 = a9;
  lock = _netdev_alloc_skb(*(_QWORD *)(a1 + 1608), (unsigned int)(a9 + *(_DWORD *)(v17 + 104) + 376), 2080);
  v21 = (_WORD *)lock;
  if ( !lock )
    goto LABEL_198;
  v22 = *(int *)(v17 + 104);
  v23 = *(_QWORD *)(lock + 224) + v22;
  LODWORD(v22) = *(_DWORD *)(lock + 208) + v22;
  *(_QWORD *)(lock + 224) = v23;
  *(_DWORD *)(lock + 208) = v22;
  if ( a4 > 0xEu )
    goto LABEL_32;
  if ( ((1 << a4) & 0x46F) == 0 )
  {
    if ( a4 != 14 )
      goto LABEL_32;
    v50 = *(_QWORD *)(a1 + 1608);
    v51 = skb_put(lock, 24);
    *(_QWORD *)(v51 + 8) = 0;
    *(_QWORD *)(v51 + 16) = 0;
    v52 = v51;
    *(_QWORD *)v51 = 0;
    v53 = a2[2];
    *(_DWORD *)(v51 + 4) = *(_DWORD *)a2;
    *(_WORD *)(v51 + 8) = v53;
    v54 = *(_DWORD *)(v50 + 8530);
    *(_WORD *)(v51 + 14) = *(_WORD *)(v50 + 8534);
    *(_DWORD *)(v51 + 10) = v54;
    v55 = *(_DWORD *)(v19 + 536);
    *(_WORD *)(v51 + 20) = *(_WORD *)(v19 + 540);
    *(_DWORD *)(v51 + 16) = v55;
    *(_WORD *)v51 = 208;
    lock = skb_put(v21, 5);
    *(_BYTE *)(v52 + 26) = a5;
    *(_WORD *)(v52 + 24) = 3588;
    if ( !a6 )
    {
      v71 = *(_QWORD *)(*(_QWORD *)v19 + 1616LL);
      v72 = _rcu_read_lock(lock, v56);
      v73 = *(unsigned int ***)(*(_QWORD *)(v19 + 944) + 832LL);
      if ( v73 )
      {
        v74 = **v73;
        lock = _rcu_read_unlock(v72);
        if ( (unsigned int)v74 >= 6 )
          goto LABEL_202;
        v75 = *(_QWORD *)(*(_QWORD *)(v71 + 72) + 8 * v74 + 328);
        if ( v75 && !*(_DWORD *)(v75 + 16) )
        {
          v57 = 1056;
          goto LABEL_31;
        }
      }
      else
      {
        lock = _rcu_read_unlock(v72);
      }
    }
    v57 = 0;
LABEL_31:
    *(_WORD *)(v52 + 27) = v57;
    goto LABEL_46;
  }
  v24 = *(_QWORD *)(a1 + 1608);
  v25 = skb_put(lock, 17);
  v26 = *(_DWORD *)a2;
  v27 = v25;
  *(_WORD *)(v25 + 4) = a2[2];
  *(_DWORD *)v25 = v26;
  v28 = *(_DWORD *)(v24 + 8530);
  v29 = *(_WORD *)(v24 + 8534);
  *(_WORD *)(v25 + 12) = 3465;
  *(_DWORD *)(v25 + 6) = v28;
  *(_WORD *)(v25 + 10) = v29;
  *(_BYTE *)(v25 + 14) = 2;
  v21[92] = v21[112] - v21[108] + 14;
  if ( a4 <= 2u )
  {
    if ( a4 )
    {
      if ( a4 != 1 )
      {
        if ( a4 != 2 )
          goto LABEL_32;
        *(_WORD *)(v25 + 15) = 524;
        lock = skb_put(v21, 3);
        *(_WORD *)(v27 + 17) = a6;
        *(_BYTE *)(v27 + 19) = a5;
        if ( a6 )
          goto LABEL_198;
        v37 = *(_QWORD *)v19;
        v38 = *(_QWORD *)(*(_QWORD *)v19 + 1616LL);
        v39 = _rcu_read_lock(lock, v36);
        v40 = *(unsigned int ***)(*(_QWORD *)(v19 + 944) + 832LL);
        if ( v40 )
        {
          v41 = **v40;
          lock = _rcu_read_unlock(v39);
          if ( (unsigned int)v41 < 6 )
          {
            v164 = *(_QWORD *)(*(_QWORD *)(v38 + 72) + 8 * v41 + 328);
            if ( !v164 )
              goto LABEL_203;
            v42 = sta_info_get(v37, a2);
            lock = sta_info_get(v37, (const void *)(v37 + 4802));
            if ( !v42 || !lock )
              goto LABEL_203;
            v43 = *(_QWORD **)(v19 + 944);
            v159 = lock;
            v45 = v43[19];
            v44 = v43[20];
            v47 = v43[17];
            v46 = v43[18];
            *(_QWORD *)(v42 + 1360) = v44;
            *(_QWORD *)(v42 + 1352) = v45;
            *(_QWORD *)(v42 + 1344) = v46;
            *(_QWORD *)(v42 + 1336) = v47;
            if ( a9 )
            {
              v48 = ieee80211_ie_split_ric(a8, a9, &ieee80211_tdls_add_setup_cfm_ies_before_qos, 1, 0, 0, 0);
              v49 = (void *)skb_put(v21, (unsigned int)v48);
              v161 = v48;
              memcpy(v49, a8, (unsigned int)v48);
            }
            else
            {
              v161 = 0;
            }
            if ( *(unsigned __int16 *)(v38 + 128) >= 4u && *(_BYTE *)(v42 + 2698) == 1 )
            {
              v132 = skb_put(v21, 26);
              *(_QWORD *)(v132 + 9) = 0;
              *(_QWORD *)(v132 + 17) = 0;
              *(_BYTE *)(v132 + 25) = 0;
              *(_BYTE *)(v132 + 8) = 0;
              *(_QWORD *)v132 = 0x10102F2500018DDLL;
              v133 = *(_BYTE *)(v37 + 4538) & 0xF;
              if ( *(_BYTE *)(v37 + 4539) )
                v133 = *(_BYTE *)(v37 + 4538) & 0xF | 0x10;
              *(_BYTE *)(v132 + 10) = v133;
              *(_BYTE *)(v132 + 11) = ~(__clz(*(unsigned __int16 *)(v37 + 4534) + 1) & 0xF
                                      | (16 * __clz(*(unsigned __int16 *)(v37 + 4536) + 1)));
              *(_WORD *)(v132 + 12) = *(_WORD *)(v37 + 4532);
              v134 = *(_BYTE *)(v37 + 4552) & 0xF;
              if ( *(_BYTE *)(v37 + 4553) )
                v134 = *(_BYTE *)(v37 + 4552) & 0xF | 0x10;
              *(_BYTE *)(v132 + 14) = v134 | 0x20;
              *(_BYTE *)(v132 + 15) = ~(__clz(*(unsigned __int16 *)(v37 + 4548) + 1) & 0xF
                                      | (16 * __clz(*(unsigned __int16 *)(v37 + 4550) + 1)));
              *(_WORD *)(v132 + 16) = *(_WORD *)(v37 + 4546);
              v135 = *(_BYTE *)(v37 + 4524) & 0xF;
              if ( *(_BYTE *)(v37 + 4525) )
                v135 = *(_BYTE *)(v37 + 4524) & 0xF | 0x10;
              *(_BYTE *)(v132 + 18) = v135 | 0x40;
              *(_BYTE *)(v132 + 19) = ~(__clz(*(unsigned __int16 *)(v37 + 4520) + 1) & 0xF
                                      | (16 * __clz(*(unsigned __int16 *)(v37 + 4522) + 1)));
              *(_WORD *)(v132 + 20) = *(_WORD *)(v37 + 4518);
              v136 = *(_BYTE *)(v37 + 4510) & 0xF;
              if ( *(_BYTE *)(v37 + 4511) )
                v136 = *(_BYTE *)(v37 + 4510) & 0xF | 0x10;
              *(_BYTE *)(v132 + 22) = v136 | 0x60;
              *(_BYTE *)(v132 + 23) = ~(__clz(*(unsigned __int16 *)(v37 + 4506) + 1) & 0xF
                                      | (16 * __clz(*(unsigned __int16 *)(v37 + 4508) + 1)));
              *(_WORD *)(v132 + 24) = *(_WORD *)(v37 + 4504);
            }
            if ( a9 )
            {
              v137 = ieee80211_ie_split_ric(a8, a9, &ieee80211_tdls_add_setup_cfm_ies_before_ht_op, 4, 0, 0, v161);
              v138 = v137 - v161;
              v97 = v137;
              v139 = (void *)skb_put(v21, (unsigned int)(v137 - v161));
              memcpy(v139, &a8[v161], v138);
            }
            else
            {
              v97 = v161;
            }
            if ( (*(_BYTE *)(v159 + 2926) & 1) == 0 && *(_BYTE *)(v42 + 2926) == 1 )
            {
              v140 = skb_put(v21, 24);
              ieee80211_ie_build_ht_oper(v140, v42 + 2924, *(_QWORD *)(v19 + 944) + 136LL, 23, 1);
            }
            ieee80211_tdls_add_link_ie(v19, v21, a2, a7 & 1);
            lock = v37;
            if ( *(_DWORD *)(v164 + 16) && *(_BYTE *)(v42 + 2948) == 1 )
            {
              if ( (*(_QWORD *)(v42 + 216) & 0x10000) != 0 )
                ieee80211_tdls_chandef_vht_upgrade(v37, v42);
              v141 = skb_put(v21, 7);
              lock = ieee80211_ie_build_vht_oper(v141, v42 + 2948, v42 + 1336);
            }
            goto LABEL_195;
          }
LABEL_202:
          __break(0x5512u);
        }
LABEL_52:
        lock = _rcu_read_unlock(v39);
        __break(0x800u);
        goto LABEL_198;
      }
      *(_WORD *)(v25 + 15) = 268;
      lock = skb_put(v21, 5);
      *(_WORD *)(v27 + 17) = a6;
      *(_BYTE *)(v27 + 19) = a5;
      if ( a6 )
        goto LABEL_45;
      v81 = *(_QWORD *)(*(_QWORD *)v19 + 1616LL);
      v82 = _rcu_read_lock(lock, v56);
      v83 = *(unsigned int ***)(*(_QWORD *)(v19 + 944) + 832LL);
      if ( v83 )
      {
        v84 = **v83;
        lock = _rcu_read_unlock(v82);
        if ( (unsigned int)v84 >= 6 )
          goto LABEL_202;
        v85 = *(_QWORD *)(*(_QWORD *)(v81 + 72) + 8 * v84 + 328);
        if ( v85 && !*(_DWORD *)(v85 + 16) )
        {
          *(_WORD *)(v27 + 20) = 1056;
LABEL_46:
          if ( a6 )
            goto LABEL_198;
          v59 = *(_QWORD *)v19;
          memset(v171, 0, 22);
          v60 = *(_QWORD *)(v59 + 1616);
          v168 = 0;
          v169 = 0;
          v39 = _rcu_read_lock(lock, v56);
          v61 = *(unsigned int ***)(*(_QWORD *)(v19 + 944) + 832LL);
          if ( !v61 )
            goto LABEL_52;
          v62 = **v61;
          lock = _rcu_read_unlock(v39);
          if ( (unsigned int)v62 >= 6 )
            goto LABEL_202;
          v160 = v60;
          v63 = *(_QWORD *)(v60 + 72) + 8 * v62;
          v64 = *(_QWORD *)(v63 + 328);
          if ( !v64 )
            goto LABEL_203;
          ieee80211_put_srates_elem(v21, *(_QWORD *)(v63 + 328), 0, 0, 0, 1);
          v163 = v64;
          ieee80211_put_srates_elem(v21, v64, 0, 0, 0, 50);
          v65 = (_BYTE *)skb_put(v21, 2);
          *v65 = 36;
          v66 = ieee80211_tdls_add_subband(v59, v21, 2412, 2472, 5);
          v67 = (void *)ieee80211_tdls_add_subband(v59, v21, 5000, 5825, 20);
          v65[1] = 2 * ((_BYTE)v67 + v66);
          if ( a9 )
          {
            v69 = ieee80211_ie_split_ric(a8, a9, &ieee80211_tdls_add_setup_start_ies_before_ext_cap, 5, 0, 0, 0);
            v70 = (void *)skb_put(v21, (unsigned int)v69);
            v162 = v69;
            v67 = memcpy(v70, a8, (unsigned int)v69);
          }
          else
          {
            v162 = 0;
          }
          v86 = *(_QWORD *)(*(_QWORD *)v19 + 1616LL);
          v87 = *(_DWORD *)(*(_QWORD *)(v86 + 72) + 108LL);
          v165 = v59;
          if ( (*(_QWORD *)(v86 + 96) & 0x20000000) != 0 )
            v88 = *(_BYTE *)(*(_QWORD *)v19 + 2740LL) ^ 1;
          else
            v88 = 0;
          v89 = *(_QWORD *)(v86 + 96);
          v90 = _rcu_read_lock(v67, v68);
          v91 = *(unsigned int ***)(*(_QWORD *)(v19 + 944) + 832LL);
          if ( v91 )
          {
            v92 = **v91;
            _rcu_read_unlock(v90);
            if ( (unsigned int)v92 >= 6 )
              goto LABEL_202;
            v93 = *(_QWORD *)(*(_QWORD *)(v86 + 72) + 8 * v92 + 328);
            if ( v93 )
            {
              if ( (*(_BYTE *)(v93 + 52) & v88 & 1) != 0 )
                v94 = 32;
              else
                v94 = 0;
LABEL_80:
              v95 = skb_put(v21, 10);
              *(_DWORD *)v95 = 2175;
              *(_WORD *)(v95 + 6) = 32;
              *(_BYTE *)(v95 + 4) = 0;
              *(_BYTE *)(v95 + 8) = 0;
              *(_BYTE *)(v95 + 5) = (v89 >> 35) & 0x10 | (v87 >> 22) & 0x40;
              *(_BYTE *)(v95 + 9) = v94;
              if ( a4 != 14 && *(unsigned __int16 *)(v160 + 128) >= 4u )
              {
                v96 = skb_put(v21, 9);
                ieee80211_add_wmm_info_ie(v96, 0);
              }
              v97 = v162;
              v98 = v163;
              if ( a9 )
              {
                v99 = ieee80211_ie_split_ric(a8, a9, &ieee80211_tdls_add_setup_start_ies_before_ht_cap, 10, 0, 0, v162);
                v100 = v99 - v162;
                v101 = v99;
                v102 = (void *)skb_put(v21, (unsigned int)(v99 - v162));
                v103 = v100;
                v98 = v163;
                memcpy(v102, &a8[v162], v103);
                v97 = v101;
              }
              if ( a4 == 1 )
              {
                lock = sta_info_get(v165, a2);
                if ( !lock )
                  goto LABEL_203;
                v104 = *(_QWORD **)(v19 + 944);
                v105 = lock;
                v107 = v104[19];
                v106 = v104[20];
                v109 = v104[17];
                v108 = v104[18];
                *(_QWORD *)(lock + 1360) = v106;
                *(_QWORD *)(lock + 1352) = v107;
                *(_QWORD *)(lock + 1344) = v108;
                *(_QWORD *)(lock + 1336) = v109;
              }
              else
              {
                v105 = 0;
              }
              v110 = *(_QWORD *)(v19 + 944);
              v170[0] = 0;
              if ( (ieee80211_chandef_to_operating_class(v110 + 136, v170) & 1) != 0 )
              {
                v111 = skb_put(v21, 4);
                *(_WORD *)v111 = 571;
                v112 = v170[0];
                *(_BYTE *)(v111 + 2) = v170[0];
                *(_BYTE *)(v111 + 3) = v112;
              }
              v113 = *(_QWORD *)(v98 + 36);
              v114 = *(_QWORD *)(v98 + 42);
              v171[0] = *(_QWORD *)(v98 + 28);
              v171[1] = v113;
              *(_QWORD *)((char *)&v171[1] + 6) = v114;
              if ( (a4 == 14 || !a4) && BYTE2(v171[0]) == 1 )
              {
                ieee80211_apply_htcap_overrides(v165, (__int64)v171);
                LOWORD(v171[0]) |= 0xCu;
              }
              else
              {
                if ( a4 != 1 || BYTE2(v171[0]) != 1 || *(_BYTE *)(v105 + 2926) != 1 )
                {
LABEL_100:
                  if ( BYTE2(v171[0]) == 1 && (v171[0] & 2) != 0 )
                  {
                    v118 = skb_put(v21, 3);
                    *(_WORD *)v118 = 328;
                    *(_BYTE *)(v118 + 2) = 1;
                  }
                  lock = ieee80211_tdls_add_link_ie(v19, v21, a2, a7 & 1);
                  if ( a9 )
                  {
                    v119 = ieee80211_ie_split_ric(
                             a8,
                             a9,
                             &ieee80211_tdls_add_setup_start_ies_before_vht_cap,
                             11,
                             0,
                             0,
                             v97);
                    v120 = v119 - v97;
                    v121 = v119;
                    v122 = (void *)skb_put(v21, (unsigned int)(v119 - v97));
                    lock = (__int64)memcpy(v122, &a8[v97], v120);
                    v97 = v121;
                  }
                  v123 = *(_QWORD *)(v98 + 60);
                  v124 = *(unsigned __int8 *)(v165 + 5848);
                  v125 = *(_DWORD *)(v165 + 4720);
                  v168 = *(_QWORD *)(v98 + 52);
                  v169 = v123;
                  if ( v124 == 1 )
                  {
                    if ( v125 == 2 )
                    {
                      v126 = 8;
                      v127 = *(unsigned __int16 *)(v98 + 92);
                      if ( *(_WORD *)(v98 + 92) )
                        goto LABEL_112;
                      goto LABEL_128;
                    }
                    if ( v125 == 3 )
                    {
                      v126 = 9;
                      v127 = *(unsigned __int16 *)(v98 + 92);
                      if ( !*(_WORD *)(v98 + 92) )
                        goto LABEL_128;
                      goto LABEL_112;
                    }
                  }
                  v126 = (unsigned __int8)v125;
                  if ( (unsigned __int8)v125 >= 0xCu )
                  {
                    __break(0x800u);
                    v125 = *(_DWORD *)(v165 + 4720);
                    v130 = nullptr;
                    if ( (*(_BYTE *)(v165 + 5848) & 1) == 0 )
                      goto LABEL_160;
                    goto LABEL_130;
                  }
                  v127 = *(unsigned __int16 *)(v98 + 92);
                  if ( *(_WORD *)(v98 + 92) )
                  {
LABEL_112:
                    if ( v126 == 4 )
                      v128 = 3;
                    else
                      v128 = v126;
                    v129 = 1LL << v128;
                    v130 = (_BYTE *)(*(_QWORD *)(v98 + 96) + 2LL);
                    while ( ((unsigned __int16)v129 & *((_WORD *)v130 - 1)) == 0 )
                    {
                      --v127;
                      v130 += 128;
                      if ( !v127 )
                        goto LABEL_121;
                    }
                    if ( v130 == byte_2 )
                      goto LABEL_128;
                    if ( (*v130 & 1) != 0 )
                      goto LABEL_129;
LABEL_121:
                    v130 = nullptr;
                    if ( (v124 & 1) == 0 )
                      goto LABEL_160;
LABEL_130:
                    if ( v125 == 2 )
                    {
                      v131 = 8;
                      goto LABEL_161;
                    }
                    if ( v125 == 3 )
                    {
                      v131 = 9;
                      goto LABEL_161;
                    }
LABEL_160:
                    v131 = (unsigned __int8)v125;
                    if ( (unsigned __int8)v125 >= 0xCu )
                    {
                      LODWORD(v142) = 0;
                      __break(0x800u);
LABEL_172:
                      v146 = v130 != nullptr;
                      if ( a4 <= 1u && (((unsigned int)v142 | v146 | (unsigned __int8)v168) & 1) != 0 )
                      {
                        lock = skb_put(v21, 4);
                        *(_WORD *)lock = 709;
                        *(_WORD *)(lock + 2) = *(_WORD *)(v165 + 4732);
                      }
                      if ( (a4 == 14 || !a4) && (unsigned __int8)v168 == 1 )
                      {
                        ieee80211_apply_vhtcap_overrides(v165, &v168);
                        v147 = skb_put(v21, 14);
                        lock = ieee80211_ie_build_vht_cap(v147, &v168, HIDWORD(v168));
                      }
                      else if ( a4 == 1 && (unsigned __int8)v168 == 1 && *(_BYTE *)(v105 + 2948) == 1 )
                      {
                        v148 = *(_QWORD *)(v105 + 2956);
                        v168 = *(_QWORD *)(v105 + 2948);
                        v169 = v148;
                        v149 = skb_put(v21, 14);
                        lock = ieee80211_ie_build_vht_cap(v149, &v168, HIDWORD(v168));
                        if ( (*(_QWORD *)(v105 + 216) & 0x10000) != 0 )
                          lock = ieee80211_tdls_chandef_vht_upgrade(v165, v105);
                      }
                      if ( a9 )
                      {
                        v150 = ieee80211_ie_split_ric(
                                 a8,
                                 a9,
                                 &ieee80211_tdls_add_setup_start_ies_before_he_cap,
                                 3,
                                 0,
                                 0,
                                 v97);
                        v151 = v150 - v97;
                        v152 = v150;
                        v153 = (void *)skb_put(v21, (unsigned int)(v150 - v97));
                        lock = (__int64)memcpy(v153, &a8[v97], v151);
                        v97 = v152;
                      }
                      if ( a4 <= 0xEu && ((1 << a4) & 0x4003) != 0 )
                      {
                        lock = ieee80211_put_he_cap(v21, v165, v98, 0);
                        if ( *(_DWORD *)(v98 + 16) == 3 )
                          lock = ieee80211_put_he_6ghz_cap(v21, v165, *(unsigned int *)(v19 + 444));
                      }
                      if ( a9 )
                      {
                        v154 = ieee80211_ie_split_ric(
                                 a8,
                                 a9,
                                 &ieee80211_tdls_add_setup_start_ies_before_he_cap_22,
                                 3,
                                 0,
                                 0,
                                 v97);
                        v155 = v154 - v97;
                        v156 = v154;
                        v157 = (void *)skb_put(v21, (unsigned int)(v154 - v97));
                        lock = (__int64)memcpy(v157, &a8[v97], v155);
                        v97 = v156;
                      }
                      if ( a4 <= 0xEu && ((1 << a4) & 0x4003) != 0 )
                        lock = ieee80211_put_eht_cap(v21, v165, v98, 0);
LABEL_195:
                      if ( a9 )
                      {
                        v20 = a9 - v97;
                        v34 = (void *)skb_put(v21, (unsigned int)(a9 - v97));
                        v35 = &a8[v97];
                        goto LABEL_197;
                      }
                      goto LABEL_198;
                    }
LABEL_161:
                    v142 = *(unsigned __int16 *)(v98 + 92);
                    if ( *(_WORD *)(v98 + 92) )
                    {
                      if ( v131 == 4 )
                        v143 = 3;
                      else
                        v143 = v131;
                      v144 = *(_QWORD *)(v98 + 96);
                      v145 = 1LL << v143;
                      while ( ((unsigned __int16)v145 & *(_WORD *)v144) == 0 )
                      {
                        --v142;
                        v144 += 128;
                        if ( !v142 )
                          goto LABEL_172;
                      }
                      if ( v144 )
                        LODWORD(v142) = (v144 != -59) & *(_BYTE *)(v144 + 59);
                      else
                        LODWORD(v142) = 0;
                    }
                    goto LABEL_172;
                  }
LABEL_128:
                  v130 = nullptr;
LABEL_129:
                  if ( !v124 )
                    goto LABEL_160;
                  goto LABEL_130;
                }
                v116 = *(_QWORD *)(v105 + 2932);
                v117 = *(_QWORD *)(v105 + 2938);
                v171[0] = *(_QWORD *)(v105 + 2924);
                v171[1] = v116;
                *(_QWORD *)((char *)&v171[1] + 6) = v117;
              }
              v115 = skb_put(v21, 28);
              ieee80211_ie_build_ht_cap(v115, v171, LOWORD(v171[0]));
              goto LABEL_100;
            }
          }
          else
          {
            _rcu_read_unlock(v90);
          }
          v94 = 0;
          goto LABEL_80;
        }
      }
      else
      {
        lock = _rcu_read_unlock(v82);
      }
LABEL_45:
      *(_WORD *)(v27 + 20) = 0;
      goto LABEL_46;
    }
    *(_WORD *)(v25 + 15) = 12;
    lock = skb_put(v21, 3);
    *(_BYTE *)(v27 + 17) = a5;
    if ( !a6 )
    {
      v76 = *(_QWORD *)(*(_QWORD *)v19 + 1616LL);
      v77 = _rcu_read_lock(lock, v56);
      v78 = *(unsigned int ***)(*(_QWORD *)(v19 + 944) + 832LL);
      if ( v78 )
      {
        v79 = **v78;
        lock = _rcu_read_unlock(v77);
        if ( (unsigned int)v79 >= 6 )
          goto LABEL_202;
        v80 = *(_QWORD *)(*(_QWORD *)(v76 + 72) + 8 * v79 + 328);
        if ( v80 && !*(_DWORD *)(v80 + 16) )
        {
          *(_WORD *)(v27 + 18) = 1056;
          goto LABEL_46;
        }
      }
      else
      {
        lock = _rcu_read_unlock(v77);
      }
    }
    *(_WORD *)(v27 + 18) = 0;
    goto LABEL_46;
  }
  if ( a4 > 5u )
  {
    if ( a4 == 6 )
    {
      *(_WORD *)(v25 + 15) = 1548;
      lock = skb_put(v21, 2);
      *(_WORD *)(v27 + 17) = a6;
      if ( !a6 )
        lock = ieee80211_tdls_add_link_ie(v19, v21, a2, a7 & 1);
      if ( a9 )
      {
        v34 = (void *)skb_put(v21, (unsigned int)a9);
        v35 = a8;
        goto LABEL_197;
      }
      goto LABEL_198;
    }
    if ( a4 == 10 )
    {
      *(_WORD *)(v25 + 15) = 2572;
      lock = skb_put(v21, 1);
      *(_BYTE *)(v27 + 17) = a5;
      if ( !a9 )
        goto LABEL_37;
      goto LABEL_36;
    }
LABEL_32:
    lock = consume_skb(v21);
    v21 = nullptr;
    goto LABEL_198;
  }
  if ( a4 != 3 )
  {
    if ( a4 == 5 )
    {
      *(_WORD *)(v25 + 15) = 1292;
      lock = skb_put(v21, 2);
      if ( a11 )
      {
        v30 = *((_QWORD *)v21 + 28);
        v31 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(*(_QWORD *)a11 + 4LL)));
        *(_BYTE *)(v30 + 18) = a10;
        *(_BYTE *)(v30 + 17) = v31;
        if ( a9 )
        {
          v32 = ieee80211_ie_split_ric(a8, a9, &ieee80211_tdls_add_chan_switch_req_ies_before_lnkie, 1, 0, 0, 0);
          v33 = (void *)skb_put(v21, (unsigned int)v32);
          memcpy(v33, a8, (unsigned int)v32);
          ieee80211_tdls_add_link_ie(v19, v21, a2, a7 & 1);
          v20 = a9 - v32;
          v34 = (void *)skb_put(v21, (unsigned int)(a9 - v32));
          v35 = &a8[v32];
LABEL_197:
          lock = (__int64)memcpy(v34, v35, v20);
          goto LABEL_198;
        }
        goto LABEL_39;
      }
LABEL_203:
      __break(0x800u);
      goto LABEL_198;
    }
    goto LABEL_32;
  }
  *(_WORD *)(v25 + 15) = 780;
  lock = skb_put(v21, 2);
  *(_WORD *)(v27 + 17) = a6;
  if ( !a9 )
    goto LABEL_37;
LABEL_36:
  v58 = (void *)skb_put(v21, (unsigned int)a9);
  lock = (__int64)memcpy(v58, a8, (unsigned int)a9);
LABEL_37:
  if ( a4 == 3 || !a6 )
LABEL_39:
    lock = ieee80211_tdls_add_link_ie(v19, v21, a2, a7 & 1);
LABEL_198:
  _rcu_read_unlock(lock);
  _ReadStatusReg(SP_EL0);
  return v21;
}
