__int64 __fastcall simple_amp_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x23
  unsigned int v6; // w2
  unsigned int v7; // w8
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 next_child; // x0
  __int64 v14; // x26
  __int64 v15; // x20
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x25
  int v19; // w0
  __int64 v20; // x0
  int v21; // w0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x24
  char *v25; // x25
  size_t v26; // x20
  int v27; // w0
  int *v28; // x8
  unsigned int *v29; // x25
  unsigned int v30; // w0
  __int64 v31; // x0
  unsigned int variable_u32_array; // w0
  unsigned int v33; // w0
  __int64 v34; // x0
  unsigned int v35; // w0
  __int64 child_by_name; // x0
  __int64 v37; // x20
  __int64 v38; // x0
  __int64 v39; // x28
  __int64 v40; // x26
  __int64 v41; // x23
  __int64 v42; // x21
  __int64 v43; // x0
  __int64 v44; // x27
  unsigned int v45; // w0
  unsigned int v46; // w0
  __int64 v47; // x0
  unsigned int v48; // w0
  unsigned __int64 v49; // x1
  const char *v50; // x2
  unsigned int v51; // w0
  __int64 v52; // x0
  unsigned int v53; // w0
  unsigned __int64 optional; // x0
  __int64 v55; // x20
  unsigned int v56; // w0
  unsigned __int64 inited; // x0
  __int64 v58; // x0
  unsigned int v59; // w0
  unsigned int v60; // w0
  const char **v61; // x0
  const char **v62; // x20
  const char *v63; // x0
  __int64 dai_driver; // x0
  __int64 v65; // x1
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 device_by_node; // x0
  __int64 *v69; // x20
  void (__fastcall *v70)(__int64, __int64, __int64); // x8
  __int64 v71; // x0
  unsigned int v73; // w22
  __int64 v74; // [xsp+0h] [xbp-100h]
  __int64 v75; // [xsp+8h] [xbp-F8h]
  __int64 v76; // [xsp+10h] [xbp-F0h]
  __int64 v77; // [xsp+18h] [xbp-E8h]
  __int64 v78; // [xsp+20h] [xbp-E0h]
  __int64 v79; // [xsp+28h] [xbp-D8h]
  __int64 v80; // [xsp+30h] [xbp-D0h] BYREF
  __int64 v81; // [xsp+38h] [xbp-C8h] BYREF
  char v82[4]; // [xsp+40h] [xbp-C0h] BYREF
  unsigned int v83; // [xsp+44h] [xbp-BCh] BYREF
  __int64 v84; // [xsp+48h] [xbp-B8h] BYREF
  char *s; // [xsp+50h] [xbp-B0h] BYREF
  __int64 v86; // [xsp+58h] [xbp-A8h] BYREF
  __int64 v87; // [xsp+60h] [xbp-A0h]
  char v88[8]; // [xsp+68h] [xbp-98h] BYREF
  __int64 v89; // [xsp+70h] [xbp-90h]
  __int64 v90; // [xsp+78h] [xbp-88h]
  __int64 v91; // [xsp+80h] [xbp-80h]
  __int64 v92; // [xsp+88h] [xbp-78h]
  __int64 v93; // [xsp+90h] [xbp-70h]
  __int16 v94; // [xsp+98h] [xbp-68h]
  __int64 v95; // [xsp+A0h] [xbp-60h] BYREF
  __int64 v96; // [xsp+A8h] [xbp-58h]
  __int64 v97; // [xsp+B0h] [xbp-50h]
  __int64 v98; // [xsp+B8h] [xbp-48h]
  __int64 v99; // [xsp+C0h] [xbp-40h]
  __int64 v100; // [xsp+C8h] [xbp-38h]
  __int64 v101; // [xsp+D0h] [xbp-30h]
  __int64 v102; // [xsp+D8h] [xbp-28h]
  __int64 v103; // [xsp+E0h] [xbp-20h]
  __int64 v104; // [xsp+E8h] [xbp-18h]
  __int64 v105; // [xsp+F0h] [xbp-10h]

  v1 = a1 + 72;
  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_WORD *)(a1 + 993) = 257;
  v84 = 0;
  v83 = -1;
  v82[0] = 0;
  v80 = 0;
  v81 = 0;
  v3 = devm_kmalloc(a1 + 72, 608, 3520);
  if ( !v3 )
    goto LABEL_154;
  v4 = *(_QWORD *)(a1 + 816);
  v5 = v3;
  v86 = 0;
  v87 = 0;
  v6 = of_property_count_elems_of_size(v4, "qcom,simple-amp-function-array", 4);
  *(_DWORD *)(v5 + 152) = v6;
  if ( v6 >= 5 )
  {
    dev_err(v1, "invalid num functions:%d\n", v6);
LABEL_112:
    v73 = -22;
    goto LABEL_109;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 816), "qcom,simple-amp-function-array", &v86, v6, 0)
      & 0x80000000) != 0 )
  {
    dev_err(v1, "%s: Failed to read function array\n", "parser_sdca_data");
    goto LABEL_112;
  }
  v7 = *(_DWORD *)(v5 + 152);
  v77 = a1;
  if ( v7 )
  {
    v8 = v5 + 48;
    if ( (unsigned int)(v86 - 1) < 3 )
    {
      v9 = devm_kmalloc(v1, 608, 3520);
      if ( (unsigned int)v86 > 3 )
        goto LABEL_180;
      *(_QWORD *)(v8 + 8LL * (unsigned int)v86) = v9;
      if ( !v9 )
        goto LABEL_116;
      v7 = *(_DWORD *)(v5 + 152);
    }
    if ( v7 >= 2 )
    {
      if ( (unsigned int)(HIDWORD(v86) - 1) <= 2 )
      {
        v10 = devm_kmalloc(v1, 608, 3520);
        if ( HIDWORD(v86) > 3 )
          goto LABEL_180;
        *(_QWORD *)(v8 + 8LL * HIDWORD(v86)) = v10;
        if ( !v10 )
          goto LABEL_116;
        v7 = *(_DWORD *)(v5 + 152);
      }
      if ( v7 >= 3 )
      {
        if ( (unsigned int)(v87 - 1) <= 2 )
        {
          v11 = devm_kmalloc(v1, 608, 3520);
          if ( (unsigned int)v87 > 3 )
            goto LABEL_180;
          *(_QWORD *)(v8 + 8LL * (unsigned int)v87) = v11;
          if ( !v11 )
            goto LABEL_116;
          v7 = *(_DWORD *)(v5 + 152);
        }
        if ( v7 >= 4 )
        {
          if ( (unsigned int)(HIDWORD(v87) - 1) > 2 )
            goto LABEL_24;
          v12 = devm_kmalloc(v1, 608, 3520);
          if ( HIDWORD(v87) > 3 )
            goto LABEL_180;
          *(_QWORD *)(v8 + 8LL * HIDWORD(v87)) = v12;
          if ( v12 )
          {
            v7 = *(_DWORD *)(v5 + 152);
LABEL_24:
            if ( v7 > 4 )
              goto LABEL_180;
            goto LABEL_25;
          }
LABEL_116:
          v73 = -12;
          goto LABEL_109;
        }
      }
    }
  }
