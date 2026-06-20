__int64 __fastcall dp_tx_mon_ppdu_process(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v3; // x28
  __int64 v4; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x9
  __int64 v7; // x9
  int v8; // w9
  int v9; // w10
  __int64 v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x8
  __int64 v20; // x25
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 v24; // x9
  unsigned int v25; // w26
  __int64 v26; // x9
  __int64 v27; // x9
  unsigned int v28; // w8
  __int64 v29; // x10
  _DWORD *v30; // x9
  __int64 v31; // x24
  __int64 v32; // x21
  __int64 *v33; // x20
  __int64 v34; // x8
  unsigned __int64 v35; // x4
  __int64 v36; // x19
  __int64 v37; // x26
  __int64 v38; // x23
  __int64 v39; // x9
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 v43; // x9
  __int64 **v44; // x8
  unsigned int i; // w19
  __int64 *v46; // x9
  __int64 v47; // x10
  __int64 v48; // x9
  __int64 v49; // x10
  int v50; // w11
  __int64 **v51; // x12
  __int64 *v52; // x13
  __int64 v53; // x14
  _BYTE *v54; // x10
  __int64 v55; // x11
  int v56; // w9
  __int64 v57; // x27
  __int64 v58; // x8
  __int64 v59; // x9
  int v60; // w10
  __int64 **v61; // x11
  __int64 *v62; // x12
  __int64 v63; // x13
  _BYTE *v64; // x24
  __int64 v65; // x9
  __int64 v66; // x8
  int v67; // w9
  unsigned __int8 v68; // w8
  __int64 v69; // x9
  __int64 **v70; // x10
  char j; // w9
  __int64 *v72; // x11
  __int64 v73; // x12
  unsigned __int8 v74; // w22
  __int64 v75; // x8
  __int64 **v76; // x9
  int k; // w8
  __int64 *v78; // x10
  __int64 v79; // x11
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  int v88; // w8
  __int64 v89; // x9
  __int64 v90; // x8
  unsigned __int64 v91; // x24
  __int64 v92; // x19
  __int64 v93; // x19
  __int64 v94; // x27
  unsigned int v95; // w8
  unsigned int v102; // w10
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  unsigned int *v111; // x8
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  __int64 v120; // x8
  _DWORD **v121; // x8
  _DWORD *v122; // x8
  __int64 v123; // x0
  double v124; // d0
  unsigned int *v125; // x8
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned int v135; // w9
  __int64 v136; // x8
  __int64 v137; // x0
  unsigned int v138; // w8
  unsigned int v139; // w12
  __int64 v140; // x11
  unsigned int v141; // w9
  unsigned int v142; // w12
  __int64 v143; // x11
  unsigned __int64 v144; // [xsp+0h] [xbp-100h]
  __int64 v145; // [xsp+8h] [xbp-F8h]
  __int64 *v146; // [xsp+10h] [xbp-F0h]
  __int64 v147; // [xsp+18h] [xbp-E8h]
  __int64 v148; // [xsp+20h] [xbp-E0h]
  __int64 v149; // [xsp+28h] [xbp-D8h]
  __int64 v150; // [xsp+38h] [xbp-C8h]
  __int64 v151; // [xsp+40h] [xbp-C0h]
  unsigned int v152; // [xsp+48h] [xbp-B8h]
  __int16 v153; // [xsp+54h] [xbp-ACh] BYREF
  __int64 v154; // [xsp+58h] [xbp-A8h] BYREF
  __int64 v155; // [xsp+60h] [xbp-A0h]
  __int64 v156; // [xsp+68h] [xbp-98h]
  __int64 v157; // [xsp+70h] [xbp-90h]
  __int64 v158; // [xsp+78h] [xbp-88h]
  __int64 v159; // [xsp+80h] [xbp-80h]
  __int64 v160; // [xsp+88h] [xbp-78h]
  __int64 v161; // [xsp+90h] [xbp-70h]
  __int64 v162; // [xsp+98h] [xbp-68h]
  __int64 v163; // [xsp+A0h] [xbp-60h]
  __int64 v164; // [xsp+A8h] [xbp-58h]
  __int64 v165; // [xsp+B0h] [xbp-50h]
  __int64 v166; // [xsp+B8h] [xbp-48h]
  __int64 v167; // [xsp+C0h] [xbp-40h]
  __int64 v168; // [xsp+C8h] [xbp-38h]
  __int64 v169; // [xsp+D0h] [xbp-30h]
  __int64 v170; // [xsp+D8h] [xbp-28h]
  __int64 v171; // [xsp+E0h] [xbp-20h]
  __int64 v172; // [xsp+E8h] [xbp-18h]
  __int64 v173; // [xsp+F0h] [xbp-10h]

  v173 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)result;
  if ( !*(_QWORD *)result )
    goto LABEL_155;
  v3 = v2 + 94208;
  v4 = *(_QWORD *)(v2 + 96456);
  if ( !v4 )
    goto LABEL_155;
  if ( *(unsigned __int8 *)(result + 8) >= 3u )
  {
LABEL_157:
    __break(0x5512u);
  }
  else
  {
    v152 = *(unsigned __int8 *)(result + 8);
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
  v6 = *(_QWORD *)(v1 + 112);
  if ( v6 )
  {
    **(_QWORD **)(v1 + 144) = v6;
    v7 = *(_QWORD *)(v1 + 120);
    *(_QWORD *)(v1 + 112) = 0;
    *(_QWORD *)(v1 + 120) = v1 + 112;
    *(_QWORD *)(v1 + 144) = v7;
  }
  v8 = *(_DWORD *)(v1 + 104);
  v9 = *(_DWORD *)(v1 + 128);
  v10 = *(_QWORD *)(v1 + 40);
  *(_DWORD *)(v1 + 104) = 0;
  *(_DWORD *)(v1 + 128) = v9 + v8;
  if ( (v10 & 1) != 0 )
  {
    *(_QWORD *)(v1 + 40) = v10 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v1 + 32);
  }
  else
  {
    result = raw_spin_unlock(v1 + 32);
  }
  v19 = (__int64 *)(v1 + 136);
  v20 = *(_QWORD *)(v1 + 136);
  if ( v20 )
  {
    v144 = _ReadStatusReg(SP_EL0);
    v146 = (__int64 *)(v1 + 136);
    v147 = v1;
    v149 = v2;
    do
    {
      v21 = *v19;
      v22 = *(_QWORD *)(v20 + 8);
      if ( *v19 == v20 )
      {
        v26 = *(_QWORD *)(v21 + 8);
        *v19 = v26;
        if ( !v26 )
          goto LABEL_19;
      }
      else
      {
        do
        {
          v23 = v21;
          v21 = *(_QWORD *)(v21 + 8);
        }
        while ( v21 != v20 );
        v24 = *(_QWORD *)(v21 + 8);
        *(_QWORD *)(v23 + 8) = v24;
        v19 = (__int64 *)(v23 + 8);
        if ( !v24 )
LABEL_19:
          *(_QWORD *)(v1 + 144) = v19;
      }
      v148 = v22;
      --*(_DWORD *)(v1 + 128);
      v25 = *(_DWORD *)(v20 + 68);
      v150 = *(unsigned __int8 *)(v20 + 28);
      if ( !v25 )
      {
        if ( *(_WORD *)(v20 + 72) )
          goto LABEL_28;
        *(_DWORD *)(v20 + 68) = *(unsigned __int16 *)(v3 + 1658);
        goto LABEL_24;
      }
      if ( !*(_WORD *)(v20 + 72) )
      {
        if ( *(unsigned __int16 *)(v3 + 1658) != (unsigned __int16)v25 )
        {
          dp_tx_mon_update_channel_freq(v2, *(_QWORD *)(v2 + 8), v25);
          *(_WORD *)(v3 + 1658) = v25;
        }
LABEL_24:
        *(_WORD *)(v20 + 72) = *(unsigned __int8 *)(v3 + 1656);
      }
LABEL_28:
      v27 = *(_QWORD *)(v20 + 56);
      v28 = *(_DWORD *)(v20 + 64);
      v29 = *(_QWORD *)(v3 + 2248) + 2576LL * v152 + 39344;
      if ( v27 && v28 )
      {
        *(_QWORD *)(*(_QWORD *)(v3 + 2248) + 2576LL * v152 + 39832) = v27;
        v30 = (_DWORD *)(v29 + 496);
LABEL_31:
        *v30 = v28;
        v27 = *(_QWORD *)(v20 + 56);
        goto LABEL_32;
      }
      v139 = *(_DWORD *)(*(_QWORD *)(v3 + 2248) + 2576LL * v152 + 39840);
      if ( !v139 )
        goto LABEL_15;
      v140 = *(_QWORD *)(*(_QWORD *)(v3 + 2248) + 2576LL * v152 + 39832);
      if ( !v140 )
        goto LABEL_15;
      if ( !v27 && v28 )
      {
        v141 = v28 / 0x3C0;
        v142 = v139 / 0x3C0;
        if ( v142 >= v28 / 0x3C0 )
          v141 = v28 / 0x3C0 + 4473924;
        v143 = v140 + v141 - v142;
        v30 = (_DWORD *)(*(_QWORD *)(v3 + 2248) + 2576LL * v152 + 39840);
        *(_QWORD *)(v20 + 56) = v143;
        *(_QWORD *)(v29 + 488) = v143;
        goto LABEL_31;
      }
LABEL_32:
      if ( v27 || *(_DWORD *)(v20 + 64) )
      {
        *(_QWORD *)(v20 + 56) = v27
                              + *(unsigned int *)(v3 + 2268)
                              + ((unsigned __int64)*(unsigned int *)(v3 + 2272) << 32);
        if ( (_DWORD)v150 )
        {
          v31 = 0;
          v1 = v20 + 384;
          while ( 1 )
          {
            v32 = v1 + 344 * v31;
            v33 = (__int64 *)(v32 + 312);
            if ( v32 != -312 && *(_DWORD *)(v32 + 328) >= 2u )
            {
              *(_BYTE *)(v20 + 144) |= 1u;
              *(_QWORD *)v32 |= 0x40000000uLL;
            }
            if ( !*(_BYTE *)(v20 + 106) )
            {
              LODWORD(v154) = 0;
              v138 = *(_DWORD *)(v20 + 76);
              v153 = 0;
              *(_BYTE *)(v20 + 106) = dp_getrateindex(
                                        (v138 >> 21) & 3,
                                        *(_WORD *)v32 & 0xF,
                                        (unsigned __int16)v138 >> 13,
                                        (v138 >> 27) & 0xF,
                                        BYTE2(v138) & 0xF,
                                        0,
                                        (unsigned int *)&v154,
                                        &v153);
            }
            v34 = v1 + 344 * v31;
            v35 = *(unsigned __int8 *)(v34 + 306);
            if ( v35 >= 0xB )
              goto LABEL_157;
            *(_BYTE *)(v34 + 306) = encrypt_map_0[v35];
            qdf_trace_msg(
              0x92u,
              8u,
              "User: %d TLV enc_type = %d map enc_type = %d direction = %d",
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              (unsigned __int8)v31);
            v36 = *(_QWORD *)(v3 + 2248);
            v151 = v31;
            if ( !v31 && (*(_BYTE *)(v20 + 30) & 0xC) != 0 )
            {
              v137 = _qdf_mem_malloc(0x2D8u, "dp_tx_mon_send_per_usr_mpdu", 2023);
              if ( v137 )
                _qdf_mem_free(v137);
            }
            v37 = *v33;
            if ( *v33 )
              break;
LABEL_36:
            v1 = v20 + 384;
            v31 = v151 + 1;
            if ( v151 + 1 == v150 )
              goto LABEL_15;
          }
          v38 = v36 + 2576LL * v152 + 39344;
          while ( 2 )
          {
            v39 = *(_QWORD *)(v32 + 320);
            --*(_DWORD *)(v32 + 328);
            if ( v37 == v39 )
            {
              v40 = 0;
              *(_QWORD *)(v32 + 320) = 0;
            }
            else
            {
              v40 = *(_QWORD *)v37;
            }
            *v33 = v40;
            v41 = *(_QWORD *)(v37 + 216);
            v42 = *(unsigned int *)(v37 + 212);
            *(_QWORD *)v37 = 0;
            v43 = v41 + v42;
            v44 = *(__int64 ***)(v43 + 8);
            for ( i = *(unsigned __int8 *)(v43 + 2); v44; i += *((unsigned __int8 *)v46 + v47 + 2) )
            {
              v46 = v44[27];
              v47 = *((unsigned int *)v44 + 53);
              v44 = (__int64 **)*v44;
            }
            *(_QWORD *)(v20 + 368) = v32;
            if ( *(_BYTE *)(*(_QWORD *)(v3 + 2248) + 39317LL) == 1 )
            {
              v48 = *(_QWORD *)(v37 + 216) + *(unsigned int *)(v37 + 212);
              v49 = *(_QWORD *)(v48 + 8);
              v50 = *(unsigned __int8 *)(v48 + 2);
              if ( v49 )
              {
                v51 = *(__int64 ***)(v48 + 8);
                do
                {
                  v52 = v51[27];
                  v53 = *((unsigned int *)v51 + 53);
                  v51 = (__int64 **)*v51;
                  v50 += *((unsigned __int8 *)v52 + v53 + 2);
                }
                while ( v51 );
                if ( !v50 )
                {
                  v54 = *(_BYTE **)(v49 + 224);
                  goto LABEL_63;
                }
LABEL_60:
                v55 = *(_QWORD *)(v48 + 88);
                v54 = nullptr;
                if ( v55 && (v55 & 1) == 0 )
                  v54 = (_BYTE *)((((v55 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                                + *(unsigned int *)(v48 + 100));
LABEL_63:
                v56 = *v54 & 0xC;
                if ( v56 == 8 )
                {
                  if ( !*(_WORD *)(*(_QWORD *)(v3 + 2248) + 37078LL) )
                    break;
                }
                else if ( v56 == 4 )
                {
                  if ( !*(_WORD *)(*(_QWORD *)(v3 + 2248) + 37076LL) )
                    break;
                }
                else if ( (*v54 & 0xC) != 0 || !*(_WORD *)(*(_QWORD *)(v3 + 2248) + 37074LL) )
                {
                  break;
                }
                v57 = *(_QWORD *)(v20 + 368);
                v58 = *(_QWORD *)(v37 + 216) + *(unsigned int *)(v37 + 212);
                v59 = *(_QWORD *)(v58 + 8);
                v60 = *(unsigned __int8 *)(v58 + 2);
                if ( v59 )
                {
                  v61 = *(__int64 ***)(v58 + 8);
                  do
                  {
                    v62 = v61[27];
                    v63 = *((unsigned int *)v61 + 53);
                    v61 = (__int64 **)*v61;
                    v60 += *((unsigned __int8 *)v62 + v63 + 2);
                  }
                  while ( v61 );
                  if ( !v60 )
                  {
                    v64 = *(_BYTE **)(v59 + 224);
                    if ( !v64 )
                      goto LABEL_89;
LABEL_81:
                    if ( (*v64 & 0xB0) == 0x80 )
                    {
                      if ( *(_BYTE *)(v57 + 340) )
                        qdf_mem_copy(v64 + 25, (const void *)(v57 + 340), 1u);
                      v66 = 26;
                      if ( !*(_DWORD *)(v57 + 336) )
                      {
LABEL_89:
                        if ( (*(_BYTE *)(v37 + 68) & 4) != 0 )
                          v67 = *(unsigned __int16 *)(v37 + 66);
                        else
                          v67 = 0;
                        if ( (unsigned int)(*(_DWORD *)(v37 + 112) + v67) <= 0xFF )
                        {
                          v68 = *(_BYTE *)(*(_QWORD *)(v20 + 368) + 306LL) - 4;
                          if ( v68 <= 7u && ((0xF7u >> v68) & 1) != 0 )
                          {
                            v69 = *(_QWORD *)(v37 + 216) + *(unsigned int *)(v37 + 212);
                            v70 = *(__int64 ***)(v69 + 8);
                            for ( j = *(_BYTE *)(v69 + 2); v70; j += *((_BYTE *)v72 + v73 + 2) )
                            {
                              v72 = v70[27];
                              v73 = *((unsigned int *)v70 + 53);
                              v70 = (__int64 **)*v70;
                            }
                            if ( j )
                            {
                              if ( (j & 0xFE) != 0 )
                              {
                                v74 = j - 1;
                                if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))_qdf_nbuf_get_frag_size)(
                                                     v37,
                                                     (unsigned __int8)(j - 1)) < ((0x1010101010081008uLL >> (8 * (v68 & 0x1Fu)))
                                                                                & 0x18) )
                                  _qdf_nbuf_remove_frag(v37, v74, 0x800u);
                                v2 = v149;
                              }
                              v75 = *(_QWORD *)(v37 + 216) + *(unsigned int *)(v37 + 212);
                              v76 = *(__int64 ***)(v75 + 8);
                              for ( k = *(unsigned __int8 *)(v75 + 2); v76; k += *((unsigned __int8 *)v78 + v79 + 2) )
                              {
                                v78 = v76[27];
                                v79 = *((unsigned int *)v76 + 53);
                                v76 = (__int64 **)*v76;
                              }
                              skb_coalesce_rx_frag(v37, (unsigned __int8)(k - 1));
                            }
                          }
                        }
                        if ( (unsigned int)qdf_nbuf_update_radiotap(
                                             v20 + 56,
                                             v37,
                                             *(_DWORD *)(v37 + 224) - *(_DWORD *)(v37 + 216)) )
                        {
                          v88 = *(_DWORD *)v20;
                          v89 = *(_QWORD *)(v3 + 2248);
                          v171 = 0;
                          v172 = 0;
                          v170 = 0;
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
                          v154 = 0;
                          v155 = 0;
                          *(_QWORD *)(v89 + 2576LL * v152 + 39552) += i;
                          LODWORD(v89) = *(unsigned __int8 *)(v89 + 39317);
                          v171 = v37;
                          LOBYTE(v154) = 1;
                          LODWORD(v155) = v88;
                          if ( (_DWORD)v89 == 1 )
                          {
                            v90 = *(_QWORD *)(v3 + 2248) + 18528LL * v152;
                            v91 = *(unsigned __int8 *)(v90 + 9);
                            v92 = v90 + 8;
                            if ( v91 <= 5 )
                            {
                              v145 = v90 + 8;
                              v93 = *(_QWORD *)(v2 + 8);
                              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                                || (*(_DWORD *)(v144 + 16) & 0xF0000) != 0
                                || (*(_DWORD *)(v144 + 16) & 0xFF00) != 0 )
                              {
                                raw_spin_lock(v93 + 18984);
                              }
                              else
                              {
                                raw_spin_lock_bh(v93 + 18984);
                                *(_QWORD *)(v93 + 18992) |= 1uLL;
                              }
                              v94 = *(_QWORD *)(v93 + 8 * v91 + 12960);
                              if ( v94 )
                              {
                                v95 = *(_DWORD *)(v94 + 43384);
                                while ( v95 )
                                {
                                  _X12 = (unsigned int *)(v94 + 43384);
                                  __asm { PRFM            #0x11, [X12] }
                                  while ( 1 )
                                  {
                                    v102 = __ldxr(_X12);
                                    if ( v102 != v95 )
                                      break;
                                    if ( !__stlxr(v95 + 1, _X12) )
                                    {
                                      __dmb(0xBu);
                                      break;
                                    }
                                  }
                                  _ZF = v102 == v95;
                                  v95 = v102;
                                  if ( _ZF )
                                  {
                                    _X8 = (unsigned int *)(v94 + 43408);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v135 = __ldxr(_X8);
                                    while ( __stxr(v135 + 1, _X8) );
                                    v136 = *(_QWORD *)(v93 + 18992);
                                    if ( (v136 & 1) != 0 )
                                    {
                                      *(_QWORD *)(v93 + 18992) = v136 & 0xFFFFFFFFFFFFFFFELL;
                                      raw_spin_unlock_bh(v93 + 18984);
                                    }
                                    else
                                    {
                                      raw_spin_unlock(v93 + 18984);
                                    }
                                    v92 = v145;
                                    if ( *(_QWORD *)(v145 + 8) != v94 )
                                    {
                                      qdf_trace_msg(
                                        0x92u,
                                        2u,
                                        "%s: Monitor vdev is NULL or invalid!!",
                                        v103,
                                        v104,
                                        v105,
                                        v106,
                                        v107,
                                        v108,
                                        v109,
                                        v110,
                                        "dp_tx_handle_local_pkt_capture");
                                      dp_vdev_unref_delete(
                                        *(_QWORD *)(v2 + 8),
                                        v94,
                                        5u,
                                        v111,
                                        v112,
                                        v113,
                                        v114,
                                        v115,
                                        v116,
                                        v117,
                                        v118,
                                        v119);
                                      goto LABEL_133;
                                    }
                                    v121 = *(_DWORD ***)(v94 + 43520);
                                    if ( v121 )
                                    {
                                      v122 = *v121;
                                      if ( v122 )
                                      {
                                        v123 = *(_QWORD *)(v94 + 88);
                                        if ( *(v122 - 1) != 1866648346 )
                                          __break(0x8228u);
                                        v124 = ((double (__fastcall *)(__int64, __int64, _QWORD))v122)(v123, v37, 0);
                                        v125 = (unsigned int *)(unsigned int)(*(_DWORD *)(v145 + 18520) + 1);
                                        *(_DWORD *)(v145 + 18520) = (_DWORD)v125;
                                        dp_vdev_unref_delete(
                                          *(_QWORD *)(v2 + 8),
                                          v94,
                                          5u,
                                          v125,
                                          v124,
                                          v126,
                                          v127,
                                          v128,
                                          v129,
                                          v130,
                                          v131,
                                          v132);
                                        goto LABEL_47;
                                      }
                                    }
                                    goto LABEL_133;
                                  }
                                }
                              }
                              v120 = *(_QWORD *)(v93 + 18992);
                              if ( (v120 & 1) != 0 )
                              {
                                *(_QWORD *)(v93 + 18992) = v120 & 0xFFFFFFFFFFFFFFFELL;
                                raw_spin_unlock_bh(v93 + 18984);
                              }
                              else
                              {
                                raw_spin_unlock(v93 + 18984);
                              }
                              v92 = v145;
                            }
                            qdf_trace_msg(
                              0x92u,
                              2u,
                              "%s: Monitor vdev is NULL or invalid!!",
                              v80,
                              v81,
                              v82,
                              v83,
                              v84,
                              v85,
                              v86,
                              v87,
                              "dp_tx_handle_local_pkt_capture",
                              v144);
LABEL_133:
                            ++*(_DWORD *)(v92 + 18524);
LABEL_108:
                            _qdf_nbuf_free(v37);
                          }
                          else
                          {
                            dp_wdi_event_handler(
                              0x112u,
                              *(_QWORD *)(v2 + 8),
                              (__int64)&v154,
                              0xFFFFu,
                              0xFFFFFFFF,
                              *(_BYTE *)v2);
                            v37 = v171;
                            if ( v171 )
                              goto LABEL_108;
                          }
                        }
                        else
                        {
                          _qdf_nbuf_free(v37);
                          *(_QWORD *)(v38 + 216) += i;
                        }
LABEL_47:
                        v37 = *v33;
                        if ( !*v33 )
                          goto LABEL_36;
                        continue;
                      }
                    }
                    else
                    {
                      v66 = 24;
                      if ( !*(_DWORD *)(v57 + 336) )
                        goto LABEL_89;
                    }
                    if ( (char)v64[1] < 0 )
                      qdf_mem_copy(&v64[v66], (const void *)(v57 + 336), 4u);
                    goto LABEL_89;
                  }
                }
                else if ( !*(_BYTE *)(v58 + 2) )
                {
                  goto LABEL_89;
                }
                v65 = *(_QWORD *)(v58 + 88);
                if ( !v65 )
                  goto LABEL_89;
                if ( (v65 & 1) != 0 )
                  goto LABEL_89;
                v64 = (_BYTE *)((((v65 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                              + *(unsigned int *)(v58 + 100));
                if ( !v64 )
                  goto LABEL_89;
                goto LABEL_81;
              }
              if ( *(_BYTE *)(v48 + 2) )
                goto LABEL_60;
            }
            break;
          }
          _qdf_nbuf_free(v37);
          *(_QWORD *)(v38 + 200) += i;
          goto LABEL_47;
        }
      }
LABEL_15:
      v1 = v147;
      result = dp_tx_mon_free_ppdu_info(v20, v147);
      v19 = v146;
      v20 = v148;
    }
    while ( v148 );
  }
LABEL_155:
  _ReadStatusReg(SP_EL0);
  return result;
}
