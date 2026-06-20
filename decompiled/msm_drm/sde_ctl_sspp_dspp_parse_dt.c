__int64 __fastcall sde_ctl_sspp_dspp_parse_dt(__int64 a1, int *a2)
{
  unsigned __int64 dt_props; // x0
  unsigned __int64 v5; // x22
  int v6; // w8
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x20
  int v9; // w8
  unsigned __int64 v10; // x19
  unsigned __int64 v11; // x23
  int *v12; // x25
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x26
  int *v17; // x9
  int v18; // w8
  unsigned int v19; // w8
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  unsigned __int64 v28; // x9
  unsigned __int64 v35; // x9
  unsigned __int64 v38; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v47; // x9
  unsigned int *v48; // x23
  __int64 v49; // x25
  __int64 v50; // x27
  unsigned __int64 v51; // x0
  unsigned __int64 v52; // x21
  int v53; // w3
  __int64 v54; // x19
  __int64 v55; // x20
  __int64 v56; // x0
  __int64 v57; // x8
  unsigned __int64 v58; // x20
  unsigned int v59; // w25
  const char *v60; // x26
  __int64 v61; // x26
  _DWORD *v62; // x8
  int v63; // w9
  unsigned __int64 v64; // x9
  unsigned __int64 v65; // x10
  __int64 v66; // x9
  unsigned int v67; // w9
  __int64 v68; // x9
  int v69; // w9
  __int64 v70; // x19
  int v71; // w3
  unsigned int *v72; // x9
  __int64 v73; // x8
  __int64 v74; // x23
  __int64 v75; // x8
  int *v76; // x10
  __int64 v77; // x9
  __int64 v78; // x11
  __int64 v79; // x11
  int *v80; // x11
  __int64 v81; // x11
  __int64 v82; // x6
  unsigned int v83; // w8
  unsigned int v84; // w8
  unsigned int v85; // w8
  unsigned __int64 v88; // x10
  unsigned __int64 v91; // x10
  unsigned __int64 v94; // x10
  unsigned __int64 v97; // x10
  unsigned __int64 v100; // x10
  unsigned __int64 v103; // x10
  unsigned __int64 v106; // x10
  unsigned __int64 v109; // x9
  unsigned __int64 v112; // x9
  unsigned __int64 v115; // x9
  unsigned __int64 v118; // x9
  unsigned __int64 v121; // x9
  unsigned __int64 v124; // x11
  unsigned __int64 v127; // x10
  unsigned __int64 v130; // x10
  unsigned __int64 v133; // x10
  unsigned __int64 v136; // x10
  unsigned __int64 v139; // x9
  unsigned __int64 v142; // x9
  __int64 child_by_name; // x0
  __int64 v145; // x20
  __int64 v146; // x24
  __int64 next_child; // x0
  __int64 v148; // x1
  unsigned int v149; // w19
  __int64 v150; // x0
  __int64 v151; // x21
  unsigned __int64 v152; // x0
  __int64 v153; // x3
  __int64 v154; // x19
  unsigned int v155; // w20
  int *v156; // x28
  int *v157; // x27
  __int64 v158; // x23
  int v159; // w8
  int v160; // w8
  __int64 v161; // x21
  char v162; // w9
  const char **v163; // x8
  const char *v164; // x19
  char v165; // w25
  __int64 v166; // x20
  unsigned int v167; // w8
  unsigned int v168; // w9
  __int64 v169; // x20
  unsigned int v170; // w8
  unsigned int v171; // w9
  __int64 v172; // x20
  unsigned int v173; // w8
  unsigned int v174; // w9
  __int64 v175; // x20
  unsigned int v176; // w8
  unsigned int v177; // w9
  __int64 v178; // x20
  unsigned int v179; // w8
  unsigned int v180; // w9
  __int64 v181; // x20
  unsigned int v182; // w8
  unsigned int v183; // w9
  __int64 v184; // x20
  unsigned int v185; // w8
  unsigned int v186; // w9
  __int64 v187; // x20
  unsigned int v188; // w8
  unsigned int v189; // w9
  __int64 v190; // x20
  unsigned int v191; // w8
  unsigned int v192; // w9
  unsigned __int64 v195; // x9
  unsigned __int64 v198; // x9
  unsigned __int64 v201; // x9
  unsigned __int64 v204; // x9
  unsigned __int64 v207; // x9
  unsigned __int64 v210; // x9
  unsigned __int64 v213; // x9
  unsigned __int64 v216; // x9
  unsigned __int64 v219; // x9
  unsigned __int64 v220; // x8
  unsigned __int64 v221; // x9
  __int64 v222; // x8
  unsigned int v223; // w9
  unsigned int v224; // w8
  __int64 v225; // x19
  int v226; // w8
  const char *v227; // x9
  unsigned int v228; // w8
  unsigned int v229; // w9
  unsigned int v230; // w8
  unsigned int v231; // w9
  unsigned int v232; // w8
  unsigned int v233; // w9
  unsigned int v234; // w8
  unsigned int v235; // w9
  unsigned int v236; // w8
  unsigned int v237; // w9
  unsigned int v238; // w8
  unsigned int v239; // w9
  __int64 v240; // x8
  unsigned int v241; // w8
  __int64 v242; // x14
  int v243; // w8
  int v244; // w9
  int v245; // w10
  __int64 v246; // x11
  __int64 v247; // x12
  __int64 v248; // x13
  unsigned __int64 v251; // x9
  unsigned __int64 v254; // x9
  unsigned __int64 v257; // x9
  unsigned __int64 v260; // x9
  unsigned __int64 v263; // x10
  unsigned __int64 v266; // x9
  unsigned __int64 v269; // x9
  unsigned __int64 v272; // x9
  unsigned __int64 v275; // x9
  unsigned __int64 v278; // x9
  unsigned __int64 v281; // x9
  unsigned __int64 v284; // x9
  unsigned __int64 v287; // x9
  unsigned __int64 v290; // x9
  void *v291; // x0
  const char *v292; // x20
  __int64 v293; // x20
  unsigned int v294; // w8
  __int64 v295; // x27
  __int64 v296; // x0
  __int64 v297; // x21
  __int64 v298; // x0
  __int64 v299; // x1
  unsigned int v300; // w19
  unsigned int v301; // w28
  __int64 v302; // x0
  __int64 v303; // x22
  unsigned __int64 v304; // x0
  unsigned __int64 v305; // x20
  __int64 v306; // x3
  __int64 v307; // x21
  unsigned int v308; // w20
  int *v309; // x22
  __int64 v310; // x19
  __int64 v311; // x8
  const char *v312; // x8
  int v313; // w8
  __int64 v314; // x23
  unsigned int v315; // w25
  const char **v316; // x9
  char v317; // w8
  unsigned __int64 v320; // x9
  unsigned int v321; // w8
  unsigned int v322; // w9
  const char *v323; // x27
  char v324; // w28
  __int64 v325; // x20
  unsigned int v326; // w8
  unsigned int v327; // w9
  __int64 v328; // x20
  unsigned int v329; // w8
  unsigned int v330; // w9
  int v331; // w8
  __int64 v332; // x0
  unsigned int v333; // w8
  unsigned int v334; // w9
  __int64 v335; // x20
  unsigned int v336; // w8
  unsigned int v337; // w9
  __int64 v338; // x20
  unsigned int v339; // w8
  unsigned int v340; // w9
  __int64 v341; // x20
  unsigned int v342; // w8
  unsigned int v343; // w9
  __int64 v344; // x20
  unsigned int v345; // w8
  unsigned int v346; // w9
  __int64 v347; // x20
  unsigned int v348; // w8
  unsigned int v349; // w9
  __int64 v350; // x20
  unsigned int v351; // w8
  unsigned int v352; // w9
  __int64 v353; // x20
  unsigned int v354; // w8
  unsigned int v355; // w9
  __int64 v356; // x20
  unsigned int v357; // w8
  unsigned int v358; // w9
  __int64 v359; // x20
  unsigned __int64 v362; // x9
  unsigned __int64 v365; // x9
  unsigned __int64 v368; // x9
  unsigned __int64 v371; // x9
  unsigned __int64 v374; // x9
  unsigned __int64 v377; // x9
  unsigned __int64 v380; // x9
  unsigned __int64 v383; // x9
  unsigned __int64 v386; // x9
  unsigned __int64 v389; // x9
  unsigned __int64 v392; // x9
  unsigned __int64 v395; // x9
  unsigned __int64 v398; // x9
  unsigned __int64 v401; // x9
  const char *v402; // x21
  __int64 v403; // x21
  int *v404; // x20
  int v405; // w9
  void *v406; // x0
  __int64 v407; // [xsp+10h] [xbp-F0h]
  unsigned int v408; // [xsp+24h] [xbp-DCh]
  __int64 v409; // [xsp+28h] [xbp-D8h]
  __int64 v410; // [xsp+30h] [xbp-D0h]
  unsigned int v411; // [xsp+30h] [xbp-D0h]
  const char *v412; // [xsp+38h] [xbp-C8h]
  __int64 v413; // [xsp+38h] [xbp-C8h]
  __int64 v414; // [xsp+40h] [xbp-C0h]
  int *v415; // [xsp+48h] [xbp-B8h]
  int *v416; // [xsp+B8h] [xbp-48h]
  unsigned int *v417; // [xsp+C0h] [xbp-40h]
  unsigned int v418; // [xsp+C8h] [xbp-38h]
  const char *v419; // [xsp+D0h] [xbp-30h] BYREF
  __int16 v420; // [xsp+DCh] [xbp-24h] BYREF
  const char *v421; // [xsp+E0h] [xbp-20h] BYREF
  _QWORD v422[3]; // [xsp+E8h] [xbp-18h] BYREF

  v422[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v421) = 0;
  dt_props = sde_get_dt_props(a1, 2, &ctl_hyp_prop, 2, &v421);
  v5 = dt_props;
  if ( dt_props <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (_DWORD)v421 )
    {
      a2[1513] = **(_DWORD **)(dt_props + 320);
      v6 = *(_DWORD *)(*(_QWORD *)(dt_props + 320) + 768LL);
      a2[1512] = 1;
      a2[1514] = v6;
      *((_QWORD *)a2 + 754) = 0x7079685F6C7463LL;
      if ( dt_props )
      {
        kvfree(*(_QWORD *)(dt_props + 320));
        kvfree(v5);
      }
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "invalid ctl hyp dt entry\n");
    }
    v416 = a2 + 5120;
    LODWORD(v419) = 0;
    v7 = sde_get_dt_props(a1, 3, &ctl_prop, 3, &v419);
    v8 = v7;
    v417 = (unsigned int *)a2;
    v414 = a1;
    if ( v7 > 0xFFFFFFFFFFFFF000LL )
    {
      LODWORD(v5) = v7;
      goto LABEL_189;
    }
    v9 = (int)v419;
    a2[1362] = (int)v419;
    if ( v9 )
    {
      v10 = 0;
      v11 = 0;
      v12 = (int *)(v417 + 1372);
      do
      {
        v421 = nullptr;
        if ( v10 == 156 )
          goto LABEL_575;
        v16 = v11 + 1;
        v17 = (int *)&v417[v10];
        v17[1369] = *(_DWORD *)(*(_QWORD *)(v8 + 320) + 4 * v11);
        v18 = *(_DWORD *)(*(_QWORD *)(v8 + 320) + 768LL);
        v17[1368] = v11 + 1;
        v17[1370] = v18;
        snprintf((char *)&v417[v10 + 1364], 0x10u, "ctl_%u", v11);
        of_property_read_string_helper(v414, off_A398, &v421, 1, (unsigned int)v11);
        if ( v421 && !strcmp(v421, "primary") )
        {
          _X8 = (unsigned __int64 *)&v12[v10];
          __asm { PRFM            #0x11, [X8] }
          do
            v41 = __ldxr(_X8);
          while ( __stxr(v41 | 8, _X8) );
        }
        if ( v11 <= 1 )
        {
          if ( v417[7] == 256 )
          {
            if ( v10 * 4 )
              goto LABEL_20;
LABEL_47:
            _X8 = (unsigned __int64 *)&v12[v10];
            __asm { PRFM            #0x11, [X8] }
            do
              v44 = __ldxr(_X8);
            while ( __stxr(v44 | 4, _X8) );
            goto LABEL_20;
          }
          _X8 = (unsigned __int64 *)&v12[v10];
          __asm { PRFM            #0x11, [X8] }
          do
            v35 = __ldxr(_X8);
          while ( __stxr(v35 | 2, _X8) );
          if ( !(v10 * 4) )
            goto LABEL_47;
        }
LABEL_20:
        if ( v417[7] == 256 )
        {
          _X8 = (unsigned __int64 *)&v12[v10];
          __asm { PRFM            #0x11, [X8] }
          do
            v22 = __ldxr(_X8);
          while ( __stxr(v22 | 0x10, _X8) );
        }
        if ( (v416[374] & 0xFFFFFFFC) == 0x100 )
        {
          _X8 = (unsigned __int64 *)&v12[v10];
          __asm { PRFM            #0x11, [X8] }
          do
            v25 = __ldxr(_X8);
          while ( __stxr(v25 | 0x20, _X8) );
        }
        if ( *v417 >> 28 >= 7 )
        {
          _X8 = (unsigned __int64 *)&v12[v10];
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stxr(v28 | 0x40, _X8) );
          if ( *v417 >> 30 == 3 )
          {
            _X8 = (unsigned __int64 *)&v12[v10];
            __asm { PRFM            #0x11, [X8] }
            do
              v38 = __ldxr(_X8);
            while ( __stxr(v38 | 0x800, _X8) );
            v19 = *v417;
            if ( *v417 >> 30 != 3 )
              goto LABEL_31;
            if ( v417[1513] )
            {
              _X8 = (unsigned __int64 *)&v12[v10];
              __asm { PRFM            #0x11, [X8] }
              do
                v47 = __ldxr(_X8);
              while ( __stxr(v47 | 0x1000, _X8) );
            }
          }
        }
        v19 = *v417;
LABEL_31:
        if ( v19 >> 28 >= 0xB )
        {
          _X8 = (unsigned __int64 *)&v12[v10];
          __asm { PRFM            #0x11, [X8] }
          do
            v15 = __ldxr(_X8);
          while ( __stxr(v15 | 0x400, _X8) );
        }
        v10 += 12LL;
        ++v11;
      }
      while ( v16 < (unsigned int)v419 );
    }
    if ( v8 )
    {
      kvfree(*(_QWORD *)(v8 + 320));
      kvfree(v8);
    }
    v48 = v417;
    v49 = v414;
    if ( v417[3] == 1 )
      v50 = *((_QWORD *)v417 + 2487);
    else
      v50 = 0;
    v421 = nullptr;
    LODWORD(v419) = 0;
    v51 = sde_get_dt_props(v414, 16, &sspp_prop, 16, &v419);
    v52 = v51;
    if ( v51 >= 0xFFFFFFFFFFFFF001LL )
    {
      LODWORD(v5) = v51;
      goto LABEL_188;
    }
    v53 = (int)v419;
    if ( (int)v419 >= 13 )
    {
      printk(&unk_23FE65, "_sde_sspp_setup_cmn");
      LODWORD(v419) = 12;
      v417[1520] = 12;
    }
    else
    {
      v417[1520] = (unsigned int)v419;
      if ( v53 < 1 )
      {
        LODWORD(v5) = 0;
        if ( !v51 )
          goto LABEL_188;
        goto LABEL_187;
      }
    }
    v54 = 0;
    v55 = 1534;
    _ReadStatusReg(SP_EL0);
    do
    {
      if ( v54 == 13 )
        goto LABEL_575;
      v56 = _kvmalloc_node_noprof(1328, 0, 3520, 0xFFFFFFFFLL);
      if ( !v56 )
      {
        v48 = v417;
        LODWORD(v5) = -12;
        v49 = v414;
        if ( !v52 )
          goto LABEL_188;
        goto LABEL_187;
      }
      v57 = (int)v419;
      ++v54;
      *(_QWORD *)&v417[v55] = v56;
      v55 += 18;
    }
    while ( v54 < v57 );
    if ( (int)v57 >= 1 )
    {
      v48 = v417;
      v58 = 0;
      v59 = 0;
      v418 = 0;
      while ( 1 )
      {
        of_property_read_string_helper(v414, off_A3E0, &v421, 1, (unsigned int)v58);
        v60 = v421;
        if ( !strcmp(v421, "vig") )
        {
          if ( v50 && *(_BYTE *)v50 == 1 && v59 >= *(_DWORD *)(v50 + 4) )
            goto LABEL_74;
          ++v59;
        }
        else if ( !strcmp(v60, "dma") )
        {
          if ( v50 && *(_BYTE *)v50 == 1 && v418 >= *(_DWORD *)(v50 + 8) )
            goto LABEL_74;
          ++v418;
        }
        if ( v58 >= 0xD )
          goto LABEL_575;
        v61 = (__int64)&v417[18 * v58 + 1522];
        v62 = *(_DWORD **)(v61 + 48);
        *v62 = v416[268];
        if ( *((_BYTE *)v416 + 1536) == 1 )
        {
          _X9 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X9] }
          do
            v94 = __ldxr(_X9);
          while ( __stxr(v94 | 0x400000000LL, _X9) );
        }
        v63 = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58 + 7680);
        v62[9] = v63;
        if ( v63 )
        {
          v64 = v48[6];
          if ( (_DWORD)v64 )
          {
            v65 = v64 >> 6;
            v66 = 1LL << v64;
            _X10 = (unsigned __int64 *)(v61 + 32 + 8 * v65);
            __asm { PRFM            #0x11, [X10] }
            do
              v124 = __ldxr(_X10);
            while ( __stxr(v124 | v66, _X10) );
          }
        }
        v62[17] = 1;
        _X9 = (unsigned __int64 *)(v61 + 32);
        __asm { PRFM            #0x11, [X9] }
        do
          v88 = __ldxr(_X9);
        while ( __stxr(v88 | 2, _X9) );
        if ( (*((_QWORD *)v48 + 2751) & 1) != 0 )
        {
          _X9 = (unsigned __int64 *)(v61 + 40);
          __asm { PRFM            #0x11, [X9] }
          do
            v97 = __ldxr(_X9);
          while ( __stxr(v97 | 0x20, _X9) );
        }
        v67 = v48[10];
        if ( v67 == 2 )
        {
          _X9 = (unsigned __int64 *)(v61 + 40);
          __asm { PRFM            #0x11, [X9] }
          do
            v130 = __ldxr(_X9);
          while ( __stxr(v130 | 8, _X9) );
          _X9 = (unsigned __int64 *)(v61 + 40);
          __asm { PRFM            #0x11, [X9] }
          do
            v133 = __ldxr(_X9);
          while ( __stxr(v133 | 0x10, _X9) );
        }
        else if ( v67 == 1 )
        {
          _X9 = (unsigned __int64 *)(v61 + 40);
          __asm { PRFM            #0x11, [X9] }
          do
            v127 = __ldxr(_X9);
          while ( __stxr(v127 | 8, _X9) );
        }
        if ( !v416[374] )
          break;
        _X9 = (unsigned __int64 *)(v61 + 40);
        __asm { PRFM            #0x11, [X9] }
        do
          v91 = __ldxr(_X9);
        while ( __stxr(v91 | 0x80, _X9) );
        if ( (unsigned int)v416[374] < 0x103 )
          break;
        _X9 = (unsigned __int64 *)(v61 + 40);
        __asm { PRFM            #0x11, [X9] }
        do
          v136 = __ldxr(_X9);
        while ( __stxr(v136 | 0x100, _X9) );
        if ( (*((_QWORD *)v48 + 2712) & 1) != 0 )
          goto LABEL_102;
LABEL_103:
        if ( (*((_QWORD *)v48 + 2751) & 0x2000000) != 0 )
        {
          _X9 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X9] }
          do
            v103 = __ldxr(_X9);
          while ( __stxr(v103 | 0x1000000, _X9) );
        }
        v68 = *((_QWORD *)v48 + 2751);
        v62[4] = 51200;
        LODWORD(v68) = ((unsigned int)v68 >> 9) & 4;
        v62[7] = v68;
        v62[8] = v68;
        if ( *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58 + 6912) == 1 )
        {
          _X9 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X9] }
          do
            v106 = __ldxr(_X9);
          while ( __stxr(v106 | 0x200, _X9) );
        }
        if ( *(_BYTE *)(v52 + 11) == 1 )
          v69 = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58 + 8448);
        else
          v69 = 2400000;
        v62[10] = v69;
        if ( *(_BYTE *)(v52 + 12) == 1 )
          v69 = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58 + 9216);
        v62[11] = v69;
        if ( (*((_QWORD *)v48 + 2751) & 0x4000000000LL) != 0 )
        {
          _X8 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v109 = __ldxr(_X8);
          while ( __stxr(v109 | 0x100000000LL, _X8) );
        }
        if ( *v48 >> 28 >= 9 )
        {
          _X8 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v112 = __ldxr(_X8);
          while ( __stxr(v112 | 0x200000000LL, _X8) );
        }
        if ( v48[5] >= 0x3005 )
        {
          _X8 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v115 = __ldxr(_X8);
          while ( __stxr(v115 | 0x80000000000LL, _X8) );
          _X8 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v118 = __ldxr(_X8);
          while ( __stxr(v118 | 0x100000000000LL, _X8) );
        }
        if ( *v48 >> 28 >= 0xD )
        {
          _X8 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v121 = __ldxr(_X8);
          while ( __stxr(v121 | 0x40000000000LL, _X8) );
        }
        v70 = *(_QWORD *)(v61 + 48);
        v71 = *(_DWORD *)(v61 + 16) - 1;
        *(_DWORD *)(v61 + 20) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58);
        *(_DWORD *)(v61 + 24) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 768LL);
        snprintf((char *)(v70 + 52), 0x10u, "sspp_src_%u", v71);
        if ( *(_DWORD *)(v61 + 60) >= 0x14u )
        {
          printk(&unk_249F33, "_sde_sspp_setup_cmn");
          LODWORD(v5) = -22;
          v49 = v414;
          if ( !v52 )
            goto LABEL_188;
LABEL_187:
          kvfree(*(_QWORD *)(v52 + 320));
          kvfree(v52);
          goto LABEL_188;
        }
        v72 = v48;
        *(_DWORD *)(v61 + 56) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58 + 2304);
        *(_DWORD *)(v70 + 76) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 768LL);
        v73 = *((_QWORD *)v48 + 2751);
        v74 = 8 * v58;
        if ( (v73 & 0x8000000000LL) == 0 )
        {
          v75 = v72[161];
          if ( (_DWORD)v75 )
          {
            v76 = (int *)(v417 + 222);
            v77 = 0;
            while ( v77 != 12 )
            {
              v78 = *(unsigned int *)(v61 + 60);
              if ( (unsigned int)v78 > 0x13 )
                break;
              v76[2 * v78 - 41] = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8 * v58 + 3328);
              v79 = *(unsigned int *)(v61 + 60);
              if ( (unsigned int)v79 > 0x13 )
                break;
              v80 = &v76[2 * v79];
              *(v80 - 40) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + v74 + 3332);
              *(v80 - 1) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + v74 + 4096);
              v81 = *(unsigned int *)(v61 + 60);
              if ( (unsigned int)v81 > 0x13 )
                break;
              ++v77;
              v76[2 * v81] = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8 * v58 + 4100);
              v76 += 100;
              if ( v75 == v77 )
                goto LABEL_127;
            }
LABEL_575:
            __break(0x5512u);
          }
