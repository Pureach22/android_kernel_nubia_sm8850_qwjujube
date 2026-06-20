__int64 __fastcall cam_cpas_util_apply_client_axi_vote(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, int a4)
{
  unsigned __int64 v4; // x20
  __int64 v5; // x22
  __int64 v6; // x26
  __int64 v7; // x27
  unsigned __int64 v10; // x21
  _BYTE *v11; // x9
  __int64 v12; // x1
  unsigned __int64 v13; // x17
  unsigned __int64 v14; // x9
  _DWORD *v15; // x10
  unsigned __int64 v16; // x11
  _DWORD *v17; // x12
  _DWORD *v18; // x13
  _DWORD *v19; // x2
  _DWORD *v20; // x3
  _DWORD *v21; // x4
  _DWORD *v22; // x5
  _DWORD *v23; // x19
  __int64 v24; // x16
  __int64 v25; // x6
  __int64 v26; // x7
  unsigned int v28; // w15
  _DWORD *v29; // x14
  unsigned int v30; // w15
  int v31; // w17
  bool v32; // zf
  __int64 v33; // x0
  __int64 v34; // x17
  __int64 v35; // x17
  __int64 v36; // x16
  __int64 v37; // x24
  __int64 v38; // x0
  __int64 v39; // x14
  _QWORD *v40; // x17
  unsigned int v41; // w6
  __int64 v42; // x17
  unsigned int v43; // w15
  int v44; // w17
  bool v45; // zf
  __int64 v46; // x0
  __int64 v47; // x17
  __int64 v48; // x15
  __int64 v49; // x0
  __int64 v50; // x14
  __int64 v51; // x15
  __int64 v52; // x0
  __int64 v53; // x14
  __int64 v54; // x15
  unsigned int v55; // w8
  __int64 v56; // x9
  __int64 v57; // x9
  __int64 v58; // x9
  __int64 v59; // x9
  __int64 v60; // x9
  __int64 v61; // x9
  __int64 v62; // x8
  unsigned int v63; // w11
  __int64 v64; // x9
  __int64 v65; // x10
  __int64 v66; // x11
  unsigned int v67; // w10
  __int64 v68; // x8
  unsigned int v69; // w11
  __int64 v70; // x9
  __int64 v71; // x10
  __int64 v72; // x11
  unsigned int v73; // w10
  __int64 v74; // x8
  unsigned int v75; // w11
  __int64 v76; // x9
  __int64 v77; // x10
  __int64 v78; // x11
  unsigned int v79; // w10
  unsigned __int64 v80; // x8
  __int64 v81; // x19
  unsigned int v82; // w0
  unsigned __int64 v83; // x28
  __int64 v84; // x10
  _QWORD *v85; // x9
  __int64 v86; // x11
  __int64 v87; // x10
  __int64 v88; // x11
  __int64 v89; // x12
  __int64 v90; // x25
  __int64 v91; // x8
  __int64 v92; // x10
  __int64 v93; // x8
  __int64 v94; // x10
  __int64 v95; // x11
  __int64 v96; // x1
  _BOOL4 v97; // w8
  unsigned int v98; // w0
  __int64 v99; // x21
  __int64 v100; // x28
  unsigned int v101; // w0
  const char **v102; // x8
  const char *v103; // x6
  __int64 v104; // x8
  unsigned __int64 v105; // x9
  __int64 v106; // x21
  unsigned int v107; // w0
  const char **v108; // x8
  const char *v109; // x6
  const char **v110; // x9
  const char *v111; // x6
  __int64 v112; // x28
  unsigned int started; // w0
  const char **v114; // x8
  const char *v115; // x6
  const char **v116; // x9
  const char *v117; // x6
  const char **v118; // x9
  const char *v119; // x6
  __int64 v120; // x28
  int v121; // w19
  unsigned int v122; // w23
  __int64 v123; // x6
  const char *v124; // x5
  __int64 v125; // x4
  unsigned int *v126; // x11
  __int64 v127; // x8
  __int64 v128; // x9
  unsigned int v129; // w25
  unsigned int v130; // w24
  int v131; // w9
  unsigned int v132; // w8
  __int64 v133; // x8
  __int64 v134; // x9
  _QWORD *v135; // x8
  int v136; // w3
  unsigned __int64 v137; // x22
  unsigned __int64 v138; // x23
  __int64 v139; // x19
  unsigned __int64 v140; // x25
  int v141; // w12
  _QWORD *v142; // x14
  __int64 v143; // x10
  __int64 v144; // x9
  __int64 v145; // x9
  _QWORD *v146; // x9
  __int64 v147; // t1
  __int64 v148; // x10
  char v149; // w8
  __int64 v150; // x11
  __int64 v151; // x11
  __int64 v152; // x8
  __int64 v153; // x10
  __int64 v154; // x9
  _QWORD *v155; // x10
  __int64 v156; // t1
  __int64 v157; // x8
  __int64 v158; // x9
  __int64 v159; // x10
  __int64 v160; // x8
  unsigned int i; // w16
  __int64 v162; // x8
  __int64 v163; // x9
  _QWORD *v164; // x8
  int v165; // w8
  unsigned __int64 v166; // x8
  unsigned __int64 v167; // x9
  __int64 v168; // x10
  unsigned __int64 v169; // x11
  _QWORD *v170; // x10
  _QWORD *v171; // x9
  unsigned __int64 v172; // x10
  unsigned __int64 v173; // x11
  __int64 v174; // x8
  _QWORD *v175; // x9
  _QWORD *v176; // x8
  __int64 v177; // x6
  _QWORD *v178; // x11
  __int64 v179; // x8
  _QWORD *v180; // x10
  __int64 v181; // x9
  __int64 v182; // x12
  __int64 v183; // x13
  __int64 v184; // x12
  __int64 v185; // x13
  __int64 v186; // x11
  __int64 v187; // x14
  _QWORD *v188; // x10
  __int64 v189; // x12
  char v190; // w9
  unsigned int v191; // w9
  __int64 v192; // x10
  __int64 v193; // x8
  __int64 v194; // x9
  __int64 v195; // x8
  const char *v196; // x5
  __int64 v197; // x4
  int v198; // w8
  __int64 v199; // x1
  unsigned int v200; // w0
  const char *v201; // x5
  __int64 v202; // x4
  __int64 v203; // x20
  int v204; // w8
  __int64 v205; // x10
  unsigned __int64 v206; // x9
  unsigned __int64 v207; // x8
  __int64 v208; // x14
  __int64 v209; // x15
  __int64 v210; // x14
  __int64 v211; // x15
  unsigned __int64 v212; // x16
  unsigned __int64 v213; // x14
  __int64 v214; // x21
  unsigned int v215; // w6
  __int64 v216; // x19
  __int64 v217; // x20
  __int64 v218; // x27
  __int64 v219; // x22
  __int64 v220; // x24
  __int64 v221; // x25
  unsigned __int64 v222; // x26
  unsigned int v223; // w0
  __int64 v224; // x10
  unsigned __int64 v225; // x11
  unsigned __int64 v226; // x9
  unsigned __int64 v227; // x8
  __int64 v228; // x2
  __int64 v229; // x4
  __int64 v230; // x19
  __int64 v231; // x28
  __int64 v232; // x25
  __int64 *v233; // x0
  __int64 v234; // x8
  unsigned int v235; // w0
  __int64 v236; // x8
  __int64 v237; // x1
  __int64 v238; // x2
  __int64 v239; // x4
  unsigned int v240; // w0
  __int64 v241; // x8
  __int64 v242; // x9
  __int64 v243; // x10
  __int64 v244; // x6
  __int64 v245; // x7
  unsigned __int64 v246; // x8
  unsigned __int64 v247; // x9
  __int64 v248; // x8
  unsigned __int64 v249; // x21
  unsigned __int64 v250; // x23
  unsigned __int64 v251; // x24
  __int64 v252; // x10
  __int64 v253; // x11
  __int64 v254; // x12
  int v255; // w10
  unsigned __int64 v256; // x11
  unsigned __int64 v257; // x12
  unsigned __int64 v258; // x25
  unsigned __int64 v259; // x0
  int v260; // w6
  unsigned __int64 v261; // x24
  unsigned __int64 v262; // x26
  __int64 *settings; // x0
  unsigned __int64 v264; // x8
  unsigned __int64 v265; // x25
  __int64 *v266; // x0
  __int64 v267; // x8
  __int64 v268; // x9
  unsigned int clk_level; // w0
  __int64 v270; // x7
  unsigned int v271; // w0
  int v272; // w8
  int v273; // w9
  unsigned int v274; // w0
  __int64 v275; // x1
  unsigned __int64 v277; // [xsp+30h] [xbp-170h]
  unsigned __int64 v278; // [xsp+38h] [xbp-168h]
  unsigned __int64 v279; // [xsp+40h] [xbp-160h]
  int v280; // [xsp+48h] [xbp-158h]
  unsigned int v281; // [xsp+4Ch] [xbp-154h]
  unsigned __int64 v282; // [xsp+50h] [xbp-150h]
  _BYTE *v283; // [xsp+58h] [xbp-148h]
  unsigned __int64 v285; // [xsp+68h] [xbp-138h]
  _BYTE *v286; // [xsp+70h] [xbp-130h]
  unsigned __int64 v287; // [xsp+78h] [xbp-128h]
  unsigned __int64 v288; // [xsp+80h] [xbp-120h]
  unsigned __int64 v289; // [xsp+88h] [xbp-118h]
  __int64 v290; // [xsp+90h] [xbp-110h]
  _DWORD *v291; // [xsp+98h] [xbp-108h]
  unsigned __int64 v292; // [xsp+98h] [xbp-108h]
  _DWORD *v293; // [xsp+A0h] [xbp-100h]
  __int64 v294; // [xsp+A0h] [xbp-100h]
  _DWORD *v295; // [xsp+A8h] [xbp-F8h]
  __int64 v296; // [xsp+A8h] [xbp-F8h]
  _DWORD *v297; // [xsp+B0h] [xbp-F0h]
  unsigned int v298; // [xsp+B0h] [xbp-F0h]
  _DWORD *v299; // [xsp+B8h] [xbp-E8h]
  _QWORD *v300; // [xsp+B8h] [xbp-E8h]
  _DWORD *v301; // [xsp+C0h] [xbp-E0h]
  __int64 v303; // [xsp+D0h] [xbp-D0h] BYREF
  __int64 v304; // [xsp+D8h] [xbp-C8h]
  __int64 v305; // [xsp+E0h] [xbp-C0h]
  __int64 v306; // [xsp+E8h] [xbp-B8h]
  __int64 v307; // [xsp+F0h] [xbp-B0h]
  __int64 v308; // [xsp+F8h] [xbp-A8h]
  __int64 v309; // [xsp+100h] [xbp-A0h]
  __int64 v310; // [xsp+108h] [xbp-98h] BYREF
  unsigned __int64 v311; // [xsp+110h] [xbp-90h]
  __int64 v312; // [xsp+118h] [xbp-88h]
  __int64 v313; // [xsp+120h] [xbp-80h]
  __int64 v314; // [xsp+128h] [xbp-78h]
  __int64 v315; // [xsp+130h] [xbp-70h]
  __int64 v316; // [xsp+138h] [xbp-68h]
  int v317; // [xsp+144h] [xbp-5Ch] BYREF
  int v318; // [xsp+148h] [xbp-58h]
  __int16 v319; // [xsp+14Ch] [xbp-54h]
  int v320; // [xsp+150h] [xbp-50h] BYREF
  __int16 v321; // [xsp+154h] [xbp-4Ch]
  __int64 v322; // [xsp+158h] [xbp-48h] BYREF
  _QWORD v323[2]; // [xsp+160h] [xbp-40h]
  __int64 v324; // [xsp+170h] [xbp-30h]
  __int64 v325; // [xsp+178h] [xbp-28h]
  __int64 v326; // [xsp+180h] [xbp-20h]
  __int64 v327; // [xsp+188h] [xbp-18h]
  __int64 v328; // [xsp+190h] [xbp-10h]

  v328 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 3680);
  v11 = *(_BYTE **)(a1 + 3392);
  v303 = 0;
  v321 = 0;
  v320 = 0;
  v319 = 0;
  v318 = 0;
  v315 = 0;
  v316 = 0;
  v313 = 0;
  v314 = 0;
  v311 = 0;
  v312 = 0;
  v310 = 0;
  v308 = 0;
  v309 = 0;
  v306 = 0;
  v307 = 0;
  v304 = 0;
  v305 = 0;
  v286 = v11;
  v283 = (_BYTE *)(v10 + 4161);
  mutex_lock(v10 + 2728);
  v285 = v10;
  if ( (*(_BYTE *)(a2 + 170) & 1) == 0 )
  {
    v55 = *(_DWORD *)(v10 + 2780);
    if ( v55 )
    {
      if ( (*(_BYTE *)(v10 + 3184) & 1) == 0 )
      {
        if ( *(_QWORD *)(a3 + 32) )
          v56 = 1024;
        else
          v56 = -1024;
        *(_QWORD *)(v10 + 3440) += v56;
        LOBYTE(v320) = 1;
      }
      if ( v55 != 1 )
      {
        if ( (*(_BYTE *)(v10 + 3592) & 1) == 0 )
        {
          if ( *(_QWORD *)(a3 + 32) )
            v57 = 1024;
          else
            v57 = -1024;
          *(_QWORD *)(v10 + 3848) += v57;
          BYTE1(v320) = 1;
        }
        if ( v55 >= 3 )
        {
          if ( (*(_BYTE *)(v10 + 4000) & 1) == 0 )
          {
            if ( *(_QWORD *)(a3 + 32) )
              v58 = 1024;
            else
              v58 = -1024;
            *(_QWORD *)(v10 + 4256) += v58;
            BYTE2(v320) = 1;
          }
          if ( v55 != 3 )
          {
            if ( (*(_BYTE *)(v10 + 4408) & 1) == 0 )
            {
              if ( *(_QWORD *)(a3 + 32) )
                v59 = 1024;
              else
                v59 = -1024;
              *(_QWORD *)(v10 + 4664) += v59;
              HIBYTE(v320) = 1;
            }
            if ( v55 >= 5 )
            {
              if ( (*(_BYTE *)(v10 + 4816) & 1) == 0 )
              {
                if ( *(_QWORD *)(a3 + 32) )
                  v60 = 1024;
                else
                  v60 = -1024;
                *(_QWORD *)(v10 + 5072) += v60;
                LOBYTE(v321) = 1;
              }
              if ( v55 != 5 )
              {
                if ( (*(_BYTE *)(v10 + 5224) & 1) == 0 )
                {
                  if ( *(_QWORD *)(a3 + 32) )
                    v61 = 1024;
                  else
                    v61 = -1024;
                  *(_QWORD *)(v10 + 5480) += v61;
                  HIBYTE(v321) = 1;
                }
                if ( v55 > 6 )
                  goto LABEL_500;
              }
            }
          }
        }
      }
    }
    if ( *(_DWORD *)(v10 + 2784) )
    {
      v62 = -1024;
      v63 = *(_DWORD *)(v10 + 2784);
      v64 = *(_QWORD *)(a3 + 24) ? 1024LL : -1024LL;
      *(_QWORD *)(v10 + 5888) += v64;
      LOBYTE(v318) = 1;
      if ( v63 > 1 )
      {
        v65 = *(_QWORD *)(a3 + 24);
        v66 = *(_QWORD *)(v10 + 6296);
        BYTE1(v318) = 1;
        v32 = v65 == 0;
        v67 = *(_DWORD *)(v10 + 2784);
        if ( !v32 )
          v62 = 1024;
        *(_QWORD *)(v10 + 6296) = v66 + v62;
        if ( v67 >= 3 )
        {
          v68 = -1024;
          v69 = *(_DWORD *)(v10 + 2784);
          v70 = *(_QWORD *)(a3 + 24) ? 1024LL : -1024LL;
          *(_QWORD *)(v10 + 6704) += v70;
          BYTE2(v318) = 1;
          if ( v69 >= 4 )
          {
            v71 = *(_QWORD *)(a3 + 24);
            v72 = *(_QWORD *)(v10 + 7112);
            HIBYTE(v318) = 1;
            v32 = v71 == 0;
            v73 = *(_DWORD *)(v10 + 2784);
            if ( !v32 )
              v68 = 1024;
            *(_QWORD *)(v10 + 7112) = v72 + v68;
            if ( v73 >= 5 )
            {
              v74 = -1024;
              v75 = *(_DWORD *)(v10 + 2784);
              v76 = *(_QWORD *)(a3 + 24) ? 1024LL : -1024LL;
              *(_QWORD *)(v10 + 7520) += v76;
              LOBYTE(v319) = 1;
              if ( v75 >= 6 )
              {
                v77 = *(_QWORD *)(a3 + 24);
                v78 = *(_QWORD *)(v10 + 7928);
                HIBYTE(v319) = 1;
                v32 = v77 == 0;
                v79 = *(_DWORD *)(v10 + 2784);
                if ( !v32 )
                  v74 = 1024;
                *(_QWORD *)(v10 + 7928) = v78 + v74;
                if ( v79 > 6 )
                  goto LABEL_500;
              }
            }
          }
        }
      }
    }
    LODWORD(v301) = 0;
    goto LABEL_161;
  }
  memset((void *)(a2 + 184), 0, 0x350u);
  LODWORD(v13) = *(_DWORD *)a3;
  if ( *(_DWORD *)a3 )
  {
    v14 = 0;
    v299 = (_DWORD *)(a2 + 416);
    v301 = (_DWORD *)(a2 + 360);
    v15 = (_DWORD *)(a2 + 192);
    v16 = a2 + 1040;
    v17 = (_DWORD *)(a2 + 248);
    v18 = (_DWORD *)(a2 + 304);
    v295 = (_DWORD *)(a2 + 528);
    v297 = (_DWORD *)(a2 + 472);
    v19 = (_DWORD *)(a2 + 696);
    v20 = (_DWORD *)(a2 + 752);
    v21 = (_DWORD *)(a2 + 808);
    v22 = (_DWORD *)(a2 + 864);
    v23 = (_DWORD *)(a2 + 920);
    v4 = a2 + 976;
    LODWORD(v10) = 40;
    v5 = 56;
    v6 = 8;
    v7 = 48;
    v291 = (_DWORD *)(a2 + 640);
    v293 = (_DWORD *)(a2 + 584);
    do
    {
      if ( v14 == 15 )
        goto LABEL_500;
      v24 = a3 + 8 + 40 * v14;
      v26 = *(unsigned int *)(v24 + 4);
      v25 = *(unsigned int *)(v24 + 8);
      if ( (unsigned int)v25 > 0x29 || (unsigned int)v26 >= 2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_axi_consolidate_path_votes",
          1801,
          "Invalid path or transac type: %d %d",
          v25,
          v26);
        goto LABEL_228;
      }
      v28 = *(_DWORD *)(a2 + 184);
      if ( v28 > 0xF )
        goto LABEL_500;
      if ( *(_QWORD *)(v16 + 16 * v25 + 8 * v26) )
      {
        v29 = &v15[14 * v28];
        v30 = v28 + 1;
        *v29 = v26;
        v29[1] = *(_DWORD *)(v24 + 8);
        v31 = *(_DWORD *)(v24 + 12);
        v32 = v31 == 1;
        if ( v31 == 1 )
          v33 = 6;
        else
          v33 = 12;
        *(_QWORD *)&v29[v33] = *(_QWORD *)(v24 + 16);
        if ( v31 == 1 )
          v34 = 2;
        else
          v34 = 8;
        *(_QWORD *)&v29[v34] = *(_QWORD *)(v24 + 24);
        if ( v32 )
          v35 = 4;
        else
          v35 = 10;
        v36 = *(_QWORD *)(v24 + 32);
        *(_DWORD *)(a2 + 184) = v30;
      }
      else
      {
        v12 = a2;
        v37 = 0;
        v38 = 8 * v26 + 1040;
        while ( 1 )
        {
          v39 = *(_QWORD *)(v12 + v38);
          if ( v39 )
          {
            if ( *(_BYTE *)(v39 + v25 + 58) == 1 )
              break;
          }
          --v37;
          v38 += 16;
          if ( v37 == -42 )
          {
            a2 = v12;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_axi_consolidate_path_votes",
              1832,
              "Client [%s][%d] i=%d num_paths=%d Consolidated path not found for path=%d, transac=%d",
              (const char *)v12,
              *(_DWORD *)(v12 + 128),
              v14,
              v13,
              v25,
              v26);
LABEL_228:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x2000000,
              1,
              "cam_cpas_util_apply_client_axi_vote",
              2018,
              "Failed in bw consolidation, Client [%s][%d]",
              (const char *)a2,
              *(_DWORD *)(a2 + 128));
            goto LABEL_316;
          }
        }
        if ( v28 )
        {
          if ( !(*(_DWORD *)(v12 + 196) + (_DWORD)v37) )
          {
            v40 = v15;
            if ( *v15 == (_DWORD)v26 )
            {
LABEL_98:
              v48 = *(_QWORD *)(v24 + 16);
              if ( *(_DWORD *)(v24 + 12) == 1 )
              {
                v49 = v40[2];
                a2 = v12;
                v50 = v40[3] + v48;
                v51 = v40[1];
                v40[3] = v50;
                v40[1] = v51 + *(_QWORD *)(v24 + 24);
                v40[2] = v49 + *(_QWORD *)(v24 + 32);
              }
              else
              {
                v52 = v40[5];
                a2 = v12;
                v53 = v40[6] + v48;
                v54 = v40[4];
                v40[6] = v53;
                v40[4] = v54 + *(_QWORD *)(v24 + 24);
                v40[5] = v52 + *(_QWORD *)(v24 + 32);
              }
              goto LABEL_22;
            }
          }
          if ( v28 == 1 )
          {
            v41 = 1;
          }
          else
          {
            if ( !(*(_DWORD *)(v12 + 252) + (_DWORD)v37) )
            {
              v40 = v17;
              if ( *v17 == (_DWORD)v26 )
                goto LABEL_98;
            }
            if ( v28 == 2 )
            {
              v41 = 2;
            }
            else
            {
              if ( !(*(_DWORD *)(v12 + 308) + (_DWORD)v37) )
              {
                v40 = v18;
                if ( *v18 == (_DWORD)v26 )
                  goto LABEL_98;
              }
              if ( v28 == 3 )
              {
                v41 = 3;
              }
              else
              {
                if ( !(*(_DWORD *)(v12 + 364) + (_DWORD)v37) )
                {
                  v40 = v301;
                  if ( *v301 == (_DWORD)v26 )
                    goto LABEL_98;
                }
                if ( v28 == 4 )
                {
                  v41 = 4;
                }
                else
                {
                  if ( !(*(_DWORD *)(v12 + 420) + (_DWORD)v37) )
                  {
                    v40 = v299;
                    if ( *v299 == (_DWORD)v26 )
                      goto LABEL_98;
                  }
                  if ( v28 == 5 )
                  {
                    v41 = 5;
                  }
                  else
                  {
                    if ( !(*(_DWORD *)(v12 + 476) + (_DWORD)v37) )
                    {
                      v40 = v297;
                      if ( *v297 == (_DWORD)v26 )
                        goto LABEL_98;
                    }
                    if ( v28 == 6 )
                    {
                      v41 = 6;
                    }
                    else
                    {
                      if ( !(*(_DWORD *)(v12 + 532) + (_DWORD)v37) )
                      {
                        v40 = v295;
                        if ( *v295 == (_DWORD)v26 )
                          goto LABEL_98;
                      }
                      if ( v28 == 7 )
                      {
                        v41 = 7;
                      }
                      else
                      {
                        if ( !(*(_DWORD *)(v12 + 588) + (_DWORD)v37) )
                        {
                          v40 = v293;
                          if ( *v293 == (_DWORD)v26 )
                            goto LABEL_98;
                        }
                        if ( v28 == 8 )
                        {
                          v41 = 8;
                        }
                        else
                        {
                          if ( !(*(_DWORD *)(v12 + 644) + (_DWORD)v37) )
                          {
                            v40 = v291;
                            if ( *v291 == (_DWORD)v26 )
                              goto LABEL_98;
                          }
                          if ( v28 == 9 )
                          {
                            v41 = 9;
                          }
                          else
                          {
                            if ( !(*(_DWORD *)(v12 + 700) + (_DWORD)v37) )
                            {
                              v40 = v19;
                              if ( *v19 == (_DWORD)v26 )
                                goto LABEL_98;
                            }
                            if ( v28 == 10 )
                            {
                              v41 = 10;
                            }
                            else
                            {
                              if ( !(*(_DWORD *)(v12 + 756) + (_DWORD)v37) )
                              {
                                v40 = v20;
                                if ( *v20 == (_DWORD)v26 )
                                  goto LABEL_98;
                              }
                              if ( v28 == 11 )
                              {
                                v41 = 11;
                              }
                              else
                              {
                                if ( !(*(_DWORD *)(v12 + 812) + (_DWORD)v37) )
                                {
                                  v40 = v21;
                                  if ( *v21 == (_DWORD)v26 )
                                    goto LABEL_98;
                                }
                                if ( v28 == 12 )
                                {
                                  v41 = 12;
                                }
                                else
                                {
                                  if ( !(*(_DWORD *)(v12 + 868) + (_DWORD)v37) )
                                  {
                                    v40 = v22;
                                    if ( *v22 == (_DWORD)v26 )
                                      goto LABEL_98;
                                  }
                                  if ( v28 == 13 )
                                  {
                                    v41 = 13;
                                  }
                                  else
                                  {
                                    if ( !(*(_DWORD *)(v12 + 924) + (_DWORD)v37) )
                                    {
                                      v40 = v23;
                                      if ( *v23 == (_DWORD)v26 )
                                        goto LABEL_98;
                                    }
                                    if ( v28 == 14 )
                                    {
                                      v41 = 14;
                                    }
                                    else
                                    {
                                      v41 = v28;
                                      if ( !(*(_DWORD *)(v12 + 980) + (_DWORD)v37) )
                                      {
                                        v40 = (_QWORD *)v4;
                                        v41 = v28;
                                        if ( *(_DWORD *)v4 == (_DWORD)v26 )
                                          goto LABEL_98;
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
        else
        {
          v41 = 0;
        }
        v29 = &v15[14 * v41];
        v42 = -v37;
        v43 = v28 + 1;
        a2 = v12;
        *v29 = v26;
        v29[1] = v42;
        v44 = *(_DWORD *)(v24 + 12);
        v45 = v44 == 1;
        if ( v44 == 1 )
          v46 = 6;
        else
          v46 = 12;
        *(_QWORD *)&v29[v46] = *(_QWORD *)(v24 + 16);
        if ( v44 == 1 )
          v47 = 2;
        else
          v47 = 8;
        *(_QWORD *)&v29[v47] = *(_QWORD *)(v24 + 24);
        if ( v45 )
          v35 = 4;
        else
          v35 = 10;
        v36 = *(_QWORD *)(v24 + 32);
        *(_DWORD *)(v12 + 184) = v43;
      }
      *(_QWORD *)&v29[v35] = v36;
LABEL_22:
      v13 = *(unsigned int *)a3;
      ++v14;
    }
    while ( v14 < v13 );
  }
  cam_cpas_dump_cons_axi_vote_info(a2, "Consolidated Vote", (unsigned int *)(a2 + 184));
  cam_cpas_dump_full_tree_state(a1, "BeforeClientVoteUpdate");
  if ( !*(_DWORD *)(a2 + 184) )
  {
    cam_cpas_dump_full_tree_state(a1, "AfterClientVoteUpdate");
    v10 = v285;
    goto LABEL_232;
  }
  a3 = 0;
  v120 = 0;
  v5 = 0xFFFFFFFFLL;
  v121 = -1;
  v278 = a2 + 1040;
  v279 = a2 + 192;
  v277 = a2;
  do
  {
    if ( a3 == 15 )
      goto LABEL_500;
    v126 = (unsigned int *)(v279 + 56 * a3);
    v127 = v126[1];
    if ( (unsigned int)v127 > 0x29 )
      goto LABEL_500;
    v128 = *v126;
    if ( (unsigned int)v128 > 1 )
      goto LABEL_500;
    v10 = *(_QWORD *)(v278 + 16 * v127 + 8 * v128);
    if ( v286[1609] == 1 && (*(_BYTE *)(v285 + 159432) & 1) == 0 )
    {
      v129 = *(_DWORD *)(v10 + 16);
      if ( v286[1610] == 1 && *(_BYTE *)(v285 + 159433) != 1 )
        LODWORD(v301) = *(_DWORD *)(v10 + 16);
      else
        LODWORD(v301) = 0;
    }
    else
    {
      LODWORD(v301) = 0;
      v129 = 0;
    }
    v130 = (unsigned int)v301;
    if ( v129 > 3 || (unsigned int)v301 >= 4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_apply_client_axi_vote",
        2046,
        "Invalid drv idx : ddr_drv_idx=%d, cesta_drv_idx=%d",
        v129,
        (_DWORD)v301);
LABEL_496:
      v10 = v285;
      goto LABEL_497;
    }
    v131 = (int)v301;
    v132 = v129;
    v300 = (_QWORD *)(v279 + 56 * a3);
    if ( a3 )
    {
      if ( (_DWORD)v5 == v129 && v121 == (_DWORD)v301 )
      {
        v130 = (unsigned int)v301;
      }
      else
      {
        v130 = (unsigned int)v301;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          2,
          "cam_cpas_util_apply_client_axi_vote",
          2060,
          "DRV indices different : DDR: %d, %d, CESTA %d %d",
          v5,
          v129,
          v121,
          (_DWORD)v301);
      }
      v131 = v121;
      v132 = v5;
    }
    v280 = v131;
    v281 = v132;
    v133 = *(_QWORD *)(v10 + 48);
    v134 = v133 + 56LL * v130;
    v135 = (_QWORD *)(v133 + 56LL * v129);
    v136 = v129;
    v282 = a3;
    v137 = *(_QWORD *)(v134 + 24);
    v138 = *(_QWORD *)(v134 + 48);
    v7 = v135[1];
    v139 = v135[2];
    v140 = v135[4];
    v6 = v135[5];
    LOBYTE(v4) = v130;
    v298 = v136;
    cam_cpas_dump_tree_vote_info(a1, v10, "Level0 before update", v136, v130);
    v296 = v130;
    v287 = (unsigned __int64)v130 << 6;
    if ( !v130 )
    {
      v142 = v300;
      v145 = *(_QWORD *)(v10 + 48);
      v141 = a4;
      v147 = *(_QWORD *)(v145 + 24);
      v146 = (_QWORD *)(v145 + 24);
      v148 = v300[6] + v300[3];
      if ( v147 != v148 )
      {
        v149 = 0;
        *v146 = v148;
        goto LABEL_263;
      }
LABEL_261:
      v149 = 1;
      goto LABEL_263;
    }
    v141 = a4;
    v142 = v300;
    if ( a4 == 2 )
    {
      v143 = v300[3];
      v144 = *(_QWORD *)(v10 + 48);
    }
    else
    {
      v144 = *(_QWORD *)(v10 + 48);
      v143 = v300[3];
      v150 = v144 + 56LL * v130;
      if ( *(_QWORD *)(v150 + 24) == v143 )
      {
        v143 = *(_QWORD *)(v150 + 24);
        if ( *(_QWORD *)(v150 + 48) == v300[6] )
          goto LABEL_261;
      }
    }
    v149 = 0;
    v151 = 56LL * v130;
    *(_QWORD *)(v144 + v151 + 24) = v143;
    *(_QWORD *)(*(_QWORD *)(v10 + 48) + v151 + 48) = v300[6];
LABEL_263:
    LOBYTE(v299) = v298;
    v288 = (unsigned __int64)v298 << 6;
    if ( v298 )
    {
      if ( v141 == 2 )
        v149 = 0;
      if ( (v149 & 1) != 0 )
      {
        v152 = *(_QWORD *)(v10 + 48);
        v153 = v152 + 56LL * v298;
        v156 = *(_QWORD *)(v153 + 8);
        v155 = (_QWORD *)(v153 + 8);
        v154 = v156;
        if ( v156 == v142[1] )
        {
          if ( v155[3] == v142[4] && v155[1] == v142[2] && v155[4] == v142[5] )
            goto LABEL_239;
        }
        else
        {
          v154 = v142[1];
        }
      }
      else
      {
        v154 = v142[1];
        v152 = *(_QWORD *)(v10 + 48);
      }
      v159 = 56LL * v298;
      *(_QWORD *)(v152 + v159 + 8) = v154;
      *(_QWORD *)(*(_QWORD *)(v10 + 48) + v159 + 32) = v142[4];
      *(_QWORD *)(*(_QWORD *)(v10 + 48) + v159 + 16) = v142[2];
      *(_QWORD *)(*(_QWORD *)(v10 + 48) + v159 + 40) = v142[5];
    }
    else
    {
      if ( (v149 & 1) != 0 )
      {
        v157 = *(_QWORD *)(v10 + 48);
        v158 = v142[4] + v142[1];
        if ( *(_QWORD *)(v157 + 8) == v158 && *(_QWORD *)(v157 + 16) == v142[5] + v142[2] )
          goto LABEL_239;
      }
      else
      {
        v157 = *(_QWORD *)(v10 + 48);
        v158 = v142[4] + v142[1];
      }
      *(_QWORD *)(v157 + v288 + 8) = v158;
      *(_QWORD *)(*(_QWORD *)(v10 + 48) + v288 + 16) = v142[5] + v142[2];
    }
    cam_cpas_dump_tree_vote_info(a1, v10, "Level0 after update", v298, (int)v301);
    v160 = *(_QWORD *)(v10 + 112);
    for ( i = v298; v160; v140 = a2 )
    {
      v120 = v160;
      v162 = *(_QWORD *)(v160 + 48);
      v163 = v162 + 56LL * (unsigned int)v296;
      v164 = (_QWORD *)(v162 + 56LL * i);
      a2 = v164[4];
      v4 = v164[5];
      v292 = *(_QWORD *)(v163 + 24);
      v294 = v164[1];
      v289 = *(_QWORD *)(v163 + 48);
      v290 = v164[2];
      cam_cpas_dump_tree_vote_info(a1, v120, "Parent before update", v298, (int)v301);
      v165 = *(_DWORD *)(v120 + 40);
      if ( v165 )
      {
        if ( v165 != 1 )
        {
          v196 = "Invalid Merge type";
          v197 = 2158;
          goto LABEL_315;
        }
        v166 = 2;
      }
      else
      {
        v166 = 1;
      }
      v167 = v137 / v166;
      v5 = (unsigned int)v301;
      v168 = *(_QWORD *)(v120 + 48) + 56LL * (unsigned int)v296;
      *(_QWORD *)(v168 + 24) -= v167;
      if ( (_DWORD)v301 )
      {
        v169 = v287 - 8 * v296;
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v169 + 48) -= v138 / v166;
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v169 + 24) += *(_QWORD *)(*(_QWORD *)(v10 + 48) + v169 + 24) / v166;
        v170 = (_QWORD *)(*(_QWORD *)(v10 + 48) + v169 + 48);
        v171 = (_QWORD *)(*(_QWORD *)(v120 + 48) + v169 + 48);
      }
      else
      {
        v172 = v287 - 8 * v296;
        v173 = *(_QWORD *)(v120 + 48) + v172;
        v170 = (_QWORD *)(*(_QWORD *)(v10 + 48) + v172 + 24);
        v171 = (_QWORD *)(v173 + 24);
      }
      LOBYTE(a3) = v298;
      *v171 += *v170 / v166;
      v174 = 56LL * v298;
      *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 8) -= v7;
      *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 16) -= v139;
      if ( v298 )
      {
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 32) -= v140;
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 40) -= v6;
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 8) += *(_QWORD *)(*(_QWORD *)(v10 + 48) + v174 + 8);
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 16) += *(_QWORD *)(*(_QWORD *)(v10 + 48) + v174 + 16);
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 32) += *(_QWORD *)(*(_QWORD *)(v10 + 48) + v174 + 32);
        v175 = (_QWORD *)(*(_QWORD *)(v10 + 48) + v174 + 40);
        v176 = (_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 40);
      }
      else
      {
        *(_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 8) += *(_QWORD *)(*(_QWORD *)(v10 + 48) + v174 + 8);
        v175 = (_QWORD *)(*(_QWORD *)(v10 + 48) + v174 + 16);
        v176 = (_QWORD *)(*(_QWORD *)(v120 + 48) + v174 + 16);
      }
      *v176 += *v175;
      cam_cpas_dump_tree_vote_info(a1, v120, "Parent after update", v298, (int)v301);
      v160 = *(_QWORD *)(v120 + 112);
      i = v298;
      if ( !v160 )
      {
        if ( (debug_bypass_drivers & 0x10) != 0 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x20000,
            2,
            "cam_cpas_update_axi_vote_bw",
            1853,
            "Bypass update axi vote bw");
          i = v298;
        }
        else
        {
          v177 = *(unsigned int *)(*(_QWORD *)(v120 + 8) + 4LL * v298);
          if ( (unsigned int)v177 > 5 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_update_axi_vote_bw",
              1861,
              "Invalid axi_port_idx: %d drv_idx: %d",
              v177,
              v298);
            v196 = "Update Vote failed";
            v197 = 2230;
LABEL_315:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_util_apply_client_axi_vote",
              v197,
              v196);
LABEL_316:
            v10 = v285;
            v122 = -22;
            goto LABEL_498;
          }
          v178 = (_QWORD *)(*(_QWORD *)(v120 + 48) + 56LL * v298);
          v179 = *(_QWORD *)(a1 + 3680);
          v180 = (_QWORD *)(v179 + 408LL * (unsigned int)v177);
          v181 = *(_QWORD *)(a1 + 3392);
          v183 = v178[1];
          v182 = v178[2];
          v180[423] = *v178;
          v180[425] = v182;
          v180[424] = v183;
          v185 = v178[5];
          v184 = v178[6];
          v187 = v178[3];
          v186 = v178[4];
          v180[429] = v184;
          v180[428] = v185;
          v180[427] = v186;
          v180[426] = v187;
          if ( v298 )
          {
            v188 = v180 + 423;
            v189 = v188[2] + v188[5];
            v188[1] += v188[4];
            v188[2] = v189;
          }
          v190 = *(_BYTE *)(v181 + 1036);
          *((_BYTE *)&v320 + v177) = 1;
          if ( (v190 & 1) == 0 )
          {
            v191 = **(_DWORD **)(v120 + 8);
            if ( (_DWORD)v301 )
            {
              if ( v191 > 5 )
                goto LABEL_500;
              v192 = *(_QWORD *)(v120 + 48) + 56LL * (unsigned int)v296;
              v193 = v179 + 408LL * v191;
              v194 = *(_QWORD *)(v192 + 48) + *(_QWORD *)(v192 + 24);
            }
            else
            {
              if ( v191 > 5 )
                goto LABEL_500;
              v193 = v179 + 408LL * v191;
              v194 = *(_QWORD *)(*(_QWORD *)(v120 + 48) + 24LL);
            }
            *(_QWORD *)(v193 + 5856) = v194;
            v195 = *(unsigned int *)(v120 + 20);
            if ( (unsigned int)v195 > 5 )
LABEL_503:
              __break(1u);
            *((_BYTE *)&v318 + v195) = 1;
          }
        }
        v160 = *(_QWORD *)(v120 + 112);
      }
      v138 = v289;
      v139 = v290;
      v10 = v120;
      v137 = v292;
      v7 = v294;
      v6 = v4;
    }
