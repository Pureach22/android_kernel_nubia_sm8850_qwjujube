__int64 __fastcall get_packed_size_core(__int64 a1, __int64 a2, int *a3, unsigned int *a4)
{
  __int64 v4; // x17
  __int64 v5; // x28
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x30
  __int64 v11; // x12
  __int64 v12; // x0
  __int64 v13; // x13
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x15
  __int64 v18; // x11
  __int64 v19; // x24
  __int64 v20; // x20
  __int64 v21; // x2
  __int64 v22; // x14
  __int64 v23; // x23
  __int64 v24; // x19
  __int64 v25; // x25
  __int64 v26; // x22
  __int64 v27; // x26
  __int64 v28; // x27
  __int64 v29; // x21
  __int64 v30; // x11
  int v31; // w8
  __int64 v32; // x24
  _BYTE *v33; // x9
  int v34; // w10
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x9
  __int64 v38; // x11
  __int64 v39; // x10
  __int64 v40; // x9
  __int64 v41; // x9
  int v42; // w11
  __int64 v43; // x10
  __int64 v44; // x9
  __int64 v45; // x10
  __int64 v46; // x9
  __int64 v47; // x10
  __int64 v48; // x10
  __int64 v49; // x9
  int v50; // w11
  __int64 v51; // x9
  int v52; // w8
  __int64 v53; // x8
  __int64 v54; // x9
  __int64 v55; // x28
  void *v56; // x2
  __int64 v57; // x9
  char v58; // w10
  __int64 v59; // x9
  unsigned __int8 v60; // w9
  __int64 v61; // x9
  int v62; // w11
  __int64 v63; // x9
  __int64 v64; // x10
  int v65; // w8
  int v66; // w10
  __int64 v67; // x8
  int v68; // w10
  int v69; // w10
  int v70; // w8
  __int64 v71; // x11
  int v72; // w10
  int v73; // w8
  __int64 v74; // x9
  __int64 v75; // x9
  __int64 v76; // x10
  __int64 v77; // x9
  int v78; // w8
  int v79; // w9
  __int64 v80; // x9
  int v81; // w10
  int v82; // w9
  __int64 v83; // x10
  __int64 v84; // x9
  __int64 v85; // x10
  __int64 v86; // x11
  __int64 v87; // x9
  __int64 v88; // x9
  int *v89; // x2
  int v90; // w8
  __int64 v91; // x10
  int v92; // w11
  __int64 v93; // x9
  int v94; // w11
  __int64 v95; // x9
  __int64 v96; // x9
  __int64 v97; // x9
  int v98; // w10
  int v99; // w9
  __int64 v100; // x9
  int v101; // w11
  __int64 v102; // x9
  int v103; // w11
  int packed_ie_measurement_report; // w0
  __int64 v105; // x9
  int v106; // w10
  __int64 v107; // x9
  __int64 v108; // x9
  int v109; // w11
  __int64 v110; // x9
  __int64 v111; // x10
  int v112; // w8
  int v113; // w8
  int v114; // w8
  int v115; // w8
  int v116; // w8
  __int64 v117; // x9
  int v118; // w10
  __int64 v119; // x8
  __int64 v120; // x9
  __int64 v121; // x9
  unsigned __int16 *v122; // x9
  int v123; // w8
  int v124; // w8
  int v125; // w8
  __int64 v126; // x9
  int v127; // w8
  int v128; // w9
  __int64 v129; // x9
  __int64 v130; // x9
  int v131; // w8
  int v132; // w8
  int v133; // w9
  __int64 v134; // x9
  int v135; // w11
  unsigned int v136; // w8
  int v137; // w8
  __int64 v138; // x9
  int v139; // w8
  __int64 v140; // x10
  int v141; // w8
  int v142; // w8
  int v143; // w8
  __int64 v144; // x10
  int v145; // w9
  __int64 v146; // x11
  int v147; // w10
  int v148; // w10
  int v149; // w9
  __int64 v151; // [xsp+0h] [xbp-1A0h]
  __int64 v152; // [xsp+0h] [xbp-1A0h]
  __int64 v154; // [xsp+10h] [xbp-190h]
  unsigned int *v155; // [xsp+18h] [xbp-188h]
  __int64 v156; // [xsp+20h] [xbp-180h]
  __int64 v157; // [xsp+20h] [xbp-180h]
  __int64 v158; // [xsp+28h] [xbp-178h]
  __int64 v159; // [xsp+28h] [xbp-178h]
  __int64 v160; // [xsp+30h] [xbp-170h]
  __int64 v161; // [xsp+30h] [xbp-170h]
  __int64 v162; // [xsp+38h] [xbp-168h]
  __int64 v163; // [xsp+38h] [xbp-168h]
  __int64 v164; // [xsp+40h] [xbp-160h]
  __int64 v165; // [xsp+40h] [xbp-160h]
  __int64 v166; // [xsp+48h] [xbp-158h]
  __int64 v167; // [xsp+48h] [xbp-158h]
  __int64 v168; // [xsp+50h] [xbp-150h]
  __int64 v169; // [xsp+50h] [xbp-150h]
  __int64 v170; // [xsp+58h] [xbp-148h]
  __int64 v171; // [xsp+60h] [xbp-140h]
  __int64 v172; // [xsp+60h] [xbp-140h]
  __int64 v173; // [xsp+68h] [xbp-138h]
  unsigned int v174; // [xsp+70h] [xbp-130h]
  unsigned int v175; // [xsp+74h] [xbp-12Ch]
  __int64 v176; // [xsp+78h] [xbp-128h]
  __int64 v177; // [xsp+80h] [xbp-120h]
  __int64 v178; // [xsp+88h] [xbp-118h]
  __int64 v179; // [xsp+90h] [xbp-110h]
  __int64 v180; // [xsp+98h] [xbp-108h]
  __int64 v181; // [xsp+A0h] [xbp-100h]
  __int64 v182; // [xsp+A8h] [xbp-F8h]
  __int64 v183; // [xsp+B0h] [xbp-F0h]
  __int64 v184; // [xsp+B8h] [xbp-E8h]
  __int64 v185; // [xsp+C0h] [xbp-E0h]
  __int64 v186; // [xsp+C8h] [xbp-D8h]
  __int64 v187; // [xsp+D0h] [xbp-D0h]
  __int64 v188; // [xsp+D8h] [xbp-C8h]
  __int64 v189; // [xsp+E0h] [xbp-C0h]
  __int64 v190; // [xsp+E8h] [xbp-B8h]
  __int64 v191; // [xsp+F0h] [xbp-B0h]
  __int64 v192; // [xsp+F8h] [xbp-A8h]
  __int64 v193; // [xsp+100h] [xbp-A0h]
  __int64 v194; // [xsp+108h] [xbp-98h]
  __int64 v195; // [xsp+110h] [xbp-90h]
  __int64 v196; // [xsp+118h] [xbp-88h]
  __int64 v197; // [xsp+120h] [xbp-80h]
  __int64 v198; // [xsp+128h] [xbp-78h]
  __int64 v199; // [xsp+130h] [xbp-70h]
  __int64 v200; // [xsp+138h] [xbp-68h]
  __int64 v201; // [xsp+140h] [xbp-60h]
  __int64 v202; // [xsp+148h] [xbp-58h]
  __int64 v203; // [xsp+150h] [xbp-50h]
  __int64 v204; // [xsp+158h] [xbp-48h]
  __int64 v205; // [xsp+160h] [xbp-40h]
  __int64 v206; // [xsp+168h] [xbp-38h]
  __int64 v207; // [xsp+170h] [xbp-30h]
  __int64 v208; // [xsp+178h] [xbp-28h]
  __int64 v209; // [xsp+180h] [xbp-20h]
  unsigned int v211; // [xsp+194h] [xbp-Ch]

  v154 = a2;
  v174 = 0;
  while ( *((unsigned __int8 *)a4 + 38) != 255 || *((_BYTE *)a4 + 39) )
  {
    if ( *(_BYTE *)(a2 + *a4 + a4[1]) )
    {
      if ( !*((_WORD *)a4 + 12) )
      {
        v175 = 1;
LABEL_10:
        v4 = 0;
        v5 = 0;
        v190 = 1;
        v191 = 0;
        v6 = 0;
        v189 = 1;
        v7 = 0;
        v188 = 1;
        v8 = 0;
        v187 = 2;
        v9 = 0;
        v186 = 1;
        v10 = 0;
        v185 = 24;
        v11 = 0;
        v201 = 1;
        v12 = 0;
        v200 = 1;
        v13 = 0;
        v184 = 3;
        v14 = 0;
        v15 = 0;
        v16 = 0;
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v20 = 0;
        v21 = 1;
        v22 = 1;
        v23 = 7;
        v24 = 1;
        v25 = 1;
        v183 = 13;
        v26 = 9;
        v27 = 2;
        v28 = 4;
        v29 = 1;
        v198 = 0;
        v199 = 0;
        v203 = 0;
        v204 = 0;
        v196 = 0;
        v197 = 0;
        v207 = 0;
        v208 = 0;
        v194 = 0;
        v195 = 0;
        v205 = 0;
        v206 = 0;
        v192 = 0;
        v193 = 0;
        v209 = 0;
        v202 = 0;
        v211 = 0;
        v182 = 3;
        v155 = a4;
        while ( 2 )
        {
          v179 = v15;
          v180 = v22;
          v178 = v16;
          v31 = *((unsigned __int8 *)a4 + 37) + *a3 + 2;
          *a3 = v31;
          if ( *((_BYTE *)a4 + 39) )
            *a3 = ++v31;
          v181 = v19;
          v32 = v17;
          v176 = v18;
          v177 = v14;
          v30 = v20;
          switch ( *((_WORD *)a4 + 15) )
          {
            case 1:
              v108 = a2 + *a4;
              v109 = *(unsigned __int8 *)(v108 + v6 + 13);
              v33 = (_BYTE *)(v108 + 46 * v211);
              v34 = v109 + 11;
              goto LABEL_128;
            case 2:
              v33 = (_BYTE *)(a2 + *a4 + 34 * v211);
              v34 = 33;
              goto LABEL_129;
            case 3:
              v74 = *a4;
              v38 = 50 * v211;
              v48 = v189;
              goto LABEL_125;
            case 4:
            case 0x28:
            case 0x2B:
              v46 = a2 + *a4;
              v47 = 7 * v211;
              goto LABEL_35;
            case 5:
            case 0x9F:
              v41 = a2 + *a4;
              v43 = 53 * v211;
              v42 = *(unsigned __int8 *)(v41 + v27);
              goto LABEL_111;
            case 6:
            case 0x13:
            case 0x1F:
            case 0x23:
            case 0x25:
            case 0x27:
            case 0x34:
            case 0x36:
            case 0x3C:
            case 0x4D:
            case 0x59:
            case 0x5B:
            case 0x5E:
            case 0x5F:
            case 0x62:
            case 0x65:
            case 0x86:
            case 0x90:
            case 0x9E:
            case 0xA8:
            case 0xAA:
              v33 = (_BYTE *)(a2 + *a4 + 2 * v211);
              v34 = 1;
              goto LABEL_129;
            case 7:
              v38 = 226 * v211;
              v44 = a2 + *a4;
              v34 = *(unsigned __int8 *)(v44 + v21);
              goto LABEL_127;
            case 8:
            case 0x1B:
            case 0x29:
            case 0x38:
            case 0x3B:
            case 0x40:
            case 0x5A:
            case 0x5D:
            case 0x6C:
            case 0x75:
            case 0x77:
            case 0x78:
            case 0x79:
            case 0x87:
              v35 = *a4;
              v36 = 3 * v211;
              goto LABEL_26;
            case 9:
            case 0xA:
            case 0xB:
            case 0xD:
            case 0x96:
              v41 = a2 + *a4;
              v42 = *(unsigned __int8 *)(v41 + v207 + 2);
              v43 = 258 * v211;
              goto LABEL_111;
            case 0xC:
            case 0x15:
            case 0x39:
              v33 = (_BYTE *)(a2 + *a4 + 6 * v211);
              v34 = 4;
              goto LABEL_129;
            case 0xE:
            case 0x18:
            case 0x70:
              v33 = (_BYTE *)(a2 + *a4 + 6 * v211);
              v34 = 5;
              goto LABEL_129;
            case 0xF:
            case 0x94:
            case 0x98:
            case 0x99:
            case 0xA1:
            case 0xA3:
            case 0xA5:
            case 0xA9:
              v37 = *a4;
              v38 = 257 * v211;
              v39 = v209;
              goto LABEL_23;
            case 0x10:
            case 0x69:
              v44 = a2 + *a4;
              v38 = 34 * v211;
              v48 = v201;
              goto LABEL_126;
            case 0x11:
            case 0x4C:
              v33 = (_BYTE *)(a2 + *a4 + 16 * v211);
              v34 = 14;
              goto LABEL_129;
            case 0x12:
              v80 = *a4;
              if ( !*(_BYTE *)(a2 + v80 + v6) )
                goto LABEL_11;
              *a3 = v31 + 3;
              v81 = *(unsigned __int8 *)(a2 + v80 + v6 + 2);
              if ( !*(_BYTE *)(a2 + v80 + v6 + 2) )
              {
                v149 = 17;
                goto LABEL_219;
              }
              v30 = v20;
              if ( v81 == 2 )
              {
                v52 = v31 + 5;
              }
              else
              {
                if ( v81 != 1 )
                  goto LABEL_12;
                *a3 = v31 + 4;
                v82 = *(unsigned __int8 *)(a2 + v80 + v6 + 4);
                if ( v82 == 4 )
                {
                  v52 = v31 + 19;
                }
                else
                {
                  if ( v82 != 6 )
                    goto LABEL_12;
                  v52 = v31 + 43;
                }
              }
              goto LABEL_132;
            case 0x14:
              v75 = *a4;
              v76 = 8 * v211;
              goto LABEL_100;
            case 0x16:
              v33 = (_BYTE *)(a2 + *a4 + 60 * v211);
              v34 = 55;
              goto LABEL_129;
            case 0x17:
              v33 = (_BYTE *)(a2 + *a4 + 16 * v211);
              v34 = 12;
              goto LABEL_129;
            case 0x19:
              v33 = (_BYTE *)(a2 + *a4 + 16 * v211);
              v34 = 15;
              goto LABEL_129;
            case 0x1A:
              v97 = *a4;
              if ( !*(_BYTE *)(a2 + v97 + v204) )
                goto LABEL_11;
              *a3 = v31 + 4;
              v98 = *(unsigned __int8 *)(a2 + v97 + v204 + 3);
              if ( *(_BYTE *)(a2 + v97 + v204 + 3) )
              {
                v30 = v20;
                if ( v98 == 2 )
                {
                  v52 = v31 + 6;
                }
                else
                {
                  if ( v98 != 1 )
                    goto LABEL_12;
                  *a3 = v31 + 5;
                  v99 = *(unsigned __int8 *)(a2 + v97 + v204 + 6);
                  if ( v99 == 4 )
                  {
                    v52 = v31 + 20;
                  }
                  else
                  {
                    if ( v99 != 6 )
                      goto LABEL_12;
                    v52 = v31 + 44;
                  }
                }
              }
              else
              {
                v149 = 18;
LABEL_219:
                v30 = v20;
                v52 = v149 + v31;
              }
              goto LABEL_132;
            case 0x1C:
            case 0x3F:
            case 0x5C:
            case 0x6F:
              v33 = (_BYTE *)(a2 + *a4 + 8 * v211);
              v34 = 5;
              goto LABEL_129;
            case 0x1D:
              v33 = (_BYTE *)(a2 + *a4 + 60 * v211);
              v34 = 56;
              goto LABEL_129;
            case 0x1E:
            case 0x2D:
            case 0x31:
            case 0x58:
            case 0xA0:
            case 0xA4:
              v33 = (_BYTE *)(a2 + *a4 + 4 * v211);
              v34 = 3;
              goto LABEL_129;
            case 0x20:
            case 0x24:
            case 0x2E:
            case 0x9A:
              v35 = *a4;
              v36 = 4 * v211;
LABEL_26:
              v33 = (_BYTE *)(a2 + v35 + v36);
              v34 = 2;
              goto LABEL_129;
            case 0x21:
            case 0x22:
              v49 = a2 + *a4;
              v50 = *(_WORD *)(v49 + v22) & 2;
              v33 = (_BYTE *)(v49 + 7 * v211);
              v34 = v50 | 4;
              goto LABEL_128;
            case 0x26:
              v88 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v88 + v11) )
                goto LABEL_195;
              v151 = v21;
              v89 = a3;
              v90 = v31 + 13;
              v91 = a2 + v11;
              goto LABEL_188;
            case 0x2A:
              v107 = *a4;
              if ( !*(_BYTE *)(a2 + v190 + v107 - 1) )
                goto LABEL_12;
              *a3 = v31 + 2;
              if ( *(_BYTE *)(a2 + v190 + v107) != 4 )
                goto LABEL_12;
              v52 = v31 + 18;
              goto LABEL_132;
            case 0x2C:
              v130 = *a4;
              if ( !*(_BYTE *)(a2 + v4 + v130) )
                goto LABEL_11;
              v131 = v31 + 1;
              *a3 = v131;
              v132 = v131 + *(unsigned __int8 *)(a2 + v4 + v130 + 2);
              *a3 = v132;
              v133 = ((*(unsigned __int8 *)(a2 + v130 + v4 + 1) >> 3) & 7) - 1;
              if ( (unsigned int)v133 > 4 )
                goto LABEL_11;
              v116 = dword_B08190[v133] + v132;
              goto LABEL_202;
            case 0x2F:
            case 0x61:
              v47 = 8 * v211;
              v46 = a2 + *a4;
LABEL_35:
              v33 = (_BYTE *)(v46 + v47);
              v34 = 6;
              goto LABEL_129;
            case 0x30:
            case 0x47:
            case 0x66:
            case 0x67:
            case 0x74:
              v40 = a2 + *a4;
              v34 = *(unsigned __int8 *)(v40 + v181 + 1);
              v30 = v20;
              v33 = (_BYTE *)(v40 + 255 * v211);
              goto LABEL_129;
            case 0x32:
              v119 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v119 + v5) )
                goto LABEL_195;
              v120 = a2 + v5;
              goto LABEL_176;
            case 0x33:
              v126 = *a4;
              if ( !*(_BYTE *)(a2 + v23 + v126 - 7) )
                goto LABEL_12;
              v127 = v31 + 6;
              *a3 = v127;
              v128 = *(unsigned __int8 *)(a2 + v23 + v126);
              if ( !v128 )
                goto LABEL_12;
              v52 = 3 * v128 + v127;
              goto LABEL_132;
            case 0x35:
              v83 = *a4;
              v84 = 20 * v211;
              goto LABEL_152;
            case 0x37:
              v74 = *a4;
              v38 = 22 * v211;
              v48 = v188;
              goto LABEL_125;
            case 0x3A:
              v43 = 11 * v211;
              v41 = a2 + *a4;
              v42 = *(unsigned __int8 *)(v41 + v187);
LABEL_111:
              v33 = (_BYTE *)(v41 + v43);
              v34 = v42 + 1;
              goto LABEL_128;
            case 0x3D:
              v74 = *a4;
              v38 = 17 * v211;
              v48 = v186;
LABEL_125:
              v44 = a2 + v74;
              goto LABEL_126;
            case 0x3E:
            case 0x6A:
              v44 = a2 + *a4;
              v38 = 14 * v211;
              v48 = v200;
LABEL_126:
              v34 = *(unsigned __int8 *)(v44 + v48);
              goto LABEL_127;
            case 0x41:
              v117 = a2 + *a4;
              v118 = *(unsigned __int8 *)(v117 + v209 + 5);
              v33 = (_BYTE *)(v117 + 257 * v211);
              v30 = v20;
              v34 = v118 + 4;
              goto LABEL_129;
            case 0x42:
              v88 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v88 + v7) )
                goto LABEL_195;
              v151 = v21;
              v89 = a3;
              v90 = v31 + 82;
              v91 = a2 + v7;
              goto LABEL_188;
            case 0x43:
              v100 = a2 + *a4;
              v101 = *(unsigned __int8 *)(v100 + v20 + 27);
              v33 = (_BYTE *)(v100 + 60 * v211);
              v34 = v101 + 26;
              goto LABEL_128;
            case 0x44:
              v93 = a2 + *a4;
              v94 = *(unsigned __int8 *)(v93 + v185);
              v33 = (_BYTE *)(v93 + 58 * v211);
              v34 = v94 + 22;
              goto LABEL_128;
            case 0x45:
              v83 = *a4;
              v84 = 19 * v211;
