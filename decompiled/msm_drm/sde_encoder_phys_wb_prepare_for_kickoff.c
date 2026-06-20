__int64 __fastcall sde_encoder_phys_wb_prepare_for_kickoff(__int64 *a1, __int64 a2)
{
  int v3; // w8
  char v4; // w9
  int v5; // w0
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x9
  __int64 *v14; // x23
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x10
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 *v23; // x22
  int v24; // w4
  __int64 v25; // x8
  int v26; // w5
  int v27; // w8
  __int64 output_fb; // x21
  __int64 v29; // x4
  int num_datapath; // w24
  int v31; // w8
  __int16 v32; // w9
  int v33; // w10
  int v34; // w9
  int v35; // w8
  int v36; // w4
  const char *sde_format_ext; // x0
  int v38; // w4
  __int64 v39; // x8
  int v40; // w5
  int v41; // w4
  __int64 v42; // x9
  int v43; // w5
  __int64 v44; // x20
  __int64 v45; // x8
  bool v46; // w8
  __int64 v47; // x9
  unsigned int v48; // w10
  unsigned int v49; // w11
  int v50; // w12
  int v51; // w0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x2
  __int64 v55; // x3
  __int64 v56; // x8
  __int64 v57; // x9
  int v58; // w10
  __int64 v59; // x12
  _DWORD *v60; // x11
  int v61; // w12
  int v62; // w13
  int v63; // w7
  int v64; // w9
  int v65; // w11
  int v66; // w10
  __int64 v67; // x11
  int v68; // w5
  __int64 v69; // x8
  unsigned int disp_op; // w0
  unsigned int v71; // w22
  __int64 v72; // x20
  int v73; // w24
  __int64 v74; // x25
  unsigned int v75; // w0
  __int64 v76; // x1
  long double v77; // q0
  __int64 v78; // x23
  __int64 v79; // x8
  __int64 v80; // x10
  __int64 v81; // x9
  int v82; // w9
  int v83; // w7
  bool v84; // zf
  int v85; // w9
  int v86; // w10
  __int64 v87; // x10
  __int64 v88; // x11
  __int64 v89; // x10
  __int64 v90; // x8
  unsigned __int64 v91; // x9
  int v92; // w8
  int v93; // w10
  int v94; // w4
  __int64 v95; // x11
  int v96; // w5
  void (__fastcall *v97)(__int64, char *, long double); // x8
  __int64 v98; // x8
  int v99; // w5
  long double v100; // q0
  __int64 v101; // x9
  _WORD *v102; // x8
  long double v103; // q0
  __int64 v104; // x1
  __int64 v105; // x8
  __int64 v106; // x8
  int v107; // w9
  unsigned int v108; // w23
  unsigned int v109; // w28
  __int64 v110; // x8
  _BOOL4 v111; // w8
  __int64 v112; // x9
  __int64 v113; // x25
  const char *v114; // x0
  __int64 v115; // x8
  int *v116; // x24
  __int64 v117; // x9
  __int64 v118; // x26
  int v119; // w4
  __int64 v120; // x8
  int v121; // w5
  char v122; // w9
  int v123; // w4
  __int64 v124; // x9
  int v125; // w5
  int v126; // w6
  int v127; // w4
  __int64 v128; // x8
  int v129; // w5
  const char *v130; // x0
  int v131; // w0
  int v132; // w4
  __int64 v133; // x8
  int v134; // w5
  __int64 v135; // x8
  int v136; // w9
  __int64 v137; // x8
  __int64 v138; // x0
  __int64 v139; // x24
  __int64 v140; // x20
  unsigned int v141; // w0
  int v142; // w25
  void (__fastcall *v143)(__int64, __int64 *); // x8
  __int64 v144; // x27
  __int64 v145; // x8
  int v146; // w9
  unsigned int *v147; // x8
  unsigned int v148; // w20
  unsigned int v149; // w20
  __int16 v150; // w9
  _DWORD *v151; // x8
  int v152; // w4
  __int64 v153; // x8
  int v154; // w5
  __int64 v155; // x23
  unsigned int v156; // w0
  __int64 v157; // x9
  char v158; // w10
  __int64 v159; // x9
  __int64 v160; // x10
  bool v161; // w9
  void (__fastcall *v162)(__int64, __int64 *); // x8
  __int64 v163; // x23
  unsigned int v164; // w24
  long double v165; // q0
  int v166; // w4
  __int64 v167; // x8
  int v168; // w5
  void (__fastcall *v169)(__int64, __int64 *, long double); // x8
  int v170; // w4
  __int64 v171; // x8
  int v172; // w5
  void (__fastcall *v173)(__int64, __int64 *); // x8
  __int64 v174; // x24
  unsigned int v175; // w0
  int v176; // w4
  __int64 v177; // x8
  int v178; // w5
  __int64 v179; // x22
  __int64 v180; // x26
  __int64 v181; // x25
  __int64 v182; // x20
  int v183; // w8
  __int64 v184; // x9
  _WORD *v185; // x8
  _BOOL4 v186; // w8
  unsigned int v187; // w23
  __int64 v188; // x8
  int v189; // w11
  __int64 v190; // x10
  __int64 v191; // x11
  __int64 v192; // x12
  int v193; // w10
  unsigned int v194; // w11
  __int64 v195; // x12
  __int64 v196; // x9
  __int64 v197; // x28
  __int64 v198; // x9
  __int64 v199; // x23
  __int64 v200; // x10
  __int64 v201; // x11
  unsigned int v202; // w9
  unsigned int v203; // w10
  __int64 v204; // x11
  _DWORD *v205; // x8
  void (__fastcall *v206)(_QWORD); // x9
  __int64 v207; // x10
  int v208; // w10
  void (__fastcall *v209)(__int64, __int64); // x10
  __int64 v210; // x1
  void (__fastcall *v211)(__int64, __int64, __int64); // x8
  __int64 v212; // x2
  void (*v213)(void); // x8
  __int64 v214; // x22
  __int64 v215; // x24
  __int64 v216; // x20
  unsigned int v217; // w0
  long double v218; // q0
  __int64 v219; // x8
  unsigned int v220; // w23
  __int64 v221; // x8
  int v222; // w4
  unsigned int v223; // w23
  __int64 v224; // x8
  int v225; // w26
  unsigned int v226; // w27
  int v227; // w8
  void (__fastcall *v228)(__int64, __int64 *); // x8
  __int64 v229; // x8
  int v230; // w4
  __int64 v231; // x21
  __int64 v232; // x22
  unsigned int v233; // w0
  int v234; // w6
  int v235; // w4
  __int64 v236; // x9
  unsigned int v237; // w23
  int v238; // w5
  _DWORD *v239; // x8
  __int64 v240; // x21
  __int64 v241; // x22
  __int64 v242; // x20
  unsigned int v243; // w0
  unsigned int v244; // w22
  __int64 v245; // x26
  unsigned __int64 v246; // x27
  __int64 *v247; // x23
  int v248; // w5
  void (__fastcall *v249)(__int64, __int64 *, __int64); // x8
  __int64 v250; // x2
  __int64 v251; // x25
  void (__fastcall *v252)(__int64, __int64 *); // x8
  void (__fastcall *v253)(__int64, __int64, __int64, __int64); // x8
  __int64 v254; // x3
  __int64 v255; // x2
  int v256; // w4
  __int64 v257; // x8
  _DWORD *v258; // x8
  int v259; // w4
  __int64 v260; // x8
  int v261; // w5
  unsigned int v262; // w0
  long double v263; // q0
  __int64 v264; // x20
  __int64 v265; // x23
  __int64 v266; // x25
  __int64 v267; // x24
  unsigned int v268; // w22
  __int64 v269; // x21
  int v270; // w4
  __int64 v271; // x8
  int v272; // w5
  __int64 v273; // x4
  __int64 v274; // x8
  __int64 v275; // x5
  __int64 v276; // x26
  _DWORD *v277; // x8
  __int64 v278; // x2
  void (__fastcall *v279)(__int64, __int64, __int64, __int64); // x8
  __int64 v280; // x2
  __int64 v281; // x9
  __int64 v282; // x2
  __int64 v283; // x22
  void (__fastcall *v284)(__int64, __int64, __int64, long double); // x8
  __int64 v285; // x1
  void (__fastcall *v286)(__int64, __int64 *, long double); // x8
  int v287; // w4
  __int64 v288; // x8
  int v289; // w5
  __int64 v290; // x4
  __int64 v291; // x8
  int v292; // w4
  unsigned int v293; // w20
  __int64 v294; // x8
  int v295; // w5
  void (__fastcall *v297)(__int64, __int64 *, __int64); // x8
  char v298; // [xsp+0h] [xbp-130h]
  char v299[4]; // [xsp+74h] [xbp-BCh]
  unsigned int v300; // [xsp+78h] [xbp-B8h]
  __int64 v301; // [xsp+78h] [xbp-B8h]
  __int64 v302; // [xsp+80h] [xbp-B0h] BYREF
  char v303[8]; // [xsp+88h] [xbp-A8h] BYREF
  unsigned __int64 v304; // [xsp+90h] [xbp-A0h]
  __int64 v305; // [xsp+98h] [xbp-98h]
  unsigned __int64 v306; // [xsp+A0h] [xbp-90h]
  __int64 v307; // [xsp+A8h] [xbp-88h] BYREF
  __int64 v308; // [xsp+B0h] [xbp-80h]
  __int64 v309; // [xsp+B8h] [xbp-78h]
  __int64 v310; // [xsp+C0h] [xbp-70h]
  __int64 v311; // [xsp+C8h] [xbp-68h]
  __int64 v312; // [xsp+D0h] [xbp-60h]
  __int64 v313; // [xsp+D8h] [xbp-58h]
  __int64 v314; // [xsp+E0h] [xbp-50h]
  __int64 v315; // [xsp+E8h] [xbp-48h]
  __int64 v316; // [xsp+F0h] [xbp-40h]
  _QWORD v317[7]; // [xsp+F8h] [xbp-38h] BYREF

  v317[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v3 = *(_DWORD *)(a2 + 12);
  else
    v3 = 0;
  v4 = *((_BYTE *)a1 + 2290);
  v5 = 0;
  *((_DWORD *)a1 + 583) = v3;
  if ( (v4 & 1) == 0 && !v3 )
  {
    if ( *((_DWORD *)a1 + 219) )
    {
      v5 = sde_encoder_phys_wb_wait_for_idle(a1, 1);
      if ( v5 )
        *((_DWORD *)a1 + 219) = 0;
    }
    else
    {
      v5 = 0;
    }
  }
  v6 = a1[353];
  v7 = a1[77];
  v8 = a1[367];
  a1[354] = a1[352];
  v9 = a1[78];
  a1[355] = v6;
  v10 = a1[79];
  v317[2] = v7;
  v317[3] = v9;
  v11 = a1[73];
  v12 = a1[76];
  v317[4] = v10;
  v13 = a1[74];
  v14 = *(__int64 **)(v8 + 2008);
  *(_DWORD *)v299 = v5;
  v315 = v11;
  v316 = v13;
  v15 = a1[75];
  v16 = a1[69];
  v302 = 0;
  v317[0] = v15;
  v317[1] = v12;
  v17 = a1[70];
  v18 = a1[72];
  v311 = v16;
  v312 = v17;
  v19 = a1[65];
  v313 = a1[71];
  v314 = v18;
  v20 = a1[66];
  v21 = a1[68];
  v307 = v19;
  v308 = v20;
  v22 = a1[1];
  v309 = a1[67];
  v310 = v21;
  v23 = *(__int64 **)(v22 + 2512);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v24 = *(_DWORD *)(*a1 + 24);
      if ( !a1 )
        goto LABEL_17;
    }
    else
    {
      v24 = -1;
      if ( !a1 )
        goto LABEL_17;
    }
    v25 = a1[358];
    if ( v25 )
    {
      v26 = *(_DWORD *)(v25 + 12) - 1;
LABEL_18:
      _drm_dev_dbg(
        0,
        0,
        0,
        "[enc:%d wb:%d] mode_set:\"%s\",%d,%d]\n",
        v24,
        v26,
        (const char *)v317,
        WORD2(v307),
        HIWORD(v308));
      goto LABEL_19;
    }
LABEL_17:
    v26 = -1;
    goto LABEL_18;
  }
