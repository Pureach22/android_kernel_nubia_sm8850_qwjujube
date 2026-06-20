const char **__fastcall dsi_panel_get(
        size_t a1,
        const char *a2,
        unsigned __int64 a3,
        const char *a4,
        __int64 a5,
        char a6)
{
  unsigned __int64 StatusReg; // x25
  const char *v7; // x24
  const char **v12; // x19
  __int64 (__fastcall *v13)(); // x15
  __int64 (__fastcall *v14)(); // x8
  __int64 (__fastcall *v15)(); // x16
  __int64 (__fastcall *v16)(); // x14
  __int64 (__fastcall *v17)(); // x13
  __int64 (__fastcall *v18)(); // x12
  __int64 (__fastcall *v19)(); // x11
  __int64 (__fastcall *v20)(); // x10
  __int64 (__fastcall *v21)(); // x9
  void *v22; // x0
  long double v23; // q0
  const char *v24; // x9
  const char *v25; // x8
  const char *v26; // x0
  __int64 v27; // x0
  const char *v28; // x8
  const char *v29; // x9
  char v30; // w8
  const char *v31; // x0
  int v32; // w0
  unsigned __int64 v33; // x0
  int v34; // w8
  const char *v35; // x0
  __int64 v36; // x0
  int v37; // w27
  size_t v38; // x0
  unsigned __int64 v39; // x2
  unsigned __int64 v40; // x26
  size_t v41; // x1
  size_t v42; // x0
  size_t v43; // x2
  const char *v44; // x0
  __int64 v45; // x0
  size_t v46; // x1
  size_t v47; // x0
  size_t v48; // x2
  const char *v49; // x8
  const char *v50; // x0
  __int64 v51; // x8
  const char *v52; // x9
  const char *v53; // x0
  const char *v54; // x0
  const char *v55; // x8
  const char *v56; // x0
  __int64 v57; // x8
  const char *v58; // x9
  const char *v59; // x0
  const char *v60; // x22
  unsigned int v61; // w0
  unsigned int v62; // w21
  const char *v63; // x3
  const char *v64; // x2
  __int64 v65; // x4
  const char *v66; // x2
  __int64 v67; // x3
  int v68; // w8
  int v69; // w21
  const char *v70; // x8
  const char *v71; // x0
  const char *v72; // x0
  const char *v73; // x8
  const char *v74; // x0
  __int64 v75; // x8
  const char *v76; // x9
  const char *v77; // x0
  const char *v78; // x21
  int v79; // w9
  const char *v80; // x0
  int v81; // w8
  const char *v82; // x9
  int v83; // w8
  const char *v84; // x0
  const char *v85; // x9
  int v86; // w8
  const char *v87; // x0
  const char *v88; // x9
  char v89; // w0
  int v90; // w8
  int v91; // w9
  int v92; // w9
  const char *v93; // x8
  const char *v94; // x0
  const char *v95; // x21
  const char *v96; // x0
  const char *v97; // x22
  long double v98; // q0
  int v99; // w8
  const char *v100; // x8
  const char *v101; // x0
  const char *v102; // x21
  const char *v103; // x0
  const char *v104; // x22
  int v105; // w8
  const char *v106; // x8
  const char *v107; // x0
  const char *v108; // x0
  const char *v109; // x22
  int v110; // w8
  const char *v111; // x8
  const char *v112; // x0
  const char *v113; // x8
  const char *v114; // x0
  const char *v115; // x21
  long double v116; // q0
  int v117; // w5
  const char *v118; // x8
  const char *v119; // x0
  long double v120; // q0
  int v121; // w5
  const char *v122; // x8
  const char *v123; // x0
  char v124; // w0
  const char *v125; // x8
  char v126; // w9
  const char *v127; // x0
  char v128; // w0
  const char *v129; // x8
  char v130; // w9
  const char *v131; // x0
  char v132; // w0
  const char *v133; // x8
  char v134; // w9
  const char *v135; // x0
  char v136; // w0
  const char *v137; // x8
  char v138; // w9
  const char *v139; // x0
  char v140; // w0
  const char *v141; // x8
  int v142; // w9
  const char *v143; // x0
  bool v144; // zf
  const char *v145; // x9
  const char *v146; // x0
  unsigned int v147; // w8
  int v148; // w0
  __int64 v149; // x5
  int v150; // w6
  long double v151; // q0
  const char *v152; // x8
  const char *v153; // x0
  __int64 v154; // x8
  const char *v155; // x9
  const char *v156; // x0
  const char *v157; // x21
  const char *v158; // x8
  const char *v159; // x0
  int v160; // w8
  const char *v161; // x9
  const char *v162; // x0
  int v163; // w8
  const char *v164; // x9
  const char *v165; // x0
  long double v166; // q0
  char v167; // w8
  const char *v168; // x9
  const char *v169; // x0
  const char *v170; // x0
  const char *v171; // x21
  long double v172; // q0
  int v173; // w25
  char v174; // w22
  int v175; // w23
  const char *v176; // x8
  const char *v177; // x0
  char v178; // w0
  int v179; // w24
  char v180; // w21
  const char *v181; // x5
  long double v182; // q0
  const char *v183; // x8
  const char *v184; // x0
  const char *v185; // x22
  long double v186; // q0
  char v187; // w8
  const char *v188; // x9
  const char *v189; // x0
  char v190; // w0
  const char *v191; // x8
  char v192; // w9
  const char *v193; // x0
  char v194; // w0
  const char *v195; // x8
  char v196; // w9
  const char *v197; // x0
  char v198; // w0
  const char *v199; // x8
  char v200; // w9
  const char *v201; // x0
  char v202; // w0
  const char *v203; // x8
  char v204; // w9
  const char *v205; // x0
  char v206; // w0
  const char *v207; // x8
  char v208; // w9
  const char *v209; // x0
  char v210; // w0
  const char *v211; // x8
  char v212; // w9
  const char *v213; // x0
  const char *v214; // x0
  const char *v215; // x21
  long double v216; // q0
  int v217; // w8
  const char *v218; // x9
  const char *v219; // x0
  unsigned int v220; // w0
  const char *v221; // x8
  const char *v222; // x0
  const char *v223; // x22
  long double v224; // q0
  int v225; // w8
  const char *v226; // x8
  const char *v227; // x0
  long double v228; // q0
  int v229; // w8
  const char *v230; // x8
  const char *v231; // x0
  long double v232; // q0
  char v233; // w8
  const char *v234; // x9
  const char *v235; // x0
  char v236; // w0
  const char *v237; // x8
  const char *v238; // x0
  const char *v239; // x8
  const char *v240; // x0
  __int64 v241; // x8
  const char *v242; // x9
  const char *v243; // x0
  __int64 v244; // x8
  const char *v245; // x9
  const char *v246; // x0
  const char *v247; // x21
  const char *v248; // x8
  const char *v249; // x0
  const char *v250; // x0
  const char *v251; // x22
  long double v252; // q0
  int v253; // w8
  const char *v254; // x9
  const char *v255; // x0
  int v256; // w0
  __int64 v257; // x2
  const char *v258; // x8
  const char *v259; // x0
  int v260; // w3
  const char *v261; // x8
  const char *v262; // x0
  const char *v263; // x21
  char v264; // w0
  const char *v265; // x8
  char v266; // w9
  const char *v267; // x0
  char v268; // w0
  const char *v269; // x8
  const char *v270; // x0
  char v271; // w0
  const char *v272; // x8
  char v273; // w9
  const char *v274; // x0
  unsigned int v275; // w22
  long double v276; // q0
  const char *v277; // x9
  const char *v278; // x0
  int v279; // w0
  long double v280; // q0
  __int64 v281; // x8
  __int64 v282; // x2
  const char *v283; // x8
  const char *v284; // x0
  __int64 v285; // x3
  const char *v286; // x8
  const char *v287; // x0
  unsigned int v288; // w21
  long double v289; // q0
  const char *v290; // x9
  const char *v291; // x0
  int v292; // w8
  int v293; // w8
  int v294; // w5
  int v295; // w3
  long double v296; // q0
  __int64 v297; // x2
  const char *v298; // x8
  const char *v299; // x0
  __int64 v300; // x3
  int v301; // w0
  int v302; // w21
  const char *v303; // x10
  __int64 v304; // x9
  unsigned int v305; // w8
  __int64 v306; // x9
  unsigned int *v307; // x10
  unsigned int v308; // w12
  unsigned int v309; // w11
  unsigned int v310; // t1
  const char *v311; // x10
  __int64 v312; // x9
  unsigned int v313; // w8
  __int64 v314; // x9
  unsigned int *v315; // x10
  unsigned int v316; // w11
  unsigned int v317; // t1
  const char *v318; // x8
  const char *v319; // x0
  char v320; // w0
  const char *v321; // x8
  const char *v322; // x0
  long double v323; // q0
  int v324; // w8
  long double v325; // q0
  const char *v326; // x9
  const char *v327; // x0
  int v328; // w0
  int v329; // w21
  const char *v330; // x9
  const char *v331; // x0
  const char *v332; // x8
  const char *v333; // x0
  char v334; // w0
  const char *v335; // x8
  const char *v336; // x0
  char v337; // w0
  const char *v338; // x8
  char v339; // w9
  const char *v340; // x0
  char v341; // w0
  long double v342; // q0
  char v343; // w8
  char v344; // w8
  const char *v345; // x8
  const char *v346; // x0
  long double v347; // q0
  const char *v348; // x9
  const char *v349; // x0
  const char *v350; // x0
  const char *v351; // x21
  int v352; // w8
  const char *v353; // x9
  const char *v354; // x0
  int v355; // w0
  const char *v356; // x8
  const char *v357; // x0
  const char *v358; // x21
  long double v359; // q0
  int v360; // w8
  const char *v361; // x9
  const char *v362; // x0
  long double v363; // q0
  int v364; // w8
  const char *v365; // x9
  const char *v366; // x0
  const char *v367; // x0
  const char *v368; // x22
  int v369; // w8
  const char *v370; // x9
  unsigned int v371; // w0
  const char *v372; // x8
  int v373; // w0
  int v374; // w0
  int v375; // w21
  int v376; // w0
  unsigned int mode_count; // w0
  int v378; // w0
  long double v379; // q0
  int v380; // w0
  long double v381; // q0
  int v382; // w0
  long double v383; // q0
  unsigned int v384; // w0
  unsigned int v385; // w0
  unsigned __int64 v386; // x2
  unsigned __int64 v387; // x2
  __int64 v388; // x26
  int v390; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v391; // [xsp+10h] [xbp-10h] BYREF
  int v392; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v393; // [xsp+18h] [xbp-8h]

  LOBYTE(v7) = a6;
  v393 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = (const char **)_kmalloc_cache_noprof(kthread_park, 3520, 2600);
  if ( !v12 )
  {
LABEL_544:
    v12 = (const char **)-12LL;
    goto LABEL_545;
  }
  while ( 1 )
  {
    if ( ((unsigned __int8)v7 & 1) != 0 )
    {
      v13 = dsi_panel_vm_stub;
      v14 = dsi_panel_vm_trigger_esd_attack;
      v15 = dsi_panel_vm_stub;
      v16 = dsi_panel_vm_stub;
      v17 = dsi_panel_vm_stub;
      v18 = dsi_panel_vm_stub;
      v19 = dsi_panel_vm_stub;
      v20 = dsi_panel_vm_stub;
      v21 = dsi_panel_vm_stub;
    }
    else
    {
      v14 = dsi_panel_trigger_esd_attack;
      v21 = dsi_panel_parse_power_cfg;
      v20 = dsi_panel_parse_gpios;
      v19 = dsi_panel_bl_unregister;
      v18 = dsi_panel_bl_register;
      v17 = dsi_panel_gpio_release;
      v16 = dsi_panel_pinctrl_deinit;
      v15 = dsi_panel_gpio_request;
      v13 = dsi_panel_pinctrl_init;
    }
    v22 = v12 + 227;
    v12[280] = (const char *)v13;
    v12[281] = (const char *)v15;
    v12[282] = (const char *)v16;
    v12[283] = (const char *)v17;
    v12[284] = (const char *)v18;
    v12[285] = (const char *)v19;
    v12[286] = (const char *)v20;
    v12[287] = (const char *)v21;
    v12[288] = (const char *)v14;
    v12[152] = (const char *)a1;
    v12[1] = a4;
    v12[2] = a2;
    if ( a3 )
    {
      memcpy(v22, &dsi_parser_get_parser_utils_parser_utils, 0x90u);
      v12[227] = (const char *)a3;
      *(double *)&v23 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: switching to parser APIs\n");
      v24 = v12[2];
      v25 = v12[229];
      v26 = v12[227];
    }
    else
    {
      a3 = (unsigned __int64)(v12 + 227);
      memcpy(v22, &dsi_parser_get_of_utils_of_utils_0, 0x90u);
      v25 = (const char *)&of_get_property;
      v26 = a2;
      v24 = a2;
      v12[227] = a2;
    }
    v12[228] = v24;
    v392 = 0;
    if ( *((_DWORD *)v25 - 1) != -1612502898 )
      __break(0x8228u);
    v27 = ((__int64 (__fastcall *)(const char *, const char *, int *, long double))v25)(
            v26,
            "qcom,mdss-dsi-panel-name",
            &v392,
            v23);
    v28 = v12[227];
    v29 = v12[233];
    *v12 = (const char *)v27;
    if ( *((_DWORD *)v29 - 1) != -834495637 )
      __break(0x8229u);
    v30 = ((__int64 (__fastcall *)(const char *, const char *))v29)(v28, "qcom,mdss-dsi-panel-xr");
    v31 = v12[1];
    if ( (v30 & 1) == 0 )
      break;
    v32 = strcmp(v31, "primary");
    if ( v32 )
      a1 = 7;
    else
      a1 = 6;
    if ( v32 )
      v7 = " right";
    else
      v7 = " left";
    v33 = strnlen(v7, a1);
    if ( v33 > a1 )
      goto LABEL_533;
    if ( v33 >= a1 )
      goto LABEL_534;
    v34 = v392 + v33;
    v35 = v12[152];
    a3 = v34;
    v392 = v34;
    v36 = devm_kmalloc(v35, v34, 3520);
    if ( !v36 )
      goto LABEL_96;
    v37 = v392;
    StatusReg = (unsigned __int64)*v12;
    a4 = (const char *)v36;
    v38 = strnlen(*v12, v392);
    if ( v38 == -1 && v37 != -1 )
      goto LABEL_535;
    if ( v38 == v37 )
      v39 = v37;
    else
      v39 = v38 + 1;
    if ( v39 > a3 )
      goto LABEL_536;
    v33 = sized_strscpy(a4, StatusReg);
    if ( !(_DWORD)a3 )
      goto LABEL_532;
    v40 = v392;
    if ( v392 >= a3 )
      v41 = a3;
    else
      v41 = v392;
    v42 = strnlen(a4, v41);
    StatusReg = v42;
    if ( v42 >= a3 && v42 != v40 )
      goto LABEL_537;
    v33 = strnlen(v7, a1);
    if ( v33 > a1 )
      goto LABEL_533;
    if ( v33 >= a1 )
      goto LABEL_534;
    if ( StatusReg >= v40 )
      goto LABEL_75;
    if ( StatusReg < a3 )
    {
      if ( v33 + StatusReg >= v40 )
        a1 = v40 - 1;
      else
        a1 = v33 + StatusReg;
      if ( a1 < a3 )
      {
        if ( v33 + StatusReg >= v40 )
          v43 = ~StatusReg + v40;
        else
          v43 = v33;
        v33 = (unsigned __int64)memcpy((void *)&a4[StatusReg], v7, v43);
        if ( (a1 & 0x8000000000000000LL) == 0 )
        {
LABEL_73:
          if ( a3 > a1 )
          {
            a4[a1] = 0;
LABEL_75:
            *v12 = a4;
            goto LABEL_76;
          }
        }
LABEL_532:
        __break(1u);
LABEL_533:
        v33 = _fortify_panic(2, a1, v33 + 1);
LABEL_534:
        v38 = _fortify_panic(4, a1, v33 + 1);
LABEL_535:
        _fortify_panic(2, -1, v38 + 1);
LABEL_536:
        _fortify_panic(7, a3, v39);
LABEL_537:
        v386 = StatusReg + 1;
LABEL_541:
        v47 = _fortify_panic(2, a3, v386);
LABEL_542:
        v387 = v47 + 1;
        goto LABEL_543;
      }
LABEL_538:
      _fortify_panic(9, a3, a1 + 1);
    }
    v387 = StatusReg + 1;
LABEL_543:
    _fortify_panic(8, a3, v387);
    StatusReg = _ReadStatusReg(SP_EL0);
    v388 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &dsi_panel_get__alloc_tag;
    v12 = (const char **)_kmalloc_cache_noprof(kthread_park, 3520, 2600);
    *(_QWORD *)(StatusReg + 80) = v388;
    if ( !v12 )
      goto LABEL_544;
  }
  if ( !strcmp(v31, "secondary") )
  {
    v44 = v12[152];
    a3 = v392 + 10;
    v392 += 10;
    v45 = devm_kmalloc(v44, v392, 3520);
    if ( !v45 )
    {
LABEL_96:
      v66 = "*ERROR* [msm-dsi-error]: failed to parse panel name, rc=%d\n";
      v67 = 4294967284LL;
      v62 = -12;
LABEL_97:
      drm_dev_printk(0, &unk_248D72, v66, v67);
LABEL_98:
      kfree(v12);
      v12 = (const char **)(int)v62;
      goto LABEL_545;
    }
    StatusReg = (unsigned int)v392;
    a1 = (size_t)*v12;
    a4 = (const char *)v45;
    LOBYTE(v7) = v392;
    v38 = strnlen(*v12, v392);
    if ( v38 == -1 && (_DWORD)StatusReg != -1 )
      goto LABEL_535;
    if ( v38 == (int)StatusReg )
      v39 = (int)StatusReg;
    else
      v39 = v38 + 1;
    if ( v39 > a3 )
      goto LABEL_536;
    v33 = sized_strscpy(a4, a1);
    if ( !(_DWORD)a3 )
      goto LABEL_532;
    v7 = (const char *)v392;
    if ( v392 >= a3 )
      v46 = a3;
    else
      v46 = v392;
    v47 = strnlen(a4, v46);
    if ( v47 >= a3 && (const char *)v47 != v7 )
    {
      v386 = v47 + 1;
      goto LABEL_541;
    }
    if ( v47 >= (unsigned __int64)v7 )
      goto LABEL_75;
    if ( v47 >= a3 )
      goto LABEL_542;
    if ( v47 + 10 >= (unsigned __int64)v7 )
      a1 = (size_t)(v7 - 1);
    else
      a1 = v47 + 10;
    if ( a1 < a3 )
    {
      if ( v47 + 10 >= (unsigned __int64)v7 )
        v48 = (size_t)&v7[~v47];
      else
        v48 = 10;
      v33 = (unsigned __int64)memcpy((void *)&a4[v47], "_secondary", v48);
      if ( (a1 & 0x8000000000000000LL) == 0 )
        goto LABEL_73;
      goto LABEL_532;
    }
    goto LABEL_538;
  }
  if ( !*v12 )
  {
    a4 = "Default dsi panel";
    goto LABEL_75;
  }
LABEL_76:
  v49 = v12[233];
  v50 = v12[227];
  if ( *((_DWORD *)v49 - 1) != -834495637 )
    __break(0x8228u);
  v51 = ((__int64 (__fastcall *)(const char *, const char *))v49)(v50, "qcom,mdss-panel-need-post-on-supply") & 1;
  v52 = v12[229];
  v53 = v12[227];
  *((_BYTE *)v12 + 2232) = v51;
  *((_DWORD *)v12 + 557) = 0;
  if ( *((_DWORD *)v52 - 1) != -1612502898 )
    __break(0x8229u);
  v54 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v52)(
                        v53,
                        "qcom,mdss-dsi-panel-physical-type",
                        0);
  if ( v54 && !strcmp(v54, "oled") )
    *((_DWORD *)v12 + 557) = 1;
  v55 = v12[233];
  v56 = v12[227];
  if ( *((_DWORD *)v55 - 1) != -834495637 )
    __break(0x8228u);
  v57 = ((__int64 (__fastcall *)(const char *, const char *))v55)(v56, "qcom,mdss-disable-cesta-hw-sleep") & 1;
  v58 = v12[231];
  v59 = v12[227];
  v60 = *v12;
  *((_BYTE *)v12 + 1975) = v57;
  v392 = 0;
  if ( *((_DWORD *)v58 - 1) != 309187163 )
    __break(0x8229u);
  v61 = ((__int64 (__fastcall *)(const char *, const char *, int *))v58)(v59, "qcom,mdss-dsi-bpp", &v392);
  if ( v61 )
  {
    v62 = v61;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to read qcom,mdss-dsi-bpp, rc=%d\n", v60, v61);
    v63 = *v12;
    v64 = "*ERROR* [msm-dsi-error]: [%s] failed to get pixel format, rc=%d\n";
    v65 = v62;
    goto LABEL_89;
  }
  v68 = v392;
  *((_BYTE *)v12 + 1233) = v392;
  if ( v68 > 15 )
  {
    switch ( v68 )
    {
      case 16:
        v69 = 0;
        break;
      case 18:
        v70 = v12[229];
        v71 = v12[227];
        if ( *((_DWORD *)v70 - 1) != -1612502898 )
          __break(0x8228u);
        v72 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v70)(
                              v71,
                              "qcom,mdss-dsi-pixel-packing",
                              0);
        v69 = 1;
        if ( v72 )
        {
          if ( !strcmp(v72, "loose") )
            v69 = 2;
          else
            v69 = 1;
        }
        break;
      case 30:
        v69 = 7;
        break;
      default:
        goto LABEL_105;
    }
  }
  else
  {
    switch ( v68 )
    {
      case 3:
        v69 = 4;
        break;
      case 8:
        v69 = 5;
        break;
      case 12:
        v69 = 6;
        break;
      default:
LABEL_105:
        v69 = 3;
        break;
    }
  }
  v73 = v12[233];
  v74 = v12[227];
  *((_DWORD *)v12 + 306) = v69;
  if ( *((_DWORD *)v73 - 1) != -834495637 )
    __break(0x8228u);
  v75 = ((__int64 (__fastcall *)(const char *, const char *))v73)(v74, "qcom,mdss-dsi-bpp-switch") & 1;
  v76 = v12[233];
  v77 = v12[227];
  v78 = *v12;
  *((_BYTE *)v12 + 1234) = v75;
  if ( *((_DWORD *)v76 - 1) != -834495637 )
    __break(0x8229u);
  v79 = ((__int64 (__fastcall *)(const char *, const char *))v76)(v77, "qcom,mdss-dsi-lane-0-state") & 1;
  v80 = v12[227];
  v81 = *((_DWORD *)v12 + 307) | v79;
  v82 = v12[233];
  *((_DWORD *)v12 + 307) = v81;
  if ( *((_DWORD *)v82 - 1) != -834495637 )
    __break(0x8229u);
  if ( (((__int64 (__fastcall *)(const char *, const char *))v82)(v80, "qcom,mdss-dsi-lane-1-state") & 1) != 0 )
    v83 = 2;
  else
    v83 = 0;
  v84 = v12[227];
  v85 = v12[233];
  *((_DWORD *)v12 + 307) |= v83;
  if ( *((_DWORD *)v85 - 1) != -834495637 )
    __break(0x8229u);
  if ( (((__int64 (__fastcall *)(const char *, const char *))v85)(v84, "qcom,mdss-dsi-lane-2-state") & 1) != 0 )
    v86 = 4;
  else
    v86 = 0;
  v87 = v12[227];
  v88 = v12[233];
  *((_DWORD *)v12 + 307) |= v86;
  if ( *((_DWORD *)v88 - 1) != -834495637 )
    __break(0x8229u);
  v89 = ((__int64 (__fastcall *)(const char *, const char *))v88)(v87, "qcom,mdss-dsi-lane-3-state");
  v90 = *((_DWORD *)v12 + 307);
  if ( (v89 & 1) != 0 )
    v91 = 8;
  else
    v91 = 0;
  v92 = v90 | v91;
  *((_DWORD *)v12 + 307) = v92;
  *((_BYTE *)v12 + 1232) = ((v90 & 2) != 0) + (v90 & 1) + ((v90 & 4) != 0) + ((v92 & 8) != 0);
  if ( !v92 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] No data lanes are enabled, rc=%d\n", v78, 0);
    v63 = *v12;
    v64 = "*ERROR* [msm-dsi-error]: [%s] failed to parse lane states, rc=%d\n";
    goto LABEL_143;
  }
  v93 = v12[229];
  v94 = v12[227];
  v95 = *v12;
  if ( *((_DWORD *)v93 - 1) != -1612502898 )
    __break(0x8228u);
  v96 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v93)(
                        v94,
                        "qcom,mdss-dsi-color-order",
                        0);
  if ( !v96 )
  {
    *(double *)&v98 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Falling back to default color order\n", v95);
    goto LABEL_145;
  }
  v97 = v96;
  if ( !strcmp(v96, "rgb_swap_rgb") )
  {
LABEL_145:
    v99 = 0;
    goto LABEL_146;
  }
  if ( !strcmp(v97, "rgb_swap_rbg") )
  {
    v99 = 1;
  }
  else if ( !strcmp(v97, "rgb_swap_brg") )
  {
    v99 = 3;
  }
  else if ( !strcmp(v97, "rgb_swap_grb") )
  {
    v99 = 4;
  }
  else
  {
    if ( strcmp(v97, "rgb_swap_gbr") )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Unrecognized color order-%s\n", v95, v97);
      v63 = *v12;
      *((_WORD *)v12 + 630) = 0;
      v64 = "*ERROR* [msm-dsi-error]: [%s] failed to parse color swap config, rc=%d\n";
      *((_BYTE *)v12 + 1262) = 0;
LABEL_143:
      v65 = 4294967274LL;
      v62 = -22;
LABEL_89:
      drm_dev_printk(0, &unk_248D72, v64, v63, v65);
      v66 = "*ERROR* [msm-dsi-error]: failed to parse host configuration, rc=%d\n";
LABEL_90:
      v67 = v62;
      goto LABEL_97;
    }
    v99 = 5;
  }