LABEL_239:
    a2 = v277;
    v10 = v285;
    v121 = v280;
    v5 = v281;
    a3 = v282 + 1;
  }
  while ( v282 + 1 < *(unsigned int *)(v277 + 184) );
  v5 = a1;
  cam_cpas_dump_full_tree_state(a1, "AfterClientVoteUpdate");
  if ( !v120 )
  {
LABEL_232:
    v122 = 0;
    if ( (debug_mdl & 4) == 0 || debug_priority )
      goto LABEL_498;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_util_apply_client_axi_vote",
      2245,
      "No change in BW for all paths");
LABEL_497:
    v122 = 0;
    goto LABEL_498;
  }
  if ( v286[1608] != 1 )
    goto LABEL_161;
  v4 = (unsigned __int64)&unk_393000;
  v12 = debug_mdl & 0x2000004;
  if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12,
      4,
      "cam_cpas_util_apply_client_axi_vote",
      2252,
      "Start QoS update for client[%s][%d]",
      (const char *)v277,
      *(_DWORD *)(v277 + 128));
  v198 = *(_DWORD *)(v285 + 2780);
  if ( !v198 )
    goto LABEL_351;
  if ( (unsigned __int8)v320 == 1 && (*(_BYTE *)(v285 + 3345) & 1) != 0 )
    goto LABEL_341;
  if ( v198 == 1 )
    goto LABEL_351;
  if ( BYTE1(v320) == 1 && (*(_BYTE *)(v285 + 3753) & 1) != 0 )
    goto LABEL_341;
  if ( v198 == 2 )
    goto LABEL_351;
  if ( BYTE2(v320) == 1 && (*v283 & 1) != 0 )
    goto LABEL_341;
  if ( v198 == 3 )
    goto LABEL_351;
  if ( HIBYTE(v320) == 1 && (v283[408] & 1) != 0 )
    goto LABEL_341;
  if ( v198 == 4 )
  {
LABEL_351:
    v10 = v285;
    goto LABEL_161;
  }
  v5 = a1;
  if ( (unsigned __int8)v321 == 1 && (v283[816] & 1) != 0 )
  {
LABEL_341:
    if ( (cam_cpas_calculate_smart_qos(v5, v12) & 1) == 0 )
      goto LABEL_351;
    if ( (cam_cpas_is_new_rt_bw_lower(v5) & 1) != 0 )
    {
      v199 = debug_mdl & 0x2000004;
      if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v199,
          4,
          "cam_cpas_util_apply_client_axi_vote",
          2268,
          "Apply Smart QoS first");
      v200 = cam_cpas_apply_smart_qos(v5, v199);
      v10 = v285;
      if ( v200 )
      {
        v122 = v200;
        v201 = "Failed in Smart QoS rc=%d";
        v202 = 2272;
        goto LABEL_485;
      }
      goto LABEL_161;
    }
    v10 = v285;
    LOBYTE(v299) = 1;
    v80 = *(unsigned int *)(v285 + 2780);
    if ( !(_DWORD)v80 )
      goto LABEL_353;
