__int64 __fastcall nl80211_pmsr_start(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x22
  _WORD *v4; // x0
  __int64 v5; // x27
  _WORD *v6; // x0
  _WORD *v7; // x24
  _WORD *v8; // x25
  int v9; // w8
  unsigned __int16 *v10; // x20
  unsigned __int16 *v11; // x21
  unsigned int v12; // w9
  __int64 v13; // x9
  unsigned int v14; // w28
  __int64 v15; // x8
  __int64 v16; // x8
  unsigned __int64 v17; // x23
  unsigned __int64 v18; // x1
  __int64 v19; // x11
  __int64 v20; // x0
  __int64 v21; // x8
  _QWORD *v22; // x21
  __int64 v23; // x8
  __int64 v24; // x8
  _QWORD *v25; // x20
  __int16 v26; // w9
  int v27; // w8
  int v28; // w26
  __int64 v29; // x8
  unsigned int v30; // w8
  _WORD *v31; // x28
  __int64 v32; // x21
  void *v33; // x0
  int v34; // w8
  unsigned int v35; // w0
  unsigned __int16 v36; // w8
  unsigned int v37; // w9
  unsigned int v38; // t1
  unsigned __int64 v39; // x10
  unsigned __int64 v40; // x11
  bool v41; // cf
  unsigned __int64 v42; // x15
  char v43; // w9
  bool v45; // w9
  unsigned __int64 v46; // x9
  unsigned __int64 v47; // x11
  char v49; // w9
  bool v50; // cf
  unsigned __int64 v51; // x9
  char v52; // w11
  unsigned __int64 v53; // x9
  bool v55; // w9
  bool v56; // w9
  unsigned __int64 v57; // x9
  unsigned __int64 v58; // x10
  bool v59; // cf
  unsigned __int64 v60; // x9
  bool v61; // w12
  unsigned __int64 v62; // x10
  bool v63; // cf
  bool v64; // w14
  unsigned __int64 v65; // x9
  bool v66; // cf
  bool v67; // w9
  bool v68; // w9
  bool v69; // w9
  bool v70; // w9
  bool v71; // w9
  __int64 v72; // x9
  int v73; // w21
  bool v74; // w8
  __int64 v75; // x28
  __int64 v76; // x10
  int v77; // w9
  const char *v78; // x28
  char v79; // w8
  __int64 v80; // x9
  __int64 v81; // x9
  char v82; // w8
  const char *v83; // x28
  __int64 v84; // x8
  __int64 v85; // x9
  unsigned int v86; // w9
  __int64 v87; // x9
  __int64 v88; // x9
  __int64 v89; // x9
  __int64 v90; // x9
  __int64 v91; // x8
  __int64 v92; // x9
  char v93; // w8
  __int64 v94; // x10
  char v95; // w8
  int v96; // w9
  char v97; // w8
  int v98; // w10
  __int64 v99; // x8
  unsigned int v100; // w8
  __int64 v101; // x8
  __int64 v102; // x3
  __int64 (__fastcall *v103)(_QWORD); // x8
  unsigned __int64 v104; // x21
  __int64 v105; // x8
  __int64 v106; // x9
  _QWORD *v107; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v109; // x26
  __int64 v110; // x9
  __int64 v111; // x9
  bool v113; // [xsp+Ch] [xbp-154h]
  unsigned __int64 v114; // [xsp+10h] [xbp-150h]
  unsigned __int64 v115; // [xsp+18h] [xbp-148h]
  bool v116; // [xsp+24h] [xbp-13Ch]
  unsigned __int64 v117; // [xsp+28h] [xbp-138h]
  unsigned __int64 v118; // [xsp+30h] [xbp-130h]
  unsigned __int64 v119; // [xsp+38h] [xbp-128h]
  bool v120; // [xsp+44h] [xbp-11Ch]
  bool v121; // [xsp+48h] [xbp-118h]
  bool v122; // [xsp+4Ch] [xbp-114h]
  char v123; // [xsp+50h] [xbp-110h]
  char v124; // [xsp+54h] [xbp-10Ch]
  bool v125; // [xsp+58h] [xbp-108h]
  bool v126; // [xsp+5Ch] [xbp-104h]
  unsigned __int64 v127; // [xsp+60h] [xbp-100h]
  unsigned __int64 v128; // [xsp+68h] [xbp-F8h]
  bool v129; // [xsp+78h] [xbp-E8h]
  bool v130; // [xsp+7Ch] [xbp-E4h]
  unsigned __int64 v131; // [xsp+80h] [xbp-E0h]
  int v132; // [xsp+88h] [xbp-D8h]
  bool v133; // [xsp+8Ch] [xbp-D4h]
  bool v134; // [xsp+90h] [xbp-D0h]
  char v135; // [xsp+94h] [xbp-CCh]
  __int64 v136; // [xsp+98h] [xbp-C8h]
  __int64 v137; // [xsp+A0h] [xbp-C0h] BYREF
  unsigned __int16 *v138; // [xsp+A8h] [xbp-B8h]
  _WORD *v139; // [xsp+B0h] [xbp-B0h]
  __int64 v140; // [xsp+B8h] [xbp-A8h] BYREF
  __int64 v141; // [xsp+C0h] [xbp-A0h]
  _WORD *v142; // [xsp+C8h] [xbp-98h]
  _WORD *v143; // [xsp+D0h] [xbp-90h]
  __int64 v144; // [xsp+D8h] [xbp-88h]
  __int64 v145; // [xsp+E0h] [xbp-80h] BYREF
  __int64 v146; // [xsp+E8h] [xbp-78h]
  __int64 v147; // [xsp+F0h] [xbp-70h]
  __int64 v148; // [xsp+F8h] [xbp-68h]
  __int64 v149; // [xsp+100h] [xbp-60h]
  __int64 v150; // [xsp+108h] [xbp-58h]
  __int64 v151; // [xsp+110h] [xbp-50h]
  __int64 v152; // [xsp+118h] [xbp-48h]
  __int64 v153; // [xsp+120h] [xbp-40h]
  __int64 v154; // [xsp+128h] [xbp-38h]
  __int64 v155; // [xsp+130h] [xbp-30h]
  __int64 v156; // [xsp+138h] [xbp-28h]
  __int64 v157; // [xsp+140h] [xbp-20h]
  __int64 v158; // [xsp+148h] [xbp-18h]
  __int64 v159; // [xsp+150h] [xbp-10h]

  v159 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a2 + 48);
  if ( !v2[303] )
  {
    v14 = -95;
    goto LABEL_280;
  }
  v4 = *(_WORD **)(*(_QWORD *)(a2 + 32) + 2184LL);
  if ( !v4 )
    goto LABEL_32;
  v5 = *(_QWORD *)(a2 + 56);
  v6 = (_WORD *)nla_find(v4 + 2, (unsigned __int16)(*v4 - 4), 5);
  if ( !v6 )
    goto LABEL_32;
  v7 = v6;
  v8 = v6 + 2;
  v9 = (unsigned __int16)(*v6 - 4);
  if ( (unsigned int)v9 >= 4 )
  {
    LODWORD(v10) = 0;
    v11 = v6 + 2;
    while ( 1 )
    {
      v12 = *v11;
      if ( v12 < 4 || v9 < v12 )
        goto LABEL_13;
      LODWORD(v10) = (_DWORD)v10 + 1;
      if ( (unsigned int)v10 > *(_DWORD *)v2[303] )
        break;
      v13 = (v12 + 3) & 0x1FFFC;
      v9 -= v13;
      v11 = (unsigned __int16 *)((char *)v11 + v13);
      if ( v9 <= 3 )
        goto LABEL_13;
    }
    v25 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("Too many peers used");
    if ( v25 )
    {
      *v25 = "Too many peers used";
      v25[1] = v11;
      v14 = -22;
      v25[2] = 0;
      goto LABEL_280;
    }
LABEL_32:
    v14 = -22;
    goto LABEL_280;
  }
  LODWORD(v10) = 0;
