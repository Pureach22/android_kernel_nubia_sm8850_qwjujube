__int64 __fastcall fastrpc_device_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  _QWORD *v4; // x23
  __int64 v5; // x19
  unsigned int v6; // w8
  unsigned int v8; // w22
  unsigned int v14; // w9
  __int64 v15; // x20
  __int64 v17; // x1
  __int64 result; // x0
  __int64 v19; // x22
  __int64 v20; // x21
  _QWORD *v21; // x23
  _QWORD *v22; // x24
  _QWORD *v23; // x8
  _QWORD *v24; // x9
  _QWORD *v25; // x1
  int v26; // w22
  __int64 v27; // x8
  unsigned __int64 v28; // x0
  int v29; // w21
  __int64 *v30; // x9
  __int64 v31; // x23
  __int64 v32; // x24
  __int64 v33; // x21
  char v35; // w8
  unsigned __int64 v36; // x0
  __int64 v37; // x23
  __int64 v38; // x8
  __int64 *v39; // x10
  __int64 *v40; // x8
  __int64 v41; // x23
  __int64 v42; // x21
  __int64 v43; // x11
  unsigned __int64 v44; // x8
  unsigned int v45; // w10
  int v46; // w0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x9
  _QWORD *v52; // x23
  _QWORD *v53; // x11
  _QWORD *v54; // x8
  __int64 v55; // x0
  __int64 v56; // x9
  __int64 v57; // x8
  _QWORD *v58; // x2
  __int64 v59; // x9
  _QWORD *v60; // x1
  __int64 v61; // x23
  unsigned __int64 v62; // x9
  unsigned int v63; // w10
  int v64; // w0
  unsigned __int64 v66; // x26
  __int64 v67; // x24
  int v68; // w25
  __int64 v69; // x0
  char v70; // w22
  _DWORD *v71; // x25
  int v72; // w0
  __int64 v73; // x24
  __int64 v74; // x23
  __int64 v76; // x0
  int v77; // w25
  int v78; // w24
  const char *v79; // x8
  int v80; // w9
  unsigned int v81; // w8
  __int64 v82; // x9
  __int64 v83; // x9
  unsigned int v85; // w10
  unsigned int v86; // t1
  unsigned int v88; // w12
  int v89; // w0
  __int64 v90; // x22
  unsigned __int64 StatusReg; // x8
  char v92; // w10
  unsigned __int64 v93; // x9
  unsigned __int64 v94; // x9
  unsigned __int64 v96; // x8
  __int64 v97; // x0
  unsigned __int64 v98; // x8
  unsigned __int64 v100; // x9
  __int64 *v101; // x24
  __int64 v102; // x9
  unsigned __int64 v103; // x11
  int v104; // w0
  __int64 v105; // x8
  __int64 v106; // x8
  __int64 v107; // x0
  __int64 v108; // x25
  __int64 v109; // x1
  __int64 v110; // x26
  int v111; // w22
  __int64 v112; // x0
  __int64 v113; // x0
  __int64 v114; // x1
  __int64 v115; // x1
  __int64 v116; // x0
  __int64 v117; // x9
  __int64 v118; // x8
  __int64 *v119; // x2
  __int64 v120; // x9
  __int64 *v121; // x1
  __int64 v122; // x2
  __int64 *v123; // x1
  unsigned __int64 v124; // x8
  unsigned __int64 v125; // x9
  unsigned __int64 v126; // x9
  unsigned __int64 v128; // x8
  __int64 v129; // x0
  unsigned __int64 v130; // x8
  unsigned __int64 v132; // x9
  size_t v133; // x21
  unsigned __int64 v134; // x21
  size_t v135; // x22
  int v136; // w9
  __int64 v137; // x10
  int v138; // w8
  __int64 v139; // x0
  __int64 v140; // x21
  size_t v141; // x22
  unsigned __int64 v142; // x23
  unsigned __int64 v143; // x22
  int v144; // w24
  unsigned __int64 v145; // x23
  __int64 **v146; // x26
  __int64 v147; // x0
  __int64 v148; // x0
  __int64 *v149; // x22
  __int64 v150; // x9
  __int64 **v151; // x8
  __int64 *v152; // x10
  unsigned int v155; // w10
  int v156; // w8
  int v157; // w21
  __int64 v158; // x8
  __int64 *v159; // x22
  __int64 v160; // x0
  __int64 v161; // x1
  __int64 v162; // x0
  __int64 v163; // x8
  _QWORD *v164; // x24
  bool v165; // w26
  __int64 v166; // x12
  __int64 v167; // x9
  unsigned int v168; // w8
  __int64 v169; // x10
  unsigned __int64 v170; // x11
  __int64 v171; // x9
  __int64 v172; // x4
  unsigned __int64 v173; // x25
  unsigned int v174; // w0
  unsigned __int64 v175; // x25
  _DWORD *v176; // x9
  int v177; // w8
  char v178; // w10
  unsigned int v179; // w0
  __int64 v180; // x4
  __int64 v181; // x5
  __int64 v182; // x21
  __int64 v183; // x10
  __int64 v184; // x10
  __int64 v185; // x10
  __int64 v186; // x10
  __int64 v187; // x10
  __int64 v188; // x10
  __int64 v189; // x10
  __int64 v190; // x10
  __int64 v191; // x10
  __int64 v192; // x10
  __int64 v193; // x10
  __int64 v194; // x10
  __int64 v195; // x10
  __int64 v196; // x10
  __int64 v197; // x10
  __int64 v198; // x21
  unsigned __int64 v199; // x8
  unsigned __int64 v200; // x9
  unsigned __int64 v201; // x9
  unsigned __int64 v203; // x8
  unsigned __int64 v204; // x8
  unsigned __int64 v206; // x9
  unsigned int v208; // w8
  unsigned int v211; // w8
  int v213; // w8
  unsigned int v216; // w8
  unsigned int v219; // w9
  __int64 v220; // x0
  size_t v221; // x24
  unsigned __int64 v222; // x25
  unsigned __int64 v223; // x24
  int v224; // w8
  int v225; // w9
  int v226; // w8
  char v227; // w9
  char v228; // w10
  __int64 v229; // x10
  __int64 v230; // x0
  unsigned __int64 v231; // x25
  _DWORD *v232; // x0
  unsigned __int64 v233; // x8
  unsigned __int64 v234; // x9
  __int64 v235; // x8
  unsigned __int64 v236; // x10
  unsigned int v237; // w12
  unsigned __int64 v238; // x13
  unsigned __int64 v239; // x13
  unsigned __int64 v240; // x14
  unsigned __int64 v241; // x14
  unsigned int v242; // w5
  unsigned int v243; // w13
  size_t v244; // x0
  int v245; // w11
  unsigned __int64 v246; // x8
  int v247; // w8
  int v248; // w22
  __int64 v249; // x0
  __int64 v250; // x9
  __int64 v251; // x23
  __int64 v252; // x9
  __int64 v253; // x10
  unsigned __int64 v254; // x9
  __int64 v255; // x9
  _QWORD *v256; // x11
  int v257; // w9
  int v258; // w0
  __int64 v259; // x0
  __int64 v260; // x23
  __int64 v261; // x0
  __int64 v262; // x0
  unsigned __int64 v263; // x22
  __int64 v264; // x9
  unsigned int v267; // w8
  unsigned __int64 v268; // x8
  __int64 v269; // x24
  int v270; // w9
  int v271; // w10
  unsigned __int64 v272; // x26
  unsigned int v273; // w25
  __int64 v274; // x11
  int v275; // w0
  unsigned __int64 v276; // x8
  unsigned __int64 v277; // x9
  unsigned __int64 v278; // x9
  unsigned __int64 v280; // x8
  unsigned __int64 v281; // x8
  unsigned __int64 v283; // x9
  unsigned int v286; // w8
  __int64 v287; // x9
  unsigned __int64 v288; // x11
  int v289; // w0
  __int64 v290; // x8
  unsigned __int64 v291; // x8
  unsigned __int64 v292; // x9
  unsigned __int64 v293; // x9
  unsigned __int64 v295; // x8
  unsigned __int64 v296; // x8
  unsigned __int64 v298; // x9
  int v300; // w8
  int v302; // w8
  __int64 v303; // x0
  int v304; // w8
  __int64 v305; // x21
  int v306; // w8
  unsigned __int64 v307; // [xsp+10h] [xbp-230h]
  __int64 v308; // [xsp+10h] [xbp-230h]
  __int64 v309; // [xsp+10h] [xbp-230h]
  unsigned __int64 v310; // [xsp+18h] [xbp-228h]
  __int64 v311; // [xsp+18h] [xbp-228h]
  __int64 v312; // [xsp+18h] [xbp-228h]
  __int64 v313; // [xsp+18h] [xbp-228h]
  __int64 v314; // [xsp+20h] [xbp-220h] BYREF
  __int64 v315[2]; // [xsp+28h] [xbp-218h] BYREF
  __int64 v316; // [xsp+38h] [xbp-208h] BYREF
  __int64 v317; // [xsp+40h] [xbp-200h]
  __int64 v318; // [xsp+48h] [xbp-1F8h]
  __int64 v319; // [xsp+50h] [xbp-1F0h] BYREF
  int v320; // [xsp+58h] [xbp-1E8h]
  __int64 v321; // [xsp+60h] [xbp-1E0h] BYREF
  int v322; // [xsp+68h] [xbp-1D8h]
  __int64 v323[3]; // [xsp+70h] [xbp-1D0h] BYREF
  unsigned __int64 v324; // [xsp+88h] [xbp-1B8h] BYREF
  __int64 v325; // [xsp+90h] [xbp-1B0h] BYREF
  _QWORD v326[3]; // [xsp+98h] [xbp-1A8h] BYREF
  __int64 v327; // [xsp+B0h] [xbp-190h] BYREF
  unsigned __int64 v328; // [xsp+B8h] [xbp-188h]
  unsigned __int64 v329; // [xsp+C0h] [xbp-180h]
  __int64 v330; // [xsp+C8h] [xbp-178h]
  __int64 v331; // [xsp+D0h] [xbp-170h]
  __int64 v332; // [xsp+D8h] [xbp-168h] BYREF
  int v333[2]; // [xsp+E0h] [xbp-160h]
  unsigned __int64 v334; // [xsp+E8h] [xbp-158h]
  unsigned __int64 v335; // [xsp+F0h] [xbp-150h]
  __int64 v336; // [xsp+F8h] [xbp-148h]
  __int64 v337; // [xsp+100h] [xbp-140h]
  __int64 v338; // [xsp+108h] [xbp-138h]
  __int64 v339; // [xsp+110h] [xbp-130h]
  __int64 v340; // [xsp+118h] [xbp-128h]
  __int64 v341; // [xsp+120h] [xbp-120h]
  _QWORD *v342; // [xsp+128h] [xbp-118h] BYREF
  __int64 *v343; // [xsp+130h] [xbp-110h]
  __int64 v344; // [xsp+138h] [xbp-108h]
  unsigned __int64 *v345; // [xsp+140h] [xbp-100h]
  __int64 v346; // [xsp+148h] [xbp-F8h]
  __int64 v347; // [xsp+150h] [xbp-F0h]
  __int64 *v348; // [xsp+158h] [xbp-E8h]
  __int64 v349; // [xsp+160h] [xbp-E0h]
  __int64 v350; // [xsp+168h] [xbp-D8h]
  __int64 *v351; // [xsp+170h] [xbp-D0h]
  __int64 v352; // [xsp+178h] [xbp-C8h]
  __int64 v353; // [xsp+180h] [xbp-C0h]
  __int64 v354; // [xsp+188h] [xbp-B8h]
  __int64 v355; // [xsp+190h] [xbp-B0h]
  __int64 v356; // [xsp+198h] [xbp-A8h]
  __int64 v357; // [xsp+1A0h] [xbp-A0h] BYREF
  __int64 *v358; // [xsp+1A8h] [xbp-98h]
  void *v359; // [xsp+1B0h] [xbp-90h]
  unsigned __int64 v360; // [xsp+1B8h] [xbp-88h]
  __int64 v361; // [xsp+1C0h] [xbp-80h]
  __int64 v362; // [xsp+1C8h] [xbp-78h]
  __int64 v363; // [xsp+1D0h] [xbp-70h]
  __int64 v364; // [xsp+1D8h] [xbp-68h]
  __int64 v365; // [xsp+1E0h] [xbp-60h]
  __int64 *v366; // [xsp+1E8h] [xbp-58h]
  __int64 v367; // [xsp+1F0h] [xbp-50h]
  __int64 v368; // [xsp+1F8h] [xbp-48h]
  _QWORD *v369; // [xsp+200h] [xbp-40h]
  __int64 v370; // [xsp+208h] [xbp-38h]
  __int64 v371; // [xsp+210h] [xbp-30h]
  char *v372; // [xsp+218h] [xbp-28h]
  __int64 v373; // [xsp+220h] [xbp-20h]
  __int64 v374; // [xsp+228h] [xbp-18h]
  __int64 v375; // [xsp+230h] [xbp-10h]

  LODWORD(v4) = a2;
  v375 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 32);
  v6 = *(_DWORD *)(v5 + 664);
  _X0 = (unsigned int *)(v5 + 664);
  if ( v6 )
  {
    do
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v14 = __ldxr(_X0);
      while ( v14 == v6 && __stxr(v6 + 1, _X0) );
      v8 = v6;
      if ( v14 == v6 )
        break;
      v8 = 0;
      v6 = v14;
    }
    while ( v14 );
  }
  else
  {
    v8 = 0;
  }
  if ( (((v8 + 1) | v8) & 0x80000000) != 0 )
  {
    refcount_warn_saturate(_X0, 0);
    v15 = *(_QWORD *)(v5 + 128);
    if ( v8 )
      goto LABEL_12;
LABEL_297:
    dev_err(
      *(_QWORD *)(v15 + 168),
      "%s : Failed to get user-obj for %s, fl (%pK)\n",
      "fastrpc_device_ioctl",
      (const char *)(_ReadStatusReg(SP_EL0) + 2320),
      (const void *)v5);
    result = -2;
    goto LABEL_578;
  }
  v15 = *(_QWORD *)(v5 + 128);
  if ( !v8 )
    goto LABEL_297;
