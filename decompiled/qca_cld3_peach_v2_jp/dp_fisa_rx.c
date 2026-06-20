__int64 __fastcall dp_fisa_rx(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned __int64 v3; // x8
  __int64 *v4; // x26
  _QWORD *v5; // x24
  unsigned int v8; // w23
  unsigned __int64 v9; // x25
  __int64 v10; // x20
  __int64 v11; // x0
  __int64 v12; // x22
  unsigned int (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x0
  void (__fastcall *v18)(__int64, int *); // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int64 v27; // x27
  __int64 *v28; // x0
  __int64 v29; // x27
  __int64 v30; // x22
  __int64 v31; // x8
  void (__fastcall *v32)(__int64, __int64 *); // x8
  int v33; // w8
  _DWORD *v35; // x8
  __int64 v36; // x1
  __int64 v37; // x0
  __int64 v38; // x22
  __int64 v39; // x8
  __int64 (*v40)(void); // x8
  __int64 flow_tuple_from_nbuf; // x0
  __int64 v42; // x27
  void (__fastcall *v43)(__int64, int *); // x8
  bool v44; // w27
  __int64 v45; // x22
  __int64 (__fastcall *v46)(_QWORD); // x8
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 (__fastcall *v49)(__int64, __int64 *); // x8
  int v50; // w27
  unsigned int v51; // w8
  __int64 v52; // x8
  __int64 v53; // x22
  int v54; // w8
  _BYTE *v55; // x22
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x9
  int v59; // w11
  __int64 v60; // x22
  __int64 v61; // x8
  __int64 (__fastcall *v62)(_QWORD); // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w23
  unsigned int v80; // w22
  __int64 v81; // x8
  __int64 (__fastcall *v82)(_QWORD); // x8
  char v83; // w0
  __int64 v84; // x8
  unsigned __int8 (__fastcall *v85)(_QWORD); // x8
  char v86; // w22
  __int64 v87; // x1
  __int64 should_stop; // x0
  __int64 v89; // x1
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  char v98; // w22
  int v99; // w8
  __int64 v100; // x9
  unsigned int v101; // w9
  unsigned __int16 v102; // w8
  __int16 v103; // w8
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int64 v128; // x22
  __int64 (__fastcall *v129)(_QWORD); // x8
  int v130; // w0
  __int64 v131; // x8
  __int64 v132; // x1
  __int64 (__fastcall *v133)(__int64, unsigned __int64 *, __int64 *); // x8
  int v134; // w8
  int v135; // w9
  __int64 v136; // x22
  unsigned int v137; // w11
  __int16 v138; // w8
  __int16 v139; // w9
  __int64 v140; // x0
  __int16 v141; // w10
  __int16 v142; // w8
  __int16 v143; // w10
  char v144; // w22
  __int64 *v145; // x0
  __int64 v146; // x8
  __int64 v147; // x8
  unsigned int v148; // w22
  __int64 v149; // x1
  int v150; // w8
  __int64 v151; // x8
  __int64 v152; // x8
  __int64 *v153; // x8
  int v154; // w8
  __int64 v155; // x9
  __int16 v156; // w9
  __int64 v157; // x0
  __int64 v158; // x1
  int v159; // w8
  int v160; // w0
  __int64 v161; // x8
  __int64 v162; // x27
  int v163; // w22
  __int64 v164; // x22
  int v165; // w9
  char v167; // w8
  bool v168; // w8
  int v169; // w9
  unsigned int v170; // w8
  __int16 v171; // w8
  __int64 v172; // x8
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  int v181; // w9
  int v182; // w17
  unsigned int v183; // w10
  unsigned int v184; // w11
  __int64 v185; // x1
  unsigned int v186; // w13
  unsigned int v187; // w15
  unsigned int v188; // w0
  unsigned int v189; // w16
  unsigned int v190; // w12
  unsigned int v191; // w14
  unsigned int v192; // w2
  __int64 v193; // x22
  __int64 v194; // x1
  char v195; // w3
  __int64 v196; // x3
  __int64 v197; // x1
  __int64 v198; // x8
  __int64 v199; // x0
  __int64 v200; // x1
  int v201; // w8
  __int64 v202; // x10
  __int64 v203; // x8
  __int64 v204; // x27
  __int64 (__fastcall *v205)(_QWORD); // x8
  int v206; // w0
  __int64 v207; // x8
  int v208; // w22
  __int64 (__fastcall *v209)(_QWORD); // x8
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  __int64 v218; // x27
  void (__fastcall *v219)(__int64, __int64, __int64); // x8
  __int64 v220; // x0
  __int64 v221; // x1
  unsigned __int8 v222; // w9
  unsigned int v223; // w8
  __int64 *v224; // x0
  __int64 v225; // x8
  __int64 v226; // x0
  __int64 (__fastcall *v227)(_QWORD); // x8
  int v228; // w0
  __int64 v229; // x8
  __int64 v230; // x1
  unsigned int v235; // w8
  unsigned int v236; // w8
  unsigned int v238; // [xsp+Ch] [xbp-F4h]
  __int64 v239; // [xsp+10h] [xbp-F0h]
  int v240; // [xsp+1Ch] [xbp-E4h]
  int v241; // [xsp+20h] [xbp-E0h]
  int v242; // [xsp+24h] [xbp-DCh]
  unsigned int v243; // [xsp+28h] [xbp-D8h]
  unsigned int v244; // [xsp+2Ch] [xbp-D4h]
  unsigned int v245; // [xsp+2Ch] [xbp-D4h]
  unsigned int v246; // [xsp+2Ch] [xbp-D4h]
  __int64 v247; // [xsp+30h] [xbp-D0h]
  __int64 v248; // [xsp+30h] [xbp-D0h]
  __int64 v249; // [xsp+30h] [xbp-D0h]
  unsigned int v250; // [xsp+30h] [xbp-D0h]
  unsigned int v251; // [xsp+30h] [xbp-D0h]
  unsigned __int64 v252; // [xsp+38h] [xbp-C8h]
  unsigned int v253; // [xsp+44h] [xbp-BCh]
  unsigned __int64 StatusReg; // [xsp+48h] [xbp-B8h]
  __int64 *v255; // [xsp+50h] [xbp-B0h]
  __int64 v256; // [xsp+58h] [xbp-A8h]
  int v257; // [xsp+64h] [xbp-9Ch] BYREF
  _BYTE v258[4]; // [xsp+68h] [xbp-98h] BYREF
  _BYTE v259[4]; // [xsp+6Ch] [xbp-94h] BYREF
  __int64 v260; // [xsp+70h] [xbp-90h] BYREF
  __int16 v261; // [xsp+78h] [xbp-88h]
  char v262; // [xsp+7Ah] [xbp-86h]
  int v263; // [xsp+7Ch] [xbp-84h] BYREF
  __int64 v264; // [xsp+80h] [xbp-80h] BYREF
  __int64 v265; // [xsp+88h] [xbp-78h] BYREF
  __int64 v266; // [xsp+90h] [xbp-70h]
  __int64 v267; // [xsp+98h] [xbp-68h]
  __int64 v268; // [xsp+A0h] [xbp-60h]
  __int64 v269; // [xsp+A8h] [xbp-58h]
  int v270; // [xsp+B0h] [xbp-50h]
  unsigned __int64 v271; // [xsp+B8h] [xbp-48h] BYREF
  unsigned __int64 v272; // [xsp+C0h] [xbp-40h]
  unsigned __int64 v273; // [xsp+C8h] [xbp-38h]
  unsigned __int64 v274; // [xsp+D0h] [xbp-30h]
  _DWORD v275[6]; // [xsp+D8h] [xbp-28h] BYREF
  __int64 v276; // [xsp+F0h] [xbp-10h]

  v276 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v3 = a3[9];
    v4 = *(__int64 **)(a1 + 1480);
    v5 = a3;
    v8 = ((unsigned int)v3 >> 18) & 0xF;
    v9 = (v3 >> 18) & 0xF;
    v257 = 0;
    v255 = v4 + 55;
    v256 = a1 + 1504;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v10 = (__int64)v5;
      v5 = (_QWORD *)*v5;
      *(_QWORD *)v10 = 0;
      if ( (*((_BYTE *)v4 + 634) & 1) == 0 && ((*(_BYTE *)(v10 + 72) & 2) != 0 || *(_DWORD *)(a2 + 32) == 1)
        || (*(_BYTE *)(v10 + 48) & 0x80) != 0
        || _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(v10 + 224))
        || (*(_BYTE *)(v10 + 84) & 0x10) != 0
        || (*(_BYTE *)(a2 + 80) & 1) != 0 )
      {
        goto LABEL_16;
      }
      if ( v8 >= 8 )
        goto LABEL_282;
      v11 = *(_QWORD *)(*(_QWORD *)(a2 + 88) + 32LL);
      v12 = v11 + 3604;
      if ( *(_BYTE *)(v11 + v9 + 3596) )
      {
        if ( !*(_BYTE *)(v11 + 3604 + v9) )
        {
          dp_rx_fisa_flush_by_intf_ctx_id(v11, v8);
          *(_BYTE *)(v12 + v9) = 1;
        }
        goto LABEL_16;
      }
      if ( *(_BYTE *)(v11 + 3604 + v9) )
        *(_BYTE *)(v12 + v9) = 0;
      if ( *(_DWORD *)(a1 + 1500) )
      {
        if ( v9 >= 8 )
          goto LABEL_282;
        if ( !*(_BYTE *)(v256 + v9) )
        {
          dp_rx_fisa_flush_by_ctx_id();
          *(_BYTE *)(v256 + v9) = 1;
        }
        goto LABEL_16;
      }
      if ( v9 > 7 )
        goto LABEL_282;
      if ( *(_BYTE *)(v256 + v9) )
        *(_BYTE *)(v256 + v9) = 0;
      v15 = *(_QWORD *)(v10 + 40);
      v16 = ((*(_DWORD *)(v10 + 48) >> 4) & 7) + (unsigned int)*((unsigned __int16 *)v4 + 316);
      if ( v15 )
        *(_QWORD *)(v10 + 40) = v15 - (unsigned int)v16;
      skb_push(v10, v16);
      v17 = *(_QWORD *)(v10 + 224);
      v18 = *(void (__fastcall **)(__int64, int *))(*(_QWORD *)(*(_QWORD *)(a1 + 256) + 74392LL) + 1136LL);
      if ( *((_DWORD *)v18 - 1) != 1076365573 )
        __break(0x8228u);
      v18(v17, &v257);
      if ( !v257 )
      {
        _qdf_nbuf_free(v10);
        if ( v4 )
          ++*((_DWORD *)v4 + 86);
        continue;
      }
      v27 = *(_QWORD *)(v10 + 72);
      v253 = ((unsigned int)v27 >> 18) & 0xF;
      if ( *((_BYTE *)v4 + 608) == 1 )
      {
        if ( v253 >= 9 )
          goto LABEL_282;
        v28 = &v255[2 * ((v27 >> 18) & 0xF)];
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v28);
        }
        else
        {
          raw_spin_lock_bh(v28);
          v255[2 * ((v27 >> 18) & 0xF) + 1] |= 1uLL;
        }
      }
      v252 = v27;
      v29 = *(_QWORD *)(v4[1] + 256);
      if ( (*((_BYTE *)v4 + 634) & 1) == 0 && (*(_BYTE *)(v10 + 72) & 2) != 0 )
        goto LABEL_95;
      v30 = *(_QWORD *)(v10 + 224);
      v260 = 0;
      v31 = *(_QWORD *)(v29 + 74392);
      v259[0] = 0;
      v258[0] = 0;
      v32 = *(void (__fastcall **)(__int64, __int64 *))(v31 + 1136);
      if ( *((_DWORD *)v32 - 1) != 1076365573 )
        __break(0x8228u);
      v32(v30, &v260);
      v33 = *(_DWORD *)(v10 + 48);
      if ( *((_BYTE *)v4 + 617) == 1 )
      {
        _CF = (_DWORD)v260 == 10 || (unsigned int)v260 >= 0x10;
        if ( !_CF || (v33 & 0x3E00) != 0 )
          goto LABEL_95;
      }
      else if ( (v33 & 0x3E00) != 0 )
      {
        goto LABEL_95;
      }
      v35 = *(_DWORD **)(*(_QWORD *)(v29 + 74392) + 840LL);
      if ( *(v35 - 1) != -134558221 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _BYTE *, _BYTE *, char *))v35)(v30, v259, v258, (char *)&v260 + 4);
      if ( ((v258[0] | v259[0]) & 1) != 0 )
      {
        v244 = HIDWORD(v260);
        if ( *((_BYTE *)v4 + 609) == 1 )
        {
          v37 = *(_QWORD *)(v10 + 224);
          v38 = *(_QWORD *)(v4[1] + 256);
          v274 = 0;
          memset(v275, 0, 12);
          v272 = 0;
          v273 = 0;
          v39 = *(_QWORD *)(v38 + 74392);
          v271 = 0;
          v263 = 0;
          v40 = *(__int64 (**)(void))(v39 + 1288);
          v262 = 0;
          v261 = 0;
          v247 = v37;
          if ( *((_DWORD *)v40 - 1) != -1199594756 )
            __break(0x8228u);
          flow_tuple_from_nbuf = v40();
          v42 = 0;
          if ( !(_DWORD)flow_tuple_from_nbuf && !v262 )
          {
            if ( !((unsigned __int8)v261 | HIBYTE(v261)) )
              goto LABEL_259;
            v43 = *(void (__fastcall **)(__int64, int *))(*(_QWORD *)(v38 + 74392) + 1136LL);
            if ( *((_DWORD *)v43 - 1) != 1076365573 )
              __break(0x8228u);
            v43(v247, &v263);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v4 + 6);
            }
            else
            {
              raw_spin_lock_bh(v4 + 6);
              v4[7] |= 1uLL;
            }
            v265 = 0;
            v264 = 0;
            if ( (unsigned int)qdf_list_peek_front(v4 + 51, &v265) == 13 )
            {
              v44 = 0;
            }
            else
            {
              v158 = v265;
              do
              {
                v159 = *(_DWORD *)(v158 + 76);
                v44 = v159 == v244;
                if ( v159 == v244 )
                  break;
                v160 = qdf_list_peek_next(v4 + 51, (_QWORD *)v158, &v264);
                v158 = v264;
                v265 = v264;
              }
              while ( !v160 );
            }
            v161 = v4[7];
            if ( (v161 & 1) != 0 )
            {
              v4[7] = v161 & 0xFFFFFFFFFFFFFFFELL;
              flow_tuple_from_nbuf = raw_spin_unlock_bh(v4 + 6);
              if ( v44 )
                goto LABEL_259;
            }
            else
            {
              flow_tuple_from_nbuf = raw_spin_unlock(v4 + 6);
              if ( v44 )
                goto LABEL_259;
            }
            v162 = *v4;
            v163 = *((_DWORD *)v4 + 10);
            flow_tuple_from_nbuf = wlan_dp_get_flow_tuple_from_nbuf(v4[1], &v271, v10, v247);
            if ( (v271 & 0x10000) != 0 )
              goto LABEL_259;
            v42 = v162 + 336LL * (v163 & v244);
            if ( !*(_BYTE *)(v42 + 40)
              || v275[0] ^ *(_DWORD *)(v42 + 120)
               | HIDWORD(v274) ^ *(_DWORD *)(v42 + 116)
               | LOWORD(v275[1]) ^ *(unsigned __int16 *)(v42 + 124)
               | HIWORD(v275[1]) ^ *(unsigned __int16 *)(v42 + 126)
               | (unsigned int)v274 ^ *(_DWORD *)(v42 + 112)
               | HIDWORD(v273) ^ *(_DWORD *)(v42 + 108)
               | (unsigned int)v273 ^ *(_DWORD *)(v42 + 104)
               | HIDWORD(v272) ^ *(_DWORD *)(v42 + 100)
               | (unsigned int)v272 ^ *(_DWORD *)(v42 + 96)
               | HIDWORD(v271) ^ *(_DWORD *)(v42 + 92)
               | LOWORD(v275[2]) ^ *(unsigned __int16 *)(v42 + 128) )
            {
              flow_tuple_from_nbuf = _qdf_mem_malloc(0x60u, "dp_fisa_rx_queue_fst_update_work", 1557);
              if ( flow_tuple_from_nbuf )
              {
                v164 = flow_tuple_from_nbuf;
                qdf_mem_copy((void *)(flow_tuple_from_nbuf + 16), &v271, 0x2Cu);
                v165 = HIBYTE(v261);
                _ZF = (unsigned __int8)v261 == 0;
                *(_DWORD *)(v164 + 76) = v244;
                v167 = !_ZF;
                *(_BYTE *)(v164 + 88) = v167;
                v168 = v165 != 0;
                v169 = v263;
                *(_BYTE *)(v164 + 89) = v168;
                v170 = *(_DWORD *)(v10 + 72);
                *(_DWORD *)(v164 + 84) = v169;
                *(_BYTE *)(v164 + 90) = (v170 >> 18) & 0xF;
                if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a2 + 88) + 32LL) + 3612LL) == 1 )
                {
                  *(_BYTE *)(v164 + 90) = 7;
                  *(_DWORD *)(v164 + 84) = 10;
                }
                *(_QWORD *)(v164 + 64) = a2;
                *(_BYTE *)(v164 + 74) = *(_BYTE *)(a2 + 59);
                v171 = *(_WORD *)(v10 + 62);
                *(_DWORD *)(v164 + 80) = 0;
                *(_WORD *)(v164 + 72) = v171;
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v4 + 6);
                }
                else
                {
                  raw_spin_lock_bh(v4 + 6);
                  v4[7] |= 1uLL;
                }
                qdf_list_insert_back(v4 + 51, (_QWORD *)v164);
                v172 = v4[7];
                if ( (v172 & 1) != 0 )
                {
                  v4[7] = v172 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v4 + 6);
                  if ( !*((_DWORD *)v4 + 153) )
                    goto LABEL_258;
