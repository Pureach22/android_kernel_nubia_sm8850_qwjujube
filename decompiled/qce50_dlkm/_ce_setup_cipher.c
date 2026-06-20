__int64 __fastcall ce_setup_cipher(__int64 a1, __int64 a2, int a3, unsigned __int16 a4, _QWORD *a5)
{
  unsigned int v5; // w9
  __int64 v6; // x19
  int v7; // w10
  __int64 v8; // x9
  char v9; // w10
  __int64 v10; // x20
  int v11; // w9
  int v12; // w12
  int v13; // w11
  unsigned int v14; // w12
  int v15; // w9
  unsigned int v16; // w11
  __int64 v17; // x13
  unsigned int v18; // w11
  int v19; // w15
  int v20; // w9
  int v21; // w21
  unsigned int v22; // w10
  char v23; // w13
  unsigned __int8 *v24; // x15
  int *v25; // x13
  unsigned __int64 v26; // x14
  unsigned int v27; // w16
  int v28; // w16
  int v29; // w15
  int v30; // w9
  int v31; // w14
  unsigned int v32; // w5
  unsigned int v33; // w6
  _DWORD *v34; // x17
  unsigned int v35; // w15
  unsigned int v36; // w16
  int v37; // w14
  __int64 v38; // x14
  __int64 v39; // x14
  int v40; // w14
  int v41; // w14
  unsigned int v42; // w14
  unsigned int v43; // w16
  _DWORD *v44; // x15
  int v45; // w15
  int v46; // w11
  bool v47; // zf
  __int64 v48; // x11
  int v49; // w15
  unsigned __int8 *v50; // x10
  __int64 v51; // x14
  unsigned __int64 *v52; // x13
  unsigned __int8 *v53; // x10
  __int64 v54; // x14
  unsigned __int64 *v55; // x13
  unsigned __int64 v56; // x14
  unsigned int v57; // w13
  unsigned __int8 *v58; // x15
  unsigned __int64 v59; // x17
  __int64 *v60; // x16
  unsigned int v61; // w13
  unsigned int v62; // w13
  unsigned int v63; // w13
  int v64; // w12
  int v65; // w10
  int v66; // w13
  __int64 v67; // x10
  int v68; // w13
  __int64 v69; // x10
  char v70; // w12
  unsigned int v71; // w13
  int v72; // w12
  int v73; // w10
  int v74; // w13
  __int64 v75; // x10
  int v76; // w13
  _DWORD *v77; // x10
  int v78; // w13
  int v79; // w13
  unsigned int v80; // w5
  int v81; // w15
  _DWORD *v82; // x14
  unsigned int v83; // w14
  int v84; // w15
  bool v85; // cf
  int v86; // w15
  unsigned __int8 *v87; // x13
  unsigned __int64 v88; // x14
  unsigned __int64 v89; // x16
  unsigned __int64 v90; // x15
  unsigned __int64 v91; // x17
  __int64 v92; // x17
  unsigned __int64 v93; // x16
  unsigned __int64 v94; // x15
  char *v95; // x5
  unsigned __int64 v96; // x16
  unsigned int v97; // w15
  unsigned int v98; // w12
  unsigned __int8 *v99; // x17
  unsigned __int8 v100; // w6
  unsigned __int8 v101; // w5
  unsigned int v102; // w12
  unsigned __int8 v103; // w16
  unsigned int v104; // w13
  unsigned int v105; // w14
  unsigned int v106; // w15
  __int64 v107; // x15
  unsigned __int64 *v108; // x14
  unsigned int v109; // w14
  __int64 result; // x0
  unsigned int v111; // w14
  int v112; // w12
  int v113; // w12
  int v114; // w12
  int v115; // w13
  int v116; // w14
  int v117; // w15
  _DWORD *v118; // x16
  _DWORD *v119; // x16
  _DWORD *v120; // x12
  __int64 v121; // x10
  int v122; // w11
  unsigned int v123; // w11
  int v124; // w10
  int v125; // w9
  int v126; // w9
  __int64 v127; // x2
  int v128; // w10
  __int64 v129; // x8
  __int64 v130; // x8
  int v131; // w9
  _QWORD *v132; // x22
  int v133; // [xsp+Ch] [xbp-84h] BYREF
  __int64 v134; // [xsp+10h] [xbp-80h] BYREF
  __int64 v135; // [xsp+18h] [xbp-78h] BYREF
  __int64 v136; // [xsp+20h] [xbp-70h] BYREF
  unsigned __int64 v137; // [xsp+28h] [xbp-68h] BYREF
  unsigned __int64 v138; // [xsp+30h] [xbp-60h] BYREF
  __int64 v139; // [xsp+38h] [xbp-58h] BYREF
  __int64 v140; // [xsp+40h] [xbp-50h]
  __int64 v141; // [xsp+48h] [xbp-48h]
  __int64 v142; // [xsp+50h] [xbp-40h]
  __int64 v143; // [xsp+58h] [xbp-38h]
  __int64 v144; // [xsp+60h] [xbp-30h]
  __int64 v145; // [xsp+68h] [xbp-28h]
  __int64 v146; // [xsp+70h] [xbp-20h]
  __int64 v147; // [xsp+78h] [xbp-18h] BYREF
  __int64 v148; // [xsp+80h] [xbp-10h]
  __int64 v149; // [xsp+88h] [xbp-8h]

  v149 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a2 + 176);
  if ( v5 >= 0xA )
    goto LABEL_267;
  v145 = 0;
  v146 = 0;
  v6 = a1 + 2624 + 7432LL * v5;
  v7 = *(_DWORD *)(a2 + 40);
  v143 = 0;
  v144 = 0;
  v141 = 0;
  v142 = 0;
  v139 = 0;
  v140 = 0;
  v8 = *(unsigned int *)(v6 + 7420);
  v9 = v7 == 3;
  v137 = 0;
  v138 = 0;
  if ( (unsigned int)v8 >= 6 )
    goto LABEL_267;
  v10 = a1 + 69632;
  v11 = *(_DWORD *)(a1 + 4 * v8 + 316);
  if ( *(_BYTE *)(a1 + 70261) )
    v12 = 15360;
  else
    v12 = 0;
  v13 = (v12 & 0x1FFFF | ((unsigned __int16)(*(_DWORD *)(a1 + 400) >> 3) << 17)) - 0x20000;
  v14 = *(_DWORD *)(a2 + 128);
  v15 = v13 | (32 * v11);
  v16 = *(_DWORD *)(a2 + 112);
  *(_DWORD *)(a1 + 148) = v15 | 0xE;
  *(_DWORD *)(a1 + 152) = v15 | 0x20E;
  *(_DWORD *)(a5[1] + 4LL) = v15 | 0xE;
  *(_DWORD *)(a5[2] + 4LL) = *(_DWORD *)(a1 + 152);
  if ( *(_BYTE *)(a1 + 73) == 1 )
    *(_DWORD *)(a5[15] + 4LL) = *(_DWORD *)(v6 + 7424);
  v17 = a5[26];
  v18 = v16 >> v9;
  v19 = *(unsigned __int8 *)(v17 + 3);
  *(_DWORD *)v17 = *(_DWORD *)(a1 + 70256) & (*(_DWORD *)(a1 + 88) + 106784) & 0xFFFFFF | ((unsigned __int8)v19 << 24);
  v20 = *(_DWORD *)(a2 + 152);
  if ( (v20 & 1) != 0 )
  {
    v21 = 0;
    v22 = 0;
    *(_DWORD *)v17 = *(_DWORD *)(a1 + 70256) & (*(_DWORD *)(a1 + 88) + 110592) & 0xFFFFFF | (v19 << 24);
    v23 = 1;
    goto LABEL_26;
  }
  if ( (v20 & 2) != 0 )
  {
    v22 = 0;
    v23 = 1;
    v21 = 1;
    goto LABEL_26;
  }
  v24 = *(unsigned __int8 **)(a2 + 104);
  v22 = v18 >> 2;
  v25 = (int *)&v139;
  v26 = 0;
  if ( v18 >= 4 )
  {
    v27 = v18 >> 2;
    do
    {
      if ( v26 > 0x3F )
        goto LABEL_266;
      --v27;
      *(_DWORD *)((char *)&v139 + v26) = bswap32(*(_DWORD *)&v24[v26]);
      v26 += 4LL;
    }
    while ( v27 );
    v24 += v26;
    v25 = (int *)((char *)&v139 + v26);
  }
  v28 = v18 & 3;
  switch ( v28 )
  {
    case 1:
      v29 = *v24 << 24;
      goto LABEL_23;
    case 2:
      v29 = (*v24 << 24) | (v24[1] << 16);
      goto LABEL_23;
    case 3:
      v29 = (*v24 << 24) | (v24[1] << 16) | (v24[2] << 8);
LABEL_23:
      if ( v26 > 0x3C )
        goto LABEL_266;
      *v25 = v29;
      break;
  }
  v23 = 0;
  v21 = 0;
