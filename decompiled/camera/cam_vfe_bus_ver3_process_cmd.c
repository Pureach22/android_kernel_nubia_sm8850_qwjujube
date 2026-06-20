__int64 __fastcall cam_vfe_bus_ver3_process_cmd(
        __int64 a1,
        unsigned int a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x9
  __int64 v9; // x10
  unsigned __int64 v10; // x19
  unsigned __int64 v11; // x20
  __int64 v12; // x28
  __int64 v13; // x27
  __int64 v14; // x9
  __int64 v15; // x22
  __int64 v16; // x10
  __int64 v17; // x7
  unsigned __int64 v18; // x21
  unsigned int v19; // w8
  unsigned int v20; // w9
  unsigned int v21; // w6
  int v22; // w0
  const char *v23; // x5
  __int64 v24; // x0
  const char *v25; // x3
  __int64 v26; // x4
  unsigned int out_res_mid_info; // w23
  int v29; // w6
  __int64 v30; // x22
  unsigned int *v31; // x24
  unsigned __int64 v32; // x25
  __int64 v33; // x14
  unsigned __int64 v35; // x8
  __int64 v36; // x21
  _DWORD *v37; // x8
  unsigned int v38; // w10
  unsigned int v39; // w9
  __int64 v40; // x23
  unsigned __int64 v46; // x11
  int v47; // w26
  unsigned int v48; // w8
  int v49; // w0
  unsigned int v50; // w8
  char v51; // w8
  const char *v52; // x17
  const char *v53; // x13
  int v54; // w8
  const char *v55; // x7
  __int64 v56; // x8
  unsigned int v57; // w17
  int v58; // w8
  __int64 v59; // x8
  char v60; // w22
  __int64 v61; // x24
  unsigned int v62; // w22
  __int64 v63; // x26
  unsigned __int64 v64; // x25
  unsigned int v65; // w23
  __int64 *v66; // x28
  unsigned int v67; // w22
  __int64 v68; // x27
  __int64 v69; // x24
  __int64 v70; // x24
  char v71; // w8
  unsigned __int64 v72; // x23
  unsigned __int64 v73; // x22
  __int64 v74; // x8
  unsigned int *v75; // x23
  __int64 v76; // x27
  __int64 v77; // x8
  char v78; // w9
  __int64 v79; // x0
  int v80; // w6
  unsigned int v81; // w8
  __int64 v82; // x9
  __int64 v83; // x22
  int v84; // w20
  __int64 i; // x25
  int v86; // w3
  int v87; // w0
  unsigned int v88; // w21
  unsigned int out_res_id_and_index; // w0
  int v90; // w22
  __int64 v91; // x21
  int v92; // w8
  __int64 v93; // x21
  __int64 v94; // x22
  __int64 v95; // x9
  __int64 v96; // x8
  __int64 v97; // x11
  __int64 v98; // x9
  __int64 v99; // x10
  int v100; // w8
  __int64 v101; // x8
  unsigned int v102; // w8
  _DWORD *v103; // x10
  unsigned int v104; // w22
  _DWORD *v105; // x10
  _DWORD *v106; // x9
  int v107; // w8
  int v108; // w11
  int v109; // w10
  __int64 v110; // x28
  __int64 v111; // x11
  unsigned int *v112; // x24
  __int64 v113; // x22
  unsigned int v114; // w7
  __int64 v115; // x27
  _DWORD *v116; // x9
  unsigned int v117; // w9
  unsigned int v118; // w9
  unsigned int v119; // w9
  __int64 v120; // x8
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x26
  _DWORD *v124; // x27
  unsigned __int64 v125; // x28
  __int64 v126; // x21
  unsigned int v127; // w22
  __int64 v128; // x23
  _DWORD *v129; // x8
  unsigned int v130; // w8
  unsigned int v131; // w24
  unsigned int v132; // w25
  int packer_fmt; // w0
  char v134; // w8
  const char *v135; // x15
  const char *v136; // x13
  __int64 v137; // x24
  __int64 v138; // x28
  char v139; // w26
  __int64 v140; // x23
  int *v141; // x21
  _QWORD *v142; // x14
  __int64 v143; // x9
  __int64 v144; // x27
  int v145; // w8
  unsigned int v146; // w7
  _QWORD *v147; // x22
  bool v148; // w22
  int v149; // w9
  int v150; // w8
  int v151; // w7
  _QWORD *v152; // x27
  unsigned int v153; // w21
  unsigned int v154; // w0
  unsigned int v155; // w22
  __int64 v156; // x8
  int v157; // w0
  unsigned int v158; // w0
  __int64 v160; // x0
  const char *v161; // x5
  __int64 v162; // x6
  __int64 v163; // x2
  const char *v164; // x3
  __int64 v165; // x4
  __int64 v166; // x2
  unsigned int v167; // w0
  __int64 v168; // x7
  __int64 v169; // x6
  const char *v170; // x5
  __int64 v171; // x4
  __int64 v172; // x21
  unsigned __int64 v173; // x22
  int *v174; // x25
  unsigned __int64 v175; // x1
  unsigned __int8 *v176; // x8
  __int64 v177; // x8
  int v178; // w8
  __int64 v179; // x8
  int v180; // w0
  __int64 v181; // x22
  __int64 v182; // x21
  __int64 v183; // x20
  __int64 v184; // x6
  __int64 v185; // x7
  const char *v186; // x3
  const char *v187; // x5
  __int64 v188; // x1
  __int64 v189; // x2
  __int64 v190; // x4
  __int64 v191; // x21
  __int64 v192; // x22
  unsigned __int64 v193; // x9
  const char *v194; // x24
  __int64 v195; // x22
  unsigned __int64 v196; // x23
  unsigned int v197; // w25
  __int64 v198; // x10
  __int64 v199; // x26
  unsigned int v200; // w28
  _DWORD *v201; // x9
  __int64 v202; // x27
  _DWORD *v203; // x8
  unsigned int v204; // w28
  _DWORD *v205; // x9
  _DWORD *v206; // x8
  __int64 v207; // x9
  int v208; // w6
  int v209; // w7
  __int64 v210; // x21
  __int64 (__fastcall *v211)(_QWORD); // x8
  unsigned int v212; // w20
  const char *v213; // x3
  const char *v214; // x5
  __int64 v215; // x4
  void (__fastcall *v216)(__int64, __int64, unsigned __int64 *); // x8
  __int64 v217; // x0
  __int64 v218; // x26
  unsigned __int64 v219; // x27
  __int64 v220; // x8
  __int64 v221; // x22
  __int64 v222; // x9
  __int64 v223; // x2
  unsigned int v224; // w0
  __int64 v225; // x2
  __int64 v226; // x15
  __int64 v227; // x14
  const char **v228; // x22
  unsigned int v229; // w16
  unsigned __int64 v230; // x17
  int v231; // w1
  unsigned int v232; // w0
  int v233; // w6
  unsigned int v234; // w2
  _BOOL4 v235; // w17
  int v236; // w0
  unsigned int v237; // w0
  unsigned int v238; // w2
  unsigned int v239; // w0
  unsigned int v240; // w2
  unsigned int v241; // w0
  unsigned int v242; // w2
  unsigned int v243; // w0
  unsigned int v244; // w2
  unsigned int v245; // w0
  unsigned int v246; // w2
  unsigned int v247; // w21
  int v248; // w8
  unsigned __int64 v249; // x14
  _DWORD *v250; // x22
  unsigned __int64 v251; // x6
  __int64 v252; // x23
  __int64 v253; // x25
  int v254; // w8
  int v255; // w9
  __int64 v256; // x9
  __int64 v257; // x24
  __int64 v258; // x7
  __int64 v259; // x8
  int v260; // w9
  __int64 v261; // x8
  __int64 v262; // x7
  __int64 v263; // x8
  int v264; // w9
  __int64 v265; // x8
  int v266; // w9
  char v267; // w8
  __int64 v268; // x7
  __int64 v269; // x8
  int v270; // w9
  int v271; // w11
  int v272; // w10
  __int64 v273; // x8
  char v274; // w8
  __int64 v275; // x9
  int *v276; // x8
  int *v277; // x10
  int v278; // w26
  int v279; // w24
  unsigned int v280; // w27
  unsigned int v281; // w8
  __int64 v282; // x9
  __int64 v283; // x7
  __int64 v284; // x9
  int v285; // w10
  __int64 v286; // x9
  char v287; // w8
  __int64 v288; // x7
  __int64 v289; // x8
  int v290; // w9
  int v291; // w10
  __int64 v292; // x8
  char v293; // w8
  __int64 v294; // x8
  __int64 v295; // x8
  _BYTE *v296; // x8
  int v297; // t1
  _BYTE *v298; // x1
  __int64 v299; // x26
  _DWORD *v300; // x25
  __int64 v301; // x22
  unsigned __int64 v302; // x28
  int v303; // w27
  __int64 v304; // x6
  __int64 v305; // x7
  int v306; // w9
  int v307; // w8
  __int64 v308; // x8
  unsigned int v309; // w24
  int v310; // w7
  __int64 v311; // x7
  __int64 v312; // x8
  int v313; // w9
  __int64 v314; // x8
  int v315; // w10
  char v316; // w8
  unsigned int *v317; // x8
  __int64 v318; // x27
  __int64 v319; // x26
  _DWORD *v320; // x25
  __int64 v321; // x22
  unsigned __int64 v322; // x28
  __int64 v323; // x7
  __int64 v324; // x8
  int v325; // w9
  __int64 v326; // x8
  __int64 v327; // x7
  __int64 v328; // x14
  __int64 v329; // x8
  int v330; // w9
  __int64 v331; // x8
  _DWORD *v332; // x22
  __int64 v333; // x7
  __int64 v334; // x8
  int v335; // w9
  __int64 v336; // x8
  __int64 v337; // x7
  __int64 v338; // x8
  int v339; // w9
  __int64 v340; // x8
  __int64 v341; // x7
  __int64 v342; // x8
  int v343; // w9
  __int64 v344; // x8
  int v345; // w10
  char v346; // w8
  __int64 v347; // x7
  int v348; // w9
  int v349; // w8
  __int64 v350; // x8
  char v351; // w8
  __int64 v352; // x8
  unsigned int v353; // t1
  __int64 (__fastcall *v354)(_QWORD); // x8
  unsigned int v355; // w22
  __int64 (__fastcall *v356)(_QWORD); // x8
  __int64 v357; // x23
  unsigned int v358; // w24
  _DWORD *v359; // x8
  __int64 v360; // x0
  __int64 v361; // x10
  int v362; // w11
  int v363; // w10
  __int64 (__fastcall *v364)(_QWORD); // x8
  _DWORD *v365; // x8
  __int64 v366; // x0
  __int64 v367; // x11
  __int64 v368; // x21
  const char *v369; // x11
  int v370; // w6
  int v371; // w20
  __int64 v372; // [xsp+0h] [xbp-1A0h]
  char v373; // [xsp+0h] [xbp-1A0h]
  int v374; // [xsp+8h] [xbp-198h]
  __int64 v375; // [xsp+50h] [xbp-150h]
  int v376; // [xsp+5Ch] [xbp-144h]
  __int64 v377; // [xsp+60h] [xbp-140h]
  __int64 v378; // [xsp+68h] [xbp-138h]
  __int64 v379; // [xsp+70h] [xbp-130h]
  unsigned __int64 v380; // [xsp+78h] [xbp-128h]
  __int64 v381; // [xsp+78h] [xbp-128h]
  __int64 v382; // [xsp+78h] [xbp-128h]
  __int64 v383; // [xsp+78h] [xbp-128h]
  __int64 v384; // [xsp+78h] [xbp-128h]
  __int64 v385; // [xsp+78h] [xbp-128h]
  signed int v386; // [xsp+78h] [xbp-128h]
  unsigned int *v387; // [xsp+80h] [xbp-120h]
  unsigned int v388; // [xsp+80h] [xbp-120h]
  unsigned int v389; // [xsp+80h] [xbp-120h]
  unsigned int v390; // [xsp+80h] [xbp-120h]
  unsigned int v391; // [xsp+80h] [xbp-120h]
  unsigned __int64 v392; // [xsp+80h] [xbp-120h]
  __int64 v393; // [xsp+80h] [xbp-120h]
  __int64 v394; // [xsp+80h] [xbp-120h]
  unsigned __int64 v395; // [xsp+88h] [xbp-118h] BYREF
  unsigned __int64 v396[34]; // [xsp+90h] [xbp-110h] BYREF

  v396[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v10 = a3) == 0 )
  {
    v22 = __ratelimit(&cam_vfe_bus_ver3_process_cmd__rs, "cam_vfe_bus_ver3_process_cmd");
    v23 = "Invalid input arguments";
    if ( v22 )
      v24 = 3;
    else
      v24 = 2;
    v25 = "cam_vfe_bus_ver3_process_cmd";
    v26 = 5540;
    goto LABEL_16;
  }
  v11 = a1;
  v12 = a1 + 0x8000;
  switch ( a2 )
  {
    case 1u:
      v13 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v13 || (v14 = *(_QWORD *)(v13 + 16), (v15 = *(_QWORD *)(v14 + 88)) == 0) )
      {
        v25 = "cam_vfe_bus_ver3_update_wm";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 3986;
        goto LABEL_16;
      }
      v16 = *(_QWORD *)(a3 + 40);
      v17 = *(unsigned int *)(v16 + 20);
      if ( (_DWORD)v17 != *(_DWORD *)(v13 + 32) )
      {
        if ( (*(_BYTE *)(a3 + 32) & 1) == 0 )
        {
          v162 = *(unsigned int *)(a1 + 8);
          v164 = "cam_vfe_bus_ver3_update_wm";
          v161 = "VFE:%u Failed! Invalid number buffers:%d required:%d";
          v160 = 3;
          v163 = 1;
          v165 = 3996;
          LODWORD(v372) = *(_DWORD *)(v13 + 32);
          goto LABEL_326;
        }
        v18 = v14 + 96;
LABEL_389:
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4003,
            "VFE:%u Using scratch for IFE out_type: %u",
            *(_DWORD *)(a1 + 8),
            *(_DWORD *)(v13 + 8));
          if ( (*(_BYTE *)(v13 + 132) & 1) != 0 )
            goto LABEL_393;
        }
        else if ( (*(_BYTE *)(v13 + 132) & 1) != 0 )
        {
LABEL_393:
          v9 = 0;
          v21 = -1;
          goto LABEL_394;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_update_wm",
          4008,
          "Configuring scratch for VFE:%u out_type: %u, with no BW limiter enabled",
          *(_DWORD *)(v11 + 8),
          *(_DWORD *)(v13 + 8));
        goto LABEL_393;
      }
      v18 = v14 + 96;
      if ( (*(_BYTE *)(a3 + 32) & 1) != 0 )
        goto LABEL_389;
      v9 = *(_QWORD *)(v16 + 56);
      if ( !v9 )
      {
        v25 = "cam_vfe_bus_ver3_update_wm";
        v23 = "Invalid io cfg for wm update";
        v24 = 3;
        v26 = 4012;
LABEL_16:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          v24,
          8,
          1,
          v25,
          v26,
          v23);
        goto LABEL_17;
      }
      v19 = *(_DWORD *)(v9 + 248);
      v20 = __clz(__rbit32(v19));
      if ( v19 )
        v21 = v20;
      else
        v21 = -1;