LABEL_146:
  *((_DWORD *)v12 + 314) = v99;
  v100 = v12[229];
  v101 = v12[227];
  v102 = *v12;
  *((_WORD *)v12 + 630) = 0;
  *((_BYTE *)v12 + 1262) = 0;
  if ( *((_DWORD *)v100 - 1) != -1612502898 )
    __break(0x8228u);
  v103 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v100)(
                         v101,
                         "qcom,mdss-dsi-mdp-trigger",
                         0,
                         v98);
  if ( !v103 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Falling back to default MDP trigger\n", v102);
    goto LABEL_155;
  }
  v104 = v103;
  if ( !strcmp(v103, "none") )
  {
    *((_DWORD *)v12 + 311) = 0;
    goto LABEL_163;
  }
  if ( !strcmp(v104, "trigger_te") )
  {
    v105 = 1;
    goto LABEL_162;
  }
  if ( !strcmp(v104, "trigger_sw") )
  {
LABEL_155:
    v105 = 3;
    goto LABEL_162;
  }
  if ( strcmp(v104, "trigger_sw_te") )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Unrecognized mdp trigger type (%s)\n", v102, v104);
    goto LABEL_163;
  }
  v105 = 5;
LABEL_162:
  *((_DWORD *)v12 + 311) = v105;
