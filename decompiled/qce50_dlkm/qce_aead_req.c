__int64 __fastcall qce_aead_req(__int64 a1, __int64 a2)
{
  __int64 v4; // x26
  __int64 v5; // x28
  unsigned int v6; // w23
  unsigned int v7; // w0
  __int64 v8; // x21
  int v10; // w8
  int v11; // w24
  unsigned int v12; // w0
  __int64 v13; // x2
  __int64 v14; // x25
  int v15; // w9
  int v16; // w8
  __int64 result; // x0
  int v18; // w9
  __int64 v19; // x0
  int v20; // w26
  int v21; // w23
  int v22; // w26
  __int64 v23; // x0
  int v24; // w9
  __int64 v25; // x16
  _QWORD *v26; // x1
  int v28; // w24
  int v29; // w10
  __int64 v30; // x2
  int v31; // w3
  int v32; // w8
  __int64 v33; // x8
  int v34; // w26
  __int64 v35; // x0
  int v36; // w23
  __int64 v37; // x26
  __int64 v38; // x27
  __int64 v39; // x0
  __int64 v40; // x26
  __int64 v41; // x25
  _BOOL4 v42; // w27
  __int64 v43; // x28
  unsigned int v44; // w28
  unsigned int v45; // w24
  int v46; // w26
  int v47; // w23
  __int64 v48; // x26
  __int64 v49; // x27
  int v50; // w8
  __int64 v51; // x2
  int v52; // w3
  __int64 v54; // x8
  __int64 v55; // x9
  __int64 v56; // x9
  __int64 v57; // x26
  __int64 v58; // x8
  int v59; // w9
  int v60; // w9
  __int64 v61; // x8
  _DWORD *v62; // x11
  unsigned __int64 v63; // x8
  int v64; // w9
  __int64 v65; // x2
  __int64 v66; // x2
  int v67; // w8
  __int64 v68; // x8
  unsigned __int64 v70; // x8
  _DWORD *v71; // x9
  int v72; // w10
  __int64 v73; // x2
  unsigned int v74; // w8
  _DWORD *v75; // x9
  unsigned __int64 v76; // x10
  __int64 v77; // x13
  __int64 v78; // x8
  unsigned __int64 v79; // x8
  _DWORD *v80; // x9
  int v81; // w10
  unsigned int v82; // w8
  unsigned __int64 v83; // x12
  _DWORD *v84; // x9
  unsigned __int64 v85; // x10
  __int64 v86; // x13
  int v87; // w8
  int v88; // w8
  int v89; // w8
  int v90; // w8
  int v91; // w8
  unsigned int *v92; // x8
  __int64 v93; // x0
  unsigned int v94; // w1
  unsigned int v95; // w8
  __int64 v96; // x10
  int v97; // w8
  __int64 v98; // x9
  __int64 v99; // x9
  int v100; // w12
  int v101; // w12
  unsigned int v102; // w11
  unsigned int v103; // w9
  __int64 v104; // x13
  unsigned int v105; // w10
  char v106; // w10
  unsigned __int8 *v107; // x12
  char v108; // w13
  char *v109; // x14
  unsigned int v114; // w9
  unsigned int v115; // w13
  unsigned int v116; // w20
  const char *v117; // x1
  unsigned int v118; // w21
  int v119; // w24
  unsigned int v120; // w26
  __int64 v121; // x23
  __int64 v122; // x20
  __int64 v123; // x20
  __int64 v124; // x23
  int v125; // w27
  _BOOL4 v126; // w24
  __int64 v127; // x20
  int v128; // w23
  __int64 v129; // x19
  unsigned int v131; // w9
  int v132; // w11
  int v133; // w11
  int v134; // w13
  _DWORD *v135; // x11
  int v136; // w12
  unsigned int v137; // w10
  unsigned __int8 *v138; // x13
  int *v139; // x11
  unsigned __int64 v140; // x12
  unsigned int v141; // w14
  int v142; // w14
  int v143; // w13
  _DWORD *v144; // x9
  int *v145; // x9
  unsigned int v146; // w12
  unsigned __int8 *v147; // x11
  unsigned __int64 v148; // x10
  unsigned int v149; // w13
  int v150; // w12
  int v151; // w11
  int v152; // w11
  _DWORD *v153; // x9
  int v154; // w11
  int v155; // w11
  int v156; // w11
  int v157; // w11
  int v158; // w11
  int v159; // w11
  int v160; // w11
  _DWORD *v161; // x9
  int v162; // w10
  int v163; // w11
  int v164; // w12
  int v165; // w13
  int v166; // w14
  __int64 v167; // x9
  __int64 v168; // x9
  unsigned int v169; // w10
  unsigned int v170; // w27
  __int64 v171; // x0
  int v172; // w28
  unsigned int v173; // w21
  __int64 v175; // x0
  __int64 v176; // x24
  _BOOL4 v177; // w25
  __int64 v178; // x26
  int v179; // w24
  int v180; // w26
  __int64 v181; // x24
  __int64 v182; // x25
  __int64 v183; // x8
  int v184; // w9
  __int64 v185; // x8
  int v186; // w9
  unsigned __int64 v187; // x8
  _DWORD *v188; // x11
  int v189; // w9
  __int64 v190; // x2
  int v191; // w9
  int v192; // w8
  __int64 v193; // x8
  int v194; // w9
  int v195; // w8
  int v196; // w10
  __int64 v197; // x9
  int v198; // w8
  __int64 v199; // x8
  int v200; // w8
  int v201; // w26
  __int64 v202; // x20
  __int64 v203; // x23
  unsigned int v204; // w25
  _BOOL4 v205; // w24
  __int64 v206; // x20
  int v207; // w23
  __int64 v208; // x19
  unsigned int v210; // w9
  unsigned int v212; // w10
  unsigned int v214; // w10
  unsigned int v215; // [xsp+8h] [xbp-C8h]
  _QWORD *v216; // [xsp+8h] [xbp-C8h]
  unsigned int *v217; // [xsp+10h] [xbp-C0h]
  unsigned int v218; // [xsp+18h] [xbp-B8h]
  unsigned int v219; // [xsp+20h] [xbp-B0h]
  unsigned int v220; // [xsp+28h] [xbp-A8h]
  __int64 v221; // [xsp+28h] [xbp-A8h]
  __int64 v222; // [xsp+30h] [xbp-A0h] BYREF
  __int64 v223; // [xsp+38h] [xbp-98h] BYREF
  __int64 v224; // [xsp+40h] [xbp-90h] BYREF
  __int64 v225; // [xsp+48h] [xbp-88h]
  __int64 v226; // [xsp+50h] [xbp-80h]
  __int64 v227; // [xsp+58h] [xbp-78h]
  __int64 v228; // [xsp+60h] [xbp-70h]
  __int64 v229; // [xsp+68h] [xbp-68h]
  __int64 v230; // [xsp+70h] [xbp-60h]
  __int64 v231; // [xsp+78h] [xbp-58h]
  __int64 v232; // [xsp+80h] [xbp-50h] BYREF
  __int64 v233; // [xsp+88h] [xbp-48h]
  __int64 v234; // [xsp+90h] [xbp-40h]
  __int64 v235; // [xsp+98h] [xbp-38h]
  __int64 v236; // [xsp+A0h] [xbp-30h]
  __int64 v237; // [xsp+A8h] [xbp-28h]
  __int64 v238; // [xsp+B0h] [xbp-20h]
  __int64 v239; // [xsp+B8h] [xbp-18h]
  __int64 v240; // [xsp+C0h] [xbp-10h]

  v4 = a1 + 69516;
  v240 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 40) == 4 )
  {
    v5 = *(_QWORD *)(a2 + 24);
    v6 = *(_DWORD *)(a2 + 60);
    v7 = qce_alloc_req_info(a1);
    if ( (v7 & 0x80000000) == 0 )
    {
      *(_DWORD *)(a2 + 176) = v7;
      if ( v7 >= 0xA )
        goto LABEL_335;
      v8 = a1 + 2624;
      _X22 = a1 + 2624 + 7432LL * v7;
      v10 = *(_DWORD *)(v5 + 52);
      v220 = v7;
      v11 = *(_DWORD *)(a2 + 88) + v10;
      if ( *(_DWORD *)(a2 + 36) )
      {
        v219 = v10 - v6;
        *(_DWORD *)(a2 + 136) = v10 - v6;
      }
      else
      {
        v18 = *(_DWORD *)(a1 + 400);
        *(_DWORD *)(a2 + 136) = v10;
        v219 = *(_DWORD *)(v5 + 52) + v6;
        v6 = ((v6 + v18 - 1) & -v18) - v6;
      }
      v217 = (unsigned int *)v4;
      v215 = v6;
      if ( *(_DWORD *)(a1 + 404) || *(_DWORD *)(a1 + 408) > 5u )
      {
        v22 = *(_DWORD *)(v5 + 48) + *(_DWORD *)(v5 + 52);
        if ( v22 >= 1 )
        {
          v23 = *(_QWORD *)(v5 + 64);
          v21 = 0;
          do
          {
            ++v21;
            v22 -= *(_DWORD *)(v23 + 12);
            v23 = sg_next(v23);
          }
          while ( v22 > 0 );
LABEL_34:
          *(_DWORD *)(_X22 + 7352) = v21;
          v34 = *(_DWORD *)(a2 + 88);
          if ( v34 )
          {
            if ( v34 < 1 )
            {
              *(_DWORD *)(_X22 + 7336) = 0;
            }
            else
            {
              v35 = *(_QWORD *)(a2 + 96);
              v36 = 0;
              do
              {
                ++v36;
                v34 -= *(_DWORD *)(v35 + 12);
                v35 = sg_next(v35);
              }
              while ( v34 > 0 );
              *(_DWORD *)(_X22 + 7336) = v36;
              if ( (unsigned int)(v36 - 1) <= 0x7FFFFFFE )
              {
                v37 = *(_QWORD *)a1;
                v38 = *(_QWORD *)(a2 + 96);
                do
                {
                  if ( !v38 )
                    break;
                  dma_map_sg_attrs(v37, v38, 1, 1, 0);
                  --v36;
                  v38 = sg_next(v38);
                }
                while ( v36 );
              }
            }
            v21 = *(_DWORD *)(_X22 + 7352);
            *(_QWORD *)(_X22 + 7344) = *(_QWORD *)(a2 + 96);
          }
          else
          {
            *(_DWORD *)(_X22 + 7336) = 0;
            *(_QWORD *)(_X22 + 7344) = 0;
          }
          v40 = *(_QWORD *)(v5 + 64);
          v39 = *(_QWORD *)(v5 + 72);
          v41 = v5;
          v42 = v40 != v39;
          if ( v21 < 1 )
          {
            v44 = v11;
            v45 = v220;
            if ( v40 != v39 )
            {
LABEL_51:
              v46 = *(_DWORD *)(v41 + 48) + v219;
              if ( v46 >= 1 )
              {
                v47 = 0;
                do
                {
                  ++v47;
                  v46 -= *(_DWORD *)(v39 + 12);
                  v39 = sg_next(v39);
                }
                while ( v46 > 0 );
                *(_DWORD *)(_X22 + 7356) = v47;
                if ( (unsigned int)(v47 - 1) <= 0x7FFFFFFE )
                {
                  v48 = *(_QWORD *)a1;
                  v49 = *(_QWORD *)(v41 + 72);
                  do
                  {
                    if ( !v49 )
                      break;
                    dma_map_sg_attrs(v48, v49, 1, 2, 0);
                    --v47;
                    v49 = sg_next(v49);
                  }
                  while ( v47 );
                }
LABEL_63:
                if ( *(_BYTE *)(a1 + 68) != 1 )
                {
                  LODWORD(result) = -95;
                  goto LABEL_174;
                }
                v51 = *(unsigned int *)(a2 + 32);
                v52 = *(_DWORD *)(a2 + 40);
                if ( (_DWORD)v51 != 2 )
                {
                  if ( (_DWORD)v51 != 1 )
                  {
                    if ( !(_DWORD)v51 )
                    {
                      _ZF = v52 == 1;
                      v54 = 1344;
                      v55 = 1568;
                      goto LABEL_75;
                    }
LABEL_139:
                    printk(&unk_14AF2, "_qce_aead_ccm_req", v51);
                    v93 = a1;
                    v94 = v45;
LABEL_166:
                    qce_free_req_info(v93, v94, 0, v92);
                    result = 4294967274LL;
                    goto LABEL_323;
                  }
                  _ZF = v52 == 1;
                  v54 = 1792;
                  v55 = 2016;
LABEL_75:
                  if ( _ZF )
                    v54 = v55;
                  goto LABEL_77;
                }
                if ( v52 <= 1 )
                {
                  if ( v52 )
                  {
                    if ( v52 != 1 )
                      goto LABEL_139;
                    v55 = 448;
                    _ZF = *(_DWORD *)(a2 + 112) == 16;
                    v54 = 672;
                    goto LABEL_75;
                  }
                }
                else if ( v52 != 2 )
                {
                  if ( v52 == 3 )
                  {
                    v55 = 896;
                    _ZF = (*(_DWORD *)(a2 + 112) & 0xFFFFFFFE) == 32;
                    v54 = 1120;
                  }
                  else
                  {
                    if ( v52 != 4 )
                      goto LABEL_139;
                    v55 = 5376;
                    _ZF = *(_DWORD *)(a2 + 112) == 16;
                    v54 = 5600;
                  }
                  goto LABEL_75;
                }
                v54 = 224;
                if ( *(_DWORD *)(a2 + 112) == 16 )
                  v54 = 0;
LABEL_77:
                v56 = v8 + 7432LL * v45 + 96;
                v57 = v56 + v54;
                if ( v56 + v54 )
                {
                  LODWORD(result) = ce_setup_cipher(a1, a2, v44, *(unsigned int *)(a2 + 88), v56 + v54);
                  if ( (result & 0x80000000) != 0 )
                    goto LABEL_174;
                  *(_DWORD *)(_X22 + 7388) = *(_DWORD *)(a2 + 40);
                  *(_QWORD *)(_X22 + 7328) = *(_QWORD *)(a2 + 24);
                  v58 = *(_QWORD *)(a2 + 8);
                  *(_QWORD *)(_X22 + 7312) = 0;
                  *(_QWORD *)(_X22 + 7304) = v58;
                  v59 = *(_DWORD *)(a2 + 36);
                  *(_DWORD *)(_X22 + 8) = 2;
                  *(_DWORD *)(_X22 + 7412) = v44;
                  *(_DWORD *)(_X22 + 7384) = v59;
                  if ( v45 == 9 )
                    goto LABEL_335;
                  v60 = *(unsigned __int8 *)(a1 + 68);
                  v61 = v8 + 7432LL * v45;
                  *(_DWORD *)(v61 + 48) = 0;
                  *(_DWORD *)(v61 + 80) = 0;
                  if ( v60 == 1 )
                  {
                    v62 = *(_DWORD **)(_X22 + 40);
                    v63 = *(_QWORD *)v57 - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24);
                    v64 = *(unsigned __int16 *)(v57 + 216) | (v63 >> 16) & 0xF0000 | 0xC000000;
                    *v62 = v63;
                    v62[1] = v64;
                    v65 = (unsigned int)(*(_DWORD *)(_X22 + 48) + 1);
                    *(_DWORD *)(_X22 + 48) = v65;
                    if ( (unsigned int)v65 >= 0x200 )
                      goto LABEL_172;
                  }
                  if ( !*(_DWORD *)(a1 + 404) && *(_DWORD *)(a1 + 408) < 6u )
                  {
                    LODWORD(result) = 0;
                    goto LABEL_174;
                  }
                  v66 = *(unsigned int *)(a2 + 88);
                  if ( (_DWORD)v66 )
                  {
                    LODWORD(result) = qce_sps_add_sg_data(a1, *(_QWORD *)(a2 + 96), v66, _X22 + 32);
                    if ( (_DWORD)result )
                      goto LABEL_174;
                  }
                  LODWORD(result) = qce_sps_add_sg_data_off(
                                      a1,
                                      *(_QWORD *)(v41 + 64),
                                      *(unsigned int *)(v41 + 52),
                                      *(unsigned int *)(v41 + 48),
                                      _X22 + 32);
                  if ( (_DWORD)result )
                    goto LABEL_174;
                  v67 = *(_DWORD *)(_X22 + 48);
                  if ( v67 )
                  {
                    v68 = *(_QWORD *)(_X22 + 40) + 8LL * (unsigned int)(v67 - 1);
                    *(_DWORD *)(v68 + 4) |= 0x50000000u;
                  }
                  _X23 = v217;
                  if ( *(_DWORD *)(a2 + 36) != 1 || *(_BYTE *)(a1 + 128) != 1 || (*(_BYTE *)(a1 + 129) & 1) != 0 )
                  {
LABEL_103:
                    if ( *(_BYTE *)(a1 + 128) != 1
                      || (v79 = *(_QWORD *)(_X22 + 7040) - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24),
                          v80 = (_DWORD *)(*(_QWORD *)(_X22 + 40) + 8LL * *(unsigned int *)(_X22 + 48)),
                          v81 = *(unsigned __int16 *)(_X22 + 7256) | 0xA000000 | (v79 >> 16) & 0xF0000,
                          *v80 = v79,
                          v80[1] = v81,
                          v65 = (unsigned int)(*(_DWORD *)(_X22 + 48) + 1),
                          *(_DWORD *)(_X22 + 48) = v65,
                          (unsigned int)v65 < 0x200) )
                    {
                      v82 = *(_DWORD *)(a2 + 88);
                      if ( v82 )
                      {
                        v83 = *(unsigned int *)(_X22 + 80);
                        v84 = (_DWORD *)(*(_QWORD *)(_X22 + 72) + 8 * v83);
                        v85 = *(_QWORD *)(a1 + 24) + *(unsigned int *)(_X22 + 7280) - *(_QWORD *)(a1 + 16);
                        while ( (_DWORD)v83 != 512 )
                        {
                          v83 = v85 >> 16;
                          if ( v82 >= 0x7FC0 )
                            v86 = 32704;
                          else
                            v86 = v82;
                          v82 -= v86;
                          *v84 = v85;
                          v84[1] = v83 & 0xF0000 | v86;
                          v84 += 2;
                          v85 += v86;
                          LODWORD(v83) = *(_DWORD *)(_X22 + 80) + 1;
                          *(_DWORD *)(_X22 + 80) = v83;
                          if ( !v82 )
                            goto LABEL_112;
                        }
                        v117 = "_qce_sps_add_data";
                        v65 = 512;
                        goto LABEL_173;
                      }
LABEL_112:
                      LODWORD(result) = qce_sps_add_sg_data_off(
                                          a1,
                                          *(_QWORD *)(v41 + 72),
                                          v219,
                                          *(unsigned int *)(v41 + 48),
                                          _X22 + 64);
                      if ( !(_DWORD)result )
                      {
                        LODWORD(result) = qce_sps_add_data(
                                            a1,
                                            *(_QWORD *)(a1 + 24) + *(unsigned int *)(_X22 + 7280) - *(_QWORD *)(a1 + 16),
                                            v215,
                                            _X22 + 64,
                                            0,
                                            0);
                        if ( !(_DWORD)result )
                        {
                          if ( (*(_BYTE *)(a1 + 128) & 1) != 0 || v44 <= 0x7FC0 )
                          {
                            LODWORD(result) = qce_sps_add_data(
                                                a1,
                                                *(_QWORD *)(a1 + 24)
                                              + *(unsigned int *)(_X22 + 7264)
                                              - *(_QWORD *)(a1 + 16),
                                                128,
                                                _X22 + 64,
                                                0,
                                                0);
                            if ( (_DWORD)result )
                              goto LABEL_174;
                            v87 = 2;
                          }
                          else
                          {
                            v87 = 0;
                          }
                          *(_DWORD *)(_X22 + 16) = v87;
                          qce_ccm_get_around_output(a1, _X22, *(unsigned int *)(a2 + 36));
                          select_mode(a1, _X22);
                          result = qce_sps_transfer(a1, v45);
                          __asm { PRFM            #0x11, [X23] }
                          while ( 1 )
                          {
                            v214 = __ldxr(v217);
                            if ( v214 != 1 )
                              break;
                            if ( !__stlxr(0, v217) )
                            {
                              __dmb(0xBu);
                              break;
                            }
                          }
                          if ( !(_DWORD)result )
                            goto LABEL_323;
                        }
                      }
LABEL_174:
                      v118 = v45;
                      v119 = *(_DWORD *)(_X22 + 7336);
                      v120 = result;
                      if ( v119 > 0 )
                      {
                        v121 = *(_QWORD *)a1;
                        v122 = *(_QWORD *)(a2 + 96);
                        do
                        {
                          if ( !v122 )
                            break;
                          dma_unmap_sg_attrs(v121, v122, 1, 1, 0);
                          --v119;
                          v122 = sg_next(v122);
                        }
                        while ( v119 );
                      }
                      v124 = *(_QWORD *)(v41 + 64);
                      v123 = *(_QWORD *)(v41 + 72);
                      v125 = *(_DWORD *)(_X22 + 7352);
                      if ( v125 )
                      {
                        v126 = v124 != v123;
                        if ( v125 >= 1 )
                        {
                          v127 = *(_QWORD *)a1;
                          do
                          {
                            if ( !v124 )
                              break;
                            dma_unmap_sg_attrs(v127, v124, 1, v126, 0);
                            --v125;
                            v124 = sg_next(v124);
                          }
                          while ( v125 );
                          v124 = *(_QWORD *)(v41 + 64);
                          v123 = *(_QWORD *)(v41 + 72);
                        }
                      }
                      if ( v124 != v123 )
                      {
                        v128 = *(_DWORD *)(_X22 + 7356);
                        if ( v128 >= 1 )
                        {
                          v129 = *(_QWORD *)a1;
                          do
                          {
                            if ( !v123 )
                              break;
                            dma_unmap_sg_attrs(v129, v123, 1, 2, 0);
                            --v128;
                            v123 = sg_next(v123);
                          }
                          while ( v128 );
                        }
                      }
                      if ( v118 != 9 )
                      {
                        *(_DWORD *)(_X22 + 8) = 5;
                        __asm { PRFM            #0x11, [X22] }
                        do
                          v131 = __ldxr((unsigned int *)_X22);
                        while ( __stlxr(0, (unsigned int *)_X22) );
                        __dmb(0xBu);
                        if ( !v131 )
                          printk(&unk_15B49, "qce_free_req_info", v118);
                        result = v120;
                        goto LABEL_323;
                      }
LABEL_335:
                      __break(0x5512u);
                    }
LABEL_172:
                    v117 = "_qce_sps_add_cmd";
LABEL_173:
                    printk(&unk_15B74, v117, v65);
                    LODWORD(result) = -12;
                    goto LABEL_174;
                  }
                  v70 = *(_QWORD *)(_X22 + 5920) - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24);
                  v71 = (_DWORD *)(*(_QWORD *)(_X22 + 40) + 8LL * *(unsigned int *)(_X22 + 48));
                  v72 = *(unsigned __int16 *)(_X22 + 6136) | (v70 >> 16) & 0xF0000 | 0x8000000;
                  *v71 = v70;
                  v71[1] = v72;
                  v73 = (unsigned int)(*(_DWORD *)(_X22 + 48) + 1);
                  *(_DWORD *)(_X22 + 48) = v73;
                  if ( (unsigned int)v73 >= 0x200 )
                  {
                    printk(&unk_15B74, "_qce_sps_add_cmd", v73);
                    v73 = *(unsigned int *)(_X22 + 48);
                    v74 = *(_DWORD *)(a1 + 400);
                    if ( v74 )
                    {
LABEL_95:
                      v75 = (_DWORD *)(*(_QWORD *)(_X22 + 40) + 8LL * (unsigned int)v73);
                      v76 = *(_QWORD *)(a1 + 24) + *(unsigned int *)(_X22 + 7280) - *(_QWORD *)(a1 + 16);
                      while ( (_DWORD)v73 != 512 )
                      {
                        if ( v74 >= 0x7FC0 )
                          v77 = 32704;
                        else
                          v77 = v74;
                        v74 -= v77;
                        *v75 = v76;
                        v75[1] = (v76 >> 16) & 0xF0000 | v77;
                        v75 += 2;
                        v76 += v77;
                        v73 = (unsigned int)(*(_DWORD *)(_X22 + 48) + 1);
                        *(_DWORD *)(_X22 + 48) = v73;
                        if ( !v74 )
                          goto LABEL_101;
                      }
                      printk(&unk_15B74, "_qce_sps_add_data", v73);
                      LODWORD(v73) = *(_DWORD *)(_X22 + 48);
                    }
                  }
                  else
                  {
                    v74 = *(_DWORD *)(a1 + 400);
                    if ( v74 )
                      goto LABEL_95;
                  }
LABEL_101:
                  if ( (_DWORD)v73 )
                  {
                    v78 = *(_QWORD *)(_X22 + 40) + 8LL * (unsigned int)(v73 - 1);
                    *(_DWORD *)(v78 + 4) |= 0x50000000u;
                  }
                  goto LABEL_103;
                }
                goto LABEL_139;
              }
              v50 = 0;
LABEL_62:
              *(_DWORD *)(_X22 + 7356) = v50;
              goto LABEL_63;
            }
          }
          else
          {
            v43 = *(_QWORD *)a1;
            do
            {
              if ( !v40 )
                break;
              dma_map_sg_attrs(v43, v40, 1, v42, 0);
              --v21;
              v40 = sg_next(v40);
            }
            while ( v21 );
            v39 = *(_QWORD *)(v41 + 72);
            v44 = v11;
            v45 = v220;
            if ( *(_QWORD *)(v41 + 64) != v39 )
              goto LABEL_51;
          }
          v50 = *(_DWORD *)(_X22 + 7352);
          goto LABEL_62;
        }
      }
      else if ( v11 >= 1 )
      {
        v19 = *(_QWORD *)(v5 + 64);
        v20 = v11;
        v21 = 0;
        do
        {
          ++v21;
          v20 -= *(_DWORD *)(v19 + 12);
          v19 = sg_next(v19);
        }
        while ( v20 > 0 );
        goto LABEL_34;
      }
      v21 = 0;
      goto LABEL_34;
    }