LABEL_394:
      if ( (*(_BYTE *)(v13 + 133) & 1) == 0 )
      {
        if ( *(_BYTE *)(v13 + 134) != 1 || v21 <= 2 )
          goto LABEL_441;
LABEL_440:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_update_wm",
          4022,
          "Invalid hw context id : %d for wm update",
          v21);
        goto LABEL_17;
      }
      if ( v21 >= 3 )
        goto LABEL_440;
LABEL_441:
      v248 = *(_DWORD *)(v13 + 32);
      LODWORD(v396[0]) = 0;
      if ( !v248 )
      {
        LODWORD(v251) = 0;
LABEL_632:
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4284,
            "No reg val pairs. num_wms: %u VFE:%u",
            v251,
            *(_DWORD *)(v11 + 8));
        out_res_mid_info = 0;
        *(_DWORD *)(v10 + 28) = 0;
        goto LABEL_18;
      }
      LODWORD(v35) = v21;
      v375 = v15;
      v249 = 0;
      v8 = v13 + 40;
      v250 = (_DWORD *)(v9 + 44);
      v379 = v13 + 40;
      v386 = v21;
      v377 = v9;
      v378 = v13;
      do
      {
        if ( LODWORD(v396[0]) >= 0x118 )
        {
          v213 = "cam_vfe_bus_ver3_update_wm";
          v214 = "VFE:%u reg_val_pair %d exceeds the array limit %zu";
          v215 = 4030;
          goto LABEL_630;
        }
        if ( v249 == 2 )
          goto LABEL_666;
        v252 = *(_QWORD *)(*(_QWORD *)(v379 + 8 * v249) + 24LL);
        if ( (*(_BYTE *)(v13 + 133) & 1) == 0 && *(_BYTE *)(*(_QWORD *)(v252 + 56) + 134LL) != 1
          || (v253 = *(_QWORD *)(v252 + 64) + 80LL * v386, (*(_BYTE *)(v253 + 32) & 1) == 0) )
        {
          v253 = v252 + 16;
        }
        v254 = *(_DWORD *)(v253 + 28);
        v255 = 1 << *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v252 + 80LL) + 116LL);
        if ( (v255 & v254) != 0 )
        {
          v254 &= ~v255;
          *(_DWORD *)(v253 + 28) = v254;
        }
        v256 = *(_QWORD *)(v10 + 40);
        v394 = v249;
        if ( *(_QWORD *)(v256 + 24) && (*(_BYTE *)(v256 + 32) & 1) == 0 && *(_DWORD *)(*(_QWORD *)(v252 + 8) + 28LL) )
        {
          *(_DWORD *)(v253 + 28) = (1 << *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v252 + 80LL) + 116LL)) | v254;
          *(_BYTE *)(*(_QWORD *)(v10 + 40) + 32LL) = 1;
          if ( (cam_smmu_is_expanded_memory() & 1) != 0 )
          {
            v257 = *(_QWORD *)(*(_QWORD *)(v10 + 40) + 24LL) >> 8;
            if ( (unsigned __int8)*(_QWORD *)(*(_QWORD *)(v10 + 40) + 24LL) )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_bus_ver3_update_wm",
                4064,
                "VFE:%u Error, address not aligned! offset:0x%x",
                *(_DWORD *)(v11 + 8),
                (unsigned __int8)*(_QWORD *)(*(_QWORD *)(v10 + 40) + 24LL));
          }
          else
          {
            v257 = *(_QWORD *)(*(_QWORD *)(v10 + 40) + 24LL);
          }
          v258 = LODWORD(v396[0]);
          v249 = v394;
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4068,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
            v249 = v394;
          }
          else
          {
            v259 = *(_QWORD *)(v252 + 8);
            v260 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v258) = *(_DWORD *)(v259 + 28) + v260;
            v261 = LODWORD(v396[0]);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v261) = v257;
          }
          v262 = LODWORD(v396[0]);
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4072,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
            v249 = v394;
            v267 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_465;
          }
          else
          {
            v263 = *(_QWORD *)(v252 + 8);
            v264 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v262) = *(_DWORD *)(v263 + 36) + v264;
            v265 = LODWORD(v396[0]);
            v266 = *(_DWORD *)(*(_QWORD *)(v10 + 40) + 36LL);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v265) = v266;
            v267 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_465;
          }
          if ( !debug_priority )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v267 & 8,
              4,
              "cam_vfe_bus_ver3_update_wm",
              4077,
              "VFE:%u WM: %d en_cfg 0x%x frame_header %pK local_id %u",
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v252 + 120),
              *(_DWORD *)(v253 + 28),
              *(const void **)(*(_QWORD *)(v10 + 40) + 24LL),
              *(_DWORD *)(*(_QWORD *)(v10 + 40) + 36LL));
            v249 = v394;
          }
        }
LABEL_465:
        v268 = LODWORD(v396[0]);
        if ( LODWORD(v396[0]) >= 0x1A3 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_update_wm",
            4083,
            "Exceed buf size %u when adding reg/val at index %u and %u",
            420);
          v249 = v394;
          v274 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_469;
        }
        else
        {
          v269 = *(_QWORD *)(v252 + 8);
          v270 = *(_DWORD *)(v252 + 156);
          v271 = *(_DWORD *)v253;
          ++LODWORD(v396[0]);
          v272 = v271 | (*(_DWORD *)(v253 + 4) << 16);
          *(_DWORD *)(v18 + 4 * v268) = *(_DWORD *)(v269 + 12) + v270;
          v273 = LODWORD(v396[0]);
          ++LODWORD(v396[0]);
          *(_DWORD *)(v18 + 4 * v273) = v272;
          v274 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_469;
        }
        if ( !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v274 & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4085,
            "VFE:%u WM:%d image height and width 0x%X",
            *(_DWORD *)(v11 + 8),
            *(_DWORD *)(v252 + 120),
            *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)));
          v249 = v394;
        }
LABEL_469:
        if ( *(_BYTE *)(v10 + 32) == 1 )
        {
          v275 = *(_QWORD *)(v10 + 40);
          v276 = (int *)(v275 + 48);
          v277 = (int *)(v275 + 52);
        }
        else
        {
          v276 = v250 - 3;
          v277 = v250 - 2;
        }
        v278 = *v277;
        v279 = *v276;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4098,
            "VFE:%u io config stride val %u wm config stride: %u",
            *(_DWORD *)(v11 + 8),
            v279,
            *(_DWORD *)(v253 + 16));
          v249 = v394;
        }
        v280 = (v279 + 15) & 0xFFFFFFF0;
        if ( v280 != v279 && (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4102,
            "VFE:%u Warning unaligned stride %u expected %u",
            *(_DWORD *)(v11 + 8),
            v279,
            v280);
          v249 = v394;
        }
        v281 = *(_DWORD *)(v253 + 16);
        if ( v281 != v280
          || *(_BYTE *)(v252 + 160) != 1
          || ((v282 = *(_QWORD *)(v252 + 56), (*(_BYTE *)(v282 + 133) & 1) != 0) || *(_BYTE *)(v282 + 134) == 1)
          && (*(_BYTE *)(*(_QWORD *)(v252 + 64) + 80LL * v386 + 76) & 1) == 0 )
        {
          if ( !v281 )
          {
            v281 = (v279 + 15) & 0xFFFFFFF0;
            *(_DWORD *)(v253 + 16) = v280;
          }
          v283 = LODWORD(v396[0]);
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4111,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
            v249 = v394;
            v287 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_490;
          }
          else
          {
            v284 = *(_QWORD *)(v252 + 8);
            v285 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v283) = *(_DWORD *)(v284 + 20) + v285;
            v286 = LODWORD(v396[0]);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v286) = v281;
            v287 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_490;
          }
          if ( !debug_priority )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v287 & 8,
              4,
              "cam_vfe_bus_ver3_update_wm",
              4114,
              "VFE:%u WM:%d image stride 0x%X",
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v252 + 120),
              *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)));
            v249 = v394;
          }
        }
LABEL_490:
        if ( *(_BYTE *)(v252 + 163) == 1 )
        {
          if ( (*(_BYTE *)(v10 + 32) & 1) == 0 && *(_DWORD *)(v377 + 168) != *(_DWORD *)(v253 + 12) )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              8,
              2,
              "cam_vfe_bus_ver3_update_wm",
              4130,
              "VFE:%u format mismatch, wm_data format:%u io_cfg format:%u",
              *(unsigned int *)(v11 + 8));
            v249 = v394;
          }
          v288 = LODWORD(v396[0]);
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4134,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
            v249 = v394;
            v293 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_498;
          }
          else
          {
            v289 = *(_QWORD *)(v252 + 8);
            v290 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            v291 = *(_DWORD *)(v253 + 8);
            *(_DWORD *)(v18 + 4 * v288) = *(_DWORD *)(v289 + 24) + v290;
            v292 = LODWORD(v396[0]);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v292) = v291;
            v293 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_498;
          }
          if ( !debug_priority )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v293 & 8,
              4,
              "cam_vfe_bus_ver3_update_wm",
              4138,
              "VFE:%u WM:%d image pack_fmt %d",
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v252 + 120),
              *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)));
            v249 = v394;
          }
        }
LABEL_498:
        if ( !*(_QWORD *)(*(_QWORD *)(v252 + 8) + 88LL)
          || ((*(_QWORD *)(*(_QWORD *)(v12 + 2216) + 8928LL) >> *(_DWORD *)(v252 + 120)) & 1) == 0 )
        {
          goto LABEL_520;
        }
        v294 = *(_QWORD *)(v252 + 56);
        if ( (*(_BYTE *)(v294 + 133) & 1) != 0 || *(_BYTE *)(v294 + 134) == 1 )
        {
          v295 = *(_QWORD *)(v252 + 64) + 80LL * v386;
          v297 = *(unsigned __int8 *)(v295 + 36);
          v296 = (_BYTE *)(v295 + 36);
          if ( v297 == 1 )
          {
            *v296 = 0;
            v298 = (_BYTE *)(*(_QWORD *)(v252 + 64) + 80LL * v386 + 36);
LABEL_506:
            cam_vfe_bus_ver3_update_ubwc_regs(v252, v298, v18, v396);
            v249 = v394;
            goto LABEL_507;
          }
        }
        v298 = (_BYTE *)(v252 + 72);
        if ( *(_BYTE *)(v252 + 72) == 1 )
        {
          *v298 = 0;
          goto LABEL_506;
        }
LABEL_507:
        v376 = v278;
        v299 = v253;
        v300 = v250;
        v301 = v12;
        v302 = *(_QWORD *)(**(_QWORD **)(v10 + 40) + 8 * v249);
        if ( (cam_smmu_is_expanded_memory() & 1) != 0 )
          v303 = v302 >> 8;
        else
          v303 = v302;
        if ( (cam_smmu_is_expanded_memory() & 1) != 0 )
        {
          v304 = (unsigned __int8)v302;
          if ( (_BYTE)v302 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_ubwc_meta_addr",
              3711,
              "Error, address not aligned! offset:0x%x",
              (unsigned __int8)v302);
        }
        if ( v18 )
        {
          v305 = LODWORD(v396[0]);
          v12 = v301;
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_ubwc_meta_addr",
              3722,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
          }
          else
          {
            v306 = *(_DWORD *)(v252 + 156);
            v307 = **(_DWORD **)(*(_QWORD *)(v252 + 8) + 88LL);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v305) = v307 + v306;
            v308 = LODWORD(v396[0]);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v308) = v303;
          }
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_update_ubwc_meta_addr",
            3715,
            "Invalid args",
            v304);
          v12 = v301;
        }
        v250 = v300;
        v249 = v394;
        v253 = v299;
        v278 = v376;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4165,
            "VFE:%u WM:%d ubwc meta addr 0x%llx",
            *(_DWORD *)(v11 + 8),
            *(_DWORD *)(v252 + 120),
            *(_QWORD *)(**(_QWORD **)(v10 + 40) + 8 * v394));
          v249 = v394;
        }