LABEL_191:
                  *((_BYTE *)v4 + 616) = 1;
                  flow_tuple_from_nbuf = qdf_trace_msg(
                                           0x45u,
                                           5u,
                                           "%s: defer fst update task in WoW",
                                           v173,
                                           v174,
                                           v175,
                                           v176,
                                           v177,
                                           v178,
                                           v179,
                                           v180,
                                           "dp_fisa_rx_queue_fst_update_work");
                }
                else
                {
                  raw_spin_unlock(v4 + 6);
                  if ( *((_DWORD *)v4 + 153) )
                    goto LABEL_191;
LABEL_258:
                  flow_tuple_from_nbuf = queue_work_on(32, v4[50], v4 + 44);
                }
              }
LABEL_259:
              v42 = 0;
            }
          }
        }
        else
        {
          v270 = 0;
          v268 = 0;
          v269 = 0;
          v266 = 0;
          v267 = 0;
          v47 = v4[1];
          v265 = 0;
          BYTE2(v264) = 0;
          v48 = *(_QWORD *)(v47 + 256);
          LOWORD(v264) = 0;
          v240 = v260;
          v49 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v48 + 74392) + 1288LL);
          v239 = *(_QWORD *)(v10 + 72);
          if ( *((_DWORD *)v49 - 1) != -1199594756 )
            __break(0x8228u);
          flow_tuple_from_nbuf = v49(v30, &v264);
          v42 = 0;
          if ( !(_DWORD)flow_tuple_from_nbuf && !BYTE2(v264) )
          {
            if ( !((unsigned __int8)v264 | BYTE1(v264)) )
              goto LABEL_259;
            v50 = *((_DWORD *)v4 + 10);
            v51 = *((unsigned __int16 *)v4 + 18);
            LOBYTE(v265) = 0;
            v238 = v51;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v4 + 6);
            }
            else
            {
              raw_spin_lock_bh(v4 + 6);
              v4[7] |= 1uLL;
            }
            wlan_dp_get_flow_tuple_from_nbuf(v4[1], &v265, v10, v30);
            if ( BYTE2(v265) == 1 )
            {
              v52 = v4[7];
              if ( (v52 & 1) != 0 )
              {
                v4[7] = v52 & 0xFFFFFFFFFFFFFFFELL;
                flow_tuple_from_nbuf = raw_spin_unlock_bh(v4 + 6);
              }
              else
              {
                flow_tuple_from_nbuf = raw_spin_unlock(v4 + 6);
              }
              goto LABEL_259;
            }
            v181 = WORD2(v269);
            v182 = (unsigned __int16)v270;
            v184 = HIDWORD(v268);
            v183 = v269;
            v241 = HIWORD(v269);
            v185 = *v4;
            v251 = 0;
            v187 = HIDWORD(v267);
            v186 = v268;
            v188 = HIDWORD(v266);
            v189 = v267;
            v191 = HIDWORD(v265);
            v190 = v266;
            v192 = v50 & v244;
            while ( 1 )
            {
              v193 = v185 + 336LL * v192;
              v242 = *(unsigned __int8 *)(v193 + 40);
              if ( !*(_BYTE *)(v193 + 40) )
                break;
              if ( !(*(_DWORD *)(v193 + 120) ^ v183
                   | *(_DWORD *)(v193 + 116) ^ v184
                   | *(unsigned __int16 *)(v193 + 124) ^ v181
                   | *(unsigned __int16 *)(v193 + 126) ^ v241
                   | *(_DWORD *)(v193 + 112) ^ v186
                   | *(_DWORD *)(v193 + 108) ^ v187
                   | *(_DWORD *)(v193 + 104) ^ v189
                   | *(_DWORD *)(v193 + 100) ^ v188
                   | *(_DWORD *)(v193 + 96) ^ v190
                   | *(_DWORD *)(v193 + 92) ^ v191
                   | *(unsigned __int16 *)(v193 + 128) ^ v182) )
              {
                *(_QWORD *)(v193 + 152) = a2;
                *(_BYTE *)(v193 + 160) = *(_BYTE *)(a2 + 59);
                *(_QWORD *)(v193 + 168) = *(_QWORD *)(*(_QWORD *)(a2 + 88) + 32LL);
                goto LABEL_206;
              }
              v192 = v4[5] & (v192 + 1);
              ++v251;
              ++*((_DWORD *)v4 + 18);
              if ( v238 + 1 == v251 )
              {
                v251 = v238 + 1;
                goto LABEL_206;
              }
            }
            v194 = v4[1];
            *(_DWORD *)(v193 + 16) = v192;
            *(_DWORD *)(v193 + 8) = v244;
            v195 = *(_BYTE *)(a2 + 59);
            *(_QWORD *)(v193 + 152) = a2;
            *(_BYTE *)(v193 + 160) = v195;
            v196 = *(_QWORD *)(*(_QWORD *)(a2 + 88) + 32LL);
            *(_QWORD *)(v193 + 200) = v194;
            *(_QWORD *)(v193 + 168) = v196;
            v275[4] = 0;
            v275[3] = -559038737;
            v272 = __PAIR64__(v189, v188);
            v273 = __PAIR64__(v186, v187);
            v274 = __PAIR64__(v183, v184);
            LOWORD(v275[0]) = v181;
            HIWORD(v275[0]) = v241;
            *(_QWORD *)&v275[1] = (unsigned __int16)v182;
            v198 = v4[1];
            v197 = v4[2];
            v271 = __PAIR64__(v190, v191);
            v199 = hal_rx_flow_setup_fse(*(_QWORD *)(v198 + 256), v197);
            *(_BYTE *)(v193 + 40) = 1;
            *(_QWORD *)v193 = v199;
            *(_DWORD *)(v193 + 244) = v240;
            *(_BYTE *)(v193 + 144) = ((unsigned int)v239 >> 18) & 0xF;
            *(_DWORD *)(v193 + 12) = *(_DWORD *)(v10 + 80);
            *(_QWORD *)(v193 + 248) = sched_clock(v199, v200);
            qdf_mem_copy((void *)(v193 + 88), &v265, 0x2Cu);
            v201 = *(unsigned __int8 *)(v193 + 128);
            v202 = 0xEA00000000LL;
            if ( v201 == 17 )
              v202 = 0;
            if ( v201 == 6 )
              v202 = 0x100000000LL;
            *(_QWORD *)(v193 + 136) = (v202
                                     | ((unsigned __int64)*(unsigned __int16 *)(v193 + 124) << 16)
                                     | *(unsigned __int16 *)(v193 + 126))
                                    ^ (unsigned int)(*(_DWORD *)(v193 + 104) ^ *(_DWORD *)(v193 + 120))
                                    ^ 0x574C414E5F44505FLL;
            *(_BYTE *)(v193 + 42) = v264;
            *(_BYTE *)(v193 + 41) = BYTE1(v264);
            __isb(0xFu);
            *(_QWORD *)(v193 + 272) = _ReadStatusReg(CNTVCT_EL0);
            if ( (*(_BYTE *)(v10 + 72) & 2) != 0 || *(_DWORD *)(a2 + 32) == 1 )
              *(_BYTE *)(v193 + 89) = 1;
            ++*((_DWORD *)v4 + 16);