LABEL_162:
    v81 = 0;
    v4 = 0;
    v5 = (__int64)&v320;
    a2 = (unsigned __int64)&unk_393000;
    v7 = (__int64)&unk_393000;
    v6 = (__int64)&unk_393000;
    while ( 1 )
    {
      if ( v81 == 2448 )
        goto LABEL_500;
      if ( *((_BYTE *)&v320 + v4) != 1 )
        goto LABEL_165;
      v90 = v10 + v81;
      v91 = *(_QWORD *)(v10 + v81 + 3400);
      v92 = *(_QWORD *)(v10 + v81 + 3384);
      v311 = *(_QWORD *)(v10 + v81 + 3392);
      v312 = v91;
      v310 = v92;
      v93 = *(_QWORD *)(v10 + v81 + 3432);
      v94 = *(_QWORD *)(v10 + v81 + 3408);
      v95 = *(_QWORD *)(v10 + v81 + 3416);
      v315 = *(_QWORD *)(v10 + v81 + 3424);
      v316 = v93;
      v313 = v94;
      v314 = v95;
      v96 = debug_mdl & 0x2000004;
      v97 = v96 != 0;
      if ( debug_priority )
        v97 = 0;
      if ( *(_BYTE *)(v10 + v81 + 3184) != 1 )
      {
        if ( v97 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v96,
            4,
            "cam_cpas_util_apply_client_axi_vote",
            2385,
            "Port[%s] :HLOS ab=%lld ib=%lld additional=%lld, streamon_clients=%d",
            *(const char **)(v90 + 3096),
            *(_QWORD *)(v10 + v81 + 3392),
            *(_QWORD *)(v10 + v81 + 3400),
            *(_QWORD *)(v10 + v81 + 3440),
            *(_DWORD *)(v10 + 2792));
        v104 = v10 + v81;
        if ( *(_QWORD *)(v10 + v81 + 3392) )
        {
          if ( (*(_BYTE *)(v104 + 3344) & 1) == 0 )
            goto LABEL_199;
        }
        else
        {
          v105 = *(_QWORD *)(v104 + 3440);
          if ( !v105 )
            v105 = (unsigned __int64)(*(_DWORD *)(v10 + 2792) != 0) << 10;
          v311 = v105;
          if ( (*(_BYTE *)(v104 + 3344) & 1) == 0 )
LABEL_199:
            v312 = 0;
        }
        v82 = ((__int64 (__fastcall *)(_BYTE *, unsigned __int64, __int64, _QWORD, __int64 *, __int64 *))cam_cpas_util_vote_hlos_bus_client_bw)(
                v286,
                v10,
                v90 + 3104,
                0,
                &v310,
                &v303);
        v83 = v10;
        if ( v82 )
        {
          v122 = v82;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_util_apply_client_axi_vote",
            2403,
            "Failed in mnoc vote for %s rc=%d",
            *(const char **)(v10 + v81 + 3096),
            v82);
          goto LABEL_498;
        }
        goto LABEL_164;
      }
      if ( v97 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v96,
          4,
          "cam_cpas_util_apply_client_axi_vote",
          2298,
          "Port[%s] :DRV high [%lld %lld] low [%lld %lld] streamon_clients=%d",
          *(const char **)(v90 + 3096),
          *(_QWORD *)(v10 + v81 + 3392),
          *(_QWORD *)(v10 + v81 + 3400),
          *(_QWORD *)(v10 + v81 + 3416),
          *(_QWORD *)(v10 + v81 + 3424),
          *(_DWORD *)(v10 + 2792));
      if ( (*(_BYTE *)(v10 + v81 + 3344) & 1) == 0 )
      {
        v312 = 0;
        v315 = 0;
      }
      v98 = cam_cpas_util_vote_drv_bus_client_bw(v286, v10, v90 + 3104, &v310, &v303);
      if ( v98 )
      {
        v122 = v98;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_util_apply_client_axi_vote",
          2311,
          "Failed in mnoc vote for %s rc=%d",
          *(const char **)(v10 + v81 + 3096),
          v98);
        goto LABEL_498;
      }
      v99 = v10 + v81;
      if ( a4 == 1 )
      {
        if ( (*(_BYTE *)(v99 + 3376) & 1) != 0 )
          goto LABEL_201;
        v112 = v285 + v81;
        started = cam_cpas_start_drv_for_dev(*(const char ***)(v285 + v81 + 3368));
        if ( started )
        {
          v123 = *(_QWORD *)(v112 + 3096);
          v122 = started;
          v124 = "Port[%s] failed in DRV start rc:%d";
          v125 = 2321;
          goto LABEL_350;
        }
        if ( debug_drv )
        {
          v114 = *(const char ***)(v112 + 3368);
          v115 = v114[14];
          if ( !v115 )
            v115 = *v114;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            3,
            "cam_cpas_util_apply_client_axi_vote",
            2328,
            "Started rsc dev %s mnoc port:%s",
            v115,
            *(const char **)(v90 + 3096));
        }
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          v116 = *(const char ***)(v112 + 3368);
          v117 = v116[14];
          if ( !v117 )
            v117 = *v116;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_util_apply_client_axi_vote",
            2332,
            "Started rsc dev %s mnoc port:%s",
            v117,
            *(const char **)(v90 + 3096));
        }
        *(_BYTE *)(v99 + 3376) = 1;
      }
      else
      {
        if ( a4 != 2 || (*(_BYTE *)(v99 + 3376) & 1) == 0 || v304 || v305 || v307 || v308 )
        {
LABEL_201:
          v83 = v285;
          if ( (*(_BYTE *)(v99 + 3376) & 1) == 0 )
            goto LABEL_164;
          v106 = v285 + v81;
          v107 = cam_cpas_drv_channel_switch_for_dev(*(const char ***)(v285 + v81 + 3368));
          if ( v107 )
          {
            v123 = *(_QWORD *)(v106 + 3096);
            v122 = v107;
            v124 = "Port[%s] failed in channel switch rc:%d";
            v125 = 2363;
LABEL_350:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_util_apply_client_axi_vote",
              v125,
              v124,
              v123,
              v122);
            v10 = v285;
            goto LABEL_498;
          }
          if ( debug_drv )
          {
            v108 = *(const char ***)(v106 + 3368);
            v109 = v108[14];
            if ( !v109 )
              v109 = *v108;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              3,
              "cam_cpas_util_apply_client_axi_vote",
              2371,
              "Channel switch for rsc dev %s mnoc port:%s",
              v109,
              *(const char **)(v90 + 3096));
          }
          v83 = v285;
          if ( (debug_mdl & 4) == 0 || debug_priority )
            goto LABEL_164;
          v110 = *(const char ***)(v106 + 3368);
          v111 = v110[14];
          if ( !v111 )
            v111 = *v110;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_util_apply_client_axi_vote",
            2376,
            "Channel switch for rsc dev %s mnoc port:%s",
            v111,
            *(const char **)(v90 + 3096));
          goto LABEL_220;
        }
        v100 = v285 + v81;
        v101 = cam_cpas_stop_drv_for_dev(*(const char ***)(v285 + v81 + 3368));
        if ( v101 )
        {
          v123 = *(_QWORD *)(v100 + 3096);
          v122 = v101;
          v124 = "Port[%s] failed in DRV stop rc:%d";
          v125 = 2343;
          goto LABEL_350;
        }
        if ( debug_drv )
        {
          v102 = *(const char ***)(v100 + 3368);
          v103 = v102[14];
          if ( !v103 )
            v103 = *v102;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            3,
            "cam_cpas_util_apply_client_axi_vote",
            2350,
            "Stopped rsc dev %s mnoc port:%s",
            v103,
            *(const char **)(v90 + 3096));
        }
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          v118 = *(const char ***)(v100 + 3368);
          v119 = v118[14];
          if ( !v119 )
            v119 = *v118;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_util_apply_client_axi_vote",
            2354,
            "Stopped rsc dev %s mnoc port:%s",
            v119,
            *(const char **)(v90 + 3096));
        }
        *(_BYTE *)(v99 + 3376) = 0;
      }
