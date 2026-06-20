__int64 __fastcall swrm_copy_data_port_config(__int64 a1, unsigned __int8 a2)
{
  __int64 v3; // x19
  __int64 v4; // x12
  __int64 v5; // x0
  __int64 v6; // x2
  int v7; // w10
  int v8; // w8
  unsigned int v9; // w22
  int v10; // w4
  int v11; // w5
  int v12; // w6
  __int64 v13; // x21
  __int64 v14; // x26
  __int64 v15; // x25
  int v16; // w23
  int v17; // w20
  int v18; // w27
  __int64 *v19; // x10
  int v20; // w11
  int v21; // w8
  int v22; // w9
  int v23; // w14
  __int64 v24; // x12
  int v25; // w14
  unsigned int v26; // w15
  int v27; // w14
  char v28; // w13
  int v29; // w13
  unsigned int v30; // w14
  unsigned int v31; // w13
  int v32; // w13
  int v33; // w13
  unsigned int v34; // w13
  int v35; // w13
  unsigned int v36; // w13
  unsigned int v37; // w13
  int v38; // w15
  char v39; // w13
  int v40; // w14
  int v41; // w16
  char v42; // w13
  bool v43; // zf
  int v44; // w16
  char v45; // w13
  unsigned int v46; // w15
  int v47; // w16
  char v48; // w13
  char *v49; // x15
  unsigned int v50; // w14
  char v51; // w17
  char v52; // w16
  int v53; // w14
  char v54; // w13
  int v55; // w14
  char v56; // w13
  int v57; // w14
  char v58; // w13
  int v59; // w14
  int v60; // w13
  int v61; // w14
  int v62; // w15
  char v63; // w17
  int v64; // w15
  char v65; // w17
  int v66; // w13
  int v67; // w15
  char v68; // w13
  int v69; // w14
  char v70; // w13
  int v71; // w14
  char v72; // w13
  int v73; // w14
  char v74; // w13
  int v75; // w14
  char v76; // w13
  int v77; // w14
  char v78; // w13
  int v79; // w14
  char v80; // w13
  int v81; // w13
  int v82; // w15
  char v83; // w13
  int v84; // w12
  int v85; // w14
  int v86; // w13
  char v87; // w15
  int v88; // w14
  int *v89; // x13
  int v90; // w14
  int v91; // w15
  int v92; // w14
  int v93; // w13
  int v94; // w16
  char v95; // w13
  int v96; // w13
  int v97; // w12
  char v98; // w14
  int v99; // w12
  int v100; // w14
  int v101; // w13
  char v102; // w15
  int v103; // w14
  int v104; // w13
  int v105; // w12
  char v106; // w15
  int v107; // w12
  int v108; // w15
  int v109; // w10
  __int64 v110; // x9
  int v111; // w8
  int v112; // w8
  unsigned int v113; // w9
  int v114; // w10
  int v115; // w10
  int v116; // w8
  int v117; // w9
  int v118; // w10
  unsigned int v119; // w9
  unsigned int v120; // w9
  int v121; // w10
  __int64 result; // x0
  int v123; // [xsp+8h] [xbp-568h]
  int v124; // [xsp+Ch] [xbp-564h]
  int v125; // [xsp+10h] [xbp-560h]
  int v126; // [xsp+14h] [xbp-55Ch]
  int v127; // [xsp+18h] [xbp-558h]
  int v128; // [xsp+1Ch] [xbp-554h]
  int v129; // [xsp+20h] [xbp-550h]
  int v130; // [xsp+24h] [xbp-54Ch]
  int v131; // [xsp+28h] [xbp-548h]
  int v132; // [xsp+2Ch] [xbp-544h]
  int v133; // [xsp+30h] [xbp-540h]
  int v134; // [xsp+3Ch] [xbp-534h]
  __int64 v135; // [xsp+40h] [xbp-530h]
  int v136; // [xsp+4Ch] [xbp-524h]
  _QWORD v137[19]; // [xsp+50h] [xbp-520h] BYREF
  __int16 v138; // [xsp+E8h] [xbp-488h]
  _QWORD v139[19]; // [xsp+F0h] [xbp-480h] BYREF
  __int16 v140; // [xsp+188h] [xbp-3E8h]
  _QWORD v141[2]; // [xsp+190h] [xbp-3E0h] BYREF
  _DWORD v142[120]; // [xsp+1A0h] [xbp-3D0h] BYREF
  _DWORD s[120]; // [xsp+380h] [xbp-1F0h] BYREF
  __int64 v144; // [xsp+560h] [xbp-10h]

  v144 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
    v3 = *(_QWORD *)(a1 + 152);
  else
    v3 = 0;
  memset(s, 0, sizeof(s));
  memset(v142, 0, sizeof(v142));
  memset(v141, 0, 11);
  if ( v3 )
  {
    v4 = 0;
    v5 = v3 + 9152;
    v6 = v3 + 15912;
    v7 = 16 * a2;
    v8 = a2 << 6;
    v9 = 0;
    v140 = 0;
    v10 = v7 + 288;
    v134 = v7 + 291;
    v11 = v7 + 290;
    v136 = v7 + 293;
    v12 = v7 + 292;
    v131 = v7 + 295;
    v132 = v7 + 294;
    v128 = v7 + 296;
    v129 = v8 + 4132;
    v130 = v7 + 289;
    v127 = v8 + 4156;
    v126 = v8 + 4136;
    v124 = v8 + 4144;
    v125 = v8 + 4148;
    memset(v139, 0, sizeof(v139));
    v138 = 0;
    v123 = v8 + 4152;
    memset(v137, 0, sizeof(v137));
    while ( 1 )
    {
      while ( 1 )
      {
        v13 = v5 + 40 * v4;
        if ( (*(_BYTE *)(v13 + 16) & 1) != 0 )
          break;
        if ( ++v4 == 13 )
          goto LABEL_219;
      }
      v14 = v6;
      v15 = v5;
      v16 = v12;
      v17 = v11;
      v18 = v10;
      memset(v141, 255, 11);
      v133 = v4;
      v135 = v4 + 1;
      swrm_pcm_port_config(v3, v4 + 1, v13, 1);
      v19 = *(__int64 **)v13;
      if ( *(_QWORD *)v13 != v13 )
      {
        v5 = v15;
        v6 = v14;
        v20 = 0;
        v21 = 0;
        v22 = 0xFFFF;
        v10 = v18;
        v11 = v17;
        v12 = v16;
        while ( 2 )
        {
          if ( !*((_BYTE *)v19 - 8) )
            goto LABEL_13;
          v23 = *(_DWORD *)(v3 + 9052);
          v24 = *((unsigned __int8 *)v19 - 6);
          if ( v23 > 3 )
          {
            if ( v23 != 4 )
            {
              if ( v23 == 5 )
              {
                v27 = *((unsigned __int8 *)v19 + 21);
                *((_WORD *)v19 - 1) = (unsigned int)(2 * *(_DWORD *)(v3 + 9136)) / *((_DWORD *)v19 + 7) - 1;
                v28 = *(_BYTE *)(v13 + 19);
                *((_BYTE *)v19 - 4) = 0;
                *((_BYTE *)v19 - 5) = v28;
                *(_WORD *)((char *)v19 + 17) = 3841;
                if ( !v27 )
                {
                  LOBYTE(v27) = 15;
                  *((_BYTE *)v19 + 21) = 15;
                }
                LOBYTE(v29) = 0;
                *(_BYTE *)(v13 + 28) = v27;
                *(_WORD *)((char *)v19 + 19) = -1;
                goto LABEL_33;
              }
              goto LABEL_28;
            }
          }
          else if ( v23 != 2 )
          {
            if ( v23 == 3 )
            {
              v25 = *(_DWORD *)(v3 + 9136);
              switch ( v25 )
              {
                case 600000:
                  v26 = 3;
                  break;
                case 4800000:
                  v26 = 1;
                  break;
                case 1200000:
                  v26 = 2;
                  break;
                default:
                  v26 = 0;
                  break;
              }
              v36 = v24 + 14 * *((unsigned __int8 *)v19 - 8) - 14;
              if ( v36 > 0x99 )
                goto LABEL_48;
              v89 = (int *)(v14 + 1232LL * v26 + 8LL * v36);
              *((_WORD *)v19 - 1) = (unsigned int)(2 * v25) / *((_DWORD *)v19 + 7) - 1;
              v90 = *((unsigned __int8 *)v19 + 21);
              v91 = *v89;
              *((_BYTE *)v19 - 4) = 0;
              *(_WORD *)((char *)v19 + 17) = -1;
              *((_BYTE *)v19 - 5) = v91;
              if ( v90 )
                *(_BYTE *)(v13 + 28) = v90;
              else
                *((_BYTE *)v19 + 21) = -1;
              *(_WORD *)((char *)v19 + 19) = -1;
              v29 = v89[1];
LABEL_33:
              *((_BYTE *)v19 + 22) = v29;
              if ( *(_DWORD *)(v3 + 9052) == 1 )
              {
                v33 = *(_DWORD *)(v3 + 9136);
                if ( v33 == 600000 )
                {
                  v34 = 3;
                }
                else if ( v33 == 4800000 )
                {
                  v34 = 1;
                }
                else
                {
                  v34 = v33 == 1200000 ? 2 : 0;
                }
                if ( *((unsigned __int8 *)v19 - 6) + 14 * (unsigned int)*((unsigned __int8 *)v19 - 8) - 14 <= 0x99 )
                {
                  v35 = *(_DWORD *)(v14
                                  + 1232LL * v34
                                  + 8LL
                                  * (*((unsigned __int8 *)v19 - 6)
                                   + 14 * (unsigned int)*((unsigned __int8 *)v19 - 8)
                                   - 14));
                  if ( v35 )
                    *((_BYTE *)v19 - 5) = v35;
                }
              }
LABEL_48:
              if ( v20 )
              {
                if ( v22 != *((unsigned __int16 *)v19 - 1) || v21 != *((unsigned __int8 *)v19 + 22) )
                {
                  result = __ratelimit(&swrm_copy_data_port_config__rs_163, "swrm_copy_data_port_config");
                  if ( (_DWORD)result )
                    result = dev_err(
                               *(_QWORD *)(v3 + 8512),
                               "%s:slaves/slave ports attaching to mport%d are not using same SI or data lane, update sla"
                               "ve tables,bailing out without setting port config\n",
                               "swrm_copy_data_port_config",
                               v133);
                  goto LABEL_224;
                }
              }
              else
              {
                v21 = *((unsigned __int8 *)v19 + 22);
                v22 = *((unsigned __int16 *)v19 - 1);
              }
              v37 = *((unsigned __int8 *)v19 - 8);
              if ( v37 > 0xA || (unsigned int)v24 > 0xD )
                goto LABEL_226;
              if ( v24 + 14 * (unsigned __int64)*((unsigned __int8 *)v19 - 8) > 0x99 )
                goto LABEL_225;
              *((_BYTE *)v139 + 14 * *((unsigned __int8 *)v19 - 8) + v24) |= *((_BYTE *)v19 + 24);
              if ( (int)v9 <= 119 )
              {
                if ( v9 > 0x77 )
                  goto LABEL_226;
                s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                v38 = *(unsigned __int8 *)(v3 + 9050);
                v39 = (v38 + 1) & 0xF;
                if ( v38 == 14 )
                  v39 = 0;
                *(_BYTE *)(v3 + 9050) = v39;
                v37 = *((unsigned __int8 *)v19 - 8);
                if ( v37 > 0xA )
                  goto LABEL_226;
                if ( v24 + 14 * (unsigned __int64)*((unsigned __int8 *)v19 - 8) > 0x99 )
                  goto LABEL_225;
                v40 = (_DWORD)v24 << 8;
                v142[v9] = (v18 + ((_DWORD)v24 << 8))
                         | (v38 << 16)
                         | (*((unsigned __int8 *)v19 - 8) << 20)
                         | (*((unsigned __int8 *)v139 + 14 * *((unsigned __int8 *)v19 - 8) + v24) << 24);
                if ( v9 == 119 )
                {
                  v9 = 120;
                }
                else
                {
                  s[v9 + 1] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                  v41 = *(unsigned __int8 *)(v3 + 9050);
                  v42 = v41 + 1;
                  v43 = v41 == 14;
                  v44 = (v17 + v40) | (v41 << 16);
                  v45 = v42 & 0xF;
                  if ( v43 )
                    v45 = 0;
                  *(_BYTE *)(v3 + 9050) = v45;
                  v37 = *((unsigned __int8 *)v19 - 8);
                  v142[v9 + 1] = v44 | (v37 << 20) | (*((unsigned __int16 *)v19 - 1) << 24);
                  if ( v9 > 0x75 )
                  {
                    v9 = 120;
                  }
                  else
                  {
                    v46 = v9 + 2;
                    v9 += 3;
                    s[v46] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v47 = *(unsigned __int8 *)(v3 + 9050);
                    v48 = (v47 + 1) & 0xF;
                    if ( v47 == 14 )
                      v48 = 0;
                    *(_BYTE *)(v3 + 9050) = v48;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v46] = (v134 + v40)
                              | (v47 << 16)
                              | (v37 << 20)
                              | (HIBYTE(*((unsigned __int16 *)v19 - 1)) << 24);
                  }
                  if ( v37 > 0xA )
                    goto LABEL_226;
                }
              }
              if ( v24 + 14 * (unsigned __int64)v37 > 0x99 )
                goto LABEL_225;
              v49 = (char *)v137 + 14 * v37;
              v50 = *((unsigned __int8 *)v19 - 5);
              if ( (unsigned __int8)v49[v24] >= v50 )
                v51 = *((_BYTE *)v19 - 5);
              else
                v51 = v49[v24];
              if ( v49[v24] )
                v52 = v51;
              else
                v52 = *((_BYTE *)v19 - 5);
              v49[v24] = v52;
              if ( v9 <= 0x77 )
              {
                if ( v50 == 255 )
                  goto LABEL_87;
                s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                v53 = *(unsigned __int8 *)(v3 + 9050);
                v54 = (v53 + 1) & 0xF;
                if ( v53 == 14 )
                  v54 = 0;
                *(_BYTE *)(v3 + 9050) = v54;
                v37 = *((unsigned __int8 *)v19 - 8);
                if ( v37 > 0xA )
                  goto LABEL_226;
                if ( v24 + 14 * (unsigned __int64)*((unsigned __int8 *)v19 - 8) > 0x99 )
                  goto LABEL_225;
                v142[v9] = (v16 + ((_DWORD)v24 << 8))
                         | (v53 << 16)
                         | (*((unsigned __int8 *)v19 - 8) << 20)
                         | (*((unsigned __int8 *)v137 + 14 * *((unsigned __int8 *)v19 - 8) + v24) << 24);
                if ( v9 != 119 )
                {
                  ++v9;
LABEL_87:
                  if ( *((unsigned __int8 *)v19 - 4) != 255 )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v55 = *(unsigned __int8 *)(v3 + 9050);
                    v56 = v55 + 1;
                    v43 = v55 == 14;
                    v57 = (v136 + ((_DWORD)v24 << 8)) | (v55 << 16);
                    v58 = v56 & 0xF;
                    if ( v43 )
                      v58 = 0;
                    *(_BYTE *)(v3 + 9050) = v58;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v9] = v57 | (v37 << 20) | (*((unsigned __int8 *)v19 - 4) << 24);
                    if ( v9 != 119 )
                    {
                      ++v9;
                      goto LABEL_93;
                    }
LABEL_155:
                    v84 = 120;
                    goto LABEL_156;
                  }
LABEL_93:
                  v59 = *((unsigned __int8 *)v19 + 17);
                  if ( v59 != 255 )
                  {
                    v60 = *((unsigned __int8 *)v19 + 18);
                    if ( v60 != 255 )
                    {
                      if ( v9 > 0x77 )
                        goto LABEL_225;
                      v61 = (v59 << 28) | (v60 << 24);
                      s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                      v62 = *(unsigned __int8 *)(v3 + 9050);
                      v63 = v62 + 1;
                      v43 = v62 == 14;
                      v64 = (v132 + ((_DWORD)v24 << 8)) | (v62 << 16);
                      v65 = v63 & 0xF;
                      if ( v43 )
                        v65 = 0;
                      *(_BYTE *)(v3 + 9050) = v65;
                      v37 = *((unsigned __int8 *)v19 - 8);
                      v142[v9] = v64 | v61 | (v37 << 20);
                      if ( v9 == 119 )
                        goto LABEL_155;
                      ++v9;
                    }
                  }
                  if ( *((unsigned __int8 *)v19 + 21) != 255 )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v66 = *(unsigned __int8 *)(v3 + 9050);
                    v67 = v66 << 16;
                    if ( v66 == 14 )
                      v68 = 0;
                    else
                      v68 = (v66 + 1) & 0xF;
                    *(_BYTE *)(v3 + 9050) = v68;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v9] = ((v67 | ((_DWORD)v24 << 8)) + 259) | (v37 << 20) | (*((unsigned __int8 *)v19 + 21) << 24);
                    if ( v9 == 119 )
                      goto LABEL_155;
                    ++v9;
                  }
                  if ( *((unsigned __int8 *)v19 + 20) != 255 )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v69 = *(unsigned __int8 *)(v3 + 9050);
                    v70 = v69 + 1;
                    v43 = v69 == 14;
                    v71 = (v131 + ((_DWORD)v24 << 8)) | (v69 << 16);
                    v72 = v70 & 0xF;
                    if ( v43 )
                      v72 = 0;
                    *(_BYTE *)(v3 + 9050) = v72;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v9] = v71 | (v37 << 20) | (*((unsigned __int8 *)v19 + 20) << 24);
                    if ( v9 == 119 )
                      goto LABEL_155;
                    ++v9;
                  }
                  if ( *((unsigned __int8 *)v19 + 19) != 255 )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v73 = *(unsigned __int8 *)(v3 + 9050);
                    v74 = v73 + 1;
                    v43 = v73 == 14;
                    v75 = (v130 + ((_DWORD)v24 << 8)) | (v73 << 16);
                    v76 = v74 & 0xF;
                    if ( v43 )
                      v76 = 0;
                    *(_BYTE *)(v3 + 9050) = v76;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v9] = v75 | (v37 << 20) | (*((unsigned __int8 *)v19 + 19) << 24);
                    if ( v9 == 119 )
                      goto LABEL_155;
                    ++v9;
                  }
                  if ( *((unsigned __int8 *)v19 + 22) != 255 )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v77 = *(unsigned __int8 *)(v3 + 9050);
                    v78 = v77 + 1;
                    v43 = v77 == 14;
                    v79 = (v128 + ((_DWORD)v24 << 8)) | (v77 << 16);
                    v80 = v78 & 0xF;
                    if ( v43 )
                      v80 = 0;
                    *(_BYTE *)(v3 + 9050) = v80;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v9] = v79 | (v37 << 20) | (*((unsigned __int8 *)v19 + 22) << 24);
                    if ( v9 == 119 )
                      goto LABEL_155;
                    ++v9;
                  }
                  if ( *((_DWORD *)v19 + 8) == *((_DWORD *)v19 + 7) )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v81 = *(unsigned __int8 *)(v3 + 9050);
                    v82 = v81 << 16;
                    v43 = v81 == 14;
                    v83 = (v81 + 1) & 0xF;
                    if ( v43 )
                      v83 = 0;
                    *(_BYTE *)(v3 + 9050) = v83;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v9] = ((v82 | ((_DWORD)v24 << 8)) + 258) | (v37 << 20);
                    if ( v9 == 119 )
                      goto LABEL_155;
                    v84 = v9 + 1;
                    if ( *(_DWORD *)(v3 + 9052) == 5 )
                    {
                      s[v84] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                      v85 = *(unsigned __int8 *)(v3 + 9050);
                      v86 = *((unsigned __int8 *)v19 - 6) << 8;
                      v87 = (v85 + 1) & 0xF;
                      if ( v85 == 14 )
                        v87 = 0;
                      *(_BYTE *)(v3 + 9050) = v87;
                      v88 = (v86 + 468) | (v85 << 16);
                      v37 = *((unsigned __int8 *)v19 - 8);
                      v142[v84] = v88 | (v37 << 20);
                      v84 = v9 + 2;
                    }
                    goto LABEL_156;
                  }
                  if ( *(_BYTE *)(v13 + 30) == 1 )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    v92 = 0x2000000;