LABEL_13:
  v15 = 56LL * (int)v10;
  v41 = __CFADD__(v15, 56);
  v16 = v15 + 56;
  if ( v41 )
    v16 = -1;
  if ( is_mul_ok((int)v10, 0x38u) )
    v17 = v16;
  else
    v17 = -1;
  v19 = _kmalloc_noprof(v17, 3520);
  if ( !v19 )
  {
LABEL_279:
    v14 = -12;
    goto LABEL_280;
  }
  while ( 1 )
  {
    if ( (v17 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
      goto LABEL_271;
    v20 = *(_QWORD *)(a2 + 32);
    *(_DWORD *)(v19 + 16) = (_DWORD)v10;
    v21 = *(_QWORD *)(v20 + 2176);
    if ( v21 )
    {
      if ( (v17 & 0xFFFFFFFFFFFFFFFCLL) == 0x18 )
        goto LABEL_271;
      v20 = *(_QWORD *)(a2 + 32);
      *(_DWORD *)(v19 + 24) = *(_DWORD *)(v21 + 4);
    }
    v136 = v19;
    if ( *(_QWORD *)(v20 + 48) )
    {
      if ( (*(_BYTE *)(v2[303] + 4LL) & 2) == 0 )
      {
        v22 = *(_QWORD **)(a2 + 64);
        do_trace_netlink_extack("device cannot randomize MAC address");
        if ( v22 )
        {
          *v22 = "device cannot randomize MAC address";
          v22[1] = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 48LL);
          v22[2] = 0;
        }
        goto LABEL_269;
      }
      v127 = v5;
      v128 = v17 & 0xFFFFFFFFFFFFFFFCLL;
      v14 = nl80211_parse_random_mac(v20, (int *)(v19 + 28), v19 + 34);
      if ( v14 )
        goto LABEL_270;
    }
    else
    {
      v23 = *(_QWORD *)(v5 + 32);
      v127 = v5;
      v128 = v17 & 0xFFFFFFFFFFFFFFFCLL;
      if ( v23 )
        v24 = *(_QWORD *)(v23 + 1008);
      else
        v24 = v5 + 70;
      v26 = *(_WORD *)(v24 + 4);
      v27 = *(_DWORD *)v24;
      *(_DWORD *)(v19 + 34) = -1;
      *(_WORD *)(v19 + 32) = v26;
      *(_DWORD *)(v19 + 28) = v27;
      *(_WORD *)(v19 + 38) = -1;
    }
    LODWORD(v10) = (unsigned __int16)(*v7 - 4);
    if ( (unsigned int)v10 >= 4 )
    {
      v28 = 0;
      do
      {
        v30 = (unsigned __int16)*v8;
        if ( v30 < 4 || (unsigned int)v10 < v30 )
          break;
        v143 = nullptr;
        v144 = 0;
        v141 = 0;
        v142 = nullptr;
        v140 = 0;
        v138 = nullptr;
        v139 = nullptr;
        v137 = 0;
        _nla_parse(&v140, 4, v8 + 2, (unsigned __int16)(*v8 - 4), 0, 0, 0);
        if ( !v141 || (v31 = v142) == nullptr || !v143 )
        {
          v107 = *(_QWORD **)(a2 + 64);
          do_trace_netlink_extack("insufficient peer data");
          if ( v107 )
          {
            *v107 = "insufficient peer data";
            goto LABEL_268;
          }
          goto LABEL_269;
        }
        v32 = 56LL * v28;
        if ( v17 >= v32 + 56 )
          v18 = v17 - (v32 + 56);
        else
          v18 = 0;
        if ( v18 <= 5 )
          goto LABEL_272;
        v33 = *(void **)(a2 + 32);
        v5 = v136 + 56 + 56LL * v28;
        v34 = *(_DWORD *)(v141 + 4);
        *(_WORD *)(v5 + 4) = *(_WORD *)(v141 + 8);
        *(_DWORD *)v5 = v34;
        memset(v33, 0, 0xA80u);
        v35 = _nla_parse(*(_QWORD *)(a2 + 32), 335, v31 + 2, (unsigned __int16)(*v31 - 4), 0, 0, *(_QWORD *)(a2 + 64));
        if ( v35 || (v35 = nl80211_parse_chandef((__int64)v2, a2, v5 + 8)) != 0 )
        {
          v14 = v35;
          goto LABEL_270;
        }
        v132 = (int)v10;
        _nla_parse(&v137, 2, v143 + 2, (unsigned __int16)(*v143 - 4), 0, 0, 0);
        v10 = v138;
        if ( !v138 )
        {
          v107 = *(_QWORD **)(a2 + 64);
          do_trace_netlink_extack("missing request type/data");
          if ( v107 )
          {
            *v107 = "missing request type/data";
            v8 = v143;
            goto LABEL_268;
          }
LABEL_269:
          v14 = -22;
          goto LABEL_270;
        }
        if ( v28 < -1 || v17 <= v32 + 96 )
          goto LABEL_271;
        if ( v139 )
        {
          if ( v17 <= v32 + 96 )
            goto LABEL_271;
          *(_BYTE *)(v5 + 40) |= 1u;
        }
        else if ( (*(_BYTE *)(v5 + 40) & 1) == 0 )
        {
          goto LABEL_60;
        }
        if ( (*(_BYTE *)(v2[303] + 4LL) & 1) == 0 )
        {
          v107 = *(_QWORD **)(a2 + 64);
          do_trace_netlink_extack("reporting AP TSF is not supported");
          if ( v107 )
          {
            *v107 = "reporting AP TSF is not supported";
            v8 = v139;
LABEL_268:
            v107[1] = v8;
            v107[2] = 0;
          }
          goto LABEL_269;
        }
LABEL_60:
        v36 = *v10 - 4;
        if ( v36 > 3u )
        {
          v38 = v10[2];
          v10 += 2;
          v37 = v38;
          if ( v38 >= 4 && v37 <= v36 )
          {
            v39 = v32 + 64;
            v40 = v32 + 100;
            v41 = v17 >= v32 + 72 && v17 - (v32 + 72) >= 4;
            v42 = v32 + 111;
            v43 = !v41;
            v135 = v43;
            v45 = v17 < v39 || v17 - v39 < 8;
            v130 = v45;
            v41 = v17 >= v40;
            v46 = v17 - v40;
            v47 = v32 + 104;
            v49 = !v41 || v46 < 4;
            v124 = v49;
            v50 = v17 >= v47 && v17 - v47 >= 2;
            v51 = v32 + 72;
            v52 = !v50;
            v123 = v52;
            v41 = v17 >= v51;
            v53 = v17 - v51;
            v55 = !v41 || v53 < 4 || v28 < -1;
            v134 = v55;
            v56 = v17 <= v32 + 106 || v28 < -1;
            v133 = v56;
            v41 = v17 >= v39;
            v57 = v17 - v39;
            v58 = v32 + 100;
            v59 = v41 && v57 >= 8;
            v60 = v32 + 104;
            v61 = !v59 || v28 < -1;
            v41 = v17 >= v58;
            v62 = v17 - v58;
            v63 = v41 && v62 >= 4;
            v129 = v61;
            v64 = !v63 || v28 < -1;
            v41 = v17 >= v60;
            v65 = v17 - v60;
            v66 = v41 && v65 >= 2;
            v125 = v64;
            v114 = v32 + 111;
            v67 = !v66 || v28 < -1;
            v126 = v67;
            v115 = v32 + 110;
            v68 = v17 <= v32 + 107 || v28 < -1;
            v122 = v68;
            v117 = v32 + 109;
            v69 = v17 <= v32 + 108 || v28 < -1;
            v120 = v69;
            v70 = v17 <= v32 + 109 || v28 < -1;
            v121 = v70;
            v118 = v32 + 108;
            v119 = v32 + 107;
            v71 = v17 <= v32 + 110 || v28 < -1;
            v116 = v71;
            v72 = v32 + 106;
            v73 = v36;
            v74 = v17 <= v42 || v28 < -1;
            v131 = v72;
            v113 = v74;
            while ( 1 )
            {
              if ( (v10[1] & 0x3FFF) != 1 )
              {
                v7 = *(_WORD **)(a2 + 64);
                do_trace_netlink_extack("unsupported measurement type");
                if ( v7 )
                {
                  *(_QWORD *)v7 = "unsupported measurement type";
                  *((_QWORD *)v7 + 1) = v10;
                  v14 = -22;
                  *((_QWORD *)v7 + 2) = 0;
                  goto LABEL_239;
                }
                goto LABEL_238;
              }
              v75 = v2[303];
              v157 = 0;
              v158 = 0;
              v155 = 0;
              v156 = 0;
              v153 = 0;
              v154 = 0;
              v151 = 0;
              v152 = 0;
              v149 = 0;
              v150 = 0;
              v147 = 0;
              v148 = 0;
              v145 = 0;
              v146 = 0;
              if ( (v135 & 1) != 0 || v134 )
                goto LABEL_271;
              if ( (((unsigned __int64)*(unsigned int *)(v75 + 12) >> *(_DWORD *)(v5 + 16)) & 1) == 0 )
              {
                v78 = "FTM: unsupported bandwidth";
                goto LABEL_147;
              }
              _nla_parse(&v145, 13, v10 + 2, (unsigned __int16)(*v10 - 4), 0, 0, 0);
              v76 = v147;
              if ( v147 )
                v77 = *(_DWORD *)(v147 + 4);
              else
                v77 = 3;
              if ( v17 <= v131 )
                goto LABEL_271;
              if ( v133 )
                goto LABEL_271;
              v79 = *(_BYTE *)(v5 + 50) | 1;
              *(_BYTE *)(v5 + 50) = v79;
              if ( v130 || v129 )
                goto LABEL_271;
              if ( !v76 && **(_DWORD **)(v5 + 8) != 2 )
              {
                v78 = "FTM: must specify preamble";
                goto LABEL_147;
              }
              if ( (((unsigned __int64)*(unsigned int *)(v75 + 8) >> v77) & 1) == 0 )
              {
                v83 = "FTM: invalid preamble";
                goto LABEL_163;
              }
              if ( (v124 & 1) != 0 )
                goto LABEL_271;
              if ( v125 )
                goto LABEL_271;
              *(_DWORD *)(v5 + 44) = v77;
              if ( (v123 & 1) != 0 || v126 )
                goto LABEL_271;
              v80 = v149;
              *(_WORD *)(v5 + 48) = 0;
              if ( v80 )
              {
                if ( v126 )
                  goto LABEL_271;
                *(_WORD *)(v5 + 48) = *(_WORD *)(v80 + 4);
              }
              v81 = v146;
              if ( v133 )
                goto LABEL_271;
              v82 = v79 & 0xFD | (2 * (v146 != 0));
              *(_BYTE *)(v5 + 50) = v82;
              if ( v81 )
              {
                if ( (*(_BYTE *)(v75 + 18) & 2) == 0 )
                {
                  v7 = *(_WORD **)(a2 + 64);
                  do_trace_netlink_extack("FTM: ASAP mode not supported");
                  if ( v7 )
                  {
                    *(_QWORD *)v7 = "FTM: ASAP mode not supported";
                    v14 = -22;
                    *((_QWORD *)v7 + 1) = v146;
                    *((_QWORD *)v7 + 2) = 0;
                    goto LABEL_239;
                  }
                  goto LABEL_238;
                }
              }
              else if ( (*(_BYTE *)(v75 + 18) & 4) == 0 )
              {
                v78 = "FTM: non-ASAP mode not supported";
                goto LABEL_147;
              }
              if ( v17 <= v119 || v122 )
                goto LABEL_271;
              v85 = v148;
              *(_BYTE *)(v5 + 51) = 0;
              if ( v85 )
              {
                if ( v122 )
                  goto LABEL_271;
                v86 = *(unsigned __int8 *)(v85 + 4);
                *(_BYTE *)(v5 + 51) = v86;
                if ( (*(char *)(v75 + 16) & 0x80000000) == 0 && v86 > *(unsigned __int8 *)(v75 + 16) )
                {
                  v7 = *(_WORD **)(a2 + 64);
                  do_trace_netlink_extack("FTM: max NUM_BURSTS_EXP must be set lower than the device limit");
                  if ( v7 )
                  {
                    *(_QWORD *)v7 = "FTM: max NUM_BURSTS_EXP must be set lower than the device limit";
                    v84 = v148;
                    goto LABEL_237;
                  }
                  goto LABEL_238;
                }
              }
              if ( v17 <= v118 || v120 )
                goto LABEL_271;
              v87 = v150;
              *(_BYTE *)(v5 + 52) = 15;
              if ( v87 )
              {
                if ( v120 )
                  goto LABEL_271;
                *(_BYTE *)(v5 + 52) = *(_BYTE *)(v87 + 4);
              }
              if ( v17 <= v117 || v121 )
                goto LABEL_271;
              v88 = v151;
              *(_BYTE *)(v5 + 53) = 0;
              if ( v88 )
              {
                if ( v121 )
                  goto LABEL_271;
                LODWORD(v88) = *(_DWORD *)(v88 + 4);
                *(_BYTE *)(v5 + 53) = v88;
              }
              if ( (unsigned __int8)(*(_BYTE *)(v75 + 17) - 1) < (unsigned int)(unsigned __int8)(v88 - 1) )
              {
                v7 = *(_WORD **)(a2 + 64);
                do_trace_netlink_extack("FTM: FTMs per burst must be set lower than the device limit but non-zero");
                if ( v7 )
                {
                  *(_QWORD *)v7 = "FTM: FTMs per burst must be set lower than the device limit but non-zero";
                  v84 = v151;
                  goto LABEL_237;
                }
                goto LABEL_238;
              }
              if ( v17 <= v115 || v116 )
                goto LABEL_271;
              v89 = v152;
              *(_BYTE *)(v5 + 54) = 3;
              if ( v89 )
              {
                if ( v116 )
                  goto LABEL_271;
                *(_BYTE *)(v5 + 54) = *(_BYTE *)(v89 + 4);
              }
              if ( v133 )
                goto LABEL_271;
              v90 = v153;
              *(_BYTE *)(v5 + 50) = v82 & 0xFB | (4 * (v153 != 0));
              if ( v90 )
              {
                if ( (*(_BYTE *)(v75 + 18) & 8) == 0 )
                {
                  v7 = *(_WORD **)(a2 + 64);
                  do_trace_netlink_extack("FTM: LCI request not supported");
                  if ( v7 )
                  {
                    *(_QWORD *)v7 = "FTM: LCI request not supported";
                    *((_QWORD *)v7 + 1) = v153;
                    *((_QWORD *)v7 + 2) = 0;
                  }
                }
              }
              if ( v133 )
                goto LABEL_271;
              v91 = v154;
              *(_BYTE *)(v5 + 50) = *(_BYTE *)(v5 + 50) & 0xF7 | (8 * (v154 != 0));
              if ( v91 )
              {
                if ( (*(_BYTE *)(v75 + 18) & 0x10) == 0 )
                {
                  v7 = *(_WORD **)(a2 + 64);
                  do_trace_netlink_extack("FTM: civic location request not supported");
                  if ( v7 )
                  {
                    *(_QWORD *)v7 = "FTM: civic location request not supported";
                    *((_QWORD *)v7 + 1) = v154;
                    *((_QWORD *)v7 + 2) = 0;
                  }
                }
              }
              if ( v133 )
                goto LABEL_271;
              v92 = v155;
              v93 = *(_BYTE *)(v5 + 50) & 0xEF | (16 * (v155 != 0));
              *(_BYTE *)(v5 + 50) = v93;
              if ( v92 && (*(_BYTE *)(v75 + 18) & 0x20) == 0 )
              {
                v7 = *(_WORD **)(a2 + 64);
                do_trace_netlink_extack("FTM: trigger based ranging is not supported");
                if ( v7 )
                {
                  *(_QWORD *)v7 = "FTM: trigger based ranging is not supported";
                  v84 = v155;
                  goto LABEL_237;
                }
LABEL_238:
                v14 = -22;
                goto LABEL_239;
              }
              v94 = v156;
              if ( v133 )
                goto LABEL_271;
              v95 = v93 & 0xDF | (32 * (v156 != 0));
              *(_BYTE *)(v5 + 50) = v95;
              if ( v94 )
              {
                if ( (*(_BYTE *)(v75 + 18) & 0x40) == 0 )
                {
                  v7 = *(_WORD **)(a2 + 64);
                  do_trace_netlink_extack("FTM: trigger based ranging is not supported");
                  if ( !v7 )
                    goto LABEL_238;
                  *(_QWORD *)v7 = "FTM: trigger based ranging is not supported";
                  v84 = v156;
LABEL_237:
                  *((_QWORD *)v7 + 1) = v84;
                  *((_QWORD *)v7 + 2) = 0;
                  goto LABEL_238;
                }
                if ( v92 )
                {
                  v78 = "FTM: can't set both trigger based and non trigger based";
LABEL_147:
                  v7 = *(_WORD **)(a2 + 64);
                  do_trace_netlink_extack(v78);
                  if ( v7 )
                    *(_QWORD *)v7 = v78;
                  goto LABEL_238;
                }
              }
              else
              {
                if ( v121 )
                  goto LABEL_271;
                if ( !v92 && *(unsigned __int8 *)(v5 + 53) >= 0x20u )
                {
                  v7 = *(_WORD **)(a2 + 64);
                  do_trace_netlink_extack("FTM: FTMs per burst must be set lower than 31");
                  if ( v7 )
                  {
                    *(_QWORD *)v7 = "FTM: FTMs per burst must be set lower than 31";
                    v14 = -34;
                    *((_QWORD *)v7 + 1) = v151;
                    *((_QWORD *)v7 + 2) = 0;
                  }
                  else
                  {
                    v14 = -34;
                  }
                  goto LABEL_239;
                }
                if ( !v92 )
                {
                  v96 = 1;
                  goto LABEL_226;
                }
              }
              if ( v125 )
                goto LABEL_271;
              if ( *(_DWORD *)(v5 + 44) != 4 )
              {
                v83 = "FTM: non EDCA based ranging must use HE preamble";
LABEL_163:
                v7 = *(_WORD **)(a2 + 64);
                do_trace_netlink_extack(v83);
                if ( v7 )
                {
                  *(_QWORD *)v7 = v83;
                  v84 = v147;
                  goto LABEL_237;
                }
                goto LABEL_238;
              }
              v96 = 0;
LABEL_226:
              if ( v133 )
                goto LABEL_271;
              v97 = v95 & 0xBF | ((v157 != 0) << 6);
              if ( v157 )
                v98 = v96;
              else
                v98 = 0;
              *(_BYTE *)(v5 + 50) = v97;
              if ( v98 == 1 )
              {
                v7 = *(_WORD **)(a2 + 64);
                do_trace_netlink_extack("FTM: LMR feedback set for EDCA based ranging");
                if ( !v7 )
                  goto LABEL_238;
                *(_QWORD *)v7 = "FTM: LMR feedback set for EDCA based ranging";
                v84 = v157;
                goto LABEL_237;
              }
              if ( v158 )
              {
                if ( !v96 )
                {
                  if ( v17 <= v114 || v113 )
                    goto LABEL_271;
                  v14 = 0;
                  *(_BYTE *)(v5 + 55) = *(_BYTE *)(v158 + 4);
                  goto LABEL_239;
                }
                v7 = *(_WORD **)(a2 + 64);
                do_trace_netlink_extack("FTM: BSS color set for EDCA based ranging");
                if ( !v7 )
                  goto LABEL_238;
                *(_QWORD *)v7 = "FTM: BSS color set for EDCA based ranging";
                v84 = v158;
                goto LABEL_237;
              }
              v14 = 0;
LABEL_239:
              v99 = (*v10 + 3) & 0x1FFFC;
              v73 -= v99;
              if ( v73 > 3 )
              {
                v10 = (unsigned __int16 *)((char *)v10 + v99);
                v100 = *v10;
                if ( v100 >= 4 && v73 >= v100 )
                  continue;
              }
              if ( !v14 )
                break;
LABEL_270:
              kfree(v136);
              goto LABEL_280;
            }
          }
        }
        ++v28;
        v29 = ((unsigned __int16)*v8 + 3) & 0x1FFFC;
        LODWORD(v10) = v132 - v29;
        v8 = (_WORD *)((char *)v8 + v29);
      }
      while ( v132 - (int)v29 > 3 );
    }
    v101 = v2[22];
    v102 = v101 + 1;
    v2[22] = v101 + 1;
    if ( v101 == -1 )
    {
      __break(0x800u);
      v102 = v2[22] + 1LL;
      v2[22] = v102;
    }
    *(_QWORD *)v136 = v102;
    if ( v128 != 20 )
    {
      v18 = v127;
      if ( (v17 & 0xFFFFFFFFFFFFFFFCLL) != 0x14 )
        break;
    }
LABEL_271:
    __break(1u);
LABEL_272:
    _fortify_panic(17, v18);
    StatusReg = _ReadStatusReg(SP_EL0);
    v109 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &nl80211_pmsr_start__alloc_tag;
    v110 = 56LL * (int)v10;
    v41 = __CFADD__(v110, 56);
    v111 = v110 + 56;
    if ( v41 )
      v111 = -1;
    if ( is_mul_ok((int)v10, 0x38u) )
      v17 = v111;
    else
      v17 = -1;
    v19 = _kmalloc_noprof(v17, 3520);
    *(_QWORD *)(StatusReg + 80) = v109;
    if ( !v19 )
      goto LABEL_279;
  }
  *(_DWORD *)(v136 + 20) = *(_DWORD *)(a2 + 4);
  v103 = *(__int64 (__fastcall **)(_QWORD))(*v2 + 880LL);
  if ( v103 )
  {
    v104 = v127;
    if ( *((_DWORD *)v103 - 1) != 487434908 )
      __break(0x8228u);
    v14 = v103(v2 + 124);
  }
  else
  {
    v104 = v127;
    v14 = -95;
  }
  if ( v14 )
    goto LABEL_270;
  list_add_tail(v136 + 40, v104 + 216);
  v105 = *(_QWORD *)(a2 + 64);
  if ( v105 )
  {
    v106 = *(_QWORD *)v136;
    v14 = 0;
    *(_BYTE *)(v105 + 54) = 8;
    *(_QWORD *)(v105 + 34) = v106;
  }
  else
  {
    v14 = 0;
  }
LABEL_280:
  _ReadStatusReg(SP_EL0);
  return v14;
}
