__int64 __fastcall sde_kms_hw_init(__int64 a1)
{
  void *v1; // x0
  __int64 v2; // x22
  __int64 v4; // x8
  unsigned __int64 v5; // x23
  __int64 v7; // x27
  __int64 v8; // x20
  __int64 v9; // x24
  __int64 v10; // x25
  __int64 phys_addr; // x0
  unsigned __int64 v12; // x0
  __int64 v13; // x24
  __int64 v14; // x25
  __int64 v15; // x0
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x0
  char v18; // w8
  __int64 v19; // x23
  __int64 v20; // x0
  __int64 v21; // x25
  __int64 v22; // x8
  __int64 v23; // x0
  unsigned __int64 v24; // x0
  __int64 v25; // x24
  __int64 v26; // x25
  __int64 v27; // x0
  unsigned __int64 v28; // x0
  char v29; // w8
  __int64 v30; // x24
  __int64 v31; // x25
  __int64 v32; // x0
  int v33; // w0
  __int64 node_opts_by_path; // x0
  void *v35; // x0
  const char *v36; // x1
  __int64 v37; // x21
  int num_of_displays; // w25
  int v39; // w0
  int v40; // w8
  __int64 v41; // x26
  int v42; // w9
  int v43; // w8
  __int64 v44; // x5
  int v45; // w8
  char v46; // w10
  int v47; // w9
  int v48; // w6
  int v49; // w8
  __int64 v50; // x0
  unsigned __int64 v51; // x24
  int v52; // w27
  __int64 *v53; // x28
  __int64 v54; // x0
  __int64 v55; // x5
  __int64 v56; // x9
  int v57; // w8
  int v58; // w6
  int v59; // w27
  __int64 v60; // x24
  int v61; // w8
  int v62; // w9
  __int64 v63; // x10
  int v64; // w11
  unsigned __int64 v65; // x9
  _DWORD *v66; // x8
  const char *v67; // x1
  _DWORD *v68; // x0
  int v69; // w0
  int v70; // w21
  char v71; // w8
  __int64 v72; // x8
  __int64 v73; // x24
  _QWORD *v74; // x21
  void *v75; // x0
  void *v76; // x0
  __int64 (__fastcall *v77)(_QWORD); // x8
  int v78; // w0
  unsigned __int64 v79; // x28
  unsigned __int64 v80; // x0
  int v81; // w0
  __int64 v82; // x1
  __int64 v83; // x1
  __int64 resource_byname; // x0
  __int64 v85; // x1
  __int64 v86; // x8
  __int64 v87; // x1
  __int64 v88; // x8
  unsigned int (__fastcall *v89)(__int64, __int64, __int64, __int64, __int64); // x9
  __int64 v90; // x3
  void (__fastcall *v91)(_QWORD); // x8
  int v92; // w0
  int v93; // w0
  unsigned __int64 v94; // x0
  int v95; // w21
  unsigned int v96; // w0
  unsigned __int64 mdp; // x0
  unsigned int *v98; // x3
  __int64 v99; // x24
  __int64 v100; // x21
  unsigned __int64 v101; // x8
  _BOOL4 v102; // w9
  unsigned __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x2
  unsigned __int64 v106; // x0
  int v107; // w0
  __int64 v108; // x1
  __int64 v109; // x0
  unsigned __int64 v110; // x0
  __int64 v111; // x24
  int v112; // w0
  __int64 v113; // x0
  int v114; // w0
  __int64 v115; // x8
  __int64 v116; // x1
  __int64 v117; // x0
  int v118; // w0
  __int64 v119; // x8
  __int64 v120; // x1
  __int64 v121; // x0
  int v122; // w0
  __int64 v123; // x8
  _QWORD *v124; // x1
  int displays; // w0
  __int64 v126; // x8
  __int64 v127; // x8
  __int64 v128; // x8
  __int64 v129; // x8
  __int64 v130; // x0
  __int64 v131; // x9
  int v132; // w9
  void *v133; // x0
  __int64 v134; // x28
  __int64 v135; // x0
  unsigned __int64 v136; // x0
  __int64 v137; // x25
  unsigned __int64 v138; // x0
  __int64 v139; // x8
  __int64 v140; // x8
  _QWORD *v141; // x21
  void *v142; // x0
  void *v143; // x0
  void *v144; // x0
  __int64 v145; // x28
  __int64 v146; // x25
  unsigned __int64 v147; // x0
  __int64 v148; // x27
  __int64 v149; // x2
  __int64 drm_panel; // x0
  unsigned __int64 v151; // x0
  unsigned __int64 v152; // x25
  __int64 v153; // x8
  __int64 v154; // x8
  __int64 v155; // x25
  unsigned __int64 v156; // x0
  __int64 v157; // x28
  unsigned __int64 v158; // x0
  __int64 v159; // x8
  __int64 v160; // x8
  unsigned int *v161; // x8
  unsigned int v162; // w9
  unsigned int v163; // w10
  unsigned int v164; // w8
  bool v165; // cf
  int v166; // w10
  int v167; // w21
  unsigned int v168; // w10
  __int64 v169; // x28
  void *v170; // x0
  __int64 v171; // x8
  __int64 v172; // x27
  unsigned __int64 v173; // x0
  __int64 v174; // x25
  unsigned __int64 v175; // x0
  __int64 v176; // x9
  unsigned int v177; // w8
  __int64 v178; // x9
  unsigned __int64 v179; // x0
  __int64 v180; // x25
  __int64 v181; // x8
  __int64 v182; // x0
  unsigned __int64 v183; // x0
  __int64 v184; // x25
  __int64 v185; // x8
  __int64 v186; // x13
  int v187; // w8
  int v188; // w9
  __int64 v189; // x11
  unsigned __int8 *v190; // x10
  int v191; // t1
  unsigned __int64 v192; // x21
  __int64 v193; // x28
  signed int v194; // w27
  unsigned __int64 v195; // x25
  unsigned int *v196; // x24
  unsigned __int64 v197; // x8
  __int64 v198; // x1
  unsigned __int64 v199; // x0
  __int64 v200; // x8
  unsigned int v201; // w8
  __int64 v202; // x21
  __int64 v203; // x1
  unsigned __int64 v204; // x0
  __int64 v205; // x8
  int v206; // w8
  __int64 v207; // x24
  __int64 v208; // x21
  unsigned __int64 v209; // x0
  __int64 v210; // x8
  unsigned __int64 v211; // x8
  __int64 v212; // x12
  unsigned __int64 v213; // x8
  __int64 v214; // x12
  void *v215; // x0
  unsigned __int64 v216; // x21
  void *v217; // x0
  __int64 v218; // x8
  _DWORD *v219; // x21
  __int64 v220; // x24
  void (*v221)(void); // x8
  int v222; // w8
  __int64 v223; // x24
  void (*v224)(void); // x8
  int v225; // w8
  __int64 v226; // x24
  void (*v227)(void); // x8
  int v228; // w8
  __int64 v229; // x24
  void (*v230)(void); // x8
  __int64 v231; // x0
  _BYTE *v232; // x8
  char v233; // w8
  __int64 v234; // x9
  unsigned int irq; // w23
  __int64 v236; // x10
  unsigned int *v237; // x8
  __int64 v238; // x9
  unsigned int *v239; // x9
  __int64 v240; // x8
  __int64 v241; // x0
  __int64 v242; // x9
  __int64 v243; // x8
  __int64 v244; // x0
  __int64 v245; // x25
  unsigned __int64 StatusReg; // x21
  __int64 v247; // x24
  __int64 v248; // x8
  __int64 v249; // [xsp+0h] [xbp-350h]
  unsigned int v250; // [xsp+1Ch] [xbp-334h]
  int v251; // [xsp+1Ch] [xbp-334h]
  unsigned int v252; // [xsp+20h] [xbp-330h]
  unsigned __int64 v253; // [xsp+20h] [xbp-330h]
  __int64 v254; // [xsp+28h] [xbp-328h]
  unsigned int **v255; // [xsp+30h] [xbp-320h]
  __int64 v256; // [xsp+38h] [xbp-318h]
  __int64 node_by_name; // [xsp+40h] [xbp-310h]
  unsigned int v258; // [xsp+40h] [xbp-310h]
  __int64 v259; // [xsp+48h] [xbp-308h] BYREF
  __int64 v260; // [xsp+50h] [xbp-300h]
  __int64 v261; // [xsp+58h] [xbp-2F8h]
  __int64 v262; // [xsp+60h] [xbp-2F0h]
  char s[8]; // [xsp+68h] [xbp-2E8h] BYREF
  __int64 v264; // [xsp+70h] [xbp-2E0h]
  __int64 v265; // [xsp+78h] [xbp-2D8h]
  __int64 v266; // [xsp+80h] [xbp-2D0h]
  __int64 v267; // [xsp+88h] [xbp-2C8h]
  __int64 v268; // [xsp+90h] [xbp-2C0h]
  __int64 v269; // [xsp+98h] [xbp-2B8h]
  __int64 v270; // [xsp+A0h] [xbp-2B0h]
  __int64 v271; // [xsp+A8h] [xbp-2A8h]
  __int64 v272; // [xsp+B0h] [xbp-2A0h]
  __int64 v273; // [xsp+B8h] [xbp-298h]
  __int64 v274; // [xsp+C0h] [xbp-290h]
  __int64 v275; // [xsp+C8h] [xbp-288h]
  __int64 v276; // [xsp+D0h] [xbp-280h]
  __int64 v277; // [xsp+D8h] [xbp-278h]
  __int64 v278; // [xsp+E0h] [xbp-270h]
  __int64 v279; // [xsp+E8h] [xbp-268h] BYREF
  __int64 v280; // [xsp+F0h] [xbp-260h]
  __int64 v281; // [xsp+F8h] [xbp-258h]
  __int64 v282; // [xsp+100h] [xbp-250h]
  __int64 v283; // [xsp+108h] [xbp-248h]
  __int64 v284; // [xsp+110h] [xbp-240h]
  __int64 v285; // [xsp+118h] [xbp-238h]
  __int64 v286; // [xsp+120h] [xbp-230h]
  __int64 v287; // [xsp+128h] [xbp-228h]
  __int64 v288; // [xsp+130h] [xbp-220h]
  __int64 v289; // [xsp+138h] [xbp-218h]
  __int64 v290; // [xsp+140h] [xbp-210h]
  __int64 v291; // [xsp+148h] [xbp-208h]
  __int64 v292; // [xsp+150h] [xbp-200h]
  __int64 v293; // [xsp+158h] [xbp-1F8h]
  __int64 v294; // [xsp+160h] [xbp-1F0h]
  __int64 v295; // [xsp+168h] [xbp-1E8h] BYREF
  __int64 v296; // [xsp+170h] [xbp-1E0h]
  __int64 v297; // [xsp+178h] [xbp-1D8h]
  __int64 v298; // [xsp+180h] [xbp-1D0h]
  __int64 v299; // [xsp+188h] [xbp-1C8h]
  __int64 v300; // [xsp+190h] [xbp-1C0h]
  __int64 v301; // [xsp+198h] [xbp-1B8h]
  __int64 v302; // [xsp+1A0h] [xbp-1B0h]
  __int64 v303; // [xsp+1A8h] [xbp-1A8h]
  __int64 v304; // [xsp+1B0h] [xbp-1A0h]
  __int64 v305; // [xsp+1B8h] [xbp-198h]
  __int64 v306; // [xsp+1C0h] [xbp-190h]
  __int64 v307; // [xsp+1C8h] [xbp-188h]
  __int64 v308; // [xsp+1D0h] [xbp-180h]
  __int64 v309; // [xsp+1D8h] [xbp-178h]
  __int64 v310; // [xsp+1E0h] [xbp-170h]
  __int64 v311; // [xsp+1E8h] [xbp-168h]
  __int64 v312; // [xsp+1F0h] [xbp-160h]
  __int64 v313; // [xsp+1F8h] [xbp-158h]
  __int64 v314; // [xsp+200h] [xbp-150h]
  __int64 v315; // [xsp+208h] [xbp-148h]
  __int64 v316; // [xsp+210h] [xbp-140h]
  __int64 v317; // [xsp+218h] [xbp-138h]
  __int64 v318; // [xsp+220h] [xbp-130h]
  __int64 v319; // [xsp+228h] [xbp-128h]
  __int64 v320; // [xsp+230h] [xbp-120h]
  __int64 v321; // [xsp+238h] [xbp-118h]
  __int64 v322; // [xsp+240h] [xbp-110h]
  __int64 v323; // [xsp+248h] [xbp-108h]
  __int64 v324; // [xsp+250h] [xbp-100h]
  __int64 v325; // [xsp+258h] [xbp-F8h]
  __int64 v326; // [xsp+260h] [xbp-F0h]
  __int64 v327; // [xsp+268h] [xbp-E8h] BYREF
  __int64 v328; // [xsp+270h] [xbp-E0h]
  unsigned int v329; // [xsp+278h] [xbp-D8h]
  char v330[8]; // [xsp+280h] [xbp-D0h] BYREF
  __int64 v331; // [xsp+288h] [xbp-C8h]
  __int64 v332; // [xsp+290h] [xbp-C0h]
  __int64 v333; // [xsp+298h] [xbp-B8h]
  __int64 v334; // [xsp+2A0h] [xbp-B0h] BYREF
  __int64 v335; // [xsp+2A8h] [xbp-A8h]
  __int64 v336; // [xsp+2B0h] [xbp-A0h]
  __int64 v337; // [xsp+2B8h] [xbp-98h]
  __int64 v338; // [xsp+2C0h] [xbp-90h]
  __int64 v339; // [xsp+2C8h] [xbp-88h]
  __int64 v340; // [xsp+2D0h] [xbp-80h]
  __int64 v341; // [xsp+2D8h] [xbp-78h]
  __int64 v342; // [xsp+2E0h] [xbp-70h]
  __int64 v343; // [xsp+2E8h] [xbp-68h]
  __int64 v344; // [xsp+2F0h] [xbp-60h]
  __int64 v345; // [xsp+2F8h] [xbp-58h]
  __int64 v346; // [xsp+300h] [xbp-50h]
  __int64 v347; // [xsp+308h] [xbp-48h]
  __int64 v348; // [xsp+310h] [xbp-40h]
  __int64 v349; // [xsp+318h] [xbp-38h]
  __int64 v350; // [xsp+320h] [xbp-30h]
  __int64 v351; // [xsp+328h] [xbp-28h]
  __int64 v352; // [xsp+330h] [xbp-20h]
  __int64 v353; // [xsp+338h] [xbp-18h]
  __int64 v354; // [xsp+340h] [xbp-10h]

  v354 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v261 = 0;
  v262 = 0;
  v259 = 0;
  v260 = 0;
  if ( !a1 )
  {
    v1 = &unk_234896;
LABEL_6:
    printk(v1, "sde_kms_hw_init");
    LODWORD(v5) = -22;
    goto LABEL_7;
  }
  v2 = *(_QWORD *)(a1 + 136);
  if ( !v2 || (v4 = *(_QWORD *)(v2 + 8)) == 0 )
  {
    v1 = &unk_231B33;
    goto LABEL_6;
  }
  v7 = *(_QWORD *)(v2 + 56);
  if ( !v7 )
  {
    v1 = &unk_25B071;
    goto LABEL_6;
  }
  v8 = v4 - 16;
  v5 = msm_ioremap(v4 - 16, "mdp_phys", "mdp_phys");
  *(_QWORD *)(a1 + 1752) = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_26CD39, "_sde_kms_hw_init_ioremap");
    *(_QWORD *)(a1 + 1752) = 0;
    goto LABEL_36;
  }
  printk(&unk_219B9E, v5);
  v9 = msm_iomap_size(v8, "mdp_phys");
  v10 = *(_QWORD *)(a1 + 1752);
  *(_QWORD *)(a1 + 1800) = v9;
  phys_addr = msm_get_phys_addr(v8, "mdp_phys");
  if ( (unsigned int)sde_dbg_reg_register_base(&unk_288730, v10, v9, phys_addr, 1) )
    printk(&unk_2161A8, "_sde_kms_hw_init_ioremap");
  v12 = msm_ioremap(v8, "vbif_phys", "vbif_phys");
  *(_QWORD *)(a1 + 1760) = v12;
  if ( v12 >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v5) = v12;
    printk(&unk_23BE46, "_sde_kms_hw_init_ioremap");
    *(_QWORD *)(a1 + 1760) = 0;
    goto LABEL_36;
  }
  v13 = msm_iomap_size(v8, "vbif_phys");
  v14 = *(_QWORD *)(a1 + 1760);
  *(_QWORD *)(a1 + 1808) = v13;
  v15 = msm_get_phys_addr(v8, "vbif_phys");
  LODWORD(v5) = sde_dbg_reg_register_base("vbif_rt", v14, v13, v15, 16);
  if ( (_DWORD)v5 )
    printk(&unk_22E519, "_sde_kms_hw_init_ioremap");
  v16 = msm_ioremap(v8, "vbif_nrt_phys", "vbif_nrt_phys");
  *(_QWORD *)(a1 + 1768) = v16;
  if ( v16 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(a1 + 1816) = msm_iomap_size(v8, "vbif_nrt_phys");
  }
  else
  {
    *(_QWORD *)(a1 + 1768) = 0;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "VBIF NRT is not defined");
  }
  v17 = msm_ioremap(v8, "regdma_phys", "regdma_phys");
  *(_QWORD *)(a1 + 1776) = v17;
  if ( v17 < 0xFFFFFFFFFFFFF001LL )
  {
    v19 = msm_get_phys_addr(v8, "mdp_phys");
    *(_QWORD *)(a1 + 1824) = msm_iomap_size(v8, "regdma_phys");
    v20 = msm_get_phys_addr(v8, "regdma_phys");
    v21 = *(_QWORD *)(a1 + 1776);
    v22 = v20 - v19;
    v5 = *(_QWORD *)(a1 + 1824);
    *(_QWORD *)(a1 + 1848) = v22;
    v23 = msm_get_phys_addr(v8, "regdma_phys");
    LODWORD(v5) = sde_dbg_reg_register_base("reg_dma", v21, v5, v23, 8);
    if ( (_DWORD)v5 )
      printk(&unk_2497DD, "_sde_kms_hw_init_ioremap");
  }
  else
  {
    v18 = _drm_debug;
    *(_QWORD *)(a1 + 1776) = 0;
    if ( (v18 & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "REG_DMA is not defined");
  }
  v24 = msm_ioremap(v8, "sid_phys", "sid_phys");
  *(_QWORD *)(a1 + 1784) = v24;
  if ( v24 < 0xFFFFFFFFFFFFF001LL )
  {
    v25 = msm_iomap_size(v8, "sid_phys");
    v26 = *(_QWORD *)(a1 + 1784);
    *(_QWORD *)(a1 + 1832) = v25;
    v27 = msm_get_phys_addr(v8, "sid_phys");
    LODWORD(v5) = sde_dbg_reg_register_base(&unk_2161E3, v26, v25, v27, 4);
    if ( (_DWORD)v5 )
      printk(&unk_24648D, "_sde_kms_hw_init_ioremap");
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "sid register is not defined: %d\n", v5);
    *(_QWORD *)(a1 + 1784) = 0;
  }
  v28 = msm_ioremap(v8, "swfuse_phys", "swfuse_phys");
  *(_QWORD *)(a1 + 1792) = v28;
  if ( v28 < 0xFFFFFFFFFFFFF001LL )
  {
    v30 = msm_iomap_size(v8, "swfuse_phys");
    v31 = *(_QWORD *)(a1 + 1792);
    *(_QWORD *)(a1 + 1840) = v30;
    v32 = msm_get_phys_addr(v8, "swfuse_phys");
    v33 = sde_dbg_reg_register_base("sw_fuse", v31, v30, v32, 64);
    if ( v33 )
    {
      LODWORD(v5) = v33;
      v35 = &unk_2353D4;
      v36 = "_sde_kms_hw_init_ioremap";
      goto LABEL_503;
    }
  }
  else
  {
    v29 = _drm_debug;
    *(_QWORD *)(a1 + 1792) = 0;
    if ( (v29 & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "sw_fuse is not defined");
    if ( (_DWORD)v5 )
      goto LABEL_36;
  }
  v344 = 0;
  v345 = 0;
  v342 = 0;
  v343 = 0;
  v340 = 0;
  v341 = 0;
  v338 = 0;
  v339 = 0;
  v336 = 0;
  v337 = 0;
  v334 = 0;
  v335 = 0;
  v289 = 0;
  v290 = 0;
  v287 = 0;
  v288 = 0;
  v285 = 0;
  v286 = 0;
  v283 = 0;
  v284 = 0;
  v281 = 0;
  v282 = 0;
  v279 = 0;
  v280 = 0;
  if ( of_find_node_with_property(0, "qcom,sde-emulated-env") )
    goto LABEL_113;
  memset((void *)(a1 + 2536), 0, 0x150u);
  node_opts_by_path = of_find_node_opts_by_path("/reserved-memory", 0);
  if ( !node_opts_by_path )
  {
    printk(&unk_265C42, "_sde_kms_get_splash_data");
LABEL_42:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "sde splash data fetch failed: %d\n", -22);
    goto LABEL_113;
  }
  node_by_name = of_find_node_by_name(node_opts_by_path, "splash_region");
  if ( !node_by_name )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "failed to find node %s\n", "splash_region");
    goto LABEL_42;
  }
  v37 = of_find_node_by_name(0, "disp_rdump_region");
  if ( !v37 && (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "failed to find disp ramdump memory reservation\n");
  num_of_displays = dsi_display_get_num_of_displays(v2);
  v39 = of_property_count_elems_of_size(node_by_name, "reg", 8);
  *(_DWORD *)(a1 + 2544) = num_of_displays;
  if ( v39 >= 0 )
    v40 = v39;
  else
    v40 = v39 + 1;
  LODWORD(v41) = v40 >> 1;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "splash mem num_regions:%d\n", v41);
  v256 = v37;
  v249 = v7;
  if ( num_of_displays > (int)v41 )
    printk(&unk_238832, "_sde_kms_get_splash_data");
  if ( num_of_displays >= 1 )
  {
    if ( (unsigned int)of_address_to_resource(node_by_name, 0, &v334) )
    {
LABEL_107:
      v67 = "_sde_kms_get_splash_data";
LABEL_108:
      printk(&unk_253C96, v67);
      v7 = v249;
      goto LABEL_42;
    }
    v255 = (unsigned int **)(a1 + 2552);
    if ( !v37 || (unsigned int)of_address_to_resource(v37, 0, &v279) )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "failed to find ramdump memory\n");
      v43 = 0;
      *(_QWORD *)(a1 + 2576) = 0;
    }
    else
    {
      v42 = v280 - v279;
      *(_QWORD *)(a1 + 2576) = v279;
      v43 = v42 + 1;
    }
    *(_DWORD *)(a1 + 2568) = v43;
    v44 = v334;
    v45 = v335;
    v46 = _drm_debug;
    *(_QWORD *)(a1 + 2728) = v255;
    v47 = *(_DWORD *)(a1 + 2540);
    *(_DWORD *)(a1 + 2584) = 0;
    v48 = v45 - v44 + 1;
    *(_QWORD *)(a1 + 2560) = v44;
    *(_DWORD *)(a1 + 2552) = v48;
    *(_DWORD *)(a1 + 2540) = v47 + 1;
    if ( (v46 & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "splash mem for disp:%d add:%lx size:%x\n", 1, v44, v48);
    if ( num_of_displays != 1 )
    {
      v5 = 0;
      v59 = 2;
      v60 = 2808;
      do
      {
        if ( v5 == 80 )
          goto LABEL_423;
        if ( num_of_displays <= (int)v41 )
        {
          if ( (unsigned int)of_address_to_resource(node_by_name, (unsigned int)(v59 - 1), &v334) )
            goto LABEL_107;
          if ( v37 && !(unsigned int)of_address_to_resource(v37, (unsigned int)(v59 - 1), &v279) )
          {
            v62 = v280 - v279;
            *(_QWORD *)(a1 + v5 + 2616) = v279;
            v61 = v62 + 1;
          }
          else
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "failed to find ramdump memory\n");
            v61 = 0;
            *(_QWORD *)(a1 + v5 + 2616) = 0;
          }
          v63 = v334;
          v64 = v335;
          v65 = a1 + v5;
          *(_DWORD *)(v65 + 2608) = v61;
          *(_DWORD *)(v65 + 2624) = 0;
          v66 = (_DWORD *)(a1 + v5 + 2592);
          *(_QWORD *)(v65 + 2600) = v63;
          *v66 = v64 - v63 + 1;
          *(_QWORD *)(a1 + v60) = v66;
          ++*(_DWORD *)(a1 + 2540);
        }
        else
        {
          if ( v5 == 40 )
            goto LABEL_423;
          *(_QWORD *)(a1 + v60) = v255;
        }
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "splash mem for disp:%d add:%lx size:%x\n",
            v59,
            *(_QWORD *)(*(_QWORD *)(a1 + v60) + 8LL),
            **(_DWORD **)(a1 + v60));
        v5 += 40LL;
        ++v59;
        v60 += 80;
      }
      while ( 40LL * (unsigned int)num_of_displays - 40 != v5 );
    }
  }
  v49 = *(_DWORD *)(a1 + 2544);
  *(_DWORD *)(a1 + 2536) = 0;
  v305 = 0;
  v306 = 0;
  v303 = 0;
  v304 = 0;
  v301 = 0;
  v302 = 0;
  v299 = 0;
  v300 = 0;
  v297 = 0;
  v298 = 0;
  v295 = 0;
  v296 = 0;
  v265 = 0;
  v266 = 0;
  *(_QWORD *)s = 0;
  v264 = 0;
  if ( !v49 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "no splash displays. skipping\n");
    goto LABEL_112;
  }
  v50 = of_find_node_opts_by_path("/reserved-memory", 0);
  if ( !*(_DWORD *)(a1 + 2544) )
    goto LABEL_110;
  v5 = v50;
  v51 = 0;
  v52 = 0;
  v41 = a1 + 2632;
  v53 = (__int64 *)(a1 + 2736);
  do
  {
    if ( v51 == 3 )
      goto LABEL_423;
    snprintf(s, 0x20u, "demura_region_%d", v51);
    *v53 = 0;
    v54 = of_find_node_by_name(v5, s);
    if ( v54 )
    {
      if ( (unsigned int)of_address_to_resource(v54, 0, &v295) )
      {
        v67 = "_sde_kms_get_demura_plane_data";
        goto LABEL_108;
      }
      v55 = v295;
      v56 = v295 | v296;
      v57 = v296 - v295;
      *(_QWORD *)(v41 + 8) = v295;
      if ( v56 )
        v58 = v57 + 1;
      else
        v58 = 0;
      *(_DWORD *)v41 = v58;
      if ( v55 )
      {
        if ( !v58 )
          goto LABEL_74;
        *(_DWORD *)(v41 + 32) = 0;
        ++v52;
        *v53 = v41;
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "demura mem for disp:%d add:%lx size:%u\n", v51 + 1, v55, v58);
      }
      else
      {
        if ( v58 )
        {
LABEL_74:
          printk(&unk_23BE92, "_sde_kms_get_demura_plane_data");
          goto LABEL_75;
        }
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "dummy splash mem for disp %d. Skipping\n", v51 + 1);
      }
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "no Demura node %s! disp count: %d\n", s, *(_DWORD *)(a1 + 2544));
    }
