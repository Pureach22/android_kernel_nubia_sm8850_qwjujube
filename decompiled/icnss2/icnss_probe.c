__int64 __fastcall icnss_probe(__int64 a1)
{
  __int64 matched; // x0
  __int64 v3; // x21
  __int64 v4; // x8
  const char *v5; // x2
  __int64 v6; // x0
  unsigned int v7; // w22
  _BYTE *v9; // x23
  __int64 v10; // x19
  __int64 v11; // x8
  __int64 v12; // x0
  int v13; // w9
  __int64 node_opts_by_path; // x0
  int v15; // w21
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x24
  unsigned int vreg; // w0
  unsigned int clk; // w0
  unsigned int pinctrl; // w0
  unsigned int psf_info; // w0
  __int64 v24; // x8
  __int64 v25; // x28
  __int64 v26; // x22
  __int64 v27; // x24
  const char *v28; // x27
  int v29; // w0
  __int64 v30; // x9
  __int64 v31; // x0
  __int64 v32; // x10
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x8
  __int64 v40; // x9
  _QWORD *resource_byname; // x0
  const void *v42; // x0
  int irq; // w0
  unsigned int v44; // w22
  int v45; // w0
  int v46; // w0
  int v47; // w0
  int v48; // w0
  int v49; // w0
  int v50; // w0
  int v51; // w0
  int v52; // w0
  int v53; // w0
  int v54; // w0
  int v55; // w0
  __int64 v56; // x0
  __int64 v57; // x0
  int v58; // w2
  __int64 *v59; // x0
  __int64 v60; // x1
  __int64 v61; // x0
  unsigned int v62; // w0
  int v63; // w3
  __int64 v64; // x0
  int v65; // w2
  __int64 v66; // x8
  int *v67; // x8
  __int64 v68; // x21
  int v69; // w0
  int *v70; // x8
  __int64 v71; // x22
  __int64 v72; // x0
  __int64 v73; // x21
  __int64 address; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  int v77; // w4
  const void *v78; // x3
  int *v79; // x21
  int variable_u32_array; // w0
  __int64 v81; // x1
  __int64 v82; // x0
  __int64 v83; // x21
  _QWORD *v84; // x26
  const char **v85; // x28
  unsigned int *v86; // x25
  unsigned int v87; // w0
  __int64 v88; // x22
  unsigned __int64 v89; // x26
  __int64 v90; // x23
  __int64 next_available_child; // x0
  const char **v92; // x28
  unsigned int v93; // w0
  unsigned int v94; // w0
  unsigned int v95; // w22
  __int64 v96; // x0
  unsigned __int64 **v97; // x24
  unsigned int string_helper; // w0
  unsigned __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x21
  unsigned __int64 v102; // x22
  int v103; // w27
  __int64 v104; // x8
  __int64 v105; // x9
  unsigned __int64 ***v106; // x1
  const char *v107; // x21
  unsigned __int64 *v108; // x9
  unsigned __int64 v109; // x10
  unsigned __int64 **v110; // x8
  unsigned __int64 *v111; // x11
  const char *v112; // x21
  int v113; // w24
  unsigned __int64 v120; // x9
  __int64 v121; // x22
  __int64 v122; // x23
  __int64 v123; // x0
  __int64 v124; // x21
  __int64 v125; // x23
  __int64 node_by_name; // x0
  unsigned __int64 property; // x0
  unsigned __int64 v128; // x8
  unsigned __int64 v129; // x24
  int v130; // w8
  __int64 v131; // x3
  __int64 v132; // x0
  __int64 domain_for_dev; // x0
  _QWORD *v134; // x9
  _QWORD *v135; // x8
  _QWORD *v136; // x23
  __int64 v137; // x0
  _BYTE *v138; // x24
  __int64 v139; // x8
  __int64 *v140; // x0
  __int64 v141; // x8
  __int64 v142; // x8
  __int64 v143; // x9
  __int64 v144; // x0
  __int64 v145; // x3
  __int64 v146; // x0
  unsigned int v147; // w0
  __int64 v148; // x21
  int v149; // w0
  int v150; // w22
  __int64 v151; // x8
  __int64 v152; // x0
  int v153; // w0
  int v154; // w20
  int v155; // w8
  int v156; // w0
  int v157; // w20
  __int64 v158; // x0
  __int64 v159; // x8
  const char *v160; // x2
  unsigned __int64 v163; // x9
  __int64 v164; // [xsp+0h] [xbp-B0h]
  _BYTE *v165; // [xsp+8h] [xbp-A8h]
  _DWORD *v166; // [xsp+10h] [xbp-A0h]
  unsigned int v167; // [xsp+18h] [xbp-98h]
  const char **v168; // [xsp+20h] [xbp-90h]
  int v169; // [xsp+20h] [xbp-90h]
  __int64 v170; // [xsp+28h] [xbp-88h]
  unsigned __int64 **v171; // [xsp+28h] [xbp-88h]
  char *s2; // [xsp+30h] [xbp-80h] BYREF
  __int64 v173; // [xsp+38h] [xbp-78h] BYREF
  int v174; // [xsp+44h] [xbp-6Ch] BYREF
  __int64 v175; // [xsp+48h] [xbp-68h] BYREF
  __int64 v176; // [xsp+50h] [xbp-60h] BYREF
  __int64 v177; // [xsp+58h] [xbp-58h]
  __int64 v178; // [xsp+60h] [xbp-50h]
  __int64 v179; // [xsp+68h] [xbp-48h]
  __int64 v180; // [xsp+70h] [xbp-40h]
  __int64 v181; // [xsp+78h] [xbp-38h]
  __int64 v182; // [xsp+80h] [xbp-30h]
  __int64 v183; // [xsp+88h] [xbp-28h]
  __int64 v184; // [xsp+90h] [xbp-20h]
  __int64 v185; // [xsp+98h] [xbp-18h]
  __int64 v186; // [xsp+A0h] [xbp-10h]

  v186 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  matched = of_match_device(&_mod_of__icnss_dt_match_device_table, a1 + 16);
  if ( !matched || (v3 = *(_QWORD *)(matched + 192)) == 0 )
  {
    printk("%sicnss2: Failed to find of match device!\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to find of match device!\n", (const char *)&unk_12DBF3);
    v7 = -19;
    goto LABEL_18;
  }
  if ( *(_QWORD *)(a1 + 168) )
  {
    printk("%sicnss2: Driver is already initialized\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Driver is already initialized\n", (const char *)&unk_12DBF3);
    v7 = -17;
    goto LABEL_16;
  }
  v4 = *(_QWORD *)(v3 + 24);
  if ( v4 > 30543 )
  {
    if ( v4 == 30544 )
    {
      v5 = "ORNE";
      goto LABEL_14;
    }
    if ( v4 == 43981 )
    {
      v5 = "ADRASTEA";
      goto LABEL_14;
    }
LABEL_11:
    v5 = "UNKNOWN";
    goto LABEL_14;
  }
  if ( v4 == 25680 )
  {
    v5 = "EVROS";
    goto LABEL_14;
  }
  if ( v4 != 26448 )
    goto LABEL_11;
  v5 = "MOSELLE";
LABEL_14:
  ipc_log_string(icnss_ipc_log_context, "icnss2: Platform driver probe for %s!\n", v5);
  v6 = devm_kmalloc(a1 + 16, 6672, 3520);
  if ( !v6 )
  {
    v7 = -12;
    goto LABEL_16;
  }
  *(_QWORD *)(a1 + 168) = v6;
  v9 = (_BYTE *)(v6 + 4096);
  *(_QWORD *)(v6 + 8) = a1;
  *(_DWORD *)v6 = 1522293436;
  v10 = v6;
  v11 = *(_QWORD *)(v3 + 24);
  *(_BYTE *)(v6 + 5640) = 1;
  *(_QWORD *)(v6 + 304) = v11;
  *(_QWORD *)(v6 + 216) = v6 + 216;
  *(_QWORD *)(v6 + 224) = v6 + 216;
  *(_QWORD *)(v6 + 232) = v6 + 232;
  *(_QWORD *)(v6 + 240) = v6 + 232;
  *(_BYTE *)(v6 + 2977) = 1;
  printk("%sicnss2: Recursive recovery allowed for WLAN\n", byte_13289B);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Recursive recovery allowed for WLAN\n", (const char *)&unk_12DBF3);
  v12 = *(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL);
  v176 = 0;
  if ( (of_property_read_variable_u32_array(v12, "wlan-txrx-intr-cpumask", &v176, 2, 0) & 0x80000000) != 0 )
  {
    printk("%sicnss2: Failed to get cpumask for wlan txrx interrupts", byte_130B32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Failed to get cpumask for wlan txrx interrupts",
      (const char *)&unk_12DBF3);
  }
  else
  {
    v13 = HIDWORD(v176);
    *(_DWORD *)(v10 + 6144) = v176;
    *(_DWORD *)(v10 + 6148) = v13;
  }
  LODWORD(v176) = 0;
  node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
  v15 = -2;
  if ( node_opts_by_path )
  {
    if ( (int)of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v176, 1, 0) >= 0 )
      v15 = v176;
    else
      v15 = -2;
  }
  *(_DWORD *)(v10 + 6280) = v15;
  if ( (icnss_probe_prealloc_initialized & 1) == 0 )
  {
    cnss_initialize_prealloc_pool(*(_QWORD *)(v10 + 304));
    icnss_probe_prealloc_initialized = 1;
  }
  v16 = *(_QWORD *)(v10 + 304);
  v176 = 0;
  *(_QWORD *)(v10 + 328) = 64;
  *(_QWORD *)(v10 + 336) = 0x1000002EELL;
  if ( v16 == 25680
    || v16 == 26448
    || v16 == 30544
    || of_find_property(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "wpss-support-enable", 0) )
  {
    v9[1872] = 1;
  }
  v17 = *(_QWORD *)(v10 + 304);
  if ( (v17 == 25680 || v17 == 30544 || v17 == 26448)
    && !(unsigned int)of_property_read_string(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "wcn-hw-version", &v176) )
  {
    *(_QWORD *)(v10 + 6136) = v176;
  }
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "bdf-download-support", 0) )
    v9[1749] = 1;
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "rproc-fw-download", 0) )
    v9[2016] = 1;
  v18 = *(_QWORD *)(v10 + 304);
  if ( v9[1749] == 1 && v18 == 43981 )
  {
    *(_DWORD *)(v10 + 340) = 0;
  }
  else if ( v18 == 30544 )
  {
    icnss_set_feature_list(v10, 6);
  }
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "qcom,rc-ep-short-channel", 0) )
    icnss_set_feature_list(v10, 5);
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "wlan-ipa-disabled", 0) )
  {
    _X8 = (unsigned __int64 *)(v10 + 5960);
    __asm { PRFM            #0x11, [X8] }
    do
      v120 = __ldxr(_X8);
    while ( __stxr(v120 | 1, _X8) );
  }
  if ( of_find_property(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "qcom,wpss-self-recovery", 0) )
    v9[2000] = 1;
  v19 = *(_QWORD *)(v10 + 8);
  LODWORD(v173) = 0;
  vreg = icnss_get_vreg(v10);
  if ( vreg )
  {
    v7 = vreg;
    printk("%sicnss2: Failed to get vreg, err = %d\n", byte_130B32, vreg);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to get vreg, err = %d\n", (const char *)&unk_12DBF3, v7);
    goto LABEL_18;
  }
  clk = icnss_get_clk(v10);
  if ( clk )
  {
    v7 = clk;
    printk("%sicnss2: Failed to get clocks, err = %d\n", byte_130B32, clk);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to get clocks, err = %d\n", (const char *)&unk_12DBF3, v7);
    goto LABEL_193;
  }
  pinctrl = icnss_get_pinctrl(v10);
  if ( pinctrl )
  {
    v7 = pinctrl;
    printk("%sicnss2: Failed to get pinctrl, err = %d\n", byte_130B32, pinctrl);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to get pinctrl, err = %d\n", (const char *)&unk_12DBF3, v7);
    goto LABEL_192;
  }
  if ( of_find_property(*(_QWORD *)(v19 + 760), "qcom,psf-supported", 0) )
  {
    psf_info = icnss_get_psf_info(v10);
    if ( (psf_info & 0x80000000) != 0 )
    {
      v7 = psf_info;
      goto LABEL_18;
    }
    v9[1750] = 1;
  }
  v24 = *(_QWORD *)(v10 + 304);
  v165 = v9;
  if ( v24 != 30544 && v24 != 25680 )
    goto LABEL_74;
  v25 = 0;
  v26 = v10 + 6284;
  v170 = v19;
  v182 = 0;
  v183 = 0;
  v180 = 0;
  v181 = 0;
  v178 = 0;
  v179 = 0;
  v176 = 0;
  v177 = 0;
  while ( 1 )
  {
    v27 = *(_QWORD *)(v10 + 8);
    v28 = off_25BC0[v25];
    v29 = of_property_read_variable_u32_array(*(_QWORD *)(v27 + 760), v28, &v176, 16, 0);
    if ( v29 == -75 )
      v29 = of_property_read_variable_u32_array(*(_QWORD *)(v27 + 760), v28, &v176, 1, 0);
    if ( (v29 & (v29 >> 31)) != 0 )
      goto LABEL_62;
    v30 = v181;
    v31 = icnss_ipc_log_context;
    *(_QWORD *)(v26 + 32) = v180;
    *(_QWORD *)(v26 + 40) = v30;
    v32 = v183;
    *(_QWORD *)(v26 + 48) = v182;
    *(_QWORD *)(v26 + 56) = v32;
    v33 = v177;
    *(_QWORD *)v26 = v176;
    *(_QWORD *)(v26 + 8) = v33;
    v34 = v179;
    *(_QWORD *)(v26 + 16) = v178;
    *(_QWORD *)(v26 + 24) = v34;
    ipc_log_string(v31, "icnss2: Parse %s config property through DT\n", v28);
    v35 = *(unsigned int *)(v26 + 4);
    if ( WORD1(v35) )
      break;
    v36 = *(unsigned int *)(v26 + 12);
    if ( (unsigned int)v36 > 0xFF )
      break;
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2: GPIO_NUM: %d, GPIO_NAME: %s, PMIC_INDEX: %d, GPIO_TYPE: %s\n",
      *(_DWORD *)v26,
      icnss_gpio_name_str[v35],
      *(_DWORD *)(v26 + 8),
      icnss_gpio_type_str[v36]);
    v37 = *(unsigned int *)(v26 + 16);
    if ( (unsigned int)v37 > 0xFF )
      break;
    v38 = *(unsigned int *)(v26 + 24);
    if ( (unsigned int)v38 > 0xFF )
      break;
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2: OUTPUT_VALUE: %s, FUNC_SELECT: %d, GPIO_DIRECTION: %s, DRIVE_STRENGTH: %d\n",
      icnss_gpio_output_str[v37],
      *(_DWORD *)(v26 + 20),
      icnss_gpio_direction_str[v38],
      *(_DWORD *)(v26 + 28));
    v39 = *(unsigned int *)(v26 + 32);
    if ( (unsigned int)v39 > 0xFF )
      break;
    v40 = *(unsigned int *)(v26 + 44);
    if ( (unsigned int)v40 > 0xFF )
      break;
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2: BIAS_TYPE: %s, IS_CLK: %d, IS_WAKE: %d, INTRPT_TRIGGER_TYPE: %s\n",
      icnss_gpio_bias_str[v39],
      *(_DWORD *)(v26 + 36),
      *(_DWORD *)(v26 + 40),
      icnss_gpio_intr_trigger_str[v40]);
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2: PRIORITY: %d, GPIO_BITRESERVED: %d, GPIO_ARRAY_VALID: %d, GPIO_OWNER: %d\n",
      *(_DWORD *)(v26 + 48),
      *(_DWORD *)(v26 + 52),
      *(_DWORD *)(v26 + 56),
      *(_DWORD *)(v26 + 60));