LABEL_19:
  v27 = *((_DWORD *)a1 + 208);
  a1[350] = 0;
  a1[352] = 0;
  a1[353] = 0;
  if ( v27 )
  {
    output_fb = sde_wb_get_output_fb(a1[358]);
    sde_wb_get_output_roi(a1[358], (_WORD *)a1 + 1400);
    if ( output_fb )
      goto LABEL_21;
LABEL_31:
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_478;
    if ( *a1 )
    {
      v36 = *(_DWORD *)(*a1 + 24);
      if ( !a1 )
        goto LABEL_130;
    }
    else
    {
      v36 = -1;
      if ( !a1 )
        goto LABEL_130;
    }
    v98 = a1[358];
    if ( v98 )
    {
      v99 = *(_DWORD *)(v98 + 12) - 1;
LABEL_131:
      _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] no out fb\n", v36, v99);
      goto LABEL_478;
    }
LABEL_130:
    v99 = -1;
    goto LABEL_131;
  }
  output_fb = a1[363];
  *((_DWORD *)a1 + 701) = 0;
  if ( !output_fb )
    goto LABEL_31;
LABEL_21:
  num_datapath = sde_crtc_get_num_datapath(*v14, *v23, (__int64)v14);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[fb_id:%u][fb:%u,%u]\n",
      *(_DWORD *)(output_fb + 24),
      *(_DWORD *)(output_fb + 128),
      *(_DWORD *)(output_fb + 132));
  sde_enc_phys_wb_get_out_resolution(v14, v23, (char *)&v302 + 4, &v302, v29);
  v31 = *((unsigned __int16 *)a1 + 1402);
  if ( !*((_WORD *)a1 + 1402) || !*((_WORD *)a1 + 1403) )
  {
    v31 = WORD2(v302);
    v32 = v302;
    *((_DWORD *)a1 + 700) = 0;
    *((_WORD *)a1 + 1402) = v31;
    *((_WORD *)a1 + 1403) = v32;
  }
  *((_DWORD *)a1 + 573) = 0;
  if ( num_datapath == 4 )
  {
    v33 = *((unsigned __int16 *)a1 + 1400);
    v34 = HIDWORD(v302) >> 1;
    if ( HIDWORD(v302) >> 1 == v33 && v33 == v31 )
    {
      v35 = 3;
LABEL_41:
      *((_DWORD *)a1 + 573) = v35;
      goto LABEL_42;
    }
    if ( v33 == HIDWORD(v302) >> 2 && v34 == v31 )
    {
      v35 = 2;
      goto LABEL_41;
    }
    if ( !*((_WORD *)a1 + 1400) && v34 == v31 )
    {
      v35 = 1;
      goto LABEL_41;
    }
  }
LABEL_42:
  sde_format_ext = sde_get_sde_format_ext(**(_DWORD **)(output_fb + 72), *(_QWORD *)(output_fb + 120));
  a1[351] = (__int64)sde_format_ext;
  if ( !sde_format_ext )
  {
    printk(&unk_232CA2, "sde_encoder_phys_wb_setup");
    goto LABEL_478;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v38 = *(_DWORD *)(*a1 + 24);
      if ( !a1 )
        goto LABEL_50;
    }
    else
    {
      v38 = -1;
      if ( !a1 )
        goto LABEL_50;
    }
    v39 = a1[358];
    if ( v39 )
    {
      v40 = *(_DWORD *)(v39 + 12) - 1;
LABEL_51:
      _drm_dev_dbg(
        0,
        0,
        0,
        "[enc:%d enc:%d] fb_id:%u, wxh:%ux%u, fb_fmt:%x,%llx, roi:{%d,%d,%d,%d}\n",
        v38,
        v40,
        *(_DWORD *)(output_fb + 24),
        *(_DWORD *)(output_fb + 128),
        *(_DWORD *)(output_fb + 132),
        **(_DWORD **)(output_fb + 72),
        *(_QWORD *)(output_fb + 120),
        *((unsigned __int16 *)a1 + 1400),
        *((unsigned __int16 *)a1 + 1401),
        *((unsigned __int16 *)a1 + 1402),
        *((unsigned __int16 *)a1 + 1403));
      goto LABEL_52;
    }