LABEL_75:
    ++v51;
    v41 += 40;
    v53 += 10;
  }
  while ( v51 < *(unsigned int *)(a1 + 2544) );
  if ( v52 )
    goto LABEL_112;
LABEL_110:
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "no demura regions for cont. splash found!\n");
LABEL_112:
  v7 = v249;
LABEL_113:
  v68 = (_DWORD *)sde_hw_catalog_init(v2);
  *(_QWORD *)(a1 + 152) = v68;
  v255 = (unsigned int **)(a1 + 152);
  if ( !v68 || (unsigned __int64)v68 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( v68 )
      LODWORD(v5) = (_DWORD)v68;
    else
      LODWORD(v5) = -22;
    printk(&unk_253CC4, "_sde_kms_hw_init_blocks");
    v74 = (_QWORD *)(a1 + 152);
    goto LABEL_128;
  }
  *(_DWORD *)(a1 + 144) = *v68;
  printk(&unk_21281D, "_sde_kms_hw_init_blocks");
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)(v2 + 8) + 744LL), "#power-domain-cells", 0) )
  {
    *(_QWORD *)(a1 + 1448) = *(_QWORD *)(v2 + 120);
    *(_QWORD *)(a1 + 1504) = sde_kms_pd_disable;
    *(_QWORD *)(a1 + 1512) = sde_kms_pd_enable;
    v69 = pm_genpd_init(a1 + 160, 0, 1);
    if ( v69 < 0 )
    {
      v70 = v69;
      printk(&unk_22E59F, "_sde_kms_hw_init_power_helper");
    }
    else
    {
      v70 = of_genpd_add_provider_simple(*(_QWORD *)(*(_QWORD *)(v2 + 8) + 744LL), a1 + 160);
      if ( v70 < 0 )
      {
        printk(&unk_216209, "_sde_kms_hw_init_power_helper");
        pm_genpd_remove(a1 + 160);
      }
      else
      {
        v71 = _drm_debug;
        *(_BYTE *)(a1 + 1696) = 1;
        if ( (v71 & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "added genpd provider %s\n", *(const char **)(a1 + 1448));
        if ( !v70 )
          goto LABEL_121;
      }
    }
    v143 = &unk_24983A;
    LODWORD(v5) = v70;
LABEL_484:
    printk(v143, "_sde_kms_hw_init_blocks");
    sde_core_perf_destroy((_QWORD *)(a1 + 1960));
LABEL_36:
    ((void (__fastcall *)(__int64, __int64))sde_kms_hw_destroy)(a1, v8);
    goto LABEL_7;
  }
LABEL_121:
  v72 = *(_QWORD *)(a1 + 136);
  if ( !v72 || (v249 = v7, !*(_QWORD *)(v72 + 8)) )
  {
    LODWORD(v5) = -22;
LABEL_272:
    v35 = &unk_27A553;
    v36 = "_sde_kms_hw_init_blocks";
    goto LABEL_503;
  }
  v73 = 0;
  v41 = (__int64)&unk_288730;
  while ( 1 )
  {
    v79 = msm_smmu_new(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL), (unsigned int)v73);
    if ( v79 < 0xFFFFFFFFFFFFF001LL )
      break;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "failed to init iommu id %d: rc:%d\n", v73, v79);