LABEL_520:
        v309 = v279 * v278;
        if ( *(_QWORD *)(*(_QWORD *)(v252 + 8) + 88LL)
          && (v310 = *(_DWORD *)(v252 + 120), ((*(_QWORD *)(*(_QWORD *)(v12 + 2216) + 8928LL) >> v310) & 1) != 0)
          && (v309 = (v309 + 4095) & 0xFFFFF000, (*(_BYTE *)(v10 + 32) & 1) == 0)
          && (v309 += *v250, (debug_mdl & 8) != 0)
          && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4180,
            "VFE:%u WM:%d frm %d: ht: %d stride %d meta: %d",
            *(_DWORD *)(v11 + 8),
            v310,
            v309,
            *(v250 - 2),
            *(v250 - 3),
            *v250);
          v249 = v394;
          if ( *(_DWORD *)(v252 + 112) )
            goto LABEL_530;
        }
        else if ( *(_DWORD *)(v252 + 112) )
        {
          goto LABEL_530;
        }
        v311 = LODWORD(v396[0]);
        if ( LODWORD(v396[0]) >= 0x1A3 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_update_wm",
            4186,
            "Exceed buf size %u when adding reg/val at index %u and %u",
            420);
          v249 = v394;
          v316 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_530;
        }
        else
        {
          v312 = *(_QWORD *)(v252 + 8);
          v313 = *(_DWORD *)(v252 + 156);
          ++LODWORD(v396[0]);
          *(_DWORD *)(v18 + 4 * v311) = *(_DWORD *)(v312 + 16) + v313;
          v314 = LODWORD(v396[0]);
          v315 = *(_DWORD *)(v253 + 24);
          ++LODWORD(v396[0]);
          *(_DWORD *)(v18 + 4 * v314) = v315;
          v316 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_530;
        }
        if ( !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v316 & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4189,
            "VFE:%u WM:%d h_init 0x%X",
            *(_DWORD *)(v11 + 8),
            *(_DWORD *)(v252 + 120),
            *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)));
          v249 = v394;
        }
LABEL_530:
        if ( *(_QWORD *)(*(_QWORD *)(v252 + 8) + 88LL) )
        {
          if ( ((*(_QWORD *)(*(_QWORD *)(v12 + 2216) + 8928LL) >> *(_DWORD *)(v252 + 120)) & 1) != 0 )
          {
            v317 = v250;
            if ( *(_BYTE *)(v10 + 32) != 1 )
              goto LABEL_535;
          }
        }
        if ( (unsigned int)(*(_DWORD *)(v252 + 112) - 1) <= 1 )
        {
          v317 = (unsigned int *)(v252 + 36);
LABEL_535:
          v318 = *v317;
          v319 = v253;
          v320 = v250;
          v321 = v12;
          goto LABEL_537;
        }
        v319 = v253;
        v320 = v250;
        v321 = v12;
        v318 = 0;
LABEL_537:
        v322 = *(_QWORD *)(**(_QWORD **)(v10 + 40) + 8 * v249) + v318;
        if ( (cam_smmu_is_expanded_memory() & 1) != 0 )
        {
          v323 = LODWORD(v396[0]);
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4212,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
          }
          else
          {
            v324 = *(_QWORD *)(v252 + 8);
            v325 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v323) = *(_DWORD *)(v324 + 4) + v325;
            v326 = LODWORD(v396[0]);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v326) = v322 >> 8;
          }
          v327 = LODWORD(v396[0]);
          v328 = v394;
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4215,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
            v328 = v394;
          }
          else
          {
            v329 = *(_QWORD *)(v252 + 8);
            v330 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v327) = *(_DWORD *)(v329 + 68) + v330;
            v331 = LODWORD(v396[0]);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v331) = (unsigned __int8)v322;
          }
          v309 >>= 8;
          v12 = v321;
          if ( (debug_mdl & 8) != 0 )
          {
            v332 = v320;
            if ( debug_priority )
              goto LABEL_552;
            LODWORD(v372) = *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 3));
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, _DWORD))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_update_wm",
              4219,
              "VFE:%u WM:%d image address:0x%X image offset: 0x%X",
              *(unsigned int *)(v11 + 8),
              *(unsigned int *)(v252 + 120),
              v372,
              *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)));
LABEL_550:
            v328 = v394;
            goto LABEL_552;
          }
        }
        else
        {
          v333 = LODWORD(v396[0]);
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4224,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
          }
          else
          {
            v334 = *(_QWORD *)(v252 + 8);
            v335 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v333) = *(_DWORD *)(v334 + 4) + v335;
            v336 = LODWORD(v396[0]);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v336) = v322;
          }
          v328 = v394;
          v12 = v321;
          if ( (debug_mdl & 8) != 0 )
          {
            v332 = v320;
            if ( debug_priority )
              goto LABEL_552;
            LODWORD(v372) = *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1));
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, int))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_update_wm",
              4228,
              "VFE:%u WM:%d image address 0x%X",
              *(unsigned int *)(v11 + 8),
              *(unsigned int *)(v252 + 120),
              v372,
              v374);
            goto LABEL_550;
          }
        }
        v332 = v320;
LABEL_552:
        *(_DWORD *)(*(_QWORD *)(v10 + 40) + 4 * v328 + 8) = v318;
        v337 = LODWORD(v396[0]);
        if ( LODWORD(v396[0]) >= 0x1A3 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_update_wm",
            4234,
            "Exceed buf size %u when adding reg/val at index %u and %u",
            420);
          v328 = v394;
        }
        else
        {
          v338 = *(_QWORD *)(v252 + 8);
          v339 = *(_DWORD *)(v252 + 156);
          ++LODWORD(v396[0]);
          *(_DWORD *)(v18 + 4 * v337) = *(_DWORD *)(v338 + 8) + v339;
          v340 = LODWORD(v396[0]);
          ++LODWORD(v396[0]);
          *(_DWORD *)(v18 + 4 * v340) = v309;
        }
        v13 = v378;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4237,
            "VFE:%u WM:%d frame_inc: %d expanded_mem: %s",
            *(_DWORD *)(v11 + 8),
            *(_DWORD *)(v252 + 120),
            *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)),
            "Y");
          v328 = v394;
        }
        if ( *(_BYTE *)(*(_QWORD *)(v252 + 56) + 134LL) == 1 )
        {
          v341 = LODWORD(v396[0]);
          if ( LODWORD(v396[0]) >= 0x1A3 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_ver3_update_wm",
              4241,
              "Exceed buf size %u when adding reg/val at index %u and %u",
              420);
            v328 = v394;
            v346 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_562;
          }
          else
          {
            v342 = *(_QWORD *)(v252 + 8);
            v343 = *(_DWORD *)(v252 + 156);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v341) = *(_DWORD *)(v342 + 72) + v343;
            v344 = LODWORD(v396[0]);
            v345 = *(_DWORD *)(v377 + 248);
            ++LODWORD(v396[0]);
            *(_DWORD *)(v18 + 4 * v344) = v345;
            v346 = debug_mdl;
            if ( (debug_mdl & 8) == 0 )
              goto LABEL_562;
          }
          if ( !debug_priority )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v346 & 8,
              4,
              "cam_vfe_bus_ver3_update_wm",
              4244,
              "VFE:%u WM:%d %s ctxt cfg 0x%X",
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v252 + 120),
              (const char *)(*(_QWORD *)(v379 + 8 * v328) + 128LL),
              *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)));
            v328 = v394;
          }
        }
LABEL_562:
        v347 = LODWORD(v396[0]);
        if ( LODWORD(v396[0]) >= 0x1A3 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_update_wm",
            4249,
            "Exceed buf size %u when adding reg/val at index %u and %u",
            420);
          v328 = v394;
          v351 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_566;
        }
        else
        {
          v348 = *(_DWORD *)(v252 + 156);
          v349 = **(_DWORD **)(v252 + 8);
          ++LODWORD(v396[0]);
          *(_DWORD *)(v18 + 4 * v347) = v349 + v348;
          v350 = LODWORD(v396[0]);
          LODWORD(v9) = *(_DWORD *)(v319 + 28);
          ++LODWORD(v396[0]);
          *(_DWORD *)(v18 + 4 * v350) = v9;
          v351 = debug_mdl;
          if ( (debug_mdl & 8) == 0 )
            goto LABEL_566;
        }
        if ( !debug_priority )
        {
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v351 & 8,
            4,
            "cam_vfe_bus_ver3_update_wm",
            4253,
            "VFE:%u WM:%d %s out_res_id:0x%x en_cfg 0x%X",
            *(_DWORD *)(v11 + 8),
            *(_DWORD *)(v252 + 120),
            (const char *)(*(_QWORD *)(v379 + 8 * v328) + 128LL),
            *(_DWORD *)(*(_QWORD *)v10 + 4LL),
            *(_DWORD *)(v18 + 4LL * (unsigned int)(LODWORD(v396[0]) - 1)));
          v328 = v394;
        }
LABEL_566:
        if ( (*(_BYTE *)(v252 + 160) & 1) == 0 )
          *(_BYTE *)(v252 + 160) = 1;
        v35 = *(_QWORD *)(v252 + 56);
        v8 = *(unsigned __int8 *)(v35 + 133);
        if ( (v8 & 1) != 0 || (LODWORD(v35) = *(unsigned __int8 *)(v35 + 134), (_DWORD)v35 == 1) )
        {
          LOBYTE(v9) = 80;
          v352 = *(_QWORD *)(v252 + 64) + 80LL * v386;
          v353 = *(unsigned __int8 *)(v352 + 76);
          v35 = v352 + 76;
          v8 = v353;
          if ( (v353 & 1) == 0 )
          {
            v8 = 1;
            *(_BYTE *)v35 = 1;
          }
        }
        v251 = *(unsigned int *)(v378 + 32);
        v249 = v328 + 1;
        v250 = v332 + 12;
      }
      while ( v249 < v251 );
      if ( LODWORD(v396[0]) < 2 )
        goto LABEL_632;
      v357 = v375;
      v355 = LODWORD(v396[0]) >> 1;
      v364 = *(__int64 (__fastcall **)(_QWORD))(v375 + 24);
      if ( *((_DWORD *)v364 - 1) != 2010610996 )
        __break(0x8228u);
      v358 = 4 * v364(v355);
      if ( v358 <= *(_DWORD *)(v10 + 24) )
        goto LABEL_647;
      v213 = "cam_vfe_bus_ver3_update_wm";
      v214 = "VFE:%u Failed! Buf size:%d insufficient, expected size:%d";
      v215 = 4273;
LABEL_630:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        v213,
        v215,
        v214);
      out_res_mid_info = -12;