LABEL_163:
  v106 = v12[229];
  v107 = v12[227];
  if ( *((_DWORD *)v106 - 1) != -1612502898 )
    __break(0x8228u);
  v108 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v106)(
                         v107,
                         "qcom,mdss-dsi-dma-trigger",
                         0);
  if ( !v108 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Falling back to default MDP trigger\n", v102);
    goto LABEL_173;
  }
  v109 = v108;
  if ( !strcmp(v108, "none") )
  {
    *((_DWORD *)v12 + 312) = 0;
    goto LABEL_180;
  }
  if ( !strcmp(v109, "trigger_te") )
  {
    v110 = 1;
    goto LABEL_179;
  }
  if ( !strcmp(v109, "trigger_sw") )
  {
LABEL_173:
    v110 = 3;
    goto LABEL_179;
  }
  if ( !strcmp(v109, "trigger_sw_seof") )
  {
    v110 = 4;
  }
  else
  {
    if ( strcmp(v109, "trigger_sw_te") )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Unrecognized mdp trigger type (%s)\n", v102, v109);
      goto LABEL_180;
    }
    v110 = 5;
  }
LABEL_179:
  *((_DWORD *)v12 + 312) = v110;
LABEL_180:
  v111 = v12[231];
  v112 = v12[227];
  if ( *((_DWORD *)v111 - 1) != 309187163 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, const char **))v111)(
         v112,
         "qcom,mdss-dsi-te-pin-select",
         v12 + 155) )
  {
    printk(&unk_26ACA9, v102);
    *((_DWORD *)v12 + 310) = 1;
  }
  v113 = v12[231];
  v114 = v12[227];
  v115 = *v12;
  v392 = 0;
  v390 = 0;
  v391 = 0;
  if ( *((_DWORD *)v113 - 1) != 309187163 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(const char *, const char *, int *))v113)(v114, "qcom,mdss-dsi-t-clk-post", &v392) )
  {
    v117 = v392;
    *((_DWORD *)v12 + 316) = v392;
    *(double *)&v116 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] t_clk_post = %d\n", v115, v117);
  }
  v118 = v12[231];
  v119 = v12[227];
  v392 = 0;
  if ( *((_DWORD *)v118 - 1) != 309187163 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v118)(
          v119,
          "qcom,mdss-dsi-t-clk-pre",
          &v392,
          v116) )
  {
    v121 = v392;
    *((_DWORD *)v12 + 317) = v392;
    *(double *)&v120 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] t_clk_pre = %d\n", v115, v121);
  }
  v122 = v12[233];
  v123 = v12[227];
  if ( *((_DWORD *)v122 - 1) != -834495637 )
    __break(0x8228u);
  v124 = ((__int64 (__fastcall *)(const char *, const char *, long double))v122)(
           v123,
           "qcom,mdss-dsi-rx-eot-ignore",
           v120);
  v125 = v12[233];
  v126 = v124 & 1;
  v127 = v12[227];
  *((_BYTE *)v12 + 1272) = v126;
  if ( *((_DWORD *)v125 - 1) != -834495637 )
    __break(0x8228u);
  v128 = ((__int64 (__fastcall *)(const char *, const char *))v125)(v127, "qcom,mdss-dsi-tx-eot-append");
  v129 = v12[233];
  v130 = v128 & 1;
  v131 = v12[227];
  *((_BYTE *)v12 + 1273) = v130;
  if ( *((_DWORD *)v129 - 1) != -834495637 )
    __break(0x8228u);
  v132 = ((__int64 (__fastcall *)(const char *, const char *))v129)(v131, "qcom,mdss-dsi-ext-bridge-mode");
  v133 = v12[233];
  v134 = v132 & 1;
  v135 = v12[227];
  *((_BYTE *)v12 + 1274) = v134;
  if ( *((_DWORD *)v133 - 1) != -834495637 )
    __break(0x8228u);
  v136 = ((__int64 (__fastcall *)(const char *, const char *))v133)(v135, "qcom,mdss-dsi-force-clock-lane-hs");
  v137 = v12[233];
  v138 = v136 & 1;
  v139 = v12[227];
  *((_BYTE *)v12 + 1275) = v138;
  if ( *((_DWORD *)v137 - 1) != -834495637 )
    __break(0x8228u);
  v140 = ((__int64 (__fastcall *)(const char *, const char *))v137)(v139, "qcom,panel-cphy-mode");
  v141 = v12[231];
  v142 = v140 & 1;
  v143 = v12[227];
  *((_DWORD *)v12 + 319) = v142;
  if ( *((_DWORD *)v141 - 1) != 309187163 )
    __break(0x8228u);
  v144 = ((unsigned int (__fastcall *)(const char *, const char *, unsigned int *))v141)(
           v143,
           "qcom,mdss-dsi-dma-schedule-line",
           &v391) == 0;
  v145 = v12[231];
  v146 = v12[227];
  if ( v144 )
    v147 = v391;
  else
    v147 = 0;
  *((_DWORD *)v12 + 326) = v147;
  if ( *((_DWORD *)v145 - 1) != 309187163 )
    __break(0x8229u);
  v148 = ((__int64 (__fastcall *)(const char *, const char *, int *))v145)(
           v146,
           "qcom,mdss-dsi-dma-schedule-window",
           &v390);
  v149 = *((unsigned int *)v12 + 326);
  if ( v148 )
    v150 = 0;
  else
    v150 = v390;
  *((_DWORD *)v12 + 327) = v150;
  *(double *)&v151 = _drm_dev_dbg(
                       0,
                       0,
                       0,
                       "[msm-dsi-debug]: [%s] DMA scheduling parameters Line: %d Window: %d\n",
                       v115,
                       v149);
  v152 = v12[233];
  v153 = v12[227];
  if ( *((_DWORD *)v152 - 1) != -834495637 )
    __break(0x8228u);
  v154 = ((__int64 (__fastcall *)(const char *, const char *, long double))v152)(
           v153,
           "qcom,mdss-dsi-panel-skip-pps-update",
           v151)
       & 1;
  v155 = v12[233];
  v156 = v12[227];
  v157 = *v12;
  *((_BYTE *)v12 + 1312) = v154;
  v392 = 0;
  if ( *((_DWORD *)v155 - 1) != -834495637 )
    __break(0x8229u);
  if ( (((__int64 (__fastcall *)(const char *, const char *))v155)(v156, "qcom,split-link-enabled") & 1) != 0 )
  {
    v158 = v12[231];
    v159 = v12[227];
    if ( *((_DWORD *)v158 - 1) != 309187163 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(const char *, const char *, int *))v158)(v159, "qcom,sublinks-count", &v392)
      || (v160 = v392) == 0 )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Using default sublinks count\n", v157);
      v160 = 2;
    }
    v161 = v12[231];
    v162 = v12[227];
    *((_DWORD *)v12 + 321) = v160;
    if ( *((_DWORD *)v161 - 1) != 309187163 )
      __break(0x8229u);
    if ( ((unsigned int (__fastcall *)(const char *, const char *, int *))v161)(v162, "qcom,lanes-per-sublink", &v392)
      || (v163 = v392) == 0 )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Using default lanes per sublink\n", v157);
      v163 = 2;
    }
    v164 = v12[233];
    v165 = v12[227];
    *((_DWORD *)v12 + 322) = v163;
    if ( *((_DWORD *)v164 - 1) != -834495637 )
      __break(0x8229u);
    if ( (((__int64 (__fastcall *)(const char *, const char *))v164)(v165, "qcom,split-link-sublink-swap") & 1) == 0 )
      *((_BYTE *)v12 + 1281) = 0;
    *(double *)&v166 = _drm_dev_dbg(
                         0,
                         0,
                         0,
                         "[msm-dsi-debug]: [%s] Split link is supported %d-%d\n",
                         v157,
                         *((_DWORD *)v12 + 321),
                         *((_DWORD *)v12 + 322));
    v167 = 1;
  }
  else
  {
    *(double *)&v166 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Split link is not supported\n", v157);
    v167 = 0;
  }
  v168 = v12[229];
  v169 = v12[227];
  *((_BYTE *)v12 + 1280) = v167;
  if ( *((_DWORD *)v168 - 1) != -1612502898 )
    __break(0x8229u);
  v170 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v168)(
                         v169,
                         "qcom,mdss-dsi-panel-type",
                         0,
                         v166);
  if ( !v170 )
  {
    *(double *)&v172 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Fallback to default panel mode\n", *v12);
    goto LABEL_240;
  }
  v171 = v170;
  if ( !strcmp(v170, "dsi_video_mode") )
  {
LABEL_240:
    v173 = 0;
    v174 = 1;
    v175 = 1;
    goto LABEL_241;
  }
  if ( strcmp(v171, "dsi_cmd_mode") )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Unrecognized panel type-%s\n", *v12, v171);
    v62 = -22;
