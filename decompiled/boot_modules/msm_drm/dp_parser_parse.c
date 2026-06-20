__int64 __fastcall dp_parser_parse(__int64 *a1)
{
  __int64 v1; // x20
  __int64 string_helper; // x0
  int v4; // w21
  __int64 v5; // x0
  __int64 v6; // x4
  __int64 v7; // x19
  __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 v11; // x22
  _DWORD *v12; // x26
  const char *v13; // x21
  unsigned __int8 *property; // x0
  int v15; // w28
  int v16; // w8
  unsigned __int8 *v17; // x27
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x20
  _BYTE *v26; // x0
  _BYTE *v27; // x0
  char v28; // w8
  char v29; // w8
  char v30; // w8
  __int64 v31; // x0
  const char *v32; // x8
  __int64 v33; // x0
  __int64 v34; // x23
  __int64 v35; // x0
  __int64 v36; // x0
  int v37; // w20
  unsigned int v38; // w21
  int v39; // w22
  int v40; // w27
  int v41; // w19
  int v42; // w28
  __int64 v43; // x0
  __int64 *v44; // x26
  __int64 v45; // x0
  __int64 v46; // x28
  __int64 result; // x0
  __int64 v48; // x0
  __int64 v49; // x1
  __int64 v50; // x0
  int v51; // w25
  __int64 v52; // x0
  int v53; // w20
  unsigned int v54; // w21
  int v55; // w24
  int v56; // w27
  int v57; // w22
  __int64 v58; // x19
  char *v59; // x26
  size_t v60; // x0
  unsigned __int64 v61; // x2
  __int64 v62; // x19
  __int64 v63; // x19
  char *v64; // x26
  __int64 v65; // x19
  __int64 v66; // x0
  __int64 v67; // x19
  char *v68; // x26
  __int64 v69; // x19
  __int64 v70; // x19
  char *v71; // x26
  __int64 v72; // x0
  __int64 v73; // x25
  _QWORD *v74; // x28
  const char *v75; // x20
  unsigned int *v76; // x26
  __int64 v77; // x0
  __int64 child_by_name; // x0
  __int64 v79; // x22
  __int64 next_available_child; // x0
  __int64 v81; // x1
  int v82; // w19
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 next_child; // x0
  __int64 v86; // x20
  int v87; // w28
  __int64 string; // x0
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x8
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 ipc_log_context; // x0
  void *v99; // x0
  const char *v100; // x1
  __int64 v101; // x0
  unsigned int v102; // w20
  __int64 v103; // x0
  void *v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x0
  __int64 v108; // x0
  unsigned int v109; // w22
  __int64 v110; // x0
  int v111; // w2
  const char *v112; // x21
  unsigned int v113; // w19
  __int64 v114; // x0
  unsigned int v115; // w20
  _QWORD *v116; // x20
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  void *v120; // x0
  __int64 v121; // x0
  __int64 v122; // x1
  unsigned __int64 v123; // x21
  _QWORD *v124; // x20
  __int64 v125; // x1
  __int64 v126; // x24
  unsigned __int64 v127; // x20
  _QWORD *v128; // x23
  __int64 v129; // x1
  unsigned __int64 v130; // x21
  _QWORD *v131; // x23
  __int64 v132; // x1
  unsigned __int64 v133; // x20
  _QWORD *v134; // x23
  __int64 v135; // x1
  _QWORD *v136; // x8
  _QWORD *v137; // x21
  __int64 v138; // x1
  _QWORD *v139; // x8
  _QWORD *v140; // x19
  __int64 v141; // x0
  __int64 v142; // x0
  int v143; // [xsp+18h] [xbp-48h]
  int v144; // [xsp+1Ch] [xbp-44h]
  int v145; // [xsp+20h] [xbp-40h]
  __int64 v146; // [xsp+20h] [xbp-40h]
  int v147; // [xsp+28h] [xbp-38h]
  _QWORD *v148; // [xsp+28h] [xbp-38h]
  __int64 *v149; // [xsp+30h] [xbp-30h]
  unsigned __int64 StatusReg; // [xsp+38h] [xbp-28h]
  char *v151; // [xsp+40h] [xbp-20h] BYREF
  int v152; // [xsp+4Ch] [xbp-14h] BYREF
  char *v153[2]; // [xsp+50h] [xbp-10h] BYREF

  v153[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v99 = &unk_275B6D;
    v100 = "dp_parser_parse";
LABEL_209:
    printk(v99, v100);
    result = 4294967274LL;
    goto LABEL_210;
  }
  v1 = *a1;
  string_helper = of_property_read_string_helper(*(_QWORD *)(*a1 + 760), "reg-names", 0, 0, 0);
  if ( !(_DWORD)string_helper )
  {
    v101 = get_ipc_log_context(string_helper);
    ipc_log_string(v101, "[e][%-4d]no reg defined\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v99 = &unk_21BCB4;
    v100 = "dp_parser_reg";
    goto LABEL_209;
  }
  v4 = string_helper;
  *((_DWORD *)a1 + 100) = string_helper;
  v5 = devm_kmalloc(v1 + 16, 32LL * (unsigned int)string_helper, 3520);
  a1[51] = v5;
  if ( !v5 )
  {
    result = 4294967284LL;
    goto LABEL_210;
  }
  v6 = 0;
  do
  {
    v7 = 32LL * (int)v6;
    v8 = (int)v6;
    of_property_read_string_helper(*(_QWORD *)(v1 + 760), "reg-names", a1[51] + v7, 1, v6);
    v9 = msm_dss_ioremap_byname(v1, a1[51] + v7 + 16, *(_QWORD *)(a1[51] + v7));
    if ( (_DWORD)v9 )
    {
      v113 = v9;
      v114 = get_ipc_log_context(v9);
      ipc_log_string(
        v114,
        "[e][%-4d]unable to remap %s resources\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(const char **)(a1[51] + 32 * v8));
      printk(&unk_278E77, "dp_parser_reg");
      if ( *((_DWORD *)a1 + 100) )
      {
        v115 = 0;
        do
          msm_dss_iounmap(a1[51] + 32LL * (int)v115++ + 16);
        while ( v115 < *((_DWORD *)a1 + 100) );
      }
      result = v113;
      goto LABEL_210;
    }
    v6 = (unsigned int)(v8 + 1);
  }
  while ( v4 != (_DWORD)v6 );
  v10 = 0;
  v11 = *(_QWORD *)(*a1 + 760);
  v149 = a1;
  v12 = (_DWORD *)a1 + 121;
  LODWORD(v153[0]) = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v13 = "unknown";
    if ( (unsigned int)v10 <= 9 )
      v13 = off_280640[v10];
    property = (unsigned __int8 *)of_get_property(v11, v13, v153);
    if ( !property )
    {
      v116 = a1 + 58;
      v117 = get_ipc_log_context(0);
      ipc_log_string(v117, "[e][%-4d]Unable to read %s\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v13);
      printk(&unk_23075A, "dp_parser_aux");
LABEL_160:
      v116[28] = 0;
      v116[29] = 0;
      result = 4294967274LL;
      v116[26] = 0;
      v116[27] = 0;
      v116[24] = 0;
      v116[25] = 0;
      v116[22] = 0;
      v116[23] = 0;
      v116[20] = 0;
      v116[21] = 0;
      v116[18] = 0;
      v116[19] = 0;
      v116[16] = 0;
      v116[17] = 0;
      v116[14] = 0;
      v116[15] = 0;
      v116[12] = 0;
      v116[13] = 0;
      v116[10] = 0;
      v116[11] = 0;
      v116[8] = 0;
      v116[9] = 0;
      v116[6] = 0;
      v116[7] = 0;
      v116[4] = 0;
      v116[5] = 0;
      v116[2] = 0;
      v116[3] = 0;
      *v116 = 0;
      v116[1] = 0;
      goto LABEL_210;
    }
    v15 = LODWORD(v153[0]) - 1;
    if ( (unsigned int)(LODWORD(v153[0]) - 5) <= 0xFFFFFFFC )
    {
      v116 = a1 + 58;
      v118 = get_ipc_log_context(property);
      ipc_log_string(
        v118,
        "[e][%-4d]Invalid config count (%d) configs for %s\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v15,
        v13);
      printk(&unk_241855, "dp_parser_aux");
      goto LABEL_160;
    }
    v16 = *property;
    v17 = property;
    *(v12 - 5) = v15;
    *(v12 - 3) = v16;
    v18 = get_ipc_log_context(property);
    v19 = ipc_log_string(
            v18,
            "[d][%-4d]%s offset=0x%x, cfg_cnt=%d\n",
            *(_DWORD *)(StatusReg + 1800),
            v13,
            *(v12 - 3),
            *(v12 - 5));
    if ( (_drm_debug & 4) != 0 )
      v19 = _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s offset=0x%x, cfg_cnt=%d\n",
              *(_DWORD *)(StatusReg + 1800),
              v13,
              *(v12 - 3),
              *(v12 - 5));
    if ( SLODWORD(v153[0]) >= 2 )
    {
      *(v12 - 2) = v17[1];
      v20 = get_ipc_log_context(v19);
      v21 = ipc_log_string(v20, "[d][%-4d]%s lut[%d]=0x%x\n", *(_DWORD *)(StatusReg + 1800), v13, v10, *(v12 - 2));
      if ( (_drm_debug & 4) != 0 )
        v21 = _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]%s lut[%d]=0x%x\n",
                *(_DWORD *)(StatusReg + 1800),
                v13,
                v10,
                *(v12 - 2));
      if ( SLODWORD(v153[0]) >= 3 )
      {
        *(v12 - 1) = v17[2];
        v22 = get_ipc_log_context(v21);
        v23 = ipc_log_string(v22, "[d][%-4d]%s lut[%d]=0x%x\n", *(_DWORD *)(StatusReg + 1800), v13, v10, *(v12 - 1));
        if ( (_drm_debug & 4) != 0 )
          v23 = _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "[msm-dp-debug][%-4d]%s lut[%d]=0x%x\n",
                  *(_DWORD *)(StatusReg + 1800),
                  v13,
                  v10,
                  *(v12 - 1));
        if ( SLODWORD(v153[0]) >= 4 )
        {
          *v12 = v17[3];
          v24 = get_ipc_log_context(v23);
          ipc_log_string(v24, "[d][%-4d]%s lut[%d]=0x%x\n", *(_DWORD *)(StatusReg + 1800), v13, v10, *v12);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s lut[%d]=0x%x\n",
              *(_DWORD *)(StatusReg + 1800),
              v13,
              v10,
              *v12);
          if ( SLODWORD(v153[0]) > 4 )
            goto LABEL_224;
        }
      }
    }
    ++v10;
    v12 += 6;
  }
  while ( v10 != 10 );
  LODWORD(v153[0]) = 0;
  v25 = *(_QWORD *)(*a1 + 760);
  v26 = (_BYTE *)of_get_property(v25, "qcom,logical2physical-lane-map", v153);
  if ( v26 && LODWORD(v153[0]) == 4 )
  {
    *((_BYTE *)a1 + 456) = *v26;
    *((_BYTE *)a1 + 457) = v26[1];
    *((_BYTE *)a1 + 458) = v26[2];
    *((_BYTE *)a1 + 459) = v26[3];
  }
  v27 = (_BYTE *)of_get_property(v25, "qcom,pn-swap-lane-map", v153);
  if ( v27 && LODWORD(v153[0]) == 4 )
  {
    v28 = *((_BYTE *)a1 + 460) | *v27 & 1;
    *((_BYTE *)a1 + 460) = v28;
    v29 = v28 | (2 * (v27[1] & 1));
    *((_BYTE *)a1 + 460) = v29;
    v30 = v29 | (4 * (v27[2] & 1));
    *((_BYTE *)a1 + 460) = v30;
    *((_BYTE *)a1 + 460) = v30 | (8 * (v27[3] & 1));
  }
  if ( (of_property_read_variable_u32_array(v25, "qcom,max-pclk-frequency-khz", a1 + 88, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)a1 + 176) = 675000;
  if ( (of_property_read_variable_u32_array(v25, "qcom,max-lclk-frequency-khz", (char *)a1 + 708, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)a1 + 177) = 810000;
  of_property_read_u32_index(v25, "qcom,pclk-reg-off", 0, a1 + 96);
  of_property_read_u32_index(v25, "qcom,pclk-reg-off", 1, (char *)a1 + 772);
  v31 = of_get_property(v25, "qcom,display-type", 0);
  if ( v31 )
    v32 = (const char *)v31;
  else
    v32 = "unknown";
  a1[99] = (__int64)v32;
  if ( (of_property_read_variable_u32_array(v25, "qcom,shallow-mode-retries", a1 + 92, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)a1 + 184) = 5;
  *((_BYTE *)a1 + 740) = of_find_property(v25, "qcom,no-backlight-support", 0) != 0;
  v33 = of_find_property(v25, "qcom,dp-ext-hpd", 0);
  v34 = *a1;
  *((_BYTE *)a1 + 741) = v33 != 0;
  v35 = *(_QWORD *)(v34 + 760);
  v152 = 0;
  v151 = nullptr;
  v153[0] = nullptr;
  v36 = of_property_read_string_helper(v35, "clock-names", 0, 0, 0);
  if ( (int)v36 < 1 )
  {
    v119 = get_ipc_log_context(v36);
    ipc_log_string(v119, "[e][%-4d]no clocks are defined\n", *(_DWORD *)(StatusReg + 1800));
    v120 = &unk_222E6F;
LABEL_163:
    v45 = printk(v120, "dp_parser_init_clk_data");
    goto LABEL_208;
  }
  v37 = v36;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  do
  {
    of_property_read_string_helper(*(_QWORD *)(v34 + 760), "clock-names", v153, 1, v38);
    v39 += dp_parser_check_prefix((int)"core", v153[0]) & 1;
    v41 += dp_parser_check_prefix((int)"strm0", v153[0]) & 1;
    v42 += dp_parser_check_prefix((int)"strm1", v153[0]) & 1;
    v43 = dp_parser_check_prefix((int)"link", v153[0]);
    ++v38;
    v40 += v43 & 1;
  }
  while ( v37 != v38 );
  if ( v39 <= 0 )
  {
    v121 = get_ipc_log_context(v43);
    ipc_log_string(v121, "[e][%-4d]no core clocks are defined\n", *(_DWORD *)(StatusReg + 1800));
    v120 = &unk_259473;
    goto LABEL_163;
  }
  v44 = a1;
  *((_DWORD *)a1 + 12) = v39;
  v45 = devm_kmalloc(v34 + 16, 120LL * (unsigned int)v39, 3520);
  a1[7] = v45;
  if ( !v45 )
  {
LABEL_208:
    v142 = get_ipc_log_context(v45);
    ipc_log_string(v142, "[e][%-4d]failed to initialize power data\n", *(_DWORD *)(StatusReg + 1800));
    v99 = &unk_26452D;
    v100 = "dp_parser_clock";
    goto LABEL_209;
  }
  if ( v41 <= 0 )
  {
    v48 = get_ipc_log_context(v45);
    v45 = ipc_log_string(v48, "[d][%-4d]no strm0 clocks are defined\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      v45 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]no strm0 clocks are defined\n", *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    *((_DWORD *)a1 + 48) = v41;
    v45 = devm_kmalloc(v34 + 16, 120LL * (unsigned int)v41, 3520);
    a1[25] = v45;
    if ( !v45 )
    {
      *((_DWORD *)a1 + 48) = 0;
      v46 = v34;
      goto LABEL_205;
    }
  }
  if ( v42 <= 0 )
  {
    v50 = get_ipc_log_context(v45);
    v45 = ipc_log_string(v50, "[d][%-4d]no strm1 clocks are defined\n", *(_DWORD *)(StatusReg + 1800));
    v46 = v34;
    if ( (_drm_debug & 4) != 0 )
      v45 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]no strm1 clocks are defined\n", *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    v49 = 120LL * (unsigned int)v42;
    *((_DWORD *)a1 + 60) = v42;
    v46 = v34;
    v45 = devm_kmalloc(v34 + 16, v49, 3520);
    a1[31] = v45;
    if ( !v45 )
      goto LABEL_203;
  }
  if ( v40 <= 0 )
  {
    v141 = get_ipc_log_context(v45);
    ipc_log_string(v141, "[e][%-4d]no link clocks are defined\n", *(_DWORD *)(StatusReg + 1800));
    v45 = printk(&unk_210D34, "dp_parser_init_clk_data");
    if ( a1 != (__int64 *)-208LL )
      goto LABEL_201;
    goto LABEL_196;
  }
  *((_DWORD *)a1 + 72) = v40;
  v45 = devm_kmalloc(v46 + 16, 120LL * (unsigned int)v40, 3520);
  a1[37] = v45;
  if ( !v45 )
  {
    *((_DWORD *)a1 + 72) = 0;
    if ( a1 != (__int64 *)-208LL )
    {
LABEL_201:
      if ( a1[31] )
      {
        v45 = devm_kfree(v46 + 16);
        a1[31] = 0;
      }
LABEL_203:
      *((_DWORD *)a1 + 60) = 0;
      if ( a1 == (__int64 *)-160LL )
      {
        v45 = printk(&unk_23A915, "dp_parser_put_clk_data");
LABEL_205:
        if ( a1[7] )
        {
          v45 = devm_kfree(v46 + 16);
          a1[7] = 0;
        }
        *((_DWORD *)a1 + 12) = 0;
        goto LABEL_208;
      }
LABEL_197:
      if ( a1[25] )
      {
        v45 = devm_kfree(v46 + 16);
        a1[25] = 0;
      }
      *((_DWORD *)a1 + 48) = 0;
      goto LABEL_205;
    }
LABEL_196:
    v45 = printk(&unk_23A915, "dp_parser_put_clk_data");
    goto LABEL_197;
  }
  v51 = *((_DWORD *)a1 + 12);
  v147 = *((_DWORD *)a1 + 72);
  v143 = *((_DWORD *)a1 + 60);
  v144 = *((_DWORD *)a1 + 48);
  v52 = of_property_read_string_helper(*(_QWORD *)(v46 + 760), "clock-names", 0, 0, 0);
  if ( (int)v52 >= 1 )
  {
    v53 = v52;
    v54 = 0;
    v55 = 0;
    v56 = 0;
    v57 = 0;
    v145 = 0;
    do
    {
      of_property_read_string_helper(*(_QWORD *)(v46 + 760), "clock-names", &v151, 1, v54);
      if ( (dp_parser_check_prefix((int)"core", v151) & 1) != 0 && v55 < v51 )
      {
        v58 = v44[7];
        v59 = v151;
        v60 = strnlen(v151, 0x20u);
        if ( v60 == -1 )
          goto LABEL_222;
        if ( v60 == 32 )
          v61 = 32;
        else
          v61 = v60 + 1;
        if ( v61 >= 0x21 )
          goto LABEL_223;
        v62 = v58 + 120LL * v55;
        v52 = sized_strscpy(v62 + 8, v59);
        *(_DWORD *)(v62 + 40) = 0;
        ++v55;
      }
      else if ( (dp_parser_check_prefix((int)"link", v151) & 1) != 0 && v56 < v147 )
      {
        v63 = v44[37];
        v64 = v151;
        v60 = strnlen(v151, 0x20u);
        if ( v60 == -1 )
          goto LABEL_222;
        if ( v60 == 32 )
          v61 = 32;
        else
          v61 = v60 + 1;
        if ( v61 >= 0x21 )
          goto LABEL_223;
        v65 = v63 + 120LL * v56;
        sized_strscpy(v65 + 8, v64);
        v66 = *(_QWORD *)(v46 + 760);
        ++v56;
        v152 = 0;
        v52 = of_property_read_u32_index(v66, "clock-mmrm", v54, &v152);
        if ( !v152 )
        {
          v52 = strcmp(v151, "link_clk_src");
          v44 = v149;
          if ( (_DWORD)v52 )
            *(_DWORD *)(v65 + 40) = 0;
          else
            *(_DWORD *)(v65 + 40) = 1;
          goto LABEL_62;
        }
        *(_DWORD *)(v65 + 40) = 2;
        *(_DWORD *)(v65 + 64) = v152;
      }
      else
      {
        if ( (dp_parser_check_prefix((int)"strm0", v151) & 1) != 0 && v57 < v144 )
        {
          v67 = v44[25];
          v68 = v151;
          v60 = strnlen(v151, 0x20u);
          if ( v60 == -1 )
            goto LABEL_222;
          if ( v60 == 32 )
            v61 = 32;
          else
            v61 = v60 + 1;
          if ( v61 >= 0x21 )
            goto LABEL_223;
          v69 = v67 + 120LL * v57;
          v52 = sized_strscpy(v69 + 8, v68);
          ++v57;
        }
        else
        {
          v52 = dp_parser_check_prefix((int)"strm1", v151);
          if ( (v52 & 1) == 0 || v145 >= v143 )
            goto LABEL_62;
          v70 = v44[31];
          v71 = v151;
          v60 = strnlen(v151, 0x20u);
          if ( v60 == -1 )
          {
LABEL_222:
            _fortify_panic(2, -1, v60 + 1);
LABEL_223:
            _fortify_panic(7, 32, v61);
LABEL_224:
            __break(0x5512u);
          }
          if ( v60 == 32 )
            v61 = 32;
          else
            v61 = v60 + 1;
          if ( v61 >= 0x21 )
            goto LABEL_223;
          v69 = v70 + 120LL * v145;
          v52 = sized_strscpy(v69 + 8, v71);
          ++v145;
        }
        *(_DWORD *)(v69 + 40) = 1;
      }
      v44 = v149;
LABEL_62:
      ++v54;
    }
    while ( v53 != v54 );
  }
  v72 = get_ipc_log_context(v52);
  ipc_log_string(v72, "[d][%-4d]clock parsing successful\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]clock parsing successful\n", *(_DWORD *)(StatusReg + 1800));
  v73 = 0;
  v74 = v44 + 2;
  v146 = *v44;
  v148 = v44 + 2;
  while ( 2 )
  {
    v75 = "???";
    v76 = (unsigned int *)&v74[6 * v73];
    LODWORD(v151) = 0;
    v77 = *(_QWORD *)(*v149 + 760);
    *v76 = 0;
    if ( (unsigned int)v73 <= 6 )
      v75 = off_280690[v73 & 7];
    child_by_name = of_get_child_by_name(v77, v75);
    if ( !child_by_name )
    {
      v96 = get_ipc_log_context(0);
      ipc_log_string(v96, "[d][%-4d]no supply entry present: %s\n", *(_DWORD *)(StatusReg + 1800), v75);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]no supply entry present: %s\n", *(_DWORD *)(StatusReg + 1800), v75);
      goto LABEL_102;
    }
    v79 = child_by_name;
    next_available_child = of_get_next_available_child(child_by_name, 0);
    if ( !next_available_child )
    {
      *v76 = 0;
      goto LABEL_127;
    }
    v81 = next_available_child;
    v82 = 0;
    do
    {
      v81 = of_get_next_available_child(v79, v81);
      --v82;
    }
    while ( v81 );
    *v76 = -v82;
    if ( !v82 )
    {
LABEL_127:
      v97 = get_ipc_log_context(0);
      ipc_log_string(v97, "[d][%-4d]no vreg\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]no vreg\n", *(_DWORD *)(StatusReg + 1800));
LABEL_102:
      *v76 = 0;
      goto LABEL_103;
    }
    v83 = get_ipc_log_context(0);
    ipc_log_string(v83, "[d][%-4d]vreg found. count=%d\n", *(_DWORD *)(StatusReg + 1800), *v76);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]vreg found. count=%d\n", *(_DWORD *)(StatusReg + 1800), *v76);
    v84 = devm_kmalloc(*v149 + 16, 72LL * *v76, 3520);
    *((_QWORD *)v76 + 1) = v84;
    if ( !v84 )
    {
      v109 = -12;
      goto LABEL_142;
    }
    next_child = of_get_next_child(v79, 0);
    if ( !next_child )
    {
LABEL_129:
      v74 = v148;
LABEL_103:
      if ( ++v73 == 7 )
      {
        result = dp_parser_gpio(v149);
        if ( !(_DWORD)result )
        {
          dp_parser_catalog(v149);
          result = dp_parser_pinctrl(v149);
          if ( !(_DWORD)result )
          {
            dp_parser_msm_hdcp_dev(v149);
            dp_parser_mst(v149);
            dp_parser_dsc(v149);
            dp_parser_fec(v149);
            dp_parser_widebus(v149);
            dp_parser_qos(v149);
            dp_parser_link_training_params(v149);
            result = 0;
          }
        }
        goto LABEL_210;
      }
      continue;
    }
    break;
  }
  v86 = next_child;
  v87 = 0;
  while ( 1 )
  {
    v153[0] = nullptr;
    string = of_property_read_string(v86, "qcom,supply-name", v153);
    if ( (_DWORD)string )
    {
      v102 = string;
      v103 = get_ipc_log_context(string);
      ipc_log_string(v103, "[e][%-4d]error reading name. rc=%d\n", *(_DWORD *)(StatusReg + 1800), v102);
      v104 = &unk_22CE6D;
      goto LABEL_140;
    }
    snprintf((char *)(*((_QWORD *)v76 + 1) + 72LL * v87 + 8), 0x20u, "%s", v153[0]);
    v89 = of_property_read_variable_u32_array(v86, "qcom,supply-min-voltage", &v151, 1, 0);
    if ( (v89 & 0x80000000) != 0 )
    {
      v102 = v89;
      v105 = get_ipc_log_context(v89);
      ipc_log_string(v105, "[e][%-4d]error reading min volt. rc=%d\n", *(_DWORD *)(StatusReg + 1800), v102);
      v104 = &unk_2522B5;
      goto LABEL_140;
    }
    *(_DWORD *)(*((_QWORD *)v76 + 1) + 72LL * v87 + 40) = (_DWORD)v151;
    v90 = of_property_read_variable_u32_array(v86, "qcom,supply-max-voltage", &v151, 1, 0);
    if ( (v90 & 0x80000000) != 0 )
    {
      v102 = v90;
      v106 = get_ipc_log_context(v90);
      ipc_log_string(v106, "[e][%-4d]error reading max volt. rc=%d\n", *(_DWORD *)(StatusReg + 1800), v102);
      v104 = &unk_222EA2;
      goto LABEL_140;
    }
    *(_DWORD *)(*((_QWORD *)v76 + 1) + 72LL * v87 + 44) = (_DWORD)v151;
    v91 = of_property_read_variable_u32_array(v86, "qcom,supply-enable-load", &v151, 1, 0);
    if ( (v91 & 0x80000000) != 0 )
    {
      v102 = v91;
      v107 = get_ipc_log_context(v91);
      ipc_log_string(v107, "[e][%-4d]error reading enable load. rc=%d\n", *(_DWORD *)(StatusReg + 1800), v102);
      v104 = &unk_22CEA4;
      goto LABEL_140;
    }
    *(_DWORD *)(*((_QWORD *)v76 + 1) + 72LL * v87 + 48) = (_DWORD)v151;
    v92 = of_property_read_variable_u32_array(v86, "qcom,supply-disable-load", &v151, 1, 0);
    if ( (v92 & 0x80000000) != 0 )
      break;
    *(_DWORD *)(*((_QWORD *)v76 + 1) + 72LL * v87 + 52) = (_DWORD)v151;
    v93 = get_ipc_log_context(v92);
    v94 = *((_QWORD *)v76 + 1) + 72LL * v87;
    ipc_log_string(
      v93,
      "[d][%-4d]%s min=%d, max=%d, enable=%d, disable=%d\n",
      *(_DWORD *)(StatusReg + 1800),
      (const char *)(v94 + 8),
      *(_DWORD *)(v94 + 40),
      *(_DWORD *)(v94 + 44),
      *(_DWORD *)(v94 + 48),
      *(_DWORD *)(v94 + 52));
    if ( (_drm_debug & 4) != 0 )
    {
      v95 = *((_QWORD *)v76 + 1) + 72LL * v87;
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]%s min=%d, max=%d, enable=%d, disable=%d\n",
        *(_DWORD *)(StatusReg + 1800),
        (const char *)(v95 + 8),
        *(_DWORD *)(v95 + 40),
        *(_DWORD *)(v95 + 44),
        *(_DWORD *)(v95 + 48),
        *(_DWORD *)(v95 + 52));
    }
    ++v87;
    v86 = of_get_next_child(v79, v86);
    if ( !v86 )
      goto LABEL_129;
  }
  v102 = v92;
  v108 = get_ipc_log_context(v92);
  ipc_log_string(v108, "[e][%-4d]error reading disable load. rc=%d\n", *(_DWORD *)(StatusReg + 1800), v102);
  v104 = &unk_255D67;