LABEL_152:
              v33 = (_BYTE *)(a2 + v83 + v84);
              v34 = 18;
              goto LABEL_129;
            case 0x46:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v8) )
                goto LABEL_195;
              v54 = a2 + v8;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_MBO_IE;
              goto LABEL_192;
            case 0x48:
              v173 = v12;
              v170 = v5;
              v55 = v21;
              v171 = v4;
              v166 = v7;
              v168 = v6;
              v162 = v9;
              v164 = v8;
              v158 = v11;
              v160 = v10;
              v156 = v13;
              packed_ie_measurement_report = dot11f_get_packed_ie_measurement_report(a1, a2 + v9 + *a4, a3);
              goto LABEL_193;
            case 0x49:
              v173 = v12;
              v170 = v5;
              v55 = v21;
              v171 = v4;
              v166 = v7;
              v168 = v6;
              v162 = v9;
              v164 = v8;
              v158 = v11;
              v160 = v10;
              v156 = v13;
              packed_ie_measurement_report = dot11f_get_packed_ie_measurement_request(a1, a2 + v10 + *a4, a3);
              goto LABEL_193;
            case 0x4A:
            case 0x88:
              v33 = (_BYTE *)(a2 + *a4 + 6 * v211);
              v34 = 3;
              goto LABEL_129;
            case 0x4B:
              v88 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v88 + v11) )
                goto LABEL_195;
              v151 = v21;
              v89 = a3;
              v90 = v31 + 13;
              v91 = a2 + v11;
              goto LABEL_188;
            case 0x4E:
            case 0x55:
            case 0x76:
            case 0x7C:
            case 0x82:
              v37 = *a4;
              v38 = 251 * v211;
              v39 = v208;