LABEL_10:
    result = 4294967280LL;
    goto LABEL_323;
  }
  v12 = qce_alloc_req_info(a1);
  if ( (v12 & 0x80000000) != 0 )
    goto LABEL_10;
  *(_DWORD *)(a2 + 176) = v12;
  if ( v12 >= 0xA )
    goto LABEL_335;
  v14 = *(_QWORD *)(a2 + 24);
  v15 = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a2 + 128) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v14 + 32) + 24LL) - 16LL);
  if ( v15 )
    v16 = *(_DWORD *)(v14 + 52) - *(_DWORD *)(a2 + 60);
  else
    v16 = *(_DWORD *)(v14 + 52);
  *(_DWORD *)(a2 + 136) = v16;
  v24 = *(_DWORD *)(v14 + 48);
  if ( __CFADD__(v24, v16) )
  {
    printk(&unk_156F4, "qce_aead_req", v13);
    result = 4294967274LL;
    goto LABEL_323;
  }
  v25 = a1 + 2624;
  v26 = nullptr;
  _X22 = a1 + 2624 + 7432LL * v12;
  v28 = v24 + v16;
  *(_QWORD *)(_X22 + 7416) = 0;
  *(_BYTE *)(_X22 + 7428) = 0;
  v29 = *(unsigned __int8 *)(a1 + 68);
  *(_DWORD *)(_X22 + 7424) = *(_DWORD *)(a2 + 116);
  if ( v29 == 1 )
  {
    if ( v12 == 9 )
      goto LABEL_335;
    v30 = *(unsigned int *)(a2 + 32);
    v31 = *(_DWORD *)(a2 + 40);
    if ( (_DWORD)v30 == 2 )
    {
      if ( v31 )
        goto LABEL_165;
      v88 = *(_DWORD *)(a2 + 112);
      if ( v88 == 32 )
      {
        v91 = *(_DWORD *)(a2 + 44);
        if ( v91 == 2 )
        {
          v33 = 3808;
        }
        else
        {
          if ( v91 != 3 )
            goto LABEL_165;
          v33 = 4704;
        }
      }
      else
      {
        if ( v88 != 16 )
          goto LABEL_165;
        v89 = *(_DWORD *)(a2 + 44);
        if ( v89 == 2 )
        {
          v33 = 3584;
        }
        else
        {
          if ( v89 != 3 )
            goto LABEL_165;
          v33 = 4480;
        }
      }
    }
    else if ( (_DWORD)v30 == 1 )
    {
      if ( v31 )
        goto LABEL_165;
      v90 = *(_DWORD *)(a2 + 44);
      if ( v90 == 2 )
      {
        v33 = 4256;
      }
      else
      {
        if ( v90 != 3 )
          goto LABEL_165;
        v33 = 5152;
      }
    }
    else
    {
      if ( (_DWORD)v30 || v31 )
        goto LABEL_165;
      v32 = *(_DWORD *)(a2 + 44);
      if ( v32 == 2 )
      {
        v33 = 4032;
      }
      else
      {
        if ( v32 != 3 )
          goto LABEL_165;
        v33 = 4928;
      }
    }
    v26 = (_QWORD *)(v25 + 7432LL * v12 + 96 + v33);
    if ( v26 )
    {
      v95 = *(_DWORD *)(a2 + 176);
      if ( v95 >= 0xA )
        goto LABEL_335;
      v238 = 0;
      v239 = 0;
      v96 = v25 + 7432LL * v95;
      v97 = *(unsigned __int16 *)(v14 + 48);
      v236 = 0;
      v237 = 0;
      v234 = 0;
      v235 = 0;
      v232 = 0;
      v233 = 0;
      v98 = *(unsigned int *)(v96 + 7420);
      v230 = 0;
      v231 = 0;
      v228 = 0;
      v229 = 0;
      v226 = 0;
      v227 = 0;
      v224 = 0;
      v225 = 0;
      v222 = 0;
      v223 = 0;
      if ( (unsigned int)v98 >= 6 )
        goto LABEL_335;
      v99 = a1 + 4 * v98;
      if ( *(_BYTE *)(v4 + 745) )
        v100 = 15360;
      else
        v100 = 0;
      v101 = ((v100 & 0x1FFFF | ((unsigned __int16)(*(_DWORD *)(a1 + 400) >> 3) << 17)) - 0x20000)
           | (32 * *(_DWORD *)(v99 + 316));
      v102 = *(_DWORD *)(a2 + 128);
      v103 = *(_DWORD *)(a2 + 112);
      v104 = v26[1];
      *(_DWORD *)(a1 + 148) = v101 | 0xE;
      *(_DWORD *)(a1 + 152) = v101 | 0x20E;
      *(_DWORD *)(v104 + 4) = v101 | 0xE;
      *(_DWORD *)(v26[2] + 4LL) = *(_DWORD *)(a1 + 152);
      if ( *(_BYTE *)(a1 + 73) == 1 )
        *(_DWORD *)(v26[15] + 4LL) = *(_DWORD *)(v96 + 7424);
      v105 = *(_DWORD *)(a2 + 32);
      if ( v105 >= 2 )
      {
        if ( v105 != 2 )
          goto LABEL_158;
        v106 = 0;
        if ( v103 != 32 && v103 != 16 )
          goto LABEL_158;
      }
      else
      {
        v106 = 1;
      }
      if ( !*(_DWORD *)(a2 + 40) )
      {
        v107 = *(unsigned __int8 **)(a2 + 120);
        if ( v102 >= 4 )
        {
          v115 = v102 >> 2;
          HIDWORD(v223) = bswap32(*(_DWORD *)v107);
          if ( v102 >> 2 == 1 )
          {
            v108 = 0;
            v109 = (char *)&v223;
            v107 += 4;
          }
          else
          {
            LODWORD(v223) = bswap32(*((_DWORD *)v107 + 1));
            if ( v115 == 2 )
            {
              v108 = 0;
              v107 += 8;
              v109 = (char *)&v222 + 4;
            }
            else
            {
              HIDWORD(v222) = bswap32(*((_DWORD *)v107 + 2));
              if ( v115 == 3 )
              {
                v108 = 0;
                v107 += 12;
                v109 = (char *)&v222;
              }
              else
              {
                v109 = (char *)bswap32(*((_DWORD *)v107 + 3));
                LODWORD(v222) = (_DWORD)v109;
                if ( v115 != 4 )
                  goto LABEL_334;
                v107 += 16;
                v108 = 1;
              }
            }
          }
        }
        else
        {
          v108 = 0;
          v109 = (char *)&v223 + 4;
        }
        v132 = v102 & 3;
        switch ( v132 )
        {
          case 1:
            v133 = *v107 << 24;
            break;
          case 2:
            v133 = (*v107 << 24) | (v107[1] << 16);
            break;
          case 3:
            v133 = (*v107 << 24) | (v107[1] << 16) | (v107[2] << 8);
            break;
          default:
            goto LABEL_205;
        }
        if ( (v108 & 1) != 0 )
          goto LABEL_334;
        *(_DWORD *)v109 = v133;
LABEL_205:
        v134 = v223;
        v135 = (_DWORD *)v26[8];
        v135[1] = HIDWORD(v223);
        v135[5] = v134;
        if ( (v106 & 1) == 0 )
        {
          v136 = v222;
          v135[9] = HIDWORD(v222);
          v135[13] = v136;
        }
        v137 = v103 >> 2;
        v138 = *(unsigned __int8 **)(a2 + 104);
        v139 = (int *)&v224;
        v140 = 0;
        if ( v103 >= 4 )
        {
          v141 = v103 >> 2;
          do
          {
            if ( v140 > 0x3F )
              goto LABEL_334;
            --v141;
            *(_DWORD *)((char *)&v224 + v140) = bswap32(*(_DWORD *)&v138[v140]);
            v140 += 4LL;
          }
          while ( v141 );
          v138 += v140;
          v139 = (int *)((char *)&v224 + v140);
        }
        v142 = v103 & 3;
        switch ( v142 )
        {
          case 1:
            v143 = *v138 << 24;
            break;
          case 2:
            v143 = (*v138 << 24) | (v138[1] << 16);
            break;
          case 3:
            v143 = (*v138 << 24) | (v138[1] << 16) | (v138[2] << 8);
            break;
          default:
LABEL_220:
            if ( v103 >= 4 )
            {
              v144 = (_DWORD *)v26[6];
              v144[1] = v224;
              if ( v137 != 1 )
              {
                v144[5] = HIDWORD(v224);
                if ( v137 != 2 )
                {
                  v144[9] = v225;
                  if ( v137 != 3 )
                  {
                    v144[13] = HIDWORD(v225);
                    if ( v137 != 4 )
                    {
                      v144[17] = v226;
                      if ( v137 != 5 )
                      {
                        v144[21] = HIDWORD(v226);
                        if ( v137 != 6 )
                        {
                          v144[25] = v227;
                          if ( v137 != 7 )
                          {
                            v144[29] = HIDWORD(v227);
                            if ( v137 != 8 )
                            {
                              v144[33] = v228;
                              if ( v137 != 9 )
                              {
                                v144[37] = HIDWORD(v228);
                                if ( v137 != 10 )
                                {
                                  v144[41] = v229;
                                  if ( v137 != 11 )
                                  {
                                    v144[45] = HIDWORD(v229);
                                    if ( v137 != 12 )
                                    {
                                      v144[49] = v230;
                                      if ( v137 != 13 )
                                      {
                                        v144[53] = HIDWORD(v230);
                                        if ( v137 != 14 )
                                        {
                                          v144[57] = v231;
                                          if ( v137 != 15 )
                                          {
                                            v144[61] = HIDWORD(v231);
                                            if ( v137 != 16 )
                                              goto LABEL_335;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            *(_DWORD *)(v26[3] + 4LL) = *(_DWORD *)(v26[3] + 4LL) & 0xFFFFFBFF | ((*(_DWORD *)(a2 + 36) == 0) << 10);
            v145 = (int *)&v232;
            v146 = *(_DWORD *)(a2 + 56);
            v147 = *(unsigned __int8 **)(a2 + 48);
            if ( v146 >= 4 )
            {
              v149 = v146 >> 2;
              v148 = 0;
              do
              {
                if ( v148 > 0x3F )
                  goto LABEL_334;
                --v149;
                *(_DWORD *)((char *)&v232 + v148) = bswap32(*(_DWORD *)&v147[v148]);
                v148 += 4LL;
              }
              while ( v149 );
              v147 += v148;
              v145 = (int *)((char *)&v232 + v148);
            }
            else
            {
              v148 = 0;
            }
            v150 = v146 & 3;
            switch ( v150 )
            {
              case 1:
                v151 = *v147 << 24;
                break;
              case 2:
                v151 = (*v147 << 24) | (v147[1] << 16);
                break;
              case 3:
                v151 = (*v147 << 24) | (v147[1] << 16) | (v147[2] << 8);
                break;
              default:
LABEL_251:
                v152 = HIDWORD(v232);
                v153 = (_DWORD *)v26[21];
                v153[1] = v232;
                v153[5] = v152;
                v154 = HIDWORD(v233);
                v153[9] = v233;
                v153[13] = v154;
                v155 = HIDWORD(v234);
                v153[17] = v234;
                v153[21] = v155;
                v156 = HIDWORD(v235);
                v153[25] = v235;
                v153[29] = v156;
                v157 = HIDWORD(v236);
                v153[33] = v236;
                v153[37] = v157;
                v158 = HIDWORD(v237);
                v153[41] = v237;
                v153[45] = v158;
                v159 = HIDWORD(v238);
                v153[49] = v238;
                v153[53] = v159;
                v160 = HIDWORD(v239);
                v153[57] = v239;
                v153[61] = v160;
                v161 = (_DWORD *)v26[22];
                if ( *(_DWORD *)(a2 + 44) == 2 )
                {
                  v162 = -1009589776;
                  v163 = 271733878;
                  v164 = -1732584194;
                  v165 = -271733879;
                  v166 = 1732584193;
                }
                else
                {
                  v161[21] = -1694144372;
                  v161[25] = 528734635;
                  v161[29] = 1541459225;
                  v162 = 1359893119;
                  v163 = -1521486534;
                  v164 = 1013904242;
                  v165 = -1150833019;
                  v166 = 1779033703;
                }
                v161[1] = v166;
                v161[5] = v165;
                v161[9] = v164;
                v161[13] = v163;
                v161[17] = v162;
                v167 = v26[24];
                *(_DWORD *)(v167 + 4) = 0;
                *(_DWORD *)(v167 + 20) = 0;
                v168 = v26[18];
                v169 = *(_DWORD *)(v168 + 4) & 0xFFFF3FFF;
                if ( !*(_DWORD *)(a2 + 36) )
                  v169 |= 0x4000u;
                *(_DWORD *)(v168 + 4) = v169;
                *(_DWORD *)(v26[19] + 4LL) = v28;
                *(_DWORD *)(v26[20] + 4LL) = 0;
                *(_DWORD *)(v26[25] + 4LL) = v28;
                *(_DWORD *)(v26[4] + 4LL) = *(_DWORD *)(a2 + 136);
                *(_DWORD *)(v26[5] + 4LL) = v97;
                goto LABEL_257;
            }
            if ( v148 <= 0x3C )
            {
              *v145 = v151;
              goto LABEL_251;
            }
LABEL_334:
            __break(1u);
            goto LABEL_335;
        }
        if ( v140 > 0x3C )
          goto LABEL_334;
        *v139 = v143;
        goto LABEL_220;
      }
LABEL_158:
      *(_DWORD *)(_X22 + 8) = 5;
      __asm { PRFM            #0x11, [X22] }
      do
        v114 = __ldxr((unsigned int *)_X22);
      while ( __stlxr(0, (unsigned int *)_X22) );
      __dmb(0xBu);
      if ( !v114 )
        printk(&unk_15B49, "qce_free_req_info", v12);
      result = 4294967274LL;
      goto LABEL_323;
    }
LABEL_165:
    v116 = v12;
    printk(&unk_1572D, "qce_aead_req", v30);
    v93 = a1;
    v94 = v116;
    goto LABEL_166;
  }
LABEL_257:
  v170 = v12;
  v218 = v12;
  v216 = v26;
  if ( v28 < 1 )
  {
    v173 = v28;
    v172 = 0;
  }
  else
  {
    v171 = *(_QWORD *)(v14 + 64);
    v172 = 0;
    v173 = v28;
    do
    {
      ++v172;
      v28 -= *(_DWORD *)(v171 + 12);
      v171 = sg_next(v171);
    }
    while ( v28 > 0 );
  }
  *(_DWORD *)(_X22 + 7352) = v172;
  _X23 = (unsigned int *)v4;
  v176 = *(_QWORD *)(v14 + 64);
  v175 = *(_QWORD *)(v14 + 72);
  v221 = v14;
  v177 = v176 != v175;
  if ( v172 >= 1 )
  {
    v178 = *(_QWORD *)a1;
    do
    {
      if ( !v176 )
        break;
      dma_map_sg_attrs(v178, v176, 1, v177, 0);
      --v172;
      v176 = sg_next(v176);
    }
    while ( v172 );
    v176 = *(_QWORD *)(v221 + 64);
    v175 = *(_QWORD *)(v221 + 72);
  }
  if ( v176 != v175 )
  {
    v179 = v173;
    if ( (int)v173 < 1 )
    {
      *(_DWORD *)(_X22 + 7356) = 0;
    }
    else
    {
      v180 = 0;
      do
      {
        ++v180;
        v179 -= *(_DWORD *)(v175 + 12);
        v175 = sg_next(v175);
      }
      while ( v179 > 0 );
      *(_DWORD *)(_X22 + 7356) = v180;
      if ( (unsigned int)(v180 - 1) <= 0x7FFFFFFE )
      {
        v181 = *(_QWORD *)a1;
        v182 = *(_QWORD *)(v221 + 72);
        do
        {
          if ( !v182 )
            break;
          dma_map_sg_attrs(v181, v182, 1, 2, 0);
          --v180;
          v182 = sg_next(v182);
        }
        while ( v180 );
      }
    }
  }
  *(_QWORD *)(_X22 + 7328) = *(_QWORD *)(a2 + 24);
  v183 = *(_QWORD *)(a2 + 8);
  *(_QWORD *)(_X22 + 7312) = 0;
  *(_QWORD *)(_X22 + 7304) = v183;
  v184 = *(_DWORD *)(a2 + 36);
  *(_QWORD *)(_X22 + 7344) = 0;
  *(_DWORD *)(_X22 + 8) = 2;
  *(_DWORD *)(_X22 + 7384) = v184;
  *(_DWORD *)(_X22 + 7412) = v173;
  if ( v170 == 9 )
    goto LABEL_335;
  v185 = a1 + 2624 + 7432LL * v218;
  v186 = *(unsigned __int8 *)(a1 + 68);
  *(_DWORD *)(v185 + 48) = 0;
  *(_DWORD *)(v185 + 80) = 0;
  if ( v186 != 1 )
  {
    LODWORD(result) = -95;
    goto LABEL_305;
  }
  v187 = *v216 - *(_QWORD *)(a1 + 16) + *(_QWORD *)(a1 + 24);
  v188 = *(_DWORD **)(_X22 + 40);
  v189 = *((unsigned __int16 *)v216 + 108) | (v187 >> 16) & 0xF0000 | 0xC000000;
  *v188 = v187;
  v188[1] = v189;
  v190 = (unsigned int)(*(_DWORD *)(_X22 + 48) + 1);
  *(_DWORD *)(_X22 + 48) = v190;
  if ( (unsigned int)v190 >= 0x200 )
  {
    printk(&unk_15B74, "_qce_sps_add_cmd", v190);
    LODWORD(result) = -12;
    goto LABEL_305;
  }
  v191 = *(_DWORD *)(a1 + 404);
  *(_DWORD *)(_X22 + 7388) = *(_DWORD *)(a2 + 40);
  if ( !v191 && *(_DWORD *)(a1 + 408) <= 5u )
  {
    LODWORD(result) = qce_sps_add_sg_data(a1, *(_QWORD *)(v221 + 64), v173, _X22 + 32);
    if ( (_DWORD)result )
      goto LABEL_305;
    v192 = *(_DWORD *)(_X22 + 48);
    if ( v192 )
    {
      v193 = *(_QWORD *)(_X22 + 40) + 8LL * (unsigned int)(v192 - 1);
      *(_DWORD *)(v193 + 4) |= 0x50000000u;
    }
    LODWORD(result) = qce_sps_add_sg_data(a1, *(_QWORD *)(v221 + 72), v173, _X22 + 64);
    if ( (_DWORD)result )
      goto LABEL_305;
    if ( v173 < 0x7FC1 )
    {
      LODWORD(result) = qce_sps_add_data(
                          a1,
                          *(_QWORD *)(a1 + 24) + *(unsigned int *)(_X22 + 7264) - *(_QWORD *)(a1 + 16),
                          128,
                          _X22 + 64,
                          0,
                          0);
      if ( (_DWORD)result )
        goto LABEL_305;
      v194 = *(_DWORD *)(_X22 + 80);
      v195 = 2;
      v196 = 2;
      if ( !v194 )
        goto LABEL_289;
    }
    else
    {
      v194 = *(_DWORD *)(_X22 + 80);
      v195 = 0;
      v196 = 0;
      if ( !v194 )
        goto LABEL_289;
    }
    v197 = *(_QWORD *)(_X22 + 72) + 8LL * (unsigned int)(v194 - 1);
    *(_DWORD *)(v197 + 4) |= 0x80000000;
    v196 = v195;
LABEL_289:
    *(_DWORD *)(_X22 + 16) = v196;
    result = qce_sps_transfer(a1, v170);
    if ( !(_DWORD)result )
      goto LABEL_323;
    goto LABEL_305;
  }
  LODWORD(result) = qce_sps_add_sg_data(a1, *(_QWORD *)(v221 + 64), v173, _X22 + 32);
  if ( (_DWORD)result )
    goto LABEL_305;
  v198 = *(_DWORD *)(_X22 + 48);
  if ( v198 )
  {
    v199 = *(_QWORD *)(_X22 + 40) + 8LL * (unsigned int)(v198 - 1);
    *(_DWORD *)(v199 + 4) |= 0x50000000u;
  }
  if ( *(_BYTE *)(a1 + 128) == 1 )
  {
    LODWORD(result) = qce_sps_add_cmd(a1, 512, _X22 + 7040, _X22 + 32);
    if ( (_DWORD)result )
      goto LABEL_305;
  }
  LODWORD(result) = qce_sps_add_sg_data(a1, *(_QWORD *)(v221 + 72), v173, _X22 + 64);
  if ( (_DWORD)result )
    goto LABEL_305;
  if ( v173 < 0x7FC1 || (*(_BYTE *)(a1 + 128) & 1) != 0 )
  {
    LODWORD(result) = qce_sps_add_data(
                        a1,
                        *(_QWORD *)(a1 + 24) + *(unsigned int *)(_X22 + 7264) - *(_QWORD *)(a1 + 16),
                        128,
                        _X22 + 64,
                        0,
                        0);
    if ( (_DWORD)result )
      goto LABEL_305;
    v200 = 2;
  }
  else
  {
    v200 = 0;
  }
  *(_DWORD *)(_X22 + 16) = v200;
  select_mode(a1, _X22);
  result = qce_sps_transfer(a1, v170);
  __asm { PRFM            #0x11, [X23] }
  while ( 1 )
  {
    v212 = __ldxr(_X23);
    if ( v212 != 1 )
      break;
    if ( !__stlxr(0, _X23) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( (_DWORD)result )
  {
LABEL_305:
    v201 = *(_DWORD *)(_X22 + 7352);
    v203 = *(_QWORD *)(v221 + 64);
    v202 = *(_QWORD *)(v221 + 72);
    if ( v201 )
    {
      v204 = result;
      v205 = v203 != v202;
      if ( v201 >= 1 )
      {
        v206 = *(_QWORD *)a1;
        do
        {
          if ( !v203 )
            break;
          dma_unmap_sg_attrs(v206, v203, 1, v205, 0);
          --v201;
          v203 = sg_next(v203);
        }
        while ( v201 );
        v203 = *(_QWORD *)(v221 + 64);
        v202 = *(_QWORD *)(v221 + 72);
      }
      if ( v203 == v202 )
        goto LABEL_318;
    }
    else
    {
      v204 = result;
      if ( v203 == v202 )
      {
LABEL_318:
        *(_DWORD *)(_X22 + 8) = 5;
        __asm { PRFM            #0x11, [X22] }
        do
          v210 = __ldxr((unsigned int *)_X22);
        while ( __stlxr(0, (unsigned int *)_X22) );
        __dmb(0xBu);
        if ( !v210 )
          printk(&unk_15B49, "qce_free_req_info", v170);
        result = v204;
        goto LABEL_323;
      }
    }
    v207 = *(_DWORD *)(_X22 + 7356);
    if ( v207 >= 1 )
    {
      v208 = *(_QWORD *)a1;
      do
      {
        if ( !v202 )
          break;
        dma_unmap_sg_attrs(v208, v202, 1, 2, 0);
        --v207;
        v202 = sg_next(v202);
      }
      while ( v207 );
    }
    goto LABEL_318;
  }
LABEL_323:
  _ReadStatusReg(SP_EL0);
  return result;
}