LABEL_50:
    v40 = -1;
    goto LABEL_51;
  }
LABEL_52:
  if ( *a1 )
  {
    v41 = *(_DWORD *)(*a1 + 24);
    if ( !a1 )
      goto LABEL_58;
  }
  else
  {
    v41 = -1;
    if ( !a1 )
      goto LABEL_58;
  }
  v42 = a1[358];
  if ( v42 )
  {
    v43 = *(_DWORD *)(v42 + 12) - 1;
    goto LABEL_59;
  }
LABEL_58:
  v43 = -1;
LABEL_59:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_wb_setup",
    1967,
    -1,
    v41,
    v43,
    **(_DWORD **)(output_fb + 72),
    *((unsigned __int16 *)a1 + 1400),
    *((_WORD *)a1 + 1401));
  v44 = a1[335];
  v45 = *(_QWORD *)(a1[1] + 2512);
  if ( v45 )
    v46 = *(_DWORD *)(v45 + 1856) == 0;
  else
    v46 = 1;
  v47 = *(_QWORD *)(v44 + 56);
  v48 = *((unsigned __int16 *)a1 + 1402);
  v49 = *((unsigned __int16 *)a1 + 1403);
  v50 = *(_DWORD *)(v44 + 48);
  HIDWORD(v305) = 0;
  LODWORD(v47) = *(_DWORD *)(v47 + 76);
  BYTE5(v305) = v46;
  v304 = __PAIR64__(v49, v48);
  *(_DWORD *)v303 = v47;
  *(_DWORD *)&v303[4] = v50 - 1;
  v51 = drm_mode_vrefresh(a1 + 65);
  v52 = *(_QWORD *)(v44 + 56);
  LODWORD(v305) = v51;
  v53 = a1[64];
  BYTE4(v305) = 0;
  v306 = __PAIR64__(*(_DWORD *)(v52 + 80), *(_DWORD *)(v52 + 72));
  sde_vbif_set_ot_limit(v53, (unsigned int *)v303, v54, v55);
  if ( !a1 )
  {
    printk(&unk_26FEB0, "sde_encoder_phys_wb_set_qos_remap");
    v305 = 0;
    v306 = 0;
LABEL_136:
    printk(&unk_247128, "sde_encoder_phys_wb_set_qos");
    goto LABEL_137;
  }
  v56 = *a1;
  if ( !*a1 || !*(_QWORD *)(v56 + 80) )
  {
    printk(&unk_26FEB0, "sde_encoder_phys_wb_set_qos_remap");
    goto LABEL_85;
  }
  if ( !a1[367] )
  {
    printk(&unk_217125, "sde_encoder_phys_wb_set_qos_remap");
    goto LABEL_85;
  }
  v57 = *(_QWORD *)(a1[1] + 2512);
  if ( v57 )
  {
    v58 = *(_DWORD *)(v57 + 1856);
    v59 = a1[335];
    if ( !v59 )
      goto LABEL_133;
  }
  else
  {
    v58 = 0;
    v59 = a1[335];
    if ( !v59 )
    {
LABEL_133:
      printk(&unk_22BD6A, "sde_encoder_phys_wb_set_qos_remap");
      goto LABEL_85;
    }
  }
  v60 = *(_DWORD **)(v59 + 56);
  if ( !v60 )
    goto LABEL_133;
  v61 = *(_DWORD *)(v59 + 48);
  if ( v58 == 3 )
    v62 = 6;
  else
    v62 = 1;
  v63 = v60[18];
  v64 = v60[19];
  v65 = v60[20];
  if ( v58 == 2 )
    v66 = 5;
  else
    v66 = v62;
  if ( *((_BYTE *)a1 + 2290) )
    v66 = 2;
  *(_DWORD *)v303 = v63;
  *(_DWORD *)&v303[4] = v64;
  LODWORD(v304) = v65;
  HIDWORD(v304) = v61 - 1;
  LODWORD(v305) = v66;
  if ( (_drm_debug & 4) != 0 )
  {
    v67 = a1[358];
    if ( v67 )
      v68 = *(_DWORD *)(v67 + 12) - 1;
    else
      v68 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[enc:%d wb:%d] qos_remap - wb:%d vbif:%d xin:%d clone:%d\n",
      *(_DWORD *)(v56 + 24),
      v68,
      v61 - 1,
      v63,
      v64,
      v66);
  }
  sde_vbif_set_qos_remap(a1[64], (int *)v303);
LABEL_85:
  v69 = a1[64];
  v305 = 0;
  v306 = 0;
  if ( !v69 || !*(_QWORD *)(v69 + 152) )
    goto LABEL_136;
  disp_op = sde_encoder_get_disp_op(*a1);
  if ( a1[335] )
  {
    v71 = disp_op;
    v72 = *(_QWORD *)(a1[1] + 2512);
    if ( v72 )
      v73 = *(_DWORD *)(v72 + 1856);
    else
      v73 = 0;
    v74 = *(_QWORD *)(a1[64] + 152);
    v75 = drm_mode_vrefresh(a1 + 65);
    v78 = a1[335];
    v79 = *(unsigned int *)(v74 + 21824);
    if ( (_DWORD)v79 )
    {
      v80 = *(_QWORD *)(v74 + 21832);
      if ( v80 )
      {
        v81 = 0;
        while ( (_DWORD)v79 - 1 != v81 && v75 > *(_DWORD *)(v80 + 4 * v81) )
        {
          if ( v79 == ++v81 )
          {
            LODWORD(v81) = *(_DWORD *)(v74 + 21824);
            break;
          }
        }
      }
      else
      {
        LODWORD(v81) = 0;
      }
      LODWORD(v79) = 18 * v81;
    }
    LOBYTE(v306) = 1;
    if ( v73 == 3 )
    {
      HIDWORD(v305) = 1;
      if ( v72 )
        v82 = *(_DWORD *)(v72 + 1920);
      else
        v82 = 0;
      v83 = *((unsigned __int8 *)a1 + 2290);
      LODWORD(v305) = v82;
      if ( (v83 & 1) == 0 )
      {
        v85 = 16;
        goto LABEL_115;
      }
    }
    else
    {
      v83 = *((unsigned __int8 *)a1 + 2290);
      if ( v83 != 1 )
      {
        v84 = v73 == 2;
        v85 = 4;
        v86 = 14;
        goto LABEL_110;
      }
    }
    v87 = a1[351];
    if ( *(_DWORD *)(v87 + 28) != 2 )
    {
      v85 = 6;
      goto LABEL_115;
    }
    v85 = 8;
    if ( (*(_QWORD *)(v87 + 32) & 4) == 0 )
      goto LABEL_115;
    v84 = (*(_QWORD *)(v87 + 32) & 4LL) == 0;
    v86 = 6;
LABEL_110:
    if ( v84 )
      v85 = v86;
LABEL_115:
    v88 = *(_QWORD *)(v74 + 21808);
    v89 = 8LL * (unsigned int)(v85 + v79);
    v90 = *(_QWORD *)(v74 + 21800);
    v91 = *(_QWORD *)(*(_QWORD *)(v74 + 21816) + v89);
    v304 = v91;
    v92 = *(_DWORD *)(v90 + v89);
    *(_DWORD *)v303 = v92;
    v93 = *(_DWORD *)(v88 + v89);
    *(_DWORD *)&v303[4] = v93;
    if ( (_drm_debug & 4) == 0 )
    {
LABEL_122:
      if ( v71 > 2 )
        goto LABEL_543;
      v97 = *(void (__fastcall **)(__int64, char *, long double))(v78 + 8LL * v71 + 280);
      if ( v97 )
      {
        if ( *((_DWORD *)v97 - 1) != -1459002633 )
          __break(0x8228u);
        v97(v78, v303, v77);
      }
LABEL_137:
      ((void (__fastcall *)(__int64 *, __int64, __int64, __int64 *, long double))sde_encoder_phys_setup_cdm)(
        a1,
        v76,
        a1[351],
        a1 + 350,
        v77);
      if ( !a1 )
      {
        printk(&unk_247128, "_sde_encoder_is_single_lm_partial_update");
        sde_encoder_phys_wb_setup_cwb(0, 0, v103);
        printk(&unk_26FCAB, "sde_encoder_phys_wb_setup_fb");
        printk(&unk_26FCAB, "_sde_encoder_phys_wb_setup_ctl");
        goto LABEL_385;
      }
      v101 = a1[367];
      if ( !v101 )
        goto LABEL_156;
      goto LABEL_139;
    }
    if ( *a1 )
    {
      v94 = *(_DWORD *)(*a1 + 24);
      v95 = a1[358];
      if ( v95 )
      {
LABEL_118:
        v96 = *(_DWORD *)(v95 + 12) - 1;
LABEL_121:
        *(double *)&v77 = _drm_dev_dbg(
                            0,
                            0,
                            0,
                            "[enc:%d wb:%d] fps:%d mode:%d type:%d luts[0x%x,0x%x 0x%llx]\n",
                            v94,
                            v96,
                            v75,
                            v83,
                            v73,
                            v92,
                            v93,
                            v91);
        goto LABEL_122;
      }
    }
    else
    {
      v94 = -1;
      v95 = a1[358];
      if ( v95 )
        goto LABEL_118;
    }
    v96 = -1;
    goto LABEL_121;
  }
  printk(&unk_22BD6A, "sde_encoder_phys_wb_set_qos");
  ((void (__fastcall *)(__int64 *, __int64, __int64, __int64 *))sde_encoder_phys_setup_cdm)(a1, v104, a1[351], a1 + 350);
  v101 = a1[367];
  if ( !v101 )
    goto LABEL_156;