LABEL_220:
      v83 = v285;
LABEL_164:
      v84 = v304;
      v85 = (_QWORD *)(v83 + v81);
      v86 = v303;
      v10 = v83;
      v85[433] = v305;
      v85[432] = v84;
      v85[431] = v86;
      v87 = v308;
      v88 = v306;
      v89 = v307;
      v85[437] = v309;
      v80 = *(unsigned int *)(v83 + 2780);
      v85[436] = v87;
      v85[435] = v89;
      v85[434] = v88;
LABEL_165:
      ++v4;
      v81 += 408;
      if ( v4 >= v80 )
        goto LABEL_353;
    }
  }
  if ( v198 == 5 )
    goto LABEL_351;
  v5 = a1;
  if ( HIBYTE(v321) == 1 && (v283[1224] & 1) != 0 )
    goto LABEL_341;
  v10 = v285;
  if ( v198 != 6 )
    goto LABEL_500;
LABEL_161:
  LOBYTE(v299) = 0;
  v80 = *(unsigned int *)(v10 + 2780);
  if ( (_DWORD)v80 )
    goto LABEL_162;
LABEL_353:
  if ( v286[1036] != 1 )
  {
    v214 = *(_QWORD *)(a1 + 3680);
    v215 = *(_DWORD *)(v214 + 2784);
    if ( v215 > 6 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_camnoc_set_bw_vote",
        1910,
        "Invalid num_camnoc_axi_ports: %d",
        v215);
      v122 = -22;
LABEL_369:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_apply_client_axi_vote",
        2421,
        "Failed in setting camnoc bw vote rc=%d",
        v122);
      v10 = v285;
      goto LABEL_498;
    }
    if ( !v215 )
      goto LABEL_490;
    v216 = 0;
    v217 = 0;
    v218 = 5896;
    v219 = 5552;
    v220 = 5832;
    while ( 1 )
    {
      if ( (unsigned int)v217 > 5 )
        goto LABEL_503;
      if ( *((_BYTE *)&v318 + v217) != 1 )
        goto LABEL_374;
      v221 = v214 + v216;
      if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000004,
          4,
          "cam_cpas_camnoc_set_bw_vote",
          1922,
          "Port[%s] : camnoc_bw=%lld",
          *(const char **)(v221 + 5544),
          *(_QWORD *)(v214 + v216 + 5856));
        v222 = *(_QWORD *)(v221 + 5856);
        if ( !v222 )
        {
LABEL_380:
          v222 = *(_QWORD *)(v214 + v216 + 5888);
          if ( !v222 )
            v222 = (unsigned __int64)(*(_DWORD *)(v214 + 2792) != 0) << 10;
        }
      }
      else
      {
        v222 = *(_QWORD *)(v221 + 5856);
        if ( !v222 )
          goto LABEL_380;
      }
      *(_QWORD *)(v214 + v216 + 5848) = v222;
      v223 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64, __int64, __int64))cam_cpas_util_vote_hlos_bus_client_bw)(
               *(_QWORD *)(a1 + 3392),
               v214,
               v214 + v219,
               1,
               v214 + v220,
               v214 + v218);
      v122 = v223;
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_camnoc_set_bw_vote",
          1939,
          "camnoc vote camnoc_bw[%llu] rc=%d %s",
          v222,
          v223,
          *(const char **)(v221 + 5544));
      if ( v122 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_camnoc_set_bw_vote",
          1943,
          "Failed in camnoc vote camnoc_bw[%llu] rc=%d",
          v222,
          v122);
        goto LABEL_369;
      }
      v215 = *(_DWORD *)(v214 + 2784);
