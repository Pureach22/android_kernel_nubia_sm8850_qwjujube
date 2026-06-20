__int64 __fastcall dp_tx_mon_ppdu_process(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v3; // x23
  __int64 v4; // x8
  __int64 v5; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  int v9; // w9
  int v10; // w10
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x8
  __int64 v21; // x25
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x9
  unsigned int v25; // w26
  __int64 v26; // x9
  __int64 v27; // x10
  unsigned int v28; // w8
  __int64 v29; // x9
  _DWORD *v30; // x10
  __int64 v31; // x26
  __int64 v32; // x27
  __int64 v33; // x8
  __int64 v34; // x8
  unsigned __int64 v35; // x4
  __int64 v36; // x24
  __int64 v37; // x20
  __int64 v38; // x27
  __int64 v39; // x24
  __int64 v40; // x9
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x9
  __int64 **v45; // x8
  unsigned int i; // w19
  __int64 *v47; // x9
  __int64 v48; // x10
  __int64 v49; // x9
  __int64 v50; // x10
  int v51; // w11
  __int64 **v52; // x12
  __int64 *v53; // x13
  __int64 v54; // x14
  _BYTE *v55; // x10
  __int64 v56; // x11
  int v57; // w9
  __int64 v58; // x28
  __int64 v59; // x8
  __int64 v60; // x9
  int v61; // w10
  __int64 **v62; // x11
  __int64 *v63; // x12
  __int64 v64; // x13
  _BYTE *v65; // x26
  __int64 v66; // x9
  __int64 v67; // x8
  int v68; // w9
  unsigned __int8 v69; // w8
  __int64 v70; // x9
  __int64 **v71; // x10
  int j; // w9
  __int64 *v73; // x11
  __int64 v74; // x12
  __int64 v75; // x21
  unsigned __int8 v76; // w22
  __int64 v77; // x8
  __int64 **v78; // x9
  char k; // w8
  __int64 *v80; // x10
  __int64 v81; // x11
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x9
  int v91; // w8
  __int64 v92; // x8
  unsigned __int64 v93; // x26
  __int64 v94; // x19
  __int64 v95; // x19
  __int64 v96; // x28
  unsigned int v97; // w8
  unsigned int v104; // w10
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  unsigned int *v113; // x8
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x8
  _DWORD **v123; // x8
  _DWORD *v124; // x8
  __int64 v125; // x0
  double v126; // d0
  unsigned int *v127; // x8
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  unsigned int v137; // w9
  __int64 v138; // x8
  __int64 v139; // x0
  unsigned int v140; // w9
  unsigned int v141; // w12
  __int64 v142; // x11
  unsigned int v143; // w10
  unsigned int v144; // w12
  __int64 v145; // x11
  unsigned __int64 v146; // [xsp+0h] [xbp-100h]
  __int64 v147; // [xsp+8h] [xbp-F8h]
  __int64 *v148; // [xsp+10h] [xbp-F0h]
  __int64 v149; // [xsp+18h] [xbp-E8h]
  __int64 v150; // [xsp+20h] [xbp-E0h]
  __int64 v151; // [xsp+28h] [xbp-D8h]
  __int64 v152; // [xsp+38h] [xbp-C8h]
  __int64 v153; // [xsp+40h] [xbp-C0h]
  __int64 *v154; // [xsp+48h] [xbp-B8h]
  __int16 v155; // [xsp+54h] [xbp-ACh] BYREF
  __int64 v156; // [xsp+58h] [xbp-A8h] BYREF
  __int64 v157; // [xsp+60h] [xbp-A0h]
  __int64 v158; // [xsp+68h] [xbp-98h]
  __int64 v159; // [xsp+70h] [xbp-90h]
  __int64 v160; // [xsp+78h] [xbp-88h]
  __int64 v161; // [xsp+80h] [xbp-80h]
  __int64 v162; // [xsp+88h] [xbp-78h]
  __int64 v163; // [xsp+90h] [xbp-70h]
  __int64 v164; // [xsp+98h] [xbp-68h]
  __int64 v165; // [xsp+A0h] [xbp-60h]
  __int64 v166; // [xsp+A8h] [xbp-58h]
  __int64 v167; // [xsp+B0h] [xbp-50h]
  __int64 v168; // [xsp+B8h] [xbp-48h]
  __int64 v169; // [xsp+C0h] [xbp-40h]
  __int64 v170; // [xsp+C8h] [xbp-38h]
  __int64 v171; // [xsp+D0h] [xbp-30h]
  __int64 v172; // [xsp+D8h] [xbp-28h]
  __int64 v173; // [xsp+E0h] [xbp-20h]
  __int64 v174; // [xsp+E8h] [xbp-18h]
  __int64 v175; // [xsp+F0h] [xbp-10h]

  v175 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)result;
  if ( !*(_QWORD *)result )
    goto LABEL_155;
  v3 = v2 + 94208;
  v4 = *(_QWORD *)(v2 + 95560);
  if ( !v4 )
    goto LABEL_155;
  v5 = *(unsigned __int8 *)(result + 8);
  if ( (unsigned int)v5 >= 3 )
  {
LABEL_157:
    __break(0x5512u);
  }
  else
  {
    v1 = v4 + 2576LL * *(unsigned __int8 *)(result + 8) + 39344;
    if ( !*(_DWORD *)(v4 + 2576LL * *(unsigned __int8 *)(result + 8) + 39352) )
      goto LABEL_155;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v1 + 32);
      goto LABEL_9;
    }
  }
  raw_spin_lock_bh(v1 + 32);
  *(_QWORD *)(v1 + 40) |= 1uLL;
