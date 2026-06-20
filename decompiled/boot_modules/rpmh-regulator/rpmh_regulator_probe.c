__int64 __fastcall rpmh_regulator_probe(__int64 a1)
{
  __int64 v1; // x23
  _DWORD *v2; // x25
  __int64 v3; // x21
  _QWORD *v4; // x0
  _QWORD *v5; // x19
  _QWORD *v6; // x28
  __int64 matched; // x0
  unsigned int string; // w0
  int addr; // w0
  __int64 v10; // x2
  unsigned int slave_id; // w26
  int v12; // w3
  bool v13; // zf
  int v14; // w8
  __int64 v15; // x0
  unsigned __int8 *v16; // x0
  char *v17; // x3
  int v18; // w8
  __int64 v19; // x10
  unsigned __int8 *v20; // x8
  char *v21; // x9
  int v22; // w11
  int v23; // w11
  __int64 v24; // x12
  __int64 v25; // x8
  __int64 v26; // x24
  unsigned int v27; // w0
  char *v28; // x22
  __int64 v29; // x8
  __int64 v30; // x2
  void *v31; // x0
  int v32; // w9
  __int64 v33; // x20
  _DWORD *v34; // x8
  unsigned __int64 v35; // x8
  int v36; // w9
  __int64 v37; // x0
  unsigned __int64 v38; // x27
  _DWORD *v39; // x22
  _DWORD *v40; // x25
  unsigned int variable_u32_array; // w0
  int v42; // w12
  unsigned __int64 v43; // x8
  _DWORD *v44; // x9
  __int64 v45; // x9
  __int64 v46; // x3
  unsigned __int64 v47; // x10
  unsigned int v48; // w5
  _DWORD *v49; // x12
  bool v50; // cf
  unsigned int v51; // w0
  __int64 v52; // x8
  unsigned __int64 v53; // x10
  __int64 property; // x0
  __int64 v55; // x8
  __int64 next_available_child; // x0
  __int64 v57; // x20
  unsigned __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x22
  int v62; // w20
  unsigned int v63; // w0
  __int64 v64; // x28
  __int64 v65; // x2
  int v66; // w20
  _QWORD *v67; // x23
  __int64 v68; // x8
  char *v69; // x26
  __int64 v70; // x20
  _QWORD *v71; // x0
  _QWORD *v72; // x22
  __int64 v73; // x1
  _DWORD *regulator_init_data; // x0
  int v75; // w8
  _DWORD *v76; // x25
  int v77; // w9
  __int64 v78; // x8
  int v79; // w10
  __int64 v80; // x9
  __int64 v81; // x11
  int v82; // w8
  int v83; // w9
  int v84; // w10
  int v85; // w11
  int v86; // w0
  char v87; // w3
  const char *v88; // x0
  size_t v89; // x20
  __int64 v90; // x0
  __int64 v91; // x22
  size_t v92; // x22
  __int64 v93; // x0
  void *v94; // x20
  __int64 v95; // x0
  int v96; // w8
  __int64 v97; // x10
  __int64 v98; // x8
  __int64 v99; // x9
  __int64 v100; // x10
  int v101; // w9
  _BOOL4 v102; // w8
  unsigned int v103; // w4
  __int64 v104; // x8
  __int64 v105; // x5
  _DWORD *v106; // x10
  int v107; // w11
  __int64 v108; // x9
  int *v109; // x8
  int v110; // w10
  __int64 v111; // x11
  int v112; // t1
  __int64 v113; // x21
  int v114; // w8
  __int64 v115; // x0
  const char *v116; // x1
  __int64 v117; // x2
  void *v118; // x0
  unsigned int v119; // w4
  unsigned __int64 v120; // x0
  unsigned int v121; // w0
  __int64 v122; // x2
  __int64 v123; // x2
  __int64 v124; // x2
  __int64 v126; // x28
  unsigned __int64 StatusReg; // x21
  __int64 v128; // x8
  __int64 v129; // x26
  _QWORD *v130; // [xsp+18h] [xbp-68h]
  _QWORD *v131; // [xsp+18h] [xbp-68h]
  __int64 v132; // [xsp+20h] [xbp-60h]
  _DWORD *v133; // [xsp+28h] [xbp-58h]
  __int64 v134; // [xsp+30h] [xbp-50h]
  unsigned int v135; // [xsp+3Ch] [xbp-44h] BYREF
  char *s1; // [xsp+40h] [xbp-40h] BYREF
  _DWORD *v137; // [xsp+48h] [xbp-38h]
  _QWORD *v138; // [xsp+50h] [xbp-30h]
  __int64 v139; // [xsp+58h] [xbp-28h]
  __int64 v140; // [xsp+60h] [xbp-20h]
  __int64 v141; // [xsp+68h] [xbp-18h]
  int v142; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v143; // [xsp+78h] [xbp-8h]

  v1 = a1 + 16;
  v143 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD **)(a1 + 760);
  if ( !v2 )
  {
    dev_err(a1 + 16, "Device tree node is missing\n");
    slave_id = -22;
    goto LABEL_263;
  }
  v3 = a1;
  v4 = (_QWORD *)devm_kmalloc(a1 + 16, 288, 3520);
  if ( !v4 )
  {
    slave_id = -12;
    goto LABEL_263;
  }
  v5 = v4;
  *v4 = v1;
  v6 = v4 + 3;
  _mutex_init(v4 + 3, "&aggr_vreg->lock", &rpmh_regulator_probe___key);
  matched = of_match_node(&rpmh_regulator_match_table, v2);
  if ( !matched )
  {
    dev_err(v1, "could not find compatible string match\n");
    slave_id = -19;
    goto LABEL_263;
  }
  *((_DWORD *)v5 + 18) = *(_QWORD *)(matched + 192);
  string = of_property_read_string(v2, "qcom,resource-name", v5 + 1);
  if ( string )
  {
    slave_id = string;
    dev_err(v1, "qcom,resource-name missing in DT node\n");
    goto LABEL_263;
  }
  addr = cmd_db_read_addr(v5[1]);
  v10 = v5[1];
  *((_DWORD *)v5 + 4) = addr;
  if ( !addr )
  {
    printk(&unk_9104, "rpmh_regulator_probe", v10);
    slave_id = -19;
    goto LABEL_263;
  }
  slave_id = cmd_db_read_slave_id(v10);
  if ( (slave_id & 0x80000000) != 0 )
  {
    v30 = v5[1];
    v31 = &unk_8BD7;
    goto LABEL_262;
  }
  v12 = *((_DWORD *)v5 + 18);
  if ( slave_id != 3 && v12 == 1
    || (v12 ? (v13 = (v12 & 0xFFFFFFFE) == 2) : (v13 = 1), !v13 ? (v14 = 0) : (v14 = 1), slave_id != 4 && v14) )
  {
    printk(&unk_95A4, "rpmh_regulator_probe", v5[1]);
    slave_id = -22;
    goto LABEL_263;
  }
  if ( v12 == 1 )
  {
    v15 = v5[1];
    s1 = nullptr;
    v16 = (unsigned __int8 *)cmd_db_read_aux_data(v15, &s1);
    slave_id = (unsigned int)v16;
    if ( (unsigned __int64)v16 > 0xFFFFFFFFFFFFF000LL )
    {
      printk(&unk_8E1B, "rpmh_regulator_load_arc_level_mapping", v5[1]);
      if ( !slave_id )
        goto LABEL_111;
    }
    else
    {
      v17 = s1;
      if ( s1 )
      {
        if ( (unsigned __int64)s1 >= 0x41 )
        {
          printk(&unk_8CE0, "rpmh_regulator_load_arc_level_mapping", v5[1]);
        }
        else
        {
          if ( ((unsigned __int8)s1 & 1) == 0 )
          {
            *((_DWORD *)v5 + 52) = (unsigned __int64)s1 >> 1;
            v18 = *((_DWORD *)v5 + 20) | *v16;
            *((_DWORD *)v5 + 20) = v18;
            *((_DWORD *)v5 + 20) = v18 | (v16[1] << 8);
            if ( (unsigned __int64)v17 >= 3 )
            {
              v19 = 0;
              v20 = v16 + 3;
              v21 = (char *)v5 + 84;
              while ( 1 )
              {
                if ( v19 == 31 )
                  goto LABEL_257;
                v22 = *(_DWORD *)&v21[4 * v19] | *(v20 - 1);
                *(_DWORD *)&v21[4 * v19] = v22;
                v23 = v22 | (*v20 << 8);
                *(_DWORD *)&v21[4 * v19] = v23;
                if ( !v23 )
                  break;
                v24 = v19 + 2;
                ++v19;
                v20 += 2;
                if ( v24 >= *((int *)v5 + 52) )
                  goto LABEL_111;
              }
              *((_DWORD *)v5 + 52) = v19 + 1;
            }
            goto LABEL_111;
          }
          printk(&unk_8D1A, "rpmh_regulator_load_arc_level_mapping", v5[1]);
        }
      }
      else
      {
        printk(&unk_8B83, "rpmh_regulator_load_arc_level_mapping", v5[1]);
      }
      slave_id = -22;
    }
    v30 = v5[1];
    v31 = &unk_8DCF;
    goto LABEL_262;
  }
  if ( v12 )
    goto LABEL_111;
  s1 = (char *)&unk_8F54;
  v25 = *v5;
  v142 = 0;
  v26 = *(_QWORD *)(v25 + 744);
  v135 = 0;
  *((_DWORD *)v5 + 19) = 0;
  *((_DWORD *)v5 + 61) = -22;
  if ( !of_find_property(v26, "qcom,regulator-type", &v142) )
    goto LABEL_111;
  v27 = of_property_read_string(v26, "qcom,regulator-type", &s1);
  if ( v27 )
  {
    slave_id = v27;
    printk(&unk_96BC, "rpmh_regulator_parse_vrm_modes", v5[1]);
    goto LABEL_261;
  }
  v28 = s1;
  if ( !strcmp(s1, "pmic4-ldo") )
  {
    v32 = 1;
    v29 = 1;
  }
  else
  {
    if ( !strcmp(v28, "pmic4-hfsmps") )
    {
      v29 = 2;
    }
    else if ( !strcmp(v28, "pmic4-ftsmps") )
    {
      v29 = 3;
    }
    else if ( !strcmp(v28, "pmic4-bob") )
    {
      v29 = 4;
    }
    else if ( !strcmp(v28, "pmic5-ldo") )
    {
      v29 = 5;
    }
    else if ( !strcmp(v28, "pmic5-hfsmps") )
    {
      v29 = 6;
    }
    else if ( !strcmp(v28, "pmic5-ftsmps") )
    {
      v29 = 7;
    }
    else if ( !strcmp(v28, "pmic5-bob") )
    {
      v29 = 8;
    }
    else if ( !strcmp(v28, "pmic7-ldo") )
    {
      v29 = 9;
    }
    else if ( !strcmp(v28, "pmic7-hfsmps") )
    {
      v29 = 10;
    }
    else if ( !strcmp(v28, "pmic7-ftsmps") )
    {
      v29 = 11;
    }
    else
    {
      if ( strcmp(v28, "pmic7-bob") )
        goto LABEL_258;
      v29 = 12;
    }
    v32 = v29;
  }
  v33 = rpmh_regulator_mode_map[v29];
  *((_DWORD *)v5 + 19) = v32;
  if ( (of_property_read_variable_u32_array(v26, "qcom,disable-mode", &v135, 1, 0) & 0x80000000) == 0 )
  {
    if ( v135 >= 5 )
    {
      printk(&unk_9296, "rpmh_regulator_parse_vrm_modes", v5[1]);
      slave_id = -22;
      goto LABEL_261;
    }
    v34 = (_DWORD *)(v33 + 12LL * v135);
    if ( !v34[1] )
    {
      printk(&unk_97D6, "rpmh_regulator_parse_vrm_modes", v5[1]);
      slave_id = -22;
      goto LABEL_261;
    }
    *((_DWORD *)v5 + 61) = *v34;
  }
  if ( !of_find_property(v26, "qcom,supported-modes", &v142) )
    goto LABEL_111;
  v35 = (__int64)v142 >> 2;
  v36 = v142 >> 2;
  v142 >>= 2;
  if ( !is_mul_ok(v35, 0xCu) )
  {
    v5[29] = 0;
LABEL_260:
    slave_id = -12;
    goto LABEL_261;
  }
  v37 = devm_kmalloc(*v5, 4 * (v35 + 2LL * v36), 3520);
  v5[29] = v37;
  if ( !v37 )
    goto LABEL_260;
  *((_DWORD *)v5 + 60) = v142;
  if ( v142 < 0 )
    goto LABEL_260;
  v38 = 4LL * (unsigned int)v142;
  v39 = v2;
  v40 = (_DWORD *)_kmalloc_noprof(v38, 3520);
  if ( !v40 )
    goto LABEL_260;
  while ( 1 )
  {
    variable_u32_array = of_property_read_variable_u32_array(v26, "qcom,supported-modes", v40, v142, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v123 = v5[1];
      slave_id = variable_u32_array;
LABEL_240:
      printk(&unk_96BC, "rpmh_regulator_parse_vrm_modes", v123);
LABEL_253:
      kfree(v40);
      goto LABEL_261;
    }
    v42 = v142;
    if ( v142 < 1 )
      goto LABEL_99;
    v43 = v38 - 4;
    if ( v38 >= 4 )
      break;
LABEL_264:
    __break(1u);
    v131 = v6;
    v126 = v3;
    StatusReg = _ReadStatusReg(SP_EL0);
    v128 = (unsigned int)v142;
    v129 = *(_QWORD *)(StatusReg + 80);
    v39 = v40;
    *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
    if ( (v128 & 0x80000000) != 0 )
    {
      v38 = 0;
      v40 = nullptr;
    }
    else
    {
      v38 = 4 * v128;
      v40 = (_DWORD *)_kmalloc_noprof(4 * v128, 3520);
    }
    *(_QWORD *)(StatusReg + 80) = v129;
    v3 = v126;
    v6 = v131;
    if ( !v40 )
      goto LABEL_260;
  }
  if ( *v40 > 4u )
  {
LABEL_249:
    printk(&unk_981F, "rpmh_regulator_parse_vrm_modes", v5[1]);
    goto LABEL_252;
  }
  v44 = (_DWORD *)(v33 + 12LL * (unsigned int)*v40);
  if ( !v44[1] )
  {
LABEL_247:
    printk(&unk_9493, "rpmh_regulator_parse_vrm_modes", v5[1]);
LABEL_252:
    slave_id = -22;
    goto LABEL_253;
  }
  *(_DWORD *)v5[29] = *v44;
  *(_DWORD *)(v5[29] + 4LL) = *(_DWORD *)(v33 + 12LL * (unsigned int)*v40 + 4);
  v42 = v142;
  if ( v142 >= 2 )
  {
    v45 = 0;
    v46 = 1;
    v47 = 4;
    while ( 1 )
    {
      if ( v38 < v47 || v43 < 4 || (v47 & 0x8000000000000000LL) != 0 || v38 < v47 )
        goto LABEL_264;
      v48 = v40[v47 / 4];
      if ( v48 >= 5 )
        goto LABEL_249;
      v49 = (_DWORD *)(v33 + 12LL * v48);
      if ( !v49[1] )
        goto LABEL_247;
      *(_DWORD *)(v5[29] + v45 + 12) = *v49;
      if ( v38 < v47 )
        goto LABEL_264;
      v50 = v43 >= 4;
      v43 -= 4LL;
      if ( !v50 )
        goto LABEL_264;
      *(_DWORD *)(v5[29] + v45 + 16) = *(_DWORD *)(v33 + 12LL * (unsigned int)v40[v47 / 4] + 4);
      if ( *(_DWORD *)(v5[29] + v45 + 12) <= *(_DWORD *)(v5[29] + v45) )
        break;
      v42 = v142;
      ++v46;
      v47 += 4LL;
      v45 += 12;
      if ( v46 >= v142 )
        goto LABEL_99;
    }
    v124 = v5[1];
LABEL_251:
    printk(&unk_96E0, "rpmh_regulator_parse_vrm_modes", v124);
    goto LABEL_252;
  }