LABEL_310:
    v66 = "*ERROR* [msm-dsi-error]: failed to parse panel mode configuration, rc=%d\n";
    goto LABEL_90;
  }
  v174 = 0;
  v175 = 2;
  v173 = 1;
LABEL_241:
  v176 = v12[233];
  v177 = v12[227];
  if ( *((_DWORD *)v176 - 1) != -834495637 )
    __break(0x8228u);
  v178 = ((__int64 (__fastcall *)(const char *, const char *, long double))v176)(
           v177,
           "qcom,mdss-dsi-panel-mode-switch",
           v172);
  v179 = v178 & 1;
  v180 = v178;
  if ( (v178 & 1) != 0 )
    v181 = "enabled";
  else
    v181 = "disabled";
  *(double *)&v182 = _drm_dev_dbg(
                       0,
                       0,
                       0,
                       "[msm-dsi-debug]: %s: panel operating mode switch feature %s\n",
                       "dsi_panel_parse_panel_mode",
                       v181);
  if ( (v174 & 1) == 0 && (v180 & 1) == 0 )
    goto LABEL_283;
  v183 = v12[231];
  v184 = v12[227];
  v185 = *v12;
  v392 = 0;
  v391 = 0;
  if ( *((_DWORD *)v183 - 1) != 309187163 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, unsigned int *, long double))v183)(
         v184,
         "qcom,mdss-dsi-h-sync-pulse",
         &v391,
         v182) )
  {
    *(double *)&v186 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] fallback to default h-sync-pulse\n", v185);
    v187 = 0;
    goto LABEL_252;
  }
  v187 = v391;
  if ( v391 >= 2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Unrecognized value for mdss-dsi-h-sync-pulse\n", v185);
LABEL_274:
    v62 = -22;
LABEL_281:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Failed to parse video host cfg, rc=%d\n", *v12, v62);
    goto LABEL_310;
  }
