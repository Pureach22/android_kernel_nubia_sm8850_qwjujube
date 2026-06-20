_DWORD *__fastcall sde_crtc_blend_setup(
        char *a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  char *v9; // x27
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x9
  void *v13; // x0
  const char *v14; // x1
  __int64 v15; // x9
  unsigned int v16; // w19
  unsigned int v17; // w8
  __int64 *v18; // x8
  __int64 v19; // x0
  void (*v20)(void); // x8
  _WORD *v21; // x19
  __int64 v22; // x8
  __int64 *i; // x20
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x10
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v32; // x10
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x8
  _DWORD *result; // x0
  int v38; // w6
  int v39; // w20
  __int64 *v40; // x11
  __int64 v41; // x9
  __int64 v42; // x10
  __int64 v43; // x8
  __int64 v44; // x10
  __int64 v45; // x8
  __int64 v46; // x9
  __int64 v47; // x8
  __int64 v48; // x10
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x8
  __int64 v53; // x8
  __int64 v54; // x21
  __int64 v55; // x8
  __int64 v56; // x9
  __int64 v57; // x9
  void *v58; // x0
  const char *v59; // x1
  _DWORD *v60; // x22
  __int64 v61; // x8
  __int64 v62; // x28
  __int64 *v63; // x24
  char v64; // w23
  __int64 v65; // x25
  unsigned int v66; // w19
  int v67; // w27
  unsigned int v68; // w0
  unsigned int v69; // w0
  int v70; // w22
  int v71; // w26
  unsigned int v72; // w20
  int v73; // w0
  __int64 v74; // x8
  int v75; // w8
  __int64 v76; // x0
  int v77; // w0
  unsigned int v78; // w8
  int v79; // w5
  __int64 v80; // x26
  int v81; // w5
  __int64 v82; // x8
  int v83; // w6
  __int64 v84; // x19
  unsigned __int64 v85; // x8
  int v86; // w8
  unsigned int v87; // w19
  __int64 v88; // x8
  char *v89; // x9
  __int64 v90; // x22
  int v91; // w0
  __int64 v92; // x8
  char *v93; // x9
  __int64 v94; // x8
  int v95; // w20
  __int64 v96; // x21
  int v97; // w27
  int v98; // w28
  int v99; // w0
  _DWORD *v100; // x9
  unsigned __int64 v101; // x8
  unsigned __int64 v102; // x8
  int v103; // w0
  unsigned __int64 v106; // x10
  unsigned __int64 v109; // x10
  __int64 v110; // x8
  __int64 v111; // x10
  __int64 v112; // x19
  _DWORD *v113; // x9
  int v114; // w8
  int v115; // w8
  __int64 v116; // x9
  __int64 *v117; // x21
  __int64 v118; // x25
  __int64 v119; // x0
  __int64 v120; // x28
  __int64 v121; // x27
  __int64 v122; // x22
  __int64 *v123; // x8
  __int64 v124; // x8
  __int64 v125; // x8
  __int64 v126; // x9
  __int64 v127; // x9
  unsigned __int64 v128; // x19
  unsigned int v129; // w8
  int v130; // w26
  unsigned int v131; // w23
  unsigned int v132; // w8
  unsigned int v133; // w24
  int v134; // w20
  int v136; // w8
  int v137; // w9
  unsigned int v138; // w20
  _DWORD *v139; // x8
  __int64 v140; // x1
  __int64 v141; // x8
  void *v142; // x0
  const char *v143; // x1
  __int64 v144; // x19
  void (__fastcall *v145)(__int64, __int64 *); // x8
  void (__fastcall *v146)(__int64, __int64 *); // x8
  __int64 v147; // x8
  __int64 v148; // x8
  __int64 v149; // x8
  __int64 v150; // x9
  unsigned __int64 v151; // x21
  __int64 v152; // x28
  __int64 v153; // x23
  int v154; // w20
  int v155; // w27
  int v156; // w0
  _DWORD *v157; // x20
  _QWORD *v158; // x8
  __int64 v159; // x24
  int v160; // w23
  _DWORD *v161; // x19
  _BYTE *v162; // x22
  unsigned int v163; // w25
  int v164; // w8
  __int64 v165; // x26
  char *v166; // x22
  int v167; // w27
  char *v168; // x20
  char *v169; // x22
  int v170; // w23
  unsigned __int64 v171; // x9
  unsigned __int64 v172; // x10
  char *v173; // x13
  __int64 v174; // x16
  unsigned __int64 v175; // x15
  __int64 v176; // x17
  __int64 v177; // x1
  char *v178; // x13
  unsigned __int64 v179; // x0
  unsigned __int64 v180; // x14
  int v181; // w2
  unsigned int v182; // w13
  unsigned int v183; // w14
  unsigned __int64 v184; // x15
  unsigned __int64 v185; // x2
  void *v186; // x0
  __int64 v187; // x9
  unsigned __int64 v188; // x24
  __int64 v189; // x27
  __int64 v190; // x25
  __int64 v191; // x8
  __int64 v192; // x9
  __int64 v193; // x9
  unsigned __int64 v194; // x21
  void *v195; // x0
  const char *v196; // x1
  unsigned int v197; // w9
  _DWORD *v198; // x20
  __int64 v199; // x28
  unsigned __int64 v200; // x23
  __int64 v201; // x8
  __int64 v202; // x19
  __int64 v203; // x8
  __int64 v204; // x0
  __int64 v205; // x0
  void (*v206)(void); // x8
  unsigned __int64 v207; // x21
  __int64 v208; // x26
  __int64 *v209; // x9
  __int64 v210; // x0
  char *v211; // x2
  __int64 v212; // x3
  __int64 v213; // x1
  __int64 v214; // x23
  unsigned int v215; // w19
  __int64 v216; // x24
  __int64 v217; // x27
  __int64 (__fastcall *v218)(__int64, __int64); // x8
  __int64 v219; // x1
  _QWORD *v220; // x20
  __int64 (__fastcall *v221)(__int64, __int64, __int64); // x8
  __int64 v222; // x1
  _DWORD *v223; // x8
  unsigned __int64 v224; // x8
  unsigned __int64 v225; // x9
  __int64 v226; // x8
  _DWORD *v227; // x8
  __int64 v228; // x1
  __int64 (__fastcall *v229)(__int64, __int64, char *, __int64); // x8
  _DWORD *v230; // x8
  __int64 v231; // x1
  unsigned __int64 v234; // x10
  __int64 (__fastcall *v235)(__int64, __int64 *); // x8
  __int64 v236; // x8
  __int64 v237; // x9
  __int64 v238; // x9
  unsigned int v239; // w22
  void *v240; // x0
  const char *v241; // x1
  unsigned __int64 v242; // x20
  char v243; // w24
  char v244; // w23
  __int64 v245; // x27
  unsigned __int16 *v246; // x26
  __int64 v247; // x0
  int v248; // w8
  int v249; // w9
  void (*v250)(void); // x10
  unsigned __int64 v256; // x9
  unsigned __int64 v259; // x10
  unsigned __int64 v262; // x10
  char v263; // [xsp+0h] [xbp-250h]
  __int64 v264; // [xsp+58h] [xbp-1F8h]
  unsigned int v265; // [xsp+64h] [xbp-1ECh]
  __int64 v266; // [xsp+68h] [xbp-1E8h]
  _DWORD *v267; // [xsp+70h] [xbp-1E0h]
  int v268; // [xsp+70h] [xbp-1E0h]
  __int64 v269; // [xsp+78h] [xbp-1D8h]
  __int64 v270; // [xsp+80h] [xbp-1D0h]
  __int64 v271; // [xsp+80h] [xbp-1D0h]
  char *v272; // [xsp+88h] [xbp-1C8h]
  int v273; // [xsp+90h] [xbp-1C0h]
  _DWORD *v274; // [xsp+90h] [xbp-1C0h]
  int v275; // [xsp+98h] [xbp-1B8h]
  __int64 v276; // [xsp+98h] [xbp-1B8h]
  __int64 v277; // [xsp+98h] [xbp-1B8h]
  __int64 *v278; // [xsp+A0h] [xbp-1B0h]
  int v279; // [xsp+A0h] [xbp-1B0h]
  __int64 v280; // [xsp+A0h] [xbp-1B0h]
  char *v281; // [xsp+A8h] [xbp-1A8h]
  unsigned int v282; // [xsp+B4h] [xbp-19Ch]
  __int64 v283; // [xsp+B8h] [xbp-198h]
  char *v284; // [xsp+C0h] [xbp-190h]
  __int64 *v285; // [xsp+C8h] [xbp-188h]
  __int64 v286; // [xsp+C8h] [xbp-188h]
  __int64 v287; // [xsp+D0h] [xbp-180h] BYREF
  unsigned __int64 v288; // [xsp+D8h] [xbp-178h]
  __int64 v289; // [xsp+E0h] [xbp-170h]
  int v290; // [xsp+ECh] [xbp-164h]
  __int64 v291; // [xsp+F0h] [xbp-160h]
  __int64 v292; // [xsp+F8h] [xbp-158h] BYREF
  _QWORD v293[8]; // [xsp+100h] [xbp-150h] BYREF
  __int64 v294; // [xsp+140h] [xbp-110h] BYREF
  __int64 v295; // [xsp+148h] [xbp-108h] BYREF
  __int64 v296; // [xsp+150h] [xbp-100h] BYREF
  __int64 v297; // [xsp+158h] [xbp-F8h]
  __int64 v298; // [xsp+160h] [xbp-F0h]
  __int64 v299; // [xsp+168h] [xbp-E8h]
  __int64 v300; // [xsp+170h] [xbp-E0h]
  __int64 v301; // [xsp+178h] [xbp-D8h]
  __int64 v302; // [xsp+180h] [xbp-D0h]
  __int64 v303; // [xsp+188h] [xbp-C8h]
  __int64 v304; // [xsp+190h] [xbp-C0h]
  __int64 v305; // [xsp+198h] [xbp-B8h]
  __int64 v306; // [xsp+1A0h] [xbp-B0h]
  __int64 v307; // [xsp+1A8h] [xbp-A8h]
  __int64 v308; // [xsp+1B0h] [xbp-A0h]
  __int64 v309; // [xsp+1B8h] [xbp-98h]
  __int64 v310; // [xsp+1C0h] [xbp-90h]
  __int64 v311; // [xsp+1C8h] [xbp-88h]
  __int64 v312; // [xsp+1D0h] [xbp-80h]
  __int64 v313; // [xsp+1D8h] [xbp-78h]
  __int64 v314; // [xsp+1E0h] [xbp-70h]
  __int64 v315; // [xsp+1E8h] [xbp-68h]
  __int64 v316; // [xsp+1F0h] [xbp-60h]
  __int64 v317; // [xsp+1F8h] [xbp-58h]
  __int64 v318; // [xsp+200h] [xbp-50h]
  __int64 v319; // [xsp+208h] [xbp-48h]
  __int64 v320; // [xsp+210h] [xbp-40h]
  __int64 v321; // [xsp+218h] [xbp-38h]
  __int64 v322; // [xsp+220h] [xbp-30h]
  __int64 v323; // [xsp+228h] [xbp-28h]
  __int64 v324; // [xsp+230h] [xbp-20h]
  _QWORD v325[3]; // [xsp+238h] [xbp-18h] BYREF
  __int64 vars0; // [xsp+250h] [xbp+0h] BYREF

  v9 = a1;
  v325[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v293, 0, sizeof(v293));
  if ( !a1 || !*(_QWORD *)a1 || (v10 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) == 0 )
  {
    v13 = &unk_25E167;
    v14 = "sde_crtc_get_disp_op";
LABEL_10:
    printk(v13, v14);
    goto LABEL_11;
  }
  v11 = *(_QWORD *)(v10 + 8);
  if ( !v11 )
  {
    v13 = &unk_234896;
    v14 = "_sde_crtc_get_kms";
    goto LABEL_10;
  }
  v12 = *(_QWORD *)(v11 + 152);
  if ( v12 && (*(_QWORD *)(v12 + 22008) & 0x8000000000000LL) != 0 )
  {
    v282 = *(_DWORD *)(v10 + 5912);
    goto LABEL_12;
  }
LABEL_11:
  v282 = 0;
LABEL_12:
  v15 = *((_QWORD *)v9 + 251);
  v292 = 0;
  v283 = v15;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "%s\n", v9 + 2176);
  if ( *((_DWORD *)v9 + 548) >= 9u )
  {
    result = (_DWORD *)printk(&unk_248E65, "_sde_crtc_blend_setup");
    goto LABEL_433;
  }
  v285 = (__int64 *)(v9 + 2200);
  if ( (*((_QWORD *)v9 + 756) & 2) != 0 )
  {
    _X8 = (unsigned __int64 *)(v283 + 1792);
    __asm { PRFM            #0x11, [X8] }
    do
      v256 = __ldxr(_X8);
    while ( __stxr(v256 | 2, _X8) );
    _X8 = (unsigned __int64 *)(v9 + 6048);
    __asm { PRFM            #0x11, [X8] }
    do
      v259 = __ldxr(_X8);
    while ( __stxr(v259 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  }
  v284 = v9;
  if ( !*((_DWORD *)v9 + 548) )
    goto LABEL_55;
  v16 = 0;
  do
  {
    v18 = &v285[6 * (int)v16];
    v19 = *v18;
    if ( !*v18 )
    {
      result = (_DWORD *)printk(&unk_261EFE, "_sde_crtc_blend_setup");
      goto LABEL_433;
    }
    *((_DWORD *)v18 + 10) = 0;
    if ( (*(_QWORD *)(v283 + 1792) & 2) != 0 )
    {
      if ( v282 >= 3 )
        goto LABEL_435;
      v9 = v284;
      v20 = *(void (**)(void))(v19 + 8LL * v282 + 208);
      if ( v20 )
      {
        if ( *((_DWORD *)v20 - 1) != -1701872535 )
          __break(0x8228u);
        v20();
      }
    }
    v17 = *((_DWORD *)v9 + 548);
    ++v16;
  }
  while ( v16 < v17 );
  if ( v17 == 2 )
  {
    v21 = *((_WORD **)v9 + 251);
    if ( v21 )
    {
      v22 = *(_QWORD *)v9;
      for ( i = *(__int64 **)(*(_QWORD *)v9 + 816LL); i != (__int64 *)(v22 + 816); i = (__int64 *)*i )
      {
        if ( ((*(_DWORD *)(*((_QWORD *)v9 + 251) + 20LL) >> *((_DWORD *)i + 15)) & 1) != 0 )
        {
          if ( (sde_encoder_is_dsc_merge(i - 1) & 1) != 0 )
          {
            if ( v21[280] )
            {
              if ( v21 == (_WORD *)-564LL || v21[281] )
              {
LABEL_48:
                v38 = (unsigned __int8)v9[2196];
                if ( v38 == 1 )
                {
                  v40 = v285;
                  v38 = 0;
                  v39 = 0;
                  v9[2196] = 0;
LABEL_50:
                  v41 = v40[3];
                  v298 = v40[2];
                  v299 = v41;
                  v42 = v40[5];
                  v300 = v40[4];
                  v301 = v42;
                  v43 = v40[1];
                  v44 = *((_QWORD *)v9 + 283);
                  v296 = *v40;
                  v297 = v43;
                  v45 = *((_QWORD *)v9 + 284);
                  v46 = *((_QWORD *)v9 + 285);
                  v40[2] = v44;
                  v40[3] = v45;
                  v47 = *((_QWORD *)v9 + 286);
                  v48 = *((_QWORD *)v9 + 281);
                  v40[4] = v46;
                  v40[5] = v47;
                  v49 = *((_QWORD *)v9 + 282);
                  *v40 = v48;
                  v40[1] = v49;
                  v50 = v299;
                  *((_QWORD *)v9 + 283) = v298;
                  *((_QWORD *)v9 + 284) = v50;
                  v51 = v301;
                  *((_QWORD *)v9 + 285) = v300;
                  *((_QWORD *)v9 + 286) = v51;
                  v52 = v297;
                  *((_QWORD *)v9 + 281) = v296;
                  *((_QWORD *)v9 + 282) = v52;
                }
                else
                {
                  v39 = 0;
                }
                goto LABEL_52;
              }
            }
            else if ( v21 == (_WORD *)-564LL )
            {
              goto LABEL_48;
            }
            if ( !v21[284] || !v21[285] )
              goto LABEL_48;
            v38 = (unsigned __int8)v9[2196];
            v39 = 1;
            if ( (v38 & 1) == 0 )
            {
              v40 = v285;
              v38 = 1;
              v9[2196] = 1;
              goto LABEL_50;
            }
LABEL_52:
            if ( (_drm_debug & 4) != 0 )
            {
              _drm_dev_dbg(
                0,
                0,
                0,
                "%s: right_only %d swapped %d, mix0->lm%d, mix1->lm%d\n",
                v9 + 2176,
                v39,
                v38,
                *(_DWORD *)(*((_QWORD *)v9 + 275) + 32LL) - 1,
                *(_DWORD *)(*((_QWORD *)v9 + 281) + 32LL) - 1);
              v38 = (unsigned __int8)v9[2196];
            }
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_crtc_swap_mixers_for_right_partial_update",
              2550,
              -1,
              *((_DWORD *)v9 + 28),
              v39,
              v38,
              *(_DWORD *)(*((_QWORD *)v9 + 275) + 32LL) - 1,
              *(_BYTE *)(*((_QWORD *)v9 + 281) + 32LL) - 1);
            goto LABEL_55;
          }
          v22 = *(_QWORD *)v9;
        }
      }
      if ( v9[2196] == 1 )
      {
        v24 = v285[2];
        v25 = v285[3];
        v9[2196] = 0;
        v298 = v24;
        v299 = v25;
        v26 = v285[5];
        v300 = v285[4];
        v301 = v26;
        v27 = v285[1];
        v28 = *((_QWORD *)v9 + 283);
        v296 = *v285;
        v297 = v27;
        v29 = *((_QWORD *)v9 + 284);
        v30 = *((_QWORD *)v9 + 285);
        v285[2] = v28;
        v285[3] = v29;
        v31 = *((_QWORD *)v9 + 286);
        v32 = *((_QWORD *)v9 + 281);
        v285[4] = v30;
        v285[5] = v31;
        v33 = *((_QWORD *)v9 + 282);
        *v285 = v32;
        v285[1] = v33;
        v34 = v300;
        *((_QWORD *)v9 + 286) = v301;
        *((_QWORD *)v9 + 285) = v34;
        v35 = v298;
        *((_QWORD *)v9 + 284) = v299;
        *((_QWORD *)v9 + 283) = v35;
        v36 = v297;
        *((_QWORD *)v9 + 281) = v296;
        *((_QWORD *)v9 + 282) = v36;
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_crtc_swap_mixers_for_right_partial_update",
          2526,
          -1,
          13107,
          -1059143953,
          a7,
          a8,
          v263);
      }
    }
  }
LABEL_55:
  v272 = v9 + 3240;
  result = memset(v9 + 3240, 0, 0x480u);
  if ( (a2 & 1) == 0 )
    goto LABEL_347;
  v53 = *((_QWORD *)v9 + 251);
  v288 = 0;
  v289 = 0;
  v287 = 0;
  v294 = 0;
  v295 = 0;
  v270 = v53;
  if ( !v53 )
  {
    result = (_DWORD *)printk(&unk_234B5E, "_sde_crtc_blend_setup_mixer");
    goto LABEL_347;
  }
  v54 = *((_QWORD *)v9 + 276);
  v264 = *((_QWORD *)v9 + 275);
  if ( !v9 || !*(_QWORD *)v9 || (v55 = *(_QWORD *)(*(_QWORD *)v9 + 56LL)) == 0 )
  {
    v58 = &unk_25E167;
    v59 = "sde_crtc_get_disp_op";
LABEL_67:
    printk(v58, v59);
    goto LABEL_68;
  }
  v56 = *(_QWORD *)(v55 + 8);
  if ( !v56 )
  {
    v58 = &unk_234896;
    v59 = "_sde_crtc_get_kms";
    goto LABEL_67;
  }
  v57 = *(_QWORD *)(v56 + 152);
  if ( v57 && (*(_QWORD *)(v57 + 22008) & 0x8000000000000LL) != 0 )
  {
    v265 = *(_DWORD *)(v55 + 5912);
    goto LABEL_69;
  }
LABEL_68:
  v265 = 0;
LABEL_69:
  result = (_DWORD *)_kmalloc_cache_noprof(kthread_should_park, 3520, 1152);
  v60 = result;
  if ( !result )
    goto LABEL_347;
  v61 = *(_QWORD *)v9;
  v62 = 0;
  v269 = v54;
  v294 = 0;
  v295 = 0;
  v63 = *(__int64 **)(v61 + 840);
  v296 = 0;
  v297 = 0;
  v298 = 0;
  v299 = 0;
  v300 = 0;
  v301 = 0;
  v302 = 0;
  v303 = 0;
  v304 = 0;
  v305 = 0;
  v306 = 0;
  v307 = 0;
  v308 = 0;
  v309 = 0;
  v310 = 0;
  v311 = 0;
  v312 = 0;
  v313 = 0;
  v314 = 0;
  v315 = 0;
  v316 = 0;
  v317 = 0;
  v318 = 0;
  v319 = 0;
  v320 = 0;
  v321 = 0;
  v281 = (char *)result;
  if ( v63 == (__int64 *)(v61 + 840) )
    goto LABEL_208;
  v64 = 0;
  v267 = v9 + 2240;
  while ( 2 )
  {
    if ( ((*(_DWORD *)(*((_QWORD *)v9 + 251) + 12LL) >> *((_DWORD *)v63 + 437)) & 1) == 0 )
      goto LABEL_72;
    v65 = v63[220];
    if ( !v65 )
      goto LABEL_72;
    v66 = *(unsigned __int16 *)(v65 + 40);
    v67 = *(unsigned __int16 *)(v65 + 44);
    v278 = v63 - 1;
    v68 = sde_plane_pipe(v63 - 1);
    _X9 = (unsigned __int64 *)(&v295 + (v68 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v106 = __ldxr(_X9);
    while ( __stxr(v106 | (1LL << v68), _X9) );
    v275 = *(_DWORD *)(v65 + 1648);
    if ( v275 != 1 )
    {
      v69 = sde_plane_pipe(v278);
      _X9 = (unsigned __int64 *)(&v294 + (v69 >> 6));
      __asm { PRFM            #0x11, [X9] }
      do
        v109 = __ldxr(_X9);
      while ( __stxr(v109 | (1LL << v69), _X9) );
    }
    ((void (__fastcall *)(__int64 *, __int64, __int64))sde_plane_ctl_flush)(v278, v269, 1);
    if ( (_drm_debug & 4) != 0 )
    {
      v70 = *(_DWORD *)(v65 + 1760);
      v71 = *((_DWORD *)v63 + 24);
      v72 = *((_DWORD *)v284 + 28);
      v73 = sde_plane_pipe(v278);
      v74 = *(_QWORD *)(v65 + 16);
      if ( v74 )
        v75 = *(_DWORD *)(v74 + 24);
      else
        v75 = -1;
      _drm_dev_dbg(0, 0, 0, "crtc %d stage:%d - plane %d sspp %d fb %d\n", v72, v70, v71, v73 - 1, v75);
      v60 = v281;
    }
    v76 = msm_framebuffer_format(*(_QWORD *)(v65 + 16));
    if ( !v76 )
    {
      printk(&unk_265611, "_sde_crtc_blend_setup_mixer");
      v9 = v284;
      goto LABEL_346;
    }
    if ( *(_DWORD *)(v65 + 1456) == 5 )
    {
      LOBYTE(v287) = 1;
      v77 = sde_plane_pipe(v278);
      LODWORD(v289) = v67;
      v78 = *(unsigned __int16 *)(v270 + 486);
      HIDWORD(v287) = v77;
      v288 = __PAIR64__(v66, v78);
      v9 = v284;
      BYTE4(v289) = is_sde_plane_virtual(v278) & 1;
      sde_cp_set_skip_blend_plane_info(v284, &v287);
      if ( v63 == (__int64 *)&unk_8 )
        v79 = -1;
      else
        v79 = *((_DWORD *)v63 + 24);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_crtc_blend_setup_mixer",
        2384,
        -1,
        *((_DWORD *)v284 + 28),
        v79,
        *(unsigned __int16 *)(v65 + 50),
        *(unsigned __int16 *)(v65 + 54),
        *(_WORD *)(v65 + 62));
      if ( (int)v62 <= 47 && v275 != 1 )
      {
        v84 = (int)v62;
        if ( (unsigned __int64)(24LL * (int)v62) > 0x480 )
          goto LABEL_436;
        v85 = 6LL * (int)v62;
        *(_QWORD *)&v60[v85] = v65;
        if ( v85 > 286 )
          goto LABEL_436;
        *(_QWORD *)&v60[v85 + 2] = v65;
        if ( v85 > 284 )
          goto LABEL_436;
        v86 = 255;
        goto LABEL_127;
      }
      goto LABEL_72;
    }
    v80 = v76;
    if ( !*(_DWORD *)(v65 + 1760) )
      v64 |= *(_BYTE *)(v76 + 24) != 0;
    if ( v63 == (__int64 *)&unk_8 )
    {
      v81 = -1;
      v82 = *(_QWORD *)(v65 + 16);
      if ( !v82 )
        goto LABEL_100;
LABEL_91:
      v83 = *(_DWORD *)(v82 + 24);
    }
    else
    {
      v81 = *((_DWORD *)v63 + 24);
      v82 = *(_QWORD *)(v65 + 16);
      if ( v82 )
        goto LABEL_91;
LABEL_100:
      v83 = -1;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_crtc_blend_setup_mixer",
      2398,
      -1,
      *((_DWORD *)v284 + 28),
      v81,
      v83,
      *(unsigned __int16 *)(v65 + 50),
      *(_WORD *)(v65 + 54));
    v87 = *(_DWORD *)(v65 + 1796);
    if ( v275 == 4 || v275 == 8 )
    {
      if ( v87 > 3 )
        goto LABEL_435;
    }
    else
    {
      v87 = v87 > 1;
    }
    v88 = *(unsigned int *)(v65 + 1760);
    if ( (unsigned int)v88 > 0xD )
      goto LABEL_435;
    if ( 4 * v88 + 52 * (unsigned __int64)v87 > 0xCF )
      goto LABEL_436;
    v89 = (char *)&v296 + 52 * v87;
    v90 = *(unsigned int *)&v89[4 * v88];
    *(_DWORD *)&v89[4 * v88] = v90 + 1;
    v91 = sde_plane_pipe(v278);
    v92 = *(unsigned int *)(v65 + 1760);
    if ( (unsigned int)v92 > 0xB )
      goto LABEL_435;
    if ( (unsigned int)v90 > 1 )
      goto LABEL_435;
    v93 = &v272[288 * v87];
    *(_DWORD *)&v93[8 * v92 + 4 * v90] = v91;
    v94 = *(unsigned int *)(v65 + 1760);
    if ( (unsigned int)v94 > 0xB )
      goto LABEL_435;
    *(_DWORD *)&v93[8 * v94 + 96 + 4 * v90] = *(_DWORD *)(v65 + 1776);
    if ( v63 == (__int64 *)&unk_8 )
    {
      v96 = v62;
      v95 = -1;
    }
    else
    {
      v95 = *((_DWORD *)v63 + 24);
      v96 = v62;
    }
    v97 = *((_DWORD *)v284 + 28);
    v98 = sde_dbg_base_evtlog;
    v99 = sde_plane_pipe(v278);
    sde_evtlog_log(v98, "_sde_crtc_blend_setup_mixer", 2431, -1, v97, v95, v90, v99 - 1, *(_DWORD *)(v65 + 1760));
    v9 = v284;
    v60 = v281;
    v62 = v96;
    if ( *((_DWORD *)v284 + 548) )
    {
      v100 = v267;
      v101 = 0;
      do
      {
        if ( (v64 & 1) == 0 || *(_BYTE *)(v80 + 24) )
          *v100 |= 1 << *(_DWORD *)(v65 + 1760);
        else
          *v100 = 0;
        ++v101;
        v100 += 12;
      }
      while ( v101 < *((unsigned int *)v284 + 548) );
    }
    if ( (int)v96 <= 47 && v275 != 1 )
    {
      v84 = (int)v96;
      if ( (unsigned __int64)(24LL * (int)v96) > 0x480 )
        goto LABEL_436;
      v102 = 24LL * (int)v96;
      *(_QWORD *)&v281[v102] = v65;
      if ( v102 > 0x478 )
        goto LABEL_436;
      *(_QWORD *)&v281[v102 + 8] = v65;
      if ( v102 > 0x470 )
        goto LABEL_436;
      v86 = *(_DWORD *)(v65 + 752);
LABEL_127:
      v60[6 * v84 + 4] = v86;
      v103 = sde_plane_pipe(v278);
      if ( (unsigned __int64)(24 * v84 - 1133) < 0xFFFFFFFFFFFFFB7FLL )
        goto LABEL_436;
      v62 = (unsigned int)(v62 + 1);
      v60[6 * (int)v84 + 5] = v103;
    }
LABEL_72:
    v63 = (__int64 *)*v63;
    if ( v63 != (__int64 *)(*(_QWORD *)v9 + 840LL) )
      continue;
    break;
  }
  v110 = *((unsigned int *)v9 + 548);
  v111 = (unsigned int)(v62 - 1);
  LODWORD(v323) = 0;
  v322 = 0;
  v266 = v110;
  if ( (int)v62 - 1 < 0 )
    goto LABEL_208;
  v268 = v62;
  while ( 2 )
  {
    v112 = 24 * v111;
    if ( (unsigned __int64)(24 * v111) > 0x47F )
      goto LABEL_436;
    v113 = *(_DWORD **)&v60[6 * v111];
    v271 = v111;
    if ( v113 )
    {
      v114 = v113[364];
      v273 = v113[736];
      if ( v113[412] )
      {
        if ( v114 != 5 )
        {
          v115 = 1;
          goto LABEL_146;
        }
        goto LABEL_135;
      }
    }
    else
    {
      v114 = 0;
      v273 = 255;
    }
    v116 = (unsigned int)v113[440];
    if ( (unsigned int)v116 > 0xB )
      goto LABEL_435;
    if ( (*((_BYTE *)&v322 + v116) & 1) != 0 || v114 == 5 )
      goto LABEL_135;
    v115 = 0;
LABEL_146:
    if ( (int)v266 < 1 )
    {
LABEL_135:
      v9 = v284;
      LODWORD(v62) = v268;
      v111 = v271 - 1;
      if ( v271 <= 0 )
        goto LABEL_208;
      continue;
    }
    break;
  }
  v117 = v285;
  v118 = v266;
  v276 = 24 * v111;
  if ( v273 == 255 )
    v115 = 0;
  v279 = v115;
  while ( 2 )
  {
    v119 = msm_framebuffer_format(*(_QWORD *)(*(_QWORD *)((char *)v60 + v112) + 16LL));
    if ( v119 )
    {
      v120 = *v117;
      v121 = v119;
      if ( v279 && v273 != *(_DWORD *)(v120 + 32) - 1 )
        goto LABEL_150;
      v122 = *(_QWORD *)((char *)v60 + v112);
      v123 = *(__int64 **)(v122 + 8);
      if ( v123 && (v124 = *v123) != 0 && (v125 = *(_QWORD *)(v124 + 56)) != 0 )
      {
        v126 = *(_QWORD *)(v125 + 8);
        if ( v126 )
        {
          v127 = *(_QWORD *)(v126 + 152);
          if ( !v127 || (*(_QWORD *)(v127 + 22008) & 0x8000000000000LL) == 0 )
          {
            v128 = 0;
            if ( v122 )
              goto LABEL_161;
LABEL_163:
            v129 = 0;
LABEL_164:
            if ( (*(_QWORD *)(*(_QWORD *)(v120 + 40) + 32LL) & 0x1000LL) != 0 )
              v130 = 1023;
            else
              v130 = 255;
            if ( (*(_QWORD *)(*(_QWORD *)(v120 + 40) + 32LL) & 0x1000LL) != 0 )
              v131 = v129 >> 6;
            else
              v131 = v129;
            if ( (sde_plane_property_is_dirty(v122, 37) & 1) != 0 )
            {
              if ( !v122 )
              {
                v132 = 0;
                goto LABEL_176;
              }
LABEL_175:
              v132 = *(_DWORD *)(v122 + 1392);
LABEL_176:
              if ( (*(_QWORD *)(*(_QWORD *)(v120 + 40) + 32LL) & 0x1000LL) != 0 )
                v133 = v132 >> 6;
              else
                v133 = v132;
              if ( v122 )
              {
LABEL_180:
                v134 = *(_DWORD *)(v122 + 1456);
                goto LABEL_182;
              }
            }
            else
            {
              v133 = v130 - v131;
              if ( v122 )
              {
                if ( *(_QWORD *)(v122 + 1648) )
                  goto LABEL_175;
                goto LABEL_180;
              }
            }
            v134 = 0;
LABEL_182:
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "blend_type:0x%x fg_alpha:0x%x bg_alpha:0x%x blend_op:0x%x max_alpha:0x%x\n",
                v134,
                v131,
                v133,
                256,
                v130);
            if ( v134 == 3 )
            {
              if ( *(_BYTE *)(v121 + 24) )
              {
                _ZF = v130 == v131;
                v136 = 6666;
                v137 = 1538;
                goto LABEL_190;
              }
            }
            else if ( v134 == 2 && *(_BYTE *)(v121 + 24) )
            {
              _ZF = v130 == v131;
              v136 = 6656;
              v137 = 1536;
LABEL_190:
              if ( _ZF )
              {
                v138 = v137;
              }
              else
              {
                v133 = v131;
                v138 = v136;
              }
LABEL_194:
              if ( v128 > 2 )
                goto LABEL_435;
              v139 = *(_DWORD **)(v120 + 8 * v128 + 88);
              if ( v139 )
              {
                v140 = *(unsigned int *)(v122 + 1760);
                if ( *(v139 - 1) != 1991044214 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD))v139)(v120, v140, v131, v133, v138);
              }
              v112 = v276;
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "format:%4.4s, alpha_enable:%u fg_alpha:0x%x bg_alpha:0x%x blend_op:0x%x\n",
                  (const char *)v121,
                  *(unsigned __int8 *)(v121 + 24),
                  v131,
                  v133,
                  v138);
              v60 = v281;
              v141 = *(unsigned int *)(*(_QWORD *)&v281[v276] + 1760LL);
              if ( (unsigned int)v141 > 0xB )
                goto LABEL_435;
              *((_BYTE *)&v322 + v141) = 1;
LABEL_150:
              --v118;
              v117 += 6;
              if ( !v118 )
                goto LABEL_135;
              continue;
            }
            v138 = 256;
            goto LABEL_194;
          }
          v128 = *(unsigned int *)(v125 + 5912);
          if ( !v122 )
            goto LABEL_163;
LABEL_161:
          v129 = *(_DWORD *)(v122 + 784);
          goto LABEL_164;
        }
        v142 = &unk_234896;
        v143 = "_sde_crtc_get_kms";
      }
      else
      {
        v142 = &unk_25E167;
        v143 = "sde_crtc_get_disp_op";
      }
      printk(v142, v143);
      v128 = 0;
      if ( !v122 )
        goto LABEL_163;
      goto LABEL_161;
    }
    break;
  }
  printk(&unk_265611, "_sde_crtc_setup_blend_cfg_by_stage");
  v9 = v284;
  LODWORD(v62) = v268;