LABEL_18:
      _ReadStatusReg(SP_EL0);
      return out_res_mid_info;
    case 4u:
      v110 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v110 || (v35 = *(_QWORD *)(v110 + 16), (v111 = *(_QWORD *)(v35 + 88)) == 0) )
      {
        v25 = "cam_vfe_bus_ver3_update_hfr";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 4311;
        goto LABEL_16;
      }
      v8 = *(unsigned int *)(v110 + 32);
      if ( !(_DWORD)v8 )
        goto LABEL_597;
      v112 = *(unsigned int **)(a3 + 40);
      v113 = 0;
      v114 = 0;
      v18 = v35 + 96;
      while ( 1 )
      {
        if ( v114 >= 0x118 )
        {
          v213 = "cam_vfe_bus_ver3_update_hfr";
          v214 = "VFE:%u reg_val_pair %d exceeds the array limit %zu";
          v215 = 4323;
          goto LABEL_630;
        }
        if ( v113 == 2 )
          goto LABEL_666;
        v115 = *(_QWORD *)(*(_QWORD *)(v110 + 40 + 8 * v113) + 24LL);
        if ( (*(_BYTE *)(v11 + 34665) & 1) == 0 )
        {
          if ( *(_DWORD *)(v115 + 136) != v112[3] || (*(_BYTE *)(v115 + 161) & 1) == 0 )
          {
            v116 = (_DWORD *)(v18 + 4LL * v114);
            v114 += 2;
            *v116 = *(_DWORD *)(*(_QWORD *)(v115 + 8) + 56LL) + *(_DWORD *)(v115 + 156);
            v116[1] = v112[3];
            v117 = v112[3];
            LOBYTE(v9) = debug_mdl;
            *(_DWORD *)(v115 + 136) = v117;
            if ( (v9 & 8) != 0 && !debug_priority )
            {
              v390 = v114;
              v383 = v111;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v9 & 8,
                4,
                "cam_vfe_bus_ver3_update_hfr",
                4341,
                "VFE:%u WM:%d framedrop pattern 0x%X",
                *(_DWORD *)(v11 + 8),
                *(_DWORD *)(v115 + 120),
                v117);
              v111 = v383;
              v114 = v390;
            }
          }
          if ( *(_DWORD *)(v115 + 132) != v112[4] || (*(_BYTE *)(v115 + 161) & 1) == 0 )
          {
            v9 = v18 + 4LL * v114;
            v114 += 2;
            *(_DWORD *)v9 = *(_DWORD *)(*(_QWORD *)(v115 + 8) + 52LL) + *(_DWORD *)(v115 + 156);
            *(_DWORD *)(v9 + 4) = v112[4];
            v118 = v112[4];
            LOBYTE(v9) = debug_mdl;
            *(_DWORD *)(v115 + 132) = v118;
            if ( (v9 & 8) != 0 && !debug_priority )
            {
              v391 = v114;
              v384 = v111;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v9 & 8,
                4,
                "cam_vfe_bus_ver3_update_hfr",
                4353,
                "VFE:%u WM:%d framedrop period 0x%X",
                *(_DWORD *)(v11 + 8),
                *(_DWORD *)(v115 + 120),
                v118);
              v111 = v384;
              v114 = v391;
            }
          }
        }
        if ( *(_DWORD *)(v115 + 124) != v112[2] || (*(_BYTE *)(v115 + 161) & 1) == 0 )
        {
          v9 = v18 + 4LL * v114;
          v114 += 2;
          *(_DWORD *)v9 = *(_DWORD *)(*(_QWORD *)(v115 + 8) + 44LL) + *(_DWORD *)(v115 + 156);
          *(_DWORD *)(v9 + 4) = v112[2];
          v119 = v112[2];
          LOBYTE(v9) = debug_mdl;
          *(_DWORD *)(v115 + 124) = v119;
          if ( (v9 & 8) != 0 && !debug_priority )
          {
            v388 = v114;
            v381 = v111;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v9 & 8,
              4,
              "cam_vfe_bus_ver3_update_hfr",
              4367,
              "VFE:%u WM:%d irq subsample period 0x%X",
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v115 + 120),
              v119);
            v111 = v381;
            v114 = v388;
          }
        }
        v8 = v112[1];
        if ( *(_DWORD *)(v115 + 128) != (_DWORD)v8 || (*(_BYTE *)(v115 + 161) & 1) == 0 )
        {
          v9 = v18 + 4LL * v114;
          v114 += 2;
          *(_DWORD *)v9 = *(_DWORD *)(*(_QWORD *)(v115 + 8) + 48LL) + *(_DWORD *)(v115 + 156);
          *(_DWORD *)(v9 + 4) = v112[1];
          v8 = v112[1];
          LOBYTE(v9) = debug_mdl;
          *(_DWORD *)(v115 + 128) = v8;
          if ( (v9 & 8) != 0 && !debug_priority )
            break;
        }
        if ( (*(_BYTE *)(v115 + 161) & 1) == 0 )
          goto LABEL_222;
LABEL_198:
        v35 = *(unsigned int *)(v110 + 32);
        if ( ++v113 >= v35 )
        {
          if ( v114 < 2 )
          {
LABEL_597:
            out_res_mid_info = 0;
            *(_DWORD *)(v10 + 28) = 0;
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              v184 = *(unsigned int *)(v11 + 8);
              v185 = *(unsigned int *)(v110 + 32);
              v186 = "cam_vfe_bus_ver3_update_hfr";
              v187 = "VFE:%u No reg val pairs. num_wms: %u";
              v188 = debug_mdl & 8;
              v189 = 4;
              v190 = 4412;
LABEL_338:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                3,
                v188,
                v189,
                v186,
                v190,
                v187,
                v184,
                v185);
              out_res_mid_info = 0;
            }
            goto LABEL_18;
          }
          v355 = v114 >> 1;
          v356 = *(__int64 (__fastcall **)(_QWORD))(v111 + 24);
          v357 = v111;
          if ( *((_DWORD *)v356 - 1) != 2010610996 )
            __break(0x8228u);
          v358 = 4 * v356(v114 >> 1);
          if ( v358 > *(_DWORD *)(v10 + 24) )
          {
            v213 = "cam_vfe_bus_ver3_update_hfr";
            v214 = "VFE:%u Failed! Buf size:%d insufficient, expected size:%d";
            v215 = 4398;
            goto LABEL_630;
          }
LABEL_647:
          v365 = *(_DWORD **)(v357 + 120);
          v366 = *(_QWORD *)(v10 + 16);
          if ( *(v365 - 1) != -1401492769 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, unsigned __int64))v365)(v366, v355, v18);
          out_res_mid_info = 0;
          *(_DWORD *)(v10 + 28) = v358;
          goto LABEL_18;
        }
      }
      v389 = v114;
      v382 = v111;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v9 & 8,
        4,
        "cam_vfe_bus_ver3_update_hfr",
        4380,
        "VFE:%u WM:%d irq subsample pattern 0x%X",
        *(_DWORD *)(v11 + 8),
        *(_DWORD *)(v115 + 120),
        v8);
      v111 = v382;
      v114 = v389;
      if ( (*(_BYTE *)(v115 + 161) & 1) != 0 )
        goto LABEL_198;