LABEL_252:
  v188 = v12[233];
  v189 = v12[227];
  *((_BYTE *)v12 + 1317) = v187;
  if ( *((_DWORD *)v188 - 1) != -834495637 )
    __break(0x8229u);
  v190 = ((__int64 (__fastcall *)(const char *, const char *, long double))v188)(
           v189,
           "qcom,mdss-dsi-hfp-power-mode",
           v186);
  v191 = v12[233];
  v192 = v190 & 1;
  v193 = v12[227];
  *((_BYTE *)v12 + 1318) = v192;
  if ( *((_DWORD *)v191 - 1) != -834495637 )
    __break(0x8228u);
  v194 = ((__int64 (__fastcall *)(const char *, const char *))v191)(v193, "qcom,mdss-dsi-hbp-power-mode");
  v195 = v12[233];
  v196 = v194 & 1;
  v197 = v12[227];
  *((_BYTE *)v12 + 1319) = v196;
  if ( *((_DWORD *)v195 - 1) != -834495637 )
    __break(0x8228u);
  v198 = ((__int64 (__fastcall *)(const char *, const char *))v195)(v197, "qcom,mdss-dsi-hsa-power-mode");
  v199 = v12[233];
  v200 = v198 & 1;
  v201 = v12[227];
  *((_BYTE *)v12 + 1320) = v200;
  if ( *((_DWORD *)v199 - 1) != -834495637 )
    __break(0x8228u);
  v202 = ((__int64 (__fastcall *)(const char *, const char *))v199)(v201, "qcom,mdss-dsi-last-line-interleave");
  v203 = v12[233];
  v204 = v202 & 1;
  v205 = v12[227];
  *((_BYTE *)v12 + 1316) = v204;
  if ( *((_DWORD *)v203 - 1) != -834495637 )
    __break(0x8228u);
  v206 = ((__int64 (__fastcall *)(const char *, const char *))v203)(v205, "qcom,mdss-dsi-bllp-eof-power-mode");
  v207 = v12[233];
  v208 = v206 & 1;
  v209 = v12[227];
  *((_BYTE *)v12 + 1321) = v208;
  if ( *((_DWORD *)v207 - 1) != -834495637 )
    __break(0x8228u);
  v210 = ((__int64 (__fastcall *)(const char *, const char *))v207)(v209, "qcom,mdss-dsi-bllp-power-mode");
  v211 = v12[229];
  v212 = v210 & 1;
  v213 = v12[227];
  *((_BYTE *)v12 + 1322) = v212;
  if ( *((_DWORD *)v211 - 1) != -1612502898 )
    __break(0x8228u);
  v214 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v211)(
                         v213,
                         "qcom,mdss-dsi-traffic-mode",
                         0);
  if ( !v214 )
  {
    *(double *)&v216 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Falling back to default traffic mode\n", v185);
    goto LABEL_276;
  }
  v215 = v214;
  if ( !strcmp(v214, "non_burst_sync_pulse") )
  {
LABEL_276:
    v217 = 0;
    goto LABEL_277;
  }
  if ( !strcmp(v215, "non_burst_sync_event") )
  {
    v217 = 1;
  }
  else
  {
    if ( strcmp(v215, "burst_mode") )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Unrecognized traffic mode-%s\n", v185, v215);
      goto LABEL_274;
    }
    v217 = 2;
  }
LABEL_277:
  v218 = v12[231];
  v219 = v12[227];
  *((_DWORD *)v12 + 331) = v217;
  if ( *((_DWORD *)v218 - 1) != 309187163 )
    __break(0x8229u);
  v220 = ((__int64 (__fastcall *)(const char *, const char *, int *, long double))v218)(
           v219,
           "qcom,mdss-dsi-virtual-channel-id",
           &v392,
           v216);
  if ( v220 )
  {
    v62 = v220;
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Fallback to default vc id\n", v185);
    *((_DWORD *)v12 + 332) = 0;
    goto LABEL_281;
  }
  *((_DWORD *)v12 + 332) = v392;