LABEL_138:
    if ( ++v73 == 4 )
    {
      *(_QWORD *)(a1 + 16) = *(_QWORD *)(a1 + 1704);
      goto LABEL_181;
    }
  }
  v80 = msm_gem_smmu_address_space_create(*(_QWORD *)(a1 + 136), v79, &unk_288730);
  v5 = v80;
  if ( v80 > 0xFFFFFFFFFFFFF000LL )
  {
    v91 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v79 + 64LL);
    if ( *((_DWORD *)v91 - 1) != -1262402125 )
      __break(0x8228u);
    v91(v79);
    goto LABEL_172;
  }
  *(_QWORD *)(a1 + 8 * v73 + 1704) = v80;
  *(_BYTE *)(v80 + 268) = 1;
  if ( v73 )
    goto LABEL_135;
  if ( !*(_DWORD *)(a1 + 2540) || !*(_DWORD *)(a1 + 2544) )
    goto LABEL_154;
  v81 = sde_kms_splash_mem_get(a1, *(_QWORD *)(a1 + 2728));
  if ( !v81 )
  {
    v82 = *(_QWORD *)(a1 + 2736);
    if ( !v82 || (v81 = sde_kms_splash_mem_get(a1, v82)) == 0 )
    {
      if ( *(_DWORD *)(a1 + 2544) >= 2u )
      {
        v81 = sde_kms_splash_mem_get(a1, *(_QWORD *)(a1 + 2808));
        if ( v81 )
          goto LABEL_506;
        v83 = *(_QWORD *)(a1 + 2816);
        if ( v83 )
        {
          v81 = sde_kms_splash_mem_get(a1, v83);
          if ( v81 )
            goto LABEL_506;
        }
        if ( *(_DWORD *)(a1 + 2544) > 2u )
          goto LABEL_423;
      }
LABEL_154:
      if ( !(*v255)[13] )
        goto LABEL_135;
      resource_byname = platform_get_resource_byname(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL) - 16LL, 512, "ipcc_reg");
      if ( resource_byname )
      {
        v86 = *(_QWORD *)(a1 + 1704);
        v87 = *(_QWORD *)resource_byname
            + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 152) + 22124LL) << 12)
            + (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 152) + 22120LL) * *(_DWORD *)(*(_QWORD *)(a1 + 152) + 22132LL));
        *(_QWORD *)(a1 + 6392) = v87;
        if ( v86 && (v88 = *(_QWORD *)(v86 + 256)) != 0 )
        {
          if ( *(_QWORD *)v88 )
          {
            v89 = *(unsigned int (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(*(_QWORD *)v88 + 88LL);
            if ( v89 )
            {
              v90 = (unsigned int)(*(_DWORD *)(resource_byname + 8) - *(_DWORD *)resource_byname + 1);
              if ( *((_DWORD *)v89 - 1) != 1814495457 )
                __break(0x8229u);
              if ( v89(v88, v87, v87, v90, 3) )
              {
                printk(&unk_22AFEF, "_sde_kms_one2one_mem_map_ipcc_reg");
LABEL_132:
                v76 = &unk_216247;
LABEL_133:
                printk(v76, "_sde_kms_mmu_init");
                goto LABEL_134;
              }
              goto LABEL_135;
            }
          }
          v75 = &unk_219C2B;
        }
        else
        {
          v75 = &unk_22E5DE;
        }
        printk(v75, "_sde_kms_one2one_mem_map_ipcc_reg");
        goto LABEL_132;
      }
      if ( (_drm_debug & 4) == 0 )
      {
        v76 = &unk_262680;
        goto LABEL_133;
      }
      printk(&unk_262646, v85);
LABEL_134:
      (*v255)[13] = 0;
LABEL_135:
      v77 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v79 + 80LL);
      if ( *((_DWORD *)v77 - 1) != 23378124 )
        __break(0x8228u);
      v78 = v77(v79);
      if ( v78 )
      {
        LODWORD(v5) = v78;
        v215 = &unk_24CC77;
        goto LABEL_507;
      }
      goto LABEL_138;
    }
  }