LABEL_99:
  v51 = of_property_read_variable_u32_array(v26, "qcom,mode-threshold-currents", v40, v42, 0);
  if ( (v51 & 0x80000000) != 0 )
  {
    v123 = v5[1];
    slave_id = v51;
    goto LABEL_240;
  }
  if ( v142 < 1 )
    goto LABEL_110;
  if ( v38 < 4 )
    goto LABEL_264;
  *(_DWORD *)(v5[29] + 8LL) = *v40;
  if ( v142 >= 2 )
  {
    v52 = 1;
    while ( 1 )
    {
      v53 = 4 * v52;
      if ( v38 < 4 * v52 || v38 - 4 * v52 < 4 || (v53 & 0x8000000000000000LL) != 0 || v38 < v53 )
        goto LABEL_264;
      *(_DWORD *)(v5[29] + 12 * v52 + 8) = v40[v52];
      if ( *(_DWORD *)(v5[29] + 12 * v52 + 8) <= *(_DWORD *)(v5[29] + 12 * v52 - 4) )
        break;
      if ( ++v52 >= v142 )
        goto LABEL_110;
    }
    v124 = v5[1];
    goto LABEL_251;
  }
LABEL_110:
  kfree(v40);
  v2 = v39;
LABEL_111:
  property = of_find_property(v2, "qcom,always-wait-for-ack", 0);
  v55 = *v5;
  *((_DWORD *)v5 + 56) = 0;
  *((_BYTE *)v5 + 212) = property != 0;
  next_available_child = of_get_next_available_child(*(_QWORD *)(v55 + 744), 0);
  if ( next_available_child )
  {
    v57 = next_available_child;
    do
    {
      if ( !of_find_property(v57, "compatible", 0) )
        ++*((_DWORD *)v5 + 56);
      v57 = of_get_next_available_child(*(_QWORD *)(*v5 + 744LL), v57);
    }
    while ( v57 );
  }
  v58 = *((int *)v5 + 56);
  if ( !(_DWORD)v58 )
  {
    printk(&unk_940D, "rpmh_regulator_allocate_vreg", v5[1]);
    slave_id = -19;
LABEL_256:
    v30 = v5[1];
    v31 = &unk_9514;
    goto LABEL_262;
  }
  if ( !is_mul_ok(v58, 0x178u) )
  {
    v5[27] = 0;
    goto LABEL_255;
  }
  v59 = devm_kmalloc(*v5, 376LL * (int)v58, 3520);
  v5[27] = v59;
  if ( !v59 )
  {
LABEL_255:
    slave_id = -12;
    goto LABEL_256;
  }
  v133 = v2;
  v134 = v3;
  v130 = v6;
  v60 = of_get_next_available_child(*(_QWORD *)(*v5 + 744LL), 0);
  if ( v60 )
  {
    v61 = v60;
    v62 = 0;
    do
    {
      if ( !of_find_property(v61, "compatible", 0) )
      {
        *(_QWORD *)(v5[27] + 376LL * v62) = v61;
        *(_QWORD *)(v5[27] + 376LL * v62 + 336) = v5;
        v63 = of_property_read_string(v61, "regulator-name", v5[27] + 376LL * v62 + 8);
        if ( v63 )
        {
          slave_id = v63;
          printk(&unk_9212, "rpmh_regulator_allocate_vreg", v5[1]);
          goto LABEL_256;
        }
        ++v62;
      }
      v61 = of_get_next_available_child(*(_QWORD *)(*v5 + 744LL), v61);
    }
    while ( v61 );
  }
  v132 = v1;
  if ( *((int *)v5 + 56) >= 1 )
  {
    v64 = 0;
    _ReadStatusReg(SP_EL0);
    while ( 2 )
    {
      v67 = (_QWORD *)(v5[27] + 376 * v64);
      v135 = 0;
      v68 = v67[42];
      v69 = *(char **)v68;
      v70 = *(unsigned int *)(v68 + 72);
      v140 = 0;
      v141 = 0;
      v138 = nullptr;
      v139 = 0;
      s1 = nullptr;
      v137 = nullptr;
      v71 = (_QWORD *)devm_kmalloc(v69, 296, 3520);
      if ( !v71 )
        goto LABEL_231;
      if ( (unsigned int)v70 >= 4 )
        goto LABEL_257;
      v72 = v71;
      memcpy(v71, (&rpmh_regulator_ops)[v70], 0x128u);
      v73 = *v67;
      v67[11] = &_this_module;
      *((_DWORD *)v67 + 21) = 0;
      v67[9] = v72;
      regulator_init_data = (_DWORD *)of_get_regulator_init_data(v69, v73, v67 + 1);
      if ( !regulator_init_data )
      {
LABEL_231:
        v66 = -12;
        goto LABEL_234;
      }
      v75 = regulator_init_data[5];
      v76 = regulator_init_data;
      regulator_init_data[17] = v75;
      if ( (_DWORD)v70 )
      {
        if ( !v72[1] )
          goto LABEL_140;
LABEL_141:
        regulator_init_data[16] |= 1u;
      }
      else
      {
        v75 &= ~(v75 >> 31);
        v77 = regulator_init_data[4] & ~((int)regulator_init_data[4] >> 31);
        if ( v77 >= 8191000 )
          v77 = 8191000;
        if ( v75 >= 8191000 )
          v75 = 8191000;
        regulator_init_data[4] = v77;
        regulator_init_data[5] = v75;
        if ( v72[1] )
          goto LABEL_141;
LABEL_140:
        if ( v72[3] )
          goto LABEL_141;
      }
      if ( (unsigned int)v70 >= 2 && regulator_init_data[4] == v75 )
        *((_DWORD *)v67 + 27) = v75;
      v78 = v67[42];
      if ( *(_DWORD *)(v78 + 240) )
      {
        regulator_init_data[16] |= 0x14u;
        v78 = v67[42];
        if ( *(int *)(v78 + 240) >= 1 )
        {
          v79 = regulator_init_data[15];
          v80 = 0;
          v81 = 4;
          do
          {
            ++v80;
            v82 = *(_DWORD *)(*(_QWORD *)(v78 + 232) + v81);
            v81 += 12;
            v79 |= v82;
            regulator_init_data[15] = v79;
            v78 = v67[42];
          }
          while ( v80 < *(int *)(v78 + 240) );
        }
        if ( (_DWORD)v70 != 1 )
        {
LABEL_154:
          if ( v72[14] )
            regulator_init_data[16] |= 8u;
          if ( (unsigned int)(v70 - 2) < 2 )
          {
            *((_DWORD *)v67 + 16) = 1;
          }
          else if ( (_DWORD)v70 == 1 )
          {
            *((_DWORD *)v67 + 16) = *(_DWORD *)(v67[42] + 208LL);
          }
          else
          {
            v83 = regulator_init_data[5];
            v84 = 1000 * ((regulator_init_data[4] + 999) / 1000);
            v85 = v83 % 1000;
            if ( v84 || v83 != v85 )
            {
              *((_DWORD *)v67 + 24) = v84;
              *((_DWORD *)v67 + 25) = 1000;
              *((_DWORD *)v67 + 16) = (v83 - v85 - v84) / 1000 + 1;
            }
            else
            {
              *((_DWORD *)v67 + 16) = 2;
            }
          }
          v86 = of_property_read_variable_u32_array(*v67, "qcom,set", &v135, 1, 0);
          if ( v86 < 0 )
          {
            v66 = v86;
            printk(&unk_8C17, "rpmh_regulator_init_vreg", v67[1]);
            goto LABEL_234;
          }
          v87 = v135;
          if ( (v135 & 3) != 0 )
          {
            v88 = (const char *)v67[1];
            *((_BYTE *)v67 + 344) = v135 & 1;
            *((_BYTE *)v67 + 345) = (v87 & 2) != 0;
            v89 = strlen(v88);
            v90 = _kmalloc_noprof(v89 + 16, 3520);
            v91 = v90;
            if ( !v90 )
              goto LABEL_222;
            scnprintf(v90, v89 + 16, "%s-parent-supply", (const char *)v67[1]);
            if ( of_find_property(*(_QWORD *)(*(_QWORD *)v67[42] + 744LL), v91, 0) || of_find_property(*v67, v91, 0) )
            {
              kfree(v91);
              v92 = strlen((const char *)v67[1]);
              v93 = devm_kmalloc(*(_QWORD *)v67[42], v92 + 10, 3520);
              if ( !v93 )
              {
LABEL_222:
                printk(&unk_94D7, "rpmh_regulator_init_vreg", v67[1]);
                v66 = -12;
                goto LABEL_234;
              }
              v94 = (void *)v93;
              scnprintf(v93, v92 + 10, "%s-parent", (const char *)v67[1]);
LABEL_171:
              v67[2] = v94;
            }
            else
            {
              v113 = of_find_property(*v67, "vin-supply", 0);
              kfree(v91);
              v94 = &unk_95E3;
              if ( v113 )
                goto LABEL_171;
            }
            s1 = v69;
            v137 = v76;
            v95 = *v67;
            v142 = 0;
            v138 = v67;
            v139 = v95;
            v96 = *(_DWORD *)(v67[42] + 72LL);
            if ( v96 > 1 )
            {
              if ( v96 == 2 )
              {
                if ( (of_property_read_variable_u32_array(v95, "qcom,init-enable", &v142, 1, 0) & 0x80000000) != 0 )
                  goto LABEL_216;
                v101 = *((_DWORD *)v67 + 91) | 2;
                *((_DWORD *)v67 + 88) = v142 != 0;
              }
              else
              {
                if ( v96 != 3
                  || (of_property_read_variable_u32_array(v95, "qcom,init-enable", &v142, 1, 0) & 0x80000000) != 0 )
                {
                  goto LABEL_216;
                }
                v101 = *((_DWORD *)v67 + 91) | 1;
                *((_DWORD *)v67 + 87) = v142 != 0;
              }
              *((_DWORD *)v67 + 91) = v101;
              goto LABEL_216;
            }
            if ( !v96 )
            {
              if ( (of_property_read_variable_u32_array(v95, "qcom,init-enable", &v142, 1, 0) & 0x80000000) == 0 )
              {
                v102 = v142 != 0;
                *((_DWORD *)v67 + 91) |= 2u;
                *((_DWORD *)v67 + 88) = v102;
              }
              if ( (of_property_read_variable_u32_array(*v67, "qcom,init-voltage", &v142, 1, 0) & 0x80000000) == 0 )
              {
                v103 = v142;
                if ( (unsigned int)v142 > 0x7CFC18 )
                {
                  v122 = v67[1];
                  goto LABEL_228;
                }
                *((_DWORD *)v67 + 91) |= 1u;
                *((_DWORD *)v67 + 87) = v103 / 0x3E8;
              }
              if ( (of_property_read_variable_u32_array(*v67, "qcom,init-mode", &v142, 1, 0) & 0x80000000) == 0 )
              {
                if ( (unsigned int)v142 >= 5 )
                {
                  v122 = v67[1];
                  goto LABEL_228;
                }
                v104 = v67[42];
                v105 = *(unsigned int *)(v104 + 76);
                if ( !(_DWORD)v105 )
                {
                  printk(&unk_8FB0, "rpmh_regulator_load_default_parameters", v67[1]);
                  goto LABEL_229;
                }
                if ( (unsigned int)v105 > 0xC )
                  goto LABEL_257;
                v106 = (_DWORD *)(rpmh_regulator_mode_map[v105] + 12LL * (unsigned int)v142);
                if ( !v106[1] )
                {
                  printk(&unk_943E, "rpmh_regulator_load_default_parameters", v67[1]);
LABEL_229:
                  printk(&unk_9723, "rpmh_regulator_init_vreg", v67[1]);
                  v66 = -22;
LABEL_234:
                  printk(&unk_8EDD, "rpmh_regulator_probe", *(_QWORD *)(v5[27] + 376 * v64 + 8));
                  slave_id = v66;
                  goto LABEL_263;
                }
                v107 = *((_DWORD *)v67 + 91);
                *((_DWORD *)v67 + 89) = *v106;
                *((_DWORD *)v67 + 91) = v107 | 4;
                v108 = *(unsigned int *)(v104 + 240);
                if ( (int)v108 >= 1 )
                {
                  v109 = *(int **)(v104 + 232);
                  v110 = *v106;
                  v111 = 0;
                  while ( 1 )
                  {
                    v112 = *v109;
                    v109 += 3;
                    if ( v112 == v110 )
                      break;
                    if ( v108 == ++v111 )
                      goto LABEL_210;
                  }
                  *((_DWORD *)v67 + 92) = v111;
                }
              }
LABEL_210:
              if ( (of_property_read_variable_u32_array(*v67, "qcom,init-headroom-voltage", &v142, 1, 0) & 0x80000000) == 0 )
              {
                v119 = v142;
                if ( (unsigned int)v142 > 0x7CC18 )
                {
                  v122 = v67[1];
                  goto LABEL_228;
                }
                *((_DWORD *)v67 + 91) |= 8u;
                *((_DWORD *)v67 + 90) = v119 / 0x3E8;
              }
              v115 = *v67;
              v116 = "qcom,min-dropout-voltage";
              goto LABEL_214;
            }
            if ( v96 == 1 )
            {
              if ( (of_property_read_variable_u32_array(v95, "qcom,init-voltage-level", &v142, 1, 0) & 0x80000000) == 0 )
              {
                v97 = v67[42];
                v98 = *(unsigned int *)(v97 + 208);
                if ( (int)v98 < 1 )
                {
LABEL_227:
                  v122 = v67[1];
LABEL_228:
                  printk(&unk_8BBB, "rpmh_regulator_load_default_parameters", v122);
                  goto LABEL_229;
                }
                v99 = 0;
                v100 = v97 + 80;
                while ( v99 != 32 )
                {
                  if ( (unsigned int)v142 <= *(_DWORD *)(v100 + 4 * v99) )
                  {
                    v114 = *((_DWORD *)v67 + 91);
                    *((_DWORD *)v67 + 87) = v99;
                    *((_DWORD *)v67 + 91) = v114 | 1;
                    goto LABEL_207;
                  }
                  if ( v98 == ++v99 )
                    goto LABEL_227;
                }
LABEL_257:
                __break(0x5512u);
LABEL_258:
                printk(&unk_9175, "rpmh_regulator_parse_hw_type", v5[1]);
                slave_id = -22;
LABEL_261:
                v30 = v5[1];
                v31 = &unk_8B50;
LABEL_262:
                printk(v31, "rpmh_regulator_probe", v30);
                goto LABEL_263;
              }
LABEL_207:
              v115 = *v67;
              v116 = "qcom,min-dropout-voltage-level";
LABEL_214:
              if ( (of_property_read_variable_u32_array(v115, v116, &v142, 1, 0) & 0x80000000) == 0 )
                *((_DWORD *)v67 + 29) = v142;
            }
LABEL_216:
            v120 = devm_regulator_register(v69, v67 + 1, &s1);
            v67[41] = v120;
            if ( v120 > 0xFFFFFFFFFFFFF000LL )
            {
              v65 = v67[1];
              v66 = v120;
              v67[41] = 0;
              printk(&unk_9689, "rpmh_regulator_init_vreg", v65);
              goto LABEL_234;
            }
            if ( (unsigned int)devm_regulator_proxy_consumer_register(v69, *v67) )
              printk(&unk_9373, "rpmh_regulator_init_vreg", v67[1]);
            if ( (unsigned int)devm_regulator_debug_register(v69, v67[41]) )
            {
              v117 = v67[1];
              v118 = &unk_8E5B;
LABEL_221:
              printk(v118, "rpmh_regulator_init_vreg", v117);
            }
            if ( (int)++v64 >= *((_DWORD *)v5 + 56) )
              goto LABEL_223;
            continue;
          }
          v117 = v67[1];
          v118 = &unk_9348;
          goto LABEL_221;
        }
      }
      else
      {
        v72[27] = 0;
        v72[17] = 0;
        v72[18] = 0;
        if ( (_DWORD)v70 != 1 )
          goto LABEL_154;
      }
      break;
    }
    if ( *(_DWORD *)(v78 + 80) )
    {
      v72[15] = 0;
      v72[16] = 0;
      v72[14] = 0;
    }
    goto LABEL_154;
  }
LABEL_223:
  if ( of_find_property(v133, "qcom,send-defaults", 0) )
  {
    mutex_lock(v130);
    v121 = rpmh_regulator_send_aggregate_requests(v5[27]);
    if ( v121 )
    {
      slave_id = v121;
      printk(&unk_8C5E, "rpmh_regulator_probe", v5[1]);
      mutex_unlock(v130);
      goto LABEL_263;
    }
    mutex_unlock(v130);
  }
  of_platform_populate(*(_QWORD *)(v134 + 760), 0, 0, v132);
  slave_id = 0;
  *(_QWORD *)(v134 + 168) = v5;
LABEL_263:
  _ReadStatusReg(SP_EL0);
  return slave_id;
}