LABEL_23:
              v44 = a2 + v37;
              v45 = v44 + v39;
              goto LABEL_24;
            case 0x4F:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v12) )
                goto LABEL_195;
              v54 = a2 + v12;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PAssocReq;
              goto LABEL_192;
            case 0x50:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v13) )
                goto LABEL_195;
              v54 = a2 + v13;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PAssocRes;
              goto LABEL_192;
            case 0x51:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v14) )
                goto LABEL_195;
              v54 = a2 + v14;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PBeacon;
              goto LABEL_192;
            case 0x52:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v179) )
                goto LABEL_195;
              v54 = a2 + v179;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PBeaconProbeRes;
              goto LABEL_192;
            case 0x53:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v205) )
                goto LABEL_195;
              v54 = a2 + v205;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PDeAuth;
              goto LABEL_192;
            case 0x54:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v205) )
                goto LABEL_195;
              v54 = a2 + v205;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PDisAssoc;
              goto LABEL_192;
            case 0x56:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v16) )
                goto LABEL_195;
              v54 = a2 + v16;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PProbeReq;
              goto LABEL_192;
            case 0x57:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v199) )
                goto LABEL_195;
              v54 = a2 + v199;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_P2PProbeRes;
              goto LABEL_192;
            case 0x60:
              v44 = a2 + *a4;
              v38 = 60 * v211;
              v45 = v44 + v20;