LABEL_139:
  v102 = *(_WORD **)(v101 + 2008);
  if ( !v102 )
  {
LABEL_156:
    printk(&unk_247128, "_sde_encoder_is_single_lm_partial_update");
    goto LABEL_157;
  }
  if ( *(_DWORD *)(v101 + 2192) != 2 )
  {
LABEL_157:
    sde_encoder_phys_wb_setup_cwb(a1, 0, v100);
    goto LABEL_158;
  }
  if ( !v102[280] )
  {
    if ( v102 == (_WORD *)-564LL )
      goto LABEL_158;
LABEL_150:
    if ( v102[284] && v102[285] )
      goto LABEL_157;
    goto LABEL_158;
  }
  if ( !v102[281] )
  {
    if ( v102 == (_WORD *)-564LL )
      goto LABEL_158;
    goto LABEL_150;
  }
  if ( v102 == (_WORD *)-564LL || !v102[284] || !v102[285] )
    goto LABEL_157;
LABEL_158:
  v105 = a1[64];
  if ( !v105 || !*(_QWORD *)(v105 + 152) || (v106 = a1[1]) == 0 )
  {
    printk(&unk_26FCAB, "sde_encoder_phys_wb_setup_fb");
    goto LABEL_276;
  }
  v107 = *((_DWORD *)a1 + 167);
  a1[346] = 0;
  a1[348] = 0;
  a1[347] = 0;
  a1[345] = 0;
  a1[344] = 0;
  a1[343] = 0;
  a1[342] = 0;
  a1[341] = 0;
  a1[340] = 0;
  a1[339] = 0;
  a1[338] = 0;
  a1[337] = 0;
  *((_DWORD *)a1 + 692) = v107;
  v109 = v302;
  v108 = HIDWORD(v302);
  v110 = *(_QWORD *)(v106 + 2512);
  if ( v110 )
    LODWORD(v110) = *(_DWORD *)(v110 + 1504);
  v111 = *((_DWORD *)a1 + 208) != 0 && (_DWORD)v110 == 1;
  v112 = 356;
  if ( v111 )
    v112 = 357;
  *((_BYTE *)a1 + 2788) = v111;
  v113 = a1[v112];
  if ( (unsigned int)msm_framebuffer_prepare(output_fb, v113) )
  {
    printk(&unk_21AD0E, "sde_encoder_phys_wb_setup_fb");
    goto LABEL_276;
  }
  a1[352] = output_fb;
  a1[353] = v113;
  drm_mode_object_get(output_fb + 24);
  v114 = (const char *)msm_framebuffer_format(output_fb);
  if ( !v114 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_276;
    if ( *a1 )
    {
      v119 = *(_DWORD *)(*a1 + 24);
      v120 = a1[358];
      if ( v120 )
      {
LABEL_172:
        v121 = *(_DWORD *)(v120 + 12) - 1;
LABEL_218:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] invalid fb fmt\n", v119, v121);
        goto LABEL_276;
      }
    }
    else
    {
      v119 = -1;
      v120 = a1[358];
      if ( v120 )
        goto LABEL_172;
    }
    v121 = -1;
    goto LABEL_218;
  }
  v115 = a1[1];
  v116 = (int *)v114;
  v117 = *(_QWORD *)(v115 + 2512);
  if ( v117 )
    v118 = *(_QWORD *)(v117 + 1888);
  else
    LODWORD(v118) = 0;
  v122 = _drm_debug;
  *((_BYTE *)a1 + 2789) = (_DWORD)v118 != 0;
  if ( (v122 & 4) != 0 )
  {
    if ( *a1 )
    {
      v123 = *(_DWORD *)(*a1 + 24);
      v124 = a1[358];
      if ( v124 )
        goto LABEL_177;
    }
    else
    {
      v123 = -1;
      v124 = a1[358];
      if ( v124 )
      {
LABEL_177:
        v125 = *(_DWORD *)(v124 + 12) - 1;
        if ( v115 )
        {
LABEL_178:
          v126 = *(_DWORD *)(v115 + 64);
LABEL_183:
          _drm_dev_dbg(
            0,
            0,
            0,
            "[enc:%d wb:%d] conn:%d rotation_type:%d format %4.4s and modifier 0x%llX\n",
            v123,
            v125,
            v126,
            v118,
            v114,
            *(_QWORD *)(output_fb + 120));
          goto LABEL_184;
        }
LABEL_182:
        v126 = -1;
        goto LABEL_183;
      }
    }
    v125 = -1;
    if ( v115 )
      goto LABEL_178;
    goto LABEL_182;
  }