LABEL_62:
    ++v25;
    v26 += 64;
    if ( v25 == 6 )
      goto LABEL_73;
  }
LABEL_72:
  __break(0x5512u);
LABEL_73:
  v24 = *(_QWORD *)(v10 + 304);
  v9 = v165;
  v19 = v170;
LABEL_74:
  if ( v24 > 30543 )
  {
    if ( v24 == 30544 )
      goto LABEL_100;
    if ( v24 != 43981 )
      goto LABEL_122;
    resource_byname = (_QWORD *)platform_get_resource_byname(v19, 512, "membase");
    if ( !resource_byname )
    {
      v107 = "%sicnss2: Memory base not found in DT\n";
      printk("%sicnss2: Memory base not found in DT\n", byte_130B32);
      goto LABEL_187;
    }
    *(_QWORD *)(v10 + 528) = *resource_byname;
    v42 = (const void *)devm_ioremap(v19 + 16);
    *(_QWORD *)(v10 + 536) = v42;
    if ( !v42 )
    {
      printk("%sicnss2: Memory base ioremap failed: phy addr: %pa\n", byte_130B32, (const void *)(v10 + 528));
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Memory base ioremap failed: phy addr: %pa\n",
        (const char *)&unk_12DBF3,
        (const void *)(v10 + 528));
      v7 = -22;
      goto LABEL_192;
    }
    ipc_log_string(icnss_ipc_log_context, "icnss2: MEM_BASE pa: %pa, va: 0x%pK\n", (const void *)(v10 + 528), v42);
    irq = platform_get_irq(v19, 0);
    if ( irq < 0 )
    {
      v44 = 0;
    }
    else
    {
      *(_DWORD *)(v10 + 348) = irq;
      v44 = 1;
      v45 = platform_get_irq(v19, 1);
      if ( (v45 & 0x80000000) == 0 )
      {
        *(_DWORD *)(v10 + 352) = v45;
        v44 = 2;
        v46 = platform_get_irq(v19, 2);
        if ( (v46 & 0x80000000) == 0 )
        {
          *(_DWORD *)(v10 + 356) = v46;
          v44 = 3;
          v47 = platform_get_irq(v19, 3);
          if ( (v47 & 0x80000000) == 0 )
          {
            *(_DWORD *)(v10 + 360) = v47;
            v44 = 4;
            v48 = platform_get_irq(v19, 4);
            if ( (v48 & 0x80000000) == 0 )
            {
              *(_DWORD *)(v10 + 364) = v48;
              v44 = 5;
              v49 = platform_get_irq(v19, 5);
              if ( (v49 & 0x80000000) == 0 )
              {
                *(_DWORD *)(v10 + 368) = v49;
                v44 = 6;
                v50 = platform_get_irq(v19, 6);
                if ( (v50 & 0x80000000) == 0 )
                {
                  *(_DWORD *)(v10 + 372) = v50;
                  v44 = 7;
                  v51 = platform_get_irq(v19, 7);
                  if ( (v51 & 0x80000000) == 0 )
                  {
                    *(_DWORD *)(v10 + 376) = v51;
                    v44 = 8;
                    v52 = platform_get_irq(v19, 8);
                    if ( (v52 & 0x80000000) == 0 )
                    {
                      *(_DWORD *)(v10 + 380) = v52;
                      v44 = 9;
                      v53 = platform_get_irq(v19, 9);
                      if ( (v53 & 0x80000000) == 0 )
                      {
                        *(_DWORD *)(v10 + 384) = v53;
                        v44 = 10;
                        v54 = platform_get_irq(v19, 10);
                        if ( (v54 & 0x80000000) == 0 )
                        {
                          *(_DWORD *)(v10 + 388) = v54;
                          v44 = 11;
                          v55 = platform_get_irq(v19, 11);
                          if ( (v55 & 0x80000000) == 0 )
                          {
                            *(_DWORD *)(v10 + 392) = v55;
                            if ( of_find_property(*(_QWORD *)(v19 + 760), "qcom,is_low_power", 0) )
                            {
                              v56 = icnss_ipc_log_context;
                              v9[1873] = 1;
                              ipc_log_string(v56, "icnss2: Deep Sleep/Hibernate mode supported\n");
                            }
                            if ( (of_property_read_variable_u32_array(
                                    *(_QWORD *)(v19 + 760),
                                    "qcom,rf_subtype",
                                    v10 + 5972,
                                    1,
                                    0)
                                & 0x80000000) == 0 )
                            {
                              v57 = icnss_ipc_log_context;
                              v58 = *(_DWORD *)(v10 + 5972);
                              v9[1874] = 1;
                              ipc_log_string(v57, "icnss2: RF subtype 0x%x\n", v58);
                            }
                            if ( of_find_property(*(_QWORD *)(v19 + 760), "qcom,is_slate_rfa", 0) )
                            {
                              v9[1880] = 1;
                              printk("%sicnss2: SLATE rfa is enabled\n", byte_130B32);
                              ipc_log_string(
                                icnss_ipc_log_context,
                                "%sicnss2: SLATE rfa is enabled\n",
                                (const char *)&unk_12DBF3);
                            }
LABEL_122:
                            v71 = *(_QWORD *)(v10 + 8);
                            v72 = *(_QWORD *)(v71 + 760);
                            v173 = 0;
                            v184 = 0;
                            v185 = 0;
                            v182 = 0;
                            v183 = 0;
                            v180 = 0;
                            v181 = 0;
                            v178 = 0;
                            v179 = 0;
                            v176 = 0;
                            v177 = 0;
                            if ( !(unsigned int)_of_parse_phandle_with_args(
                                                  v72,
                                                  "qcom,wlan-msa-fixed-region",
                                                  0,
                                                  0,
                                                  0,
                                                  &v176) )
                            {
                              v73 = v176;
                              if ( v176 )
                              {
                                address = _of_get_address(v176, 0, 0xFFFFFFFFLL, &v173, 0);
                                if ( address )
                                {
                                  v75 = of_translate_address(v73, address);
                                  *(_QWORD *)(v10 + 1792) = v75;
                                  if ( v75 != -1 )
                                  {
                                    v76 = memremap(v75, v173, 2);
                                    *(_QWORD *)(v10 + 1824) = v76;
                                    if ( !v76 )
                                    {
                                      printk(
                                        "%sicnss2: MSA PA ioremap failed: phy addr: %pa\n",
                                        byte_130B32,
                                        (const void *)(v10 + 1792));
                                      ipc_log_string(
                                        icnss_ipc_log_context,
                                        "%sicnss2: MSA PA ioremap failed: phy addr: %pa\n",
                                        (const char *)&unk_12DBF3,
                                        (const void *)(v10 + 1792));
                                      v7 = -22;
                                      goto LABEL_231;
                                    }
                                    v77 = v173;
                                    v78 = (const void *)v76;
                                    *(_DWORD *)(v10 + 1816) = v173;
                                    goto LABEL_132;
                                  }
                                  v112 = "%sicnss2: Failed to translate MSA PA from device-tree\n";
                                  printk("%sicnss2: Failed to translate MSA PA from device-tree\n", byte_130B32);
                                }
                                else
                                {
                                  v112 = "%sicnss2: Failed to get assigned-addresses or property\n";
                                  printk("%sicnss2: Failed to get assigned-addresses or property\n", byte_130B32);
                                }
                                ipc_log_string(icnss_ipc_log_context, v112, &unk_12DBF3);
                                v7 = -22;
                                goto LABEL_231;
                              }
                            }
                            v79 = (int *)(v10 + 1816);
                            variable_u32_array = of_property_read_variable_u32_array(
                                                   *(_QWORD *)(v71 + 760),
                                                   "qcom,wlan-msa-memory",
                                                   v10 + 1816,
                                                   1,
                                                   0);
                            v81 = *(unsigned int *)(v10 + 1816);
                            if ( variable_u32_array < 0 || !(_DWORD)v81 )
                            {
                              v7 = variable_u32_array & (variable_u32_array >> 31);
                              v113 = variable_u32_array;
                              printk(
                                "%sicnss2: Fail to get MSA Memory Size: %u ret: %d\n",
                                byte_130B32,
                                *(_DWORD *)(v10 + 1816),
                                v7);
                              ipc_log_string(
                                icnss_ipc_log_context,
                                "%sicnss2: Fail to get MSA Memory Size: %u ret: %d\n",
                                (const char *)&unk_12DBF3,
                                *v79,
                                v7);
                              if ( v113 < 0 )
                                goto LABEL_231;
LABEL_133:
                              v83 = *(_QWORD *)(v10 + 8);
                              v84 = (_QWORD *)(v10 + 1648);
                              LODWORD(v176) = 0;
                              v85 = *(const char ***)(v83 + 760);
                              *(_QWORD *)(v10 + 1648) = v10 + 1648;
                              *(_QWORD *)(v10 + 1656) = v10 + 1648;
                              v166 = (_DWORD *)(v10 + 1664);
                              if ( (of_property_read_variable_u32_array(
                                      *(_QWORD *)(v83 + 760),
                                      "qcom,icc-path-count",
                                      v10 + 1664,
                                      1,
                                      0)
                                  & 0x80000000) != 0 )
                              {
                                ipc_log_string(
                                  icnss_ipc_log_context,
                                  "icnss2: Platform Bus Interconnect path not configured\n");
                              }
                              else
                              {
                                v86 = (unsigned int *)(v10 + 1672);
                                v87 = of_property_read_variable_u32_array(
                                        *(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL),
                                        "qcom,bus-bw-cfg-count",
                                        v10 + 1672,
                                        1,
                                        0);
                                if ( (v87 & 0x80000000) != 0 )
                                {
                                  v7 = v87;
                                  printk("%sicnss2: Failed to get Bus BW Config table size\n", byte_130B32);
                                  ipc_log_string(
                                    icnss_ipc_log_context,
                                    "%sicnss2: Failed to get Bus BW Config table size\n",
                                    (const char *)&unk_12DBF3);
                                  v90 = 0;
                                  goto LABEL_202;
                                }
                                v171 = (unsigned __int64 **)(v10 + 1648);
                                v88 = 2 * *v166 * *v86;
                                v89 = 4 * v88;
                                v90 = _kmalloc_noprof(4 * v88, 3520);
                                if ( !v90 )
                                {
                                  printk("%sicnss2: Failed to alloc cfg table mem\n", byte_130B32);
                                  ipc_log_string(
                                    icnss_ipc_log_context,
                                    "%sicnss2: Failed to alloc cfg table mem\n",
                                    (const char *)&unk_12DBF3);
                                  v84 = (_QWORD *)(v10 + 1648);
                                  v7 = -12;
                                  goto LABEL_202;
                                }
                                v168 = v85;
                                next_available_child = of_get_next_available_child(
                                                         *(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL),
                                                         0);
                                if ( next_available_child )
                                {
                                  v92 = (const char **)next_available_child;
                                  do
                                  {
                                    if ( !strcmp(*v92, "ddr_cfg") )
                                    {
                                      v93 = of_property_read_variable_u32_array(v92, "ddr_type", &v176, 1, 0);
                                      if ( (v93 & 0x80000000) != 0 )
                                      {
                                        v7 = v93;
                                        printk(
                                          "%sicnss2: DDR type: %d is not found in dt\n",
                                          byte_130B32,
                                          *(_DWORD *)(v10 + 6280));
                                        ipc_log_string(
                                          icnss_ipc_log_context,
                                          "%sicnss2: DDR type: %d is not found in dt\n",
                                          (const char *)&unk_12DBF3,
                                          *(_DWORD *)(v10 + 6280));
                                        v84 = (_QWORD *)(v10 + 1648);
                                        goto LABEL_202;
                                      }
                                      if ( (_DWORD)v176 == *(_DWORD *)(v10 + 6280) )
                                      {
                                        printk("%sicnss2: child node set for DDR type %d", byte_13289B, v176);
                                        ipc_log_string(
                                          icnss_ipc_log_context,
                                          "%sicnss2: child node set for DDR type %d",
                                          (const char *)&unk_12DBF3,
                                          v176);
                                        v168 = v92;
                                      }
                                    }
                                    v92 = (const char **)of_get_next_available_child(
                                                           *(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL),
                                                           v92);
                                  }
                                  while ( v92 );
                                }
                                v94 = of_property_read_variable_u32_array(v168, "qcom,bus-bw-cfg", v90, v88, 0);
                                if ( (v94 & 0x80000000) != 0 )
                                {
                                  v7 = v94;
                                  printk("%sicnss2: Invalid Bus BW Config Table\n", byte_130B32);
                                  ipc_log_string(
                                    icnss_ipc_log_context,
                                    "%sicnss2: Invalid Bus BW Config Table\n",
                                    (const char *)&unk_12DBF3);
                                  v84 = (_QWORD *)(v10 + 1648);
                                  goto LABEL_202;
                                }
                                ipc_log_string(
                                  icnss_ipc_log_context,
                                  "icnss2: ICC Path_Count: %d BW_CFG_Count: %d\n",
                                  *v166,
                                  *v86);
                                if ( *v166 )
                                {
                                  v95 = 0;
                                  v169 = 0;
                                  v164 = v83;
                                  while ( 1 )
                                  {
                                    v96 = devm_kmalloc(v83 + 16, 40, 3520);
                                    if ( !v96 )
                                    {
LABEL_165:
                                      v7 = -12;
                                      goto LABEL_168;
                                    }
                                    v97 = (unsigned __int64 **)v96;
                                    v167 = v95;
                                    string_helper = of_property_read_string_helper(
                                                      *(_QWORD *)(v83 + 760),
                                                      "interconnect-names",
                                                      v96 + 16,
                                                      1,
                                                      v95);
                                    if ( (string_helper & 0x80000000) != 0 )
                                    {
                                      v7 = string_helper;
                                      goto LABEL_168;
                                    }
                                    v99 = of_icc_get(*(_QWORD *)(v10 + 8) + 16LL, v97[2]);
                                    v97[3] = (unsigned __int64 *)v99;
                                    if ( v99 >= 0xFFFFFFFFFFFFF001LL )
                                    {
                                      v7 = v99;
                                      if ( (_DWORD)v99 != -517 )
                                        break;
                                    }
                                    v100 = devm_kmalloc(v83 + 16, 8LL * *v86, 3520);
                                    v97[4] = (unsigned __int64 *)v100;
                                    if ( !v100 )
                                      goto LABEL_165;
                                    ipc_log_string(
                                      icnss_ipc_log_context,
                                      "icnss2: ICC Vote CFG for path: %s\n",
                                      (const char *)v97[2]);
                                    if ( *v86 )
                                    {
                                      v101 = 0;
                                      v102 = 0;
                                      v103 = *v86 * v169;
                                      do
                                      {
                                        v104 = (unsigned int)(v103 + v101 * 2);
                                        if ( v89 <= 4 * (unsigned __int64)(unsigned int)v104
                                          || (v105 = (unsigned int)(v103 + v101 * 2 + 1),
                                              LODWORD(v97[4][v101]) = *(_DWORD *)(v90 + 4 * v104),
                                              v89 <= 4 * (unsigned __int64)(unsigned int)v105) )
                                        {
                                          __break(1u);
                                        }
                                        HIDWORD(v97[4][v101]) = *(_DWORD *)(v90 + 4 * v105);
                                        ipc_log_string(
                                          icnss_ipc_log_context,
                                          "icnss2: ICC Vote BW: %d avg: %d peak: %d\n",
                                          v102++,
                                          LODWORD(v97[4][v101]),
                                          HIDWORD(v97[4][v101]));
                                        ++v101;
                                      }
                                      while ( v102 < *v86 );
                                    }
                                    v106 = *(unsigned __int64 ****)(v10 + 1656);
                                    if ( v97 == v171 || v106 == (unsigned __int64 ***)v97 || *v106 != v171 )
                                    {
                                      _list_add_valid_or_report(v97, v106);
                                    }
                                    else
                                    {
                                      *(_QWORD *)(v10 + 1656) = v97;
                                      *v97 = (unsigned __int64 *)v171;
                                      v97[1] = (unsigned __int64 *)v106;
                                      *v106 = v97;
                                    }
                                    v83 = v164;
                                    v95 = v167 + 1;
                                    v169 += 2;
                                    if ( v167 + 1 >= *v166 )
                                      goto LABEL_164;
                                  }
                                  printk(
                                    "%sicnss2: Failed to get Interconnect path for %s. Err: %d\n",
                                    byte_130B32,
                                    (const char *)v97[2],
                                    v99);
                                  ipc_log_string(
                                    icnss_ipc_log_context,
                                    "%sicnss2: Failed to get Interconnect path for %s. Err: %d\n",
                                    (const char *)&unk_12DBF3,
                                    (const char *)v97[2],
                                    v7);
LABEL_168:
                                  v84 = (_QWORD *)(v10 + 1648);
                                  v108 = *v171;
                                  if ( *v171 != (unsigned __int64 *)v171 )
                                  {
                                    v109 = 0xDEAD000000000100LL;
                                    do
                                    {
                                      v111 = (unsigned __int64 *)*v108;
                                      v110 = (unsigned __int64 **)v108[1];
                                      if ( *v110 == v108 && (unsigned __int64 *)v111[1] == v108 )
                                      {
                                        v111[1] = (unsigned __int64)v110;
                                        *v110 = v111;
                                      }
                                      else
                                      {
                                        _list_del_entry_valid_or_report(v108);
                                      }
                                      *v108 = v109;
                                      v108[1] = v109 + 34;
                                      v108 = v111;
                                    }
                                    while ( v111 != (unsigned __int64 *)v171 );
                                  }
LABEL_202:
                                  kfree(v90);
                                  v84[2] = 0;
                                  v84[3] = 0;
                                  *v84 = 0;
                                  v84[1] = 0;
                                  if ( !v7 )
                                    goto LABEL_203;
LABEL_231:
                                  icnss_put_resources(v10);
                                  goto LABEL_18;
                                }
LABEL_164:
                                kfree(v90);
                                v84 = (_QWORD *)(v10 + 1648);
                              }
LABEL_203:
                              v121 = *(_QWORD *)(v10 + 8);
                              v122 = *(_QWORD *)(v121 + 760);
                              s2 = nullptr;
                              v175 = 0;
                              if ( (of_property_read_variable_u32_array(v122, "qcom,iommu-dma-addr-pool", &v175, 2, 0)
                                  & 0x80000000) != 0 )
                              {
                                v123 = *(_QWORD *)(v121 + 760);
                                v184 = 0;
                                v185 = 0;
                                v182 = 0;
                                v183 = 0;
                                v180 = 0;
                                v181 = 0;
                                v178 = 0;
                                v179 = 0;
                                v176 = 0;
                                v177 = 0;
                                v124 = 0;
                                if ( (unsigned int)_of_parse_phandle_with_args(v123, "qcom,iommu-group", 0, 0, 0, &v176)
                                  || (v122 = v176) == 0
                                  || (v124 = v176,
                                      (of_property_read_variable_u32_array(
                                         v176,
                                         "qcom,iommu-dma-addr-pool",
                                         &v175,
                                         2,
                                         0)
                                     & 0x80000000) != 0) )
                                {
                                  v125 = *(_QWORD *)(v121 + 760);
                                  v174 = 0;
                                  node_by_name = of_find_node_by_name(v125, "icnss2_iommu_region_partition");
                                  if ( !node_by_name )
                                    goto LABEL_232;
                                  property = of_get_property(node_by_name, "iommu-addresses", &v174);
                                  if ( !property )
                                    goto LABEL_232;
                                  v175 = 0;
                                  v128 = v174 & 0xFFFFFFFFFFFFFFFCLL;
                                  v129 = property + v128;
                                  if ( property >= property + v128 )
                                    goto LABEL_232;
                                  do
                                  {
                                    while ( 1 )
                                    {
                                      v176 = 0;
                                      v173 = 0;
                                      property = of_translate_dma_region(v125, property + 4, &v176, &v173);
                                      if ( !(_DWORD)v175 )
                                        break;
                                      v130 = v176 - v175;
                                      HIDWORD(v175) = v176 - v175;
                                      if ( property >= v129 )
                                        goto LABEL_217;
                                    }
                                    LODWORD(v175) = v173;
                                  }
                                  while ( property < v129 );
                                  if ( !(_DWORD)v173 )
                                    goto LABEL_232;
                                  v130 = HIDWORD(v175);
LABEL_217:
                                  if ( !v130 )
                                  {
LABEL_232:
                                    printk("%sicnss2: SMMU IOVA base not found\n", byte_130B32);
                                    ipc_log_string(
                                      icnss_ipc_log_context,
                                      "%sicnss2: SMMU IOVA base not found\n",
                                      (const char *)&unk_12DBF3);
                                    v138 = v165;
                                    goto LABEL_241;
                                  }
                                  v122 = v124;
                                }
                              }
                              v131 = HIDWORD(v175);
                              v132 = icnss_ipc_log_context;
                              *(_QWORD *)(v10 + 584) = (unsigned int)v175;
                              *(_QWORD *)(v10 + 592) = v131;
                              ipc_log_string(
                                v132,
                                "icnss2: SMMU IOVA start: %pa, len: %zx\n",
                                (const void *)(v10 + 584),
                                v131);
                              domain_for_dev = iommu_get_domain_for_dev(v121 + 16);
                              *(_QWORD *)(v10 + 576) = domain_for_dev;
                              if ( !domain_for_dev )
                              {
                                v7 = -517;
LABEL_221:
                                v134 = (_QWORD *)*v84;
                                if ( (_QWORD *)*v84 != v84 )
                                {
                                  do
                                  {
                                    v136 = (_QWORD *)*v134;
                                    v135 = (_QWORD *)v134[1];
                                    if ( (_QWORD *)*v135 == v134 && (_QWORD *)v136[1] == v134 )
                                    {
                                      v136[1] = v135;
                                      *v135 = v136;
                                    }
                                    else
                                    {
                                      _list_del_entry_valid_or_report(v134);
                                    }
                                    v137 = v134[3];
                                    *v134 = 0xDEAD000000000100LL;
                                    v134[1] = 0xDEAD000000000122LL;
                                    if ( v137 )
                                      icc_put();
                                    v134 = v136;
                                  }
                                  while ( v136 != v84 );
                                }
                                v84[2] = 0;
                                v84[3] = 0;
                                *v84 = 0;
                                v84[1] = 0;
                                goto LABEL_231;
                              }
                              v138 = v165;
                              if ( !(unsigned int)of_property_read_string(v122, "qcom,iommu-dma", &s2)
                                && !strcmp("fastmap", s2) )
                              {
                                ipc_log_string(icnss_ipc_log_context, "icnss2: SMMU S1 stage enabled\n");
                                v139 = *(_QWORD *)(v10 + 304);
                                *(_BYTE *)(v10 + 3251) = 1;
                                if ( v139 == 26448 || v139 == 25680 )
                                  iommu_set_fault_handler(*(_QWORD *)(v10 + 576), icnss_smmu_fault_handler, v10);
                              }
                              v140 = (__int64 *)platform_get_resource_byname(v121, 512, "smmu_iova_ipa");
                              if ( v140 )
                              {
                                v141 = *v140;
                                *(_QWORD *)(v10 + 600) = *v140;
                                *(_QWORD *)(v10 + 608) = v141;
                                v143 = *v140;
                                v142 = v140[1];
                                v144 = icnss_ipc_log_context;
                                v145 = v142 - v143 + 1;
                                *(_QWORD *)(v10 + 616) = v145;
                                ipc_log_string(
                                  v144,
                                  "icnss2: SMMU IOVA IPA start: %pa, len: %zx\n",
                                  (const void *)(v10 + 600),
                                  v145);
                              }
                              else
                              {
                                printk("%sicnss2: SMMU IOVA IPA not found\n", byte_130B32);
                                ipc_log_string(
                                  icnss_ipc_log_context,
                                  "%sicnss2: SMMU IOVA IPA not found\n",
                                  (const char *)&unk_12DBF3);
                              }
LABEL_241:
                              *(_QWORD *)(v10 + 1640) = 0;
                              *(_DWORD *)(v10 + 2152) = 0;
                              _mutex_init(v10 + 2984, "&priv->dev_lock", &icnss_probe___key);
                              _mutex_init(v10 + 5544, "&priv->tcdev_lock", &icnss_probe___key_315);
                              _mutex_init(v10 + 5592, "&priv->wpss_lock", &icnss_probe___key_317);
                              v146 = alloc_workqueue("icnss_driver_event", 2, 1);
                              *(_QWORD *)(v10 + 1776) = v146;
                              if ( !v146 )
                              {
                                printk("%sicnss2: Workqueue creation failed\n", byte_130B32);
                                ipc_log_string(
                                  icnss_ipc_log_context,
                                  "%sicnss2: Workqueue creation failed\n",
                                  (const char *)&unk_12DBF3);
                                v7 = -14;
LABEL_255:
                                *(_QWORD *)(v10 + 576) = 0;
                                goto LABEL_221;
                              }
                              *(_QWORD *)(v10 + 1680) = 0xFFFFFFFE00000LL;
                              *(_QWORD *)(v10 + 1688) = v10 + 1688;
                              *(_QWORD *)(v10 + 1696) = v10 + 1688;
                              *(_QWORD *)(v10 + 1704) = icnss_driver_event_work;
                              *(_QWORD *)(v10 + 1608) = v10 + 1608;
                              *(_QWORD *)(v10 + 1616) = v10 + 1608;
                              if ( v138[1880] )
                              {
                                *(_DWORD *)(v10 + 5984) = 0;
                                _init_swait_queue_head(v10 + 5992, "&x->wait", &init_completion___key);
                              }
                              v147 = icnss_register_fw_service(v10);
                              if ( (v147 & 0x80000000) != 0 )
                              {
                                v7 = v147;
                                printk("%sicnss2: fw service registration failed: %d\n", byte_130B32, v147);
                                ipc_log_string(
                                  icnss_ipc_log_context,
                                  "%sicnss2: fw service registration failed: %d\n",
                                  (const char *)&unk_12DBF3,
                                  v7);
LABEL_254:
                                destroy_workqueue(*(_QWORD *)(v10 + 1776));
                                goto LABEL_255;
                              }
                              icnss_power_misc_params_init(v10);
                              icnss_enable_recovery(v10);
                              icnss_debugfs_create(v10);
                              icnss_sysfs_create(v10);
                              v148 = *(_QWORD *)(v10 + 8);
                              device_set_wakeup_capable(v148 + 16, 1);
                              v149 = device_wakeup_enable(v148 + 16);
                              if ( v149 )
                              {
                                v150 = v149;
                                printk(
                                  "%sicnss2: Failed to init platform device wakeup source, err = %d\n",
                                  byte_130B32,
                                  v149);
                                ipc_log_string(
                                  icnss_ipc_log_context,
                                  "%sicnss2: Failed to init platform device wakeup source, err = %d\n",
                                  (const char *)&unk_12DBF3,
                                  v150);
                              }
                              penv = v10;
                              *(_DWORD *)(v10 + 3088) = 0;
                              _init_swait_queue_head(v10 + 3096, "&x->wait", &init_completion___key);
                              v151 = *(_QWORD *)(v10 + 304);
                              if ( v151 == 25680 || v151 == 30544 || v151 == 26448 )
                              {
                                v152 = alloc_workqueue("icnss_soc_wake_event", 18, 1);
                                *(_QWORD *)(v10 + 1784) = v152;
                                if ( !v152 )
                                {
                                  printk("%sicnss2: Soc wake Workqueue creation failed\n", byte_130B32);
                                  ipc_log_string(
                                    icnss_ipc_log_context,
                                    "%sicnss2: Soc wake Workqueue creation failed\n",
                                    (const char *)&unk_12DBF3);
                                  icnss_unregister_fw_service(v10);
                                  v7 = -14;
                                  goto LABEL_254;
                                }
                                *(_QWORD *)(v10 + 1744) = 0xFFFFFFFE00000LL;
                                *(_QWORD *)(v10 + 1752) = v10 + 1752;
                                *(_QWORD *)(v10 + 1760) = v10 + 1752;
                                *(_QWORD *)(v10 + 1768) = icnss_soc_wake_msg_work;
                                *(_QWORD *)(v10 + 1624) = v10 + 1624;
                                *(_QWORD *)(v10 + 1632) = v10 + 1624;
                                v153 = icnss_genl_init();
                                if ( v153 < 0 )
                                {
                                  v154 = v153;
                                  printk("%sicnss2: ICNSS genl init failed %d\n", byte_130B32, v153);
                                  ipc_log_string(
                                    icnss_ipc_log_context,
                                    "%sicnss2: ICNSS genl init failed %d\n",
                                    (const char *)&unk_12DBF3,
                                    v154);
                                }
                                *(_DWORD *)(v10 + 5808) = 0;
                                _init_swait_queue_head(v10 + 5816, "&x->wait", &init_completion___key);
                                icnss_runtime_pm_init(v10);
                                icnss_aop_interface_init(v10);
                                _X8 = (unsigned __int64 *)(v10 + 1832);
                                __asm { PRFM            #0x11, [X8] }
                                do
                                  v163 = __ldxr(_X8);
                                while ( __stxr(v163 | 0x200000, _X8) );
                                v138[1749] = 1;
                                tracepoint_probe_register(
                                  &_tracepoint_android_vh_rproc_recovery_set,
                                  rproc_restart_level_notifier,
                                  0);
                                v151 = *(_QWORD *)(v10 + 304);
                              }
                              if ( v151 == 30544 )
                                icnss_reboot_register_notifier(v10);
                              v155 = (unsigned __int8)v138[1872];
                              if ( v155 == 1 )
                              {
                                v156 = icnss_dms_init(v10);
                                if ( v156 )
                                {
                                  v157 = v156;
                                  printk("%sicnss2: ICNSS DMS init failed %d\n", byte_130B32, v156);
                                  ipc_log_string(
                                    icnss_ipc_log_context,
                                    "%sicnss2: ICNSS DMS init failed %d\n",
                                    (const char *)&unk_12DBF3,
                                    v157);
                                }
                                v158 = of_find_property(*(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL), "use-nv-mac", 0);
                                v159 = icnss_ipc_log_context;
                                v138[1560] = v158 != 0;
                                if ( v158 )
                                  v160 = "Mandatory";
                                else
                                  v160 = "Not Mandatory";
                                ipc_log_string(v159, "icnss2: NV MAC feature is %s\n", v160);
                                LOBYTE(v155) = v138[1872];
                              }
                              if ( (v155 & 1) != 0 || v138[2016] == 1 )
                              {
                                wpss_loader = 0xFFFFFFFE00000LL;
                                qword_136210 = (__int64)&qword_136210;
                                qword_136218 = (__int64)&qword_136210;
                                qword_136220 = (__int64)icnss_wpss_load;
                              }
                              init_timer_key(v10 + 6016, icnss_recovery_timeout_hdlr, 0, 0, 0);
                              if ( v138[2000] == 1 )
                              {
                                wpss_ssr_work = 0xFFFFFFFE00000LL;
                                qword_1361E8 = (__int64)&qword_1361E8;
                                qword_1361F0 = (__int64)&qword_1361E8;
                                qword_1361F8 = (__int64)icnss_wpss_self_recovery;
                                init_timer_key(v10 + 6056, icnss_wpss_ssr_timeout_hdlr, 0, 0, 0);
                              }
                              icnss_register_ims_service(v10);
                              *(_QWORD *)(v10 + 5528) = v10 + 5528;
                              *(_QWORD *)(v10 + 5536) = v10 + 5528;
                              printk("%sicnss2: Platform driver probed successfully\n", byte_13289B);
                              ipc_log_string(
                                icnss_ipc_log_context,
                                "%sicnss2: Platform driver probed successfully\n",
                                (const char *)&unk_12DBF3);
                              v7 = 0;
                              goto LABEL_16;
                            }
                            v82 = dmam_alloc_attrs(v71 + 16, v81, v10 + 1792, 3264, 0);
                            *(_QWORD *)(v10 + 1824) = v82;
                            if ( !v82 )
                            {
                              printk("%sicnss2: DMA alloc failed for MSA\n", byte_130B32);
                              ipc_log_string(
                                icnss_ipc_log_context,
                                "%sicnss2: DMA alloc failed for MSA\n",
                                (const char *)&unk_12DBF3);
                              v7 = -12;
                              goto LABEL_231;
                            }
                            v77 = *v79;
                            v78 = (const void *)v82;
LABEL_132:
                            ipc_log_string(
                              icnss_ipc_log_context,
                              "icnss2: MSA pa: %pa, MSA va: 0x%pK MSA Memory Size: 0x%x\n",
                              (const void *)(v10 + 1792),
                              v78,
                              v77);
                            *(_BYTE *)(v10 + 345) = of_find_property(
                                                      *(_QWORD *)(*(_QWORD *)(v10 + 8) + 760LL),
                                                      "qcom,fw-prefix",
                                                      0) != 0;
                            goto LABEL_133;
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
    printk("%sicnss2: Fail to get IRQ-%d\n", byte_130B32, v44);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Fail to get IRQ-%d\n", &unk_12DBF3, v44);
    goto LABEL_191;
  }
  if ( v24 != 25680 && v24 != 26448 )
    goto LABEL_122;
LABEL_100:
  v59 = (__int64 *)platform_get_resource_byname(v19, 512, "msi_addr");
  if ( !v59 )
  {
    v107 = "%sicnss2: MSI address not found in DT\n";
    printk("%sicnss2: MSI address not found in DT\n", byte_130B32);
LABEL_187:
    ipc_log_string(icnss_ipc_log_context, v107, &unk_12DBF3);
    v7 = -22;
    goto LABEL_192;
  }
  v60 = *v59;
  *(_QWORD *)(v10 + 1800) = *v59;
  v61 = dma_map_resource(v19 + 16, v60, 4096, 2, 0);
  *(_QWORD *)(v10 + 1808) = v61;
  if ( v61 == -1 )
  {
    printk("%sicnss2: MSI: failed to map msi address\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: MSI: failed to map msi address\n", (const char *)&unk_12DBF3);
    *(_QWORD *)(v10 + 1808) = 0;
    v7 = -12;
    goto LABEL_192;
  }
  ipc_log_string(icnss_ipc_log_context, "icnss2: MSI Addr pa: %pa, iova: %lluK\n", (const void *)(v10 + 1800), v61);
  v62 = of_property_read_u32_index(*(_QWORD *)(v19 + 760), "interrupts", 1, &v173);
  if ( v62 )
  {
    v7 = v62;
    ipc_log_string(icnss_ipc_log_context, "icnss2: Read interrupt prop failed");
    goto LABEL_192;
  }
  v63 = v173;
  v64 = icnss_ipc_log_context;
  v65 = v173 + 32;
  *(_DWORD *)(v10 + 320) = v173 + 32;
  ipc_log_string(v64, "icnss2:  MSI Base Data: %d, IRQ Index: %d\n", v65, v63);
  v66 = *(_QWORD *)(v10 + 304);
  switch ( v66 )
  {
    case 25680LL:
      v67 = (int *)&msi_config_wcn6450;
      goto LABEL_115;
    case 26448LL:
      v67 = (int *)&msi_config_wcn6750;
LABEL_115:
      *(_QWORD *)(v10 + 312) = v67;
      goto LABEL_117;
    case 30544LL:
      v67 = (int *)&msi_config_wcn7750;
      goto LABEL_115;
  }
  v67 = *(int **)(v10 + 312);
LABEL_117:
  if ( *v67 < 1 )
    goto LABEL_122;
  v68 = 0;
  while ( 1 )
  {
    v69 = platform_get_irq(*(_QWORD *)(v10 + 8), (unsigned int)v68);
    if ( v69 < 0 )
      break;
    if ( v68 == 32 )
      goto LABEL_72;
    v70 = *(int **)(v10 + 312);
    *(_DWORD *)(v10 + 396 + 4 * v68++) = v69;
    if ( v68 >= *v70 )
      goto LABEL_122;
  }
  printk("%sicnss2: Fail to get IRQ-%d\n", byte_130B32, v68);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Fail to get IRQ-%d\n", &unk_12DBF3, (unsigned int)v68);
LABEL_191:
  v7 = -19;
LABEL_192:
  icnss_put_clk(v10);
LABEL_193:
  icnss_put_vreg(v10);
LABEL_18:
  *(_QWORD *)(a1 + 168) = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v7;
}