LABEL_206:
            v203 = v4[7];
            if ( (v203 & 1) != 0 )
            {
              v4[7] = v203 & 0xFFFFFFFFFFFFFFFELL;
              flow_tuple_from_nbuf = raw_spin_unlock_bh(v4 + 6);
            }
            else
            {
              flow_tuple_from_nbuf = raw_spin_unlock(v4 + 6);
            }
            if ( v251 <= v238 )
              v42 = v193;
            else
              v42 = 0;
            if ( !v242 && v251 <= v238 )
            {
              if ( *((_BYTE *)v4 + 152) == 1 )
              {
                _X9 = (unsigned int *)(v4 + 11);
                __asm { PRFM            #0x11, [X9] }
                do
                {
                  v235 = __ldxr(_X9);
                  v236 = v235 + 1;
                }
                while ( __stlxr(v236, _X9) );
                __dmb(0xBu);
                if ( v236 == 1 )
                {
                  v204 = jiffies;
                  v4[14] = v204 + 2LL * (unsigned int)qdf_timer_get_multiplier();
                  flow_tuple_from_nbuf = add_timer(v4 + 12);
                }
              }
              v42 = v193;
            }
          }
        }
      }
      else
      {
        flow_tuple_from_nbuf = *(_QWORD *)(v10 + 224);
        v45 = *(_QWORD *)(v4[1] + 256);
        if ( HIDWORD(v260) >= *((unsigned __int16 *)v4 + 16) )
        {
          v218 = *(_QWORD *)(v10 + 224);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: flow_idx is invalid 0x%x",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "dp_fisa_rx_get_sw_ft_entry");
          v219 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v45 + 74392) + 1240LL);
          if ( *((_DWORD *)v219 - 1) != 343547449 )
            __break(0x8228u);
          v219(v45, v218, 5);
          if ( v4 )