LABEL_12:
  _X0 = (unsigned int *)(v15 + 51664);
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v208 = __ldxr(_X0);
    while ( __stxr(v208 + 1, _X0) );
    if ( v208 )
    {
      if ( (((v208 + 1) | v208) & 0x80000000) == 0 )
        goto LABEL_14;
      v161 = 1;
    }
    else
    {
      v161 = 2;
    }
    refcount_warn_saturate(_X0, v161);
LABEL_14:
    v17 = raw_spin_lock_irqsave(v15 + 51600);
    if ( *(_DWORD *)(v15 + 64136) )
    {
      raw_spin_unlock_irqrestore(v15 + 51600, v17);
      fastrpc_channel_ctx_put(v15);
      fastrpc_file_put((__int64 *)v5, 0);
      result = -32;
      goto LABEL_578;
    }
    ++*(_DWORD *)(v15 + 64180);
    raw_spin_unlock_irqrestore(v15 + 51600, v17);
    LODWORD(v19) = -25;
    if ( (int)v4 > -1071623675 )
      break;
    if ( (int)v4 <= -1072672248 )
    {
      if ( (_DWORD)v4 != -1072672255 )
      {
        if ( (_DWORD)v4 == -1072672253 )
        {
          v342 = nullptr;
          v343 = nullptr;
          if ( inline_copy_from_user((__int64)&v342, a3, 0x10u) )
          {
            LODWORD(v19) = -14;
          }
          else
          {
            v370 = 0;
            v371 = 0;
            v368 = 0;
            v369 = nullptr;
            v366 = nullptr;
            v367 = 0;
            v364 = 0;
            v365 = 0;
            v362 = 0;
            v363 = 0;
            v360 = 0;
            v361 = 0;
            v358 = v343;
            v359 = nullptr;
            v357 = (__int64)v342;
            LODWORD(v19) = fastrpc_internal_invoke(v5, 0, (int *)&v357);
          }
          goto LABEL_575;
        }
        if ( (_DWORD)v4 != -1072672249 )
          goto LABEL_575;
        v327 = 0;
        v328 = 0;
        if ( *(_DWORD *)(v5 + 628) == 2 )
        {
          if ( inline_copy_from_user((__int64)&v327, a3, 0x10u) )
            goto LABEL_92;
          v20 = **(_QWORD **)(v5 + 136);
          raw_spin_lock(v5 + 320);
          v21 = (_QWORD *)(v5 + 64);
          v22 = *(_QWORD **)(v5 + 64);
          if ( v22 == (_QWORD *)(v5 + 64) )
          {
LABEL_119:
            raw_spin_unlock(v5 + 320);
          }
          else
          {
            while ( 1 )
            {
              v23 = (_QWORD *)*v22;
              if ( v22[18] == v327 && v22[9] == v328 )
                break;
              v22 = (_QWORD *)*v22;
              if ( v23 == v21 )
                goto LABEL_119;
            }
            v24 = (_QWORD *)v22[1];
            if ( (_QWORD *)*v24 == v22 && (_QWORD *)v23[1] == v22 )
            {
              v23[1] = v24;
              *v24 = v23;
            }
            else
            {
              _list_del_entry_valid_or_report(v22);
            }
            *v22 = 0xDEAD000000000100LL;
            v22[1] = 0xDEAD000000000122LL;
            raw_spin_unlock(v5 + 320);
            if ( v22 )
            {
              LODWORD(v19) = ((__int64 (__fastcall *)(__int64, _QWORD *))fastrpc_req_munmap_impl)(v5, v22);
              if ( (_DWORD)v19 )
              {
                raw_spin_lock(v5 + 320);
                v25 = *(_QWORD **)(v5 + 72);
                if ( v22 == v21 || v22 == v25 || (_QWORD *)*v25 != v21 )
                {
                  _list_add_valid_or_report(v22, v25, v5 + 64);
                }
                else
                {
                  *(_QWORD *)(v5 + 72) = v22;
                  *v22 = v21;
                  v22[1] = v25;
                  *v25 = v22;
                }
                raw_spin_unlock(v5 + 320);
                goto LABEL_575;
              }
              v160 = (__int64)v22;
              goto LABEL_564;
            }
          }
          v49 = raw_spin_lock_irqsave(*(_QWORD *)(v5 + 128) + 51600LL);
          v50 = *(_QWORD *)(v5 + 128);
          v51 = v49;
          v52 = *(_QWORD **)(v50 + 52744);
          if ( v52 == (_QWORD *)(v50 + 52744) )
          {
LABEL_135:
            raw_spin_unlock_irqrestore(v50 + 51600, v49);
          }
          else
          {
            while ( 1 )
            {
              v53 = (_QWORD *)*v52;
              if ( v52[18] == v327 && v52[9] == v328 )
                break;
              v52 = (_QWORD *)*v52;
              if ( v53 == (_QWORD *)(v50 + 52744) )
                goto LABEL_135;
            }
            v54 = (_QWORD *)v52[1];
            if ( (_QWORD *)*v54 == v52 && (_QWORD *)v53[1] == v52 )
            {
              v53[1] = v54;
              *v54 = v53;
            }
            else
            {
              _list_del_entry_valid_or_report(v52);
            }
            *v52 = 0xDEAD000000000100LL;
            v52[1] = 0xDEAD000000000122LL;
            raw_spin_unlock_irqrestore(*(_QWORD *)(v5 + 128) + 51600LL, v51);
            if ( v52 )
            {
              LODWORD(v19) = ((__int64 (__fastcall *)(__int64, _QWORD *))fastrpc_req_munmap_impl)(v5, v52);
              if ( (_DWORD)v19 )
              {
                v55 = raw_spin_lock_irqsave(*(_QWORD *)(v5 + 128) + 51600LL);
                v56 = *(_QWORD *)(v5 + 128);
                v57 = v56 + 49152;
                v58 = (_QWORD *)(v56 + 52744);
                v59 = v55;
                v60 = *(_QWORD **)(v57 + 3600);
                if ( v52 == v58 || v52 == v60 || (_QWORD *)*v60 != v58 )
                {
                  _list_add_valid_or_report(v52, v60, v58);
                }
                else
                {
                  *(_QWORD *)(v57 + 3600) = v52;
                  *v52 = v58;
                  v52[1] = v60;
                  *v60 = v52;
                }
                raw_spin_unlock_irqrestore(*(_QWORD *)(v5 + 128) + 51600LL, v59);
                goto LABEL_575;
              }
              v160 = (__int64)v52;
              goto LABEL_564;
            }
          }
          raw_spin_lock(v5 + 320);
          v61 = v5 + 16;
          do
          {
            v61 = *(_QWORD *)v61;
            if ( v61 == v5 + 16 )
            {
              LODWORD(v19) = -22;
              goto LABEL_405;
            }
          }
          while ( *(_QWORD *)(v61 + 96) != v327 );
          _X9 = (unsigned int *)(v61 + 120);
          __asm { PRFM            #0x11, [X9] }
          while ( 1 )
          {
            v216 = __ldxr(_X9);
            if ( v216 != 2 )
              break;
            if ( !__stlxr(3u, _X9) )
            {
              __dmb(0xBu);
              break;
            }
          }
          if ( v216 != 2 )
          {
            LODWORD(v19) = -114;
LABEL_405:
            raw_spin_unlock(v5 + 320);
LABEL_406:
            dev_err(v20, "buffer not in buf or map list\n");
            goto LABEL_575;
          }
          raw_spin_unlock(v5 + 320);
          if ( !v61 )
          {
            LODWORD(v19) = -22;
            goto LABEL_406;
          }
          v62 = *(_QWORD *)(v61 + 72);
          v63 = *(_DWORD *)(v5 + 244);
          *(_QWORD *)v333 = *(_QWORD *)(v61 + 96);
          v334 = v62;
          v342 = &v332;
          v343 = (_QWORD *)&_ksymtab_fastrpc_driver_unregister;
          v344 = 0;
          v370 = 0;
          v371 = 0;
          v368 = 0;
          v369 = nullptr;
          v366 = nullptr;
          v367 = 0;
          v364 = 0;
          v365 = 0;
          v362 = 0;
          v363 = 0;
          v360 = 0;
          v361 = 0;
          v332 = v63;
          v357 = 0x501000000000001LL;
          v358 = (__int64 *)&v342;
          v359 = nullptr;
          v64 = fastrpc_internal_invoke(v5, 1u, (int *)&v357);
          if ( v64 )
          {
            LODWORD(v19) = v64;
            dev_err(v20, "unmmap\tpt fd = %d, 0x%09llx error\n", *(_DWORD *)(v61 + 24), *(_QWORD *)(v61 + 96));
            *(_DWORD *)(v61 + 120) = 2;
            goto LABEL_575;
          }
          *(_DWORD *)(v61 + 120) = 0;
          mutex_lock(v5 + 328);
          _X0 = (unsigned int *)(v61 + 112);
          __asm { PRFM            #0x11, [X0] }
          do
            v213 = __ldxr(_X0);
          while ( __stlxr(v213 - 1, _X0) );
          if ( v213 == 1 )
          {
            __dmb(9u);
            v48 = v61;
            goto LABEL_144;
          }
LABEL_409:
          if ( v213 <= 0 )
            refcount_warn_saturate(_X0, 3);
          goto LABEL_411;
        }
        dev_err(
          *(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL),
          " %s: %s: trying to unmap buf before creating remote session\n",
          "fastrpc_req_munmap",
          _ReadStatusReg(SP_EL0) + 2320);
LABEL_204:
        LODWORD(v19) = -112;
        goto LABEL_575;
      }
      v342 = nullptr;
      v343 = nullptr;
      v365 = 0;
      v363 = 0;
      v364 = 0;
      v332 = 0;
      v359 = nullptr;
      v360 = 0;
      v361 = 0;
      v362 = 0;
      v357 = (__int64)"frpc_adsprpc";
      v358 = (__int64 *)&_this_module;
      if ( inline_copy_from_user((__int64)&v342, a3, 0x10u) || !v343 )
        goto LABEL_92;
      if ( *(_QWORD *)(v5 + 136) )
      {
        LODWORD(v19) = fastrpc_smmu_buf_alloc(v5, (unsigned __int64)v343, 3u, (__int64)&v332);
        if ( !(_DWORD)v19 )
        {
          v19 = v332;
          LODWORD(v361) = 2;
          v359 = &fastrpc_dma_buf_ops;
          v360 = (unsigned __int64)v343;
          v363 = v332;
          v28 = dma_buf_export(&v357);
          *(_QWORD *)(v19 + 24) = v28;
          if ( v28 < 0xFFFFFFFFFFFFF001LL )
          {
            LODWORD(v342) = dma_buf_fd();
            if ( ((unsigned int)v342 & 0x80000000) != 0 )
            {
              dma_buf_put(*(_QWORD *)(v19 + 24));
              LODWORD(v19) = -22;
            }
            else if ( inline_copy_to_user(a3, (__int64)&v342, 0x10u) )
            {
              LODWORD(v19) = -14;
            }
            else
            {
              LODWORD(v19) = 0;
            }
          }
          else
          {
            v29 = v28;
            fastrpc_buf_free(v19, 0);
            LODWORD(v19) = v29;
          }
        }
        goto LABEL_575;
      }
LABEL_87:
      LODWORD(v19) = -22;
      goto LABEL_575;
    }
    if ( (_DWORD)v4 != -1072672247 )
    {
      if ( (_DWORD)v4 != -1072147963 )
      {
        if ( (_DWORD)v4 != -1071885811 )
          goto LABEL_575;
        LODWORD(v335) = 0;
        *(_QWORD *)v333 = 0;
        v334 = 0;
        v332 = 0;
        if ( inline_copy_from_user((__int64)&v332, a3, 0x1Cu) )
          goto LABEL_92;
        v26 = v332;
        v333[0] = 0;
        if ( (unsigned int)v332 >= 5 )
        {
          mutex_lock(&unk_26CD8);
          v27 = 0;
          while ( 1 )
          {
            v39 = *(__int64 **)&g_frpc[2 * v27 + 26];
            if ( v39 )
              break;
LABEL_99:
            if ( ++v27 == 256 )
            {
              mutex_unlock(&unk_26CD8);
              dev_err(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL), "Error: Invalid domain id:%d, err:%d\n", v332, 0);
              LODWORD(v19) = -44;
              goto LABEL_575;
            }
          }
          while ( *((_DWORD *)v39 + 4) != v26 )
          {
            v39 = (__int64 *)*v39;
            if ( !v39 )
              goto LABEL_99;
          }
          mutex_unlock(&unk_26CD8);
        }
        v37 = HIDWORD(v332);
        v66 = *(_QWORD *)(v5 + 128);
        if ( HIDWORD(v332) >= 0x100 )
        {
          dev_err(*(_QWORD *)(v66 + 168), "Error: invalid attribute: %d, err: %d\n", HIDWORD(v332), 0);
          LODWORD(v19) = -75;
          goto LABEL_575;
        }
        v67 = 51600;
        v68 = v332;
        v69 = raw_spin_lock_irqsave(v66 + 51600);
        v70 = *(_BYTE *)(v66 + 51668);
        raw_spin_unlock_irqrestore(v66 + 51600, v69);
        if ( (v70 & 1) == 0 )
        {
          LODWORD(v310) = v68;
          v71 = (_DWORD *)_kmalloc_cache_noprof(wait_for_completion_interruptible_timeout, 3520, 1024);
          if ( !v71 )
            goto LABEL_574;
LABEL_156:
          HIDWORD(v344) = 0;
          *v71 = 0;
          v345 = (unsigned __int64 *)(v71 + 1);
          LODWORD(v327) = 255;
          v346 = 1020;
          v342 = &v327;
          v343 = (_QWORD *)&unk_4;
          LODWORD(v344) = -1;
          v347 = 0xFFFFFFFFLL;
          v370 = 0;
          v371 = 0;
          v368 = 0;
          v369 = nullptr;
          v366 = nullptr;
          v367 = 0;
          v364 = 0;
          v365 = 0;
          v362 = 0;
          v363 = 0;
          v360 = 0;
          v361 = 0;
          v359 = nullptr;
          v357 = 0x1010000000002LL;
          v358 = (__int64 *)&v342;
          v72 = fastrpc_internal_invoke(v5, 1u, (int *)&v357);
          if ( v72 )
          {
            LODWORD(v19) = v72;
            if ( v72 == -2147482604 )
            {
              dev_info(*(_QWORD *)(v66 + 168), "Warning: DSP capabilities not supported on domain: %d\n", v310);
              kfree(v71);
              LODWORD(v19) = -95;
            }
            else
            {
              kfree(v71);
            }
            goto LABEL_575;
          }
          v90 = raw_spin_lock_irqsave(v66 + v67);
          memcpy((void *)(v66 + 51672), v71, 0x400u);
          *(_BYTE *)(v66 + 51668) = 1;
          raw_spin_unlock_irqrestore(v66 + v67, v90);
          kfree(v71);
        }
        StatusReg = _ReadStatusReg(SP_EL0);
        v92 = *(_BYTE *)(StatusReg + 70);
        v333[0] = *(_DWORD *)(v66 + 4 * v37 + 51672);
        if ( (v92 & 0x20) != 0 || (v93 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v93 = a3 & ((__int64)(a3 << 8) >> 8);
        if ( v93 > 0x7FFFFFFFE4LL )
          goto LABEL_92;
        v94 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v96 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v96 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v96);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v94);
        v97 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v332, 28);
        v98 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v100 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v100 - 4096);
        _WriteStatusReg(TTBR1_EL1, v100);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v98);