LABEL_184:
  if ( *a1 )
    v127 = *(_DWORD *)(*a1 + 24);
  else
    v127 = -1;
  v128 = a1[358];
  if ( v128 )
    v129 = *(_DWORD *)(v128 + 12) - 1;
  else
    v129 = -1;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_phys_wb_setup_fb", 603, -1, v127, v129, v118, v108, v109);
  v130 = sde_get_sde_format_ext(*v116, *(_QWORD *)(output_fb + 120));
  a1[337] = (__int64)v130;
  if ( !v130 )
  {
    printk(&unk_266A8C, "sde_encoder_phys_wb_setup_fb");
    goto LABEL_276;
  }
  *(__int64 *)((char *)a1 + 2772) = a1[350];
  v131 = sde_format_populate_layout(v113, (_DWORD *)output_fb, a1 + 337);
  if ( v131 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_276;
    if ( *a1 )
    {
      v132 = *(_DWORD *)(*a1 + 24);
      v133 = a1[358];
      if ( v133 )
      {
LABEL_195:
        v134 = *(_DWORD *)(v133 + 12) - 1;
LABEL_221:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] failed to populate layout; ret:%d\n", v132, v134, v131);
        goto LABEL_276;
      }
    }
    else
    {
      v132 = -1;
      v133 = a1[358];
      if ( v133 )
        goto LABEL_195;
    }
    v134 = -1;
    goto LABEL_221;
  }
  *((_DWORD *)a1 + 677) = *(_DWORD *)(output_fb + 128);
  v135 = a1[337];
  *((_DWORD *)a1 + 678) = *(_DWORD *)(output_fb + 132);
  *((_DWORD *)a1 + 676) = *(unsigned __int8 *)(v135 + 25);
  if ( *(_DWORD *)(v135 + 4) == 1 && *(_BYTE *)(v135 + 8) == 1 )
  {
    v136 = *((_DWORD *)a1 + 681);
    *((_DWORD *)a1 + 681) = *((_DWORD *)a1 + 682);
    *((_DWORD *)a1 + 682) = v136;
  }
  v137 = a1[367];
  v138 = *a1;
  v139 = a1[335];
  *(_QWORD *)v303 = 0;
  v140 = *(_QWORD *)(v137 + 2008);
  v141 = sde_encoder_get_disp_op(v138);
  if ( v140 )
  {
    v142 = *(_DWORD *)(v140 + 1472);
    if ( v141 > 2 )
      goto LABEL_543;
  }
  else
  {
    v142 = 0;
    if ( v141 > 2 )
      goto LABEL_543;
  }
  v143 = *(void (__fastcall **)(__int64, __int64 *))(v139 + 232 + 8LL * v141);
  if ( v143 )
  {
    v144 = v139 + 256;
    if ( *(_QWORD *)(v139 + 256 + 8LL * v141) && *((_BYTE *)a1 + 2290) == 1 )
    {
      v300 = v141;
      v145 = *(_QWORD *)(a1[1] + 2512);
      *((_DWORD *)a1 + 695) = *((_DWORD *)a1 + 693);
      if ( *(_DWORD *)(v140 + 620) || *(_DWORD *)(v145 + 2048) )
      {
        v146 = 0;
        if ( v140 && v145 )
        {
          v147 = (unsigned int *)(v145 + 2048);
          if ( !v142 )
            v147 = (unsigned int *)(v140 + 620);
          v148 = v141;
          sde_kms_rect_merge_rectangles(v147, (__int64)v303);
          v146 = *(unsigned __int16 *)&v303[4];
          v141 = v148;
        }
        if ( *((unsigned __int16 *)a1 + 1388) == v146
          && *((unsigned __int16 *)a1 + 1389) == *(unsigned __int16 *)&v303[6] )
        {
          v149 = 0;
        }
        else
        {
          v149 = 1;
          v150 = *((_WORD *)a1 + 1391) - *(_WORD *)&v303[2];
          *((_WORD *)a1 + 1390) -= *(_WORD *)v303;
          *((_WORD *)a1 + 1391) = v150;
        }
        v151 = *(_DWORD **)(v144 + 8LL * v141);
        if ( *(v151 - 1) != 1313938762 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64 *, _QWORD))v151)(v139, a1 + 337, v149);
        *((_DWORD *)a1 + 693) = 0;
      }
      else if ( v108 == *((unsigned __int16 *)a1 + 1388) && v109 == *((unsigned __int16 *)a1 + 1389)
             || *((_DWORD *)a1 + 573) )
      {
        v205 = *(_DWORD **)(v144 + 8LL * v141);
        if ( *(v205 - 1) != 1313938762 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64 *, _QWORD))v205)(v139, a1 + 337, 0);
      }
      else
      {
        v297 = *(void (__fastcall **)(__int64, __int64 *, __int64))(v144 + 8LL * v141);
        if ( *((_DWORD *)v297 - 1) != 1313938762 )
          __break(0x8228u);
        v297(v139, a1 + 337, 1);
      }
      if ( *((_DWORD *)a1 + 677) < v108 || *((_DWORD *)a1 + 678) < v109 )
        *((_DWORD *)a1 + 693) = 0;
      if ( *a1 )
        v152 = *(_DWORD *)(*a1 + 24);
      else
        v152 = -1;
      v153 = a1[358];
      if ( v153 )
        v154 = *(_DWORD *)(v153 + 12) - 1;
      else
        v154 = -1;
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_phys_wb_setup_roi",
        499,
        -1,
        v152,
        v154,
        *((unsigned __int16 *)a1 + 1390),
        *((unsigned __int16 *)a1 + 1391),
        v303[0]);
      v143 = *(void (__fastcall **)(__int64, __int64 *))(v139 + 232 + 8LL * v300);
    }
    if ( *((_DWORD *)v143 - 1) != 1754914647 )
      __break(0x8228u);
    v143(v139, a1 + 337);
  }
  v155 = a1[335];
  v156 = sde_encoder_get_disp_op(*a1);
  if ( v156 >= 3 )
LABEL_543:
    __break(0x5512u);
  if ( *(_QWORD *)(v155 + 304 + 8LL * v156) )
  {
    v157 = a1[64];
    a1[349] = 0;
    v158 = *(_BYTE *)(*(_QWORD *)(v157 + 152) + 2 * (*((unsigned __int8 *)a1 + 2290) ^ 1LL) + 21841);
    v159 = a1[337];
    *((_BYTE *)a1 + 2792) = v158;
    if ( *(_DWORD *)(v159 + 28) == 2 )
      v160 = (*(_QWORD *)(v159 + 32) >> 2) & 1LL;
    else
      LOBYTE(v160) = 0;
    *((_BYTE *)a1 + 2793) = v160;
    v161 = *(_DWORD *)(v159 + 28) == 2 && ((*(_QWORD *)(v159 + 32) & 4) != 0 || (*(_QWORD *)(v159 + 32) & 4LL) == 0);
    *((_BYTE *)a1 + 2794) = v161;
    *((_DWORD *)a1 + 699) = 1;
    v162 = *(void (__fastcall **)(__int64, __int64 *))(v155 + 304 + 8LL * v156);
    if ( *((_DWORD *)v162 - 1) != -1415308130 )
      __break(0x8228u);
    v162(v155, a1 + 349);
  }
  v163 = a1[335];
  v164 = sde_encoder_get_disp_op(*a1);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v166 = *(_DWORD *)(*a1 + 24);
      v167 = a1[358];
      if ( v167 )
      {
LABEL_257:
        v168 = *(_DWORD *)(v167 + 12) - 1;
        goto LABEL_260;
      }
    }
    else
    {
      v166 = -1;
      v167 = a1[358];
      if ( v167 )
        goto LABEL_257;
    }
    v168 = -1;
LABEL_260:
    *(double *)&v165 = _drm_dev_dbg(
                         0,
                         0,
                         0,
                         "[enc:%d wb:%d] [fb_offset:%8.8x,%8.8x,%8.8x,%8.8x], fb_sec:%d\n",
                         v166,
                         v168,
                         *((_DWORD *)a1 + 680),
                         *((_DWORD *)a1 + 681),
                         *((_DWORD *)a1 + 682),
                         *((_DWORD *)a1 + 683),
                         *((unsigned __int8 *)a1 + 2788));
    if ( (_drm_debug & 4) != 0 )
      *(double *)&v165 = _drm_dev_dbg(
                           0,
                           0,
                           0,
                           "[fb_stride:%8.8x,%8.8x,%8.8x,%8.8x]\n",
                           *((_DWORD *)a1 + 688),
                           *((_DWORD *)a1 + 689),
                           *((_DWORD *)a1 + 690),
                           *((_DWORD *)a1 + 691));
  }
  if ( v164 > 2 )
    goto LABEL_543;
  v169 = *(void (__fastcall **)(__int64, __int64 *, long double))(v163 + 8LL * v164 + 112);
  if ( v169 )
  {
    if ( *((_DWORD *)v169 - 1) != 1754914647 )
      __break(0x8228u);
    v169(v163, a1 + 337, v165);
  }
  if ( *(_QWORD *)(v163 + 88 + 8LL * v164) )
  {
    if ( *a1 )
    {
      v170 = *(_DWORD *)(*a1 + 24);
      v171 = a1[358];
      if ( v171 )
      {
LABEL_270:
        v172 = *(_DWORD *)(v171 + 12) - 1;
LABEL_273:
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_encoder_phys_wb_setup_out_cfg",
          530,
          -1,
          v170,
          v172,
          *((_DWORD *)a1 + 677),
          *((_DWORD *)a1 + 678),
          *((_DWORD *)a1 + 680));
        v173 = *(void (__fastcall **)(__int64, __int64 *))(v163 + 88 + 8LL * v164);
        if ( *((_DWORD *)v173 - 1) != 1754914647 )
          __break(0x8228u);
        v173(v163, a1 + 337);
        goto LABEL_276;
      }
    }
    else
    {
      v170 = -1;
      v171 = a1[358];
      if ( v171 )
        goto LABEL_270;
    }
    v172 = -1;
    goto LABEL_273;
  }