LABEL_222:
      *(_BYTE *)(v115 + 161) = 1;
      goto LABEL_198;
    case 6u:
      out_res_mid_info = 0;
      **(_DWORD **)(a3 + 40) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a3 + 24LL) + 92LL) == 1;
      goto LABEL_18;
    case 8u:
      v101 = *(_QWORD *)(a3 + 8);
      v11 = *(_QWORD *)(v101 + 24);
      if ( !v11 )
      {
        v25 = "cam_vfe_bus_ver3_update_stripe_cfg";
        v23 = "Failed! Invalid data";
        v24 = 3;
        v26 = 4627;
        goto LABEL_16;
      }
      v102 = *(_DWORD *)(v101 + 4);
      if ( v102 < 0x3000 || v102 >= *(_DWORD *)(a1 + 34968) || !*(_DWORD *)(v11 + 32) )
        goto LABEL_642;
      v103 = *(_DWORD **)(a3 + 16);
      v104 = 3 * ((unsigned __int8)v102 + *(_DWORD *)a3 * *v103);
      v105 = &v103[4 * v104];
      v106 = *(_DWORD **)(*(_QWORD *)(v11 + 40) + 24LL);
      v107 = v105[7];
      v108 = v106[28];
      v106[4] = v107;
      v109 = v105[6];
      if ( (unsigned int)(v108 - 1) >= 2 )
        v106[10] = v109;
      else
        v106[9] = v109;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_update_stripe_cfg",
          4662,
          "VFE:%u out_type:0x%X WM:%d width:%d offset:0x%X h_init:%d",
          *(_DWORD *)(*(_QWORD *)(v11 + 16) + 8LL),
          *(_DWORD *)(*(_QWORD *)(a3 + 8) + 4LL),
          v106[30],
          v107,
          v106[9],
          v106[10]);
      if ( *(_DWORD *)(v11 + 32) < 2u )
        goto LABEL_642;
      v361 = *(_QWORD *)(v10 + 16) + 16LL * (v104 + 1);
      v8 = *(_QWORD *)(*(_QWORD *)(v11 + 48) + 24LL);
      LODWORD(v35) = *(_DWORD *)(v361 + 28);
      v362 = *(_DWORD *)(v8 + 112);
      *(_DWORD *)(v8 + 16) = v35;
      v363 = *(_DWORD *)(v361 + 24);
      if ( (unsigned int)(v362 - 1) >= 2 )
        *(_DWORD *)(v8 + 40) = v363;
      else
        *(_DWORD *)(v8 + 36) = v363;
      LOBYTE(v9) = debug_mdl;
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_641;
      goto LABEL_667;
    case 0xEu:
      if ( !*(_DWORD *)(a1 + 34952) )
        goto LABEL_17;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_process_cmd",
          5562,
          "VFE:%u Mask off bus error irq handler",
          *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
      out_res_mid_info = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v11 + 32));
      *(_DWORD *)(v11 + 34952) = 0;
      goto LABEL_18;
    case 0x11u:
      v88 = *(_DWORD *)(a3 + 8);
      LODWORD(v396[0]) = 44;
      out_res_id_and_index = cam_vfe_bus_ver3_get_out_res_id_and_index(a1, v88, v396);
      v90 = v396[0];
      v10 = out_res_id_and_index;
      if ( out_res_id_and_index == 44 || LODWORD(v396[0]) >= *(_DWORD *)(v11 + 34732) )
      {
        v180 = __ratelimit(&cam_vfe_bus_ver3_print_dimensions__rs, "cam_vfe_bus_ver3_print_dimensions");
        v161 = "target does not support req res id :0x%x outtype:%d index:%d";
        if ( v180 )
          v160 = 3;
        else
          v160 = 2;
        v163 = 2;
        v164 = "cam_vfe_bus_ver3_print_dimensions";
        v165 = 3161;
        v162 = v88;
        v17 = (unsigned int)v10;
        LODWORD(v372) = v90;
        goto LABEL_326;
      }
      v91 = *(_QWORD *)(*(_QWORD *)(v11 + 34760) + 152LL * LODWORD(v396[0]) + 24);
      if ( !v91 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_ver3_print_dimensions",
          3169,
          "VFE out data is null, res_id: %d",
          out_res_id_and_index);
        goto LABEL_17;
      }
      if ( *(_DWORD *)(v91 + 32) )
      {
        cam_vfe_bus_ver3_print_wm_info(
          *(_QWORD *)(*(_QWORD *)(v91 + 40) + 24LL),
          *(_QWORD *)(v91 + 16),
          v11,
          *(_QWORD *)(v91 + 40) + 128LL);
        if ( *(_DWORD *)(v91 + 32) > 1u )
        {
          cam_vfe_bus_ver3_print_wm_info(
            *(_QWORD *)(*(_QWORD *)(v91 + 48) + 24LL),
            *(_QWORD *)(v91 + 16),
            v11,
            *(_QWORD *)(v91 + 48) + 128LL);
          LODWORD(v35) = *(_DWORD *)(v91 + 32);
          if ( (unsigned int)v35 > 2 )
            goto LABEL_666;
        }
      }
      goto LABEL_642;
    case 0x18u:
      v11 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v11 || !*(_QWORD *)(*(_QWORD *)(v11 + 16) + 88LL) )
      {
        v25 = "cam_vfe_bus_ver3_update_ubwc_config_v2";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 4510;
        goto LABEL_16;
      }
      if ( !*(_DWORD *)(v11 + 32) )
        goto LABEL_642;
      v120 = *(_QWORD *)(v11 + 40);
      v121 = *(_QWORD *)(v120 + 24);
      if ( *(_QWORD *)(*(_QWORD *)(v121 + 8) + 88LL)
        && ((*(_QWORD *)(*(_QWORD *)(v12 + 2216) + 8928LL) >> *(_DWORD *)(v121 + 120)) & 1) != 0 )
      {
        v10 = *(_QWORD *)(a3 + 40);
        cam_vfe_bus_ver3_update_wm_ubwc_data(v121, v121 + 72, v10 + 4, *(unsigned __int8 *)(v121 + 160));
        if ( *(_DWORD *)(v11 + 32) < 2u )
          goto LABEL_642;
        v120 = *(_QWORD *)(v11 + 48);
        v122 = *(_QWORD *)(v120 + 24);
        if ( *(_QWORD *)(*(_QWORD *)(v122 + 8) + 88LL) )
        {
          if ( ((*(_QWORD *)(*(_QWORD *)(v12 + 2216) + 8928LL) >> *(_DWORD *)(v122 + 120)) & 1) != 0 )
          {
            cam_vfe_bus_ver3_update_wm_ubwc_data(v122, v122 + 72, v10 + 76, *(unsigned __int8 *)(v122 + 160));
            goto LABEL_641;
          }
        }
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_ver3_update_ubwc_config_v2",
        4525,
        "VFE:%u UBWC config not supported for client: %s",
        *(_DWORD *)(*(_QWORD *)(v11 + 16) + 8LL),
        (const char *)(v120 + 128));
      goto LABEL_17;
    case 0x1Au:
      v123 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v123 || !*(_QWORD *)(*(_QWORD *)(v123 + 16) + 88LL) || (v124 = *(_DWORD **)(a3 + 40)) == nullptr )
      {
        v25 = "cam_vfe_bus_ver3_update_wm_config";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 4821;
        goto LABEL_16;
      }
      if ( !*(_DWORD *)(v123 + 32) )
        goto LABEL_642;
      v35 = *(_QWORD *)(v123 + 24);
      v125 = 0;
      v126 = v123 + 40;
      v392 = v35;
      while ( 1 )
      {
        if ( v125 == 2 )
          goto LABEL_666;
        v127 = v124[1];
        v128 = *(_QWORD *)(*(_QWORD *)(v126 + 8 * v125) + 24LL);
        if ( v127 >= 3 )
        {
          v164 = "cam_vfe_bus_ver3_update_wm_config";
          v161 = "VFE:%u Invalid wm_mode: 0x%X WM:%d";
          v160 = 3;
          v162 = *(unsigned int *)(*(_QWORD *)(v123 + 16) + 8LL);
          v163 = 1;
          v165 = 4833;
          v17 = v127;
          LODWORD(v372) = *(_DWORD *)(v128 + 120);
          goto LABEL_326;
        }
        v10 = *(unsigned int *)(v128 + 112);
        v129 = *(_DWORD **)(*(_QWORD *)v128 + 80LL);
        if ( v127 != (_DWORD)v10 )
          *(_DWORD *)(v128 + 112) = v127;
        LODWORD(v9) = v124[5] << v129[30];
        v8 = v125 == 1;
        *(_DWORD *)(v128 + 44) = v9 | (v124[1] << v129[24]) | (1 << v129[28]);
        *(_DWORD *)(v128 + 16) = v124[4];
        v130 = v124[3];
        *(_BYTE *)(v128 + 163) = 0;
        *(_DWORD *)(v128 + 20) = v130 >> v8;
        v11 = (unsigned int)v124[9];
        if ( (_DWORD)v11 && *(_DWORD *)(v128 + 28) != (_DWORD)v11 )
        {
          *(_DWORD *)(v128 + 28) = v11;
          v131 = *(_DWORD *)(v128 + 120);
          v132 = v124[9];
          packer_fmt = cam_vfe_bus_ver3_get_packer_fmt(v132, v131);
          if ( packer_fmt == 17 )
          {
            v164 = "cam_vfe_bus_ver3_update_wm_config";
            v161 = "VFE:%u Invalid format:%d";
            v160 = 3;
            v162 = *(unsigned int *)(*(_QWORD *)(v123 + 16) + 8LL);
            v163 = 1;
            v165 = 4872;
            v17 = v132;
            goto LABEL_326;
          }
          if ( (unsigned int)v11 <= 0x31 )
          {
            v8 = 0x200000005E000LL;
            if ( ((1LL << v11) & 0x200000005E000LL) != 0 )
            {
              v8 = 34716;
              packer_fmt |= 1 << *(_DWORD *)(v392 + 34716);
            }
          }
          v134 = debug_mdl;
          *(_DWORD *)(v128 + 24) = packer_fmt;
          *(_BYTE *)(v128 + 163) = 1;
          if ( (v134 & 8) != 0 )
          {
            v8 = (unsigned int)debug_priority;
            if ( !debug_priority )
              ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v134 & 8,
                4,
                "cam_vfe_bus_ver3_update_wm_config",
                4880,
                "VFE:%u WM:%d update format:%d pack_fmt:%d",
                *(_DWORD *)(*(_QWORD *)(v123 + 16) + 8LL),
                v131,
                v124[9],
                packer_fmt);
          }
        }
        if ( *(_DWORD *)(v123 + 8) <= 4u && (v127 != (_DWORD)v10 || (*(_BYTE *)(v128 + 163) & 1) != 0) )
          cam_vfe_bus_ver3_config_rdi_wm(v128);
        if ( (debug_mdl & 8) != 0 )
        {
          v8 = (unsigned int)debug_priority;
          if ( !debug_priority )
          {
            v135 = "N";
            if ( v127 == (_DWORD)v10 )
              v136 = "N";
            else
              v136 = "Y";
            if ( *(_BYTE *)(v128 + 163) )
              v135 = "Y";
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_update_wm_config",
              4893,
              "VFE:%u WM:%d %s update_mode:%s update_fmt:%s en_cfg:0x%X height:%d width:%d stride:%d",
              *(_DWORD *)(*(_QWORD *)(v123 + 16) + 8LL),
              *(_DWORD *)(v128 + 120),
              (const char *)(*(_QWORD *)(v126 + 8 * v125) + 128LL),
              v136,
              v135,
              *(_DWORD *)(v128 + 44),
              *(_DWORD *)(v128 + 20),
              *(_DWORD *)(v128 + 16),
              *(_DWORD *)(v128 + 32));
          }
        }
        v35 = *(unsigned int *)(v123 + 32);
        ++v125;
        out_res_mid_info = 0;
        if ( v125 >= v35 )
          goto LABEL_18;
      }
    case 0x23u:
      v158 = cam_io_r_mb(*(_QWORD *)(a1 + 16) + *(_QWORD *)a1 + *(unsigned int *)(*(_QWORD *)(a1 + 80) + 124LL));
      cam_io_w_mb(
        (1 << *(_DWORD *)(v11 + 34740)) | v158,
        *(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + 124LL));
      goto LABEL_17;
    case 0x25u:
      v153 = *(_DWORD *)(a3 + 4);
      LODWORD(v396[0]) = 44;
      v154 = cam_vfe_bus_ver3_get_out_res_id_and_index(a1, v153, v396);
      v155 = v154;
      if ( v154 > 0x2B || LODWORD(v396[0]) >= *(_DWORD *)(v11 + 34732) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_get_last_consumed_addr",
          5442,
          "target does not support req res id :0x%x outtype:%d index:%d",
          v153,
          v154,
          LODWORD(v396[0]));
        *(_DWORD *)(v10 + 12) = 0;
        goto LABEL_17;
      }
      v156 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 34760) + 152LL * LODWORD(v396[0]) + 24) + 40LL) + 24LL);
      v157 = cam_io_r_mb(
               *(_QWORD *)(*(_QWORD *)v156 + 16LL)
             + *(unsigned int *)(v156 + 156)
             + *(unsigned int *)(*(_QWORD *)(v156 + 8) + 96LL));
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v370 = *(_DWORD *)(v11 + 8);
        v371 = v157;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_get_last_consumed_addr",
          5454,
          "VFE:%u res_type:0x%x res_id:0x%x last_consumed_addr:0x%x",
          v370,
          v153,
          v155,
          v157);
        *(_DWORD *)(v10 + 12) = v371;
        if ( v371 )
          goto LABEL_642;
      }
      else
      {
        *(_DWORD *)(v10 + 12) = v157;
        if ( v157 )
          goto LABEL_642;
      }
      goto LABEL_17;
    case 0x26u:
      v10 = *(_QWORD *)(a3 + 40);
      if ( !v10 )
      {
        v25 = "cam_vfe_bus_get_res_for_mid";
        v23 = "invalid get resource for mid paramas";
        v24 = 3;
        v26 = 5396;
        goto LABEL_16;
      }
      v56 = *(_QWORD *)(a1 + 34984);
      if ( *(_BYTE *)(v56 + 8944) == 1 )
      {
        v57 = *(_DWORD *)(v56 + 488);
        if ( v57 )
        {
          LODWORD(v8) = 0;
          v9 = v56 + 728;
          do
          {
            v226 = 152LL * (unsigned int)v8;
            v227 = (unsigned int)v8;
            v228 = (const char **)(v9 + 240LL * (unsigned int)v8);
            if ( (unsigned int)v8 <= 0x21 )
              v8 = 33;
            else
              v8 = (unsigned int)v8;
            v35 = 0;
            v8 = v227 - v8;
            v229 = v57;
            while ( 1 )
            {
              if ( (v229 & 1) == 0 )
              {
                LODWORD(v8) = v227 - v35;
                goto LABEL_400;
              }
              if ( v8 == v35 )
                goto LABEL_666;
              v230 = (unsigned __int64)*(v228 - 5);
              if ( !v230 || ((v230 >> *(_DWORD *)(v10 + 8)) & 1) != 0 )
                break;
              _CF = v229 >= 2;
              v226 += 152;
              --v35;
              v228 += 30;
              v229 >>= 1;
              if ( !_CF )
                goto LABEL_431;
            }
            v231 = *((_DWORD *)v228 - 12);
            v8 = v227 - v35;
            if ( v231 )
            {
              v232 = *((_DWORD *)v228 - 7);
              v233 = *(_DWORD *)v10;
              v234 = HIWORD(v232);
              v235 = HIWORD(v232) == *(_DWORD *)v10;
              _ZF = *(_DWORD *)v10 == (unsigned __int16)v232;
              v236 = 0;
              if ( _ZF || v234 == v233 )
              {
LABEL_650:
                v9 = *(_QWORD *)(v11 + 34760) + v226;
                v367 = *(_QWORD *)(v9 + 24);
                *(_DWORD *)(v10 + 4) = *(_DWORD *)(v9 + 4);
                LODWORD(v9) = *(_DWORD *)(v367 + 32);
                if ( !(_DWORD)v9 )
                  goto LABEL_661;
                v368 = *(_QWORD *)(*(_QWORD *)(v367 + 40) + 24LL);
                if ( (_DWORD)v227 - *(_DWORD *)(v368 + 120) == (_DWORD)v35 )
                  goto LABEL_652;
                if ( (_DWORD)v9 == 1 )
                  goto LABEL_661;
                v368 = *(_QWORD *)(*(_QWORD *)(v367 + 48) + 24LL);
                if ( (_DWORD)v227 - *(_DWORD *)(v368 + 120) == (_DWORD)v35 )
                {
LABEL_652:
                  v369 = "NO";
                  if ( v235 )
                    v369 = "YES";
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    8,
                    3,
                    "cam_vfe_bus_ver3_dump_wm_mid_info",
                    5336,
                    "MID:%d PID:%d pid_mask:0x%lx match for WM[%u: %s] ctxt:%d is_meta %s",
                    v233,
                    *(_DWORD *)(v10 + 8),
                    *(v228 - 5),
                    v8,
                    *v228,
                    v236,
                    v369);
                  cam_vfe_bus_ver3_print_wm_info(v368, v11, v11, *v228);
                  goto LABEL_661;
                }
                if ( (_DWORD)v9 == 2 )
                {
LABEL_661:
                  out_res_mid_info = 0;
                  *(_BYTE *)(v10 + 12) = 1;
                  goto LABEL_18;
                }
                do
                {
LABEL_666:
                  __break(0x5512u);
LABEL_667:
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v9 & 8,
                    4,
                    "cam_vfe_bus_ver3_update_stripe_cfg",
                    4662,
                    "VFE:%u out_type:0x%X WM:%d width:%d offset:0x%X h_init:%d",
                    *(_DWORD *)(*(_QWORD *)(v11 + 16) + 8LL),
                    *(_DWORD *)(*(_QWORD *)(v10 + 8) + 4LL),
                    *(_DWORD *)(v8 + 120),
                    v35,
                    *(_DWORD *)(v8 + 36),
                    *(_DWORD *)(v8 + 40));
LABEL_641:
                  LODWORD(v35) = *(_DWORD *)(v11 + 32);
                }
                while ( (unsigned int)v35 > 2 );
LABEL_642:
                out_res_mid_info = 0;
                goto LABEL_18;
              }
              if ( v231 != 1 )
              {
                v237 = *((_DWORD *)v228 - 6);
                v238 = HIWORD(v237);
                v235 = HIWORD(v237) == v233;
                _ZF = v233 == (unsigned __int16)v237;
                v236 = 1;
                if ( _ZF || v238 == v233 )
                  goto LABEL_650;
                if ( v231 != 2 )
                {
                  v239 = *((_DWORD *)v228 - 5);
                  v240 = HIWORD(v239);
                  v235 = HIWORD(v239) == v233;
                  _ZF = v233 == (unsigned __int16)v239;
                  v236 = 2;
                  if ( _ZF || v240 == v233 )
                    goto LABEL_650;
                  if ( v231 != 3 )
                  {
                    v241 = *((_DWORD *)v228 - 4);
                    v242 = HIWORD(v241);
                    v235 = HIWORD(v241) == v233;
                    _ZF = v233 == (unsigned __int16)v241;
                    v236 = 3;
                    if ( _ZF || v242 == v233 )
                      goto LABEL_650;
                    if ( v231 != 4 )
                    {
                      v243 = *((_DWORD *)v228 - 3);
                      v244 = HIWORD(v243);
                      v235 = HIWORD(v243) == v233;
                      _ZF = v233 == (unsigned __int16)v243;
                      v236 = 4;
                      if ( _ZF || v244 == v233 )
                        goto LABEL_650;
                      if ( v231 != 5 )
                      {
                        v245 = *((_DWORD *)v228 - 2);
                        v246 = HIWORD(v245);
                        v235 = HIWORD(v245) == v233;
                        _ZF = v233 == (unsigned __int16)v245;
                        v236 = 5;
                        if ( _ZF || v246 == v233 )
                          goto LABEL_650;
                        if ( v231 != 6 )
                          goto LABEL_666;
                      }
                    }
                  }
                }
              }
            }
LABEL_400:
            v57 = v229 >> 1;
            LODWORD(v8) = v8 + 1;
          }
          while ( v229 > 1 );
        }