LABEL_24:
              v34 = *(unsigned __int8 *)(v45 + 1);
              goto LABEL_127;
            case 0x63:
              v119 = *a4;
              v173 = v12;
              a3 -= 2;
              if ( !*(_BYTE *)(a2 + v119 + v198) )
                goto LABEL_195;
              v120 = a2 + v198;
LABEL_176:
              v170 = v5;
              v55 = v21;
              v171 = v4;
              v166 = v7;
              v168 = v6;
              v162 = v9;
              v164 = v8;
              v158 = v11;
              v160 = v10;
              v156 = v13;
              packed_ie_measurement_report = get_packed_size_core(a1, v120 + v119);
              goto LABEL_193;
            case 0x64:
              v63 = *a4;
              if ( !*(_BYTE *)(a2 + v17 + v63) )
                goto LABEL_12;
              *a3 = v31 + 2;
              v64 = a2 + v63 + v17;
              if ( !*(_BYTE *)(v64 + 4) )
                goto LABEL_11;
              *a3 = v31 + 6;
              if ( !*(_WORD *)(v64 + 10) )
                goto LABEL_11;
              v65 = v31 + 8;
              *a3 = v65;
              v66 = v65 + 4 * *(unsigned __int16 *)(v64 + 10);
              v67 = a2 + v63 + v17;
              *a3 = v66;
              if ( !*(_WORD *)(v67 + 36) )
                goto LABEL_11;
              v68 = v66 + 2;
              *a3 = v68;
              v69 = v68 + 4 * *(unsigned __int16 *)(v67 + 36);
              *a3 = v69;
              if ( !*(_BYTE *)(v67 + 70) )
                goto LABEL_11;
              v70 = v69 + 2;
              *a3 = v69 + 2;
              v71 = a2 + v63 + v17;
              if ( *(_WORD *)(v71 + 74) || *(_BYTE *)(a2 + v17 + v63 + 140) )
              {
                v70 = v69 + 4;
                *a3 = v69 + 4;
                v72 = *(unsigned __int16 *)(v71 + 74);
              }
              else
              {
                v72 = 0;
              }
              v73 = v70 + 16 * v72;
              v30 = v20;
              *a3 = v73;
              if ( *(_BYTE *)(a2 + v17 + v63 + 140) )
                *a3 = v73 + 4;
              goto LABEL_12;
            case 0x68:
              v44 = a2 + *a4;
              v38 = 98 * v211;
              v34 = 2 * *(unsigned __int8 *)(v44 + v25);
              goto LABEL_127;
            case 0x6B:
              v102 = a2 + *a4;
              v103 = *(unsigned __int8 *)(v102 + v28);
              v33 = (_BYTE *)(v102 + (v211 << 8));
              v34 = v103 + 3;
              goto LABEL_128;
            case 0x6D:
            case 0x71:
            case 0x72:
              goto LABEL_12;
            case 0x6E:
            case 0x95:
              v33 = (_BYTE *)(a2 + *a4 + 17 * v211);
              v34 = 16;
              goto LABEL_129;
            case 0x73:
              v121 = a2 + *a4;
              if ( !*(_BYTE *)(v121 + v176) )
                goto LABEL_11;
              v122 = (unsigned __int16 *)(v121 + v176);
              *a3 = v31 + 4;
              v123 = v31 + 4 * v122[2] + 6;
              *a3 = v123;
              v124 = v123 + 4 * v122[11];
              *a3 = v124 + 6;
              if ( !v122[23] )
                goto LABEL_11;
              v125 = v124 + 8;
              v30 = v20;
              *a3 = v125;
              *a3 = v125 + 16 * v122[23];
              goto LABEL_12;
            case 0x7A:
              v33 = (_BYTE *)(a2 + *a4 + 20 * v211);
              v34 = 19;
              goto LABEL_129;
            case 0x7B:
              v110 = *a4;
              if ( !*(_BYTE *)(a2 + v110 + v204) )
                goto LABEL_11;
              *a3 = v31 + 2;
              if ( !*(_BYTE *)(a2 + v110 + v204 + 4) )
                goto LABEL_11;
              *a3 = v31 + 6;
              v111 = a2 + v110 + v204;
              if ( !*(_WORD *)(v111 + 10) )
                goto LABEL_11;
              v112 = v31 + 8;
              *a3 = v112;
              v113 = v112 + 4 * *(unsigned __int16 *)(v111 + 10);
              *a3 = v113;
              if ( !*(_WORD *)(v111 + 28) )
                goto LABEL_11;
              v114 = v113 + 2;
              *a3 = v114;
              v115 = v114 + 4 * *(unsigned __int16 *)(v111 + 28);
              *a3 = v115;
              if ( !*(_WORD *)(a2 + v110 + v204 + 46) )
                goto LABEL_11;
              v116 = v115 + 2;
              goto LABEL_202;
            case 0x7D:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v197) )
                goto LABEL_195;
              v54 = a2 + v197;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WSC;
              goto LABEL_192;
            case 0x7E:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v206) )
                goto LABEL_195;
              v54 = a2 + v206;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WscAssocReq;
              goto LABEL_192;
            case 0x7F:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v206) )
                goto LABEL_195;
              v54 = a2 + v206;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WscAssocRes;
              goto LABEL_192;
            case 0x80:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v196) )
                goto LABEL_195;
              v54 = a2 + v196;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WscBeacon;
              goto LABEL_192;
            case 0x81:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v203) )
                goto LABEL_195;
              v54 = a2 + v203;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WscBeaconProbeRes;
              goto LABEL_192;
            case 0x83:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v195) )
                goto LABEL_195;
              v54 = a2 + v195;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WscProbeReq;
              goto LABEL_192;
            case 0x84:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v203) )
                goto LABEL_195;
              v54 = a2 + v203;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WscProbeRes;
              goto LABEL_192;
            case 0x85:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v206) )
                goto LABEL_195;
              v54 = a2 + v206;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_WscReassocRes;
              goto LABEL_192;
            case 0x89:
              v105 = a2 + *a4;
              v106 = *(unsigned __int8 *)(v105 + v209 + 2);
              v33 = (_BYTE *)(v105 + 257 * v211);
              v30 = v20;
              v34 = v106 + 1;
              goto LABEL_129;
            case 0x8A:
              v129 = *a4;
              v173 = v12;
              if ( *(_BYTE *)(a2 + v129 + v193) )
              {
                v152 = v21;
                *a3 = v31 + 7;
                v172 = v4;
                v167 = v7;
                v169 = v6;
                v163 = v9;
                v165 = v8;
                v159 = v11;
                v161 = v10;
                v157 = v13;
                packed_ie_measurement_report = get_packed_size_core(a1, a2 + v193 + v129);
                v13 = v157;
                v11 = v159;
                v17 = v32;
                v10 = v161;
                v9 = v163;
                v21 = v152;
                v8 = v165;
                v7 = v167;
                v4 = v172;
                v6 = v169;
                a2 = v154;
                a4 = v155;
              }
              else
              {
                packed_ie_measurement_report = 0;
              }
              v136 = v174;
              v30 = v20;
              goto LABEL_197;
            case 0x8B:
              v85 = 259 * v211;
              v86 = v184;
              v87 = a2 + *a4;
              goto LABEL_90;
            case 0x8C:
              v77 = *a4;
              if ( !*(_BYTE *)(a2 + v194 + v77) )
                goto LABEL_11;
              v78 = v31 + 24;
              *a3 = v78;
              if ( (*(_QWORD *)(a2 + v77 + v194 + 1) & 0x8000000000000000LL) == 0 )
                goto LABEL_11;
              v79 = *(unsigned __int8 *)(a2 + v194 + v77 + 26);
              goto LABEL_201;
            case 0x8D:
              v57 = a2 + *a4;
              v58 = *(_DWORD *)(v57 + 4 * v205 + 1);
              v33 = (_BYTE *)(v57 + 12 * v211);
              v30 = v20;
              v34 = v58 & 2 | 8;
              goto LABEL_129;
            case 0x8E:
              v38 = 98 * v211;
              v44 = a2 + *a4;
              v34 = *(unsigned __int8 *)(v44 + v25);