LABEL_211:
        if ( v97 )
          LODWORD(v19) = -14;
        else
          LODWORD(v19) = 0;
        goto LABEL_575;
      }
      v37 = *(unsigned int *)(v5 + 600);
      v19 = *(unsigned int *)(v5 + 604);
      v328 = 0;
      v329 = 0;
      v327 = 0;
      v373 = 0;
      v374 = 0;
      v371 = 0;
      v372 = nullptr;
      v369 = nullptr;
      v370 = 0;
      v367 = 0;
      v368 = 0;
      v365 = 0;
      v366 = nullptr;
      v363 = 0;
      v364 = 0;
      v361 = 0;
      v362 = 0;
      v359 = nullptr;
      v360 = 0;
      v357 = 0;
      v358 = nullptr;
      v355 = 0;
      v356 = 0;
      v353 = 0;
      v354 = 0;
      v351 = nullptr;
      v352 = 0;
      v349 = 0;
      v350 = 0;
      v347 = 0;
      v348 = nullptr;
      v345 = nullptr;
      v346 = 0;
      v343 = nullptr;
      v344 = 0;
      v341 = 0;
      v342 = nullptr;
      v339 = 0;
      v340 = 0;
      v337 = 0;
      v338 = 0;
      v335 = 0;
      v336 = 0;
      *(_QWORD *)v333 = 0;
      v334 = 0;
      v332 = 0;
      v316 = 0;
      v323[0] = 0;
      v325 = 0;
      v326[0] = 0;
      v324 = 0;
      if ( inline_copy_from_user((__int64)&v327, a3, 0x18u) )
      {
LABEL_94:
        LODWORD(v19) = -14;
        goto LABEL_568;
      }
      if ( (unsigned int)v327 > 0x500000 )
      {
LABEL_106:
        LODWORD(v19) = -22;
        goto LABEL_568;
      }
      _X8 = (unsigned int *)(v5 + 628);
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v219 = __ldxr(_X8);
        if ( v219 )
          break;
        if ( !__stlxr(1u, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      if ( v219 )
      {
        LODWORD(v19) = -114;
        goto LABEL_568;
      }
      if ( v327 > 0 )
      {
        a3 = 0;
        goto LABEL_425;
      }
      if ( !(_DWORD)v327 || !v329 )
      {
        a3 = 0;
        v329 = 0;
        LODWORD(v327) = 0;
        goto LABEL_425;
      }
      v220 = _kmalloc_noprof((unsigned int)v327, 3520);
      a3 = v220;
      if ( !v220 )
      {
        LODWORD(v19) = -12;
        goto LABEL_567;
      }
      v221 = (unsigned int)v327;
      if ( (v327 & 0x80000000) == 0 )
      {
        v222 = v329;
        _check_object_size(v220, (unsigned int)v327, 0);
        if ( inline_copy_from_user(a3, v222, v221) )
          goto LABEL_423;
LABEL_425:
        v223 = _ReadStatusReg(SP_EL0);
        v224 = *(_DWORD *)(v223 + 1804);
        v225 = *(_DWORD *)(v5 + 240);
        *(_DWORD *)(v5 + 248) = v224;
        if ( v224 != v225 )
        {
          *(_BYTE *)(v5 + 625) = 1;
          snprintf((char *)(v5 + 252), 0x10u, "%s", (const char *)(v223 + 2320));
        }
        v226 = v328;
        if ( (v328 & 8) != 0 )
        {
          v227 = 1;
          *(_BYTE *)(v5 + 306) = 1;
        }
        else
        {
          v227 = *(_BYTE *)(v5 + 306);
        }
        v228 = *(_BYTE *)(v5 + 304);
        LODWORD(v328) = v226 & 0xFFFDFFFF;
        if ( (v228 & 1) != 0
          || (v229 = *(_QWORD *)(v5 + 128), *(_BYTE *)(v229 + 64105) != 1)
          || (unsigned __int8)(*(_BYTE *)(v229 + 64106) & v227) == 1 )
        {
          if ( (v227 & 1) != 0 || !*(_BYTE *)(v5 + 625) )
          {
            if ( (*(_BYTE *)(v5 + 625) & 1) != 0 )
            {
              if ( (v227 & 1) == 0 )
                goto LABEL_442;
            }
            else
            {
              if ( (v227 & 1) == 0 )
                goto LABEL_442;
              LODWORD(v328) = v226 | 0x20000;
            }
            if ( *(_BYTE *)(*(_QWORD *)(v5 + 128) + 64176LL) == 1 )
              *(_DWORD *)(v5 + 268) = 9;
LABEL_442:
            v230 = fastrpc_session_alloc(v5, 0, *(_DWORD *)(v5 + 268));
            if ( v230 )
            {
              *(_QWORD *)(v5 + 136) = v230;
              v307 = a3;
              v310 = v223;
              v66 = *(_QWORD *)(*(_QWORD *)(v223 + 2304) + 160LL);
              LODWORD(v328) = v328 & 0xFFFFFFBF;
              if ( v66
                && (a3 = (unsigned int)(*(_DWORD *)(v66 + 4) + 1), (a3 & 0x80000000) == 0)
                && (v231 = 4LL * (unsigned int)(*(_DWORD *)(v66 + 4) + 1),
                    v232 = (_DWORD *)_kmalloc_noprof(v231, 3520),
                    (v67 = (__int64)v232) != 0) )
              {
                v233 = v231 - 4;
                if ( v231 < 4 )
                  goto LABEL_518;
                *v232 = *(_DWORD *)(*(_QWORD *)(v310 + 2304) + 12LL);
                if ( (int)a3 >= 2 )
                {
                  v234 = 0;
                  while ( v231 >= v234 + 4 )
                  {
                    if ( v233 < 4 )
                      break;
                    if ( (__int64)(v234 + 4) < 0 )
                      break;
                    if ( v231 < v234 + 4 )
                      break;
                    _CF = v233 >= 4;
                    v233 -= 4LL;
                    if ( !_CF )
                      break;
                    v232[v234 / 4 + 1] = *(_DWORD *)(v66 + 8 + v234);
                    v234 += 4LL;
                    if ( 4LL * (unsigned int)a3 - 4 == v234 )
                      goto LABEL_456;
                  }
LABEL_518:
                  __break(1u);
LABEL_519:
                  _fortify_panic(2);
                  goto LABEL_520;
                }
LABEL_456:
                sort(v232, (int)a3, 4, uint_cmp_func, 0);
                v66 = v310;
                if ( (_DWORD)a3 )
                {
                  v235 = *(_QWORD *)(v5 + 128);
                  if ( *(_DWORD *)(v235 + 52736) )
                  {
                    v236 = 0;
                    v237 = 0;
                    do
                    {
                      v238 = 4LL * v237;
                      _CF = v231 >= v238;
                      v239 = v231 - v238;
                      if ( !_CF )
                        goto LABEL_518;
                      if ( v239 < 4 )
                        goto LABEL_518;
                      v240 = 4LL * v237;
                      _CF = v231 >= v240;
                      v241 = v231 - v240;
                      if ( !_CF || v241 < 4 )
                        goto LABEL_518;
                      v242 = *(_DWORD *)(v67 + 4LL * v237);
                      v243 = *(_DWORD *)(*(_QWORD *)(v235 + 52728) + 4 * v236);
                      if ( v242 >= v243 )
                      {
                        if ( v242 <= v243 )
                        {
                          if ( v242 )
                          {
                            dev_info(
                              *(_QWORD *)(v235 + 168),
                              "%s: %s (PID %d, GID %u) is a privileged process\n",
                              "fastrpc_check_privileged_process",
                              (const char *)(v310 + 2320),
                              *(_DWORD *)(v310 + 1804),
                              v242);
                            LODWORD(v328) = v328 | 0x40;
                          }
                          break;
                        }
                        ++v236;
                      }
                      else
                      {
                        ++v237;
                      }
                    }
                    while ( v237 < (unsigned int)a3 && v236 < *(unsigned int *)(v235 + 52736) );
                  }
                }
                kfree(v67);
              }
              else
              {
                dev_info(
                  *(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL),
                  "%s failed to get gidlist\n",
                  "fastrpc_check_privileged_process");
                v66 = v310;
              }
              v67 = v66 + 2320;
              LODWORD(v324) = *(_DWORD *)(v5 + 244);
              v244 = strnlen((const char *)(v66 + 2320), 0x10u);
              if ( v244 >= 0x11 )
                goto LABEL_519;
              if ( v244 == 16 )
              {
LABEL_520:
                _fortify_panic(4);
                v263 = _ReadStatusReg(SP_EL0);
                v264 = *(_QWORD *)(v263 + 80);
                *(_QWORD *)(v263 + 80) = &fastrpc_get_info_from_kernel__alloc_tag;
                v308 = v264;
                v71 = (_DWORD *)_kmalloc_cache_noprof(wait_for_completion_interruptible_timeout, 3520, 1024);
                *(_QWORD *)(v263 + 80) = v308;
                if ( !v71 )
                  goto LABEL_574;
                goto LABEL_156;
              }
              v245 = *(_DWORD *)(v5 + 268);
              HIDWORD(v324) = v244 + 1;
              v325 = (unsigned int)v327 | 0x100000000LL;
              v326[0] = v328;
              if ( !v245 )
                *(_DWORD *)(v5 + 268) = 7;
              if ( (_DWORD)v37 == -1 || (int)v19 < 1 )
              {
LABEL_486:
                fastrpc_alloc_rootheap_buf(*(_QWORD *)(v5 + 128), &v332, (char *)&v325 + 4);
                fastrpc_pack_root_sharedpage(v5, &v332, (char *)&v325 + 4);
                v247 = 4 * v327;
                if ( 4 * (int)v327 <= 5242880 )
                  v247 = 5242880;
                LODWORD(v19) = fastrpc_smmu_buf_alloc(v5, (int)((v247 + 0xFFFFF) & 0xFFF00000), 2u, (__int64)v323);
                if ( !(_DWORD)v19 )
                {
                  if ( *(_DWORD *)(*(_QWORD *)(v5 + 128) + 52208LL) )
                  {
                    v248 = fastrpc_smmu_buf_alloc(v5, 0x100000u, 6u, v5 + 200);
                    v249 = *(_QWORD *)(v5 + 200);
                    if ( v248 )
                    {
                      if ( v249 )
                      {
                        fastrpc_buf_free(v249, 0);
                        *(_QWORD *)(v5 + 200) = 0;
                      }
                      dev_err(
                        *(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL),
                        "Error 0x%x: %s: Failed to allocate dbglogbuf buffer size %d\n",
                        v248,
                        "fastrpc_init_create_process",
                        0x100000);
                    }
                    else
                    {
                      v250 = *(_QWORD *)(v249 + 72);
                      v340 = *(_QWORD *)(v249 + 64);
                      v341 = v250;
                      HIDWORD(v325) = 5;
                    }
                  }
                  v357 = (__int64)&v324;
                  v358 = (_QWORD *)&_ksymtab_fastrpc_driver_unregister;
                  v251 = v323[0];
                  v252 = HIDWORD(v324);
                  v253 = (unsigned int)v325;
                  *(_QWORD *)(v5 + 160) = v323[0];
                  LODWORD(v359) = -1;
                  v360 = v66 + 2320;
                  v361 = v252;
                  v254 = v329;
                  LODWORD(v362) = -1;
                  if ( v307 )
                    v254 = v307;
                  v363 = v254;
                  v364 = v253;
                  LODWORD(v365) = HIDWORD(v327);
                  v256 = *(_QWORD **)(v251 + 64);
                  v255 = *(_QWORD *)(v251 + 72);
                  LODWORD(v368) = -1;
                  LODWORD(v371) = -1;
                  LODWORD(v374) = -1;
                  v332 = (__int64)v256;
                  *(_QWORD *)v333 = v255;
                  v366 = &v332;
                  v367 = 16LL * HIDWORD(v325);
                  v369 = v326;
                  v370 = 4;
                  v372 = (char *)v326 + 4;
                  v373 = 4;
                  if ( (_DWORD)v328 )
                    v257 = 117702656;
                  else
                    v257 = 100925440;
                  LODWORD(v342) = 1;
                  HIDWORD(v342) = v257;
                  v343 = &v357;
                  v258 = fastrpc_internal_invoke(v5, 1u, (int *)&v342);
                  if ( !v258 )
                  {
                    if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 24LL) + 60LL) == 1 )
                      fastrpc_create_persistent_headers(v5);
                    if ( v5 )
                      fastrpc_create_session_debugfs(v5);
                    v262 = *(_QWORD *)(v5 + 176);
                    if ( v262 )
                    {
                      fastrpc_buf_free(v262, 0);
                      *(_QWORD *)(v5 + 176) = 0;
                    }
                    kfree(v307);
                    LODWORD(v19) = 0;
                    goto LABEL_568;
                  }
                  LODWORD(v19) = v258;
                  raw_spin_lock(v5 + 320);
                  *(_QWORD *)(v5 + 160) = 0;
                  raw_spin_unlock(v5 + 320);
                  fastrpc_buf_free(v251, 0);
                }
                v259 = *(_QWORD *)(v5 + 176);
                if ( v259 )
                {
                  fastrpc_buf_free(v259, 0);
                  *(_QWORD *)(v5 + 176) = 0;
                }
                v260 = v316;
                a3 = v307;
                if ( v316 )
                {
                  mutex_lock(v5 + 328);
                  fastrpc_map_put(v260);
                  mutex_unlock(v5 + 328);
                }
                v261 = *(_QWORD *)(v5 + 200);
                if ( v261 )
                {
                  fastrpc_buf_free(v261, 0);
                  *(_QWORD *)(v5 + 200) = 0;
                }
              }
              else
              {
                mutex_lock(v5 + 328);
                LODWORD(v19) = fastrpc_map_create(v5, (unsigned int)v37, 0, 0, v19, 0, 0, &v316, 1u);
                mutex_unlock(v5 + 328);
                a3 = v307;
                if ( !(_DWORD)v19 )
                {
                  HIDWORD(v325) = 2;
                  v246 = *(_QWORD *)(v316 + 72);
                  v334 = *(_QWORD *)(v316 + 64);
                  v335 = v246;
                  goto LABEL_486;
                }
              }
            }
            else
            {
              if ( (unsigned int)__ratelimit(&fastrpc_init_create_process__rs, "fastrpc_init_create_process") )
                dev_warn(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL), "No session available\n");
              LODWORD(v19) = -16;
            }
LABEL_567:
            kfree(a3);
            *(_DWORD *)(v5 + 628) = 0;
            goto LABEL_568;
          }
          v229 = *(_QWORD *)(v5 + 128);
        }
        dev_err(*(_QWORD *)(v229 + 168), "Error: Untrusted application trying to offload to signed PD");
        LODWORD(v19) = -13;
        goto LABEL_567;
      }
      __break(0x800u);