LABEL_208:
  if ( v265 > 2 )
  {
LABEL_435:
    __break(0x5512u);
LABEL_436:
    __break(1u);
  }
  v60 = v281;
  v144 = v269 + 8LL * v265;
  v145 = *(void (__fastcall **)(__int64, __int64 *))(v144 + 1480);
  if ( v145 )
  {
    if ( *((_DWORD *)v145 - 1) != -60854866 )
      __break(0x8228u);
    v145(v269, &v295);
  }
  v146 = *(void (__fastcall **)(__int64, __int64 *))(v144 + 1528);
  if ( v146 )
  {
    if ( *((_DWORD *)v146 - 1) != -60854866 )
      __break(0x8228u);
    v146(v269, &v294);
  }
  sort(v281, (int)v62, 24, pstate_cmp, 0);
  if ( !v9 || !*(_QWORD *)v9 || (v147 = *(_QWORD *)(*(_QWORD *)v9 + 56LL)) == 0 )
  {
    v186 = &unk_25E167;
LABEL_296:
    printk(v186, "_sde_crtc_get_kms");
    goto LABEL_297;
  }
  v148 = *(_QWORD *)(v147 + 8);
  if ( !v148 )
  {
    v186 = &unk_234896;
    goto LABEL_296;
  }
  v149 = *(_QWORD *)(v148 + 152);
  if ( !v149 )
  {
LABEL_297:
    printk(&unk_27D28A, "_sde_crtc_set_src_split_order");
    goto LABEL_298;
  }
  if ( (int)v62 >= 1 && *(_DWORD *)(v149 + 21604) )
  {
    v150 = *(_QWORD *)v281;
    if ( v281 != (char *)-24LL && (_DWORD)v62 != 1 )
    {
      if ( *((_DWORD *)v281 + 10) != *((_DWORD *)v281 + 4)
        || *(_DWORD *)(*((_QWORD *)v281 + 3) + 1796LL) != *(_DWORD *)(v150 + 1796) )
      {
        *(_DWORD *)(v150 + 1788) = 0;
      }
LABEL_254:
      v171 = -1152;
      v172 = 1;
      while ( 2 )
      {
        ++v172;
        v175 = v171 + 1200;
        v176 = (__int64)&v281[v171 + 1176];
        v177 = (__int64)&v281[v171 + 1152];
        v178 = &v281[v171 + 1200];
        v179 = v171 + 1176;
        if ( v172 >= (unsigned int)v62 )
          v180 = 0;
        else
          v180 = 1152;
        if ( v172 >= (unsigned int)v62 )
        {
          v175 = 0;
          v178 = nullptr;
        }
        if ( &v281[v171] == (char *)-1152LL )
        {
          if ( v179 > 0x47F )
            goto LABEL_436;
          v174 = *(_QWORD *)v176;
          v181 = *(_DWORD *)(*(_QWORD *)v176 + 1796LL);
        }
        else
        {
          if ( v171 < 0xFFFFFFFFFFFFFB80LL || v179 >= 0x470 || v171 + 15 < 0xFFFFFFFFFFFFFB7FLL )
            goto LABEL_436;
          v174 = *(_QWORD *)v176;
          v181 = *(_DWORD *)(*(_QWORD *)v176 + 1796LL);
          if ( *(_DWORD *)&v281[v171 + 1168] == *(_DWORD *)&v281[v171 + 1192]
            && *(_DWORD *)(*(_QWORD *)v177 + 1796LL) == v181 )
          {
            if ( v171 + 7 < 0xFFFFFFFFFFFFFB7FLL )
              goto LABEL_436;
            v182 = *(unsigned __int16 *)(*(_QWORD *)&v281[v171 + 1160] + 32LL);
            v183 = *(unsigned __int16 *)(*(_QWORD *)&v281[v171 + 1184] + 32LL);
            v184 = v171 + 1152;
            if ( v183 >= v182 )
              v185 = v171 + 1152;
            else
              v185 = v171 + 1176;
            if ( v183 < v182 )
              v174 = *(_QWORD *)v177;
            *(_DWORD *)(v174 + 1788) = 64;
            if ( v185 > 0x47F )
              goto LABEL_436;
            if ( v183 < v182 )
              v184 = v171 + 1176;
            if ( v184 > 0x47F )
              goto LABEL_436;
            if ( v183 >= v182 )
              v173 = &v281[v171 + 1152];
            else
              v173 = &v281[v171 + 1176];
            v174 = *(_QWORD *)v173;
LABEL_259:
            *(_DWORD *)(v174 + 1788) = 0;
LABEL_260:
            v171 += 24LL;
            if ( (unsigned int)v62 == v172 )
              goto LABEL_230;
            continue;
          }
        }
        break;
      }
      if ( !v178 )
        goto LABEL_259;
      if ( v180 <= v175 + 16
        || v171 + 40 < 0xFFFFFFFFFFFFFB80LL
        || v180 <= v175 + 16
        || v171 + 40 < 0xFFFFFFFFFFFFFB80LL )
      {
        goto LABEL_436;
      }
      if ( *((_DWORD *)v178 + 4) != *(_DWORD *)&v281[v171 + 1192] )
        goto LABEL_259;
      if ( v180 <= v175 )
        goto LABEL_436;
      if ( *(_DWORD *)(*(_QWORD *)v178 + 1796LL) != v181 )
        goto LABEL_259;
      goto LABEL_260;
    }
    *(_DWORD *)(v150 + 1788) = 0;
    if ( (_DWORD)v62 != 1 )
      goto LABEL_254;
LABEL_230:
    v151 = 0;
    v152 = 24LL * (unsigned int)v62;
    while ( 2 )
    {
      if ( v151 == 1152 || v151 - 1144 < 0xFFFFFFFFFFFFFB80LL )
        goto LABEL_436;
      v157 = *(_DWORD **)&v60[v151 / 4];
      v158 = *(_QWORD **)&v60[v151 / 4 + 2];
      v159 = *v158;
      if ( v157 )
      {
        v160 = v157[412];
        v161 = v157 + 444;
        v162 = v157 + 447;
        ((void (__fastcall *)(__int64, _QWORD, bool))sde_plane_setup_src_split_order)(
          v159,
          (unsigned int)v157[444],
          v157[447] != 0);
        v163 = v157[449];
        if ( v160 == 8 || v160 == 4 )
        {
          if ( v163 >= 4 )
          {
            printk(&unk_23164C, "_sde_crtc_set_src_split_order");
            goto LABEL_234;
          }
          if ( (*v162 & 0x40) == 0 )
          {
LABEL_234:
            v151 += 24LL;
            v60 = v281;
            if ( v152 == v151 )
              goto LABEL_298;
            continue;
          }
        }
        else
        {
          v163 = v163 > 1;
          if ( (*v162 & 0x40) == 0 )
            goto LABEL_234;
        }
      }
      else
      {
        ((void (__fastcall *)(_QWORD, __int64, __int64))sde_plane_setup_src_split_order)(*v158, 2816568, 1);
        v161 = &dword_6F0;
        v163 = 1;
      }
      break;
    }
    v164 = v157[440];
    if ( v164 > 11 )
      goto LABEL_234;
    v165 = v164;
    if ( (unsigned int)v164 > 0xB )
      goto LABEL_435;
    v166 = &v272[288 * v163];
    v167 = *(_DWORD *)&v166[8 * v164];
    v168 = v166 + 96;
    v169 = &v166[8 * v164];
    if ( v167 == (unsigned int)sde_plane_pipe(v159) && *(_DWORD *)&v168[8 * v165] == *v161 )
    {
      v153 = 0;
      if ( !v159 )
        goto LABEL_252;
    }
    else
    {
      v170 = *((_DWORD *)v169 + 1);
      v9 = v284;
      if ( v170 != (unsigned int)sde_plane_pipe(v159) || *(_DWORD *)&v168[8 * v165 + 4] != *v161 )
        goto LABEL_234;
      v153 = 1;
      if ( !v159 )
      {
LABEL_252:
        v154 = -1;
        goto LABEL_233;
      }
    }
    v154 = *(_DWORD *)(v159 + 104);
LABEL_233:
    v155 = sde_dbg_base_evtlog;
    v156 = sde_plane_pipe(v159);
    sde_evtlog_log(v155, "_sde_crtc_set_src_split_order", 2238, -1, v154, v156, v163, v165, v153);
    v9 = v284;
    *(_DWORD *)&v169[4 * v153 + 192] = 1;
    goto LABEL_234;
  }