LABEL_94:
            ++*((_DWORD *)v4 + 80);
LABEL_95:
          v42 = 0;
LABEL_96:
          v54 = 1;
          goto LABEL_97;
        }
        v42 = *v4 + 336LL * HIDWORD(v260);
        if ( !*(_BYTE *)(v42 + 40) )
        {
          v53 = jiffies;
          if ( dp_fisa_rx_get_sw_ft_entry___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: Pkt rx for non configured flow idx 0x%x",
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              "dp_fisa_rx_get_sw_ft_entry");
            dp_fisa_rx_get_sw_ft_entry___last_ticks = v53;
          }
          if ( v4 )
            goto LABEL_94;
          goto LABEL_95;
        }
        if ( (v4[76] & 1) != 0 )
        {
          v46 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v45 + 74392) + 816LL);
          if ( *((_DWORD *)v46 - 1) != 855462014 )
            __break(0x8228u);
          flow_tuple_from_nbuf = v46(flow_tuple_from_nbuf);
          if ( *((_DWORD *)v4 + 17) )
          {
            if ( (_DWORD)flow_tuple_from_nbuf != *(_DWORD *)(v42 + 240) )
              goto LABEL_95;
          }
        }
        *(_QWORD *)(v42 + 152) = a2;
        *(_BYTE *)(v42 + 160) = *(_BYTE *)(a2 + 59);
        *(_QWORD *)(v42 + 168) = *(_QWORD *)(*(_QWORD *)(a2 + 88) + 32LL);
      }
      if ( !v42 )
        goto LABEL_96;
      ++*(_QWORD *)(v42 + 280);
      v220 = sched_clock(flow_tuple_from_nbuf, v36);
      *(_QWORD *)(v42 + 256) = v220;
      v222 = *(_DWORD *)(v42 + 16);
      *(_WORD *)(v42 + 36) = *(_WORD *)(v10 + 62);
      v223 = *(_DWORD *)(v10 + 52) & 0xFFF00FFF | (v222 << 12);
      *(_DWORD *)(v10 + 52) = v223;
      *(_DWORD *)(v10 + 56) = *(_DWORD *)(v42 + 240);
      if ( *(_BYTE *)(v42 + 321) )
        *(_DWORD *)(v10 + 52) = v223 | 0x100000;
      if ( *(_BYTE *)(a1 + 223) == 1 )
        *(_QWORD *)(v42 + 304) = sched_clock(v220, v221);
      v54 = *(unsigned __int8 *)(v42 + 89);
      if ( *(_BYTE *)(v42 + 89) )
      {
LABEL_266:
        if ( *((_BYTE *)v4 + 608) == 1 )
        {
          if ( v253 >= 9 )
LABEL_282:
            __break(0x5512u);
          v224 = &v255[2 * ((v252 >> 18) & 0xF)];
          v225 = v224[1];
          if ( (v225 & 1) != 0 )
          {
            v224[1] = v225 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v224);
          }
          else
          {
            raw_spin_unlock(v224);
          }
        }
        goto LABEL_270;
      }