LABEL_506:
  LODWORD(v5) = v81;
  v215 = &unk_23F705;
LABEL_507:
  printk(v215, "_sde_kms_mmu_init");
  sde_kms_unmap_all_splash_regions(a1);
LABEL_172:
  if ( *(_QWORD *)(a1 + 1728) )
  {
    msm_gem_address_space_put();
    *(_QWORD *)(a1 + 1728) = 0;
  }
  if ( *(_QWORD *)(a1 + 1720) )
  {
    msm_gem_address_space_put();
    *(_QWORD *)(a1 + 1720) = 0;
  }
  if ( *(_QWORD *)(a1 + 1712) )
  {
    msm_gem_address_space_put();
    *(_QWORD *)(a1 + 1712) = 0;
  }
  if ( *(_QWORD *)(a1 + 1704) )
  {
    msm_gem_address_space_put();
    *(_QWORD *)(a1 + 1704) = 0;
  }
  if ( (_DWORD)v5 )
    goto LABEL_272;
LABEL_181:
  *(_DWORD *)(*(_QWORD *)(a1 + 152) + 19956LL) = *(_QWORD *)(a1 + 1848);
  v92 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))sde_reg_dma_init)(
          *(_QWORD *)(a1 + 1776),
          *(_QWORD *)(a1 + 152),
          *(_QWORD *)(a1 + 136));
  if ( v92 )
  {
    LODWORD(v5) = v92;
    printk(&unk_219BF5, "_sde_kms_hw_init_blocks");
    goto LABEL_36;
  }
  sde_dbg_init_dbg_buses(*(unsigned int *)(a1 + 144));
  v93 = sde_rm_init((char *)(a1 + 2144));
  if ( v93 )
  {
    LODWORD(v5) = v93;
    v35 = &unk_242FFB;
    v36 = "_sde_kms_hw_init_rm";
    goto LABEL_503;
  }
  *(_BYTE *)(a1 + 2528) = 1;
  if ( *(_DWORD *)(v7 + 5912) == 1 )
    sde_rm_set_disp_op(a1 + 2144, 1);
  v94 = sde_hw_intr_init(*(_QWORD *)(a1 + 1752), *(_QWORD *)(a1 + 152));
  v5 = v94;
  *(_QWORD *)(a1 + 1896) = v94;
  if ( !v94 || v94 >= 0xFFFFFFFFFFFFF001LL )
  {
    v141 = (_QWORD *)(a1 + 1896);
    v142 = &unk_253D2C;
    goto LABEL_281;
  }
  if ( *(_DWORD *)(a1 + 2540) )
  {
    v95 = *(_DWORD *)(a1 + 2544);
    v96 = sde_rm_cont_splash_res_init(v7, a1 + 2144, a1 + 2536, *(_DWORD **)(a1 + 152));
    if ( v95 >= 1 )
    {
      v5 = v96;
      if ( *(_BYTE *)(a1 + 2712) != 1 || v96 )
        sde_kms_free_splash_display_data(a1, (_QWORD *)(a1 + 2712));
      if ( v95 != 1 )
      {
        if ( *(_BYTE *)(a1 + 2792) != 1 || (_DWORD)v5 )
          sde_kms_free_splash_display_data(a1, (_QWORD *)(a1 + 2792));
        if ( v95 != 2 )
        {
          if ( *(_BYTE *)(a1 + 2872) != 1 || (_DWORD)v5 )
            sde_kms_free_splash_display_data(a1, (_QWORD *)(a1 + 2872));
          if ( v95 != 3 )
            goto LABEL_423;
        }
      }
    }
  }
  mdp = sde_rm_get_mdp(a1 + 2144);
  *(_QWORD *)(a1 + 3528) = mdp;
  if ( !mdp || mdp >= 0xFFFFFFFFFFFFF001LL )
  {
    v141 = (_QWORD *)(a1 + 3528);
    if ( mdp )
      v5 = (unsigned int)mdp;
    else
      v5 = 4294967274LL;
    v142 = &unk_220FCC;
LABEL_281:
    printk(v142, "_sde_kms_hw_init_rm");
    *v141 = 0;
    if ( !(_DWORD)v5 )
      goto LABEL_203;
    goto LABEL_36;
  }