LABEL_127:
              v33 = (_BYTE *)(v44 + v38);
              goto LABEL_128;
            case 0x8F:
              v75 = *a4;
              v76 = 5 * v211;
LABEL_100:
              v33 = (_BYTE *)(a2 + v75 + v76);
              v34 = 4;
              goto LABEL_129;
            case 0x91:
              v61 = a2 + *a4;
              v62 = *(unsigned __int8 *)(v61 + v183);
              v33 = (_BYTE *)(v61 + 269 * v211);
              v34 = v62 + 12;
              goto LABEL_128;
            case 0x92:
              v86 = v182;
              v87 = a2 + *a4;
              v85 = 260 * v211;
LABEL_90:
              v92 = *(unsigned __int8 *)(v87 + v86);
              v33 = (_BYTE *)(v87 + v85);
              v34 = v92 + 2;
              goto LABEL_128;
            case 0x93:
              v134 = a2 + *a4;
              v135 = *(unsigned __int8 *)(v134 + v26);
              v33 = (_BYTE *)(v134 + 265 * v211);
              v34 = v135 + 8;
LABEL_128:
              v30 = v20;
              goto LABEL_129;
            case 0x97:
              v33 = (_BYTE *)(a2 + *a4 + 9 * v211);
              v34 = 8;
              goto LABEL_129;
            case 0x9B:
              v138 = *a4;
              if ( *(_BYTE *)(a2 + v20 + v138) )
              {
                v139 = v31 + 21;
                v140 = a2 + v138 + v20;
                *a3 = v139;
                v141 = ((*(_QWORD *)(v140 + 1) >> 51) & 2) + v139;
                *a3 = v141;
                v142 = ((*(_QWORD *)(v140 + 1) >> 51) & 2) + v141;
                *a3 = v142;
                v143 = ((*(_QWORD *)(v140 + 1) >> 52) & 2) + v142;
                *a3 = v143;
                v78 = ((*(_QWORD *)(v140 + 1) >> 52) & 2) + v143;
                *a3 = v78;
                if ( (*(_BYTE *)(v140 + 14) & 4) != 0 )
                {
                  v79 = *(unsigned __int8 *)(a2 + v20 + v138 + 32);
LABEL_201:
                  v116 = v78 + v79;
LABEL_202:
                  v30 = v20;
                  *a3 = v116;
                }
                else
                {
LABEL_11:
                  v30 = v20;
                }
              }
              goto LABEL_12;
            case 0x9C:
              v144 = a2 + *a4;
              if ( !*(_BYTE *)(v144 + v192) )
                goto LABEL_12;
              v145 = v31 + 6;
              *a3 = v31 + 6;
              v146 = v144 + v192;
              v147 = *(_DWORD *)(v144 + v192 + 1);
              if ( (v147 & 0x40000) != 0 )
              {
                v145 = v31 + 9;
                *a3 = v31 + 9;
                v147 = *(_DWORD *)(v146 + 1);
                if ( (v147 & 0x80000) == 0 )
                {
LABEL_208:
                  v30 = v20;
                  if ( (v147 & 0x200000) == 0 )
                    goto LABEL_12;
                  goto LABEL_214;
                }
              }
              else if ( (v147 & 0x80000) == 0 )
              {
                goto LABEL_208;
              }
              *a3 = ++v145;
              v148 = *(_DWORD *)(v146 + 1);
              v30 = v20;
              if ( (v148 & 0x200000) == 0 )
                goto LABEL_12;