LABEL_374:
      ++v217;
      v216 += 408;
      v218 += 408;
      v219 += 408;
      v220 += 408;
      if ( (unsigned int)v217 >= v215 )
        goto LABEL_490;
    }
  }
  v7 = (__int64)&unk_393000;
  v203 = *(_QWORD *)(a1 + 3392);
  v5 = *(_QWORD *)(a1 + 3680);
  if ( (debug_mdl & 4) == 0 || debug_priority )
  {
    if ( (_DWORD)v301 )
      goto LABEL_357;
LABEL_427:
    v248 = 0;
    v249 = 0;
    v250 = 0;
    v251 = 0;
    LODWORD(v322) = 0;
    v317 = 0;
    do
    {
      v252 = *(_QWORD *)(v203 + 360 + v248);
      if ( v252 && *(_BYTE *)(v252 + 57) == 1 )
      {
        v253 = *(_QWORD *)(v252 + 48);
        v254 = *(unsigned int *)(v252 + 44);
        v255 = *(unsigned __int8 *)(v252 + 56);
        v256 = *(_QWORD *)(v253 + 24) * v254;
        if ( v251 <= v256 )
          v251 = v256;
        if ( v250 <= v256 )
          v257 = v256;
        else
          v257 = v250;
        if ( v249 > v256 )
          v256 = v249;
        if ( v255 )
          v250 = v257;
        else
          v249 = v256;
      }
      v248 += 8;
    }
    while ( v248 != 504 );
    v258 = cam_common_util_mul_then_div(v251, *(unsigned int *)(v203 + 1044), 100) + v251;
    a3 = cam_common_util_mul_then_div(v250, *(unsigned int *)(v203 + 1044), 100) + v250;
    v259 = cam_common_util_mul_then_div(v249, *(unsigned int *)(v203 + 1044), 100);
    v260 = *(_DWORD *)(v5 + 2792);
    v261 = v259 + v249;
    if ( !v260 || v258 )
    {
      if ( v258 )
        goto LABEL_447;
      v10 = 0;
      if ( a3 )
      {
LABEL_451:
        if ( a3 <= *(_QWORD *)(v203 + 1048) )
          a3 = *(_QWORD *)(v203 + 1048);
      }
    }
    else
    {
      v258 = 1024;
      if ( (debug_mdl & 4) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_util_set_camnoc_axi_hlos_clk_rate",
          1536,
          "Set min vote if streamon_clients is non-zero : streamon_clients=%d",
          v260);
        v258 = 1024;
      }
LABEL_447:
      if ( v258 <= *(_QWORD *)(v203 + 1048) )
        v10 = *(_QWORD *)(v203 + 1048);
      else
        v10 = v258;
      if ( a3 )
        goto LABEL_451;
    }
    if ( v261 )
    {
      if ( v261 <= *(_QWORD *)(v203 + 1048) )
        v262 = *(_QWORD *)(v203 + 1048);
      else
        v262 = v261;
      settings = cam_debug_get_settings();
      if ( !settings )
        goto LABEL_465;
    }
    else
    {
      v262 = 0;
      settings = cam_debug_get_settings();
      if ( !settings )
        goto LABEL_465;
    }
    v264 = settings[10];
    if ( v264 )
    {
      v262 = *(unsigned int *)(v203 + 1040);
      if ( v264 <= v262 )
        v10 = *(unsigned int *)(v203 + 1040);
      else
        v10 = settings[10];
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, _QWORD))cam_print_log)(
        3,
        4,
        3,
        "cam_cpas_util_set_camnoc_axi_hlos_clk_rate",
        1564,
        "Overriding camnoc full tree bw: %llu, NRT/ICP tree bw: %llu",
        v10,
        *(unsigned int *)(v203 + 1040));
    }