LABEL_203:
  v98 = *v255;
  if ( !(*v255)[3834] )
    goto LABEL_212;
  v99 = v98[3840];
  if ( (unsigned int)v99 >= 2 )
    goto LABEL_423;
  v100 = a1 + 1760;
  v5 = a1 + 3512;
  *(_QWORD *)(a1 + 3512) = sde_hw_vbif_init((unsigned int)v99, *(_QWORD *)(a1 + 1760 + 8 * v99), *v255);
  v101 = *(_QWORD *)(a1 + 3512 + 8 * v99);
  v102 = v101 == 0;
  if ( !v101 || v101 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_286;
  v98 = *v255;
  if ( (*v255)[3834] < 2 )
  {
LABEL_212:
    *(_QWORD *)(a1 + 3536) = 0;
    if ( v98[5477] )
    {
      v103 = sde_hw_uidle_init(1, *(_QWORD *)(a1 + 1752), *(_QWORD *)(a1 + 1800));
      *(_QWORD *)(a1 + 3536) = v103;
      if ( !v103 || v103 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_262611, "_sde_kms_hw_init_blocks");
        *(_QWORD *)(a1 + 3536) = 0;
      }
    }
    v104 = *(_QWORD *)(a1 + 1784);
    v105 = *(_QWORD *)(a1 + 152);
    if ( v104 )
    {
      v106 = sde_hw_sid_init(v104, *(unsigned int *)(a1 + 1832), v105);
      LODWORD(v5) = v106;
      *(_QWORD *)(a1 + 3552) = v106;
      if ( !v106 || v106 > 0xFFFFFFFFFFFFF000LL )
      {
        v74 = (_QWORD *)(a1 + 3552);
        printk(&unk_26CDAF, "_sde_kms_hw_init_blocks");
        goto LABEL_128;
      }
      v105 = (__int64)*v255;
    }
    v107 = sde_core_perf_init(a1 + 1960, v2, v105, v7 + 16, "core_clk");
    if ( !v107 )
    {
      v109 = *(_QWORD *)(a1 + 1792);
      *(_QWORD *)(a1 + 3560) = 0;
      if ( v109 )
      {
        v110 = sde_hw_sw_fuse_init(v109, *(unsigned int *)(a1 + 1840), *(_QWORD *)(a1 + 152));
        *(_QWORD *)(a1 + 3560) = v110;
        if ( v110 >= 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_25B0EC, "_sde_kms_hw_init_blocks");
          *(_QWORD *)(a1 + 3560) = 0;
        }
      }
      if ( (*((_QWORD *)*v255 + 2751) & 0x1000000) != 0 )
        *(_BYTE *)(v2 + 376) = 1;
      if ( (*(_BYTE *)(v7 + 432) & 1) == 0 )
      {
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_235413, v108);
        else
          printk(&unk_23BED5, "_sde_kms_hw_init_blocks");
        (*v255)[13] = 0;
      }
      v111 = *(_QWORD *)(a1 + 136);
      v326 = 0;
      v325 = 0;
      v324 = 0;
      v323 = 0;
      v322 = 0;
      v321 = 0;
      v320 = 0;
      v319 = 0;
      v318 = 0;
      v317 = 0;
      v316 = 0;
      v315 = 0;
      v313 = 0;
      v314 = 0;
      v311 = 0;
      v312 = 0;
      v309 = 0;
      v310 = 0;
      v307 = 0;
      v308 = 0;
      v305 = 0;
      v306 = 0;
      v303 = 0;
      v304 = 0;
      v301 = 0;
      v302 = 0;
      v299 = 0;
      v300 = 0;
      v297 = 0;
      v298 = 0;
      v295 = 0;
      v296 = 0;
      v293 = 0;
      v294 = 0;
      v291 = 0;
      v292 = 0;
      v289 = 0;
      v290 = 0;
      v287 = 0;
      v288 = 0;
      v285 = 0;
      v286 = 0;
      v283 = 0;
      v284 = 0;
      v281 = 0;
      v282 = 0;
      v279 = 0;
      v280 = 0;
      v277 = 0;
      v278 = 0;
      v275 = 0;
      v276 = 0;
      v273 = 0;
      v274 = 0;
      v271 = 0;
      v272 = 0;
      v269 = 0;
      v270 = 0;
      v267 = 0;
      v268 = 0;
      v265 = 0;
      v266 = 0;
      *(_QWORD *)s = 0;
      v264 = 0;
      if ( v111 && *(_QWORD *)(v111 + 8) )
      {
        v5 = *(_QWORD *)(v111 + 56);
        v254 = *(_QWORD *)(a1 + 152);
        v112 = sde_core_irq_domain_add((_QWORD *)a1);
        if ( !v112 )
        {
          v113 = *(_QWORD *)(a1 + 136);
          *(_QWORD *)(a1 + 3576) = 0;
          v114 = dsi_display_get_num_of_displays(v113);
          *(_DWORD *)(a1 + 3568) = v114;
          if ( v114 )
          {
            v115 = *(unsigned int *)(a1 + 3568);
            if ( (v115 & 0x80000000) != 0 )
            {
              *(_QWORD *)(a1 + 3576) = 0;
              goto LABEL_509;
            }
            v116 = _kmalloc_noprof(8 * v115, 3520);
            *(_QWORD *)(a1 + 3576) = v116;
            if ( !v116 )
              goto LABEL_509;
            goto LABEL_232;
          }
LABEL_233:
          v117 = *(_QWORD *)(a1 + 136);
          *(_QWORD *)(a1 + 3592) = 0;
          v118 = sde_wb_get_num_of_displays(v117);
          *(_DWORD *)(a1 + 3584) = v118;
          if ( v118 )
          {
            v119 = *(unsigned int *)(a1 + 3584);
            if ( (v119 & 0x80000000) != 0 )
            {
              *(_QWORD *)(a1 + 3592) = 0;
            }
            else
            {
              v120 = _kmalloc_noprof(8 * v119, 3520);
              *(_QWORD *)(a1 + 3592) = v120;
              if ( v120 )
              {
                *(_DWORD *)(a1 + 3584) = wb_display_get_displays(
                                           *(_QWORD *)(a1 + 136),
                                           v120,
                                           *(unsigned int *)(a1 + 3584));
                goto LABEL_237;
              }
            }
            printk(&unk_25023B, "_sde_kms_get_displays");
            goto LABEL_517;
          }
LABEL_237:
          v121 = *(_QWORD *)(a1 + 136);
          *(_QWORD *)(a1 + 3608) = 0;
          v122 = dp_display_get_num_of_displays(v121);
          *(_DWORD *)(a1 + 3600) = v122;
          if ( v122 )
          {
            v123 = *(unsigned int *)(a1 + 3600);
            if ( (v123 & 0x80000000) != 0 )
            {
              *(_QWORD *)(a1 + 3608) = 0;
            }
            else
            {
              v124 = (_QWORD *)_kmalloc_noprof(8 * v123, 3520);
              *(_QWORD *)(a1 + 3608) = v124;
              if ( v124 )
              {
                displays = dp_display_get_displays(*(_QWORD *)(a1 + 136), v124, *(_DWORD *)(a1 + 3600));
                v126 = *(_QWORD *)(a1 + 136);
                *(_DWORD *)(a1 + 3600) = displays;
                *(_DWORD *)(a1 + 3616) = dp_display_get_num_of_streams(v126);
                goto LABEL_241;
              }
            }
            printk(&unk_224576, "_sde_kms_get_displays");
LABEL_516:
            kfree(*(_QWORD *)(a1 + 3608));
            *(_DWORD *)(a1 + 3616) = 0;
            *(_DWORD *)(a1 + 3600) = 0;
            *(_QWORD *)(a1 + 3608) = 0;
LABEL_517:
            kfree(*(_QWORD *)(a1 + 3592));
            *(_DWORD *)(a1 + 3584) = 0;
            *(_QWORD *)(a1 + 3592) = 0;
LABEL_518:
            kfree(*(_QWORD *)(a1 + 3576));
            *(_DWORD *)(a1 + 3568) = 0;
            *(_QWORD *)(a1 + 3576) = 0;
            goto LABEL_393;
          }
LABEL_241:
          v127 = *(_QWORD *)(a1 + 152);
          *(_QWORD *)(a1 + 3624) = 0;
          if ( *(_DWORD *)(v127 + 56) != 41 )
          {
            LODWORD(v128) = 0;
            *(_DWORD *)(a1 + 3632) = 0;
            goto LABEL_250;
          }
          LODWORD(v128) = *(_DWORD *)(a1 + 3568);
          *(_DWORD *)(a1 + 3632) = v128;
          if ( !(_DWORD)v128 )
            goto LABEL_250;
          v129 = *(unsigned int *)(a1 + 3632);
          if ( (v129 & 0x80000000) != 0 )
          {
            *(_QWORD *)(a1 + 3624) = 0;
          }
          else
          {
            v130 = _kmalloc_noprof(8 * v129, 3520);
            *(_QWORD *)(a1 + 3624) = v130;
            if ( v130 )
            {
              LODWORD(v128) = *(_DWORD *)(a1 + 3632);
              if ( (int)v128 >= 1 )
              {
                v131 = 0;
                do
                {
                  *(_QWORD *)(*(_QWORD *)(a1 + 3624) + 8 * v131) = *(_QWORD *)(*(_QWORD *)(a1 + 3576) + 8 * v131);
                  ++v131;
                  v128 = *(int *)(a1 + 3632);
                }
                while ( v131 < v128 );
              }
LABEL_250:
              *(_QWORD *)(a1 + 3640) = 0;
              *(_DWORD *)(a1 + 3648) = 0;
              v352 = 0;
              v353 = 0;
              v350 = 0;
              v351 = 0;
              v348 = 0;
              v349 = 0;
              v346 = 0;
              v347 = 0;
              v344 = 0;
              v345 = 0;
              v342 = 0;
              v343 = 0;
              v340 = 0;
              v341 = 0;
              v338 = 0;
              v339 = 0;
              v336 = 0;
              v337 = 0;
              v334 = 0;
              v335 = 0;
              v332 = 0;
              v333 = 0;
              *(_QWORD *)v330 = 0;
              v331 = 0;
              if ( v5 )
              {
                v132 = *(_DWORD *)(a1 + 3584);
                v258 = *(_DWORD *)(a1 + 3568) + v128 + v132 + *(_DWORD *)(a1 + 3600) + *(_DWORD *)(a1 + 3616);
                if ( v258 >= 0x11 )
                {
                  v258 = 16;
                  printk(&unk_216281, "_sde_kms_setup_displays");
                  if ( *(int *)(a1 + 3584) >= 1 )
                    goto LABEL_253;
                }
                else if ( v132 >= 1 )
                {
LABEL_253:
                  v41 = 0;
                  while ( 1 )
                  {
                    if ( *(_DWORD *)(v5 + 3792) >= v258 )
                      goto LABEL_298;
                    v134 = *(_QWORD *)(*(_QWORD *)(a1 + 3592) + 8 * v41);
                    v334 = 0;
                    v335 = 0;
                    v336 = 0;
                    v337 = 0;
                    v338 = 0;
                    v339 = 0;
                    v340 = 0;
                    v341 = 0;
                    v342 = 0;
                    v343 = 0;
                    v344 = 0;
                    v345 = 0;
                    v346 = 0;
                    v347 = 0;
                    v348 = 0;
                    v349 = 0;
                    v350 = 0;
                    v351 = 0;
                    v352 = 0;
                    v353 = 0;
                    if ( (unsigned int)sde_wb_get_info(0, &v334, v134) )
                      break;
                    snprintf(v330, 0x20u, "wb%u", v41);
                    v135 = ((__int64 (__fastcall *)(_QWORD, char *))sde_cesta_create_client)(
                             **(unsigned int **)(v111 + 64),
                             v330);
                    v136 = sde_encoder_init(v111, (__int64)&v334, v135);
                    if ( !v136 || (v137 = v136, v136 >= 0xFFFFFFFFFFFFF001LL) )
                    {
                      v133 = &unk_21DC04;
                      goto LABEL_255;
                    }
                    if ( (unsigned int)((__int64 (__fastcall *)(__int64, unsigned __int64))sde_wb_drm_init)(v134, v136) )
                    {
                      printk(&unk_27042A, "_sde_kms_setup_displays");
LABEL_270:
                      sde_encoder_destroy(v137);
                      goto LABEL_256;
                    }
                    v138 = sde_connector_init(v111, v137, 0, v134, &sde_kms_setup_displays_wb_ops, 1, 15, 0);
                    if ( !v138 || v138 > 0xFFFFFFFFFFFFF000LL )
                    {
                      printk(&unk_220FFF, "_sde_kms_setup_displays");
                      sde_wb_drm_deinit(v134);
                      goto LABEL_270;
                    }
                    v139 = *(unsigned int *)(v5 + 3792);
                    *(_DWORD *)(v5 + 3792) = v139 + 1;
                    if ( (unsigned int)v139 >= 0x10 )
                      goto LABEL_423;
                    *(_QWORD *)(v5 + 3800 + 8 * v139) = v137;
                    v140 = *(unsigned int *)(v5 + 4064);
                    *(_DWORD *)(v5 + 4064) = v140 + 1;
                    if ( (unsigned int)v140 > 0xF )
                      goto LABEL_423;
                    *(_QWORD *)(v5 + 4072 + 8 * v140) = v138;
LABEL_256:
                    if ( ++v41 >= *(int *)(a1 + 3584) )
                      goto LABEL_298;
                  }
                  v133 = &unk_2278FA;
LABEL_255:
                  printk(v133, "_sde_kms_setup_displays");
                  goto LABEL_256;
                }
LABEL_298:
                if ( *(int *)(a1 + 3568) >= 1 )
                {
                  v41 = 0;
                  v250 = 0;
                  v252 = 0;
                  while ( 1 )
                  {
                    if ( *(_DWORD *)(v5 + 3792) >= v258 )
                      goto LABEL_324;
                    v145 = *(_QWORD *)(*(_QWORD *)(a1 + 3576) + 8 * v41);
                    v334 = 0;
                    v335 = 0;
                    v336 = 0;
                    v337 = 0;
                    v338 = 0;
                    v339 = 0;
                    v340 = 0;
                    v341 = 0;
                    v342 = 0;
                    v343 = 0;
                    v344 = 0;
                    v345 = 0;
                    v346 = 0;
                    v347 = 0;
                    v348 = 0;
                    v349 = 0;
                    v350 = 0;
                    v351 = 0;
                    v352 = 0;
                    v353 = 0;
                    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64 *, __int64))dsi_display_get_info)(
                                         0,
                                         &v334,
                                         v145) )
                      break;
                    snprintf(v330, 0x20u, "dsi%u", v41);
                    v146 = ((__int64 (__fastcall *)(_QWORD, char *))sde_cesta_create_client)(
                             **(unsigned int **)(v111 + 64),
                             v330);
                    v147 = sde_encoder_init(v111, (__int64)&v334, v146);
                    if ( !v147 || (v148 = v147, v147 >= 0xFFFFFFFFFFFFF001LL) )
                    {
                      v144 = &unk_2464C8;
                      goto LABEL_301;
                    }
                    if ( (sde_cesta_is_aoss_supported(**(unsigned int **)(v111 + 64)) & 1) != 0 )
                      v149 = v146;
                    else
                      v149 = 0;
                    if ( (unsigned int)dsi_display_drm_bridge_init(v145, v148, v149) )
                    {
                      printk(&unk_22B02B, "_sde_kms_setup_displays");
LABEL_322:
                      sde_encoder_destroy(v148);
                      goto LABEL_302;
                    }
                    drm_panel = dsi_display_get_drm_panel(v145);
                    v151 = sde_connector_init(v111, v148, drm_panel, v145, &sde_kms_setup_displays_dsi_ops, 1, 16, 0);
                    if ( !v151 || (v152 = v151, v151 > 0xFFFFFFFFFFFFF000LL) )
                    {
                      printk(&unk_22792A, "_sde_kms_setup_displays");
                      dsi_display_drm_bridge_deinit(v145);
                      goto LABEL_322;
                    }
                    v153 = *(unsigned int *)(v5 + 3792);
                    *(_DWORD *)(v5 + 3792) = v153 + 1;
                    if ( (unsigned int)v153 > 0xF )
                      goto LABEL_423;
                    *(_QWORD *)(v5 + 3800 + 8 * v153) = v148;
                    v154 = *(unsigned int *)(v5 + 4064);
                    *(_DWORD *)(v5 + 4064) = v154 + 1;
                    if ( (unsigned int)v154 > 0xF )
                      goto LABEL_423;
                    *(_QWORD *)(v5 + 4072 + 8 * v154) = v151;
                    if ( (unsigned int)dsi_display_drm_ext_bridge_init(v145, v148, v151) )
                    {
                      printk(&unk_231CF1, "_sde_kms_setup_displays");
                      dsi_display_drm_bridge_deinit(v145);
                      sde_connector_destroy(v152);
                      sde_encoder_destroy(v148);
                    }
                    v250 += v353;
                    v252 += HIDWORD(v352);
                    if ( (dsi_display_has_dsc_switch_support(v145) & 1) != 0 )
                      *(_BYTE *)(a1 + 3636) = 1;
LABEL_302:
                    if ( ++v41 >= *(int *)(a1 + 3568) )
                      goto LABEL_324;
                  }
                  v144 = &unk_243028;
LABEL_301:
                  printk(v144, "_sde_kms_setup_displays");
                  goto LABEL_302;
                }
                v250 = 0;
                v252 = 0;
LABEL_324:
                if ( *(int *)(a1 + 3632) >= 1 )
                {
                  v41 = 0;
                  while ( *(_DWORD *)(v5 + 3792) < v258 )
                  {
                    v155 = *(_QWORD *)(*(_QWORD *)(a1 + 3624) + 8 * v41);
                    v334 = 0;
                    v335 = 0;
                    v336 = 0;
                    v337 = 0;
                    v338 = 0;
                    v339 = 0;
                    v340 = 0;
                    v341 = 0;
                    v342 = 0;
                    v343 = 0;
                    v344 = 0;
                    v345 = 0;
                    v346 = 0;
                    v347 = 0;
                    v348 = 0;
                    v349 = 0;
                    v350 = 0;
                    v351 = 0;
                    v352 = 0;
                    v353 = 0;
                    sde_lb_display_get_info(0, &v334, v155);
                    v156 = sde_encoder_init(v111, (__int64)&v334, 0);
                    if ( v156 && (v157 = v156, v156 < 0xFFFFFFFFFFFFF001LL) )
                    {
                      v158 = sde_connector_init(v111, v156, 0, v155, &sde_kms_setup_displays_virt_ops, 1, 15, 0);
                      if ( v158 && v158 <= 0xFFFFFFFFFFFFF000LL )
                      {
                        v159 = *(unsigned int *)(v5 + 3792);
                        *(_DWORD *)(v5 + 3792) = v159 + 1;
                        if ( (unsigned int)v159 > 0xF )
                          goto LABEL_423;
                        *(_QWORD *)(v5 + 3800 + 8 * v159) = v157;
                        v160 = *(unsigned int *)(v5 + 4064);
                        *(_DWORD *)(v5 + 4064) = v160 + 1;
                        if ( (unsigned int)v160 > 0xF )
                          goto LABEL_423;
                        *(_QWORD *)(v5 + 4072 + 8 * v160) = v158;
                      }
                      else
                      {
                        printk(&unk_25B170, "_sde_kms_setup_displays");
                        sde_encoder_destroy(v157);
                      }
                    }
                    else
                    {
                      printk(&unk_23BF1E, "_sde_kms_setup_displays");
                    }
                    if ( ++v41 >= *(int *)(a1 + 3632) )
                      break;
                  }
                }
                v161 = *v255;
                v162 = (*v255)[5403];
                if ( v162 && (*(_BYTE *)(a1 + 3636) & 1) == 0 )
                {
                  if ( (_drm_debug & 4) != 0 )
                  {
                    _drm_dev_dbg(0, 0, 0, "dsc switch not supported\n");
                    v161 = *v255;
                  }
                  v161[5403] = 0;
                  v161 = *v255;
                  v162 = (*v255)[5403];
                }
                v163 = v161[1738];
                v164 = v161[2598];
                v165 = v163 >= v250;
                v166 = v163 - v250;
                if ( v165 )
                  v167 = v166;
                else
                  v167 = 0;
                v168 = v164 - v252;
                if ( v164 < v252 )
                  v168 = 0;
                if ( (v162 & 1) == 0 )
                  v164 = v168;
                v251 = v164;
                if ( *(_DWORD *)(v5 + 5912) != 1 && *(int *)(a1 + 3600) >= 1 )
                {
                  v169 = 0;
                  v253 = v5 + 3800;
                  while ( 1 )
                  {
                    if ( *(_DWORD *)(v5 + 3792) >= v258 )
                      goto LABEL_392;
                    v171 = *(_QWORD *)(a1 + 3608);
                    v329 = 0;
                    v327 = 0;
                    v328 = 0;
                    v41 = *(_QWORD *)(v171 + 8 * v169);
                    v334 = 0;
                    v335 = 0;
                    v336 = 0;
                    v337 = 0;
                    v338 = 0;
                    v339 = 0;
                    v340 = 0;
                    v341 = 0;
                    v342 = 0;
                    v343 = 0;
                    v344 = 0;
                    v345 = 0;
                    v346 = 0;
                    v347 = 0;
                    v348 = 0;
                    v349 = 0;
                    v350 = 0;
                    v351 = 0;
                    v352 = 0;
                    v353 = 0;
                    if ( (unsigned int)dp_connector_get_info(0, (__int64)&v334, v41) )
                      break;
                    if ( (unsigned int)dp_display_get_info((_DWORD *)v41, &v327) )
                    {
                      v170 = &unk_21DC3C;
LABEL_354:
                      printk(v170, "_sde_kms_setup_displays");
                      goto LABEL_355;
                    }
                    LODWORD(v336) = HIDWORD(v327);
                    snprintf(v330, 0x20u, "dp%u", v169);
                    v172 = ((__int64 (__fastcall *)(_QWORD, char *))sde_cesta_create_client)(
                             **(unsigned int **)(v111 + 64),
                             v330);
                    v173 = sde_encoder_init(v111, (__int64)&v334, v172);
                    if ( !v173 || (v174 = v173, v173 >= 0xFFFFFFFFFFFFF001LL) )
                    {
                      v170 = &unk_227961;
                      goto LABEL_354;
                    }
                    if ( (unsigned int)dp_drm_bridge_init((__int64 *)v41, v173, v167, v251) )
                    {
                      printk(&unk_221065, "_sde_kms_setup_displays");
LABEL_387:
                      sde_encoder_destroy(v174);
                      goto LABEL_355;
                    }
                    v175 = sde_connector_init(
                             v111,
                             v174,
                             0,
                             v41,
                             sde_kms_setup_displays_dp_ops,
                             1,
                             (unsigned int)v334,
                             0);
                    if ( !v175 || v175 > 0xFFFFFFFFFFFFF000LL )
                    {
                      printk(&unk_2626D4, "_sde_kms_setup_displays");
                      dp_drm_bridge_deinit(v41);
                      goto LABEL_387;
                    }
                    v176 = *(unsigned int *)(v5 + 3792);
                    v177 = v176 + 1;
                    *(_DWORD *)(v5 + 3792) = v176 + 1;
                    if ( (unsigned int)v176 > 0xF )
                      goto LABEL_423;
                    *(_QWORD *)(v253 + 8 * v176) = v174;
                    v178 = *(unsigned int *)(v5 + 4064);
                    *(_DWORD *)(v5 + 4064) = v178 + 1;
                    if ( (unsigned int)v178 > 0xF )
                      goto LABEL_423;
                    *(_QWORD *)(v5 + 4072 + 8 * v178) = v175;
                    HIDWORD(v334) |= 0x20u;
                    if ( v177 < v258 )
                    {
                      if ( v329 )
                      {
                        LODWORD(v336) = HIDWORD(v327);
                        v179 = sde_encoder_init(v111, (__int64)&v334, v172);
                        if ( v179 && (v180 = v179, v179 < 0xFFFFFFFFFFFFF001LL) )
                        {
                          if ( (unsigned int)dp_mst_drm_bridge_init((_QWORD *)v41, v179) )
                          {
                            printk(&unk_243091, "_sde_kms_setup_displays");
                            sde_encoder_destroy(v180);
                          }
                          else
                          {
                            v181 = *(unsigned int *)(v5 + 3792);
                            *(_DWORD *)(v5 + 3792) = v181 + 1;
                            if ( (unsigned int)v181 > 0xF )
                              goto LABEL_423;
                            *(_QWORD *)(v253 + 8 * v181) = v180;
                          }
                        }
                        else
                        {
                          printk(&unk_243059, "_sde_kms_setup_displays");
                        }
                        if ( v329 >= 2 && *(_DWORD *)(v5 + 3792) < v258 )
                        {
                          LODWORD(v336) = v328;
                          snprintf(v330, 0x20u, "dp%u.%u", v169, 1);
                          v182 = ((__int64 (__fastcall *)(_QWORD, char *))sde_cesta_create_client)(
                                   **(unsigned int **)(v111 + 64),
                                   v330);
                          v183 = sde_encoder_init(v111, (__int64)&v334, v182);
                          if ( v183 && (v184 = v183, v183 <= 0xFFFFFFFFFFFFF000LL) )
                          {
                            if ( (unsigned int)dp_mst_drm_bridge_init((_QWORD *)v41, v183) )
                            {
                              printk(&unk_243091, "_sde_kms_setup_displays");
                              sde_encoder_destroy(v184);
                            }
                            else
                            {
                              v185 = *(unsigned int *)(v5 + 3792);
                              *(_DWORD *)(v5 + 3792) = v185 + 1;
                              if ( (unsigned int)v185 > 0xF )
                                goto LABEL_423;
                              *(_QWORD *)(v253 + 8 * v185) = v184;
                            }
                          }
                          else
                          {
                            printk(&unk_243059, "_sde_kms_setup_displays");
                          }
                          if ( v329 >= 3 && *(_DWORD *)(v5 + 3792) < v258 )
                            goto LABEL_423;
                        }
                      }
                    }
LABEL_355:
                    if ( ++v169 >= *(int *)(a1 + 3600) )
                      goto LABEL_392;
                  }
                  v170 = &unk_221035;
                  goto LABEL_354;
                }
LABEL_392:
                setup_hdmi_displays(v111, v5, a1, v258);
              }
              else
              {
                printk(&unk_253460, "_sde_kms_setup_displays");
              }