LABEL_431:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_bus_ver3_dump_wm_mid_info",
          5324,
          "no valid client found for mid: %d pid:%d",
          *(_DWORD *)v10,
          *(_DWORD *)(v10 + 8));
        out_res_mid_info = -22;
        *(_BYTE *)(v10 + 12) = 1;
      }
      else
      {
        out_res_mid_info = cam_vfe_bus_ver3_get_out_res_mid_info(a1, *(int **)(a3 + 40));
        *(_BYTE *)(v10 + 12) = 0;
        if ( !out_res_mid_info )
          goto LABEL_18;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_get_res_for_mid",
        5411,
        "VFE:%u mid:%d does not match with any out resource",
        *(_DWORD *)(v11 + 8),
        *(_DWORD *)v10);
      *(_DWORD *)(v10 + 4) = 0;
      goto LABEL_18;
    case 0x2Cu:
      v92 = *(_DWORD *)(a1 + 34968);
      v93 = (unsigned int)(v92 - 12288);
      *(_DWORD *)a3 = v92;
      if ( v92 != 12288 )
      {
        v94 = 0;
        LODWORD(v396[0]) = 0;
        do
        {
          if ( (unsigned int)cam_vfe_bus_ver3_get_out_res_id_and_index(v11, (unsigned int)(v94 + 12288), v396) <= 0x2B
            && LODWORD(v396[0]) < *(_DWORD *)(v11 + 34732) )
          {
            v95 = *(_QWORD *)(v11 + 34760) + 152LL * LODWORD(v396[0]);
            v96 = *(_QWORD *)(v95 + 24);
            if ( v96 )
            {
              if ( *(_DWORD *)(v95 + 8) == 1 )
              {
                v97 = *(_QWORD *)(v10 + 56);
                v98 = 1LL << v94;
                *(_QWORD *)(v10 + 48) |= 1LL << v94;
                if ( *(_BYTE *)(v96 + 133) )
                  v99 = 1LL << v94;
                else
                  v99 = 0;
                *(_QWORD *)(v10 + 56) = v99 | v97;
                if ( !*(_BYTE *)(v96 + 134) )
                  v98 = 0;
                *(_QWORD *)(v10 + 64) |= v98;
              }
            }
          }
          ++v94;
        }
        while ( v93 != v94 );
      }
      out_res_mid_info = 0;
      *(_BYTE *)(v10 + 29) = *(_BYTE *)(v11 + 34667);
      *(_BYTE *)(v10 + 32) = *(_BYTE *)(*(_QWORD *)(v11 + 34984) + 8905LL);
      *(_DWORD *)(v10 + 36) = *(_DWORD *)(*(_QWORD *)(v11 + 34984) + 8908LL);
      *(_DWORD *)(v10 + 40) = *(_DWORD *)(*(_QWORD *)(v11 + 34984) + 8912LL);
      *(_DWORD *)(v10 + 8) = *(_DWORD *)(*(_QWORD *)(v11 + 34984) + 160LL);
      v100 = *(unsigned __int8 *)(v11 + 34673);
      *(_BYTE *)(v10 + 44) = v100;
      if ( v100 == 1 )
        *(_BYTE *)(v10 + 29) = 0;
      goto LABEL_18;
    case 0x38u:
      v63 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v63 )
      {
        v25 = "cam_vfe_bus_ver3_config_wm";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 3893;
        goto LABEL_16;
      }
      if ( (*(_BYTE *)(v63 + 132) & 1) == 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_config_wm",
          3900,
          "Configuring scratch for VFE:%u out_type: %u, with no BW limiter enabled",
          *(_DWORD *)(a1 + 8),
          *(_DWORD *)(v63 + 8));
      if ( !*(_DWORD *)(v63 + 32) )
        goto LABEL_642;
      v64 = 0;
      LODWORD(v35) = v63 + 40;
      do
      {
        if ( v64 == 2 )
          goto LABEL_666;
        v65 = *(_DWORD *)(*(_QWORD *)(v10 + 40) + 48LL);
        v66 = *(__int64 **)(*(_QWORD *)(v63 + 40 + 8 * v64) + 24LL);
        v67 = (v65 + 15) & 0xFFFFFFF0;
        v68 = *((unsigned int *)v66 + 39);
        v69 = *(_QWORD *)(*v66 + 16);
        v387 = *(unsigned int **)(v66[1] + 88);
        if ( v67 != v65 && v67 != *((_DWORD *)v66 + 8) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            2,
            "cam_vfe_bus_ver3_config_wm",
            3914,
            "VFE:%u Warning stride %u expected %u",
            *(_DWORD *)(v11 + 8),
            v65,
            v67);
        v70 = v69 + v68;
        if ( *((_DWORD *)v66 + 8) != v67 || (v66[20] & 1) == 0 )
        {
          cam_io_w_mb(v65, v70 + *(unsigned int *)(v66[1] + 20));
          v71 = debug_mdl;
          *((_DWORD *)v66 + 8) = v67;
          if ( (v71 & 8) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v71 & 8,
              4,
              "cam_vfe_bus_ver3_config_wm",
              3920,
              "VFE:%u WM:%d image stride 0x%x",
              *(_DWORD *)(v11 + 8),
              *((_DWORD *)v66 + 30),
              v65);
        }
        v72 = *(_QWORD *)(**(_QWORD **)(v10 + 40) + 8 * v64);
        if ( (cam_smmu_is_expanded_memory() & 1) != 0 )
        {
          v73 = v72 >> 8;
          cam_io_w_mb((unsigned int)(v72 >> 8), v70 + *(unsigned int *)(v66[1] + 4));
          cam_io_w_mb((unsigned __int8)v72, v70 + *(unsigned int *)(v66[1] + 68));
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_config_wm",
              3934,
              "VFE:%u WM:%d image address 0x%x 0x%x",
              *(_DWORD *)(v11 + 8),
              *((_DWORD *)v66 + 30),
              v73,
              (unsigned __int8)v72);
        }
        else
        {
          cam_io_w_mb((unsigned int)v72, v70 + *(unsigned int *)(v66[1] + 4));
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_config_wm",
              3939,
              "VFE:%u WM:%d image address 0x%X",
              *(_DWORD *)(v11 + 8),
              *((_DWORD *)v66 + 30),
              v72);
          LODWORD(v73) = v72;
        }
        v74 = v66[1];
        if ( *(_QWORD *)(v74 + 88)
          && ((*(_QWORD *)(*(_QWORD *)(v11 + 34984) + 8928LL) >> *((_DWORD *)v66 + 30)) & 1) != 0 )
        {
          if ( *((_BYTE *)v66 + 72) == 1 )
          {
            *((_BYTE *)v66 + 72) = 0;
            if ( v66 )
            {
              v75 = *(unsigned int **)(v74 + 88);
              v76 = *(_QWORD *)(*v66 + 16) + *((unsigned int *)v66 + 39);
              cam_io_w_mb(*((unsigned int *)v66 + 20), v76 + v75[1]);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_ver3_config_ubwc_regs",
                  3827,
                  "VFE:%u WM:%d meta stride:0x%x",
                  *(_DWORD *)(*v66 + 8),
                  *((_DWORD *)v66 + 30),
                  *((_DWORD *)v66 + 20));
              v77 = *v66;
              if ( *(_BYTE *)(*v66 + 34669) == 1 )
              {
                v78 = debug_mdl;
                *((_DWORD *)v66 + 21) &= ~v75[9];
                if ( (v78 & 8) != 0 && !debug_priority )
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v78 & 8,
                    4,
                    "cam_vfe_bus_ver3_config_ubwc_regs",
                    3833,
                    "Force disable UBWC compression on VFE:%u WM:%d",
                    *(_DWORD *)(v77 + 8),
                    *((_DWORD *)v66 + 30));
              }
              cam_io_w_mb(*((unsigned int *)v66 + 21), v76 + v75[2]);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_ver3_config_ubwc_regs",
                  3839,
                  "VFE:%u WM:%d ubwc_mode_cfg:0x%x",
                  *(_DWORD *)(*v66 + 8),
                  *((_DWORD *)v66 + 30),
                  *((_DWORD *)v66 + 21));
              cam_io_w_mb(*((unsigned int *)v66 + 23), v76 + v75[4]);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_ver3_config_ubwc_regs",
                  3844,
                  "VFE:%u WM:%d ubwc_ctrl_2:0x%x",
                  *(_DWORD *)(*v66 + 8),
                  *((_DWORD *)v66 + 30),
                  *((_DWORD *)v66 + 23));
              cam_io_w_mb(*((unsigned int *)v66 + 24), v76 + v75[5]);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_ver3_config_ubwc_regs",
                  3849,
                  "VFE:%u WM:%d lossy_thresh0: 0x%x",
                  *(_DWORD *)(*v66 + 8),
                  *((_DWORD *)v66 + 30),
                  *((_DWORD *)v66 + 24));
              cam_io_w_mb(*((unsigned int *)v66 + 25), v76 + v75[6]);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_ver3_config_ubwc_regs",
                  3854,
                  "VFE:%u WM:%d lossy_thresh0:0x%x",
                  *(_DWORD *)(*v66 + 8),
                  *((_DWORD *)v66 + 30),
                  *((_DWORD *)v66 + 25));
              cam_io_w_mb(*((unsigned int *)v66 + 26), v76 + v75[7]);
              if ( (debug_mdl & 8) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 8,
                  4,
                  "cam_vfe_bus_ver3_config_ubwc_regs",
                  3859,
                  "VFE:%u WM:%d off_lossy_var:0x%x",
                  *(_DWORD *)(*v66 + 8),
                  *((_DWORD *)v66 + 30),
                  *((_DWORD *)v66 + 26));
              v79 = *((unsigned int *)v66 + 27);
              if ( (unsigned int)v79 <= 0xFFFE )
              {
                cam_io_w_mb(v79, v76 + v75[8]);
                if ( (debug_mdl & 8) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "cam_vfe_bus_ver3_config_ubwc_regs",
                    3869,
                    "VFE:%u WM:%d ubwc bw limit:0x%x",
                    *(_DWORD *)(*v66 + 8),
                    *((_DWORD *)v66 + 30),
                    *((_DWORD *)v66 + 27));
              }
            }
            else
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_bus_ver3_config_ubwc_regs",
                3817,
                "Invalid args");
            }
          }
          cam_io_w_mb((unsigned int)v73, v70 + *v387);
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_config_wm",
              3951,
              "VFE:%u WM:%d meta address 0x%x",
              *(_DWORD *)(v11 + 8),
              *((_DWORD *)v66 + 30),
              v73);
        }
        cam_io_w_mb(*((unsigned int *)v66 + 11), v70 + *(unsigned int *)v66[1]);
        if ( (debug_mdl & 8) != 0 )
        {
          v8 = (unsigned int)debug_priority;
          if ( !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_config_wm",
              3957,
              "VFE:%u WM:%d en_cfg 0x%x",
              *(_DWORD *)(v11 + 8),
              *((_DWORD *)v66 + 30),
              *((_DWORD *)v66 + 11));
        }
        v35 = *(unsigned int *)(v63 + 32);
        ++v64;
        out_res_mid_info = 0;
      }
      while ( v64 < v35 );
      goto LABEL_18;
    case 0x3Du:
      v54 = *(unsigned __int8 *)(a3 + 76);
      out_res_mid_info = 0;
      *(_BYTE *)(a1 + 34671) = v54;
      *(_BYTE *)(a1 + 34674) = *(_BYTE *)(a3 + 78);
      *(_BYTE *)(a1 + 34675) = *(_BYTE *)(a3 + 79);
      *(_DWORD *)(a1 + 34632) = *(_DWORD *)(a3 + 44);
      *(_DWORD *)(a1 + 34636) = *(_DWORD *)(a3 + 48);
      *(_DWORD *)(a1 + 34640) = *(_DWORD *)(a3 + 52);
      *(_DWORD *)(a1 + 34644) = *(_DWORD *)(a3 + 56);
      *(_DWORD *)(a1 + 34648) = *(_DWORD *)(a3 + 60);
      *(_DWORD *)(a1 + 34652) = *(_DWORD *)(a3 + 64);
      *(_DWORD *)(a1 + 34656) = *(_DWORD *)(a3 + 68);
      *(_DWORD *)(a1 + 34660) = *(_DWORD *)(a3 + 72);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        if ( v54 )
          v55 = "disabled";
        else
          v55 = "enabled";
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_process_cmd",
          5672,
          "IFE: %u bus WR prefetch %s",
          *(_DWORD *)(a1 + 8),
          v55);
        out_res_mid_info = 0;
      }
      goto LABEL_18;
    case 0x40u:
      v137 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v137 || (v9 = *(_QWORD *)(v137 + 16), (v8 = *(_QWORD *)(v9 + 88)) == 0) )
      {
        v25 = "cam_vfe_bus_update_bw_limiter";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 4919;
        goto LABEL_16;
      }
      LODWORD(v35) = *(_DWORD *)(v137 + 32);
      if ( (_DWORD)v35 )
      {
        v138 = *(_QWORD *)(a3 + 40);
        v11 = 0;
        v139 = 0;
        v140 = v137 + 40;
        v141 = (int *)(v9 + 100);
        v142 = &unk_393000;
        v385 = *(_QWORD *)(v137 + 16);
        v393 = *(_QWORD *)(v9 + 88);
        do
        {
          if ( v11 == 2 )
            goto LABEL_666;
          v143 = *(_QWORD *)(v140 + 8 * v11);
          v144 = *(_QWORD *)(v143 + 24);
          v145 = *(_DWORD *)(*(_QWORD *)(v144 + 8) + 132LL);
          if ( !v145 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_bus_update_bw_limiter",
              4948,
              "VFE:%u WM: %d %s has no support for bw limiter",
              *(unsigned int *)(*(_QWORD *)(v137 + 16) + 8LL),
              *(unsigned int *)(v144 + 120),
              v143 + 128);
            goto LABEL_17;
          }
          v146 = *(_DWORD *)(v138 + 8 + 4 * v11);
          if ( v146 > *(_DWORD *)(*(_QWORD *)v144 + 34720LL) )
          {
            v147 = v142;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              8,
              2,
              "cam_vfe_bus_update_bw_limiter",
              4961,
              "VFE:%u Invalid counter limit: 0x%x capping to max: 0x%x",
              *(unsigned int *)(*(_QWORD *)(v137 + 16) + 8LL));
            v142 = v147;
            v146 = *(_DWORD *)(*(_QWORD *)v144 + 34720LL);
            v145 = *(_DWORD *)(*(_QWORD *)(v144 + 8) + 132LL);
          }
          LODWORD(v9) = *(_DWORD *)(v144 + 156);
          v148 = *(_DWORD *)(v138 + 4) != 0 && v146 != 0;
          v149 = v9 + v145;
          if ( v148 )
            v150 = 2 * v146 + 1;
          else
            v150 = 0;
          *(v141 - 1) = v149;
          *v141 = v150;
          v8 = v142[458];
          if ( (v8 & 8) != 0 )
          {
            LOBYTE(v9) = debug_priority;
            if ( !debug_priority )
            {
              v151 = *(_DWORD *)(v144 + 120);
              v152 = v142;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v142[458] & 8LL,
                4,
                "cam_vfe_bus_update_bw_limiter",
                4980,
                "VFE:%u WM: %d for %s bw_limter: 0x%x",
                *(_DWORD *)(*(_QWORD *)(v137 + 16) + 8LL),
                v151,
                (const char *)(*(_QWORD *)(v140 + 8 * v11) + 128LL),
                v150);
              v142 = v152;
            }
          }
          v35 = *(unsigned int *)(v137 + 32);
          ++v11;
          v139 |= v148;
          v141 += 2;
        }
        while ( v11 < v35 );
        v354 = *(__int64 (__fastcall **)(_QWORD))(v393 + 24);
        if ( *((_DWORD *)v354 - 1) != 2010610996 )
          __break(0x8228u);
        v247 = 4 * v354((unsigned int)v11);
        if ( v247 > *(_DWORD *)(v10 + 24) )
        {
          v213 = "cam_vfe_bus_update_bw_limiter";
          v214 = "VFE:%u Failed! Buf size:%d insufficient, expected size:%d";
          v215 = 4996;
          goto LABEL_630;
        }
        v359 = *(_DWORD **)(v393 + 120);
        v360 = *(_QWORD *)(v10 + 16);
        if ( *(v359 - 1) != -1401492769 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v359)(v360, (unsigned int)v11, v385 + 96);
      }
      else
      {
        v247 = 0;
        if ( (debug_mdl & 8) != 0 )
        {
          v139 = 0;
          if ( !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_update_bw_limiter",
              5009,
              "VFE:%u No reg val pairs. num_wms: %u",
              *(_DWORD *)(v9 + 8),
              0);
            v247 = 0;
            v139 = 0;
          }
        }
        else
        {
          v139 = 0;
        }
      }
      out_res_mid_info = 0;
      *(_DWORD *)(v10 + 28) = v247;
      *(_BYTE *)(v137 + 132) = v139 & 1;
      goto LABEL_18;
    case 0x45u:
      if ( *(_QWORD *)(a3 + 8) < 0x18u )
      {
        v35 = 0;
        goto LABEL_612;
      }
      v191 = *(_QWORD *)a3;
      v192 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 112LL);
      *(_QWORD *)(v191 + 8) = cam_soc_util_get_applied_src_clk((_QWORD *)(v192 + 96), 1);
      *(_BYTE *)(v191 + 21) = *(_DWORD *)(*(_QWORD *)(v11 + 24) + 4LL);
      *(_BYTE *)(v191 + 20) = *(_DWORD *)(v192 + 92);
      *(_QWORD *)v191 = *(_QWORD *)v10 + 24LL;
      v193 = *(unsigned int *)(v11 + 34732);
      if ( !(_DWORD)v193 )
      {
        LODWORD(v9) = 0;
        v35 = 24;
        goto LABEL_611;
      }
      v194 = (const char *)(v11 + 0x8000);
      v195 = 0;
      v196 = 0;
      v197 = 0;
      v35 = 24;
      v11 = (unsigned __int64)"%s";
      while ( 2 )
      {
        v198 = *((_QWORD *)v194 + 249);
        v199 = *(_QWORD *)(v198 + v195 + 24);
        if ( !v199 || !*(_DWORD *)(v199 + 32) )
          goto LABEL_342;
        v200 = v35 + 56;
        if ( v35 + 56 > *(_QWORD *)(v10 + 8) )
        {
          LODWORD(v9) = v197;
        }
        else
        {
          v201 = (_DWORD *)(*(_QWORD *)v191 + 56LL * v197);
          v202 = v198 + v195;
          v203 = *(_DWORD **)(*(_QWORD *)(v199 + 40) + 24LL);
          *v201 = v203[4];
          v201[8] = v203[30];
          v201[1] = v203[5];
          v201[2] = v203[8];
          v201[6] = v203[11];
          v201[3] = v203[10];
          v201[7] = v203[7];
          v201[4] = v203[36];
          v201[5] = v203[37];
          v201[9] = *(_DWORD *)(v198 + v195 + 8);
          scnprintf(v201 + 10, 16, "%s", (const char *)(*(_QWORD *)(v199 + 40) + 128LL));
          LODWORD(v9) = v197 + 1;
          v35 = v200;
          if ( *(_DWORD *)(v199 + 32) <= 1u )
            goto LABEL_341;
          v204 = v200 + 56;
          if ( v35 + 56 > *(_QWORD *)(v10 + 8) )
            break;
          v205 = (_DWORD *)(*(_QWORD *)v191 + 56LL * (unsigned int)v9);
          v206 = *(_DWORD **)(*(_QWORD *)(v199 + 48) + 24LL);
          *v205 = v206[4];
          v205[8] = v206[30];
          v205[1] = v206[5];
          v205[2] = v206[8];
          v205[6] = v206[11];
          v205[3] = v206[10];
          v205[7] = v206[7];
          v205[4] = v206[36];
          v205[5] = v206[37];
          v205[9] = *(_DWORD *)(v202 + 8);
          scnprintf(v205 + 10, 16, "%s", (const char *)(*(_QWORD *)(v199 + 48) + 128LL));
          LODWORD(v9) = v197 + 2;
          v35 = v204;
          if ( *(_DWORD *)(v199 + 32) < 3u )
          {
LABEL_341:
            v193 = *((unsigned int *)v194 + 491);
            v197 = v9;
LABEL_342:
            ++v196;
            v195 += 152;
            LODWORD(v9) = v197;
            if ( v196 >= v193 )
              break;
            continue;
          }
          v8 = *(_QWORD *)(v10 + 8);
          if ( (unsigned __int64)v204 + 56 <= v8 )
            goto LABEL_666;
        }
        break;
      }