LABEL_283:
  if ( ((v173 | v179) & 1) != 0 )
  {
    v221 = v12[231];
    v222 = v12[227];
    v223 = *v12;
    v392 = 0;
    if ( *((_DWORD *)v221 - 1) != 309187163 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v221)(
           v222,
           "qcom,mdss-dsi-wr-mem-start",
           &v392,
           v182) )
    {
      *(double *)&v224 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Fallback to default wr-mem-start\n", v223);
      v225 = 44;
    }
    else
    {
      v225 = v392;
    }
    *((_DWORD *)v12 + 334) = v225;
    v226 = v12[231];
    v227 = v12[227];
    v392 = 0;
    if ( *((_DWORD *)v226 - 1) != 309187163 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v226)(
           v227,
           "qcom,mdss-dsi-wr-mem-continue",
           &v392,
           v224) )
    {
      *(double *)&v228 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Fallback to default wr-mem-continue\n", v223);
      v229 = 60;
    }
    else
    {
      v229 = v392;
    }
    *((_DWORD *)v12 + 335) = v229;
    v230 = v12[231];
    v231 = v12[227];
    *((_DWORD *)v12 + 333) = 0;
    v392 = 0;
    if ( *((_DWORD *)v230 - 1) != 309187163 )
      __break(0x8228u);
    v62 = ((__int64 (__fastcall *)(const char *, const char *, int *, long double))v230)(
            v231,
            "qcom,mdss-dsi-te-dcs-command",
            &v392,
            v228);
    if ( v62 )
    {
      *(double *)&v232 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] fallback to default te-dcs-cmd\n", v223);
      v233 = 1;
      goto LABEL_298;
    }
    v233 = v392;
    if ( (unsigned int)v392 >= 2 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] Unrecognized value for mdss-dsi-te-dcs-command\n",
        v223);
      v62 = -22;
      goto LABEL_309;
    }
LABEL_298:
    v234 = v12[233];
    v235 = v12[227];
    *((_BYTE *)v12 + 1344) = v233;
    if ( *((_DWORD *)v234 - 1) != -834495637 )
      __break(0x8229u);
    v236 = ((__int64 (__fastcall *)(const char *, const char *, long double))v234)(
             v235,
             "qcom,mdss-dsi-mdp-idle-ctrl-en",
             v232);
    *((_BYTE *)v12 + 1345) = v236 & 1;
    if ( (v236 & 1) != 0 )
    {
      v237 = v12[231];
      v238 = v12[227];
      v392 = 0;
      if ( *((_DWORD *)v237 - 1) != 309187163 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(const char *, const char *, int *))v237)(
             v238,
             "qcom,mdss-dsi-mdp-idle-ctrl-len",
             &v392) )
      {
        *(double *)&v182 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] mdp idle ctrl len is not defined\n", v223);
        *((_BYTE *)v12 + 1345) = 0;
        *((_DWORD *)v12 + 337) = 0;
      }
      else
      {
        *((_DWORD *)v12 + 337) = v392;
      }
    }
    else if ( v62 )
    {
LABEL_309:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] Failed to parse cmd host config, rc=%d\n",
        *v12,
        v62);
      goto LABEL_310;
    }
  }
  v239 = v12[233];
  v240 = v12[227];
  if ( *((_DWORD *)v239 - 1) != -834495637 )
    __break(0x8228u);
  v241 = ((__int64 (__fastcall *)(const char *, const char *, long double))v239)(
           v240,
           "qcom,poms-align-panel-vsync",
           v182)
       & 1;
  v242 = v12[233];
  v243 = v12[227];
  *((_DWORD *)v12 + 338) = v175;
  *((_BYTE *)v12 + 1357) = v241;
  *((_BYTE *)v12 + 1356) = v179;
  if ( *((_DWORD *)v242 - 1) != -834495637 )
    __break(0x8229u);
  v244 = ((__int64 (__fastcall *)(const char *, const char *))v242)(v243, "qcom,panel-ack-disabled") & 1;
  v245 = v12[233];
  v246 = v12[227];
  v247 = *v12;
  *((_BYTE *)v12 + 1016) = v244;
  if ( *((_DWORD *)v245 - 1) != -834495637 )
    __break(0x8229u);
  if ( (((__int64 (__fastcall *)(const char *, const char *))v245)(v246, "qcom,mdss-dsi-pan-enable-dynamic-fps") & 1) == 0 )
  {
    *(double *)&v252 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] DFPS is not supported\n", v247);
    *((_BYTE *)v12 + 1388) = 0;
    goto LABEL_346;
  }
  v248 = v12[229];
  v249 = v12[227];
  if ( *((_DWORD *)v248 - 1) != -1612502898 )
    __break(0x8228u);
  v250 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v248)(
                         v249,
                         "qcom,mdss-dsi-pan-fps-update",
                         0);
  if ( !v250 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] dfps type not defined\n", v247);
    goto LABEL_344;
  }
  v251 = v250;
  if ( !strcmp(v250, "dfps_suspend_resume_mode") )
  {
    v253 = 1;
  }
  else if ( !strcmp(v251, "dfps_immediate_clk_mode") )
  {
    v253 = 2;
  }
  else if ( !strcmp(v251, "dfps_immediate_porch_mode_hfp") )
  {
    v253 = 3;
  }
  else
  {
    if ( strcmp(v251, "dfps_immediate_porch_mode_vfp") )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] dfps type is not recognized\n", v247);
      goto LABEL_344;
    }
    v253 = 4;
  }
  v254 = v12[241];
  v255 = v12[227];
  *((_DWORD *)v12 + 340) = v253;
  if ( *((_DWORD *)v254 - 1) != 1473856103 )
    __break(0x8229u);
  v256 = ((__int64 (__fastcall *)(const char *, const char *))v254)(v255, "qcom,dsi-supported-dfps-list");
  *((_DWORD *)v12 + 346) = v256;
  if ( !v256 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] dfps refresh list not present\n", v247);
LABEL_344:
    v260 = -22;
    goto LABEL_345;
  }
  v257 = _kmalloc_noprof(4LL * *((unsigned int *)v12 + 346), 3520);
  v12[172] = (const char *)v257;
  if ( !v257 )
  {
    v260 = -12;
LABEL_345:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to parse dfps configuration, rc=%d\n", v260);
    goto LABEL_346;
  }
  v258 = v12[234];
  v259 = v12[227];
  if ( *((_DWORD *)v258 - 1) != 905330014 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *))v258)(v259, "qcom,dsi-supported-dfps-list") )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] dfps refresh rate list parse failed\n", v247);
    goto LABEL_344;
  }
  v303 = v12[172];
  v304 = *((unsigned int *)v12 + 346);
  *((_BYTE *)v12 + 1388) = 1;
  v305 = *(_DWORD *)v303;
  *((_DWORD *)v12 + 342) = *(_DWORD *)v303;
  *((_DWORD *)v12 + 341) = v305;
  if ( (unsigned int)v304 >= 2 )
  {
    v306 = v304 - 1;
    v307 = (unsigned int *)(v303 + 4);
    v308 = v305;
    do
    {
      v310 = *v307++;
      v309 = v310;
      if ( v310 < v308 )
      {
        *((_DWORD *)v12 + 341) = v309;
      }
      else
      {
        if ( v309 > v305 )
        {
          v305 = v309;
          *((_DWORD *)v12 + 342) = v309;
        }
        v309 = v308;
      }
      --v306;
      v308 = v309;
    }
    while ( v306 );
  }