LABEL_276:
  v174 = a1[351];
  v175 = sde_encoder_get_disp_op(*a1);
  if ( *((_BYTE *)a1 + 2290) != 1 )
  {
    v179 = a1[335];
    v180 = a1[54];
    v181 = a1[63];
    v182 = a1[52];
    if ( *((_DWORD *)a1 + 573) )
    {
      v183 = 1;
      goto LABEL_299;
    }
    v184 = a1[367];
    if ( !v184 || (v185 = *(_WORD **)(v184 + 2008)) == nullptr )
    {
      v187 = v175;
      printk(&unk_247128, "_sde_encoder_is_single_lm_partial_update");
      v175 = v187;
      goto LABEL_297;
    }
    if ( *(_DWORD *)(v184 + 2192) != 2 )
    {
LABEL_297:
      v186 = 1;
      goto LABEL_298;
    }
    if ( v185[280] )
    {
      if ( v185[281] )
      {
        if ( v185 != (_WORD *)-564LL && v185[284] )
        {
          v186 = v185[285] == 0;
LABEL_298:
          v183 = !v186;
LABEL_299:
          if ( (*(_QWORD *)(*(_QWORD *)(v182 + 72) + 32LL) & 0x10) != 0 )
          {
            v196 = a1[52];
            if ( !v196 )
              goto LABEL_385;
            if ( v175 >= 3 )
              goto LABEL_543;
            v197 = v175;
            if ( *(_QWORD *)(v196 + 8LL * v175 + 880) )
            {
              LODWORD(v198) = *((_DWORD *)a1 + 208);
              v199 = a1[62];
              a1[87] = 0;
              a1[88] = 0;
              a1[89] = 0;
              a1[90] = 0;
              a1[91] = 0;
              a1[92] = 0;
              a1[93] = 0;
              a1[94] = 0;
              a1[95] = 0;
              a1[96] = 0;
              a1[97] = 0;
              a1[98] = 0;
              a1[99] = 0;
              if ( !(_DWORD)v198 || (v198 = a1[1]) == 0 )
              {
                LODWORD(v200) = 0;
                goto LABEL_362;
              }
              v200 = *(_QWORD *)(v198 + 2512);
              if ( !v200 )
                goto LABEL_361;
              v201 = a1[53];
              v202 = *(_DWORD *)(v200 + 2244);
              v203 = *(_DWORD *)(v200 + 2248);
              if ( !v201 || (*(_BYTE *)(v201 + 77) & 1) == 0 )
              {
                if ( *((_DWORD *)a1 + 166) )
                {
                  v204 = *a1;
                  if ( *a1 )
                  {
                    if ( *(_DWORD *)(v204 + 196) == 1 )
                    {
                      LODWORD(v204) = *(unsigned __int8 *)(v204 + 4936);
                      if ( (_DWORD)v204 == 1 && v202 == 2 && v203 < 2 )
                        goto LABEL_359;
                    }
                    else
                    {
                      LOBYTE(v204) = 0;
                    }
                  }
                  if ( (v204 & 1) != 0 || v202 != 4 )
                    goto LABEL_360;
                  goto LABEL_358;
                }
                if ( v202 == 2 )
                {
LABEL_358:
                  if ( v202 > v203 )
                  {
LABEL_359:
                    LODWORD(v198) = 2;
                    LODWORD(v200) = 1;
                    goto LABEL_362;
                  }
                }
              }
LABEL_360:
              LODWORD(v200) = 0;
LABEL_361:
              LODWORD(v198) = 0;
LABEL_362:
              *((_DWORD *)a1 + 179) = 1;
              *((_DWORD *)a1 + 180) = *(_DWORD *)(v179 + 48);
              if ( (*(_QWORD *)(v174 + 32) & 1) != 0 )
              {
                *((_DWORD *)a1 + 189) = 1;
                *((_DWORD *)a1 + 190) = *(_DWORD *)(v180 + 40);
              }
              if ( v181 )
              {
                *((_DWORD *)a1 + 198) = 1;
                *((_DWORD *)a1 + 199) = *(_DWORD *)(v181 + 40);
              }
              if ( ((unsigned int)v200 & v183) == 1 && v199 )
              {
                v207 = *(_QWORD *)(v199 + 56);
                if ( v207 )
                {
                  v208 = *(_DWORD *)(v207 + 32);
                  *((_DWORD *)a1 + 181) = 1;
                  *((_DWORD *)a1 + 182) = v208;
                }
              }
              else if ( !v199 )
              {
LABEL_382:
                v213 = *(void (**)(void))(a1[52] + 8 * v197 + 880);
                if ( *((_DWORD *)v213 - 1) != 836498625 )
                  __break(0x8228u);
                v213();
                goto LABEL_385;
              }
              v209 = *(void (__fastcall **)(__int64, __int64))(v199 + 8LL * v175 + 376);
              if ( v209 )
              {
                if ( v183 )
                  v210 = (unsigned int)v198;
                else
                  v210 = 0;
                if ( *((_DWORD *)v209 - 1) != -671500202 )
                  __break(0x822Au);
                v209(v199, v210);
              }
              v211 = *(void (__fastcall **)(__int64, __int64, __int64))(v179 + 8 * v197 + 328);
              if ( v211 )
              {
                v212 = *(unsigned int *)(v199 + 32);
                if ( *((_DWORD *)v211 - 1) != 1726930563 )
                  __break(0x8228u);
                v211(v179, 1, v212);
              }
              goto LABEL_382;
            }
          }
          v188 = a1[52];
          if ( !v188 )
            goto LABEL_385;
          if ( v175 > 2 )
            goto LABEL_543;
          if ( !*(_QWORD *)(v188 + 808 + 8LL * v175) )
            goto LABEL_385;
          *((_DWORD *)a1 + 173) = 0;
          v189 = *((_DWORD *)a1 + 208);
          *(__int64 *)((char *)a1 + 676) = 0;
          *(__int64 *)((char *)a1 + 684) = 0;
          *((_DWORD *)a1 + 170) = *(_DWORD *)(v179 + 48);
          if ( v189 )
          {
            v190 = a1[1];
            if ( !v190 )
            {
LABEL_352:
              *((_DWORD *)a1 + 171) = v190;
              v206 = *(void (__fastcall **)(_QWORD))(v188 + 808 + 8LL * v175);
              if ( *((_DWORD *)v206 - 1) != -1201655407 )
                __break(0x8229u);
              v206(v188);
              goto LABEL_385;
            }
            v191 = *(_QWORD *)(v190 + 2512);
            if ( v191 )
            {
              v192 = a1[53];
              v193 = *(_DWORD *)(v191 + 2244);
              v194 = *(_DWORD *)(v191 + 2248);
              if ( !v192 || (*(_BYTE *)(v192 + 77) & 1) == 0 )
              {
                if ( *((_DWORD *)a1 + 166) )
                {
                  v195 = *a1;
                  if ( *a1 )
                  {
                    if ( *(_DWORD *)(v195 + 196) == 1 )
                    {
                      LODWORD(v195) = *(unsigned __int8 *)(v195 + 4936);
                      if ( (_DWORD)v195 == 1 && v193 == 2 && v194 < 2 )
                        goto LABEL_350;
                    }
                    else
                    {
                      LOBYTE(v195) = 0;
                    }
                  }
                  if ( (v195 & 1) == 0 && v193 == 4 && v194 < 4 )
                  {
LABEL_350:
                    LODWORD(v190) = 2;
                    goto LABEL_352;
                  }
                }
                else if ( v193 == 2 && v194 < 2 )
                {
                  goto LABEL_350;
                }
              }
            }
          }
          LODWORD(v190) = 0;
          goto LABEL_352;
        }
        goto LABEL_297;
      }
      if ( v185 == (_WORD *)-564LL )
      {
LABEL_334:
        v186 = 0;
        goto LABEL_298;
      }
    }
    else if ( v185 == (_WORD *)-564LL )
    {
      goto LABEL_334;
    }
    if ( v185[284] )
    {
      v186 = v185[285] != 0;
      goto LABEL_298;
    }
    goto LABEL_334;
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v176 = *(_DWORD *)(*a1 + 24);
      v177 = a1[358];
      if ( v177 )
      {
LABEL_280:
        v178 = *(_DWORD *)(v177 + 12) - 1;
LABEL_293:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] in CWB mode. early return\n", v176, v178);
        goto LABEL_385;
      }
    }
    else
    {
      v176 = -1;
      v177 = a1[358];
      if ( v177 )
        goto LABEL_280;
    }
    v178 = -1;
    goto LABEL_293;
  }