LABEL_393:
              v186 = v254;
              v256 = v111;
              v187 = *(_DWORD *)(v254 + 6952);
              if ( v187 )
              {
                if ( (unsigned int)(v187 - 13) < 0xFFFFFFF4 )
                  goto LABEL_423;
                v188 = 0;
                v189 = *(unsigned int *)(v254 + 6952);
                v190 = (unsigned __int8 *)(v254 + 7032);
                do
                {
                  v191 = *v190;
                  v190 += 96;
                  --v189;
                  v188 += v191;
                }
                while ( v189 );
              }
              else
              {
                v188 = 0;
              }
              LODWORD(v41) = v187 - v188;
              if ( !*(_DWORD *)(v254 + 6080) )
                goto LABEL_424;
              v192 = 0;
              v193 = -1LL << v41;
              v194 = 0;
              v195 = v5 + 736;
              v196 = (unsigned int *)(v254 + 6104);
              do
              {
                if ( v192 == 12 )
                  goto LABEL_423;
                v198 = *v196;
                if ( (_DWORD)v198 )
                {
                  v199 = sde_plane_init(v256, v198, v194 < (int)v41, ~v193, 0);
                  if ( v199 > 0xFFFFFFFFFFFFF000LL )
                  {
                    v216 = v199;
                    v217 = &unk_23F746;
LABEL_450:
                    printk(v217, "_sde_kms_drm_obj_init");
                    v209 = v216;
LABEL_451:
                    v218 = *(_QWORD *)(a1 + 136);
                    if ( v218 )
                    {
                      v219 = *(_DWORD **)(v218 + 56);
                      v5 = v209;
                      if ( v219 )
                      {
                        if ( v219[248] )
                        {
                          v220 = 0;
                          while ( v220 != 16 )
                          {
                            v221 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)&v219[2 * v220 + 250] + 424LL) + 40LL);
                            if ( *((_DWORD *)v221 - 1) != -1434212794 )
                              __break(0x8228u);
                            v221();
                            if ( ++v220 >= (unsigned __int64)(unsigned int)v219[248] )
                              goto LABEL_459;
                          }
                          goto LABEL_423;
                        }
LABEL_459:
                        v222 = v219[182];
                        v219[248] = 0;
                        if ( v222 )
                        {
                          v223 = 0;
                          while ( v223 != 32 )
                          {
                            v224 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)&v219[2 * v223 + 184] + 200LL) + 16LL);
                            if ( *((_DWORD *)v224 - 1) != 1504025452 )
                              __break(0x8228u);
                            v224();
                            if ( ++v223 >= (unsigned __int64)(unsigned int)v219[182] )
                              goto LABEL_465;
                          }
                          goto LABEL_423;
                        }