LABEL_144:
                    s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                    v93 = *(unsigned __int8 *)(v3 + 9050);
                    v94 = v93 << 16;
                    v43 = v93 == 14;
                    v95 = (v93 + 1) & 0xF;
                    if ( v43 )
                      v95 = 0;
                    *(_BYTE *)(v3 + 9050) = v95;
                    v37 = *((unsigned __int8 *)v19 - 8);
                    v142[v9] = ((v94 | ((_DWORD)v24 << 8)) + 258) | (v37 << 20) | v92;
                    if ( v9 > 0x76 )
                      goto LABEL_155;
                    ++v9;
                  }
                  else if ( !*(_BYTE *)(v13 + 30) )
                  {
                    if ( v9 > 0x77 )
                      goto LABEL_225;
                    v92 = 0x1000000;
                    goto LABEL_144;
                  }
                  if ( v9 > 0x77 )
                    goto LABEL_225;
                  s[v9] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                  v96 = *(unsigned __int8 *)(v3 + 9050);
                  v97 = *((unsigned __int8 *)v19 - 6) << 8;
                  v98 = (v96 + 1) & 0xF;
                  if ( v96 == 14 )
                    v98 = 0;
                  *(_BYTE *)(v3 + 9050) = v98;
                  v99 = (v97 + 468) | (v96 << 16);
                  v37 = *((unsigned __int8 *)v19 - 8);
                  v142[v9] = v99 | (v37 << 20) | 0x4000000;
                  if ( v9 == 119 )
                    goto LABEL_155;
                  s[v9 + 1] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                  v100 = *(unsigned __int8 *)(v3 + 9050);
                  v101 = *((unsigned __int8 *)v19 - 6) << 8;
                  v102 = (v100 + 1) & 0xF;
                  if ( v100 == 14 )
                    v102 = 0;
                  *(_BYTE *)(v3 + 9050) = v102;
                  v103 = (v101 + 460) | (v100 << 16);
                  v37 = *((unsigned __int8 *)v19 - 8);
                  v142[v9 + 1] = v103 | (v37 << 20) | 0x1000000;
                  if ( v9 == 118 )
                    goto LABEL_155;
                  s[v9 + 2] = (*(_DWORD *)(v3 + 9056) << 12) + 16416;
                  v104 = *(unsigned __int8 *)(v3 + 9050);
                  v105 = *((unsigned __int8 *)v19 - 6) << 8;
                  v106 = (v104 + 1) & 0xF;
                  if ( v104 == 14 )
                    v106 = 0;
                  *(_BYTE *)(v3 + 9050) = v106;
                  v107 = (v105 + 452) | (v104 << 16);
                  v37 = *((unsigned __int8 *)v19 - 8);
                  v108 = v107 | (v37 << 20) | 0x1000000;
                  v84 = v9 + 3;
                  v142[v9 + 2] = v108;