LABEL_140:
  v109 = v102;
  v84 = printk(v104, "dp_parser_get_vreg");
  v74 = v148;
  if ( *((_QWORD *)v76 + 1) )
  {
    v84 = devm_kfree(*v149 + 16);
    *((_QWORD *)v76 + 1) = 0;
  }
LABEL_142:
  *v76 = 0;
  v110 = get_ipc_log_context(v84);
  v111 = *(_DWORD *)(StatusReg + 1800);
  if ( (int)v73 <= 2 )
  {
    if ( (_DWORD)v73 )
    {
      if ( (_DWORD)v73 == 1 )
      {
        v112 = "DP_CTRL_PM";
      }
      else
      {
        if ( (_DWORD)v73 != 2 )
          goto LABEL_166;
        v112 = "DP_PHY_PM";
      }
      goto LABEL_170;
    }
    ipc_log_string(v110, "[e][%-4d]get_dt_vreg_data failed for %s. rc=%d\n", v111, "DP_CORE_PM", v109);
    printk(&unk_255D10, "dp_parser_regulator");
LABEL_165:
    result = v109;
    goto LABEL_210;
  }
  if ( (int)v73 > 4 )
  {
    if ( (_DWORD)v73 == 5 )
    {
      v112 = "DP_LINK_PM";
    }
    else
    {
      if ( (_DWORD)v73 != 6 )
        goto LABEL_166;
      v112 = "DP_PLL_PM";
    }
  }
  else if ( (_DWORD)v73 == 3 )
  {
    v112 = "DP_STREAM0_PM";
  }
  else
  {
    if ( (_DWORD)v73 == 4 )
    {
      v112 = "DP_STREAM1_PM";
      goto LABEL_170;
    }
LABEL_166:
    v112 = "???";
  }