LABEL_385:
  v214 = a1[335];
  v215 = a1[367];
  v216 = *(_QWORD *)(*(_QWORD *)(a1[358] + 96) + 2512LL);
  v217 = sde_encoder_get_disp_op(*a1);
  if ( !v214 )
    goto LABEL_394;
  if ( v217 >= 3 )
    goto LABEL_543;
  if ( !*(_QWORD *)(v214 + 424 + 8LL * v217) )
  {
LABEL_394:
    if ( !v217 && (_drm_debug & 4) != 0 )
    {
      if ( a1 && (v221 = a1[358]) != 0 )
        v222 = *(_DWORD *)(v221 + 12) - 1;
      else
        v222 = -1;
      *(double *)&v218 = _drm_dev_dbg(0, 0, 0, "unsupported ops: setup_sys_cache WB %d\n", v222);
    }
    goto LABEL_422;
  }
  if ( *((_BYTE *)a1 + 2290) == 1 )
  {
    v219 = *(_QWORD *)(v214 + 32);
    if ( (*(_QWORD *)(v219 + 21696) & 2) == 0
      || *((_DWORD *)a1 + 733)
      || (*(_QWORD *)(v219 + 22008) & 0x40000000000LL) != 0 )
    {
      v223 = v217;
      sde_core_perf_llcc_stale_frame(v215, 0);
      v217 = v223;
      v220 = 0;
    }
    else
    {
      v220 = 1;
    }
  }
  else
  {
    v220 = 2;
  }
  v224 = *(_QWORD *)(v214 + 32);
  if ( ((*(_QWORD *)(v224 + 21696) >> v220) & 1) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      *(double *)&v218 = _drm_dev_dbg(0, 0, 0, "sys cache type %d not enabled\n", v220);
    goto LABEL_422;
  }
  if ( v216 )
  {
    v225 = *(_DWORD *)(v216 + 1792);
    if ( (a1[364] & 1) != 0 )
    {
LABEL_408:
      v226 = v217;
      *((_DWORD *)a1 + 732) = 3;
      *((_BYTE *)a1 + 2912) = v225 != 0;
      if ( v225 )
      {
        v227 = *(_DWORD *)(v224 + 21624 + 24LL * v220 + 12);
        *((_DWORD *)a1 + 733) = v220;
        *((_DWORD *)a1 + 729) = v227;
        msm_framebuffer_set_cache_hint(output_fb, 1, v220, v220);
        *(_BYTE *)(v215 + v220 + 7560) = 1;
      }
      else
      {
        *((_DWORD *)a1 + 729) = 0;
        *((_DWORD *)a1 + 733) = 3;
        msm_framebuffer_set_cache_hint(output_fb, 0, 3, 3);
        if ( (*((_BYTE *)a1 + 2290) & 1) != 0 )
        {
LABEL_415:
          v228 = *(void (__fastcall **)(__int64, __int64 *))(v214 + 424 + 8LL * v226);
          if ( *((_DWORD *)v228 - 1) != 1904575617 )
            __break(0x8228u);
          v228(v214, a1 + 364);
          if ( a1 && (v229 = a1[358]) != 0 )
            v230 = *(_DWORD *)(v229 + 12) - 1;
          else
            v230 = -1;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_encoder_phys_wb_setup_sys_cache",
            1541,
            -1,
            v230,
            *((_DWORD *)a1 + 729),
            *((_DWORD *)a1 + 732),
            *((_DWORD *)a1 + 733),
            v225);
          goto LABEL_422;
        }
        *(_WORD *)(v215 + 7560) = 0;
        *(_BYTE *)(v215 + 7562) = 0;
      }
      sde_core_perf_crtc_update_llcc((__int64 *)a1[367]);
      goto LABEL_415;
    }
  }
  else
  {
    v225 = 0;
    if ( (a1[364] & 1) != 0 )
      goto LABEL_408;
  }
  if ( v225 )
    goto LABEL_408;
LABEL_422:
  sde_encoder_phys_wb_setup_cwb(a1, 1, v218);
  v231 = a1[335];
  v232 = *(_QWORD *)(*(_QWORD *)(a1[358] + 96) + 2512LL);
  v233 = sde_encoder_get_disp_op(*a1);
  if ( (*((_BYTE *)a1 + 2290) & 1) == 0 )
  {
    if ( v233 >= 3 )
      goto LABEL_543;
    if ( *(_QWORD *)(v231 + 496 + 8LL * v233) )
    {
      if ( v232 )
        LODWORD(v232) = *(_DWORD *)(v232 + 1280);
      v234 = *((_DWORD *)a1 + 736);
      if ( v234 != (_DWORD)v232 )
      {
        if ( *a1 )
        {
          v235 = *(_DWORD *)(*a1 + 24);
          if ( !a1 )
            goto LABEL_434;
        }
        else
        {
          v235 = -1;
          if ( !a1 )
            goto LABEL_434;
        }
        v236 = a1[358];
        if ( v236 )
        {
          v237 = v233;
          v238 = *(_DWORD *)(v236 + 12) - 1;
LABEL_435:
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_encoder_phys_wb_setup_prog_line",
            1886,
            -1,
            v235,
            v238,
            v234,
            v232,
            239);
          *((_DWORD *)a1 + 736) = v232;
          v239 = *(_DWORD **)(v231 + 496 + 8LL * v237);
          if ( *(v239 - 1) != -1533632034 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v239)(v231, (unsigned int)v232);
          goto LABEL_438;
        }
LABEL_434:
        v237 = v233;
        v238 = -1;
        goto LABEL_435;
      }
    }
  }
LABEL_438:
  v240 = a1[63];
  v241 = a1[64];
  v242 = a1[358];
  v301 = a1[62];
  v243 = sde_encoder_get_disp_op(*a1);
  if ( !*(_DWORD *)(*(_QWORD *)(v241 + 152) + 12624LL) || !v301 )
    goto LABEL_478;
  v244 = v243;
  v245 = *(_QWORD *)(*(_QWORD *)(v242 + 96) + 2512LL);
  if ( !*(_DWORD *)(v245 + 3264) )
  {
    *(_DWORD *)(v245 + 3952) = 1 - *(_DWORD *)(v245 + 3952);
    if ( !v240 )
      goto LABEL_478;
    if ( v243 > 2 )
      goto LABEL_543;
    v258 = *(_DWORD **)(v240 + 8LL * v243 + 48);
    if ( *(v258 - 1) != -204335525 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))v258)(v240, 0, 0);
    if ( *a1 )
    {
      v259 = *(_DWORD *)(*a1 + 24);
      if ( !a1 )
        goto LABEL_476;
    }
    else
    {
      v259 = -1;
      if ( !a1 )
        goto LABEL_476;
    }
    v260 = a1[358];
    if ( v260 )
    {
      v261 = *(_DWORD *)(v260 + 12) - 1;
LABEL_477:
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_encoder_phys_wb_setup_dnsc_blur",
        1847,
        -1,
        v259,
        v261,
        13107,
        -1059143953,
        v298);
      goto LABEL_478;
    }