LABEL_127:
          v72 = v417;
          if ( (_drm_debug & 4) != 0 )
          {
            v82 = *(unsigned int *)(v61 + 60);
            if ( (unsigned int)v82 > 0x13 )
              goto LABEL_575;
            _drm_dev_dbg(
              0,
              0,
              0,
              "xin:%d ram:%d clk%d:%x/%d\n",
              *(_DWORD *)(v61 + 56),
              *(_DWORD *)(v70 + 16),
              v82,
              v417[2 * v82 + 181],
              v417[2 * v82 + 182]);
            v72 = v417;
          }
        }
        v83 = v72[14];
        if ( v83 == 41 )
        {
          if ( *(_BYTE *)(v52 + 13) != 1 || *(_DWORD *)(v52 + 124) != 2 * (_DWORD)v419 )
          {
LABEL_73:
            v48 = v417;
            goto LABEL_74;
          }
          v85 = (_DWORD)v419 + v58;
          *(_DWORD *)(v70 + 1296) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58 + 9984);
          *(_DWORD *)(v70 + 1308) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8 * v58 + 11776);
          if ( v85 > 0x3F )
            goto LABEL_575;
          *(_DWORD *)(v70 + 1316) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8LL * v85 + 11776);
          *(_DWORD *)(v70 + 1312) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8 * v58 + 11780);
          if ( (unsigned int)((_DWORD)v419 + v58) > 0x3F )
            goto LABEL_575;
          v48 = v417;
          *(_DWORD *)(v70 + 1320) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8LL * (unsigned int)((_DWORD)v419 + v58) + 11780);
          _X8 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v139 = __ldxr(_X8);
          while ( __stxr(v139 | 0x20000000000LL, _X8) );
        }
        else
        {
          if ( v83 != 40
            || *(_BYTE *)(v52 + 13) != 1
            || *(_BYTE *)(v52 + 14) != 1
            || *(_DWORD *)(v52 + 124) != 2 * (_DWORD)v419 )
          {
            goto LABEL_73;
          }
          v84 = (_DWORD)v419 + v58;
          *(_DWORD *)(v70 + 1296) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 4 * v58 + 9984);
          *(_DWORD *)(v70 + 1300) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + v74 + 11008);
          *(_DWORD *)(v70 + 1308) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + v74 + 11776);
          if ( v84 > 0x3F )
            goto LABEL_575;
          *(_DWORD *)(v70 + 1316) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8LL * v84 + 11776);
          *(_DWORD *)(v70 + 1304) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + v74 + 11012);
          *(_DWORD *)(v70 + 1312) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + v74 + 11780);
          if ( (unsigned int)((_DWORD)v419 + v58) > 0x3F )
            goto LABEL_575;
          v48 = v417;
          *(_DWORD *)(v70 + 1320) = *(_DWORD *)(*(_QWORD *)(v52 + 320) + 8LL * (unsigned int)((_DWORD)v419 + v58) + 11780);
          _X8 = (unsigned __int64 *)(v61 + 32);
          __asm { PRFM            #0x11, [X8] }
          do
            v142 = __ldxr(_X8);
          while ( __stxr(v142 | 0x10000000000LL, _X8) );
        }