LABEL_9:
  v7 = *(_QWORD *)(v1 + 112);
  if ( v7 )
  {
    **(_QWORD **)(v1 + 144) = v7;
    v8 = *(_QWORD *)(v1 + 120);
    *(_QWORD *)(v1 + 112) = 0;
    *(_QWORD *)(v1 + 120) = v1 + 112;
    *(_QWORD *)(v1 + 144) = v8;
  }
  v9 = *(_DWORD *)(v1 + 104);
  v10 = *(_DWORD *)(v1 + 128);
  v11 = *(_QWORD *)(v1 + 40);
  *(_DWORD *)(v1 + 104) = 0;
  *(_DWORD *)(v1 + 128) = v10 + v9;
  if ( (v11 & 1) != 0 )
  {
    *(_QWORD *)(v1 + 40) = v11 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v1 + 32);
  }
  else
  {
    result = raw_spin_unlock(v1 + 32);
  }
  v20 = (__int64 *)(v1 + 136);
  v21 = *(_QWORD *)(v1 + 136);
  if ( v21 )
  {
    v146 = _ReadStatusReg(SP_EL0);
    v148 = (__int64 *)(v1 + 136);
    v149 = v1;
    v151 = v5;
    do
    {
      v22 = *v20;
      v150 = *(_QWORD *)(v21 + 8);
      if ( *v20 == v21 )
      {
        v26 = *(_QWORD *)(v22 + 8);
        *v20 = v26;
        if ( !v26 )
          goto LABEL_19;
      }
      else
      {
        do
        {
          v23 = v22;
          v22 = *(_QWORD *)(v22 + 8);
        }
        while ( v22 != v21 );
        v24 = *(_QWORD *)(v22 + 8);
        *(_QWORD *)(v23 + 8) = v24;
        v20 = (__int64 *)(v23 + 8);
        if ( !v24 )
LABEL_19:
          *(_QWORD *)(v1 + 144) = v20;
      }
      --*(_DWORD *)(v1 + 128);
      v25 = *(_DWORD *)(v21 + 68);
      v152 = *(unsigned __int8 *)(v21 + 28);
      if ( !v25 )
      {
        if ( *(_WORD *)(v21 + 72) )
          goto LABEL_28;
        *(_DWORD *)(v21 + 68) = *(unsigned __int16 *)(v3 + 762);
        goto LABEL_24;
      }
      if ( !*(_WORD *)(v21 + 72) )
      {
        if ( *(unsigned __int16 *)(v3 + 762) != (unsigned __int16)v25 )
        {
          dp_tx_mon_update_channel_freq(v2, *(_QWORD *)(v2 + 8), v25);
          *(_WORD *)(v3 + 762) = v25;
        }
LABEL_24:
        *(_WORD *)(v21 + 72) = *(unsigned __int8 *)(v3 + 760);
      }
LABEL_28:
      v27 = *(_QWORD *)(v21 + 56);
      v154 = (__int64 *)(v21 + 56);
      v28 = *(_DWORD *)(v21 + 64);
      v29 = *(_QWORD *)(v3 + 1352) + 2576LL * (unsigned int)v5 + 39344;
      if ( v27 && v28 )
      {
        *(_QWORD *)(*(_QWORD *)(v3 + 1352) + 2576LL * (unsigned int)v5 + 39832) = v27;
        v30 = (_DWORD *)(v29 + 496);
LABEL_31:
        *v30 = v28;
        v27 = *v154;
        goto LABEL_32;
      }
      v141 = *(_DWORD *)(*(_QWORD *)(v3 + 1352) + 2576LL * (unsigned int)v5 + 39840);
      if ( !v141 )
        goto LABEL_15;
      v142 = *(_QWORD *)(*(_QWORD *)(v3 + 1352) + 2576LL * (unsigned int)v5 + 39832);
      if ( !v142 )
        goto LABEL_15;
      if ( !v27 && v28 )
      {
        v143 = v28 / 0x3C0;
        v144 = v141 / 0x3C0;
        if ( v144 >= v28 / 0x3C0 )
          v143 = v28 / 0x3C0 + 4473924;
        v145 = v142 + v143 - v144;
        *v154 = v145;
        v30 = (_DWORD *)(v29 + 496);
        *(_QWORD *)(v29 + 488) = v145;
        goto LABEL_31;
      }
LABEL_32:
      if ( (v27 || *(_DWORD *)(v21 + 64)) && (_DWORD)v152 )
      {
        v31 = 0;
        v32 = v21 + 384;
        while ( 1 )
        {
          v33 = v32 + 344 * v31;
          if ( v33 != -312 && *(_DWORD *)(v33 + 328) >= 2u )
          {
            *(_BYTE *)(v21 + 144) |= 1u;
            *(_QWORD *)v33 |= 0x40000000uLL;
          }
          if ( !*(_BYTE *)(v21 + 106) )
          {
            LODWORD(v156) = 0;
            v140 = *(_DWORD *)(v21 + 76);
            v155 = 0;
            *(_BYTE *)(v21 + 106) = dp_getrateindex(
                                      (v140 >> 21) & 3,
                                      *(_WORD *)v33 & 0xF,
                                      (unsigned __int16)v140 >> 13,
                                      (v140 >> 27) & 0xF,
                                      BYTE2(v140) & 0xF,
                                      0,
                                      (unsigned int *)&v156,
                                      &v155);
          }
          v1 = (unsigned __int8)v31;
          v34 = v32 + 344LL * (unsigned __int8)v31;
          v35 = *(unsigned __int8 *)(v34 + 306);
          if ( v35 >= 0xB )
            goto LABEL_157;
          *(_BYTE *)(v34 + 306) = encrypt_map_0[v35];
          qdf_trace_msg(
            0x92u,
            8u,
            "User: %d TLV enc_type = %d map enc_type = %d direction = %d",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            (unsigned __int8)v31);
          v36 = *(_QWORD *)(v3 + 1352);
          v153 = v31;
          if ( !v31 && (*(_BYTE *)(v21 + 30) & 0xC) != 0 )
          {
            v139 = _qdf_mem_malloc(0x2D8u, "dp_tx_mon_send_per_usr_mpdu", 2023);
            if ( v139 )
              _qdf_mem_free(v139);
          }
          v37 = v32 + 344LL * (unsigned __int8)v31;
          v38 = *(_QWORD *)(v37 + 312);
          if ( v38 )
            break;
LABEL_36:
          v32 = v21 + 384;
          v31 = v153 + 1;
          if ( v153 + 1 == v152 )
            goto LABEL_15;
        }
        v39 = v36 + 2576LL * (unsigned int)v5 + 39344;
        while ( 2 )
        {
          v40 = *(_QWORD *)(v37 + 320);
          --*(_DWORD *)(v37 + 328);
          if ( v38 == v40 )
          {
            v41 = 0;
            *(_QWORD *)(v37 + 320) = 0;
          }
          else
          {
            v41 = *(_QWORD *)v38;
          }
          *(_QWORD *)(v37 + 312) = v41;
          v42 = *(_QWORD *)(v38 + 216);
          v43 = *(unsigned int *)(v38 + 212);
          *(_QWORD *)v38 = 0;
          v44 = v42 + v43;
          v45 = *(__int64 ***)(v44 + 8);
          for ( i = *(unsigned __int8 *)(v44 + 2); v45; i += *((unsigned __int8 *)v47 + v48 + 2) )
          {
            v47 = v45[27];
            v48 = *((unsigned int *)v45 + 53);
            v45 = (__int64 **)*v45;
          }
          *(_QWORD *)(v21 + 368) = v37;
          if ( *(_BYTE *)(*(_QWORD *)(v3 + 1352) + 39317LL) == 1 )
          {
            v49 = *(_QWORD *)(v38 + 216) + *(unsigned int *)(v38 + 212);
            v50 = *(_QWORD *)(v49 + 8);
            v51 = *(unsigned __int8 *)(v49 + 2);
            if ( v50 )
            {
              v52 = *(__int64 ***)(v49 + 8);
              do
              {
                v53 = v52[27];
                v54 = *((unsigned int *)v52 + 53);
                v52 = (__int64 **)*v52;
                v51 += *((unsigned __int8 *)v53 + v54 + 2);
              }
              while ( v52 );
              if ( !v51 )
              {
                v55 = *(_BYTE **)(v50 + 224);
                goto LABEL_63;
              }
LABEL_60:
              v56 = *(_QWORD *)(v49 + 88);
              v55 = nullptr;
              if ( v56 && (v56 & 1) == 0 )
                v55 = (_BYTE *)((((v56 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                              + *(unsigned int *)(v49 + 100));
LABEL_63:
              v57 = *v55 & 0xC;
              if ( v57 == 8 )
              {
                if ( !*(_WORD *)(*(_QWORD *)(v3 + 1352) + 37078LL) )
                  break;
              }
              else if ( v57 == 4 )
              {
                if ( !*(_WORD *)(*(_QWORD *)(v3 + 1352) + 37076LL) )
                  break;
              }
              else if ( (*v55 & 0xC) != 0 || !*(_WORD *)(*(_QWORD *)(v3 + 1352) + 37074LL) )
              {
                break;
              }
              v58 = *(_QWORD *)(v21 + 368);
              v59 = *(_QWORD *)(v38 + 216) + *(unsigned int *)(v38 + 212);
              v60 = *(_QWORD *)(v59 + 8);
              v61 = *(unsigned __int8 *)(v59 + 2);
              if ( v60 )
              {
                v62 = *(__int64 ***)(v59 + 8);
                do
                {
                  v63 = v62[27];
                  v64 = *((unsigned int *)v62 + 53);
                  v62 = (__int64 **)*v62;
                  v61 += *((unsigned __int8 *)v63 + v64 + 2);
                }
                while ( v62 );
                if ( !v61 )
                {
                  v65 = *(_BYTE **)(v60 + 224);
                  if ( !v65 )
                    goto LABEL_89;
LABEL_81:
                  if ( (*v65 & 0xB0) == 0x80 )
                  {
                    if ( *(_BYTE *)(v58 + 340) )
                      qdf_mem_copy(v65 + 25, (const void *)(v58 + 340), 1u);
                    v67 = 26;
                    if ( !*(_DWORD *)(v58 + 336) )
                    {
LABEL_89:
                      if ( (*(_BYTE *)(v38 + 68) & 4) != 0 )
                        v68 = *(unsigned __int16 *)(v38 + 66);
                      else
                        v68 = 0;
                      if ( (unsigned int)(*(_DWORD *)(v38 + 112) + v68) <= 0xFF )
                      {
                        v69 = *(_BYTE *)(*(_QWORD *)(v21 + 368) + 306LL) - 4;
                        if ( v69 <= 7u && ((0xF7u >> v69) & 1) != 0 )
                        {
                          v70 = *(_QWORD *)(v38 + 216) + *(unsigned int *)(v38 + 212);
                          v71 = *(__int64 ***)(v70 + 8);
                          for ( j = *(unsigned __int8 *)(v70 + 2); v71; j += *((unsigned __int8 *)v73 + v74 + 2) )
                          {
                            v73 = v71[27];
                            v74 = *((unsigned int *)v71 + 53);
                            v71 = (__int64 **)*v71;
                          }
                          if ( (_BYTE)j )
                          {
                            if ( (j & 0xFE) != 0 )
                            {
                              v75 = v2;
                              v76 = j - 1;
                              if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))_qdf_nbuf_get_frag_size)(
                                                   v38,
                                                   (unsigned __int8)(j - 1)) < ((0x1010101010081008uLL >> (8 * (v69 & 0x1Fu)))
                                                                              & 0x18) )
                                _qdf_nbuf_remove_frag(v38, v76, 0x800u);
                              v2 = v75;
                              v5 = v151;
                            }
                            v77 = *(_QWORD *)(v38 + 216) + *(unsigned int *)(v38 + 212);
                            v78 = *(__int64 ***)(v77 + 8);
                            for ( k = *(_BYTE *)(v77 + 2); v78; k += *((_BYTE *)v80 + v81 + 2) )
                            {
                              v80 = v78[27];
                              v81 = *((unsigned int *)v78 + 53);
                              v78 = (__int64 **)*v78;
                            }
                            skb_coalesce_rx_frag(v38, (unsigned __int8)(k - 1));
                          }
                        }
                      }
                      if ( (unsigned int)qdf_nbuf_update_radiotap(
                                           (__int64)v154,
                                           v38,
                                           *(_DWORD *)(v38 + 224) - *(_DWORD *)(v38 + 216)) )
                      {
                        v90 = *(_QWORD *)(v3 + 1352);
                        v91 = *(_DWORD *)v21;
                        v173 = 0;
                        v174 = 0;
                        v172 = 0;
                        v170 = 0;
                        v171 = 0;
                        v168 = 0;
                        v169 = 0;
                        v166 = 0;
                        v167 = 0;
                        v164 = 0;
                        v165 = 0;
                        v162 = 0;
                        v163 = 0;
                        v160 = 0;
                        v161 = 0;
                        v158 = 0;
                        v159 = 0;
                        v156 = 0;
                        v157 = 0;
                        *(_QWORD *)(v90 + 2576LL * (unsigned int)v5 + 39552) += i;
                        LODWORD(v90) = *(unsigned __int8 *)(v90 + 39317);
                        v173 = v38;
                        LOBYTE(v156) = 1;
                        LODWORD(v157) = v91;
                        if ( (_DWORD)v90 == 1 )
                        {
                          v92 = *(_QWORD *)(v3 + 1352) + 18528LL * (unsigned int)v5;
                          v93 = *(unsigned __int8 *)(v92 + 9);
                          v94 = v92 + 8;
                          if ( v93 <= 5 )
                          {
                            v147 = v92 + 8;
                            v95 = *(_QWORD *)(v2 + 8);
                            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                              || (*(_DWORD *)(v146 + 16) & 0xF0000) != 0
                              || (*(_DWORD *)(v146 + 16) & 0xFF00) != 0 )
                            {
                              raw_spin_lock(v95 + 18928);
                            }
                            else
                            {
                              raw_spin_lock_bh(v95 + 18928);
                              *(_QWORD *)(v95 + 18936) |= 1uLL;
                            }
                            v96 = *(_QWORD *)(v95 + 8 * v93 + 12912);
                            if ( v96 )
                            {
                              v97 = *(_DWORD *)(v96 + 42560);
                              while ( v97 )
                              {
                                _X12 = (unsigned int *)(v96 + 42560);
                                __asm { PRFM            #0x11, [X12] }
                                while ( 1 )
                                {
                                  v104 = __ldxr(_X12);
                                  if ( v104 != v97 )
                                    break;
                                  if ( !__stlxr(v97 + 1, _X12) )
                                  {
                                    __dmb(0xBu);
                                    break;
                                  }
                                }
                                _ZF = v104 == v97;
                                v97 = v104;
                                if ( _ZF )
                                {
                                  _X8 = (unsigned int *)(v96 + 42584);
                                  __asm { PRFM            #0x11, [X8] }
                                  do
                                    v137 = __ldxr(_X8);
                                  while ( __stxr(v137 + 1, _X8) );
                                  v138 = *(_QWORD *)(v95 + 18936);
                                  if ( (v138 & 1) != 0 )
                                  {
                                    *(_QWORD *)(v95 + 18936) = v138 & 0xFFFFFFFFFFFFFFFELL;
                                    raw_spin_unlock_bh(v95 + 18928);
                                  }
                                  else
                                  {
                                    raw_spin_unlock(v95 + 18928);
                                  }
                                  v94 = v147;
                                  if ( *(_QWORD *)(v147 + 8) != v96 )
                                  {
                                    qdf_trace_msg(
                                      0x92u,
                                      2u,
                                      "%s: Monitor vdev is NULL or invalid!!",
                                      v105,
                                      v106,
                                      v107,
                                      v108,
                                      v109,
                                      v110,
                                      v111,
                                      v112,
                                      "dp_tx_handle_local_pkt_capture");
                                    dp_vdev_unref_delete(
                                      *(_QWORD *)(v2 + 8),
                                      v96,
                                      5u,
                                      v113,
                                      v114,
                                      v115,
                                      v116,
                                      v117,
                                      v118,
                                      v119,
                                      v120,
                                      v121);
                                    goto LABEL_133;
                                  }
                                  v123 = *(_DWORD ***)(v96 + 42696);
                                  if ( v123 )
                                  {
                                    v124 = *v123;
                                    if ( v124 )
                                    {
                                      v125 = *(_QWORD *)(v96 + 88);
                                      if ( *(v124 - 1) != 1866648346 )
                                        __break(0x8228u);
                                      v126 = ((double (__fastcall *)(__int64, __int64, _QWORD))v124)(v125, v38, 0);
                                      v127 = (unsigned int *)(unsigned int)(*(_DWORD *)(v147 + 18520) + 1);
                                      *(_DWORD *)(v147 + 18520) = (_DWORD)v127;
                                      dp_vdev_unref_delete(
                                        *(_QWORD *)(v2 + 8),
                                        v96,
                                        5u,
                                        v127,
                                        v126,
                                        v128,
                                        v129,
                                        v130,
                                        v131,
                                        v132,
                                        v133,
                                        v134);
                                      goto LABEL_47;
                                    }
                                  }
                                  goto LABEL_133;
                                }
                              }
                            }
                            v122 = *(_QWORD *)(v95 + 18936);
                            if ( (v122 & 1) != 0 )
                            {
                              *(_QWORD *)(v95 + 18936) = v122 & 0xFFFFFFFFFFFFFFFELL;
                              raw_spin_unlock_bh(v95 + 18928);
                            }
                            else
                            {
                              raw_spin_unlock(v95 + 18928);
                            }
                            v94 = v147;
                          }
                          qdf_trace_msg(
                            0x92u,
                            2u,
                            "%s: Monitor vdev is NULL or invalid!!",
                            v82,
                            v83,
                            v84,
                            v85,
                            v86,
                            v87,
                            v88,
                            v89,
                            "dp_tx_handle_local_pkt_capture",
                            v146);
LABEL_133:
                          ++*(_DWORD *)(v94 + 18524);
LABEL_108:
                          _qdf_nbuf_free(v38);
                        }
                        else
                        {
                          dp_wdi_event_handler(
                            0x112u,
                            *(_QWORD *)(v2 + 8),
                            (__int64)&v156,
                            0xFFFFu,
                            0xFFFFFFFF,
                            *(_BYTE *)v2);
                          v38 = v173;
                          if ( v173 )
                            goto LABEL_108;
                        }
                      }
                      else
                      {
                        _qdf_nbuf_free(v38);
                        *(_QWORD *)(v39 + 216) += i;
                      }
LABEL_47:
                      v38 = *(_QWORD *)(v37 + 312);
                      if ( !v38 )
                        goto LABEL_36;
                      continue;
                    }
                  }
                  else
                  {
                    v67 = 24;
                    if ( !*(_DWORD *)(v58 + 336) )
                      goto LABEL_89;
                  }
                  if ( (char)v65[1] < 0 )
                    qdf_mem_copy(&v65[v67], (const void *)(v58 + 336), 4u);
                  goto LABEL_89;
                }
              }
              else if ( !*(_BYTE *)(v59 + 2) )
              {
                goto LABEL_89;
              }
              v66 = *(_QWORD *)(v59 + 88);
              if ( !v66 )
                goto LABEL_89;
              if ( (v66 & 1) != 0 )
                goto LABEL_89;
              v65 = (_BYTE *)((((v66 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                            + *(unsigned int *)(v59 + 100));
              if ( !v65 )
                goto LABEL_89;
              goto LABEL_81;
            }
            if ( *(_BYTE *)(v49 + 2) )
              goto LABEL_60;
          }
          break;
        }
        _qdf_nbuf_free(v38);
        *(_QWORD *)(v39 + 200) += i;
        goto LABEL_47;
      }
LABEL_15:
      v1 = v149;
      result = dp_tx_mon_free_ppdu_info(v21, v149);
      v20 = v148;
      v21 = v150;
    }
    while ( v150 );
  }
LABEL_155:
  _ReadStatusReg(SP_EL0);
  return result;
}