LABEL_465:
    a2 = cam_common_util_mul_then_div(v10, 1u, *(unsigned int *)(v203 + 1040));
    v265 = cam_common_util_mul_then_div(a3, 1u, *(unsigned int *)(v203 + 1040));
    v6 = cam_common_util_mul_then_div(v262, 1u, *(unsigned int *)(v203 + 1040));
    if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000004,
        4,
        "cam_cpas_util_set_camnoc_axi_hlos_clk_rate",
        1581,
        "Setting camnoc axi HLOS clk rate[BW Clk RT_only_Clk] : [%llu %lld %lld]",
        v10,
        a2,
        v265);
      v4 = a1;
      if ( !v5 )
        goto LABEL_478;
LABEL_468:
      v266 = cam_debug_get_settings();
      if ( !debug_disable_rt_clk_bw_limit && (!v266 || !v266[10]) )
      {
        v267 = *(unsigned int *)(v4 + 2972);
        if ( (unsigned int)v267 >= 0xA )
          goto LABEL_500;
        v268 = *(unsigned int *)(v4 + 2892);
        if ( (unsigned int)v268 > 0x1F )
          goto LABEL_500;
        if ( *(_QWORD *)(v5 + 8176) + *(_QWORD *)(v5 + 8160) + *(_QWORD *)(v5 + 0x2000) + v265 > *(int *)(v4 + (v267 << 7) + 4 * v268 + 1480) )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
            3,
            4,
            2,
            "cam_cpas_util_validate_rt_camnoc_clk_rate",
            1292,
            "Requested clk rate[SW HW Total]: [%lld %lld %lld] exceeds max supported value: %d",
            v265);
      }
    }
    else
    {
      v4 = a1;
      if ( v5 )
        goto LABEL_468;
LABEL_478:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_validate_rt_camnoc_clk_rate",
        1265,
        "Invalid params for validating rt camnoc clock rate");
    }
    clk_level = cam_soc_util_get_clk_level((_BYTE *)(v4 + 96), a2, *(_DWORD *)(v4 + 2892), (int *)&v322);
    v270 = *(unsigned int *)(v4 + 2892);
    if ( clk_level )
    {
      v122 = clk_level;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned __int64))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_set_camnoc_axi_hlos_clk_rate",
        1590,
        "failed to get clk lvl: %d, src clk idx: %d, hlos clk rate %lld",
        clk_level,
        v270,
        a2);
    }
    else
    {
      v271 = cam_soc_util_get_clk_level((_BYTE *)(v4 + 96), v6, v270, &v317);
      if ( v271 )
      {
        v122 = v271;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_util_set_camnoc_axi_hlos_clk_rate",
          1598,
          "failed to get clk lvl: %d, src clk idx: %d, hlos clk rate %lld",
          v271,
          *(unsigned int *)(v4 + 2892),
          v6);
      }
      else
      {
        v272 = v322;
        v273 = *(_DWORD *)(v5 + 2792);
        *(_QWORD *)(v5 + 159448) = v265;
        *(_DWORD *)(v5 + 159440) = v272;
        *(_DWORD *)(v5 + 159456) = v317;
        if ( !v273 )
          goto LABEL_490;
        v274 = cam_cpas_util_set_max_camnoc_axi_clk_rate(v5, v4 + 96);
        if ( !v274 )
        {
          *(_QWORD *)(v5 + 8208) = v265;
          goto LABEL_490;
        }
        v122 = v274;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_util_set_camnoc_axi_hlos_clk_rate",
          1633,
          "Failed in setting camnoc axi clk [BW Clk]:[%llu %lld] rc:%d",
          v10,
          a2,
          v274);
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_set_camnoc_axi_clk_rate",
      1660,
      "Failed in setting hlos clk rate rc: %d",
      v122);
    v10 = v285;
    goto LABEL_484;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 4,
    4,
    "cam_cpas_util_set_camnoc_axi_clk_rate",
    1653,
    "control_camnoc_axi_clk=%d",
    *(unsigned __int8 *)(v203 + 1036));
  if ( !(_DWORD)v301 )
    goto LABEL_427;