LABEL_97:
      v55 = *(_BYTE **)(*(_QWORD *)(a2 + 88) + 32LL);
      if ( (v55[3613] & 1) != 0 )
      {
        v56 = *(_QWORD *)(*(_QWORD *)v55 + 1480LL);
        if ( *(_BYTE *)(v56 + 608) == 1 )
        {
          v57 = v56 + 16 * v9;
          v58 = *(_QWORD *)(v57 + 448);
          if ( (v58 & 1) != 0 )
          {
            *(_QWORD *)(v57 + 448) = v58 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v57 + 440);
          }
          else
          {
            raw_spin_unlock(v57 + 440);
          }
        }
        if ( !v55[v9 + 3604] )
        {
          dp_rx_fisa_flush_by_intf_ctx_id(v55, v8);
          v55[v9 + 3604] = 1;
        }
        goto LABEL_270;
      }
      if ( v55[v9 + 3604] )
        v55[v9 + 3604] = 0;
      if ( *(_QWORD *)(*(_QWORD *)(v10 + 216) + *(unsigned int *)(v10 + 212) + 8LL) )
      {
        if ( (v54 & 1) == 0 )
          dp_rx_fisa_flush_flow(a2, v42);
        if ( *((_BYTE *)v4 + 608) == 1 )
        {
          if ( v253 >= 9 )
            goto LABEL_282;
          qdf_spin_unlock_bh_14((__int64)&v255[2 * ((v252 >> 18) & 0xF)]);
        }
LABEL_270:
        v226 = *(_QWORD *)(v10 + 224);
        v227 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 256) + 74392LL) + 536LL);
        if ( *((_DWORD *)v227 - 1) != 855462014 )
          __break(0x8228u);
        v228 = v227(v226);
        v229 = *(_QWORD *)(v10 + 40);
        v230 = v228 + (unsigned int)*((unsigned __int16 *)v4 + 316);
        if ( v229 )
          *(_QWORD *)(v10 + 40) = v229 + (unsigned int)v230;
        skb_pull(v10, v230);