LABEL_156:
                  v9 = v84;
                  *((_BYTE *)v19 + 23) = *((_BYTE *)v19 + 24);
                  if ( v37 > 0xA )
                    goto LABEL_226;
LABEL_12:
                  ++v20;
                  *((_BYTE *)v141 + v37) = *((_BYTE *)v19 - 5);
LABEL_13:
                  v19 = (__int64 *)*v19;
                  if ( v19 == (__int64 *)v13 )
                    goto LABEL_162;
                  continue;
                }
                v9 = 120;
              }
              *((_BYTE *)v19 + 23) = *((_BYTE *)v19 + 24);
              goto LABEL_12;
            }
LABEL_28:
            v30 = *((_DWORD *)v19 + 7);
            v31 = 2 * *(_DWORD *)(v3 + 9136) / v30 - 1;
            *((_WORD *)v19 - 1) = 2 * *(_DWORD *)(v3 + 9136) / v30 - 1;
            *(_WORD *)(v13 + 22) = v31;
LABEL_29:
            *((_BYTE *)v19 - 5) = *(_BYTE *)(v13 + 19);
            *((_BYTE *)v19 - 4) = *(_BYTE *)(v13 + 20);
            *((_BYTE *)v19 + 17) = *(_BYTE *)(v13 + 24);
            v32 = *((unsigned __int8 *)v19 + 21);
            *((_BYTE *)v19 + 18) = *(_BYTE *)(v13 + 25);
            if ( v32 )
              *(_BYTE *)(v13 + 28) = v32;
            else
              *((_BYTE *)v19 + 21) = *(_BYTE *)(v13 + 28);
            *((_BYTE *)v19 + 20) = *(_BYTE *)(v13 + 27);
            *((_BYTE *)v19 + 19) = *(_BYTE *)(v13 + 26);
            LOBYTE(v29) = *(_BYTE *)(v13 + 29);
            goto LABEL_33;
          }
          break;
        }
        *((_WORD *)v19 - 1) = *(_WORD *)(v13 + 22);
        goto LABEL_29;
      }
      LOBYTE(v21) = 0;
      LOWORD(v22) = -1;
      v5 = v15;
      v6 = v14;
      v10 = v18;
      v11 = v17;
      v12 = v16;