LABEL_476:
    v261 = -1;
    goto LABEL_477;
  }
  if ( v240 )
  {
    if ( v243 >= 3 )
      goto LABEL_543;
    if ( *(_QWORD *)(v240 + 48 + 8LL * v243) )
    {
      v246 = 0;
      v247 = (__int64 *)(v245 + 3272);
      *(_DWORD *)(v245 + 3952) = 1 - *(_DWORD *)(v245 + 3952);
      while ( 1 )
      {
        if ( v246 == 2 )
          goto LABEL_543;
        v249 = *(void (__fastcall **)(__int64, __int64 *, __int64))(v240 + 48 + 8LL * v244);
        v250 = *(unsigned int *)(v245 + 3952);
        v251 = *v247;
        if ( *((_DWORD *)v249 - 1) != -204335525 )
          __break(0x8228u);
        v249(v240, v247, v250);
        v252 = *(void (__fastcall **)(__int64, __int64 *))(v240 + 72 + 8LL * v244);
        if ( v252 )
        {
          if ( *((_DWORD *)v252 - 1) != 403819499 )
            __break(0x8228u);
          v252(v240, v247);
        }
        v253 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v240 + 96 + 8LL * v244);
        if ( v253 )
        {
          v254 = *((unsigned __int8 *)a1 + 2290);
          v255 = *(unsigned int *)(v301 + 32);
          if ( *((_DWORD *)v253 - 1) != 1605504302 )
            __break(0x8228u);
          v253(v240, v251 & 1, v255, v254);
        }
        if ( *a1 )
        {
          v256 = *(_DWORD *)(*a1 + 24);
          if ( !a1 )
            goto LABEL_445;
        }
        else
        {
          v256 = -1;
          if ( !a1 )
            goto LABEL_445;
        }
        v257 = a1[358];
        if ( v257 )
        {
          v248 = *(_DWORD *)(v257 + 12) - 1;
          goto LABEL_446;
        }
LABEL_445:
        v248 = -1;
LABEL_446:
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_encoder_phys_wb_setup_dnsc_blur",
          1868,
          -1,
          v256,
          v248,
          *(_DWORD *)(v245 + 3264),
          *v247,
          *((_DWORD *)v247 + 7));
        ++v246;
        v247 += 85;
        if ( v246 >= *(unsigned int *)(v245 + 3264) )
          goto LABEL_478;
      }
    }
  }
  if ( !v243 )
    printk(&unk_21AD59, "_sde_encoder_phys_wb_setup_dnsc_blur");
LABEL_478:
  v313 = 0;
  v314 = 0;
  v311 = 0;
  v312 = 0;
  v309 = 0;
  v310 = 0;
  v307 = 0;
  v308 = 0;
  if ( !a1 )
    goto LABEL_530;
  v262 = sde_encoder_get_disp_op(*a1);
  v265 = a1[62];
  v264 = a1[63];
  v266 = a1[335];
  v267 = a1[54];
  v268 = v262;
  v269 = a1[52];
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v270 = *(_DWORD *)(*a1 + 24);
      v271 = a1[358];
      if ( v271 )
      {
LABEL_482:
        v272 = *(_DWORD *)(v271 + 12) - 1;
LABEL_485:
        *(double *)&v263 = _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d]\n", v270, v272);
        goto LABEL_486;
      }
    }
    else
    {
      v270 = -1;
      v271 = a1[358];
      if ( v271 )
        goto LABEL_482;
    }
    v272 = -1;
    goto LABEL_485;
  }
LABEL_486:
  if ( *((_BYTE *)a1 + 2290) == 1 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_530;
    if ( *a1 )
    {
      v273 = *(unsigned int *)(*a1 + 24);
      v274 = a1[358];
      if ( v274 )
      {
LABEL_490:
        v275 = (unsigned int)(*(_DWORD *)(v274 + 12) - 1);
LABEL_526:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] in CWB mode. early return\n", v273, v275, *(double *)&v263);
        goto LABEL_530;
      }
    }
    else
    {
      v273 = 0xFFFFFFFFLL;
      v274 = a1[358];
      if ( v274 )
        goto LABEL_490;
    }
    v275 = 0xFFFFFFFFLL;
    goto LABEL_526;
  }
  if ( !v269 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_530;
    if ( *a1 )
    {
      v290 = *(unsigned int *)(*a1 + 24);
      v291 = a1[358];
      if ( v291 )
      {
LABEL_523:
        _drm_dev_dbg(
          0,
          0,
          0,
          "[enc:%d wb:%d] invalid ctl\n",
          v290,
          (unsigned int)(*(_DWORD *)(v291 + 12) - 1),
          *(double *)&v263);
        goto LABEL_530;
      }
    }
    else
    {
      v290 = 0xFFFFFFFFLL;
      v291 = a1[358];
      if ( v291 )
        goto LABEL_523;
    }
    _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] invalid ctl\n", v290, 0xFFFFFFFFLL, *(double *)&v263);
    goto LABEL_530;
  }
  if ( v268 >= 3 )
    goto LABEL_543;
  v276 = v269 + 1192;
  v277 = *(_DWORD **)(v269 + 1192 + 8LL * v268);
  if ( v277 )
  {
    v278 = *(unsigned int *)(v266 + 48);
    if ( *(v277 - 1) != 949740941 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, long double))v277)(v269, 0, v278, 1, v263);
    v279 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v276 + 8LL * v268);
    if ( v279 && v267 )
    {
      v280 = *(unsigned int *)(v267 + 40);
      if ( *((_DWORD *)v279 - 1) != 949740941 )
        __break(0x8228u);
      v279(v269, 4, v280, 1);
      v279 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v276 + 8LL * v268);
    }
    if ( v279 )
    {
      if ( v265 )
      {
        v281 = *(_QWORD *)(v265 + 56);
        if ( v281 )
        {
          v282 = *(unsigned int *)(v281 + 32);
          if ( *((_DWORD *)v279 - 1) != 949740941 )
            __break(0x8228u);
          v279(v269, 3, v282, 1);
        }
      }
    }
  }
  v283 = v269 + 8LL * v268;
  v284 = *(void (__fastcall **)(__int64, __int64, __int64, long double))(v283 + 1240);
  if ( v284 && v264 )
  {
    v285 = *(unsigned int *)(v264 + 40);
    if ( *((_DWORD *)v284 - 1) != -1720921224 )
      __break(0x8228u);
    v284(v269, v285, 1, v263);
  }
  v286 = *(void (__fastcall **)(__int64, __int64 *, long double))(v283 + 712);
  if ( v286 )
  {
    if ( *((_DWORD *)v286 - 1) != 1851168652 )
      __break(0x8228u);
    v286(v269, &v307, v263);
  }
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *a1 )
    {
      v287 = *(_DWORD *)(*a1 + 24);
      v288 = a1[358];
      if ( v288 )
      {
LABEL_519:
        v289 = *(_DWORD *)(v288 + 12) - 1;
LABEL_529:
        _drm_dev_dbg(
          0,
          0,
          0,
          "[enc:%d wb:%d] Pending flush mask for CTL_%d is 0x%x\n",
          v287,
          v289,
          *(_DWORD *)(v269 + 64) - 1,
          v307);
        goto LABEL_530;
      }
    }
    else
    {
      v287 = -1;
      v288 = a1[358];
      if ( v288 )
        goto LABEL_519;
    }
    v289 = -1;
    goto LABEL_529;
  }
LABEL_530:
  sde_encoder_phys_wb_update_cwb_flush(a1, 1);
  if ( *a1 )
  {
    v292 = *(_DWORD *)(*a1 + 24);
    v293 = *(_DWORD *)v299;
    if ( !a1 )
      goto LABEL_536;
  }
  else
  {
    v292 = -1;
    v293 = *(_DWORD *)v299;
    if ( !a1 )
    {
LABEL_536:
      v295 = -1;
      goto LABEL_537;
    }
  }
  v294 = a1[358];
  if ( !v294 )
    goto LABEL_536;
  v295 = *(_DWORD *)(v294 + 12) - 1;
LABEL_537:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_wb_prepare_for_kickoff",
    2538,
    -1,
    v292,
    v295,
    *((unsigned __int8 *)a1 + 2290),
    *((_DWORD *)a1 + 583),
    v293);
  _ReadStatusReg(SP_EL0);
  return v293;
}