LABEL_346:
  v261 = v12[233];
  v262 = v12[227];
  v263 = *v12;
  v392 = 0;
  if ( *((_DWORD *)v261 - 1) != -834495637 )
    __break(0x8228u);
  v264 = ((__int64 (__fastcall *)(const char *, const char *, long double))v261)(
           v262,
           "qcom,hwfence_sw_override_always",
           v252);
  v265 = v12[233];
  v266 = v264 & 1;
  v267 = v12[227];
  *((_BYTE *)v12 + 1996) = v266;
  if ( *((_DWORD *)v265 - 1) != -834495637 )
    __break(0x8228u);
  v268 = ((__int64 (__fastcall *)(const char *, const char *))v265)(v267, "qcom,qsync-enable");
  *((_BYTE *)v12 + 1976) = v268 & 1;
  if ( (v268 & 1) == 0 )
  {
    *(double *)&v280 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: qsync feature not enabled\n");
    goto LABEL_381;
  }
  v269 = v12[233];
  v270 = v12[227];
  if ( *((_DWORD *)v269 - 1) != -834495637 )
    __break(0x8228u);
  v271 = ((__int64 (__fastcall *)(const char *, const char *))v269)(v270, "qcom,video-mrr-enable");
  v272 = v12[231];
  v273 = v271 & 1;
  v274 = v12[227];
  *((_BYTE *)v12 + 2046) = v273;
  if ( *((_DWORD *)v272 - 1) != 309187163 )
    __break(0x8228u);
  v275 = ((__int64 (__fastcall *)(const char *, const char *, int *))v272)(
           v274,
           "qcom,mdss-dsi-qsync-min-refresh-rate",
           &v392);
  if ( v275 )
    *(double *)&v276 = _drm_dev_dbg(
                         0,
                         0,
                         0,
                         "[msm-dsi-debug]: [%s] qsync min fps not defined dt%d rc:%d\n",
                         *v12,
                         a2 == nullptr,
                         v275);
  v277 = v12[241];
  v278 = v12[227];
  *((_DWORD *)v12 + 495) = v392;
  if ( *((_DWORD *)v277 - 1) != 1473856103 )
    __break(0x8229u);
  v279 = ((__int64 (__fastcall *)(const char *, const char *, long double))v277)(
           v278,
           "qcom,dsi-supported-qsync-min-fps-list",
           v276);
  *((_DWORD *)v12 + 498) = v279;
  if ( v279 <= 0 )
  {
    *((_DWORD *)v12 + 498) = 0;
    goto LABEL_364;
  }
  if ( *((_DWORD *)v12 + 495) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Both qsync nodes are defined\n", v263);
    goto LABEL_378;
  }
  if ( *((_DWORD *)v12 + 346) != v279 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Qsync min fps list mismatch with dfps\n", v263);
LABEL_378:
    v275 = -22;
    goto LABEL_379;
  }
  v281 = *((unsigned int *)v12 + 498);
  if ( (v281 & 0x80000000) != 0 )
  {
    v12[248] = nullptr;
    v275 = -12;
    goto LABEL_379;
  }
  v282 = _kmalloc_noprof(4 * v281, 3520);
  v12[248] = (const char *)v282;
  if ( !v282 )
  {
    v275 = -12;
LABEL_379:
    *((_DWORD *)v12 + 495) = 0;
    *((_DWORD *)v12 + 498) = 0;
    goto LABEL_380;
  }
  v283 = v12[234];
  v284 = v12[227];
  v285 = *((int *)v12 + 498);
  if ( *((_DWORD *)v283 - 1) != 905330014 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, __int64, __int64))v283)(
         v284,
         "qcom,dsi-supported-qsync-min-fps-list",
         v282,
         v285) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Qsync min fps list parse failed\n", v263);
    goto LABEL_378;
  }
  v311 = v12[248];
  v312 = *((unsigned int *)v12 + 498);
  v313 = *(_DWORD *)v311;
  *((_DWORD *)v12 + 495) = *(_DWORD *)v311;
  if ( (unsigned int)v312 >= 2 )
  {
    v314 = v312 - 1;
    v315 = (unsigned int *)(v311 + 4);
    do
    {
      v317 = *v315++;
      v316 = v317;
      if ( v317 < v313 )
      {
        v313 = v316;
        *((_DWORD *)v12 + 495) = v316;
      }
      --v314;
    }
    while ( v314 );
  }
  v275 = 0;
LABEL_364:
  if ( *((_BYTE *)v12 + 1388) == 1 && *((_DWORD *)v12 + 340) != 4 )
  {
    *((_BYTE *)v12 + 1976) = 0;
    *((_DWORD *)v12 + 495) = 0;
  }
  if ( (v275 & 0x80000000) != 0 )
    goto LABEL_379;
  if ( v275 )
LABEL_380:
    *(double *)&v280 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to parse qsync features, rc=%d\n", v275);
LABEL_381:
  v286 = v12[231];
  v287 = v12[227];
  v392 = 0;
  if ( *((_DWORD *)v286 - 1) != 309187163 )
    __break(0x8228u);
  v288 = ((__int64 (__fastcall *)(const char *, const char *, int *, long double))v286)(
           v287,
           "qcom,dsi-qsync-avr-step-fps",
           &v392,
           v280);
  if ( v288 )
    *(double *)&v289 = _drm_dev_dbg(
                         0,
                         0,
                         0,
                         "[msm-dsi-debug]: [%s] avr step fps not defined dt%d rc:%d\n",
                         *v12,
                         a2 == nullptr,
                         v288);
  v290 = v12[241];
  v291 = v12[227];
  if ( v288 )
    v292 = 0;
  else
    v292 = v392;
  *((_DWORD *)v12 + 500) = v292;
  if ( *((_DWORD *)v290 - 1) != 1473856103 )
    __break(0x8229u);
  v293 = ((__int64 (__fastcall *)(const char *, const char *, long double))v290)(
           v291,
           "qcom,dsi-qsync-avr-step-list",
           v289);
  v392 = v293;
  if ( v293 <= 0 )
  {
    *(double *)&v296 = _drm_dev_dbg(
                         0,
                         0,
                         0,
                         "[msm-dsi-debug]: [%s] optional avr step list not defined, val:%d\n",
                         *v12,
                         v293);
    goto LABEL_422;
  }
  if ( v293 != 1 )
  {
    v294 = *((_DWORD *)v12 + 346);
    if ( v293 != v294 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] avr step list size %d not same as dfps list %d\n",
        *v12,
        v293,
        v294);
      v295 = -22;
LABEL_421:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to parse AVR features, rc=%d\n", v295);
      goto LABEL_422;
    }
  }
  if ( *((_DWORD *)v12 + 500) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] both modes of avr-steps are defined\n", *v12);
    v295 = -22;
    goto LABEL_421;
  }
  if ( v392 < 0 )
  {
    v12[251] = nullptr;
    goto LABEL_420;
  }
  v297 = _kmalloc_noprof(4LL * (unsigned int)v392, 3520);
  v12[251] = (const char *)v297;
  if ( !v297 )
  {
LABEL_420:
    v295 = -12;
    goto LABEL_421;
  }
  v298 = v12[234];
  v299 = v12[227];
  v300 = v392;
  if ( *((_DWORD *)v298 - 1) != 905330014 )
    __break(0x8228u);
  v301 = ((__int64 (__fastcall *)(const char *, const char *, __int64, __int64))v298)(
           v299,
           "qcom,dsi-qsync-avr-step-list",
           v297,
           v300);
  if ( v301 )
  {
    v302 = v301;
    kfree(v12[251]);
    v295 = v302;
    goto LABEL_421;
  }
  *((_DWORD *)v12 + 504) = v392;
LABEL_422:
  v318 = v12[233];
  v319 = v12[227];
  if ( *((_DWORD *)v318 - 1) != -834495637 )
    __break(0x8228u);
  v320 = ((__int64 (__fastcall *)(const char *, const char *, long double))v318)(v319, "qcom,mdss-esync", v296);
  v392 = v320 & 1;
  *((_BYTE *)v12 + 2024) = v320 & 1;
  if ( (v320 & 1) != 0 )
  {
    v321 = v12[231];
    v322 = v12[227];
    if ( *((_DWORD *)v321 - 1) != 309187163 )
      __break(0x8228u);
    if ( ((unsigned int (__fastcall *)(const char *, const char *, int *))v321)(
           v322,
           "qcom,mdss-esync-milli-skew",
           &v392) )
    {
      *(double *)&v323 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] esync skew fallback on default\n", *v12);
      v324 = 0;
      v392 = 0;
    }
    else
    {
      v324 = v392;
    }
    v326 = v12[231];
    v327 = v12[227];
    *((_DWORD *)v12 + 507) = v324;
    if ( *((_DWORD *)v326 - 1) != 309187163 )
      __break(0x8229u);
    v328 = ((__int64 (__fastcall *)(const char *, const char *, int *, long double))v326)(
             v327,
             "qcom,mdss-esync-hsync-milli-pulse-width",
             &v392,
             v323);
    if ( v328 )
    {
      v329 = v328;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] esync enabled but hsync pulse width not defined\n",
        *v12);
      goto LABEL_435;
    }
    v330 = v12[231];
    v331 = v12[227];
    *((_DWORD *)v12 + 508) = v392;
    if ( *((_DWORD *)v330 - 1) != 309187163 )
      __break(0x8229u);
    if ( ((unsigned int (__fastcall *)(const char *, const char *, int *))v330)(
           v331,
           "qcom,mdss-esync-emsync-fps",
           &v392) )
    {
      *(double *)&v325 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] esync EM pulse not enabled\n", *v12);
      *((_DWORD *)v12 + 510) = 0;
    }
    else
    {
      v353 = v12[231];
      v354 = v12[227];
      *((_DWORD *)v12 + 510) = v392;
      if ( *((_DWORD *)v353 - 1) != 309187163 )
        __break(0x8229u);
      v355 = ((__int64 (__fastcall *)(const char *, const char *, int *))v353)(
               v354,
               "qcom,mdss-esync-emsync-milli-pulse-width",
               &v392);
      if ( v355 )
      {
        v329 = v355;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] esync EM pulse enabled but pulse width not defined\n",
          *v12);