LABEL_170:
  ipc_log_string(v110, "[e][%-4d]get_dt_vreg_data failed for %s. rc=%d\n", v111, v112, v109);
  printk(&unk_255D10, "dp_parser_regulator");
  v123 = (unsigned int)v73 - 1LL;
  v124 = &v74[6 * v123];
  if ( v124 )
  {
    v125 = v124[1];
    v126 = v146;
    if ( v125 )
    {
      devm_kfree(v146 + 16);
      v124[1] = 0;
    }
    *(_DWORD *)v124 = 0;
  }
  else
  {
    printk(&unk_275CE5, v122);
    v126 = v146;
  }
  v127 = (unsigned int)v73 - 2LL;
  result = v109;
  if ( (unsigned int)v73 >= 2uLL )
  {
    v128 = &v74[6 * v127];
    if ( v128 )
    {
      v129 = v128[1];
      if ( v129 )
      {
        devm_kfree(v126 + 16);
        result = v109;
        v128[1] = 0;
      }
      *(_DWORD *)v128 = 0;
      if ( v123 >= 2 )
      {
LABEL_179:
        v130 = (unsigned int)v73 - 3LL;
        v131 = &v74[6 * v130];
        if ( v131 )
        {
          v132 = v131[1];
          if ( v132 )
          {
            devm_kfree(v126 + 16);
            result = v109;
            v131[1] = 0;
          }
          *(_DWORD *)v131 = 0;
          if ( v127 >= 2 )
          {
LABEL_183:
            v133 = (unsigned int)v73 - 4LL;
            v134 = &v74[6 * v133];
            if ( v134 )
            {
              v135 = v134[1];
              if ( v135 )
              {
                devm_kfree(v126 + 16);
                result = v109;
                v134[1] = 0;
              }
              *(_DWORD *)v134 = 0;
              if ( v130 >= 2 )
              {
LABEL_187:
                v136 = &v74[6 * (unsigned int)v73];
                v137 = v136 - 30;
                if ( v136 == &_ksymtab_msm_dss_iounmap )
                {
                  printk(&unk_275CE5, v135);
                  result = v109;
                  if ( v133 >= 2 )
                    goto LABEL_191;
                }
                else
                {
                  v138 = *(v136 - 29);
                  if ( v138 )
                  {
                    devm_kfree(v126 + 16);
                    result = v109;
                    v137[1] = 0;
                  }
                  *(_DWORD *)v137 = 0;
                  if ( v133 >= 2 )
                  {
LABEL_191:
                    v139 = &v74[6 * (unsigned int)v73];
                    v140 = v139 - 36;
                    if ( v139 == (_QWORD *)&_ksymtab_msm_dss_single_clk_set_rate )
                    {
                      printk(&unk_275CE5, v138);
                    }
                    else
                    {
                      if ( *(v139 - 35) )
                      {
                        devm_kfree(v126 + 16);
                        v140[1] = 0;
                      }
                      *(_DWORD *)v140 = 0;
                    }
                    goto LABEL_165;
                  }
                }
              }
            }
            else
            {
              printk(&unk_275CE5, v132);
              result = v109;
              if ( v130 >= 2 )
                goto LABEL_187;
            }
          }
        }
        else
        {
          printk(&unk_275CE5, v129);
          result = v109;
          if ( v127 >= 2 )
            goto LABEL_183;
        }
      }
    }
    else
    {
      printk(&unk_275CE5, v125);
      result = v109;
      if ( v123 >= 2 )
        goto LABEL_179;
    }
  }
LABEL_210:
  _ReadStatusReg(SP_EL0);
  return result;
}