LABEL_423:
      dev_err(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL), "copy_from_user failed for shell file\n");
      LODWORD(v19) = -14;
      goto LABEL_567;
    }
    v35 = *(_BYTE *)(v5 + 304);
    v332 = 0;
    *(_QWORD *)v333 = 0;
    v349 = 0;
    v350 = 0;
    v347 = 0;
    v348 = nullptr;
    v345 = nullptr;
    v346 = 0;
    v343 = nullptr;
    v344 = 0;
    v342 = nullptr;
    v327 = 0;
    v328 = 0;
    v316 = 0;
    LODWORD(v325) = 0;
    v324 = 0;
    if ( (v35 & 1) == 0 )
    {
      dev_err(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL), "untrusted app trying to attach to privileged DSP PD\n");
      LODWORD(v19) = -13;
      goto LABEL_568;
    }
    if ( inline_copy_from_user((__int64)&v332, a3, 0x10u) )
      goto LABEL_94;
    if ( (unsigned int)(v332 - 1) > 0x7F )
      goto LABEL_106;
    v36 = memdup_user_nul(*(_QWORD *)v333);
    a3 = v36;
    if ( v36 >= 0xFFFFFFFFFFFFF001LL )
    {
      LODWORD(v19) = v36;
      goto LABEL_568;
    }
    v76 = fastrpc_session_alloc(v5, 0, *(_DWORD *)(v5 + 268));
    if ( !v76 )
    {
      dev_err(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL), "No session available\n");
      LODWORD(v19) = -16;
      goto LABEL_242;
    }
    v4 = (_QWORD *)v76;
    *(_QWORD *)(v5 + 136) = v76;
    v77 = strcmp((const char *)a3, "oispd");
    v78 = strcmp((const char *)a3, "audiopd");
    if ( v78 && v77 )
    {
      dev_err(*v4, "Create static process is failed for proc_name %s", (const char *)a3);
      LODWORD(v19) = -22;
      goto LABEL_242;
    }
    v79 = "ois_pdr_adsprpc";
    if ( v78 )
      v80 = 5;
    else
      v80 = 2;
    LODWORD(v357) = 0;
    if ( !v78 )
      v79 = "audio_pdr_adsp";
    *(_DWORD *)(v5 + 268) = v80;
    *(_QWORD *)(v5 + 312) = v79;
    if ( !v5 )
    {
      LODWORD(v19) = -9;
      goto LABEL_242;
    }
    _X0 = (unsigned int *)fastrpc_get_static_pd_session(v5, &v357);
    LODWORD(v19) = (_DWORD)_X0;
    if ( (_DWORD)_X0 )
      goto LABEL_242;
    v81 = v357;
    if ( (unsigned int)v357 < 4 )
    {
      v82 = *(_QWORD *)(v5 + 128) + 51376LL;
      if ( !*(_DWORD *)(v82 + 56LL * (unsigned int)v357 + 40) )
      {
        LODWORD(v19) = -107;
        goto LABEL_242;
      }
      v83 = v82 + 56LL * (unsigned int)v357;
      v86 = *(_DWORD *)(v83 + 44);
      _X9 = (unsigned int *)(v83 + 44);
      v85 = v86;
      do
      {
        if ( v85 == 1 )
        {
          dev_err(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL), "Application already attached to audio PD\n");
          LODWORD(v19) = -111;
          goto LABEL_242;
        }
        __asm { PRFM            #0x11, [X9] }
        while ( 1 )
        {
          v88 = __ldxr(_X9);
          if ( v88 != v85 )
            break;
          if ( !__stlxr(v85 + 1, _X9) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v88 == v85;
        v85 = v88;
      }
      while ( !_ZF );
      v162 = *(_QWORD *)(v5 + 128);
      v163 = v162 + 56LL * v81 + 51376;
      *(_QWORD *)(v5 + 184) = v163;
      if ( !v78 && v163 && *(_QWORD *)(v163 + 24) != *(_QWORD *)(v163 + 32) )
      {
        v179 = fastrpc_mmap_remove_ssr(v162, 1);
        if ( !v179 )
        {
          v163 = *(_QWORD *)(v5 + 184);
          goto LABEL_307;
        }
        LODWORD(v19) = v179;
        printk(&unk_24E6B, _ReadStatusReg(SP_EL0) + 2320, "fastrpc_init_create_static_process", v179, v180, v181);
LABEL_242:
        kfree(a3);
LABEL_568:
        if ( (_DWORD)v19 )
          goto LABEL_575;
        v303 = _kmalloc_cache_noprof(wait_for_completion_interruptible_timeout, 3520, 952);
        if ( v303 )
        {
          *(_QWORD *)(v303 + 936) = v5;
          *(_DWORD *)(v303 + 928) = *(_DWORD *)(v5 + 244);
          *(_QWORD *)(v5 + 208) = v303;
          *(_DWORD *)(v5 + 628) = 2;
          v304 = *(_DWORD *)(v5 + 268);
          if ( v304 == 9 || v304 == 7 )
            fastrpc_sysfs_notify_pids(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 24LL));
          goto LABEL_573;
        }
LABEL_574:
        LODWORD(v19) = -12;
        goto LABEL_575;
      }
LABEL_307:
      v370 = 0;
      v371 = 0;
      v164 = nullptr;
      v368 = 0;
      v369 = nullptr;
      v165 = 1;
      v166 = 0;
      v366 = nullptr;
      v367 = 0;
      v364 = 0;
      v365 = 0;
      v362 = 0;
      v363 = 0;
      v360 = 0;
      v361 = 0;
      v167 = *(_QWORD *)(v163 + 24);
      v358 = nullptr;
      v359 = nullptr;
      v357 = 0;
      *(_QWORD *)(v163 + 32) = v167;
      v168 = v332;
      v169 = *(_QWORD *)(v5 + 128);
      LODWORD(v167) = *(_DWORD *)(v5 + 244);
      LODWORD(v325) = 0;
      LOBYTE(v169) = *(_BYTE *)(v169 + 51670);
      v170 = 0;
      v324 = __PAIR64__(v332, v167);
      if ( (v169 & 1) == 0 && v77 )
      {
        LODWORD(v325) = 1;
        LODWORD(v19) = fastrpc_buf_alloc(v5, 0, HIDWORD(v332), 4u, &v316);
        if ( (_DWORD)v19 )
          goto LABEL_242;
        v171 = *(_QWORD *)(v5 + 128);
        v164 = (_QWORD *)v316;
        v172 = *(unsigned int *)(v171 + 8);
        v173 = *(_QWORD *)(v316 + 72);
        v165 = (_DWORD)v172 == 0;
        v311 = *(_QWORD *)(v316 + 64);
        if ( (_DWORD)v172 )
        {
          v323[0] = 8;
          v174 = qcom_scm_assign_mem(v311, v173, v323, v171 + 32, v172);
          if ( v174 )
          {
            LODWORD(v19) = v174;
            dev_err(
              *v4,
              "%s: Failed to assign memory with phys 0x%llx size 0x%llx err %d",
              "fastrpc_init_create_static_process",
              v311,
              v173,
              v174);
LABEL_380:
            if ( !v164 )
              goto LABEL_242;
LABEL_361:
            *(_BYTE *)(*(_QWORD *)(v5 + 128) + 51670LL) = 0;
            fastrpc_buf_free((__int64)v164, 0);
            goto LABEL_242;
          }
          v171 = *(_QWORD *)(v5 + 128);
        }
        v168 = HIDWORD(v324);
        v166 = v311;
        *(_BYTE *)(v171 + 51670) = 1;
        v170 = v173;
      }
      v342 = &v324;
      v343 = (_QWORD *)&_ksymtab_fastrpc_driver_register;
      v345 = (unsigned __int64 *)a3;
      v346 = v168;
      v348 = &v327;
      v349 = 16;
      LODWORD(v344) = -1;
      LODWORD(v347) = -1;
      v175 = v170;
      LODWORD(v350) = -1;
      v312 = v166;
      v327 = v166;
      v328 = v170;
      v357 = 0x803000000000001LL;
      v358 = (__int64 *)&v342;
      _X0 = (unsigned int *)fastrpc_internal_invoke(v5, 1u, (int *)&v357);
      if ( !(_DWORD)_X0 )
      {
        fastrpc_create_session_debugfs(v5);
        kfree(a3);
        if ( v164 )
        {
          v182 = raw_spin_lock_irqsave(*(_QWORD *)(v5 + 128) + 51600LL);
          _list_add(v164, *(_QWORD **)(*(_QWORD *)(v5 + 128) + 52752LL), *(_QWORD *)(v5 + 128) + 52744LL);
          raw_spin_unlock_irqrestore(*(_QWORD *)(v5 + 128) + 51600LL, v182);
        }
        LODWORD(v19) = 0;
        goto LABEL_568;
      }
      v176 = *(_DWORD **)(v5 + 128);
      v177 = v176[2];
      if ( v177 )
        v178 = v165;
      else
        v178 = 1;
      if ( (v178 & 1) != 0 )
      {
        LODWORD(v19) = (_DWORD)_X0;
        if ( !v164 )
          goto LABEL_242;
        goto LABEL_361;
      }
      v183 = 1LL << v176[8];
      v315[0] = 0x700000003LL;
      v323[0] = v183;
      if ( v177 == 1 )
        goto LABEL_359;
      v184 = (1LL << v176[10]) | v183;
      v323[0] = v184;
      if ( v177 == 2 )
        goto LABEL_359;
      v185 = (1LL << v176[12]) | v184;
      v323[0] = v185;
      if ( v177 == 3 )
        goto LABEL_359;
      v186 = (1LL << v176[14]) | v185;
      v323[0] = v186;
      if ( v177 == 4 )
        goto LABEL_359;
      v187 = (1LL << v176[16]) | v186;
      v323[0] = v187;
      if ( v177 == 5 )
        goto LABEL_359;
      v188 = (1LL << v176[18]) | v187;
      v323[0] = v188;
      if ( v177 == 6 )
        goto LABEL_359;
      v189 = (1LL << v176[20]) | v188;
      v323[0] = v189;
      if ( v177 == 7 )
        goto LABEL_359;
      v190 = (1LL << v176[22]) | v189;
      v323[0] = v190;
      if ( v177 == 8 )
        goto LABEL_359;
      v191 = (1LL << v176[24]) | v190;
      v323[0] = v191;
      if ( v177 == 9 )
        goto LABEL_359;
      v192 = (1LL << v176[26]) | v191;
      v323[0] = v192;
      if ( v177 == 10 )
        goto LABEL_359;
      v193 = (1LL << v176[28]) | v192;
      v323[0] = v193;
      if ( v177 == 11 )
        goto LABEL_359;
      v194 = (1LL << v176[30]) | v193;
      v323[0] = v194;
      if ( v177 == 12
        || (v195 = (1LL << v176[32]) | v194, v323[0] = v195, v177 == 13)
        || (v196 = (1LL << v176[34]) | v195, v323[0] = v196, v177 == 14)
        || (v197 = (1LL << v176[36]) | v196, v323[0] = v197, v177 == 15)
        || (v323[0] = (1LL << v176[38]) | v197, v177 == 16) )
      {
LABEL_359:
        LODWORD(v19) = qcom_scm_assign_mem(v312, v175, v323, v315, 1);
        if ( !(_DWORD)v19 )
        {
          if ( !v164 )
            goto LABEL_242;
          goto LABEL_361;
        }
        dev_err(
          *v4,
          "%s: Failed to assign memory phys 0x%llx size 0x%llx err %d",
          "fastrpc_init_create_static_process",
          v312,
          v175,
          (unsigned int)v19);
        goto LABEL_380;
      }
    }
    __break(0x5512u);
  }
  if ( (int)v4 <= -1069526519 )
  {
    if ( (_DWORD)v4 != -1071623674 )
    {
      if ( (_DWORD)v4 != -1070575093 )
      {
        if ( (_DWORD)v4 != -1070050804 )
          goto LABEL_575;
        v370 = 0;
        v371 = 0;
        v368 = 0;
        v369 = nullptr;
        v366 = nullptr;
        v367 = 0;
        v364 = 0;
        v365 = 0;
        v362 = 0;
        v363 = 0;
        v360 = 0;
        v361 = 0;
        v358 = nullptr;
        v359 = nullptr;
        v357 = 0;
        v337 = 0;
        v338 = 0;
        v335 = 0;
        v336 = 0;
        *(_QWORD *)v333 = 0;
        v334 = 0;
        v332 = 0;
        v322 = 0;
        v321 = 0;
        v320 = 0;
        v318 = 0;
        v319 = 0;
        v316 = 0;
        v317 = 0;
        v315[0] = 0;
        v315[1] = 0;
        v350 = 0;
        v351 = nullptr;
        v348 = nullptr;
        v349 = 0;
        v346 = 0;
        v347 = 0;
        v344 = 0;
        v345 = nullptr;
        v342 = nullptr;
        v343 = nullptr;
        v325 = 0;
        memset(v326, 0, sizeof(v326));
        v324 = 0;
        memset(v323, 0, sizeof(v323));
        v314 = 0;
        if ( inline_copy_from_user((__int64)&v332, a3, 0x38u) )
          goto LABEL_92;
        LODWORD(v19) = -25;
        if ( (int)v332 > 6 )
        {
          if ( (int)v332 <= 9 )
          {
            if ( (_DWORD)v332 == 7 )
            {
              v134 = *(_QWORD *)v333;
              if ( v334 >= 0x18 )
                v135 = 24;
              else
                v135 = v334;
              _check_object_size(&v316, v135, 0);
              if ( inline_copy_from_user((__int64)&v316, v134, v135) )
                goto LABEL_92;
              v136 = HIDWORD(v316);
              v137 = v317;
              LODWORD(v19) = 0;
              *(_DWORD *)(v5 + 600) = v316;
              v138 = v318;
              *(_DWORD *)(v5 + 604) = v136;
              *(_QWORD *)(v5 + 608) = v137;
              *(_DWORD *)(v5 + 616) = v138;
            }
            else if ( (_DWORD)v332 == 8 )
            {
              if ( inline_copy_from_user((__int64)v315, *(unsigned __int64 *)v333, 0x10u) )
                goto LABEL_92;
              LODWORD(v19) = fastrpc_set_session_info(v5, v315);
            }
            else
            {
              if ( inline_copy_from_user((__int64)&v342, *(unsigned __int64 *)v333, 0x50u) )
                goto LABEL_92;
              LODWORD(v19) = fastrpc_multidomain_ctx_manage(v5, &v342);
            }
            goto LABEL_575;
          }
          if ( (_DWORD)v332 == 10 )
          {
            if ( inline_copy_from_user((__int64)&v324, *(unsigned __int64 *)v333, 0x28u) )
              goto LABEL_92;
            LODWORD(v19) = fastrpc_remote_process_state_dump(v5, &v324);
            goto LABEL_575;
          }
          if ( (_DWORD)v332 == 11 )
          {
            if ( inline_copy_from_user((__int64)v323, *(unsigned __int64 *)v333, 0x18u) )
              goto LABEL_92;
            LODWORD(v19) = fastrpc_user_set_rpc_timeout(v5, v323);
            goto LABEL_575;
          }
          if ( (_DWORD)v332 != 12 )
            goto LABEL_575;
          if ( inline_copy_from_user((__int64)&v314, *(unsigned __int64 *)v333, 4u) )
            goto LABEL_92;
          fastrpc_set_dsp_recovery_mode(v5, (unsigned int)v314);
        }
        else
        {
          if ( (int)v332 <= 3 )
          {
            if ( (_DWORD)v332 == 1 )
            {
              v133 = 16;
            }
            else
            {
              if ( (_DWORD)v332 != 2 )
              {
                if ( (_DWORD)v332 == 3 )
                {
                  if ( inline_copy_from_user((__int64)&v321, *(unsigned __int64 *)v333, 0xCu) )
                    goto LABEL_92;
                  LODWORD(v19) = fastrpc_internal_control(v5, &v321);
                }
                goto LABEL_575;
              }
              v133 = 120;
            }
            v143 = *(_QWORD *)v333;
            _check_object_size(&v357, v133, 0);
            if ( inline_copy_from_user((__int64)&v357, v143, v133) )
              goto LABEL_92;
            if ( v360 )
              *(_DWORD *)(v5 + 280) = 1;
            LODWORD(v19) = fastrpc_internal_invoke(v5, 0, (int *)&v357);
            goto LABEL_575;
          }
          if ( (_DWORD)v332 == 4 )
          {
            if ( v334 <= 0xC )
            {
              v139 = _kmalloc_cache_noprof(_init_swait_queue_head, 3520, 12);
              v140 = v139;
              if ( v139 )
              {
                v141 = v334;
                if ( v334 >= 0xD )
                {
                  _copy_overflow(12, v334);
                }
                else
                {
                  v142 = *(_QWORD *)v333;
                  _check_object_size(v139, v334, 0);
                  if ( !inline_copy_from_user(v140, v142, v141) )
                  {
                    LODWORD(v19) = fastrpc_invoke_dspsignal(v5, v140);
                    kfree(v140);
                    goto LABEL_575;
                  }
                }
                kfree(v140);
                LODWORD(v19) = -14;
                goto LABEL_575;
              }
              goto LABEL_574;
            }
            goto LABEL_87;
          }
          if ( (_DWORD)v332 == 5 )
          {
            v144 = v335;
            v145 = *(_QWORD *)v333;
            v146 = (__int64 **)(v5 + 584);
            if ( *(_DWORD *)(v5 + 544) )
              goto LABEL_270;
LABEL_264:
            v330 = 0;
            v331 = 0;
            v328 = 0;
            v329 = 0;
            v327 = 0;
            init_wait_entry(&v327, 0);
            v147 = prepare_to_wait_event(v5 + 552, &v327, 1);
            if ( !*(_DWORD *)(v5 + 544) )
            {
              v19 = v147;
              do
              {
                if ( v19 )
                {
                  if ( (_DWORD)v19 )
                    goto LABEL_575;
                  while ( 1 )
                  {
LABEL_270:
                    v148 = raw_spin_lock_irqsave(v5 + 576);
                    v149 = *v146;
                    v150 = v148;
                    if ( *v146 == (__int64 *)v146 )
                    {
                      raw_spin_unlock_irqrestore(v5 + 576, v148);
                    }
                    else
                    {
                      v151 = (__int64 **)v149[1];
                      if ( *v151 == v149 && (v152 = (__int64 *)*v149, *(__int64 **)(*v149 + 8) == v149) )
                      {
                        v152[1] = (__int64)v151;
                        *v151 = v152;
                      }
                      else
                      {
                        _list_del_entry_valid_or_report(*v146);
                      }
                      *v149 = 0xDEAD000000000100LL;
                      v149[1] = 0xDEAD000000000122LL;
                      _X8 = (unsigned int *)(v5 + 544);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v155 = __ldxr(_X8);
                      while ( __stxr(v155 - 1, _X8) );
                      raw_spin_unlock_irqrestore(v5 + 576, v150);
                      if ( v149 )
                      {
                        v156 = *((_DWORD *)v149 + 6);
                        v157 = *((_DWORD *)v149 + 4);
                        HIDWORD(v319) = *((_DWORD *)v149 + 5);
                        v320 = v156;
                        LODWORD(v319) = v157;
                        kfree(v149);
                        if ( !v144 )
                        {
                          mutex_lock(&unk_26CD8);
                          v158 = 0;
                          while ( 1 )
                          {
                            v159 = *(__int64 **)&g_frpc[2 * v158 + 26];
                            if ( v159 )
                              break;
LABEL_291:
                            if ( ++v158 == 256 )
                            {
                              v159 = nullptr;
                              goto LABEL_368;
                            }
                          }
                          while ( *((_DWORD *)v159 + 4) != v157 )
                          {
                            v159 = (__int64 *)*v159;
                            if ( !v159 )
                              goto LABEL_291;
                          }
LABEL_368:
                          mutex_unlock(&unk_26CD8);
                          if ( *((_BYTE *)v159 + 51) == 1 )
                            LODWORD(v319) = *((_DWORD *)v159 + 18);
                        }
                        v199 = _ReadStatusReg(SP_EL0);
                        if ( (*(_BYTE *)(v199 + 70) & 0x20) != 0 || (v200 = v145, (*(_QWORD *)v199 & 0x4000000) != 0) )
                          v200 = v145 & ((__int64)(v145 << 8) >> 8);
                        if ( v200 <= 0x7FFFFFFFF4LL )
                        {
                          v201 = _ReadStatusReg(DAIF);
                          __asm { MSR             DAIFSet, #3 }
                          v203 = *(_QWORD *)(v199 + 8);
                          _WriteStatusReg(
                            TTBR1_EL1,
                            v203 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                          _WriteStatusReg(TTBR0_EL1, v203);
                          __isb(0xFu);
                          _WriteStatusReg(DAIF, v201);
                          v97 = _arch_copy_to_user(v145 & 0xFF7FFFFFFFFFFFFFLL, &v319, 12);
                          v204 = _ReadStatusReg(DAIF);
                          __asm { MSR             DAIFSet, #3 }
                          v206 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                          _WriteStatusReg(TTBR0_EL1, v206 - 4096);
                          _WriteStatusReg(TTBR1_EL1, v206);
                          __isb(0xFu);
                          _WriteStatusReg(DAIF, v204);
                          goto LABEL_211;
                        }
LABEL_92:
                        LODWORD(v19) = -14;
                        goto LABEL_575;
                      }
                    }
                    dev_err(*(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL), "Invalid status notification response\n");
                    if ( !*(_DWORD *)(v5 + 544) )
                      goto LABEL_264;
                  }
                }
                schedule();
                v19 = prepare_to_wait_event(v5 + 552, &v327, 1);
              }
              while ( !*(_DWORD *)(v5 + 544) );
            }
            finish_wait(v5 + 552, &v327);
            goto LABEL_270;
          }
          if ( inline_copy_from_user((__int64)&v314 + 4, *(unsigned __int64 *)v333, 4u) )
            goto LABEL_92;
          if ( (*(_BYTE *)(v5 + 624) & 1) == 0 )
          {
            LODWORD(v19) = 0;
            *(_DWORD *)(v5 + 284) = 1;
            goto LABEL_575;
          }
        }
LABEL_573:
        LODWORD(v19) = 0;
        goto LABEL_575;
      }
      v346 = 0;
      v347 = 0;
      v344 = 0;
      v345 = nullptr;
      v342 = nullptr;
      v343 = nullptr;
      if ( *(_DWORD *)(v5 + 628) != 2 )
      {
        dev_err(
          *(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL),
          "%s: %s: trying to unmap buf before creating remote session\n",
          "fastrpc_req_mem_unmap",
          _ReadStatusReg(SP_EL0) + 2320);
        goto LABEL_204;
      }
      if ( inline_copy_from_user((__int64)&v342, a3, 0x30u) )
        goto LABEL_92;
      v40 = *(__int64 **)(v5 + 136);
      *(_QWORD *)v333 = 0;
      v334 = 0;
      v332 = 0;
      v328 = 0;
      v329 = 0;
      v327 = 0;
      v41 = *v40;
      raw_spin_lock(v5 + 320);
      v42 = *(_QWORD *)(v5 + 16);
      if ( v42 != v5 + 16 )
      {
        while ( 1 )
        {
          v43 = *(_QWORD *)v42;
          if ( ((HIDWORD(v342) & 0x80000000) != 0 || *(_DWORD *)(v42 + 24) == HIDWORD(v342))
            && *(__int64 **)(v42 + 96) == v343 )
          {
            break;
          }
          v42 = *(_QWORD *)v42;
          if ( v43 == v5 + 16 )
            goto LABEL_214;
        }
        v370 = 0;
        v371 = 0;
        v368 = 0;
        v369 = nullptr;
        v366 = nullptr;
        v367 = 0;
        v364 = 0;
        v365 = 0;
        v362 = 0;
        v363 = 0;
        v360 = 0;
        v361 = 0;
        v358 = nullptr;
        v359 = nullptr;
        v357 = 0;
        _X9 = (unsigned int *)(v42 + 120);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v211 = __ldxr(_X9);
          if ( v211 != 2 )
            goto LABEL_393;
        }
        while ( __stlxr(3u, _X9) );
        __dmb(0xBu);
LABEL_393:
        if ( v211 == 2 )
        {
          raw_spin_unlock(v5 + 320);
          if ( v42 )
          {
            v44 = *(_QWORD *)(v42 + 88);
            v45 = *(_DWORD *)(v5 + 244);
            v328 = *(_QWORD *)(v42 + 96);
            v329 = v44;
            v327 = __PAIR64__(*(_DWORD *)(v42 + 24), v45);
            v332 = (__int64)&v327;
            *(_QWORD *)v333 = 24;
            v357 = 0xB01000000000001LL;
            v358 = &v332;
            v46 = fastrpc_internal_invoke(v5, 1u, (int *)&v357);
            if ( v46 )
            {
              LODWORD(v19) = v46;
              dev_err(
                v41,
                "Unmap on DSP failed for fd:%d, addr:0x%09llx\n",
                *(_DWORD *)(v42 + 24),
                *(_QWORD *)(v42 + 96));
              *(_DWORD *)(v42 + 120) = 2;
              goto LABEL_575;
            }
            *(_DWORD *)(v42 + 120) = 0;
            mutex_lock(v5 + 328);
            _X0 = (unsigned int *)(v42 + 112);
            __asm { PRFM            #0x11, [X0] }
            do
              v213 = __ldxr(_X0);
            while ( __stlxr(v213 - 1, _X0) );
            if ( v213 != 1 )
              goto LABEL_409;
            __dmb(9u);
            v48 = v42;
LABEL_144:
            _fastrpc_free_map(v48);
LABEL_411:
            mutex_unlock(v5 + 328);
            goto LABEL_573;
          }
          LODWORD(v19) = -22;
        }
        else
        {
          LODWORD(v19) = -114;
LABEL_395:
          raw_spin_unlock(v5 + 320);
        }
        dev_err(v41, "map not in list\n");
        goto LABEL_575;
      }
LABEL_214:
      LODWORD(v19) = -22;
      goto LABEL_395;
    }
    v349 = 0;
    v350 = 0;
    v347 = 0;
    v348 = nullptr;
    v345 = nullptr;
    v346 = 0;
    v343 = nullptr;
    v344 = 0;
    v342 = nullptr;
    v316 = 0;
    v328 = 0;
    v329 = 0;
    v327 = 0;
    v323[0] = 0;
    v324 = 0;
    v325 = 0;
    v334 = 0;
    v335 = 0;
    v332 = 0;
    *(_QWORD *)v333 = 0;
    v315[0] = 0;
    if ( *(_DWORD *)(v5 + 628) != 2 )
    {
      dev_err(
        *(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL),
        "%s: %s: trying to map buf before creating remote session\n",
        "fastrpc_req_mmap",
        _ReadStatusReg(SP_EL0) + 2320);
      goto LABEL_204;
    }
    if ( inline_copy_from_user((__int64)&v332, a3, 0x20u) || !v334 )
      goto LABEL_92;
    v30 = *(__int64 **)(v5 + 136);
    v370 = 0;
    v371 = 0;
    v368 = 0;
    v369 = nullptr;
    v366 = nullptr;
    v367 = 0;
    v364 = 0;
    v365 = 0;
    v362 = 0;
    v363 = 0;
    v360 = 0;
    v361 = 0;
    v358 = nullptr;
    v359 = nullptr;
    v357 = 0;
    v31 = *v30;
    if ( HIDWORD(v332) == 4096 || HIDWORD(v332) == 8 )
    {
      if ( (*(_BYTE *)(v5 + 306) & 1) != 0 )
      {
        if ( HIDWORD(v332) != 8 )
          goto LABEL_73;
        dev_err(v31, "remote heap is not supported for unsigned PD\n");
LABEL_330:
        LODWORD(v19) = -22;
        goto LABEL_575;
      }
      if ( *(_QWORD *)v333 )
      {
        dev_err(v31, "adding user allocated pages is only supported for unsigned PD\n");
        goto LABEL_330;
      }
      if ( HIDWORD(v332) == 8 )
        v89 = fastrpc_buf_alloc(v5, 0, v334, 4u, &v316);
      else
        v89 = fastrpc_smmu_buf_alloc(v5, v334, 3u, (__int64)&v316);
      LODWORD(v19) = v89;
      if ( v89 )
      {
        dev_err(v31, "failed to allocate buffer\n");
        goto LABEL_575;
      }
      v101 = (__int64 *)v316;
      if ( HIDWORD(v332) == 4096 )
        v31 = **(_QWORD **)(v316 + 40);
      LODWORD(v327) = *(_DWORD *)(v5 + 244);
      HIDWORD(v327) = HIDWORD(v332);
      v328 = *(_QWORD *)v333;
      v342 = &v327;
      v343 = (_QWORD *)&_ksymtab_fastrpc_driver_unregister;
      v103 = *(_QWORD *)(v316 + 64);
      v102 = *(_QWORD *)(v316 + 72);
      LODWORD(v329) = 16;
      v324 = v103;
      v325 = v102;
      v345 = &v324;
      v346 = 16;
      v348 = v323;
      v349 = 8;
      v357 = 0x402010000000001LL;
      v358 = (__int64 *)&v342;
      v104 = fastrpc_internal_invoke(v5, 1u, (int *)&v357);
      if ( v104 )
      {
        LODWORD(v19) = v104;
        dev_err(v31, "mmap error (len 0x%08llx)\n", v101[9]);
      }
      else
      {
        v105 = v323[0];
        _ZF = HIDWORD(v332) == 8;
        v101[18] = v323[0];
        v335 = v105;
        if ( !_ZF )
          goto LABEL_231;
        v106 = *(_QWORD *)(v5 + 128);
        if ( !*(_DWORD *)(v106 + 8) )
        {
LABEL_226:
          v116 = raw_spin_lock_irqsave(v106 + 51600);
          v117 = *(_QWORD *)(v5 + 128);
          v118 = v117 + 49152;
          v119 = (__int64 *)(v117 + 52744);
          v120 = v116;
          v121 = *(__int64 **)(v118 + 3600);
          if ( v101 == v119 || v101 == v121 || (__int64 *)*v121 != v119 )
          {
            _list_add_valid_or_report(v101, v121, v119);
          }
          else
          {
            *(_QWORD *)(v118 + 3600) = v101;
            *v101 = (__int64)v119;
            v101[1] = (__int64)v121;
            *v121 = (__int64)v101;
          }
          raw_spin_unlock_irqrestore(*(_QWORD *)(v5 + 128) + 51600LL, v120);
          goto LABEL_236;
        }
        v321 = 8;
        v107 = ktime_get_with_offset(1);
        v108 = ns_to_timespec64(v107);
        v110 = v109;
        v111 = qcom_scm_assign_mem(
                 v101[8],
                 v101[9],
                 &v321,
                 *(_QWORD *)(v5 + 128) + 32LL,
                 *(unsigned int *)(*(_QWORD *)(v5 + 128) + 8LL));
        v112 = ktime_get_with_offset(1);
        v113 = ns_to_timespec64(v112);
        v101[22] = timespec64_sub(v113, v114, v108, v110);
        v101[23] = v115;
        if ( !v111 )
        {
          if ( HIDWORD(v332) == 8 )
          {
            v106 = *(_QWORD *)(v5 + 128);
            goto LABEL_226;
          }
LABEL_231:
          raw_spin_lock(v5 + 320);
          v122 = v5 + 64;
          v123 = *(__int64 **)(v5 + 72);
          if ( v101 == (__int64 *)(v5 + 64) || v101 == v123 || *v123 != v122 )
          {
            _list_add_valid_or_report(v101, v123, v122);
          }
          else
          {
            *(_QWORD *)(v5 + 72) = v101;
            *v101 = v122;
            v101[1] = (__int64)v123;
            *v123 = (__int64)v101;
          }
          raw_spin_unlock(v5 + 320);
LABEL_236:
          v124 = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(v124 + 70) & 0x20) != 0 || (v125 = a3, (*(_QWORD *)v124 & 0x4000000) != 0) )
            v125 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( v125 > 0x7FFFFFFFE0LL )
            goto LABEL_92;
          v126 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v128 = *(_QWORD *)(v124 + 8);
          _WriteStatusReg(TTBR1_EL1, v128 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v128);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v126);
          v129 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v332, 32);
          v130 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v132 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v132 - 4096);
          _WriteStatusReg(TTBR1_EL1, v132);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v130);
LABEL_546:
          if ( v129 )
            goto LABEL_92;
          goto LABEL_573;
        }
        dev_err(v31, "Failed to assign memory phys 0x%llx size 0x%llx err %d", v101[8], v101[9], v111);
        LODWORD(v19) = fastrpc_req_munmap_dsp(v5, v101[18], v101[9]);
        if ( (_DWORD)v19 )
        {
          if ( HIDWORD(v332) == 8 )
          {
            v198 = raw_spin_lock_irqsave(*(_QWORD *)(v5 + 128) + 51600LL);
            _list_add(v101, *(_QWORD **)(*(_QWORD *)(v5 + 128) + 52752LL), *(_QWORD *)(v5 + 128) + 52744LL);
            raw_spin_unlock_irqrestore(*(_QWORD *)(v5 + 128) + 51600LL, v198);
          }
          else
          {
            raw_spin_lock(v5 + 320);
            _list_add(v101, *(_QWORD **)(v5 + 72), v5 + 64);
            raw_spin_unlock(v5 + 320);
          }
          v316 = 0;
        }
      }
    }
    else
    {
LABEL_73:
      mutex_lock(v5 + 328);
      LODWORD(v19) = fastrpc_map_create(v5, (unsigned int)v332, *(__int64 *)v333, 0, v334, 0, 0, v315, 1u);
      mutex_unlock(v5 + 328);
      if ( (_DWORD)v19 )
      {
        dev_err(v31, "failed to map buffer, fd = %d\n", v332);
        goto LABEL_575;
      }
      v32 = v315[0];
      _X10 = (unsigned int *)(v315[0] + 120);
      __asm { PRFM            #0x11, [X10] }
      do
      {
        v286 = __ldxr(_X10);
        if ( v286 )
          goto LABEL_539;
      }
      while ( __stlxr(1u, _X10) );
      __dmb(0xBu);
LABEL_539:
      if ( v286 )
      {
        LODWORD(v19) = -114;
      }
      else
      {
        LODWORD(v327) = *(_DWORD *)(v5 + 244);
        HIDWORD(v327) = HIDWORD(v332);
        v328 = *(_QWORD *)v333;
        v342 = &v327;
        v343 = (_QWORD *)&_ksymtab_fastrpc_driver_unregister;
        v288 = *(_QWORD *)(v32 + 64);
        v287 = *(_QWORD *)(v32 + 72);
        LODWORD(v329) = 16;
        v324 = v288;
        v325 = v287;
        v345 = &v324;
        v346 = 16;
        v348 = v323;
        v349 = 8;
        v357 = 0x402010000000001LL;
        v358 = (__int64 *)&v342;
        v289 = fastrpc_internal_invoke(v5, 1u, (int *)&v357);
        if ( !v289 )
        {
          v290 = v323[0];
          *(_QWORD *)(v32 + 96) = v323[0];
          v335 = v290;
          v291 = _ReadStatusReg(SP_EL0);
          *(_DWORD *)(v32 + 120) = 2;
          if ( (*(_BYTE *)(v291 + 70) & 0x20) != 0 || (v292 = a3, (*(_QWORD *)v291 & 0x4000000) != 0) )
            v292 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( v292 > 0x7FFFFFFFE0LL )
            goto LABEL_92;
          v293 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v295 = *(_QWORD *)(v291 + 8);
          _WriteStatusReg(TTBR1_EL1, v295 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v295);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v293);
          v129 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v332, 32);
          v296 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v298 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v298 - 4096);
          _WriteStatusReg(TTBR1_EL1, v298);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v296);
          goto LABEL_546;
        }
        LODWORD(v19) = v289;
        dev_err(v31, "mmap error (len 0x%08llx)\n", *(_QWORD *)(v32 + 72));
        *(_DWORD *)(v32 + 120) = 0;
      }
    }
    v33 = v315[0];
    if ( v315[0] )
    {
      mutex_lock(v5 + 328);
      _X0 = (unsigned int *)(v33 + 112);
      __asm { PRFM            #0x11, [X0] }
      do
        v302 = __ldxr(_X0);
      while ( __stlxr(v302 - 1, _X0) );
      if ( v302 == 1 )
      {
        __dmb(9u);
        _fastrpc_free_map(v33);
      }
      else if ( v302 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      mutex_unlock(v5 + 328);
    }
    v160 = v316;
    if ( !v316 )
      goto LABEL_575;
LABEL_564:
    fastrpc_buf_free(v160, 0);
    goto LABEL_575;
  }
  if ( (_DWORD)v4 != -1069526518 )
  {
    if ( (_DWORD)v4 == 20996 )
    {
      LODWORD(v19) = fastrpc_init_attach(v5, 1);
      if ( v5 )
      {
        v38 = *(_QWORD *)(v5 + 128);
        v332 = *(_QWORD *)(v38 + 64120);
        if ( (*(_BYTE *)(v38 + 51669) & 1) == 0 )
        {
          v344 = 0xFFFFFFFFLL;
          v359 = nullptr;
          v360 = 0;
          v361 = 0;
          v362 = 0;
          v363 = 0;
          v364 = 0;
          v365 = 0;
          v366 = nullptr;
          v367 = 0;
          v368 = 0;
          v369 = nullptr;
          v370 = 0;
          v371 = 0;
          v342 = &v332;
          v343 = (_QWORD *)&unk_8;
          v357 = 0x101000000000002LL;
          v358 = (__int64 *)&v342;
          if ( !(unsigned int)fastrpc_internal_invoke(v5, 1u, (int *)&v357) )
            *(_BYTE *)(*(_QWORD *)(v5 + 128) + 51669LL) = 1;
        }
      }
    }
    else
    {
      if ( (_DWORD)v4 != 21000 )
        goto LABEL_575;
      LODWORD(v19) = fastrpc_init_attach(v5, 3);
    }
    goto LABEL_568;
  }
  v338 = 0;
  v339 = 0;
  v336 = 0;
  v337 = 0;
  v334 = 0;
  v335 = 0;
  v332 = 0;
  *(_QWORD *)v333 = 0;
  v323[0] = 0;
  if ( *(_DWORD *)(v5 + 628) != 2 )
  {
    dev_err(
      *(_QWORD *)(*(_QWORD *)(v5 + 128) + 168LL),
      "%s: %s: trying to map buf before creating remote session\n",
      "fastrpc_req_mem_map",
      _ReadStatusReg(SP_EL0) + 2320);
    goto LABEL_204;
  }
  if ( inline_copy_from_user((__int64)&v332, a3, 0x40u) )
    goto LABEL_92;
  if ( v333[1] == 0x20000 )
    goto LABEL_87;
  v73 = **(_QWORD **)(v5 + 136);
  mutex_lock(v5 + 328);
  LODWORD(v19) = fastrpc_map_create(v5, HIDWORD(v332), v334, 0, v335, v337, v333[1], v323, 1u);
  mutex_unlock(v5 + 328);
  if ( (_DWORD)v19 )
  {
    dev_err(v73, "failed to map buffer, fd = %d\n", HIDWORD(v332));
    goto LABEL_575;
  }
  v74 = v323[0];
  _X10 = (unsigned int *)(v323[0] + 120);
  __asm { PRFM            #0x11, [X10] }
  while ( 1 )
  {
    v267 = __ldxr(_X10);
    if ( v267 )
      break;
    if ( !__stlxr(1u, _X10) )
    {
      __dmb(0xBu);
      break;
    }
  }
  if ( v267 )
  {
    LODWORD(v19) = -114;
  }
  else
  {
    v313 = v73;
    v268 = *(_QWORD *)(v74 + 64);
    v269 = *(_QWORD *)(v74 + 72);
    v271 = v333[0];
    v270 = v333[1];
    v272 = v334;
    v273 = *(_DWORD *)(v74 + 24);
    v350 = 0;
    v351 = nullptr;
    v348 = nullptr;
    v349 = 0;
    *(_QWORD *)(v74 + 80) = v334;
    v352 = 0;
    v353 = 0;
    v346 = 0;
    v347 = 0;
    v344 = 0;
    v345 = nullptr;
    v316 = 0;
    if ( v5 )
    {
      v274 = **(_QWORD **)(v5 + 136);
      v328 = __PAIR64__(v270, v271);
      v324 = v268;
      v325 = v269;
      v329 = v272;
      v330 = 16;
      v345 = &v324;
      v346 = 16;
      v348 = (__int64 *)&v324;
      v349 = 0;
      v309 = v274;
      LODWORD(v274) = *(_DWORD *)(v5 + 244);
      v351 = &v316;
      v352 = 8;
      v327 = __PAIR64__(v273, v274);
      v370 = 0;
      v371 = 0;
      v368 = 0;
      v369 = nullptr;
      v366 = nullptr;
      v367 = 0;
      v364 = 0;
      v365 = 0;
      v362 = 0;
      v363 = 0;
      v360 = 0;
      v361 = 0;
      v359 = nullptr;
      v342 = &v327;
      v343 = (_QWORD *)&unk_20;
      v357 = 0xA03010000000001LL;
      v358 = (__int64 *)&v342;
      v275 = fastrpc_internal_invoke(v5, 1u, (int *)&v357);
      if ( !v275 )
      {
        v336 = v316;
        *(_QWORD *)(v74 + 96) = v316;
        v276 = _ReadStatusReg(SP_EL0);
        *(_DWORD *)(v74 + 120) = 2;
        if ( (*(_BYTE *)(v276 + 70) & 0x20) != 0 || (v277 = a3, (*(_QWORD *)v276 & 0x4000000) != 0) )
          v277 = a3 & ((__int64)(a3 << 8) >> 8);
        if ( v277 <= 0x7FFFFFFFC0LL )
        {
          v278 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v280 = *(_QWORD *)(v276 + 8);
          _WriteStatusReg(TTBR1_EL1, v280 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v280);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v278);
          v97 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v332, 64);
          v281 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v283 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v283 - 4096);
          _WriteStatusReg(TTBR1_EL1, v283);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v281);
          goto LABEL_211;
        }
        goto LABEL_92;
      }
      LODWORD(v19) = v275;
      dev_err(v309, "mem mmap error, fd %d, vaddr %llx, size %zx, err 0x%x\n", v273, v272, v269, v275);
      v273 = *(_DWORD *)(v74 + 24);
    }
    else
    {
      LODWORD(v19) = -9;
    }
    dev_err(v313, "failed to map buffer on dsp, fd = %d\n", v273);
    *(_DWORD *)(v74 + 120) = 0;
  }
  mutex_lock(v5 + 328);
  if ( v74 )
  {
    _X0 = (unsigned int *)(v74 + 112);
    __asm { PRFM            #0x11, [X0] }
    do
      v300 = __ldxr(_X0);
    while ( __stlxr(v300 - 1, _X0) );
    if ( v300 == 1 )
    {
      __dmb(9u);
      _fastrpc_free_map(v74);
    }
    else if ( v300 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  mutex_unlock(v5 + 328);
LABEL_575:
  v305 = raw_spin_lock_irqsave(v15 + 51600);
  v306 = *(_DWORD *)(v15 + 64180) - 1;
  *(_DWORD *)(v15 + 64180) = v306;
  if ( !v306 )
    _wake_up(v15 + 64216, 1, 1, 0);
  raw_spin_unlock_irqrestore(v15 + 51600, v305);
  fastrpc_channel_ctx_put(*(_QWORD *)(v5 + 128));
  fastrpc_file_put((__int64 *)v5, 0);
  result = (int)v19;
LABEL_578:
  _ReadStatusReg(SP_EL0);
  return result;
}