LABEL_357:
  v204 = *(unsigned __int8 *)(v203 + 1610);
  v326 = 0;
  v327 = 0;
  v324 = 0;
  v325 = 0;
  v323[0] = 0;
  v323[1] = 0;
  v322 = 0;
  if ( v204 != 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_set_camnoc_axi_drv_clk_rate",
      1307,
      "Clk DRV not enabled, can't set clk rates through cesta APIs");
    v122 = -22;
    goto LABEL_417;
  }
  v205 = 0;
  v206 = 0;
  v207 = 0;
  do
  {
    v208 = *(_QWORD *)(v203 + 360 + v205);
    if ( v208 && *(_BYTE *)(v208 + 57) == 1 )
    {
      v209 = *(_QWORD *)(v208 + 48);
      v210 = *(unsigned int *)(v208 + 44);
      v211 = v209 + 56LL * (unsigned int)v301;
      v212 = *(_QWORD *)(v211 + 24) * v210;
      v213 = *(_QWORD *)(v211 + 48) * v210;
      if ( v206 <= v212 )
        v206 = v212;
      if ( v207 <= v213 )
        v207 = v213;
    }
    v205 += 8;
  }
  while ( v205 != 504 );
  if ( !*(_DWORD *)(v5 + 2792) )
    goto LABEL_490;
  v224 = *(unsigned int *)(v203 + 1044);
  v225 = v206 + v206 * v224 / 0x64;
  v226 = *(unsigned int *)(v203 + 1040);
  v227 = v207 + v207 * v224 / 0x64;
  if ( (_DWORD)v301 == 1 )
  {
    LOBYTE(v4) = 0;
    LODWORD(v10) = 0;
    LOBYTE(a3) = 1;
  }
  else
  {
    LOBYTE(a3) = 0;
    if ( (_DWORD)v301 == 3 )
    {
      LOBYTE(v4) = 0;
      LODWORD(v10) = 2;
    }
    else
    {
      LOBYTE(v4) = 1;
      LODWORD(v10) = 1;
    }
  }
  v6 = (v225 + v227) / v226;
  a2 = v227 / v226;
  if ( !debug_drv )
  {
    v12 = debug_mdl & 0x2000004;
    if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
      goto LABEL_501;
    goto LABEL_400;
  }
  v12 = 0x2000000;
  v228 = 3;
  v229 = 1372;
  while ( 2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v12,
      v228,
      "cam_cpas_util_set_camnoc_axi_drv_clk_rate",
      v229,
      "Setting camnoc axi cesta clk rate[BW Clk] : High [%llu %lld] Low [%llu %lld] cesta/hw_client_idx:[%d][%d]");