LABEL_435:
        *((_BYTE *)v12 + 2024) = 0;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to parse esync features, rc=%d\n", v329);
      }
      else
      {
        *((_DWORD *)v12 + 509) = v392;
      }
    }
  }
  else
  {
    *(double *)&v325 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] esync not enabled\n", *v12);
  }
  v332 = v12[233];
  v333 = v12[227];
  if ( *((_DWORD *)v332 - 1) != -834495637 )
    __break(0x8228u);
  v334 = ((__int64 (__fastcall *)(const char *, const char *, long double))v332)(v333, "qcom,vrr-enable", v325);
  *((_BYTE *)v12 + 2044) = v334 & 1;
  if ( (v334 & 1) != 0 )
  {
    v335 = v12[233];
    v336 = v12[227];
    if ( *((_DWORD *)v335 - 1) != -834495637 )
      __break(0x8228u);
    v337 = ((__int64 (__fastcall *)(const char *, const char *))v335)(v336, "qcom,arp-enable");
    v338 = v12[233];
    v339 = v337 & 1;
    v340 = v12[227];
    *((_BYTE *)v12 + 2047) = v339;
    if ( *((_DWORD *)v338 - 1) != -834495637 )
      __break(0x8228u);
    v341 = ((__int64 (__fastcall *)(const char *, const char *))v338)(v340, "qcom,video-psr-enable");
    v343 = *((_BYTE *)v12 + 2047);
    *((_BYTE *)v12 + 2045) = v341 & 1;
    if ( (v343 & 1) != 0 || (v341 & 1) != 0 )
    {
      if ( *((_BYTE *)v12 + 1976) == 1 && *((_DWORD *)v12 + 495) )
      {
        if ( *((_BYTE *)v12 + 1388) != 1
          || (*((_BYTE *)v12 + 2046) & 1) != 0
          || (drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: disabling dfps as it can't be supported with ARP/Video PSR\n"),
              v344 = *((_BYTE *)v12 + 2047),
              *((_BYTE *)v12 + 1388) = 0,
              (v344 & 1) != 0)
          || (*((_BYTE *)v12 + 2045) & 1) != 0 )
        {
          if ( *((_BYTE *)v12 + 1356) == 1 )
          {
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: disabling poms as it can't be supported with ARP/Video PSR\n");
            *((_BYTE *)v12 + 1356) = 0;
          }
        }
      }
      else
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: ARP/Video PSR can't be supported without qsync\n");
        *((_BYTE *)v12 + 2047) = 0;
        *((_BYTE *)v12 + 2045) = 0;
        *(double *)&v342 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to parse VRR features, rc=%d\n", -22);
      }
    }
  }
  else
  {
    *(double *)&v342 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: VRR feature not enabled\n");
  }
  v345 = v12[233];
  v346 = v12[227];
  if ( *((_DWORD *)v345 - 1) != -834495637 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(const char *, const char *, long double))v345)(v346, "qcom,dsi-dyn-clk-enable", v342)
      & 1) != 0 )
  {
    v348 = v12[229];
    v349 = v12[227];
    *((_BYTE *)v12 + 1392) = 1;
    if ( *((_DWORD *)v348 - 1) != -1612502898 )
      __break(0x8229u);
    v350 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v348)(
                           v349,
                           "qcom,dsi-dyn-clk-type",
                           0);
    if ( v350 )
    {
      v351 = v350;
      if ( !strcmp(v350, "constant-fps-adjust-hfp") )
      {
        *((_DWORD *)v12 + 349) = 1;
        *((_BYTE *)v12 + 1400) = 1;
      }
      else
      {
        if ( !strcmp(v351, "constant-fps-adjust-vfp") )
        {
          v352 = 2;
        }
        else if ( !strcmp(v351, "adjust-hfp") )
        {
          v352 = 3;
        }
        else
        {
          if ( strcmp(v351, "adjust-vfp") )
          {
            *((_DWORD *)v12 + 349) = 0;
            *((_BYTE *)v12 + 1400) = 0;
            goto LABEL_481;
          }
          v352 = 4;
        }
        *((_DWORD *)v12 + 349) = v352;
        *((_BYTE *)v12 + 1400) = 1;
      }
LABEL_481:
      *(double *)&v347 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Dynamic clock type is [%s]\n", v351);
    }
    else
    {
      *((_DWORD *)v12 + 349) = 0;
      *((_BYTE *)v12 + 1400) = 0;
    }
  }
  else
  {
    *((_BYTE *)v12 + 1392) = 0;
  }
  v356 = v12[231];
  v357 = v12[227];
  v358 = *v12;
  v392 = 0;
  if ( *((_DWORD *)v356 - 1) != 309187163 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v356)(
         v357,
         "qcom,mdss-pan-physical-width-dimension",
         &v392,
         v347) )
  {
    *(double *)&v359 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Physical panel width is not defined\n", v358);
    v360 = 0;
  }
  else
  {
    v360 = v392;
  }
  v361 = v12[231];
  v362 = v12[227];
  *((_DWORD *)v12 + 351) = v360;
  if ( *((_DWORD *)v361 - 1) != 309187163 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v361)(
         v362,
         "qcom,mdss-pan-physical-height-dimension",
         &v392,
         v359) )
  {
    *(double *)&v363 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] Physical panel height is not defined\n", v358);
    v364 = 0;
  }
  else
  {
    v364 = v392;
  }
  v365 = v12[229];
  v366 = v12[227];
  *((_DWORD *)v12 + 352) = v364;
  if ( *((_DWORD *)v365 - 1) != -1612502898 )
    __break(0x8229u);
  v367 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v365)(
                         v366,
                         "qcom,mdss-dsi-panel-orientation",
                         0,
                         v363);
  if ( v367 )
  {
    v368 = v367;
    if ( !strcmp(v367, "180") )
    {
      v369 = 1;
    }
    else if ( !strcmp(v368, "hflip") )
    {
      v369 = 2;
    }
    else
    {
      if ( strcmp(v368, "vflip") )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] Unrecognized panel rotation-%s\n", v358, v368);
        v62 = -22;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: failed to parse panel physical dimension, rc=%d\n",
          4294967274LL);
        goto LABEL_98;
      }
      v369 = 3;
    }
  }
  else
  {
    v369 = 0;
  }
  v370 = v12[286];
  *((_DWORD *)v12 + 353) = v369;
  if ( *((_DWORD *)v370 - 1) != -1699580201 )
    __break(0x8229u);
  v371 = ((__int64 (__fastcall *)(const char **))v370)(v12);
  if ( v371 )
  {
    v62 = v371;
    v66 = "*ERROR* [msm-dsi-error]: failed to parse panel gpios, rc=%d\n";
    goto LABEL_90;
  }
  v372 = v12[287];
  if ( *((_DWORD *)v372 - 1) != -1699580201 )
    __break(0x8228u);
  v373 = ((__int64 (__fastcall *)(const char **))v372)(v12);
  if ( v373 )
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to parse power config, rc=%d\n", v373);
  v374 = dsi_panel_parse_bl_config(v12);
  if ( v374 )
  {
    v375 = v374;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to parse backlight config, rc=%d\n", v374);
    if ( v375 == -517 )
    {
      v62 = -517;
      goto LABEL_98;
    }
  }
  zte_disp_common_func(v12);
  dsi_panel_parse_misc_features(v12);
  v376 = dsi_panel_parse_hdr_config(v12);
  if ( v376 )
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to parse hdr config, rc=%d\n", v376);
  mode_count = dsi_panel_get_mode_count(v12);
  if ( mode_count )
  {
    v62 = mode_count;
    v66 = "*ERROR* [msm-dsi-error]: failed to get mode count, rc=%d\n";
    goto LABEL_90;
  }
  v378 = dsi_panel_parse_dms_info(v12);
  if ( v378 )
    *(double *)&v379 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to get dms info, rc=%d\n", v378);
  v380 = dsi_panel_parse_esd_config(v12, v379);
  if ( v380 )
    *(double *)&v381 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to parse esd config, rc=%d\n", v380);
  v382 = dsi_panel_parse_rgb_led(v12, a2, v381);
  if ( v382 )
    *(double *)&v383 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to get rgb led info, rc=%d\n", v382);
  v384 = dsi_panel_vreg_get(v12, v383);
  if ( v384 )
  {
    v62 = v384;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to get panel regulators, rc=%d\n", *v12, v384);
    goto LABEL_98;
  }
  if ( *((_BYTE *)v12 + 2232) == 1 )
  {
    v385 = dsi_panel_post_vreg_get(v12);
    if ( v385 )
    {
      v62 = v385;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to get panel post regulators, rc=%d\n",
        *v12,
        v385);
      goto LABEL_98;
    }
  }
  *((_DWORD *)v12 + 555) = 5;
  drm_panel_init(v12 + 136, v12 + 4, 0, 16);
  v12[97] = a2;
  drm_panel_add(v12 + 136);
  _mutex_init(v12 + 130, "&panel->panel_lock", &dsi_panel_get___key);
LABEL_545:
  _ReadStatusReg(SP_EL0);
  return v12;
}