LABEL_465:
                        v225 = v219[1016];
                        v219[182] = 0;
                        if ( v225 )
                        {
                          v226 = 0;
                          while ( v226 != 16 )
                          {
                            v227 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)&v219[2 * v226 + 1018] + 416LL) + 64LL);
                            if ( *((_DWORD *)v227 - 1) != -767843333 )
                              __break(0x8228u);
                            v227();
                            if ( ++v226 >= (unsigned __int64)(unsigned int)v219[1016] )
                              goto LABEL_471;
                          }
                          goto LABEL_423;
                        }
LABEL_471:
                        v228 = v219[948];
                        v219[1016] = 0;
                        if ( v228 )
                        {
                          v229 = 0;
                          while ( v229 != 16 )
                          {
                            v230 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)&v219[2 * v229 + 950] + 104LL) + 8LL);
                            if ( *((_DWORD *)v230 - 1) != -781534014 )
                              __break(0x8228u);
                            v230();
                            if ( ++v229 >= (unsigned __int64)(unsigned int)v219[948] )
                              goto LABEL_477;
                          }
                          goto LABEL_423;
                        }
LABEL_477:
                        v219[948] = 0;
                        kfree(*(_QWORD *)(a1 + 3592));
                        v231 = *(_QWORD *)(a1 + 3576);
                        *(_QWORD *)(a1 + 3592) = 0;
                        *(_DWORD *)(a1 + 3584) = 0;
                        kfree(v231);
                        *(_QWORD *)(a1 + 3576) = 0;
                        *(_DWORD *)(a1 + 3568) = 0;
                      }
                      else
                      {
                        printk(&unk_219C62, "_sde_kms_drm_obj_destroy");
                      }
                    }
                    else
                    {
                      LODWORD(v5) = v209;
                      printk(&unk_2162BB, "_sde_kms_drm_obj_destroy");
                    }
                    sde_core_irq_domain_fini(a1);
                    goto LABEL_483;
                  }
                  v200 = *(unsigned int *)(v5 + 728);
                  v186 = v254;
                  *(_DWORD *)(v5 + 728) = v200 + 1;
                  if ( (unsigned int)v200 > 0x1F )
                    goto LABEL_423;
                  *(_QWORD *)(v195 + 8 * v200) = v199;
                  if ( v194 < (int)v41 )
                  {
                    if ( (unsigned int)v194 > 0x1F )
                      goto LABEL_423;
                    *(&v295 + (unsigned int)v194++) = v199;
                  }
                  if ( ((*((_QWORD *)v196 + 2) & 0x400) != 0
                     || (*((_QWORD *)v196 + 2) & 0x800) != 0
                     || (*((_QWORD *)v196 + 2) & 0x1000) != 0)
                    && sdecustom == 1 )
                  {
                    v201 = *(_DWORD *)(*((_QWORD *)v196 + 4) + 36LL) - 1;
                    if ( v201 > 0x1F )
                      goto LABEL_423;
                    *((_DWORD *)&v279 + v201) = *v196;
                    *(_DWORD *)&s[4 * v201] = *(_DWORD *)(v199 + 104);
                  }
                }
                v197 = *(unsigned int *)(v186 + 6080);
                ++v192;
                v196 += 18;
              }
              while ( v192 < v197 );
              if ( !*(_DWORD *)(v186 + 6080) )
                goto LABEL_425;
              v202 = 0;
              while ( v202 != 32 )
              {
                v203 = *((unsigned int *)&v279 + v202);
                if ( (_DWORD)v203 )
                {
                  v204 = sde_plane_init(v256, v203, 0, ~v193, *(unsigned int *)&s[4 * v202]);
                  if ( v204 >= 0xFFFFFFFFFFFFF001LL )
                  {
                    v216 = v204;
                    v217 = &unk_23F776;
                    goto LABEL_450;
                  }
                  v205 = *(unsigned int *)(v5 + 728);
                  *(_DWORD *)(v5 + 728) = v205 + 1;
                  if ( (unsigned int)v205 > 0x1F )
                    goto LABEL_423;
                  *(_QWORD *)(v195 + 8 * v205) = v204;
                  v197 = *(unsigned int *)(v254 + 6080);
                }
                if ( ++v202 >= v197 )
                  goto LABEL_425;
              }
              while ( 1 )
              {
                while ( 1 )
                {
LABEL_423:
                  while ( 1 )
                  {
                    __break(0x5512u);
LABEL_424:
                    v194 = 0;
LABEL_425:
                    v206 = (int)v41 >= v194 ? v194 : v41;
                    if ( v206 < 1 )
                      break;
                    v207 = 8LL * (unsigned int)v206;
                    v208 = 0;
                    v41 = (__int64)&v295;
                    while ( v208 != 256 )
                    {
                      v209 = sde_crtc_init(v256, *(__int64 *)((char *)&v295 + v208));
                      if ( v209 > 0xFFFFFFFFFFFFF000LL )
                        goto LABEL_451;
                      v210 = *(unsigned int *)(v5 + 992);
                      *(_DWORD *)(v5 + 992) = v210 + 1;
                      if ( (unsigned int)v210 > 0xF )
                        break;
                      v208 += 8;
                      *(_QWORD *)(v5 + 1000 + 8 * v210) = v209;
                      if ( v207 == v208 )
                        goto LABEL_434;
                    }
                  }
LABEL_434:
                  if ( sdecustom != 1 || !*(_DWORD *)(v5 + 728) )
                    break;
                  v211 = 0;
                  while ( v211 != 32 )
                  {
                    v212 = *(_QWORD *)(v5 + 736 + 8 * v211++);
                    *(_DWORD *)(v212 + 136) = ~(-1 << *(_DWORD *)(v5 + 992));
                    if ( v211 >= *(unsigned int *)(v5 + 728) )
                      goto LABEL_439;
                  }
                }
LABEL_439:
                if ( !*(_DWORD *)(v5 + 3792) )
                  break;
                v213 = 0;
                while ( v213 != 16 )
                {
                  v214 = *(_QWORD *)(v5 + 3800 + 8 * v213++);
                  *(_DWORD *)(v214 + 72) = ~(-1 << *(_DWORD *)(v5 + 992));
                  if ( v213 >= *(unsigned int *)(v5 + 3792) )
                    goto LABEL_443;
                }
              }