LABEL_162:
      v109 = *(_DWORD *)(v3 + 9052);
      if ( v109 == 5 )
      {
        *(_WORD *)(v13 + 22) = v22;
        v110 = 25;
        *(_BYTE *)(v13 + 29) = v21;
        LOBYTE(v21) = 15;
        *(_BYTE *)(v13 + 24) = 1;
      }
      else
      {
        if ( v109 != 3 )
          goto LABEL_167;
        *(_WORD *)(v13 + 22) = v22;
        v110 = 29;
      }
      *(_BYTE *)(v13 + v110) = v21;
LABEL_167:
      v111 = *(unsigned __int8 *)(v13 + 20);
      if ( v111 == 255 )
        v112 = 0;
      else
        v112 = v111 << 16;
      if ( *(_DWORD *)(v3 + 9052) == 3 )
      {
        v113 = BYTE1(v141[0]);
        if ( BYTE1(v141[0]) >= (unsigned int)BYTE2(v141[0]) )
          v113 = BYTE2(v141[0]);
        if ( v113 >= BYTE3(v141[0]) )
          v113 = BYTE3(v141[0]);
        if ( v113 >= BYTE4(v141[0]) )
          v113 = BYTE4(v141[0]);
        if ( v113 >= BYTE5(v141[0]) )
          v113 = BYTE5(v141[0]);
        if ( v113 >= BYTE6(v141[0]) )
          v113 = BYTE6(v141[0]);
        if ( v113 >= HIBYTE(v141[0]) )
          v113 = HIBYTE(v141[0]);
        if ( v113 >= LOBYTE(v141[1]) )
          v113 = LOBYTE(v141[1]);
        if ( v113 >= BYTE1(v141[1]) )
          v113 = BYTE1(v141[1]);
        if ( v113 >= BYTE2(v141[1]) )
          v113 = BYTE2(v141[1]);
        if ( v113 >= 0xF )
          LOBYTE(v113) = 15;
      }
      else
      {
        LOBYTE(v113) = *(_BYTE *)(v13 + 19);
      }
      v114 = *(unsigned __int8 *)(v13 + 18);
      *(_BYTE *)(v13 + 19) = v113;
      if ( (int)v9 <= 119 )
      {
        if ( v9 > 0x77 )
          goto LABEL_226;
        v115 = v112 | (v114 << 24);
        v4 = v135;
        v116 = (_DWORD)v135 << 8;
        v117 = v115 | ((unsigned __int8)v113 << 8);
        v118 = *(unsigned __int8 *)(v13 + 22);
        s[v9] = v129 + ((_DWORD)v135 << 8);
        v142[v9] = v117 | v118;
        if ( v9 != 119 )
        {
          v119 = v9 + 1;
          s[v119] = v127 + v116;
          v142[v119] = *(unsigned __int8 *)(v13 + 23);
          if ( v9 <= 0x75 )
          {
            v120 = v9 + 2;
            if ( *(unsigned __int8 *)(v13 + 29) == 255 )
              goto LABEL_199;
            s[v120] = v126 + v116;
            v142[v120] = *(unsigned __int8 *)(v13 + 29);
            if ( v9 != 117 )
            {
              v120 = v9 + 3;
LABEL_199:
              if ( *(unsigned __int8 *)(v13 + 28) == 255 )
              {
LABEL_203:
                if ( *(unsigned __int8 *)(v13 + 26) != 255 )
                {
                  if ( v120 > 0x77 )
                    goto LABEL_225;
                  s[v120] = v124 + v116;
                  v142[v120] = *(unsigned __int8 *)(v13 + 26);
                  if ( v120 == 119 )
                    goto LABEL_217;
                  ++v120;
                }
                if ( *(unsigned __int8 *)(v13 + 24) == 255 || *(unsigned __int8 *)(v13 + 25) == 255 )
                {
                  if ( v120 > 0x77 )
                  {
LABEL_225:
                    __break(1u);
LABEL_226:
                    __break(0x5512u);
                  }
                  s[v120] = v125 + v116;
                  v121 = 240;
                }
                else
                {
                  if ( v120 > 0x77 )
                    goto LABEL_225;
                  s[v120] = v125 + v116;
                  v121 = (16 * (*(_BYTE *)(v13 + 25) & 0xF)) | *(unsigned __int8 *)(v13 + 24);
                }
                v142[v120] = v121;
                if ( v120 <= 0x76 )
                {
                  v9 = v120 + 1;
                  if ( *(unsigned __int8 *)(v13 + 27) != 255 )
                  {
                    s[v9] = v123 + v116;
                    v142[v9] = *(unsigned __int8 *)(v13 + 27);
                    v9 = v120 + 2;
                  }
                  goto LABEL_218;
                }
                goto LABEL_217;
              }
              if ( v120 > 0x77 )
                goto LABEL_225;
              s[v120] = v116 + 4140;
              v142[v120] = *(unsigned __int8 *)(v13 + 28);
              if ( v120 != 119 )
              {
                ++v120;
                goto LABEL_203;
              }
            }
          }
        }
LABEL_217:
        v9 = 120;
        goto LABEL_218;
      }
      v4 = v135;
LABEL_218:
      *(_BYTE *)(v13 + 17) = *(_BYTE *)(v13 + 18);
      if ( v4 == 13 )
      {
LABEL_219:
        result = swr_master_bulk_write(v3, (__int64)s, (__int64)v142, v9);
        goto LABEL_224;
      }
    }
  }
  result = __ratelimit(&swrm_copy_data_port_config__rs, "swrm_copy_data_port_config");
  if ( (_DWORD)result )
    result = printk(&unk_10D41, "swrm_copy_data_port_config");
LABEL_224:
  _ReadStatusReg(SP_EL0);
  return result;
}
