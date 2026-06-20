__int64 __fastcall gdsc_probe(_QWORD *a1)
{
  _QWORD *v1; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 regulator_init_data; // x0
  __int64 v6; // x22
  unsigned __int64 v7; // x23
  unsigned __int64 v8; // x0
  unsigned int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x24
  __int64 v12; // x0
  __int64 v13; // x0
  int string_helper; // w0
  int v15; // w0
  bool v16; // w9
  __int64 v17; // x0
  bool v18; // w9
  __int64 v19; // x0
  bool v20; // w9
  __int64 v21; // x0
  bool v22; // w9
  __int64 v23; // x0
  bool v24; // w9
  __int64 v25; // x0
  bool v26; // w9
  __int64 v27; // x0
  bool v28; // w9
  __int64 v29; // x0
  __int64 property; // x0
  int v31; // w8
  __int64 v32; // x0
  int v33; // w0
  int v34; // w8
  __int64 v35; // x0
  __int64 inited; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x24
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v44; // x0
  unsigned __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  unsigned __int64 v49; // x8
  __int64 v50; // x0
  unsigned __int64 v51; // x0
  int v52; // w0
  __int64 v53; // x2
  unsigned int v54; // w8
  unsigned int v55; // w9
  char v56; // w8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x24
  char v60; // w8
  unsigned int v61; // w0
  __int64 v62; // x0
  unsigned int v63; // w0
  int v64; // w9
  __int64 v65; // x8
  __int64 v66; // x9
  unsigned __int64 v67; // x0
  int v68; // w0
  int v69; // w0
  int v70; // w21
  unsigned int v77; // w8
  unsigned int v78; // w8
  __int64 v79; // [xsp+0h] [xbp-90h] BYREF
  _QWORD *v80; // [xsp+8h] [xbp-88h] BYREF
  __int64 v81; // [xsp+10h] [xbp-80h]
  __int64 v82; // [xsp+18h] [xbp-78h]
  __int64 v83; // [xsp+20h] [xbp-70h]
  __int64 v84; // [xsp+28h] [xbp-68h]
  __int64 v85; // [xsp+30h] [xbp-60h]
  char *s1[11]; // [xsp+38h] [xbp-58h] BYREF

  v1 = a1 + 2;
  s1[10] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = nullptr;
  v81 = 0;
  v79 = 0;
  v3 = devm_kmalloc(a1 + 2, 520, 3520);
  if ( !v3 )
    goto LABEL_59;
  v4 = v3;
  regulator_init_data = of_get_regulator_init_data(v1, a1[95], v3 + 8);
  if ( !regulator_init_data )
    goto LABEL_59;
  v6 = regulator_init_data;
  if ( of_get_property(a1[95], "parent-supply", 0) )
    *(_QWORD *)v6 = "parent";
  LODWORD(v7) = of_property_read_string(a1[95], "regulator-name", v4 + 8);
  if ( (_DWORD)v7 )
    goto LABEL_60;
  if ( of_find_property(a1[95], "domain-addr", 0) )
  {
    v8 = syscon_regmap_lookup_by_phandle(a1[95], "domain-addr");
    *(_QWORD *)(v4 + 344) = v8;
    if ( v8 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_28;
  }
  if ( !of_find_property(a1[95], "sw-reset", 0) )
    goto LABEL_17;
  v9 = of_count_phandle_with_args(a1[95], "sw-reset", 0);
  *(_DWORD *)(v4 + 496) = v9;
  if ( (v9 & 0x80000000) != 0 )
  {
    *(_QWORD *)(v4 + 360) = 0;
    goto LABEL_59;
  }
  v10 = devm_kmalloc(v1, 8LL * v9, 3264);
  *(_QWORD *)(v4 + 360) = v10;
  if ( !v10 )
    goto LABEL_59;
  if ( *(int *)(v4 + 496) < 1 )
  {
LABEL_17:
    if ( !of_find_property(a1[95], "hw-ctrl-addr", 0)
      || (v8 = syscon_regmap_lookup_by_phandle(a1[95], "hw-ctrl-addr"),
          *(_QWORD *)(v4 + 352) = v8,
          v8 < 0xFFFFFFFFFFFFF001LL) )
    {
      v13 = a1[95];
      *(_DWORD *)(v4 + 508) = 1500;
      of_property_read_variable_u32_array(v13, "qcom,gds-timeout", v4 + 508, 1, 0);
      string_helper = of_property_read_string_helper(a1[95], "clock-names", 0, 0, 0);
      *(_DWORD *)(v4 + 484) = string_helper;
      if ( string_helper == -22 )
      {
        *(_DWORD *)(v4 + 484) = 0;
      }
      else if ( string_helper < 0 )
      {
        dev_err(v1, "Failed to get clock names, ret=%d\n", string_helper);
        LODWORD(v7) = *(_DWORD *)(v4 + 484);
        goto LABEL_29;
      }
      v15 = of_property_read_string_helper(a1[95], "interconnect-names", 0, 0, 0);
      *(_DWORD *)(v4 + 500) = v15;
      if ( v15 == -22 )
      {
        *(_DWORD *)(v4 + 500) = 0;
      }
      else if ( v15 < 0 )
      {
        dev_err(v1, "Failed to get interconnect names, ret=%d\n", v15);
        LODWORD(v7) = *(_DWORD *)(v4 + 500);
        goto LABEL_29;
      }
      v16 = of_find_property(a1[95], "qcom,enable-root-clk", 0) != 0;
      v17 = a1[95];
      *(_BYTE *)(v4 + 475) = v16;
      v18 = of_find_property(v17, "qcom,force-enable-root-clk", 0) != 0;
      v19 = a1[95];
      *(_BYTE *)(v4 + 476) = v18;
      v20 = of_find_property(v19, "qcom,reset-aon-logic", 0) != 0;
      v21 = a1[95];
      *(_BYTE *)(v4 + 481) = v20;
      v22 = of_find_property(v21, "qcom,no-status-check-on-disable", 0) != 0;
      v23 = a1[95];
      *(_BYTE *)(v4 + 477) = v22;
      v24 = of_find_property(v23, "qcom,retain-regs", 0) != 0;
      v25 = a1[95];
      *(_BYTE *)(v4 + 473) = v24;
      v26 = of_find_property(v25, "qcom,skip-disable-before-sw-enable", 0) != 0;
      v27 = a1[95];
      *(_BYTE *)(v4 + 512) = v26;
      v28 = of_find_property(v27, "qcom,support-cfg-gdscr", 0) != 0;
      v29 = a1[95];
      *(_BYTE *)(v4 + 515) = v28;
      if ( !of_find_property(v29, "qcom,collapse-vote", 0) )
        goto LABEL_33;
      if ( (unsigned int)of_property_count_elems_of_size(a1[95], "qcom,collapse-vote", 4) != 2 )
      {
        dev_err(v1, "qcom,collapse-vote needs two values\n");
        goto LABEL_66;
      }
      v8 = syscon_regmap_lookup_by_phandle(a1[95], "qcom,collapse-vote");
      *(_QWORD *)(v4 + 368) = v8;
      if ( v8 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_28;
      LODWORD(v7) = of_property_read_u32_index(a1[95], "qcom,collapse-vote", 1, v4 + 376);
      if ( (_DWORD)v7 || *(_DWORD *)(v4 + 376) >= 0x20u )
      {
        dev_err(v1, "qcom,collapse-vote vote_bit error\n");
      }
      else
      {
LABEL_33:
        property = of_find_property(a1[95], "qcom,skip-disable", 0);
        *(_BYTE *)(v4 + 513) = property != 0;
        if ( property )
        {
          v31 = *(_DWORD *)(v6 + 64) | 4;
          *(_DWORD *)(v6 + 60) = 6;
          *(_DWORD *)(v6 + 64) = v31;
        }
        v32 = of_find_property(a1[95], "qcom,skip-logic-collapse", 0);
        *(_BYTE *)(v4 + 472) = v32 == 0;
        if ( !v32 )
          goto LABEL_40;
        v33 = of_property_read_string_helper(a1[95], "reset-names", 0, 0, 0);
        *(_DWORD *)(v4 + 488) = v33;
        if ( v33 == -22 )
        {
          *(_DWORD *)(v4 + 488) = 0;
          goto LABEL_40;
        }
        if ( (v33 & 0x80000000) == 0 )
        {
LABEL_40:
          if ( of_find_property(a1[95], "qcom,support-hw-trigger", 0) )
          {
            v34 = *(_DWORD *)(v6 + 64) | 4;
            *(_DWORD *)(v6 + 60) |= 3u;
            *(_DWORD *)(v6 + 64) = v34;
            *(_BYTE *)(v4 + 482) = 1;
          }
          goto LABEL_42;
        }
        dev_err(v1, "Failed to get reset clock names\n");
        LODWORD(v7) = *(_DWORD *)(v4 + 488);
      }
LABEL_29:
      if ( (_DWORD)v7 )
        goto LABEL_60;
LABEL_42:
      if ( !platform_get_resource(a1, 512, 0) )
      {
        dev_err(v1, "Failed to get address resource\n");
        goto LABEL_66;
      }
      v35 = devm_ioremap(v1);
      *(_QWORD *)(v4 + 328) = v35;
      if ( v35 )
      {
        if ( of_find_property(a1[95], "qcom,no-config-gdscr", 0) )
          dword_2C8 = 0;
        inited = _devm_regmap_init_mmio_clk(v1, 0, *(_QWORD *)(v4 + 328), &gdsc_regmap_config, 0, 0);
        *(_QWORD *)(v4 + 336) = inited;
        if ( !inited )
        {
          dev_err(v1, "Couldn't get regmap\n");
          goto LABEL_66;
        }
        v37 = *(unsigned int *)(v4 + 484);
        if ( (v37 & 0x80000000) != 0 )
        {
          v38 = 0;
          *(_QWORD *)(v4 + 384) = 0;
          if ( !(_DWORD)v37 )
          {
LABEL_50:
            *(_DWORD *)(v4 + 492) = -1;
            if ( (int)v37 >= 1 )
            {
              v39 = 0;
              while ( 1 )
              {
                v40 = a1[95];
                s1[0] = nullptr;
                of_property_read_string_helper(v40, "clock-names", s1, 1, (unsigned int)v39);
                *(_QWORD *)(*(_QWORD *)(v4 + 384) + 8 * v39) = devm_clk_get(v1, s1[0]);
                v7 = *(_QWORD *)(*(_QWORD *)(v4 + 384) + 8 * v39);
                if ( v7 >= 0xFFFFFFFFFFFFF001LL )
                  break;
                if ( !strcmp(s1[0], "core_root_clk") )
                  *(_DWORD *)(v4 + 492) = v39;
                if ( ++v39 >= *(int *)(v4 + 484) )
                  goto LABEL_56;
              }
              if ( (_DWORD)v7 == -517 )
                goto LABEL_60;
LABEL_62:
              dev_err(v1, "Failed to get %s, ret=%d\n", s1[0], (unsigned int)v7);
              goto LABEL_60;
            }
LABEL_56:
            v41 = *(unsigned int *)(v4 + 500);
            if ( (v41 & 0x80000000) != 0 )
            {
              v42 = 0;
              *(_QWORD *)(v4 + 464) = 0;
              if ( (_DWORD)v41 )
              {
LABEL_58:
                if ( !v42 )
                  goto LABEL_59;
              }
            }
            else
            {
              v42 = devm_kmalloc(v1, 8 * v41, 3520);
              LODWORD(v41) = *(_DWORD *)(v4 + 500);
              *(_QWORD *)(v4 + 464) = v42;
              if ( (_DWORD)v41 )
                goto LABEL_58;
            }
            if ( (int)v41 >= 1 )
            {
              v7 = 0;
              while ( 1 )
              {
                v44 = a1[95];
                s1[0] = nullptr;
                of_property_read_string_helper(v44, "interconnect-names", s1, 1, (unsigned int)v7);
                *(_QWORD *)(*(_QWORD *)(v4 + 464) + 8 * v7) = of_icc_get(v1, s1[0]);
                v45 = *(_QWORD *)(*(_QWORD *)(v4 + 464) + 8 * v7);
                if ( v45 >= 0xFFFFFFFFFFFFF001LL )
                  break;
                if ( (__int64)++v7 >= *(int *)(v4 + 500) )
                  goto LABEL_79;
              }
              LODWORD(v7) = *(_QWORD *)(*(_QWORD *)(v4 + 464) + 8 * v7);
              if ( (_DWORD)v45 != -517 )
                dev_err(v1, "Failed to get path %s, ret=%d\n", s1[0], (unsigned int)v45);
              goto LABEL_60;
            }
LABEL_79:
            if ( (*(_BYTE *)(v4 + 475) & 1) == 0 && *(_BYTE *)(v4 + 476) != 1 || *(_DWORD *)(v4 + 492) != -1 )
            {
              if ( (*(_BYTE *)(v4 + 472) & 1) != 0 )
                goto LABEL_95;
              v46 = *(unsigned int *)(v4 + 488);
              if ( (v46 & 0x80000000) != 0 )
              {
                v47 = 0;
                *(_QWORD *)(v4 + 456) = 0;
                if ( (_DWORD)v46 )
                {
LABEL_85:
                  if ( !v47 )
                    goto LABEL_59;
                }
              }
              else
              {
                v47 = devm_kmalloc(v1, 8 * v46, 3520);
                LODWORD(v46) = *(_DWORD *)(v4 + 488);
                *(_QWORD *)(v4 + 456) = v47;
                if ( (_DWORD)v46 )
                  goto LABEL_85;
              }
              if ( (int)v46 >= 1 )
              {
                v7 = 0;
                while ( 1 )
                {
                  v48 = a1[95];
                  s1[0] = nullptr;
                  of_property_read_string_helper(v48, "reset-names", s1, 1, (unsigned int)v7);
                  *(_QWORD *)(*(_QWORD *)(v4 + 456) + 8 * v7) = _devm_reset_control_get(v1, s1[0], 0, 0, 0, 1);
                  v49 = *(_QWORD *)(*(_QWORD *)(v4 + 456) + 8 * v7);
                  if ( v49 >= 0xFFFFFFFFFFFFF001LL )
                    break;
                  if ( (__int64)++v7 >= *(int *)(v4 + 488) )
                    goto LABEL_95;
                }
                LODWORD(v7) = *(_QWORD *)(*(_QWORD *)(v4 + 456) + 8 * v7);
                if ( (_DWORD)v49 == -517 )
                  goto LABEL_60;
                goto LABEL_62;
              }
LABEL_95:
              regmap_read(*(_QWORD *)(v4 + 336), 0, (char *)&v79 + 4);
              v50 = a1[95];
              HIDWORD(v79) &= 0xFFFFFFF9;
              if ( of_find_property(v50, "mboxes", 0)
                && (*(_QWORD *)(v4 + 392) = v1,
                    *(_BYTE *)(v4 + 400) = 1,
                    *(_QWORD *)(v4 + 408) = 500,
                    *(_BYTE *)(v4 + 416) = 0,
                    v51 = mbox_request_channel(v4 + 392, 0),
                    *(_QWORD *)(v4 + 448) = v51,
                    v51 >= 0xFFFFFFFFFFFFF001LL) )
              {
                v70 = v51;
                dev_err(v1, "mailbox channel request failed, ret=%d\n", v51);
                *(_QWORD *)(v4 + 448) = 0;
                if ( v70 == -11 )
                  LODWORD(v7) = -517;
                else
                  LODWORD(v7) = v70;
              }
              else
              {
                v52 = of_property_read_variable_u32_array(a1[95], "qcom,clk-dis-wait-val", &v79, 1, 0);
                v53 = HIDWORD(v79);
                if ( (v52 & 0x80000000) == 0 )
                {
                  v54 = v79;
                  v55 = HIDWORD(v79) & 0xFFFF0FFF;
                  *(_BYTE *)(v4 + 482) = 1;
                  v54 <<= 12;
                  v53 = v53 & 0xFFFF0FFF | v54;
                  *(_DWORD *)(v4 + 504) = v54;
                  LODWORD(v79) = v54;
                  HIDWORD(v79) = v55 | v54;
                }
                regmap_write(*(_QWORD *)(v4 + 336), 0, v53);
                v56 = *(_BYTE *)(v4 + 472);
                if ( (v56 & 1) == 0 )
                {
                  v57 = *(_QWORD *)(v4 + 336);
                  HIDWORD(v79) &= ~1u;
                  regmap_write(v57, 0, HIDWORD(v79));
                  LODWORD(v7) = check_gdsc_status(v4, v1, 1);
                  if ( (_DWORD)v7 )
                    goto LABEL_101;
                  v56 = *(_BYTE *)(v4 + 472);
                }
                if ( (v56 & 1) != 0 )
                {
                  v58 = *(_QWORD *)(v4 + 368);
                  if ( v58 )
                  {
                    v59 = 1LL << *(_DWORD *)(v4 + 376);
                  }
                  else
                  {
                    v58 = *(_QWORD *)(v4 + 336);
                    LODWORD(v59) = 1;
                  }
                  LODWORD(s1[0]) = 0;
                  v61 = regmap_read(v58, 0, s1);
                  if ( (v61 & 0x80000000) != 0 )
                  {
                    LODWORD(v7) = v61;
                    dev_err(v1, "%s failed to get initial enable state, ret=%d\n", *(_QWORD *)(v4 + 8), v61);
                    goto LABEL_101;
                  }
                  v60 = ((__int64)s1[0] & (unsigned int)v59) == 0;
                }
                else
                {
                  v60 = *(_BYTE *)(v4 + 474) ^ 1;
                }
                v62 = *(_QWORD *)(v4 + 336);
                *(_BYTE *)(v4 + 478) = v60 & 1;
                LODWORD(s1[0]) = 0;
                v63 = regmap_read(v62, 0, s1);
                if ( (v63 & 0x80000000) != 0 )
                {
                  LODWORD(v7) = v63;
                  dev_err(v1, "%s failed to get initial hw_ctrl state, ret=%d\n", *(_QWORD *)(v4 + 8), v63);
                }
                else
                {
                  v64 = *(unsigned __int8 *)(v4 + 482);
                  *(_BYTE *)(v4 + 479) = ((__int64)s1[0] & 2) != 0;
                  if ( v64 == 1 )
                    *(_QWORD *)(a1[19] + 120LL) = &gdsc_pm_ops;
                  _X9 = &gdsc_probe_gdsc_count;
                  __asm { PRFM            #0x11, [X9] }
                  do
                  {
                    v77 = __ldxr((unsigned int *)&gdsc_probe_gdsc_count);
                    v78 = v77 + 1;
                  }
                  while ( __stlxr(v78, (unsigned int *)&gdsc_probe_gdsc_count) );
                  __dmb(0xBu);
                  *(_DWORD *)(v4 + 56) = v78;
                  *(_QWORD *)(v4 + 72) = &gdsc_ops;
                  *(_QWORD *)(v4 + 88) = &_this_module;
                  v65 = a1[95];
                  v66 = *(_QWORD *)(v4 + 336);
                  *(_DWORD *)(v4 + 84) = 0;
                  v80 = v1;
                  v81 = v6;
                  v82 = v4;
                  v83 = v65;
                  v84 = v66;
                  v67 = devm_regulator_register(v1, v4 + 8, &v80);
                  *(_QWORD *)v4 = v67;
                  if ( v67 >= 0xFFFFFFFFFFFFF001LL )
                  {
                    LODWORD(v7) = v67;
                    dev_err(v1, "regulator_register(\"%s\") failed, ret=%d\n", *(const char **)(v4 + 8), v67);
                  }
                  else
                  {
                    v68 = devm_regulator_proxy_consumer_register(v1, a1[95]);
                    if ( !v68 )
                    {
                      v69 = devm_regulator_debug_register(v1, *(_QWORD *)v4);
                      if ( v69 )
                        dev_err(v1, "failed to register debug regulator, ret=%d\n", v69);
                      LODWORD(v7) = 0;
                      a1[21] = v4;
                      goto LABEL_60;
                    }
                    LODWORD(v7) = v68;
                    dev_err(v1, "failed to register proxy consumer, ret=%d\n", v68);
                  }
                }
              }
LABEL_101:
              if ( *(_QWORD *)(v4 + 448) )
                mbox_free_channel();
              goto LABEL_60;
            }
            dev_err(v1, "Failed to get root clock name\n");
LABEL_66:
            LODWORD(v7) = -22;
            goto LABEL_60;
          }
        }
        else
        {
          v38 = devm_kmalloc(v1, 8 * v37, 3520);
          LODWORD(v37) = *(_DWORD *)(v4 + 484);
          *(_QWORD *)(v4 + 384) = v38;
          if ( !(_DWORD)v37 )
            goto LABEL_50;
        }
        if ( v38 )
          goto LABEL_50;
      }
LABEL_59:
      LODWORD(v7) = -12;
      goto LABEL_60;
    }
LABEL_28:
    LODWORD(v7) = v8;
    goto LABEL_29;
  }
  v11 = 0;
  while ( 1 )
  {
    v12 = a1[95];
    memset(s1, 0, 80);
    LODWORD(v7) = -19;
    if ( (unsigned int)_of_parse_phandle_with_args(v12, "sw-reset", 0, 0, (unsigned int)v11, s1) || !s1[0] )
      break;
    *(_QWORD *)(*(_QWORD *)(v4 + 360) + 8 * v11) = syscon_node_to_regmap();
    v7 = *(_QWORD *)(*(_QWORD *)(v4 + 360) + 8 * v11);
    if ( v7 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_29;
    if ( ++v11 >= *(int *)(v4 + 496) )
      goto LABEL_17;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