LABEL_298:
  if ( v264 )
  {
    if ( *(_QWORD *)(v264 + 8LL * v265 + 184) )
    {
      v187 = *((_QWORD *)v9 + 251);
      if ( (*(_QWORD *)(v187 + 1792) & 2) != 0 )
      {
        if ( *(_DWORD *)(v187 + 1808) )
        {
          v188 = 0;
          v277 = *((_QWORD *)v9 + 251);
          v280 = v187 + 1820;
          v274 = v9 + 2240;
          while ( 1 )
          {
            if ( v188 == 8 )
              goto LABEL_435;
            v324 = 0;
            v325[0] = 0;
            v322 = 0;
            v323 = 0;
            v189 = v280 + 32 * v188;
            if ( !*(_WORD *)(v189 + 28) || !*(_WORD *)(v189 + 30) )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "empty dim_layer\n");
              goto LABEL_303;
            }
            v190 = *((_QWORD *)v284 + 251);
            if ( !v284 )
              break;
            if ( !*(_QWORD *)v284 )
              break;
            v191 = *(_QWORD *)(*(_QWORD *)v284 + 56LL);
            if ( !v191 )
              break;
            v192 = *(_QWORD *)(v191 + 8);
            if ( !v192 )
            {
              v195 = &unk_234896;
              v196 = "_sde_crtc_get_kms";
              goto LABEL_318;
            }
            v193 = *(_QWORD *)(v192 + 152);
            if ( v193 && (*(_QWORD *)(v193 + 22008) & 0x8000000000000LL) != 0 )
            {
              v194 = *(unsigned int *)(v191 + 5912);
              goto LABEL_320;
            }
LABEL_319:
            v194 = 0;
LABEL_320:
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "dim_layer - flags:%d, stage:%d\n", *(_DWORD *)v189, *(_DWORD *)(v189 + 4));
            v197 = *((_DWORD *)v284 + 548);
            HIDWORD(v322) = *(_DWORD *)(v189 + 4);
            if ( v197 )
            {
              v198 = v274;
              v199 = 0;
              v200 = 0;
              while ( 1 )
              {
                LODWORD(v322) = *(_DWORD *)v189;
                v201 = *(_QWORD *)(v189 + 16);
                v323 = *(_QWORD *)(v189 + 8);
                v324 = v201;
                if ( v200 == 9 )
                  goto LABEL_435;
                v202 = v190 + v199;
                sde_kms_rect_intersect(v190 + v199 + 556, v189 + 24, v325);
                if ( &vars0 != (__int64 *)&_ksymtab___tracepoint_tracing_mark_write && WORD2(v325[0]) && HIWORD(v325[0]) )
                  break;
                if ( (v322 & 1) != 0 )
                  goto LABEL_324;
                LODWORD(v322) = v322 & 0xFFFFFFFC | 1;
                v203 = *(_QWORD *)(v190 + 8 * v200 + 492) >> 16;
                v325[0] = *(_QWORD *)(v190 + 8 * v200 + 492);
                if ( *(_DWORD *)(v190 + 6908) )
                  goto LABEL_331;
LABEL_332:
                if ( v200 == 8 )
                  goto LABEL_435;
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "_sde_crtc_setup_dim_layer_cfg",
                  1238,
                  -1,
                  *((_DWORD *)v284 + 28),
                  *(_DWORD *)(v189 + 4),
                  *(unsigned __int16 *)(v202 + 556),
                  *(unsigned __int16 *)(v190 + v199 + 558),
                  *(_WORD *)(v190 + v199 + 560));
                if ( (_drm_debug & 4) != 0 )
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "split_dim_layer - LM:%d, rect:{%d,%d,%d,%d}}\n",
                    v200,
                    LOWORD(v325[0]),
                    WORD1(v325[0]),
                    WORD2(v325[0]),
                    HIWORD(v325[0]));
                v205 = *((_QWORD *)v198 - 5);
                *v198 |= 1 << SBYTE4(v322);
                if ( (*(_QWORD *)(*(_QWORD *)(v205 + 40) + 32LL) & 0x2000) != 0 )
                  HIDWORD(v324) >>= 6;
                if ( v194 > 2 )
                  goto LABEL_435;
                v206 = *(void (**)(void))(v205 + 8 * v194 + 184);
                if ( v206 )
                {
                  if ( *((_DWORD *)v206 - 1) != -219284390 )
                    __break(0x8228u);
                  v206();
                }
LABEL_324:
                ++v200;
                v198 += 12;
                v199 += 8;
                if ( v200 >= *((unsigned int *)v284 + 548) )
                  goto LABEL_303;
              }
              if ( v200 == 8 )
                goto LABEL_435;
              LOWORD(v325[0]) -= *(_WORD *)(v202 + 556);
              LOWORD(v203) = WORD1(v325[0]) - *(_WORD *)(v190 + v199 + 558);
              WORD1(v325[0]) = v203;
              if ( !*(_DWORD *)(v190 + 6908) )
                goto LABEL_332;
LABEL_331:
              v291 = 0;
              v204 = *((_QWORD *)v284 + 251);
              v290 = 0;
              sde_crtc_calc_vpadding_param(v204, (unsigned __int16)v203);
              WORD1(v325[0]) = WORD2(v291);
              HIWORD(v325[0]) = v290;
              goto LABEL_332;
            }