LABEL_214:
              v52 = v145 + 5;
LABEL_132:
              *a3 = v52;
LABEL_12:
              v20 = v30 + 60;
              v29 += 21;
              v202 += 28;
              v28 += 256;
              v185 += 58;
              v209 += 257;
              v27 += 53;
              v26 += 265;
              v186 += 17;
              v191 += 44;
              v192 += 18;
              v25 += 98;
              v19 = v181 + 255;
              v18 = v176 + 112;
              v187 += 11;
              v193 += 32;
              v17 += 146;
              v24 += 4;
              v13 += 10;
              v188 += 22;
              v207 += 258;
              v12 += 62;
              v11 += 548;
              v10 += 682;
              v189 += 50;
              v9 += 264;
              v8 += 282;
              v7 += 220;
              v23 += 248;
              v182 += 260;
              v183 += 269;
              v6 += 46;
              v5 += 232;
              v4 += 27;
              v21 += 226;
              v205 += 3;
              v190 += 19;
              v211 = (unsigned __int16)v211 + 1;
              v194 += 92;
              v22 = v180 + 7;
              v184 += 259;
              v206 += 20;
              v208 += 251;
              v195 += 246;
              v196 += 52;
              v14 = v177 + 51;
              v197 += 308;
              v203 += 272;
              v204 += 48;
              v200 += 14;
              v201 += 34;
              v198 += 636;
              v199 += 1128;
              v16 = v178 + 30;
              v15 = v179 + 1136;
              if ( v211 < v175 )
                continue;
              goto LABEL_2;
            case 0x9D:
              v51 = *a4;
              if ( !*(_BYTE *)(a2 + v24 + v51 - 1) )
                goto LABEL_12;
              *a3 = v31 + 1;
              if ( ((*(unsigned __int8 *)(a2 + v24 + v51) >> 1) & 3u) - 1 > 1 )
                goto LABEL_12;
              v52 = v31 + 3;
              goto LABEL_132;
            case 0xA2:
              v33 = (_BYTE *)(a2 + *a4 + 14 * v211);
              v34 = 13;
              goto LABEL_129;
            case 0xA6:
              v53 = *a4;
              v173 = v12;
              if ( !*(_BYTE *)(a2 + v53 + v191) )
                goto LABEL_195;
              v54 = a2 + v191;
              v170 = v5;
              v55 = v21;
              v56 = &TLVS_qcn_ie;