LABEL_26:
  v30 = v20 & 1;
  if ( *(_DWORD *)a2 == 2 )
  {
    v31 = *(_DWORD *)(a2 + 40);
    if ( v31 != 4 )
      goto LABEL_60;
    v32 = *(_DWORD *)(a2 + 72);
    v33 = *(_DWORD *)(a2 + 76);
    v34 = (_DWORD *)a5[23];
    v35 = *(_DWORD *)(a2 + 112);
    v36 = bswap32(*(_DWORD *)(a2 + 68));
    v34[1] = bswap32(*(_DWORD *)(a2 + 64));
    v34[5] = v36;
    v34[9] = bswap32(v32);
    v34[13] = bswap32(v33);
    v37 = *(_DWORD *)(a2 + 56);
    if ( v37 == 16 )
    {
      v38 = 244;
    }
    else
    {
      if ( v37 != 32 )
      {
        v40 = 0;
        goto LABEL_35;
      }
      v38 = 248;
    }
    v40 = *(_DWORD *)(a1 + v38);
LABEL_35:
    if ( *(_DWORD *)(a2 + 36) )
      v40 |= 0x4000u;
    v41 = ((*(_DWORD *)(a2 + 60) << 9) - 512) | v40;
    if ( v30 )
    {
      v42 = v41 | 0x40000;
    }
    else
    {
      v42 = v41 & 0xFFFBFFFF;
      if ( v35 >= 4 )
      {
        v43 = v35 >> 2;
        v44 = (_DWORD *)a5[21];
        v44[1] = v139;
        if ( v43 != 1 )
        {
          v44[5] = HIDWORD(v139);
          if ( v43 != 2 )
          {
            v44[9] = v140;
            if ( v43 != 3 )
            {
              v44[13] = HIDWORD(v140);
              if ( v43 != 4 )
              {
                v44[17] = v141;
                if ( v43 != 5 )
                {
                  v44[21] = HIDWORD(v141);
                  if ( v43 != 6 )
                  {
                    v44[25] = v142;
                    if ( v43 != 7 )
                    {
                      v44[29] = HIDWORD(v142);
                      if ( v43 != 8 )
                      {
                        v44[33] = v143;
                        if ( v43 != 9 )
                        {
                          v44[37] = HIDWORD(v143);
                          if ( v43 != 10 )
                          {
                            v44[41] = v144;
                            if ( v43 != 11 )
                            {
                              v44[45] = HIDWORD(v144);
                              if ( v43 != 12 )
                              {
                                v44[49] = v145;
                                if ( v43 != 13 )
                                {
                                  v44[53] = HIDWORD(v145);
                                  if ( v43 != 14 )
                                  {
                                    v44[57] = v146;
                                    if ( v43 != 15 )
                                    {
                                      v44[61] = HIDWORD(v146);
                                      if ( v43 != 16 )
                                        goto LABEL_267;
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
    }
    *(_DWORD *)(a5[18] + 4LL) = v42;
    v45 = a3;
    if ( *(_DWORD *)(a2 + 36) )
      v45 = a3 - *(_DWORD *)(a2 + 60);
    *(_DWORD *)(a5[19] + 4LL) = v45;
    v39 = 20;
    goto LABEL_59;
  }
  v39 = 18;
LABEL_59:
  *(_DWORD *)(a5[v39] + 4LL) = 0;
  v31 = *(_DWORD *)(a2 + 40);
LABEL_60:
  if ( v31 > 2 )
  {
    if ( v31 == 3 )
    {
      if ( v18 == 16 )
        v46 = *(_DWORD *)(a1 + 172);
      else
        v46 = *(_DWORD *)(a1 + 176);
    }
    else
    {
      if ( v31 != 4 )
      {
LABEL_70:
        if ( v18 == 16 )
          v46 = *(_DWORD *)(a1 + 180);
        else
          v46 = *(_DWORD *)(a1 + 184);
        goto LABEL_80;
      }
      v47 = v18 == 16;
      v48 = 192;
      if ( v47 )
        v48 = 188;
      v46 = *(_DWORD *)(a1 + v48) | 0x2100;
    }
  }
  else
  {
    if ( v31 )
    {
      if ( v31 == 1 )
      {
        if ( v18 == 16 )
          v46 = *(_DWORD *)(a1 + 164);
        else
          v46 = *(_DWORD *)(a1 + 168);
        goto LABEL_80;
      }
      goto LABEL_70;
    }
    if ( v18 == 16 )
      v46 = *(_DWORD *)(a1 + 156);
    else
      v46 = *(_DWORD *)(a1 + 160);
  }
LABEL_80:
  v49 = *(_DWORD *)(a2 + 32);
  if ( v49 == 1 )
  {
    if ( v31 == 1 )
      goto LABEL_134;
    if ( v14 >= 0x11 )
      goto LABEL_198;
    v53 = *(unsigned __int8 **)(a2 + 120);
    if ( v14 >= 4 )
    {
      v62 = v14 >> 2;
      HIDWORD(v138) = bswap32(*(_DWORD *)v53);
      if ( v14 >> 2 == 1 )
      {
        v55 = &v138;
        v54 = 4;
        v53 += 4;
      }
      else
      {
        LODWORD(v138) = bswap32(*((_DWORD *)v53 + 1));
        if ( v62 == 2 )
        {
          v53 += 8;
          v55 = (unsigned __int64 *)((char *)&v137 + 4);
          v54 = 8;
        }
        else
        {
          HIDWORD(v137) = bswap32(*((_DWORD *)v53 + 2));
          if ( v62 == 3 )
          {
            v53 += 12;
            v55 = &v137;
            v54 = 12;
          }
          else
          {
            v71 = *((_DWORD *)v53 + 3);
            v53 += 16;
            v54 = 16;
            v55 = (unsigned __int64 *)bswap32(v71);
            LODWORD(v137) = (_DWORD)v55;
          }
        }
      }
    }
    else
    {
      v54 = 0;
      v55 = (unsigned __int64 *)((char *)&v138 + 4);
    }
    v72 = v14 & 3;
    switch ( v72 )
    {
      case 1:
        v73 = *v53 << 24;
        break;
      case 2:
        v73 = (*v53 << 24) | (v53[1] << 16);
        break;
      case 3:
        v73 = (*v53 << 24) | (v53[1] << 16) | (v53[2] << 8);
        break;
      default:
LABEL_133:
        v74 = v138;
        v75 = a5[8];
        *(_DWORD *)(v75 + 4) = HIDWORD(v138);
        *(_DWORD *)(v75 + 20) = v74;
LABEL_134:
        if ( !v30 )
        {
          v76 = HIDWORD(v139);
          v77 = (_DWORD *)a5[6];
          v77[1] = v139;
          v77[5] = v76;
          v78 = HIDWORD(v140);
          v77[9] = v140;
          v77[13] = v78;
          v79 = HIDWORD(v141);
          v77[17] = v141;
          v70 = 1;
          v77[21] = v79;
LABEL_234:
          v121 = a5[3];
          if ( *(_DWORD *)(a2 + 32) > 1u )
          {
            if ( v21 )
              v46 |= 0x8000u;
            v123 = v46 | ((*(_DWORD *)(a2 + 36) == 0) << 10);
          }
          else
          {
            v122 = *(_DWORD *)(v121 + 4);
            if ( *(_DWORD *)(a2 + 36) )
              v123 = v122 & 0xFFFFFBFF;
            else
              v123 = v122 | 0x400;
          }
          *(_DWORD *)(v121 + 4) = v123 & 0xFFFFBFFF | ((v30 & 1) << 14);
          if ( (*(_BYTE *)(a2 + 172) & 1) != 0 )
          {
            v124 = 0;
          }
          else if ( *(_DWORD *)(a2 + 40) == 4 && *(_DWORD *)(a2 + 36) == 1 )
          {
            v124 = *(_DWORD *)(a2 + 60) + *(_DWORD *)(a2 + 136);
          }
          else
          {
            v124 = *(_DWORD *)(a2 + 136);
          }
          *(_DWORD *)(a5[4] + 4LL) = v124;
          *(_DWORD *)(a5[5] + 4LL) = a4;
          *(_DWORD *)(a5[25] + 4LL) = a3;
          if ( (v70 & 1) == 0 )
          {
            *(_DWORD *)(a5[16] + 4LL) = *(_DWORD *)(a2 + 164);
            *(_DWORD *)(a5[17] + 4LL) = (*(_DWORD *)(a2 + 168) != 0) | (16 * *(_DWORD *)(a2 + 168));
            v125 = *(_DWORD *)(a2 + 132);
            *(_QWORD *)(a1 + 276) = -1;
            if ( v125 == 64 )
              v126 = 0;
            else
              v126 = -1;
            *(_DWORD *)(a1 + 268) = v126;
            *(_DWORD *)(a1 + 272) = v126;
            *(_DWORD *)(a5[13] + 4LL) = -1;
            *(_DWORD *)(a5[12] + 4LL) = *(_DWORD *)(a1 + 276);
            *(_DWORD *)(a5[11] + 4LL) = *(_DWORD *)(a1 + 272);
            *(_DWORD *)(a5[10] + 4LL) = *(_DWORD *)(a1 + 268);
          }
          v127 = *(unsigned int *)(a2 + 176);
          if ( (unsigned int)v127 < 0xA )
          {
            v128 = *(unsigned __int8 *)(a1 + 70260);
            v129 = a1 + 2624 + 7432LL * (unsigned int)v127;
            if ( v128 != 1 )
            {
              if ( (unsigned int)(*(_DWORD *)(v129 + 7416) - 3) < 2 )
              {
                *(_BYTE *)(v129 + 7429) = 0;
                v132 = a5;
                printk(&unk_15BF3, "try_results_dump_enable", v127);
                a5 = v132;
LABEL_258:
                v130 = a5[26];
                *(_DWORD *)(v130 + 4) = 3;
                if ( *(_BYTE *)(v6 + 7429) != 1 )
                  goto LABEL_262;
                *(_DWORD *)(v130 + 4) = 7;
                if ( *(_BYTE *)(v10 + 628) != 1 )
                  goto LABEL_262;
                v131 = *(_DWORD *)(v6 + 7416);
                if ( v21 )
                {
                  if ( v131 != 5 )
                  {
LABEL_262:
                    result = 0;
                    goto LABEL_263;
                  }
                }
                else if ( (unsigned int)(v131 - 3) > 1 )
                {
                  goto LABEL_262;
                }
                result = 0;
                *(_DWORD *)(v130 + 4) = 15;
                goto LABEL_263;
              }
              LOBYTE(v128) = 1;
            }
            *(_BYTE *)(v129 + 7429) = v128;
            goto LABEL_258;
          }
LABEL_267:
          __break(0x5512u);
        }
LABEL_135:
        v70 = 1;
        goto LABEL_234;
    }
    if ( (unsigned __int64)(v54 - 13) < 4 )
      goto LABEL_266;
    *(_DWORD *)v55 = v73;
    goto LABEL_133;
  }
  if ( v49 )
  {
    if ( v31 != 3 )
      goto LABEL_172;
    LODWORD(v147) = 0;
    v135 = 0;
    v136 = 0;
    v134 = 0;
    v133 = 0;
    if ( (v23 & 1) != 0 )
    {
LABEL_164:
      v83 = *(_DWORD *)(a2 + 136);
      v84 = *(unsigned __int8 *)(a2 + 153) << 8;
      if ( v84 == 512 )
      {
        v85 = v83 >= 0x400;
        v86 = 1024;
      }
      else
      {
        if ( v84 != 256 )
        {
LABEL_171:
          *(_DWORD *)(a5[14] + 4LL) = v83;
          v31 = *(_DWORD *)(a2 + 40);
LABEL_172:
          if ( v31 == 1 )
            goto LABEL_214;
          if ( v14 >= 0x11 )
            goto LABEL_198;
          v87 = *(unsigned __int8 **)(a2 + 120);
          if ( v31 == 3 )
          {
            v147 = 0;
            v148 = 0;
            if ( v14 )
            {
              v88 = 16 - v14;
              v89 = 15 - v88;
              if ( 16 - v88 < 15 - v88 )
                v89 = 16 - v88;
              v90 = v89 + 1;
              if ( v89 + 1 > 2 )
              {
                v91 = 16 - v88;
                if ( 16 - v88 >= 15 - v88 )
                  v91 = 15 - v88;
                if ( v14 - 1 >= (unsigned int)v91 && !HIDWORD(v91) )
                {
                  v92 = v90 & 1;
                  v93 = ~v89;
                  if ( (v90 & 1) == 0 )
                    v92 = 2;
                  v94 = v90 - v92;
                  v95 = (char *)&v147 + v88;
                  v96 = v93 + v92;
                  v88 += v94;
                  v97 = v14 - v94;
                  v98 = v14 - 2;
                  v99 = (unsigned __int8 *)(v95 + 1);
                  do
                  {
                    v100 = v87[v98];
                    v96 += 2LL;
                    v101 = v87[v98 + 1];
                    v98 -= 2;
                    *(v99 - 1) = v101;
                    *v99 = v100;
                    v99 += 2;
                  }
                  while ( v96 );
                  v14 = v97;
                }
              }
              v102 = v14 - 1;
              do
              {
                if ( v88 > 0xF )
                  goto LABEL_266;
                v103 = v87[v102--];
                *((_BYTE *)&v147 + v88++) = v103;
              }
              while ( v88 != 16 );
              v14 = bswap32(v147);
              v104 = bswap32(HIDWORD(v147));
              v105 = bswap32(v148);
              v106 = bswap32(HIDWORD(v148));
            }
            else
            {
              v104 = 0;
              v105 = 0;
              v106 = 0;
            }
            v138 = __PAIR64__(v14, v104);
            v137 = __PAIR64__(v105, v106);
            goto LABEL_212;
          }
          if ( v14 >= 4 )
          {
            v109 = v14 >> 2;
            HIDWORD(v138) = bswap32(*(_DWORD *)v87);
            if ( v14 >> 2 == 1 )
            {
              v108 = &v138;
              v107 = 4;
              v87 += 4;
            }
            else
            {
              LODWORD(v138) = bswap32(*((_DWORD *)v87 + 1));
              if ( v109 == 2 )
              {
                v87 += 8;
                v108 = (unsigned __int64 *)((char *)&v137 + 4);
                v107 = 8;
              }
              else
              {
                HIDWORD(v137) = bswap32(*((_DWORD *)v87 + 2));
                if ( v109 == 3 )
                {
                  v87 += 12;
                  v108 = &v137;
                  v107 = 12;
                }
                else
                {
                  v111 = *((_DWORD *)v87 + 3);
                  v87 += 16;
                  v107 = 16;
                  v108 = (unsigned __int64 *)bswap32(v111);
                  LODWORD(v137) = (_DWORD)v108;
                }
              }
            }
          }
          else
          {
            v107 = 0;
            v108 = (unsigned __int64 *)((char *)&v138 + 4);
          }
          v112 = v14 & 3;
          switch ( v112 )
          {
            case 1:
              v113 = *v87 << 24;
              break;
            case 2:
              v113 = (*v87 << 24) | (v87[1] << 16);
              break;
            case 3:
              v113 = (*v87 << 24) | (v87[1] << 16) | (v87[2] << 8);
              break;
            default:
LABEL_212:
              v115 = v138;
              v114 = HIDWORD(v138);
              v117 = v137;
              v116 = HIDWORD(v137);
              v118 = (_DWORD *)a5[8];
              v118[1] = HIDWORD(v138);
              v118[5] = v115;
              v118[9] = v116;
              v118[13] = v117;
              if ( *(_DWORD *)(a2 + 40) == 4 )
              {
                v119 = (_DWORD *)a5[9];
                v119[1] = v114;
                v119[5] = v115;
                v119[9] = v116;
                v119[13] = v117;
                ++*(_DWORD *)(a5[8] + 52LL);
              }
LABEL_214:
              v70 = 0;
              if ( !v30 && *(_DWORD *)a2 != 1 && v22 )
              {
                v120 = (_DWORD *)a5[6];
                v120[1] = v139;
                if ( v22 != 1 )
                {
                  v120[5] = HIDWORD(v139);
                  if ( v22 != 2 )
                  {
                    v120[9] = v140;
                    if ( v22 != 3 )
                    {
                      v120[13] = HIDWORD(v140);
                      if ( v22 != 4 )
                      {
                        v120[17] = v141;
                        if ( v22 != 5 )
                        {
                          v120[21] = HIDWORD(v141);
                          if ( v22 != 6 )
                          {
                            v120[25] = v142;
                            if ( v22 != 7 )
                            {
                              v120[29] = HIDWORD(v142);
                              if ( v22 != 8 )
                              {
                                v120[33] = v143;
                                if ( v22 != 9 )
                                {
                                  v120[37] = HIDWORD(v143);
                                  if ( v22 != 10 )
                                  {
                                    v120[41] = v144;
                                    if ( v22 != 11 )
                                    {
                                      v120[45] = HIDWORD(v144);
                                      if ( v22 != 12 )
                                      {
                                        v120[49] = v145;
                                        if ( v22 != 13 )
                                        {
                                          v120[53] = HIDWORD(v145);
                                          if ( v22 != 14 )
                                          {
                                            v120[57] = v146;
                                            if ( v22 != 15 )
                                            {
                                              v120[61] = HIDWORD(v146);
                                              if ( v22 != 16 )
                                                goto LABEL_267;
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
                v70 = 0;
              }
              goto LABEL_234;
          }
          if ( (unsigned __int64)(v107 - 13) < 4 )
            goto LABEL_266;
          *(_DWORD *)v108 = v113;
          goto LABEL_212;
        }
        v85 = v83 >= 0x200;
        v86 = 512;
      }
      if ( v85 )
        v83 = v86;
      goto LABEL_171;
    }
    v56 = *(unsigned int *)(a2 + 112);
    v57 = (unsigned int)v56 >> 3;
    v58 = (unsigned __int8 *)(*(_QWORD *)(a2 + 104) + (v56 >> 1));
    if ( (unsigned int)v56 >= 8 )
    {
      LODWORD(v147) = bswap32(*(_DWORD *)v58);
      if ( v57 == 1 )
      {
        v60 = (__int64 *)((char *)&v136 + 4);
        v59 = 4;
        v58 += 4;
      }
      else
      {
        HIDWORD(v136) = bswap32(*((_DWORD *)v58 + 1));
        if ( v57 == 2 )
        {
          v58 += 8;
          v60 = &v136;
          v59 = 8;
        }
        else
        {
          LODWORD(v136) = bswap32(*((_DWORD *)v58 + 2));
          if ( v57 == 3 )
          {
            v58 += 12;
            v60 = (__int64 *)((char *)&v135 + 4);
            v59 = 12;
          }
          else
          {
            HIDWORD(v135) = bswap32(*((_DWORD *)v58 + 3));
            if ( v57 == 4 )
            {
              v58 += 16;
              v60 = &v135;
              v59 = 16;
            }
            else
            {
              LODWORD(v135) = bswap32(*((_DWORD *)v58 + 4));
              if ( v57 == 5 )
              {
                v58 += 20;
                v60 = (__int64 *)((char *)&v134 + 4);
                v59 = 20;
              }
              else
              {
                HIDWORD(v134) = bswap32(*((_DWORD *)v58 + 5));
                if ( v57 == 6 )
                {
                  v58 += 24;
                  v60 = &v134;
                  v59 = 24;
                }
                else
                {
                  LODWORD(v134) = bswap32(*((_DWORD *)v58 + 6));
                  if ( v57 == 7 )
                  {
                    v58 += 28;
                    v60 = (__int64 *)&v133;
                    v59 = 28;
                  }
                  else
                  {
                    v60 = (__int64 *)bswap32(*((_DWORD *)v58 + 7));
                    v133 = (int)v60;
                    if ( v57 != 8 )
                      goto LABEL_266;
                    v58 += 32;
                    v59 = 32;
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v59 = 0;
      v60 = &v147;
    }
    v80 = ((unsigned int)v56 >> 1) & 3;
    switch ( v80 )
    {
      case 1u:
        v81 = *v58 << 24;
        break;
      case 2u:
        v81 = (*v58 << 24) | (v58[1] << 16);
        break;
      case 3u:
        v81 = (*v58 << 24) | (v58[1] << 16) | (v58[2] << 8);
        break;
      default:
LABEL_155:
        if ( (unsigned int)v56 >= 8 )
        {
          v82 = (_DWORD *)a5[7];
          v82[1] = v147;
          if ( v57 != 1 )
          {
            v82[5] = HIDWORD(v136);
            if ( v57 != 2 )
            {
              v82[9] = v136;
              if ( v57 != 3 )
              {
                v82[13] = HIDWORD(v135);
                if ( v57 != 4 )
                {
                  v82[17] = v135;
                  if ( v57 != 5 )
                  {
                    v82[21] = HIDWORD(v134);
                    if ( v57 != 6 )
                    {
                      v82[25] = v134;
                      if ( v57 != 7 )
                      {
                        v82[29] = v133;
                        if ( v57 != 8 )
                          goto LABEL_267;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LABEL_164;
    }
    if ( v59 > 0x1C )
      goto LABEL_266;
    *(_DWORD *)v60 = v81;
    goto LABEL_155;
  }
  if ( v31 == 1 )
    goto LABEL_122;
  if ( v14 < 0x11 )
  {
    v50 = *(unsigned __int8 **)(a2 + 120);
    if ( v14 >= 4 )
    {
      v61 = v14 >> 2;
      HIDWORD(v138) = bswap32(*(_DWORD *)v50);
      if ( v14 >> 2 == 1 )
      {
        v52 = &v138;
        v51 = 4;
        v50 += 4;
      }
      else
      {
        LODWORD(v138) = bswap32(*((_DWORD *)v50 + 1));
        if ( v61 == 2 )
        {
          v50 += 8;
          v52 = (unsigned __int64 *)((char *)&v137 + 4);
          v51 = 8;
        }
        else
        {
          HIDWORD(v137) = bswap32(*((_DWORD *)v50 + 2));
          if ( v61 == 3 )
          {
            v50 += 12;
            v52 = &v137;
            v51 = 12;
          }
          else
          {
            v63 = *((_DWORD *)v50 + 3);
            v50 += 16;
            v51 = 16;
            v52 = (unsigned __int64 *)bswap32(v63);
            LODWORD(v137) = (_DWORD)v52;
          }
        }
      }
    }
    else
    {
      v51 = 0;
      v52 = (unsigned __int64 *)((char *)&v138 + 4);
    }
    v64 = v14 & 3;
    switch ( v64 )
    {
      case 1:
        v65 = *v50 << 24;
        break;
      case 2:
        v65 = (*v50 << 24) | (v50[1] << 16);
        break;
      case 3:
        v65 = (*v50 << 24) | (v50[1] << 16) | (v50[2] << 8);
        break;
      default:
LABEL_121:
        v66 = v138;
        v67 = a5[8];
        *(_DWORD *)(v67 + 4) = HIDWORD(v138);
        *(_DWORD *)(v67 + 20) = v66;
LABEL_122:
        if ( !v30 )
        {
          v68 = HIDWORD(v139);
          v69 = a5[6];
          *(_DWORD *)(v69 + 4) = v139;
          v70 = 1;
          *(_DWORD *)(v69 + 20) = v68;
          goto LABEL_234;
        }
        goto LABEL_135;
    }
    if ( (unsigned __int64)(v51 - 13) >= 4 )
    {
      *(_DWORD *)v52 = v65;
      goto LABEL_121;
    }
LABEL_266:
    __break(1u);
    goto LABEL_267;
  }
LABEL_198:
  printk(&unk_1507D, "_ce_setup_cipher", "_ce_setup_cipher");
  result = 4294967274LL;
LABEL_263:
  _ReadStatusReg(SP_EL0);
  return result;
}