LABEL_611:
      *(_DWORD *)(v191 + 16) = v9;
LABEL_612:
      out_res_mid_info = 0;
      *(_QWORD *)(v10 + 16) = v35;
      goto LABEL_18;
    case 0x47u:
      v166 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 112LL);
      if ( *(_DWORD *)(v166 + 92) )
      {
        v167 = cam_common_user_dump_helper(
                 (_QWORD *)v10,
                 (__int64 (__fastcall *)(__int64, __int64))cam_common_user_dump_clock,
                 v166,
                 8,
                 "CLK_RATE_PRINT:",
                 a6,
                 a7,
                 a8,
                 v372);
        if ( v167 )
        {
          v169 = *(unsigned int *)(v11 + 8);
          out_res_mid_info = v167;
          v170 = "VFE:%u BUS VER3: Clock dump failed, rc: %d";
          v171 = 3315;
LABEL_301:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_user_dump",
            v171,
            v170,
            v169,
            out_res_mid_info);
          goto LABEL_18;
        }
        if ( !*(_DWORD *)(v11 + 34732) )
          goto LABEL_642;
        v218 = 0;
        v219 = 0;
        while ( 1 )
        {
          v220 = *(_QWORD *)(v11 + 34760);
          LODWORD(v9) = *(_DWORD *)(v220 + v218 + 8);
          if ( (unsigned int)v9 > 1 )
          {
            v221 = *(_QWORD *)(v220 + v218 + 24);
            if ( v221 )
            {
              LODWORD(v35) = *(_DWORD *)(v221 + 32);
              if ( (_DWORD)v35 )
              {
                v222 = *(_QWORD *)(v221 + 40);
                v223 = *(_QWORD *)(v222 + 24);
                if ( v223 )
                {
                  v224 = cam_common_user_dump_helper(
                           (_QWORD *)v10,
                           (__int64 (__fastcall *)(__int64, __int64))cam_vfe_bus_ver3_user_dump_info,
                           v223,
                           4,
                           "VFE_BUS_CLIENT.%s.%d:",
                           v222 + 128,
                           *(unsigned int *)(*(_QWORD *)(v221 + 16) + 8LL),
                           v168,
                           v373);
                  if ( v224 )
                    goto LABEL_386;
                  LODWORD(v35) = *(_DWORD *)(v221 + 32);
                }
                if ( (unsigned int)v35 >= 2 )
                {
                  v8 = *(_QWORD *)(v221 + 48);
                  v225 = *(_QWORD *)(v8 + 24);
                  if ( v225 )
                  {
                    v224 = cam_common_user_dump_helper(
                             (_QWORD *)v10,
                             (__int64 (__fastcall *)(__int64, __int64))cam_vfe_bus_ver3_user_dump_info,
                             v225,
                             4,
                             "VFE_BUS_CLIENT.%s.%d:",
                             v8 + 128,
                             *(unsigned int *)(*(_QWORD *)(v221 + 16) + 8LL),
                             v168,
                             v373);
                    if ( v224 )
                    {
LABEL_386:
                      v169 = *(unsigned int *)(v11 + 8);
                      out_res_mid_info = v224;
                      v170 = "VFE:%u BUS VER3: Info dump failed, rc: %d";
                      v171 = 3344;
                      goto LABEL_301;
                    }
                    LODWORD(v35) = *(_DWORD *)(v221 + 32);
                  }
                  if ( (unsigned int)v35 > 2 )
                    goto LABEL_666;
                }
              }
            }
          }
          else if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_vfe_bus_ver3_user_dump",
              3324,
              "VFE:%u BUS VER3: path inactive res ID: %d, continuing",
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v220 + v218 + 4));
          }
          ++v219;
          out_res_mid_info = 0;
          v218 += 152;
          if ( v219 >= *(unsigned int *)(v11 + 34732) )
            goto LABEL_18;
        }
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_vfe_bus_ver3_user_dump",
        3306,
        "VFE:%u  BUS powered down",
        *(_DWORD *)(a1 + 8));
      goto LABEL_17;
    case 0x4Bu:
      if ( *(_BYTE *)(a1 + 34665) == 1 )
      {
        out_res_mid_info = 0;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_mc_ctxt_sel",
            5092,
            "Skipping ctxt sel for IFE LITE");
          out_res_mid_info = 0;
        }
      }
      else
      {
        v207 = *(_QWORD *)(a1 + 80);
        v208 = **(_DWORD **)(a3 + 40);
        v209 = v208 << *(_DWORD *)(v207 + 88);
        LODWORD(v396[0]) = *(_DWORD *)(v207 + 16) + *(_DWORD *)a1;
        HIDWORD(v396[0]) = v209;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_mc_ctxt_sel",
            5101,
            "CTXT_SEL updated with ctxt_id: %u, val: 0x%x",
            v208,
            v209);
        v210 = *(_QWORD *)(v11 + 88);
        v211 = *(__int64 (__fastcall **)(_QWORD))(v210 + 24);
        if ( *((_DWORD *)v211 - 1) != 2010610996 )
          __break(0x8228u);
        v212 = 4 * v211(1);
        if ( v212 > *(_DWORD *)(v10 + 24) )
        {
          v213 = "cam_vfe_bus_ver3_mc_ctxt_sel";
          v214 = "Failed! Buf size:%d insufficient, expected size:%d";
          v215 = 5110;
          goto LABEL_630;
        }
        v216 = *(void (__fastcall **)(__int64, __int64, unsigned __int64 *))(v210 + 120);
        v217 = *(_QWORD *)(v10 + 16);
        if ( *((_DWORD *)v216 - 1) != -1401492769 )
          __break(0x8228u);
        v216(v217, 1, v396);
        out_res_mid_info = 0;
        *(_DWORD *)(v10 + 28) = v212;
      }
      goto LABEL_18;
    case 0x4Du:
      v29 = *(_DWORD *)(a3 + 8);
      if ( (unsigned int)(v29 - 200) >= 2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_irq_inject",
          5146,
          "Invalid reg_unit %d",
          v29);
        goto LABEL_17;
      }
      v181 = *(_QWORD *)(a1 + 34984);
      v182 = *(_QWORD *)(v181 + 136) + 28LL * (unsigned int)(v29 - 200);
      if ( v182 )
      {
        v183 = *(_QWORD *)(a1 + 72);
        cam_io_w_mb(*(unsigned int *)(a3 + 12), *(_QWORD *)(v183 + 288) + *(unsigned int *)(v182 + 12));
        cam_io_w_mb(16, *(_QWORD *)(v183 + 288) + *(unsigned int *)(v181 + 144));
        v184 = *(unsigned int *)(v10 + 12);
        v185 = *(unsigned int *)(v182 + 12);
        v186 = "cam_vfe_bus_ver3_irq_inject";
        v187 = "Injected : irq_mask %#x set_reg_offset %#x";
        v188 = 8;
        v189 = 3;
        v190 = 5162;
        goto LABEL_338;
      }
      v25 = "cam_vfe_bus_ver3_irq_inject";
      v23 = "Invalid inject_reg";
      v24 = 3;
      v26 = 5152;
      goto LABEL_16;
    case 0x4Eu:
      v80 = *(_DWORD *)(a3 + 8);
      v81 = v80 - 200;
      if ( v80 - 200 < 0 || (v82 = *(_QWORD *)(a1 + 34984), v81 >= *(_DWORD *)(v82 + 8720)) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          2,
          "cam_vfe_bus_ver3_dump_irq_desc",
          5191,
          "Invalid reg_unit %d",
          v80);
        goto LABEL_17;
      }
      v83 = *(_QWORD *)(v82 + 8728) + 768LL * v81;
      v84 = scnprintf(*(_QWORD *)(a3 + 32), 1500, "Printing executable IRQ for hw_type: VFE reg_unit: %d\n", v80);
      for ( i = 0; i != 768; i += 24 )
      {
        v86 = *(_DWORD *)(v83 + i);
        if ( !v86 )
          goto LABEL_642;
        v87 = scnprintf(
                *(_QWORD *)(v10 + 32) + v84,
                1500 - v84,
                "%#12x : %s - %s\n",
                v86,
                *(const char **)(v83 + i + 8),
                *(const char **)(v83 + i + 16));
        out_res_mid_info = 0;
        v84 += v87;
      }
      goto LABEL_18;
    case 0x50u:
      v172 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v172 || !*(_QWORD *)(*(_QWORD *)(v172 + 16) + 88LL) )
      {
        v25 = "cam_vfe_bus_ver3_update_ubwc_config_v3";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 4560;
        goto LABEL_16;
      }
      if ( !*(_DWORD *)(v172 + 32) )
        goto LABEL_642;
      v35 = *(_QWORD *)(a3 + 40);
      v173 = 0;
      v174 = (int *)(v35 + 72);
      while ( 2 )
      {
        if ( v173 == 2 )
          goto LABEL_666;
        v177 = *(_QWORD *)(v172 + 40 + 8 * v173);
        v10 = *(_QWORD *)(v177 + 24);
        if ( !*(_QWORD *)(*(_QWORD *)(v10 + 8) + 88LL) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_update_ubwc_config_v3",
            4576,
            "VFE:%u No UBWC register to configure.",
            *(_DWORD *)(*(_QWORD *)(v172 + 16) + 8LL));
          goto LABEL_17;
        }
        LODWORD(v9) = *(_DWORD *)(v10 + 120);
        if ( ((*(_QWORD *)(*(_QWORD *)(v12 + 2216) + 8928LL) >> v9) & 1) == 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_vfe_bus_ver3_update_ubwc_config_v3",
            4585,
            "VFE:%u UBWC config not supported for client: %s",
            *(_DWORD *)(*(_QWORD *)(v172 + 16) + 8LL),
            (const char *)(v177 + 128));
          goto LABEL_17;
        }
        v11 = (unsigned __int64)(v174 - 17);
        if ( (*(_BYTE *)(v172 + 133) & 1) == 0 && *(_BYTE *)(v172 + 134) != 1 || (v8 = *(_QWORD *)(v10 + 64)) == 0 )
        {
          v175 = v10 + 72;
          v176 = (unsigned __int8 *)(v10 + 160);
LABEL_307:
          cam_vfe_bus_ver3_update_wm_ubwc_data(v10, v175, v174 - 17, *v176);
          goto LABEL_308;
        }
        v178 = *v174;
        if ( (*v174 & 1) != 0 )
        {
          cam_vfe_bus_ver3_update_wm_ubwc_data(v10, v8 + 36, v174 - 17, *(unsigned __int8 *)(v8 + 76));
          v178 = *v174;
          if ( (*v174 & 2) == 0 )
          {
LABEL_317:
            if ( (v178 & 4) != 0 )
              goto LABEL_321;
            goto LABEL_308;
          }
        }
        else if ( (v178 & 2) == 0 )
        {
          goto LABEL_317;
        }
        cam_vfe_bus_ver3_update_wm_ubwc_data(
          v10,
          *(_QWORD *)(v10 + 64) + 116LL,
          v174 - 17,
          *(unsigned __int8 *)(*(_QWORD *)(v10 + 64) + 156LL));
        if ( (*v174 & 4) != 0 )
        {
LABEL_321:
          v179 = *(_QWORD *)(v10 + 64);
          v175 = v179 + 196;
          v176 = (unsigned __int8 *)(v179 + 236);
          goto LABEL_307;
        }