LABEL_192:
              v171 = v4;
              v166 = v7;
              v168 = v6;
              v162 = v9;
              v164 = v8;
              v158 = v11;
              v160 = v10;
              v156 = v13;
              packed_ie_measurement_report = get_packed_size_tlv_core(v54 + v53, a3, v56);
LABEL_193:
              v21 = v55;
              goto LABEL_194;
            case 0xA7:
              v59 = a2 + *a4;
              if ( !*(_BYTE *)(v59 + v202) )
                goto LABEL_12;
              *a3 = v31 + 4;
              v60 = *(_BYTE *)(v59 + v202 + 2) - 1;
              if ( v60 > 0xFu || ((0x9DF3u >> v60) & 1) == 0 )
                goto LABEL_12;
              v52 = dword_B08150[v60] + v31;
              goto LABEL_132;
            case 0xAB:
              v95 = *a4;
              if ( !*(_BYTE *)(a2 + v29 + v95 - 1) )
                goto LABEL_12;
              v96 = v29 + v95;
              *a3 = v31 + 1;
              if ( (*(_BYTE *)(a2 + v96) & 4) == 0 )
                goto LABEL_12;
              *a3 = v31 + 2;
              if ( (*(_BYTE *)(a2 + v96) & 8) == 0 )
                goto LABEL_12;
              v52 = v31 + 20;
              goto LABEL_132;
            case 0xAC:
              v33 = (_BYTE *)(a2 + v209 + *a4);
              v34 = (unsigned __int8)v33[1];