LABEL_74:
        if ( (__int64)++v58 >= (int)v419 )
          goto LABEL_186;
      }
      if ( (*((_QWORD *)v48 + 2712) & 1) == 0 )
        goto LABEL_103;
LABEL_102:
      _X9 = (unsigned __int64 *)(v61 + 40);
      __asm { PRFM            #0x11, [X9] }
      do
        v100 = __ldxr(_X9);
      while ( __stxr(v100 | 0x40, _X9) );
      goto LABEL_103;
    }
    v48 = v417;
LABEL_186:
    LODWORD(v5) = 0;
    v49 = v414;
    if ( v52 )
      goto LABEL_187;
LABEL_188:
    if ( !(_DWORD)v5 )
    {
      v421 = nullptr;
      v422[0] = 0;
      v419 = nullptr;
      child_by_name = of_get_child_by_name(v49, off_A458);
      if ( !child_by_name )
        goto LABEL_413;
      v145 = child_by_name;
      if ( v48[3] == 1 )
        v146 = *((_QWORD *)v48 + 2487);
      else
        v146 = 0;
      next_child = of_get_next_child(child_by_name, 0);
      if ( !next_child )
        goto LABEL_209;
      v148 = next_child;
      v149 = -1;
      do
      {
        v148 = of_get_next_child(v145, v148);
        ++v149;
      }
      while ( v148 );
      if ( v149 <= 0x7FFFFFFE )
      {
        if ( v149 + 1 >= 3 )
          printk(&unk_2663DE, "_sde_sspp_setup_vigs");
        v150 = of_get_next_child(v145, 0);
        if ( v150 )
        {
          v151 = v150;
          while ( 1 )
          {
            v152 = sde_get_dt_props(v151, 20, &vig_prop, 20, 0);
            v5 = v152;
            if ( v152 >= 0xFFFFFFFFFFFFF001LL )
            {
              v48 = v417;
              goto LABEL_408;
            }
            if ( (*(_BYTE *)v152 & 1) == 0 )
            {
              printk(&unk_21693A, "_sde_sspp_setup_vigs");
              goto LABEL_405;
            }
            v153 = **(unsigned int **)(v152 + 320);
            if ( (int)v153 >= 2 )
            {
              v291 = &unk_25B8FF;
              goto LABEL_404;
            }
            if ( (unsigned int)v153 > 1 )
              goto LABEL_575;
            if ( v422[v153 - 1] )
              break;
            v422[v153 - 1] = v152;
            v151 = of_get_next_child(v145, v151);
            if ( !v151 )
              goto LABEL_210;
          }
          v291 = &unk_213274;
LABEL_404:
          printk(v291, "_sde_sspp_setup_vigs");
LABEL_405:
          v48 = v417;
          if ( !v5 )
          {
LABEL_408:
            v292 = v421;
            if ( v421 )
            {
              kvfree(*((_QWORD *)v421 + 40));
              kvfree(v292);
            }
            v293 = v422[0];
            if ( v422[0] )
            {
              kvfree(*(_QWORD *)(v422[0] + 320LL));
              kvfree(v293);
            }
            if ( (_DWORD)v5 )
              goto LABEL_189;
LABEL_413:
            v294 = v48[3];
            v295 = 0;
            v421 = nullptr;
            v422[0] = 0;
            if ( v294 == 1 )
              v295 = *((_QWORD *)v48 + 2487);
            v419 = nullptr;
            v296 = of_get_child_by_name(v49, off_A470);
            if ( !v296 )
            {
              v301 = 0;
              goto LABEL_432;
            }
            v297 = v296;
            v298 = of_get_next_child(v296, 0);
            if ( v298 )
            {
              v299 = v298;
              v300 = -1;
              do
              {
                v299 = of_get_next_child(v297, v299);
                ++v300;
              }
              while ( v299 );
              v301 = v300 + 1;
              if ( v300 > 0x7FFFFFFE )
                goto LABEL_432;
              if ( v301 < 3 )
              {
                v302 = of_get_next_child(v297, 0);
                if ( v302 )
                {
                  v303 = v302;
                  while ( 1 )
                  {
                    v304 = sde_get_dt_props(v303, 15, &dma_prop, 15, 0);
                    v305 = v304;
                    if ( v304 >= 0xFFFFFFFFFFFFF001LL )
                    {
                      v48 = v417;
                      LODWORD(v5) = v304;
                      v305 = 0;
                      v402 = v421;
                      if ( v421 )
                        goto LABEL_558;
                      goto LABEL_559;
                    }
                    if ( (*(_BYTE *)v304 & 1) == 0 )
                    {
                      printk(&unk_25F74D, "_sde_sspp_setup_dmas");
                      goto LABEL_573;
                    }
                    v306 = **(unsigned int **)(v304 + 320);
                    if ( (int)v306 >= 2 )
                    {
                      v406 = &unk_274700;
                      goto LABEL_572;
                    }
                    if ( (unsigned int)v306 > 1 )
                      goto LABEL_575;
                    if ( v422[v306 - 1] )
                      break;
                    v422[v306 - 1] = v304;
                    v303 = of_get_next_child(v297, v303);
                    if ( !v303 )
                    {
                      v48 = v417;
                      if ( !v417[1520] )
                        goto LABEL_556;
LABEL_435:
                      v307 = 0;
                      v308 = 0;
                      v415 = (int *)(v48 + 1522);
                      v413 = v295;
                      v411 = v301;
                      while ( 2 )
                      {
                        if ( v307 == 13 )
                          goto LABEL_575;
                        v309 = &v415[18 * v307];
                        v310 = *((_QWORD *)v309 + 6);
                        of_property_read_string_helper(v49, off_A3E0, &v419, 1, (unsigned int)v307);
                        if ( strcmp(v419, "dma") )
                        {
                          v48 = v417;
                          goto LABEL_437;
                        }
                        v48 = v417;
                        if ( !v295 || *(_BYTE *)v295 != 1 || v308 < *(_DWORD *)(v295 + 8) )
                        {
                          *(_QWORD *)(v310 + 20) = 0x100000001LL;
                          v311 = *((_QWORD *)v417 + 2754);
                          *(_QWORD *)(v310 + 1224) = v311;
                          *(_QWORD *)(v310 + 1232) = v311;
                          v309[4] = v308 + 9;
                          v309[15] = v308 + 9;
                          snprintf((char *)v309, 0x10u, "sspp_%u", v308 + 8);
                          v309[16] = 1;
                          _X8 = (unsigned __int64 *)(v309 + 10);
                          __asm { PRFM            #0x11, [X8] }
                          do
                            v398 = __ldxr(_X8);
                          while ( __stxr(v398 | 2, _X8) );
                          if ( v416[278] == 8 )
                          {
                            _X8 = (unsigned __int64 *)(v309 + 10);
                            __asm { PRFM            #0x11, [X8] }
                            do
                              v401 = __ldxr(_X8);
                            while ( __stxr(v401 | 4, _X8) );
                            if ( (*(_BYTE *)(v310 + 1296) & 1) != 0 )
                            {
LABEL_446:
                              *(_QWORD *)(v310 + 1248) = *((_QWORD *)v417 + 2763);
                              v312 = v421;
                              if ( !v421 )
                              {
LABEL_452:
                                v313 = 512;
                                goto LABEL_453;
                              }
LABEL_450:
                              if ( v312[1] != 1 )
                                goto LABEL_452;
                              v313 = *(_DWORD *)(*((_QWORD *)v312 + 40) + 768LL);
LABEL_453:
                              *(_DWORD *)(v310 + 48) = v313;
                              v314 = 0;
                              v315 = v308 + 1;
                              v316 = &v421;
                              *(_DWORD *)(v310 + 304) = v301;
                              *(_DWORD *)(v310 + 380) = v301;
                              *(_DWORD *)(v310 + 456) = v301;
                              v317 = 1;
                              do
                              {
                                v323 = *v316;
                                v324 = v317;
                                if ( *v316 )
                                {
                                  if ( v323[2] == 1 )
                                  {
                                    v325 = v310 + 308 + 36 * v314;
                                    *(_DWORD *)(v325 + 16) = 15;
                                    *(_DWORD *)(v325 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v365 = __ldxr(_X8);
                                    while ( __stxr(v365 | 0x8000, _X8) );
                                    v326 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 1536LL);
                                    *(_DWORD *)(v325 + 20) = v326;
                                    v327 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v326 < v327 )
                                      v327 = 0;
                                    *(_DWORD *)(v325 + 28) = v326 - v327;
                                    snprintf((char *)v325, 0x10u, "%s%u", "sspp_dma_igc", (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v325 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 1540LL);
                                  }
                                  if ( v323[3] == 1 )
                                  {
                                    v328 = v310 + 384 + 36 * v314;
                                    *(_DWORD *)(v328 + 16) = 16;
                                    *(_DWORD *)(v328 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v368 = __ldxr(_X8);
                                    while ( __stxr(v368 | 0x10000, _X8) );
                                    v329 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 2304LL);
                                    *(_DWORD *)(v328 + 20) = v329;
                                    v330 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v329 < v330 )
                                      v330 = 0;
                                    *(_DWORD *)(v328 + 28) = v329 - v330;
                                    snprintf((char *)v328, 0x10u, "%s%u", "sspp_dma_gc", (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v328 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 2308LL);
                                  }
                                  if ( *(_DWORD *)(*((_QWORD *)v323 + 40) + 3072LL) )
                                  {
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v362 = __ldxr(_X8);
                                    while ( __stxr(v362 | 0x40000, _X8) );
                                    if ( *v417 <= 0x8000FFFF )
                                      v331 = 2052;
                                    else
                                      v331 = 3588;
                                    *(_DWORD *)(v310 + 1216 + 4 * v314) = v331 | ((_DWORD)v314 << 12);
                                  }
                                  if ( v323[5] == 1 )
                                  {
                                    v332 = v310 + 460 + 36 * v314;
                                    *(_DWORD *)(v332 + 16) = 19;
                                    *(_DWORD *)(v332 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v371 = __ldxr(_X8);
                                    while ( __stxr(v371 | 0x80000, _X8) );
                                    v333 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 3840LL);
                                    *(_DWORD *)(v332 + 20) = v333;
                                    v334 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v333 < v334 )
                                      v334 = 0;
                                    *(_DWORD *)(v332 + 28) = v333 - v334;
                                    snprintf((char *)v332, 0x10u, "%s%u", "sspp_dgm_csc", (unsigned int)(v309[4] - 9));
                                  }
                                  if ( v323[6] == 1 )
                                  {
                                    v335 = v310 + 536 + 36 * v314;
                                    *(_DWORD *)(v335 + 16) = 28;
                                    *(_DWORD *)(v335 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v374 = __ldxr(_X8);
                                    while ( __stxr(v374 | 0x10000000, _X8) );
                                    v336 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 4608LL);
                                    *(_DWORD *)(v335 + 20) = v336;
                                    v337 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v336 < v337 )
                                      v337 = 0;
                                    *(_DWORD *)(v335 + 28) = v336 - v337;
                                    snprintf(
                                      (char *)v335,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_fp16_igc",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v335 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 4612LL);
                                  }
                                  if ( v323[7] == 1 )
                                  {
                                    v338 = v310 + 612 + 36 * v314;
                                    *(_DWORD *)(v338 + 16) = 29;
                                    *(_DWORD *)(v338 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v377 = __ldxr(_X8);
                                    while ( __stxr(v377 | 0x20000000, _X8) );
                                    v339 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 5376LL);
                                    *(_DWORD *)(v338 + 20) = v339;
                                    v340 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v339 < v340 )
                                      v340 = 0;
                                    *(_DWORD *)(v338 + 28) = v339 - v340;
                                    snprintf(
                                      (char *)v338,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_fp16_gc",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v338 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 5380LL);
                                  }
                                  if ( v323[8] == 1 )
                                  {
                                    v341 = v310 + 688 + 36 * v314;
                                    *(_DWORD *)(v341 + 16) = 30;
                                    *(_DWORD *)(v341 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v380 = __ldxr(_X8);
                                    while ( __stxr(v380 | 0x40000000, _X8) );
                                    v342 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 6144LL);
                                    *(_DWORD *)(v341 + 20) = v342;
                                    v343 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v342 < v343 )
                                      v343 = 0;
                                    *(_DWORD *)(v341 + 28) = v342 - v343;
                                    snprintf(
                                      (char *)v341,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_fp16_csc",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v341 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 6148LL);
                                  }
                                  if ( v323[9] == 1 )
                                  {
                                    v344 = v310 + 764 + 36 * v314;
                                    *(_DWORD *)(v344 + 16) = 31;
                                    *(_DWORD *)(v344 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v383 = __ldxr(_X8);
                                    while ( __stxr(v383 | 0x80000000, _X8) );
                                    v345 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 6912LL);
                                    *(_DWORD *)(v344 + 20) = v345;
                                    v346 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v345 < v346 )
                                      v346 = 0;
                                    *(_DWORD *)(v344 + 28) = v345 - v346;
                                    snprintf(
                                      (char *)v344,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_fp16_unmult",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v344 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 6916LL);
                                  }
                                  if ( v323[10] == 1 )
                                  {
                                    v347 = v310 + 840 + 36 * v314;
                                    *(_DWORD *)(v347 + 16) = 35;
                                    *(_DWORD *)(v347 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v386 = __ldxr(_X8);
                                    while ( __stxr(v386 | 0x800000000LL, _X8) );
                                    v348 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 7680LL);
                                    *(_DWORD *)(v347 + 20) = v348;
                                    v349 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v348 < v349 )
                                      v349 = 0;
                                    *(_DWORD *)(v347 + 28) = v348 - v349;
                                    snprintf(
                                      (char *)v347,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_ucsc_igc",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v347 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 7684LL);
                                  }
                                  if ( v323[11] == 1 )
                                  {
                                    v350 = v310 + 916 + 36 * v314;
                                    *(_DWORD *)(v350 + 16) = 36;
                                    *(_DWORD *)(v350 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v389 = __ldxr(_X8);
                                    while ( __stxr(v389 | 0x1000000000LL, _X8) );
                                    v351 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 8448LL);
                                    *(_DWORD *)(v350 + 20) = v351;
                                    v352 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v351 < v352 )
                                      v352 = 0;
                                    *(_DWORD *)(v350 + 28) = v351 - v352;
                                    snprintf(
                                      (char *)v350,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_ucsc_gc",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v350 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 8452LL);
                                  }
                                  if ( v323[12] == 1 )
                                  {
                                    v353 = v310 + 992 + 36 * v314;
                                    *(_DWORD *)(v353 + 16) = 37;
                                    *(_DWORD *)(v353 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v392 = __ldxr(_X8);
                                    while ( __stxr(v392 | 0x2000000000LL, _X8) );
                                    v354 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 9216LL);
                                    *(_DWORD *)(v353 + 20) = v354;
                                    v355 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v354 < v355 )
                                      v355 = 0;
                                    *(_DWORD *)(v353 + 28) = v354 - v355;
                                    snprintf(
                                      (char *)v353,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_ucsc_csc",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v353 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 9220LL);
                                  }
                                  if ( v323[13] == 1 )
                                  {
                                    v356 = v310 + 1068 + 36 * v314;
                                    *(_DWORD *)(v356 + 16) = 38;
                                    *(_DWORD *)(v356 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v395 = __ldxr(_X8);
                                    while ( __stxr(v395 | 0x4000000000LL, _X8) );
                                    v357 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 9984LL);
                                    *(_DWORD *)(v356 + 20) = v357;
                                    v358 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v357 < v358 )
                                      v358 = 0;
                                    *(_DWORD *)(v356 + 28) = v357 - v358;
                                    snprintf(
                                      (char *)v356,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_ucsc_unmult",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v356 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 9988LL);
                                  }
                                  if ( v323[14] == 1 )
                                  {
                                    v359 = v310 + 1144 + 36 * v314;
                                    *(_DWORD *)(v359 + 16) = 39;
                                    *(_DWORD *)(v359 + 24) = 0;
                                    _X8 = (unsigned __int64 *)(v309 + 8);
                                    __asm { PRFM            #0x11, [X8] }
                                    do
                                      v320 = __ldxr(_X8);
                                    while ( __stxr(v320 | 0x8000000000LL, _X8) );
                                    v321 = *(_DWORD *)(*((_QWORD *)v323 + 40) + 10752LL);
                                    *(_DWORD *)(v359 + 20) = v321;
                                    v322 = *(_DWORD *)(*((_QWORD *)v309 + 6) + 48LL);
                                    if ( v321 < v322 )
                                      v322 = 0;
                                    *(_DWORD *)(v359 + 28) = v321 - v322;
                                    snprintf(
                                      (char *)v359,
                                      0x10u,
                                      "%s%u",
                                      "sspp_dma_ucsc_alpha_dither",
                                      (unsigned int)(v309[4] - 9));
                                    *(_DWORD *)(v359 + 32) = *(_DWORD *)(*((_QWORD *)v323 + 40) + 10756LL);
                                  }
                                }
                                v316 = (const char **)v422;
                                v317 = 0;
                                v314 = 1;
                              }
                              while ( (v324 & 1) != 0 );
                              v308 = v315;
                              v295 = v413;
                              v49 = v414;
                              v48 = v417;
                              v301 = v411;
                              goto LABEL_437;
                            }
                          }
                          else if ( (*(_BYTE *)(v310 + 1296) & 1) != 0 )
                          {
                            goto LABEL_446;
                          }
                          v312 = v421;
                          if ( !v421 )
                            goto LABEL_452;
                          goto LABEL_450;
                        }
LABEL_437:
                        if ( ++v307 >= (unsigned __int64)v48[1520] )
                          goto LABEL_556;
                        continue;
                      }
                    }
                  }
                  v406 = &unk_27E48D;
LABEL_572:
                  printk(v406, "_sde_sspp_setup_dmas");
LABEL_573:
                  v48 = v417;
LABEL_557:
                  LODWORD(v5) = 0;
                  v402 = v421;
                  if ( v421 )
                  {
LABEL_558:
                    kvfree(*((_QWORD *)v402 + 40));
                    kvfree(v402);
                  }
LABEL_559:
                  v403 = v422[0];
                  if ( v422[0] )
                  {
                    kvfree(*(_QWORD *)(v422[0] + 320LL));
                    kvfree(v403);
                  }
                  if ( v305 )
                  {
                    kvfree(*(_QWORD *)(v305 + 320));
                    kvfree(v305);
                  }
                  if ( !(_DWORD)v5 )
                  {
                    v421 = nullptr;
                    v420 = 0;
                    LODWORD(v419) = 0;
                    v404 = (int *)_kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
                    if ( v404 )
                    {
                      LODWORD(v5) = validate_dt_entry(v49, &dspp_top_prop, 2, &v421, &v419);
                      if ( !(_DWORD)v5 )
                      {
                        LODWORD(v5) = read_dt_entry(v49, &dspp_top_prop, 2, &v421, &v420, v404);
                        if ( !(_DWORD)v5 )
                        {
                          if ( (_DWORD)v419 == 1 )
                          {
                            v405 = v404[192];
                            v48[2033] = *v404;
                            v48[2034] = v405;
                            strcpy((char *)v48 + 8112, "dspp_top");
                            kvfree(v404);
                            LODWORD(v5) = sde_dspp_parse_dt(v49, v48);
                            goto LABEL_189;
                          }
                          printk(&unk_246CB9, "sde_dspp_top_parse_dt");
                          LODWORD(v5) = -22;
                        }
                      }
                    }
                    else
                    {
                      LODWORD(v5) = -12;
                    }
                    kvfree(v404);
                    goto LABEL_189;
                  }
                  goto LABEL_189;
                }
LABEL_432:
                if ( !v48[1520] )
                  goto LABEL_556;
                goto LABEL_435;
              }
              printk(&unk_27E440, "_sde_sspp_setup_dmas");
            }
            else
            {
              v301 = 0;
              if ( v48[1520] )
                goto LABEL_435;
            }
LABEL_556:
            v305 = 0;
            goto LABEL_557;
          }
          kvfree(*(_QWORD *)(v5 + 320));
          kvfree(v5);
LABEL_407:
          LODWORD(v5) = 0;
          goto LABEL_408;
        }
      }
      else
      {
LABEL_209:
        v421 = (const char *)sde_get_dt_props(v145, 20, &vig_prop, 20, 0);
      }
LABEL_210:
      v48 = v417;
      if ( !v417[1520] )
        goto LABEL_407;
      v154 = 0;
      v155 = 0;
      v156 = (int *)(v417 + 1522);
      v407 = v146;
      while ( 1 )
      {
        if ( v154 == 13 )
          goto LABEL_575;
        v157 = &v156[18 * v154];
        v158 = *((_QWORD *)v157 + 6);
        of_property_read_string_helper(v49, off_A3E0, &v419, 1, (unsigned int)v154);
        if ( !strcmp(v419, "vig") )
        {
          v410 = v158;
          v48 = v417;
          if ( !v146 || *(_BYTE *)v146 != 1 || v155 < *(_DWORD *)(v146 + 4) )
          {
            *(_DWORD *)v410 = v416[269];
            v159 = v416[270];
            *(_QWORD *)(v410 + 20) = 0x1400000004LL;
            *(_DWORD *)(v410 + 4) = v159;
            v157[4] = v155 + 1;
            snprintf((char *)&v156[18 * v154], 0x10u, "sspp_%u", v155);
            v408 = v155 + 1;
            v157[15] = v155 + 1;
            v157[16] = 0;
            _X8 = (unsigned __int64 *)(v157 + 10);
            __asm { PRFM            #0x11, [X8] }
            do
              v251 = __ldxr(_X8);
            while ( __stxr(v251 | 2, _X8) );
            if ( v416[278] == 8 )
            {
              _X8 = (unsigned __int64 *)(v157 + 10);
              __asm { PRFM            #0x11, [X8] }
              do
                v257 = __ldxr(_X8);
              while ( __stxr(v257 | 4, _X8) );
            }
            v412 = v421;
            if ( v421 && v421[1] == 1 )
              v160 = *(_DWORD *)(*((_QWORD *)v421 + 40) + 768LL);
            else
              v160 = 512;
            *(_DWORD *)(v410 + 48) = v160;
            v161 = 0;
            *(_QWORD *)(v410 + 1224) = *((_QWORD *)v417 + 2755);
            *(_QWORD *)(v410 + 1232) = *((_QWORD *)v417 + 2758);
            v162 = 1;
            v163 = &v421;
            v409 = v154;
            *(_DWORD *)(v410 + 532) = 0;
            *(_DWORD *)(v410 + 608) = 0;
            *(_DWORD *)(v410 + 684) = 0;
            *(_DWORD *)(v410 + 760) = 0;
            *(_DWORD *)(v410 + 836) = 0;
            *(_DWORD *)(v410 + 912) = 0;
            *(_DWORD *)(v410 + 988) = 0;
            *(_DWORD *)(v410 + 1064) = 0;
            *(_DWORD *)(v410 + 1140) = 0;
            do
            {
              v164 = *v163;
              v165 = v162;
              if ( *v163 )
              {
                v166 = v410 + 536 + 36 * v161;
                if ( v164[11] == 1 )
                {
                  *(_DWORD *)(v166 + 24) = 0;
                  *(_DWORD *)(v166 + 16) = 28;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v195 = __ldxr(_X8);
                  while ( __stxr(v195 | 0x10000000, _X8) );
                  v167 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 8448LL);
                  *(_DWORD *)(v166 + 20) = v167;
                  v168 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v167 < v168 )
                    v168 = 0;
                  *(_DWORD *)(v166 + 28) = v167 - v168;
                  snprintf((char *)v166, 0x10u, "%s%u", "sspp_vig_fp16_igc", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v166 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 8452LL);
                  if ( v410 != -532 )
                    ++*(_DWORD *)(v410 + 532);
                }
                else
                {
                  *(_DWORD *)(v166 + 16) = 0;
                }
                v169 = v410 + 612 + 36 * v161;
                if ( v164[12] == 1 )
                {
                  *(_DWORD *)(v169 + 24) = 0;
                  *(_DWORD *)(v169 + 16) = 29;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v198 = __ldxr(_X8);
                  while ( __stxr(v198 | 0x20000000, _X8) );
                  v170 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 9216LL);
                  *(_DWORD *)(v169 + 20) = v170;
                  v171 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v170 < v171 )
                    v171 = 0;
                  *(_DWORD *)(v169 + 28) = v170 - v171;
                  snprintf((char *)v169, 0x10u, "%s%u", "sspp_vig_fp16_gc", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v169 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 9220LL);
                  if ( v410 != -608 )
                    ++*(_DWORD *)(v410 + 608);
                }
                else
                {
                  *(_DWORD *)(v169 + 16) = 0;
                }
                v172 = v410 + 688 + 36 * v161;
                if ( v164[13] == 1 )
                {
                  *(_DWORD *)(v172 + 24) = 0;
                  *(_DWORD *)(v172 + 16) = 30;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v201 = __ldxr(_X8);
                  while ( __stxr(v201 | 0x40000000, _X8) );
                  v173 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 9984LL);
                  *(_DWORD *)(v172 + 20) = v173;
                  v174 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v173 < v174 )
                    v174 = 0;
                  *(_DWORD *)(v172 + 28) = v173 - v174;
                  snprintf((char *)v172, 0x10u, "%s%u", "sspp_vig_fp16_csc", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v172 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 9988LL);
                  if ( v410 != -684 )
                    ++*(_DWORD *)(v410 + 684);
                }
                else
                {
                  *(_DWORD *)(v172 + 16) = 0;
                }
                v175 = v410 + 764 + 36 * v161;
                if ( v164[14] == 1 )
                {
                  *(_DWORD *)(v175 + 24) = 0;
                  *(_DWORD *)(v175 + 16) = 31;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v204 = __ldxr(_X8);
                  while ( __stxr(v204 | 0x80000000, _X8) );
                  v176 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 10752LL);
                  *(_DWORD *)(v175 + 20) = v176;
                  v177 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v176 < v177 )
                    v177 = 0;
                  *(_DWORD *)(v175 + 28) = v176 - v177;
                  snprintf((char *)v175, 0x10u, "%s%u", "sspp_vig_fp16_unmult", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v175 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 10756LL);
                  if ( v410 != -760 )
                    ++*(_DWORD *)(v410 + 760);
                }
                else
                {
                  *(_DWORD *)(v175 + 16) = 0;
                }
                v178 = v410 + 840 + 36 * v161;
                if ( v164[15] == 1 )
                {
                  *(_DWORD *)(v178 + 24) = 0;
                  *(_DWORD *)(v178 + 16) = 35;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v207 = __ldxr(_X8);
                  while ( __stxr(v207 | 0x800000000LL, _X8) );
                  v179 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 11520LL);
                  *(_DWORD *)(v178 + 20) = v179;
                  v180 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v179 < v180 )
                    v180 = 0;
                  *(_DWORD *)(v178 + 28) = v179 - v180;
                  snprintf((char *)v178, 0x10u, "%s%u", "sspp_vig_ucsc_igc", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v178 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 11524LL);
                  if ( v410 != -836 )
                    ++*(_DWORD *)(v410 + 836);
                }
                else
                {
                  *(_DWORD *)(v178 + 16) = 0;
                }
                v181 = v410 + 916 + 36 * v161;
                if ( v164[16] == 1 )
                {
                  *(_DWORD *)(v181 + 16) = 36;
                  *(_DWORD *)(v181 + 24) = 0;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v210 = __ldxr(_X8);
                  while ( __stxr(v210 | 0x1000000000LL, _X8) );
                  v182 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 12288LL);
                  *(_DWORD *)(v181 + 20) = v182;
                  v183 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v182 < v183 )
                    v183 = 0;
                  *(_DWORD *)(v181 + 28) = v182 - v183;
                  snprintf((char *)v181, 0x10u, "%s%u", "sspp_vig_ucsc_gc", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v181 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 12292LL);
                  if ( v410 != -912 )
                    ++*(_DWORD *)(v410 + 912);
                }
                else
                {
                  *(_DWORD *)(v181 + 16) = 0;
                }
                v184 = v410 + 992 + 36 * v161;
                if ( v164[17] == 1 )
                {
                  *(_DWORD *)(v184 + 24) = 0;
                  *(_DWORD *)(v184 + 16) = 37;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v213 = __ldxr(_X8);
                  while ( __stxr(v213 | 0x2000000000LL, _X8) );
                  v185 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 13056LL);
                  *(_DWORD *)(v184 + 20) = v185;
                  v186 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v185 < v186 )
                    v186 = 0;
                  *(_DWORD *)(v184 + 28) = v185 - v186;
                  snprintf((char *)v184, 0x10u, "%s%u", "sspp_vig_ucsc_csc", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v184 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 13060LL);
                  if ( v410 != -988 )
                    ++*(_DWORD *)(v410 + 988);
                }
                else
                {
                  *(_DWORD *)(v184 + 16) = 0;
                }
                v187 = v410 + 1068 + 36 * v161;
                if ( v164[18] == 1 )
                {
                  *(_DWORD *)(v187 + 24) = 0;
                  *(_DWORD *)(v187 + 16) = 38;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v216 = __ldxr(_X8);
                  while ( __stxr(v216 | 0x4000000000LL, _X8) );
                  v188 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 13824LL);
                  *(_DWORD *)(v187 + 20) = v188;
                  v189 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v188 < v189 )
                    v189 = 0;
                  *(_DWORD *)(v187 + 28) = v188 - v189;
                  snprintf((char *)v187, 0x10u, "%s%u", "sspp_vig_ucsc_unmult", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v187 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 13828LL);
                  if ( v410 != -1064 )
                    ++*(_DWORD *)(v410 + 1064);
                }
                else
                {
                  *(_DWORD *)(v187 + 16) = 0;
                }
                v190 = v410 + 1144 + 36 * v161;
                if ( v164[19] == 1 )
                {
                  *(_DWORD *)(v190 + 24) = 0;
                  *(_DWORD *)(v190 + 16) = 39;
                  _X8 = (unsigned __int64 *)(v157 + 8);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v219 = __ldxr(_X8);
                  while ( __stxr(v219 | 0x8000000000LL, _X8) );
                  v191 = *(_DWORD *)(*((_QWORD *)v164 + 40) + 14592LL);
                  *(_DWORD *)(v190 + 20) = v191;
                  v192 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                  if ( v191 < v192 )
                    v192 = 0;
                  *(_DWORD *)(v190 + 28) = v191 - v192;
                  snprintf((char *)v190, 0x10u, "%s%u", "sspp_vig_ucsc_alpha_dither", (unsigned int)(v157[4] - 1));
                  *(_DWORD *)(v190 + 32) = *(_DWORD *)(*((_QWORD *)v164 + 40) + 14596LL);
                  if ( v410 != -1140 )
                    ++*(_DWORD *)(v410 + 1140);
                }
                else
                {
                  *(_DWORD *)(v190 + 16) = 0;
                }
              }
              v163 = (const char **)v422;
              v162 = 0;
              v161 = 1;
            }
            while ( (v165 & 1) != 0 );
            v49 = v414;
            v156 = (int *)(v417 + 1522);
            v146 = v407;
            v48 = v417;
            if ( v412 )
            {
              v220 = v417[4];
              if ( (unsigned int)v220 <= 0x16 && ((1 << v220) & 0x40000C) != 0 )
              {
                v221 = v220 >> 6;
                v222 = 1LL << v220;
                _X9 = (unsigned __int64 *)&v157[2 * v221 + 8];
                __asm { PRFM            #0x11, [X9] }
                do
                  v263 = __ldxr(_X9);
                while ( __stxr(v263 | v222, _X9) );
                *(_DWORD *)(v410 + 96) = v417[4];
                v223 = *(_DWORD *)(v410 + 48);
                v224 = *(_DWORD *)(*((_QWORD *)v412 + 40) + 1536LL);
                *(_DWORD *)(v410 + 100) = v224;
                if ( v224 < v223 )
                  v223 = 0;
                *(_DWORD *)(v410 + 104) = *(_DWORD *)(*((_QWORD *)v412 + 40) + 2304LL);
                *(_DWORD *)(v410 + 108) = v224 - v223;
                snprintf((char *)(v410 + 80), 0x10u, "sspp_scaler%u", (unsigned int)(v157[4] - 1));
              }
              v225 = *((_QWORD *)v157 + 6);
              v226 = v416[282];
              if ( v226 == 5 )
              {
                v227 = v412;
                if ( v412[4] != 1 )
                  goto LABEL_326;
                *(_DWORD *)(v225 + 148) = 0;
                *(_DWORD *)(v225 + 140) = 5;
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v290 = __ldxr(_X8);
                while ( __stxr(v290 | 0x20, _X8) );
LABEL_323:
                v228 = *(_DWORD *)(*((_QWORD *)v412 + 40) + 3072LL);
                *(_DWORD *)(v225 + 144) = v228;
                v229 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                if ( v228 < v229 )
                  v229 = 0;
                *(_DWORD *)(v225 + 152) = v228 - v229;
                snprintf((char *)(v225 + 124), 0x10u, "%s%u", "sspp_csc", (unsigned int)(v157[4] - 1));
                v227 = v412;
              }
              else
              {
                v227 = v412;
                if ( v226 == 4 )
                {
                  if ( v412[4] == 1 )
                  {
                    *(_DWORD *)(v225 + 148) = 0;
                    *(_DWORD *)(v225 + 140) = 4;
                    _X8 = (unsigned __int64 *)(v157 + 8);
                    __asm { PRFM            #0x11, [X8] }
                    do
                      v287 = __ldxr(_X8);
                    while ( __stxr(v287 | 0x10, _X8) );
                    goto LABEL_323;
                  }
LABEL_326:
                  *(_DWORD *)(v225 + 140) = 0;
                }
              }
              if ( v227[5] == 1 )
              {
                *(_DWORD *)(v225 + 184) = 0;
                *(_DWORD *)(v225 + 176) = 6;
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v269 = __ldxr(_X8);
                while ( __stxr(v269 | 0x40, _X8) );
                v230 = *(_DWORD *)(*((_QWORD *)v412 + 40) + 3840LL);
                *(_DWORD *)(v225 + 180) = v230;
                v231 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                if ( v230 < v231 )
                  v231 = 0;
                *(_DWORD *)(v225 + 188) = v230 - v231;
                snprintf((char *)(v225 + 160), 0x10u, "%s%u", "sspp_hsic", (unsigned int)(v157[4] - 1));
                v227 = v412;
                *(_DWORD *)(v225 + 192) = *(_DWORD *)(*((_QWORD *)v412 + 40) + 3844LL);
              }
              else
              {
                *(_DWORD *)(v225 + 176) = 0;
              }
              if ( v227[6] == 1 )
              {
                *(_DWORD *)(v225 + 220) = 0;
                *(_DWORD *)(v225 + 212) = 7;
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v272 = __ldxr(_X8);
                while ( __stxr(v272 | 0x80, _X8) );
                v232 = *(_DWORD *)(*((_QWORD *)v412 + 40) + 4608LL);
                *(_DWORD *)(v225 + 216) = v232;
                v233 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                if ( v232 < v233 )
                  v233 = 0;
                *(_DWORD *)(v225 + 224) = v232 - v233;
                snprintf((char *)(v225 + 196), 0x10u, "%s%u", "sspp_memcolor", (unsigned int)(v157[4] - 1));
                v227 = v412;
                *(_DWORD *)(v225 + 228) = *(_DWORD *)(*((_QWORD *)v412 + 40) + 4612LL);
              }
              else
              {
                *(_DWORD *)(v225 + 212) = 0;
              }
              if ( v227[7] == 1 )
              {
                *(_DWORD *)(v225 + 256) = 0;
                *(_DWORD *)(v225 + 248) = 8;
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v275 = __ldxr(_X8);
                while ( __stxr(v275 | 0x100, _X8) );
                v234 = *(_DWORD *)(*((_QWORD *)v412 + 40) + 5376LL);
                *(_DWORD *)(v225 + 252) = v234;
                v235 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                if ( v234 < v235 )
                  v235 = 0;
                *(_DWORD *)(v225 + 260) = v234 - v235;
                snprintf((char *)(v225 + 232), 0x10u, "%s%u", "sspp_pcc", (unsigned int)(v157[4] - 1));
                v227 = v412;
                *(_DWORD *)(v225 + 264) = *(_DWORD *)(*((_QWORD *)v412 + 40) + 5380LL);
              }
              else
              {
                *(_DWORD *)(v225 + 248) = 0;
              }
              if ( v227[8] == 1 )
              {
                *(_DWORD *)(v225 + 292) = 0;
                *(_DWORD *)(v225 + 284) = 14;
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v278 = __ldxr(_X8);
                while ( __stxr(v278 | 0x4000, _X8) );
                v236 = *(_DWORD *)(*((_QWORD *)v412 + 40) + 6144LL);
                *(_DWORD *)(v225 + 288) = v236;
                v237 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                if ( v236 < v237 )
                  v237 = 0;
                *(_DWORD *)(v225 + 296) = v236 - v237;
                snprintf((char *)(v225 + 268), 0x10u, "%s%u", "sspp_vig_gamut", (unsigned int)(v157[4] - 1));
                v227 = v412;
                *(_DWORD *)(v225 + 300) = *(_DWORD *)(*((_QWORD *)v412 + 40) + 6148LL);
              }
              else
              {
                *(_DWORD *)(v225 + 284) = 0;
              }
              if ( v227[9] == 1 )
              {
                *(_DWORD *)(v225 + 332) = 0;
                *(_DWORD *)(v225 + 324) = 13;
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v281 = __ldxr(_X8);
                while ( __stxr(v281 | 0x2000, _X8) );
                v238 = *(_DWORD *)(*((_QWORD *)v412 + 40) + 6912LL);
                *(_DWORD *)(v225 + 328) = v238;
                v239 = *(_DWORD *)(*((_QWORD *)v157 + 6) + 48LL);
                if ( v238 < v239 )
                  v239 = 0;
                *(_DWORD *)(v225 + 336) = v238 - v239;
                snprintf((char *)(v225 + 308), 0x10u, "%s%u", "sspp_vig_igc", (unsigned int)(v157[4] - 1));
                v227 = v412;
                *(_DWORD *)(v225 + 340) = *(_DWORD *)(*((_QWORD *)v412 + 40) + 6916LL);
              }
              else
              {
                *(_DWORD *)(v225 + 324) = 0;
              }
              if ( v227[10] == 1 )
              {
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v284 = __ldxr(_X8);
                while ( __stxr(v284 | 0x20000, _X8) );
                *(_DWORD *)(v225 + 1216) = 7840;
              }
            }
            v154 = v409;
            if ( v417[11] )
            {
              _X8 = (unsigned __int64 *)(v157 + 8);
              __asm { PRFM            #0x11, [X8] }
              do
                v254 = __ldxr(_X8);
              while ( __stxr(v254 | 0x800000, _X8) );
              v240 = *((_QWORD *)v417 + 2759);
              *(_DWORD *)(v410 + 1276) = 1088;
              *(_QWORD *)(v410 + 1240) = v240;
              v241 = v417[11];
              if ( v241 - 512 >= 3 )
              {
                if ( v241 == 256 )
                {
                  v242 = v410;
                  v243 = 4;
                  v244 = 5;
                  v245 = 11;
                  v246 = 1256;
                  v247 = 1260;
                  v248 = 1264;
                  goto LABEL_365;
                }
              }
              else
              {
                _X8 = (unsigned __int64 *)(v157 + 8);
                __asm { PRFM            #0x11, [X8] }
                do
                  v266 = __ldxr(_X8);
                while ( __stxr(v266 | 0x2000000, _X8) );
                v242 = v410;
                v244 = 11;
                v245 = 4;
                v246 = 1264;
                *(_QWORD *)(v410 + 1256) = 0x100000004LL;
                v243 = 5;
                v247 = 1268;
                v248 = 1272;
LABEL_365:
                *(_DWORD *)(v242 + v246) = v245;
                *(_DWORD *)(v242 + v247) = v244;
                *(_DWORD *)(v242 + v248) = v243;
              }
            }
            if ( (*((_QWORD *)v417 + 2751) & 0x10000000) != 0 )
            {
              _X8 = (unsigned __int64 *)(v157 + 8);
              __asm { PRFM            #0x11, [X8] }
              do
                v260 = __ldxr(_X8);
              while ( __stxr(v260 | 0x8000000, _X8) );
            }
            v155 = v408;
          }
        }
        else
        {
          v48 = v417;
        }
        if ( ++v154 >= (unsigned __int64)v48[1520] )
          goto LABEL_407;
      }
    }
  }
LABEL_189:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