LABEL_308:
        v35 = *(unsigned int *)(v172 + 32);
        ++v173;
        out_res_mid_info = 0;
        v174 += 18;
        if ( v173 >= v35 )
          goto LABEL_18;
        continue;
      }
    case 0x51u:
      v30 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
      if ( !v30 || !*(_QWORD *)(*(_QWORD *)(v30 + 16) + 88LL) || (v31 = *(unsigned int **)(a3 + 40)) == nullptr )
      {
        v25 = "cam_vfe_bus_ver3_update_wm_config_v2";
        v23 = "Invalid data";
        v24 = 3;
        v26 = 4696;
        goto LABEL_16;
      }
      if ( !*(_DWORD *)(v30 + 32) )
        goto LABEL_642;
      v32 = 0;
      v33 = v30 + 40;
      _X28 = v396;
      v10 = 80;
      v35 = *(_QWORD *)(v30 + 24) + 0x8000LL;
      v380 = v35;
      while ( 1 )
      {
        v8 = v31[12];
        v396[0] = v8;
        if ( v32 == 2 )
          goto LABEL_666;
        v36 = *(_QWORD *)(*(_QWORD *)(v33 + 8 * v32) + 24LL);
        v37 = *(_DWORD **)(*(_QWORD *)v36 + 80LL);
        if ( *(_BYTE *)(v30 + 133) == 1 )
        {
          if ( !(_DWORD)v8 )
          {
            v17 = v31[2];
            if ( (unsigned int)v17 < 3 )
            {
LABEL_657:
              v17 = *(unsigned int *)(v36 + 120);
              v164 = "cam_vfe_bus_ver3_update_wm_config_v2";
              v161 = "VFE:%u WM:%d config data is NULL";
              v162 = *(unsigned int *)(*(_QWORD *)(v30 + 16) + 8LL);
              v160 = 3;
              v163 = 1;
              v165 = 4733;
            }
            else
            {
LABEL_656:
              v164 = "cam_vfe_bus_ver3_update_wm_config_v2";
              v161 = "VFE:%u Invalid wm_mode: 0x%X WM:%d";
              v160 = 3;
              v162 = *(unsigned int *)(*(_QWORD *)(v30 + 16) + 8LL);
              v163 = 1;
              v165 = 4727;
              LODWORD(v372) = *(_DWORD *)(v36 + 120);
            }
LABEL_326:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64))cam_print_log)(
              v160,
              8,
              v163,
              v164,
              v165,
              v161,
              v162,
              v17,
              v372);
LABEL_17:
            out_res_mid_info = -22;
            goto LABEL_18;
          }
          do
          {
            v38 = v31[12];
            v39 = __clz(__rbit32(v38));
            if ( v38 )
              v17 = v39;
            else
              v17 = 0xFFFFFFFFLL;
            if ( !v38 || (int)v17 >= 3 )
            {
              v164 = "cam_vfe_bus_ver3_update_wm_config_v2";
              v161 = "VFE[%u] Invalid context id received %d";
              v160 = 3;
              v162 = *(unsigned int *)(*(_QWORD *)(v30 + 16) + 8LL);
              v163 = 1;
              v165 = 4712;
              goto LABEL_326;
            }
            __asm { PRFM            #0x11, [X28] }
            do
              v46 = __ldxr(v396);
            while ( __stxr(v46 & ~(1LL << v39), v396) );
            v40 = *(_QWORD *)(v36 + 64) + 80LL * v39;
            *(_BYTE *)(v40 + 32) = 1;
          }
          while ( v396[0] );
        }
        else
        {
          v40 = v36 + 16;
        }
        v17 = v31[2];
        if ( (unsigned int)v17 > 2 )
          goto LABEL_656;
        if ( !v40 )
          goto LABEL_657;
        *(_DWORD *)v40 = v31[5];
        v11 = v31[2];
        v47 = *(_DWORD *)(v36 + 112);
        if ( (_DWORD)v11 != v47 )
          *(_DWORD *)(v36 + 112) = v11;
        LODWORD(v9) = v31[6] << v37[30];
        v8 = (unsigned int)v9 | (v31[2] << v37[24]);
        if ( v31[14] )
          v8 = (1 << v37[28]) | (unsigned int)v8;
        *(_DWORD *)(v40 + 28) = v8;
        if ( *(_BYTE *)(v36 + 164) == 1 )
        {
          LODWORD(v35) = *(_DWORD *)(v36 + 120);
          if ( (unsigned int)v35 > 0x1F )
            goto LABEL_666;
          v9 = *(_QWORD *)(v380 + 2216);
          *(_DWORD *)(v40 + 28) = *(_DWORD *)(v9 + 240LL * (unsigned int)v35 + 664) | v8;
        }
        *(_DWORD *)(v40 + 4) = v31[4] >> (v32 == 1);
        *(_DWORD *)(v40 + 16) = v31[7];
        *(_BYTE *)(v36 + 163) = 0;
        v48 = v31[10];
        if ( v48 )
        {
          if ( *(_DWORD *)(v40 + 12) == v48 )
          {
            LOBYTE(v48) = 0;
          }
          else
          {
            *(_DWORD *)(v40 + 12) = v48;
            v49 = cam_vfe_bus_ver3_get_packer_fmt(v31[10], *(unsigned int *)(v36 + 120));
            v50 = *(_DWORD *)(v36 + 28);
            if ( v50 <= 0x31 && ((1LL << v50) & 0x200000005E000LL) != 0 )
              v49 |= 1 << *(_DWORD *)(v380 + 1948);
            v33 = v30 + 40;
            LOBYTE(v48) = 1;
            *(_DWORD *)(v40 + 8) = v49;
            *(_BYTE *)(v36 + 163) = 1;
          }
        }
        v51 = v48 ^ 1;
        if ( (_DWORD)v11 != v47 )
          v51 = 0;
        if ( (v51 & 1) == 0 && *(_DWORD *)(v30 + 8) <= 4u )
        {
          cam_vfe_bus_ver3_config_rdi_wm(v36);
          v33 = v30 + 40;
        }
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v52 = "N";
          if ( (_DWORD)v11 == v47 )
            v53 = "N";
          else
            v53 = "Y";
          if ( *(_BYTE *)(v36 + 163) )
            v52 = "Y";
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_update_wm_config_v2",
            4788,
            "VFE:%u WM:%d %s update_mode:%s update_fmt:%s en_cfg:0x%X height:%d width:%d stride:%d pack_fmt:%d ctxt_mask %u",
            *(_DWORD *)(*(_QWORD *)(v30 + 16) + 8LL),
            *(_DWORD *)(v36 + 120),
            (const char *)(*(_QWORD *)(v33 + 8 * v32) + 128LL),
            v53,
            v52,
            *(_DWORD *)(v40 + 28),
            *(_DWORD *)(v40 + 4),
            *(_DWORD *)v40,
            *(_DWORD *)(v40 + 16),
            *(_DWORD *)(v40 + 8),
            v31[12]);
          v33 = v30 + 40;
        }
        v35 = *(unsigned int *)(v30 + 32);
        ++v32;
        out_res_mid_info = 0;
        if ( v32 >= v35 )
          goto LABEL_18;
      }
    case 0x54u:
      v58 = *(unsigned __int8 *)(a1 + 34672);
      v395 = 0;
      if ( v58 != 1 )
        goto LABEL_642;
      memset(v396, 0, 256);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_read_rst_perf_cntrs",
          5472,
          "IFE%u Checking perf count status",
          *(_DWORD *)(a1 + 8));
      v59 = *(_QWORD *)(v11 + 80);
      ++*(_DWORD *)(v11 + 34724);
      if ( !*(_DWORD *)(v59 + 160) )
        goto LABEL_642;
      v10 = 0;
      v60 = 0;
      while ( 1 )
      {
        v61 = 8 * v10;
        while ( 1 )
        {
          v35 = (unsigned int)cam_io_r_mb(*(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(v59 + 164)) >> v10;
          if ( (v35 & 1) != 0 )
            break;
          v59 = *(_QWORD *)(v11 + 80);
          ++v10;
          v61 += 8;
          if ( v10 >= *(unsigned int *)(v59 + 160) )
          {
            if ( (v60 & 1) == 0 )
              goto LABEL_642;
LABEL_365:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              3,
              "cam_vfe_bus_ver3_read_rst_perf_cntrs",
              5494,
              "IFE%u Frame: %u Perf counters %s",
              *(_DWORD *)(v11 + 8),
              *(_DWORD *)(v11 + 34724),
              (const char *)v396);
            goto LABEL_642;
          }
        }
        if ( v10 >= 8 )
          goto LABEL_666;
        v62 = cam_io_r_mb(*(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + v61 + 172));
        cam_io_w_mb(
          *(unsigned int *)(v11 + 34632 + 4 * v10),
          *(_QWORD *)(v11 + 16) + *(_QWORD *)v11 + *(unsigned int *)(*(_QWORD *)(v11 + 80) + v61 + 168));
        cam_print_to_buffer((__int64)v396, 0x100u, &v395, 3u, 8u, "cnt%d: 0x%x ", (unsigned int)v10, v62, v372);
        v59 = *(_QWORD *)(v11 + 80);
        ++v10;
        v60 = 1;
        if ( v10 >= *(unsigned int *)(v59 + 160) )
          goto LABEL_365;
      }
    default:
      if ( (unsigned int)__ratelimit(&cam_vfe_bus_ver3_process_cmd__rs_145, "cam_vfe_bus_ver3_process_cmd") )
        v160 = 3;
      else
        v160 = 2;
      v161 = "VFE:%u Invalid camif process command:%d";
      v162 = *(unsigned int *)(*(_QWORD *)(v11 + 16) + 4LL);
      v163 = 1;
      v164 = "cam_vfe_bus_ver3_process_cmd";
      v165 = 5699;
      v17 = a2;
      goto LABEL_326;
  }
}