LABEL_129:
              if ( !v34 || !*v33 )
                goto LABEL_12;
              v52 = v31 + v34;
              goto LABEL_132;
            case 0xAD:
              v88 = *a4;
              v173 = v12;
              if ( *(_BYTE *)(a2 + v88 + v202) )
              {
                v151 = v21;
                v89 = a3;
                v90 = v31 + 1;
                v91 = a2 + v202;
LABEL_188:
                *v89 = v90;
                v170 = v5;
                v171 = v4;
                v166 = v7;
                v168 = v6;
                v162 = v9;
                v164 = v8;
                v158 = v11;
                v160 = v10;
                v156 = v13;
                packed_ie_measurement_report = get_packed_size_core(a1, v91 + v88);
                v21 = v151;
LABEL_194:
                v13 = v156;
                v11 = v158;
                v30 = v20;
                v10 = v160;
                v9 = v162;
                v17 = v32;
                v8 = v164;
                v7 = v166;
                v4 = v171;
                v6 = v168;
                v5 = v170;
                a2 = v154;
                a4 = v155;
              }
              else
              {
LABEL_195:
                packed_ie_measurement_report = 0;
              }
              v136 = v174;
LABEL_197:
              v137 = packed_ie_measurement_report | v136;
              v12 = v173;
              v174 = v137;
              goto LABEL_12;
            default:
              return 268435457;
          }
        }
      }
      v175 = *(unsigned __int16 *)(a2 + a4[2]);
      if ( *(_WORD *)(a2 + a4[2]) )
        goto LABEL_10;
    }
LABEL_2:
    a4 += 12;
  }
  return v174;
}