LABEL_443:
              v7 = v249;
              if ( (*v255)[3] == 1 )
              {
                v232 = *((_BYTE **)*v255 + 2487);
                if ( v232 )
                {
                  if ( *v232 == 1 )
                    v233 = v232[1];
                  else
                    v233 = 0;
                  *(_BYTE *)(v249 + 394) = v233 & 1;
                }
              }
              goto LABEL_487;
            }
          }
          printk(&unk_25B137, "_sde_kms_get_displays");
          kfree(*(_QWORD *)(a1 + 3624));
          *(_DWORD *)(a1 + 3632) = 0;
          *(_QWORD *)(a1 + 3624) = 0;
          goto LABEL_516;
        }
        LODWORD(v5) = v112;
        sde_core_irq_domain_fini(a1);
      }
      else
      {
        printk(&unk_25E374, "_sde_kms_drm_obj_init");
        LODWORD(v5) = -22;
      }
LABEL_483:
      v143 = &unk_24CC45;
      goto LABEL_484;
    }
    LODWORD(v5) = v107;
    v35 = &unk_212847;
    v36 = "_sde_kms_hw_init_blocks";
LABEL_503:
    printk(v35, v36);
    goto LABEL_36;
  }
  v99 = v98[3910];
  if ( (unsigned int)v99 > 1 )
    goto LABEL_423;
  *(_QWORD *)(a1 + 3520) = sde_hw_vbif_init((unsigned int)v99, *(_QWORD *)(v100 + 8 * v99), *v255);
  v101 = *(_QWORD *)(v5 + 8 * v99);
  v102 = v101 == 0;
  if ( v101 && v101 <= 0xFFFFFFFFFFFFF000LL )
  {
    v98 = *v255;
    if ( (*v255)[3834] < 3 )
      goto LABEL_212;
    v244 = v98[3980];
    if ( (unsigned int)v244 <= 1 )
    {
      sde_hw_vbif_init(v244, *(_QWORD *)(v100 + 8 * v244), v98);
      __break(0x5512u);
      v245 = v99;
      StatusReg = _ReadStatusReg(SP_EL0);
      v247 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sde_kms_get_displays__alloc_tag;
      v248 = *(unsigned int *)(a1 + 3568);
      if ( (v248 & 0x80000000) != 0 )
        v116 = 0;
      else
        v116 = _kmalloc_noprof(8 * v248, 3520);
      *(_QWORD *)(StatusReg + 80) = v247;
      v111 = v245;
      *(_QWORD *)(a1 + 3576) = v116;
      if ( !v116 )
      {
LABEL_509:
        printk(&unk_2691E7, "_sde_kms_get_displays");
        goto LABEL_518;
      }
LABEL_232:
      *(_DWORD *)(a1 + 3568) = dsi_display_get_active_displays(
                                 *(_QWORD *)(a1 + 136),
                                 v116,
                                 *(unsigned int *)(a1 + 3568));
      goto LABEL_233;
    }
    goto LABEL_423;
  }
LABEL_286:
  v74 = (_QWORD *)(v5 + 8 * v99);
  if ( v102 )
    LODWORD(v5) = -22;
  else
    LODWORD(v5) = v101;
  printk(&unk_25B0B7, "_sde_kms_hw_init_blocks");
LABEL_128:
  *v74 = 0;
  if ( (_DWORD)v5 )
    goto LABEL_36;
LABEL_487:
  *(_DWORD *)(v2 + 912) = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 21544LL);
  *(_DWORD *)(v2 + 916) = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 21548LL);
  *(_DWORD *)(v2 + 920) = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 21536LL);
  *(_DWORD *)(v2 + 924) = *(_DWORD *)(*(_QWORD *)(a1 + 152) + 21540LL);
  _mutex_init(a1 + 3696, "&sde_kms->secure_transition_lock", &sde_kms_hw_init___key);
  *(_DWORD *)(a1 + 3684) = 0;
  *(_DWORD *)(a1 + 3688) = 0;
  *(_DWORD *)(a1 + 3760) = 0;
  v234 = *(_QWORD *)(a1 + 136);
  *(_QWORD *)(a1 + 6368) = sde_kms_irq_affinity_notify;
  *(_QWORD *)(a1 + 6376) = sde_kms_irq_affinity_release;
  irq = platform_get_irq(*(_QWORD *)(v234 + 8) - 16LL, 0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "Registering for notification of irq_num: %d\n", irq);
  irq_set_affinity_notifier(irq, a1 + 6328);
  v236 = *(_QWORD *)(a1 + 2016);
  v237 = (unsigned int *)(*(_QWORD *)(a1 + 152) + 20480LL);
  v259 = *(unsigned int *)(*(_QWORD *)(a1 + 152) + 21704LL);
  v238 = v237[307];
  v262 = v236;
  v260 = v238;
  LODWORD(v261) = v237[348];
  v239 = *(unsigned int **)(v2 + 64);
  HIDWORD(v261) = v237[349];
  sde_cesta_update_perf_config(*v239, &v259);
  v240 = *(_QWORD *)(a1 + 152);
  if ( v240 && *(_BYTE *)(v240 + 20120) == 1 )
  {
    LODWORD(v5) = sde_vm_trusted_init(a1);
    v241 = 0;
  }
  else
  {
    LODWORD(v5) = sde_vm_primary_init(a1);
    v241 = 1;
  }
  sde_dbg_set_hw_ownership_status(v241);
  if ( (_DWORD)v5 )
  {
    v35 = &unk_26CCFB;
    v36 = "sde_kms_hw_init";
    goto LABEL_503;
  }
  if ( (*((_QWORD *)*v255 + 2751) & 0x8000000000000LL) != 0 )
    *(_BYTE *)(a1 + 6928) = 1;
  if ( *(_DWORD *)(v7 + 5912) != 1 )
    goto LABEL_501;
  *(_DWORD *)(*(_QWORD *)(a1 + 1896) + 28LL) = 1;
  *(_DWORD *)(*(_QWORD *)(a1 + 3528) + 28LL) = 1;
  *(_DWORD *)(*(_QWORD *)(a1 + 3536) + 28LL) = 1;
  v242 = *(_QWORD *)(a1 + 3512);
  if ( v242 )
    *(_DWORD *)(v242 + 28) = 1;
  v243 = *(_QWORD *)(a1 + 3520);
  if ( v243 )
  {
    LODWORD(v5) = 0;
    *(_DWORD *)(v243 + 28) = 1;
  }
  else
  {
LABEL_501:
    LODWORD(v5) = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