LABEL_16:
        *(_BYTE *)(v10 + 75) = 1;
        *(_QWORD *)v10 = 0;
        v13 = *(unsigned int (__fastcall **)(__int64, __int64))(a2 + 160);
        if ( !v13 )
          goto LABEL_3;
        v14 = *(_QWORD *)(a2 + 88);
        if ( *((_DWORD *)v13 - 1) != 424933381 )
          __break(0x8228u);
        if ( v13(v14, v10) )
LABEL_3:
          _qdf_nbuf_free(v10);
        continue;
      }
      if ( v54 )
        goto LABEL_266;
      v243 = v8;
      v59 = (*(_DWORD *)(v10 + 72) >> 18) & 0xF;
      v60 = *(_QWORD *)(v4[1] + 256);
      v248 = *(_QWORD *)(v10 + 224);
      if ( v59 != *(unsigned __int8 *)(v42 + 144) )
      {
        v246 = (*(_DWORD *)(v10 + 72) >> 18) & 0xF;
        if ( *(_BYTE *)(v42 + 146) == 1 && v59 == *(unsigned __int8 *)(v42 + 145) )
        {
          if ( v4 )
          {
            v144 = 0;
            ++*((_DWORD *)v4 + 85);
            goto LABEL_152;
          }
        }
        else
        {
          v205 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v60 + 74392) + 816LL);
          if ( *((_DWORD *)v205 - 1) != 855462014 )
            __break(0x8228u);
          v206 = v205(v248);
          v207 = *(_QWORD *)(v60 + 74392);
          v208 = v206;
          v209 = *(__int64 (__fastcall **)(_QWORD))(v207 + 824);
          if ( *((_DWORD *)v209 - 1) != -1147376687 )
            __break(0x8228u);
          if ( (v209(v248) & 1) != 0 )
          {
            if ( v4 )
            {
              v144 = 0;
              ++*((_DWORD *)v4 + 82);
              goto LABEL_152;
            }
          }
          else if ( v208 == *(_DWORD *)(v42 + 240) )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: REO id mismatch flow: %pK napi_id: %u nbuf: %pK reo_id: %u",
              v210,
              v211,
              v212,
              v213,
              v214,
              v215,
              v216,
              v217,
              "dp_add_nbuf_to_fisa_flow",
              v42,
              *(unsigned __int8 *)(v42 + 144),
              v10,
              v246);
            if ( v4 )
            {
              v144 = 0;
              ++*((_DWORD *)v4 + 84);
              goto LABEL_152;
            }
          }
          else if ( v4 )
          {
            v144 = 0;
            ++*((_DWORD *)v4 + 83);
            goto LABEL_152;
          }
        }
        v144 = 0;
        goto LABEL_152;
      }
      if ( !v60 )
      {
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hal_rx_get_fisa_cumulative_ip_length");
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "hal_rx_get_fisa_flow_agg_continuation");
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "hal_rx_get_fisa_flow_agg_count");
        v79 = 0;
        v80 = 0;