LABEL_303:
            v187 = v277;
            ++v188;
            v9 = v284;
            if ( v188 >= *(unsigned int *)(v277 + 1808) )
              goto LABEL_345;
          }
          v195 = &unk_25E167;
          v196 = "sde_crtc_get_disp_op";
LABEL_318:
          printk(v195, v196);
          goto LABEL_319;
        }
LABEL_345:
        _X8 = (unsigned __int64 *)(v187 + 1792);
        __asm { PRFM            #0x11, [X8] }
        do
          v262 = __ldxr(_X8);
        while ( __stxr(v262 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        v60 = v281;
      }
    }
  }
LABEL_346:
  result = (_DWORD *)kfree(v60);
LABEL_347:
  if ( *((_DWORD *)v9 + 548) )
  {
    v207 = 0;
    v208 = v283 + 556;
    while ( 2 )
    {
      if ( v207 == 9 )
        goto LABEL_435;
      v214 = *v285;
      if ( (*(_BYTE *)(v283 + 6921) & 1) != 0 )
        v215 = *(_DWORD *)(v214 + 32) - 1;
      else
        v215 = v207;
      v216 = v285[1];
      if ( !v208 || !*(_WORD *)(v208 + 4) || !*(_WORD *)(v208 + 6) )
      {
        if ( v207 == 8 )
          goto LABEL_435;
        *((_DWORD *)v285 + 10) = 0;
      }
      if ( v282 > 2 )
        goto LABEL_435;
      v217 = v214 + 8LL * v282;
      v218 = *(__int64 (__fastcall **)(__int64, __int64))(v217 + 112);
      if ( v218 )
      {
        v219 = *((unsigned int *)v285 + 10);
        if ( *((_DWORD *)v218 - 1) != 135357866 )
          __break(0x8228u);
        result = (_DWORD *)v218(v214, v219);
      }
      v220 = (_QWORD *)(v216 + 8LL * v282);
      v221 = (__int64 (__fastcall *)(__int64, __int64, __int64))v220[134];
      if ( v221 )
      {
        v222 = *(unsigned int *)(*v285 + 32);
        if ( *((_DWORD *)v221 - 1) != -1730422967 )
          __break(0x8228u);
        result = (_DWORD *)v221(v216, v222, 1);
      }
      v223 = (_DWORD *)v220[89];
      if ( v223 )
      {
        if ( *(v223 - 1) != 1851168652 )
          __break(0x8228u);
        result = (_DWORD *)((__int64 (__fastcall *)(__int64, _QWORD *))v223)(v216, v293);
      }
      v224 = *(unsigned int *)(v214 + 32);
      v225 = v224 >> 6;
      v226 = 1LL << v224;
      _X9 = &v293[v225 - 1];
      __asm { PRFM            #0x11, [X9] }
      do
        v234 = __ldxr(_X9);
      while ( __stxr(v234 | v226, _X9) );
      v235 = (__int64 (__fastcall *)(__int64, __int64 *))v220[197];
      if ( v235 )
      {
        if ( *((_DWORD *)v235 - 1) != -60854866 )
          __break(0x8228u);
        result = (_DWORD *)v235(v216, &v292);
      }
      if ( (_drm_debug & 4) != 0 )
        result = (_DWORD *)_drm_dev_dbg(
                             0,
                             0,
                             0,
                             "lm %d, op_mode 0x%X, ctl %d, flush mask 0x%x\n",
                             *(_DWORD *)(*v285 + 32) - 1,
                             *((_DWORD *)v285 + 10),
                             *(_DWORD *)(v216 + 64) - 1,
                             LODWORD(v293[0]));
      if ( v208 && *(_WORD *)(v208 + 4) && *(_WORD *)(v208 + 6) )
      {
        v227 = (_DWORD *)v220[173];
        if ( v227 )
        {
          if ( v215 > 9 )
            goto LABEL_435;
          v228 = *(unsigned int *)(*v285 + 32);
          if ( *(v227 - 1) != -259091045 )
            __break(0x8228u);
          result = (_DWORD *)((__int64 (__fastcall *)(__int64, __int64, char *, _QWORD))v227)(
                               v216,
                               v228,
                               &v272[288 * (v215 >> 1)],
                               0);
        }
        v229 = *(__int64 (__fastcall **)(__int64, __int64, char *, __int64))(v217 + 304);
        if ( v229 )
        {
          if ( v215 > 9 )
            goto LABEL_435;
          v209 = v285;
          v210 = v214;
          v211 = &v272[288 * (v215 >> 1)];
          v212 = 0;
LABEL_350:
          v213 = *(unsigned int *)(*v209 + 32);
          if ( *((_DWORD *)v229 - 1) != -1100699727 )
            __break(0x8228u);
          result = (_DWORD *)v229(v210, v213, v211, v212);
        }
      }
      else
      {
        if ( (_drm_debug & 4) != 0 )
          result = (_DWORD *)_drm_dev_dbg(
                               0,
                               0,
                               0,
                               "%s: lm%d leave ctl%d mask 0 since null roi\n",
                               v284 + 2176,
                               *(_DWORD *)(v214 + 32) - 1,
                               *(_DWORD *)(v216 + 64) - 1);
        v230 = (_DWORD *)v220[173];
        if ( v230 )
        {
          v231 = *(unsigned int *)(*v285 + 32);
          if ( *(v230 - 1) != -259091045 )
            __break(0x8228u);
          result = (_DWORD *)((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v230)(v216, v231, 0, 1);
        }
        v229 = *(__int64 (__fastcall **)(__int64, __int64, char *, __int64))(v217 + 304);
        if ( v229 )
        {
          v209 = v285;
          v210 = v214;
          v211 = nullptr;
          v212 = 1;
          goto LABEL_350;
        }
      }
      v9 = v284;
      ++v207;
      v208 += 8;
      v285 += 6;
      if ( v207 >= *((unsigned int *)v284 + 548) )
        break;
      continue;
    }
  }
  v286 = *((_QWORD *)v9 + 251);
  if ( !v9 || !*(_QWORD *)v9 || (v236 = *(_QWORD *)(*(_QWORD *)v9 + 56LL)) == 0 )
  {
    v240 = &unk_25E167;
    v241 = "sde_crtc_get_disp_op";
LABEL_414:
    result = (_DWORD *)printk(v240, v241);
    goto LABEL_415;
  }
  v237 = *(_QWORD *)(v236 + 8);
  if ( !v237 )
  {
    v240 = &unk_234896;
    v241 = "_sde_crtc_get_kms";
    goto LABEL_414;
  }
  v238 = *(_QWORD *)(v237 + 152);
  if ( !v238 || (*(_QWORD *)(v238 + 22008) & 0x8000000000000LL) == 0 )
  {
LABEL_415:
    v239 = 0;
    if ( *((_DWORD *)v9 + 548) )
      goto LABEL_416;
    goto LABEL_433;
  }
  v239 = *(_DWORD *)(v236 + 5912);
  if ( !*((_DWORD *)v9 + 548) )
    goto LABEL_433;
LABEL_416:
  v242 = 0;
  v243 = 0;
  v244 = 0;
  v245 = 2200;
  v246 = (unsigned __int16 *)(v286 + 562);
  do
  {
    v296 = 0;
    v297 = 0;
    if ( v242 == 8 )
      goto LABEL_435;
    v247 = *(_QWORD *)&v284[v245];
    v248 = *(v246 - 1);
    if ( !v284[2196] )
      v244 = v242;
    if ( *(_DWORD *)(v247 + 376) != v248
      || *(_DWORD *)(v247 + 380) != *v246
      || *(_BYTE *)(v247 + 384) != (v244 & 1)
      || *(_BYTE *)(v286 + 6922) == 1 )
    {
      *(_DWORD *)(v247 + 376) = v248;
      v248 = *v246;
      *(_BYTE *)(v247 + 384) = v244 & 1;
      *(_DWORD *)(v247 + 380) = v248;
      LOWORD(v248) = *(v246 - 1);
      LODWORD(v296) = (unsigned __int16)v248;
      v249 = *v246;
      LOBYTE(v297) = v244 & 1;
      HIDWORD(v296) = v249;
      if ( v239 > 2 )
        goto LABEL_435;
      v250 = *(void (**)(void))(v247 + 8LL * v239 + 64);
      if ( v250 )
      {
        if ( *((_DWORD *)v250 - 1) != -1971864154 )
          __break(0x822Au);
        v250();
        LOWORD(v248) = *(v246 - 1);
      }
      v243 = 1;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_crtc_program_lm_output_roi",
      1999,
      -1,
      *((_DWORD *)v284 + 28),
      v242++,
      *(v246 - 3),
      *(v246 - 2),
      v248);
    v245 += 48;
    v246 += 4;
  }
  while ( v242 < *((unsigned int *)v284 + 548) );
  result = v284;
  if ( (v243 & 1) != 0 )
    result = (_DWORD *)sde_cp_crtc_res_change(v284);
LABEL_433:
  _ReadStatusReg(SP_EL0);
  return result;
}