LABEL_25:
  next_child = of_get_next_child(v4, 0);
  if ( !next_child )
    goto LABEL_92;
  v14 = next_child;
  v15 = 0;
  v16 = v5 + 48;
  v75 = v4;
  v76 = v5;
  v74 = v5 + 48;
  do
  {
    if ( v15 == 4 )
      goto LABEL_180;
    if ( (v15 & 0x3FFFFFFFFFFFFFFFLL) == 4 )
      goto LABEL_179;
    v17 = *((unsigned int *)&v86 + v15);
    if ( (unsigned int)v17 > 3 )
      goto LABEL_180;
    v18 = *(_QWORD *)(v16 + 8 * v17);
    if ( !v18 )
    {
      v73 = -22;
      goto LABEL_107;
    }
    if ( of_find_property(v14, "mipi-sdca-function-initialization-table-v2", 0) )
    {
      v19 = of_property_count_elems_of_size(v14, "mipi-sdca-function-initialization-table-v2", 4);
      *(_DWORD *)(v18 + 600) = v19;
      if ( v19 < 1 )
      {
        dev_err(v1, "%s: Failed to count elements from init table v2\n", "parse_initialization_table_v2");
      }
      else if ( (v19 & 1) != 0 )
      {
        dev_err(v1, "%s: Invalid number of elements in init table v2\n", "parse_initialization_table_v2");
      }
      else
      {
        v20 = devm_kmalloc(v1, 4LL * (unsigned int)v19, 3520);
        *(_QWORD *)(v18 + 592) = v20;
        if ( !v20 )
        {
          v73 = -12;
LABEL_163:
          dev_err(v1, "init table v2 parse failed\n");
          goto LABEL_107;
        }
        if ( (of_property_read_variable_u32_array(
                v14,
                "mipi-sdca-function-initialization-table-v2",
                v20,
                *(int *)(v18 + 600),
                0)
            & 0x80000000) == 0 )
          goto LABEL_36;
        dev_err(v1, "%s: Failed to read mipi-sdca-function-initialization-table-v2\n", "parse_initialization_table_v2");
      }
      v73 = -22;
      goto LABEL_163;
    }
LABEL_36:
    if ( of_find_property(v14, "mipi-sdca-function-initialization-table", 0) )
    {
      v21 = of_property_count_elems_of_size(v14, "mipi-sdca-function-initialization-table", 4);
      *(_DWORD *)(v18 + 584) = v21;
      if ( v21 < 1 )
      {
        dev_err(v1, "%s: Failed to count elements from init table\n", "parse_initialization_table");
      }
      else if ( (v21 & 1) != 0 )
      {
        dev_err(v1, "%s: Invalid number of elements in init table\n", "parse_initialization_table");
      }
      else
      {
        v22 = devm_kmalloc(v1, 4LL * (unsigned int)v21, 3520);
        *(_QWORD *)(v18 + 576) = v22;
        if ( !v22 )
        {
          v73 = -12;
LABEL_168:
          dev_err(v1, "init table parse failed\n");
          goto LABEL_107;
        }
        if ( (of_property_read_variable_u32_array(
                v14,
                "mipi-sdca-function-initialization-table",
                v22,
                *(int *)(v18 + 584),
                0)
            & 0x80000000) == 0 )
          goto LABEL_41;
        dev_err(v1, "%s: Failed to read mipi-sdca-function-initialization-table\n", "parse_initialization_table");
      }
      v73 = -22;
      goto LABEL_168;
    }
LABEL_41:
    v78 = v15;
    s = nullptr;
    v94 = 0;
    v92 = 0;
    v93 = 0;
    v90 = 0;
    v91 = 0;
    *(_QWORD *)v88 = 0;
    v89 = 0;
    v23 = of_get_next_child(v14, 0);
    if ( !v23 )
      goto LABEL_91;
    v24 = v23;
    v79 = v18;
    while ( 1 )
    {
      if ( (unsigned int)of_property_read_string(v24, "mipi-sdca-entity-label", &s) )
      {
        dev_err(v1, "%s: Failed to read entity label\n", "parse_entity");
        goto LABEL_131;
      }
      v25 = s;
      v26 = strlen(s);
      if ( !strncmp("ENTITY0", s, v26) )
      {
        v28 = &entity_idx_table;
      }
      else if ( !strncmp("IT21", v25, v26) )
      {
        v28 = &dword_ACD0;
      }
      else if ( !strncmp("CS21", v25, v26) )
      {
        v28 = &dword_ACE0;
      }
      else if ( !strncmp("PPU21", v25, v26) )
      {
        v28 = &dword_ACF0;
      }
      else if ( !strncmp("FU21", v25, v26) )
      {
        v28 = &dword_AD00;
      }
      else if ( !strncmp("SAPU29", v25, v26) )
      {
        v28 = &dword_AD10;
      }
      else if ( !strncmp("PDE23", v25, v26) )
      {
        v28 = &dword_AD20;
      }
      else if ( !strncmp("OT23", v25, v26) )
      {
        v28 = &dword_AD30;
      }
      else if ( !strncmp("IT29", v25, v26) )
      {
        v28 = &dword_AD40;
      }
      else if ( !strncmp("CS24", v25, v26) )
      {
        v28 = &dword_AD50;
      }
      else if ( !strncmp("OT24", v25, v26) )
      {
        v28 = &dword_AD60;
      }
      else
      {
        v27 = strncmp("TG23", v25, v26);
        v28 = &dword_AD70;
        if ( v27 )
        {
          v73 = -22;
LABEL_178:
          dev_err(v1, "%s: entity label %s not found idx %d\n", "parse_entity", v25, v73);
          goto LABEL_106;
        }
      }
      v73 = *v28;
      if ( *v28 < 0 )
        goto LABEL_178;
      if ( v73 >= 0xD )
        goto LABEL_180;
      v29 = (unsigned int *)(v79 + 48LL * v73);
      if ( (of_property_read_variable_u32_array(v24, "mipi-sdca-entity-number", v29, 1, 0) & 0x80000000) != 0 )
      {
        dev_err(v1, "%s: Failed to read entity number\n", "parse_entity");
        goto LABEL_131;
      }
      v30 = of_property_count_elems_of_size(v24, "mipi-sdca-control-numbers", 4);
      v29[6] = v30;
      v31 = devm_kmalloc(v1, 4LL * v30, 3520);
      *((_QWORD *)v29 + 2) = v31;
      if ( !v31 )
        goto LABEL_123;
      variable_u32_array = of_property_read_variable_u32_array(v24, "mipi-sdca-control-numbers", v31, v29[6], 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
      {
        v73 = variable_u32_array;
        dev_err(v1, "%s: Failed to read control number: %d ent_num = %d\n", "parse_entity", variable_u32_array, *v29);
        goto LABEL_106;
      }
      v33 = of_property_count_elems_of_size(v24, "mipi-sdca-control-selectors", 4);
      v29[7] = v33;
      if ( (v33 & 0x80000000) != 0 )
        break;
      v34 = devm_kmalloc(v1, 4LL * v33, 3520);
      *((_QWORD *)v29 + 4) = v34;
      if ( !v34 )
        goto LABEL_123;
      v35 = of_property_read_variable_u32_array(v24, "mipi-sdca-control-selectors", v34, (int)v29[7], 0);
      if ( (v35 & 0x80000000) != 0 )
      {
        v73 = v35;
        dev_err(v1, "%s: Failed to read %s\n", "parse_entity", "mipi-sdca-control-selectors");
LABEL_106:
        v15 = v78;
        dev_err(v1, "%s: Failed to parse Entities ret: %d\n", "parse_functions", v73);
LABEL_107:
        if ( (v15 & 0x3FFFFFFFFFFFFFFFLL) != 4 )
        {
          dev_err(v1, "parse function %d failed\n", *((_DWORD *)&v86 + v15));
LABEL_109:
          dev_err(v1, "sdca simple amp DT parse failed\n");
          goto LABEL_155;
        }
LABEL_179:
        __break(1u);
LABEL_180:
        __break(0x5512u);
      }
      child_by_name = of_get_child_by_name(v24, "control-selectors");
      if ( !child_by_name )
      {
        dev_err(v1, "%s: Failed to find control list node\n", "parse_entity");
LABEL_131:
        v73 = -22;
        goto LABEL_106;
      }
      v37 = child_by_name;
      v38 = devm_kmalloc(v1, 384, 3520);
      *((_QWORD *)v29 + 5) = v38;
      if ( !v38 )
      {
LABEL_123:
        v73 = -12;
        goto LABEL_106;
      }
      v39 = v14;
      if ( (int)v29[7] >= 1 )
      {
        v40 = 0;
        while ( 1 )
        {
          snprintf(v88, 0x32u, "mipi-sdca-control-0x%X-subproperties", *(_DWORD *)(*((_QWORD *)v29 + 4) + 4 * v40));
          v103 = 0;
          v104 = 0;
          v101 = 0;
          v102 = 0;
          v99 = 0;
          v100 = 0;
          v97 = 0;
          v98 = 0;
          v95 = 0;
          v96 = 0;
          if ( (unsigned int)_of_parse_phandle_with_args(v37, v88, 0, 0, 0, &v95) || (v41 = v95) == 0 )
          {
            dev_err(v1, "%s: Invalid phandle property: %s, entity_num: %d\n", "parse_entity", v88, *v29);
            v73 = -22;
            goto LABEL_106;
          }
          LODWORD(v95) = 0;
          v42 = *(unsigned int *)(*((_QWORD *)v29 + 4) + 4 * v40);
          if ( (unsigned int)v42 >= 0x30 )
          {
            dev_err(v1, "%s: cnt_sel %d > Max cnt sel %d\n", "parse_control_selectors", v42, 48);
            goto LABEL_104;
          }
          v43 = devm_kmalloc(v1, 8, 3520);
          if ( !v43 )
          {
            v73 = -12;
            goto LABEL_105;
          }
          v44 = v43;
          v45 = of_property_read_variable_u32_array(v41, "mipi-sdca-control-access-layer", v43, 1, 0);
          if ( (v45 & 0x80000000) != 0 )
          {
            v73 = v45;
            dev_err(
              v1,
              "%s: failed to read access layer for selector 0x%x subproperty, ret: %d\n",
              "parse_control_selectors",
              v42,
              v45);
            goto LABEL_105;
          }
          v46 = of_property_read_variable_u32_array(v41, "mipi-sdca-control-access-mode", &v95, 1, 0);
          if ( (v46 & 0x80000000) != 0 )
          {
            v73 = v46;
            dev_err(
              v1,
              "%s: failed to read access mode for selector 0x%x subproperty\n",
              "parse_control_selectors",
              v42);
            goto LABEL_105;
          }
          if ( (unsigned int)v95 >= 3 )
            break;
          *(_DWORD *)(v44 + 4) = v95;
          ++v40;
          *(_QWORD *)(*((_QWORD *)v29 + 5) + 8 * v42) = v44;
          if ( v40 >= (int)v29[7] )
            goto LABEL_43;
        }
        dev_err(v1, "%s: Unknown access mode %d\n", "parse_control_selectors", v95);
LABEL_104:
        v73 = -22;
LABEL_105:
        dev_err(
          v1,
          "%s: Failed to parse mipi-sdca-control-0x%X-subproperties ret: %d\n",
          "parse_entity",
          *(unsigned int *)(*((_QWORD *)v29 + 4) + 4 * v40),
          v73);
        goto LABEL_106;
      }
LABEL_43:
      v14 = v39;
      v24 = of_get_next_child(v39, v24);
      if ( !v24 )
        goto LABEL_91;
    }
    dev_err(v1, "%s: failed to count control selector elements\n", "parse_entity");
    v73 = v29[7];
    if ( v73 )
      goto LABEL_106;
LABEL_91:
    v15 = v78 + 1;
    v47 = of_get_next_child(v75, v14);
    v5 = v76;
    v16 = v74;
    v14 = v47;
  }
  while ( v47 );
LABEL_92:
  *(_QWORD *)(v5 + 144) = 9600000;
  *(_DWORD *)(v5 + 160) = -84;
  *(_QWORD *)(v5 + 88) = "vdd-io";
  *(_QWORD *)(v77 + 224) = v5;
  *(_QWORD *)(v5 + 8) = v1;
  *(_QWORD *)(v5 + 16) = v77;
  *(_DWORD *)(v5 + 600) = 24;
  *(_QWORD *)(v5 + 112) = "vdd-1p8";
  v48 = devm_regulator_bulk_get(v1, 2, v5 + 88);
  if ( v48 )
  {
    v49 = v48;
    v50 = "Failed to get regulators\n";
    goto LABEL_96;
  }
  v51 = regulator_bulk_enable(2, v5 + 88);
  if ( !v51 )
  {
    v53 = _devm_add_action(v1, simple_amp_regulator_disable, v5 + 88, "simple_amp_regulator_disable");
    if ( v53 )
    {
      v73 = v53;
      regulator_bulk_disable(2, v5 + 88);
    }
    else
    {
      optional = devm_gpiod_get_optional(v1, "powerdown", 7);
      v49 = optional;
      *(_QWORD *)(v5 + 136) = optional;
      if ( optional >= 0xFFFFFFFFFFFFF001LL )
      {
        v50 = "Shutdown Control GPIO not found\n";
        v52 = v1;
        goto LABEL_97;
      }
      v73 = gpiod_direction_output(optional, 0);
      if ( (v73 & 0x80000000) != 0 )
      {
        if ( (unsigned int)__ratelimit(&simple_amp_gpio_set__rs, "simple_amp_gpio_set") )
          dev_err(*(_QWORD *)(v5 + 8), "%s: failed to set GPIO: %d\n", "simple_amp_gpio_set", v73);
        goto LABEL_155;
      }
      if ( v73 )
        goto LABEL_155;
      v55 = *(_QWORD *)(v5 + 136);
      v56 = _devm_add_action(v1, simple_amp_gpio_powerdown, v55, "simple_amp_gpio_powerdown");
      if ( !v56 )
      {
        usleep_range_state(5000, 5010, 2);
        if ( (unsigned int)swr_get_logical_dev_num(v77, *(_QWORD *)(v77 + 984), v82) )
        {
          dev_err(
            v77 + 72,
            "%s get dev_num %d for dev addr %llx failed\n",
            "simple_amp_init",
            (unsigned __int8)v82[0],
            *(_QWORD *)(v77 + 984));
          v73 = -517;
          goto LABEL_155;
        }
        *(_BYTE *)(v77 + 64) = v82[0];
        inited = _devm_regmap_init_swr(v77, &simple_amp_regmap, 0, 0);
        if ( inited >= 0xFFFFFFFFFFFFF001LL )
        {
          v73 = inited;
          goto LABEL_155;
        }
        *(_QWORD *)v5 = inited;
        get_reg_defaults(&v81, &v80, v5);
        if ( !v80 )
        {
          dev_err(v1, "Failed to get the num_reg_def\n");
          v73 = -22;
          goto LABEL_155;
        }
        v58 = *(_QWORD *)v5;
        dword_258 = v80;
        qword_250 = v81;
        v59 = regmap_reinit_cache(v58, &simple_amp_regmap);
        if ( v59 )
        {
          v73 = v59;
          dev_err(v1, "Failed to reinit register cache: %d\n", v59);
          goto LABEL_155;
        }
        v60 = of_property_read_string(*(_QWORD *)(v77 + 816), "qcom,codec-name", &v84);
        if ( v60 )
        {
          v73 = v60;
          dev_err(
            v77 + 72,
            "Looking up %s property in node %s failed\n",
            "qcom,codec-name",
            *(const char **)(*(_QWORD *)(v77 + 816) + 16LL));
          goto LABEL_155;
        }
        v61 = (const char **)devm_kmalloc(v1, 384, 3520);
        if ( v61 )
        {
          v62 = v61;
          memcpy(v61, &soc_codec_dev_simple_amp, 0x180u);
          v63 = (const char *)devm_kstrdup(v1, v84, 3264);
          *v62 = v63;
          if ( v63 )
          {
            *(_QWORD *)(v5 + 32) = v62;
            if ( sscanf(v63, "sdca-simple-amp.%02d", &v83) == 1 )
            {
              dai_driver = get_dai_driver(v1, v83);
              v65 = *(_QWORD *)(v5 + 32);
              *(_QWORD *)(v5 + 40) = dai_driver;
              v73 = devm_snd_soc_register_component(v1, v65, dai_driver, 3);
              if ( v73 )
                dev_err(v1, "Codec component %s registration failed\n", **(const char ***)(v5 + 32));
              v66 = *(_QWORD *)(v77 + 816);
              v103 = 0;
              v104 = 0;
              v101 = 0;
              v102 = 0;
              v99 = 0;
              v100 = 0;
              v97 = 0;
              v98 = 0;
              v95 = 0;
              v96 = 0;
              if ( (unsigned int)_of_parse_phandle_with_args(v66, "qcom,lpass-cdc-handle", 0, 0, 0, &v95) )
                v67 = 0;
              else
                v67 = v95;
              *(_QWORD *)(v5 + 176) = v67;
              if ( v67 )
              {
                device_by_node = of_find_device_by_node();
                *(_QWORD *)(v5 + 184) = device_by_node;
                if ( device_by_node )
                {
                  v69 = *(__int64 **)(device_by_node + 160);
                  if ( v69 )
                  {
                    *(_QWORD *)(v5 + 192) = simple_amp_event_notify;
                    v70 = (void (__fastcall *)(__int64, __int64, __int64))v69[2];
                    if ( v70 )
                    {
                      v71 = *v69;
                      if ( *((_DWORD *)v70 - 1) != -875060373 )
                        __break(0x8228u);
                      v70(v71, v5 + 192, 1);
                      v70 = (void (__fastcall *)(__int64, __int64, __int64))v69[2];
                    }
                    *(_QWORD *)(v5 + 224) = v70;
                    *(_QWORD *)(v5 + 216) = *v69;
                  }
                  else
                  {
                    dev_err(v1, "%s: plat data not found\n", "simple_amp_init");
                  }
                }
                else
                {
                  dev_err(v1, "%s: parent dev not found\n", "simple_amp_init");
                }
              }
              else
              {
                dev_info(v1, "%s: parent node not found\n", "simple_amp_init");
              }
              simple_amp_regdump_register(v5, v77);
              *(_QWORD *)(v5 + 536) = 0xFFFFFFFE00000LL;
              *(_QWORD *)(v5 + 544) = v5 + 544;
              *(_QWORD *)(v5 + 552) = v5 + 544;
              *(_QWORD *)(v5 + 560) = simple_amp_temperature_work;
              *(_DWORD *)(v5 + 568) = 0;
              _init_swait_queue_head(v5 + 576, "&x->wait", &init_completion___key);
            }
            else
            {
              dev_err(v1, "name parsing for dev_index failed:%s\n", **(const char ***)(v5 + 32));
              v73 = -22;
            }
            goto LABEL_155;
          }
        }
LABEL_154:
        v73 = -12;
        goto LABEL_155;
      }
      v73 = v56;
      gpiod_direction_output(v55, 1);
    }
    dev_err(v1, "failed to devm_add_action_or_reset, %d\n", v73);
    goto LABEL_155;
  }
  v49 = v51;
  v50 = "Failed to enable regulators\n";
LABEL_96:
  v52 = v1;
LABEL_97:
  v73 = dev_err_probe(v52, v49, v50);
LABEL_155:
  _ReadStatusReg(SP_EL0);
  return v73;
}