LABEL_133:
        dp_rx_fisa_flush_flow(a2, v42);
        *(_WORD *)(v42 + 64) = 0;
        *(_DWORD *)(v42 + 60) = 0;
        *(_BYTE *)(v42 + 192) = 0;
        *(_WORD *)(v42 + 194) = 0;
        *(_DWORD *)(v42 + 216) = 0;
        should_stop = dp_fisa_aggregation_should_stop(v42, v79, v80, v248, v10);
        if ( (should_stop & 1) == 0 )
          goto LABEL_134;
        v8 = v243;
        v144 = 0;
        *(_BYTE *)(v42 + 192) = 1;
        goto LABEL_152;
      }
      v61 = *(_QWORD *)(v60 + 74392);
      if ( !v61 )
      {
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hal_rx_get_fisa_cumulative_ip_length");
LABEL_116:
        v245 = 0;
        goto LABEL_117;
      }
      v62 = *(__int64 (__fastcall **)(_QWORD))(v61 + 896);
      if ( !v62 )
        goto LABEL_116;
      if ( *((_DWORD *)v62 - 1) != 646946022 )
        __break(0x8228u);
      v245 = v62(v248);
LABEL_117:
      v81 = *(_QWORD *)(v60 + 74392);
      if ( v81 )
      {
        v82 = *(__int64 (__fastcall **)(_QWORD))(v81 + 912);
        if ( v82 )
        {
          if ( *((_DWORD *)v82 - 1) != -1147376687 )
            __break(0x8228u);
          v83 = v82(v248);
          goto LABEL_124;
        }
      }
      else
      {
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hal_rx_get_fisa_flow_agg_continuation");
      }
      v83 = 0;