LABEL_400:
    v323[2 * (unsigned int)v10] = v6;
    if ( !v5 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_util_validate_rt_camnoc_clk_rate",
        1265,
        "Invalid params for validating rt camnoc clock rate");
      goto LABEL_407;
    }
    v230 = v323[0];
    v231 = v324;
    v232 = v326;
    v233 = cam_debug_get_settings();
    if ( debug_disable_rt_clk_bw_limit || v233 && v233[10] )
      goto LABEL_407;
    if ( (a3 & 1) != 0 )
    {
      v234 = *(_QWORD *)(v5 + 8176) + v230;
      goto LABEL_420;
    }
    v241 = *(_QWORD *)(v5 + 8160);
    if ( (v4 & 1) != 0 )
    {
      v234 = v241 + v231;
LABEL_420:
      v232 = *(_QWORD *)(v5 + 0x2000);
    }
    else
    {
      v234 = *(_QWORD *)(v5 + 8176) + v241;
    }
    v242 = *(unsigned int *)(a1 + 2972);
    if ( (unsigned int)v242 >= 0xA || (v243 = *(unsigned int *)(a1 + 2892), (unsigned int)v243 > 0x1F) )
    {
LABEL_500:
      __break(0x5512u);
LABEL_501:
      v228 = 4;
      v229 = 1377;
      continue;
    }
    break;
  }
  v244 = *(_QWORD *)(v5 + 8208);
  v245 = v232 + v234;
  v246 = v232 + v234 + v244;
  v247 = *(int *)(a1 + (v242 << 7) + 4 * v243 + 1480);
  if ( v246 > v247 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      2,
      "cam_cpas_util_validate_rt_camnoc_clk_rate",
      1292,
      "Requested clk rate[SW HW Total]: [%lld %lld %lld] exceeds max supported value: %d",
      v244,
      v245,
      v246,
      v247);
LABEL_407:
  v235 = cam_soc_util_set_src_clk_rate(a1 + 96, v10, v6, a2);
  if ( v235 )
  {
    v122 = v235;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_set_camnoc_axi_drv_clk_rate",
      1389,
      "Failed in setting camnoc cesta clk rates[high low]:[%ld %ld] client_idx:%d rc:%d",
      v6,
      a2,
      v10,
      v235);
    goto LABEL_416;
  }
  v236 = v5 + 16LL * (unsigned int)v10;
  *(_QWORD *)(v236 + 8160) = v6;
  *(_QWORD *)(v236 + 8168) = a2;
  if ( debug_drv )
  {
    v237 = 0x2000000;
    v238 = 3;
    v239 = 1400;
    goto LABEL_411;
  }
  v237 = *(_QWORD *)(v7 + 3664) & 0x2000004LL;
  if ( v237 && !debug_priority )
  {
    v238 = 4;
    v239 = 1403;
LABEL_411:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      v237,
      v238,
      "cam_cpas_util_set_camnoc_axi_drv_clk_rate",
      v239,
      "Triggering channel switch for cesta client %d",
      (unsigned int)v10);
  }
  v240 = cam_soc_util_cesta_channel_switch(v10, "cpas_update");
  if ( v240 )
  {
    v122 = v240;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_set_camnoc_axi_drv_clk_rate",
      1408,
      "Failed to apply power states for cesta client:%d rc:%d",
      v10,
      v240);
LABEL_416:
    v10 = v285;
LABEL_417:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_set_camnoc_axi_clk_rate",
      1669,
      "Failed in setting drv clk rate drv_idx:%d rc: %d",
      (_DWORD)v301,
      v122);
LABEL_484:
    v201 = "Failed in setting axi clk rate rc=%d";
    v202 = 2415;
LABEL_485:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_apply_client_axi_vote",
      v202,
      v201,
      v122);
    goto LABEL_498;
  }
LABEL_490:
  if ( (unsigned __int8)((unsigned __int8)v299 & v286[1608]) != 1 )
    goto LABEL_496;
  v10 = v285;
  v275 = debug_mdl & 0x2000004;
  if ( (debug_mdl & 0x2000004) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v275,
      4,
      "cam_cpas_util_apply_client_axi_vote",
      2427,
      "Apply Smart QoS after bw votes");
  v122 = cam_cpas_apply_smart_qos(a1, v275);
  if ( v122 )
  {
    v201 = "Failed in Smart QoS rc=%d";
    v202 = 2431;
    goto LABEL_485;
  }
LABEL_498:
  mutex_unlock(v10 + 2728);
  _ReadStatusReg(SP_EL0);
  return v122;
}