LABEL_124:
      v84 = *(_QWORD *)(v60 + 74392);
      if ( v84 )
      {
        v85 = *(unsigned __int8 (__fastcall **)(_QWORD))(v84 + 920);
        if ( v85 )
        {
          v86 = v83;
          if ( *((_DWORD *)v85 - 1) != -1147376687 )
            __break(0x8228u);
          v87 = v85(v248);
          if ( (v86 & 1) == 0 )
          {
LABEL_132:
            v80 = v245;
            v79 = v87;
            goto LABEL_133;
          }
        }
        else
        {
          v87 = 0;
          if ( (v83 & 1) == 0 )
            goto LABEL_132;
        }
      }
      else
      {
        v98 = v83;
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: hal handle is NULL",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hal_rx_get_fisa_flow_agg_count");
        v87 = 0;
        if ( (v98 & 1) == 0 )
          goto LABEL_132;
      }
      v79 = v87;
      should_stop = dp_fisa_aggregation_should_stop(v42, v87, v245, v248, v10);
      if ( (should_stop & 1) == 0 )
      {
        LOWORD(v80) = v245;
        ++*(_WORD *)(v42 + 60);
LABEL_134:
        v99 = *(_DWORD *)(v42 + 188);
        v100 = *(_QWORD *)(v42 + 48);
        *(_DWORD *)(v42 + 216) = v79;
        *(_WORD *)(v42 + 194) = v80;
        *(_DWORD *)(v42 + 188) = v99 + 1;
        if ( v100 )
        {
          v101 = *(unsigned __int16 *)(v42 + 60);
          v8 = v243;
          v102 = v80 - (*(_WORD *)(v42 + 64) + 8 * v101);
          *(_WORD *)(v42 + 58) = v102;
          if ( v101 >= 0x10 )
          {
            should_stop = qdf_trace_msg(
                            0x45u,
                            2u,
                            "%s: HAL cumulative_ip_length %d",
                            v90,
                            v91,
                            v92,
                            v93,
                            v94,
                            v95,
                            v96,
                            v97,
                            "dp_add_nbuf_to_fisa_flow",
                            (unsigned __int16)v80);
            v102 = *(_WORD *)(v42 + 58);
          }
        }
        else
        {
          v103 = *(_WORD *)(v42 + 64);
          v8 = v243;
          *(_DWORD *)(v42 + 60) = 0;
          v102 = v80 - v103;
          *(_WORD *)(v42 + 58) = v102;
        }
        if ( v102 >= 0x5C61u )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: fisa_flow %pK nbuf %pK",
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            "dp_add_nbuf_to_fisa_flow",
            v42,
            v10);
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: fisa_flow->adjusted_cumulative_ip_length %d",
            v104,
            v105,
            v106,
            v107,
            v108,
            v109,
            v110,
            v111,
            "dp_add_nbuf_to_fisa_flow",
            *(unsigned __int16 *)(v42 + 58));
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: HAL cumulative_ip_length %d",
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            v119,
            "dp_add_nbuf_to_fisa_flow",
            (unsigned __int16)v80);
          should_stop = qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: napi_flush_cumulative_ip_length %d",
                          v120,
                          v121,
                          v122,
                          v123,
                          v124,
                          v125,
                          v126,
                          v127,
                          "dp_add_nbuf_to_fisa_flow",
                          *(unsigned __int16 *)(v42 + 64));
        }
        if ( *(_BYTE *)(v42 + 41) )
        {
          v128 = *(_QWORD *)(v10 + 224);
          v129 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v4[1] + 256) + 74392LL) + 536LL);
          v249 = *(_QWORD *)(v42 + 48);
          if ( *((_DWORD *)v129 - 1) != 855462014 )
            __break(0x8228u);
          v130 = v129(v128);
          v131 = *(_QWORD *)(v10 + 40);
          v132 = v130 + (unsigned int)*((unsigned __int16 *)v4 + 316);
          if ( v131 )
            *(_QWORD *)(v10 + 40) = v131 + (unsigned int)v132;
          LODWORD(v271) = 0;
          LODWORD(v265) = 0;
          skb_pull(v10, v132);
          v133 = *(__int64 (__fastcall **)(__int64, unsigned __int64 *, __int64 *))(*(_QWORD *)(*(_QWORD *)(v4[1] + 256)
                                                                                              + 74392LL)
                                                                                  + 1296LL);
          if ( *((_DWORD *)v133 - 1) != 348550285 )
            __break(0x8228u);
          should_stop = v133(v128, &v271, &v265);
          v134 = v271;
          v135 = v265;
          v136 = *(_QWORD *)(v10 + 224) + (int)v265 + (int)v271;
          v137 = bswap32(*(unsigned __int16 *)(v136 + 4)) >> 16;
          if ( v249 )
          {
            if ( v137 > bswap32(*(unsigned __int16 *)(*(_QWORD *)(v42 + 224) + 4LL)) >> 16 )
            {
              v138 = *(_WORD *)(v42 + 58);
              v139 = *(_WORD *)(v42 + 60);
              v140 = *(_QWORD *)(v42 + 152);
              v250 = v137;
              *(_WORD *)(v42 + 62) = *(_WORD *)(v42 + 56);
              v141 = *(_WORD *)(v42 + 194);
              *(_WORD *)(v42 + 60) = v139 - 1;
              *(_WORD *)(v42 + 58) = v138 - v137 + 8;
              *(_WORD *)(v42 + 64) = v141;
              should_stop = dp_rx_fisa_flush_flow(v140, v42);
              v137 = v250;
              v142 = *(_WORD *)(v42 + 64);
              v135 = v265;
              *(_WORD *)(v42 + 60) = 0;
              v143 = v142 - v250;
              v134 = v271;
              *(_WORD *)(v42 + 64) = v143;
              goto LABEL_150;
            }
            v147 = *(_QWORD *)(v10 + 40);
            v148 = v137;
            v149 = (unsigned int)(v265 + v271 + 8);
            if ( v147 )
              *(_QWORD *)(v10 + 40) = v147 + (unsigned int)v149;
            should_stop = skb_pull(v10, v149);
            if ( (*(_BYTE *)(v10 + 68) & 4) != 0 )
              v150 = *(unsigned __int16 *)(v10 + 66);
            else
              v150 = 0;
            v151 = *(_QWORD *)(v42 + 176) + (unsigned int)(*(_DWORD *)(v10 + 112) + v150);
            *(_WORD *)(v42 + 232) = v148 + *(_WORD *)(v42 + 232) - 8;
            *(_QWORD *)(v42 + 176) = v151;
            v152 = *(_QWORD *)(v249 + 216) + *(unsigned int *)(v249 + 212);
            if ( !*(_QWORD *)(v152 + 8) )
            {
              *(_QWORD *)(v152 + 8) = v10;
              *(_BYTE *)(v10 + 84) |= 0x80u;
              goto LABEL_169;
            }
            v153 = *(__int64 **)(v42 + 72);
            if ( v153 )
            {
              *v153 = v10;
LABEL_169:
              v154 = *(_DWORD *)(v42 + 188);
              v155 = *(_QWORD *)(v42 + 224);
              *(_QWORD *)(v42 + 72) = v10;
              *(_DWORD *)(v42 + 188) = v154 + 1;
              if ( v148 < bswap32(*(unsigned __int16 *)(v155 + 4)) >> 16 )
              {
                v156 = *(_WORD *)(v42 + 194);
                v157 = *(_QWORD *)(v42 + 152);
                *(_WORD *)(v42 + 62) = *(_WORD *)(v42 + 56);
                *(_WORD *)(v42 + 64) = v156;
                should_stop = dp_rx_fisa_flush_flow(v157, v42);
                *(_WORD *)(v42 + 60) = 0;
              }
            }
            else
            {
              should_stop = _qdf_nbuf_free(v10);
            }
          }
          else
          {
LABEL_150:
            *(_QWORD *)(v42 + 48) = v10;
            *(_QWORD *)(v42 + 224) = v136;
            *(_DWORD *)(v42 + 220) = v137 - 8;
            *(_WORD *)(v42 + 58) = v137;
            *(_DWORD *)(v42 + 80) = v134;
            *(_DWORD *)(v42 + 84) = v135;
            *(_WORD *)(v42 + 232) = 0;
          }
        }
        v144 = 1;
        *(_QWORD *)(v42 + 256) = sched_clock(should_stop, v89);
        goto LABEL_152;
      }
      dp_rx_fisa_flush_flow(a2, v42);
      v8 = v243;
      v144 = 0;
      *(_BYTE *)(v42 + 192) = 1;
      *(_WORD *)(v42 + 60) = 0;
      *(_WORD *)(v42 + 64) = 0;
LABEL_152:
      if ( *((_BYTE *)v4 + 608) != 1 )
        goto LABEL_156;
      if ( v253 >= 9 )
        goto LABEL_282;
      v145 = &v255[2 * ((v252 >> 18) & 0xF)];
      v146 = v145[1];
      if ( (v146 & 1) == 0 )
      {
        raw_spin_unlock(v145);
LABEL_156:
        if ( (v144 & 1) == 0 )
          goto LABEL_270;
        continue;
      }
      v145[1] = v146 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v145);
      if ( (v144 & 1) == 0 )
        goto LABEL_270;
    }
    while ( v5 );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
