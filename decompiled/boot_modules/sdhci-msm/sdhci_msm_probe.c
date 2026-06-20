__int64 __fastcall sdhci_msm_probe(__int64 a1)
{
  __int64 v2; // x21
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x0
  unsigned __int8 *v6; // x22
  int v7; // w2
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x20
  unsigned __int64 v10; // x23
  __int64 v11; // x8
  int group; // w0
  __int64 v13; // x8
  __int64 v14; // x1
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v18; // x0
  __int64 match_data; // x0
  unsigned int *v20; // x26
  __int64 v21; // x23
  __int64 v22; // x23
  __int64 v23; // x0
  __int64 property; // x0
  __int64 v25; // x0
  int v26; // w24
  _DWORD *v27; // x8
  unsigned __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x24
  __int64 v31; // x27
  unsigned __int64 v32; // x0
  int v33; // w0
  int v34; // w0
  unsigned __int64 v35; // x0
  int v36; // w0
  int v37; // w3
  unsigned __int64 v38; // x0
  unsigned __int64 v39; // x8
  int v40; // w0
  unsigned __int64 v41; // x25
  int v42; // w0
  unsigned __int64 v43; // x0
  unsigned __int64 v44; // x24
  _QWORD *v45; // x8
  __int64 v46; // x24
  unsigned __int64 v47; // x0
  int v48; // w0
  __int64 v49; // x2
  void (__fastcall *v50)(__int64, unsigned __int64, __int64); // x8
  __int64 v51; // x1
  __int64 (__fastcall *v52)(unsigned __int64, __int64); // x8
  int v53; // w0
  __int64 v54; // x2
  __int64 v55; // x0
  void (__fastcall *v56)(__int64, unsigned __int64, __int64); // x8
  __int64 v57; // x23
  int v58; // w0
  __int64 v59; // x27
  __int64 v60; // x1
  __int64 (__fastcall *v61)(unsigned __int64, __int64); // x8
  unsigned int v62; // w23
  unsigned int v63; // w26
  unsigned int v64; // w24
  int v65; // w0
  int v66; // w0
  _BOOL4 v68; // w8
  _QWORD *v69; // x25
  unsigned __int64 v70; // x24
  int v71; // w24
  __int64 v72; // x26
  int is_supported_voltage; // w23
  int v74; // w0
  int v75; // w27
  int v76; // w0
  int v77; // w0
  int v78; // w0
  int v79; // w0
  unsigned __int64 v80; // x0
  int v81; // w0
  bool v82; // zf
  __int64 v83; // x0
  int v84; // w0
  __int64 v85; // x21
  unsigned __int64 v86; // x20
  __int64 v87; // x1
  int v88; // [xsp+0h] [xbp-70h] BYREF
  int v89; // [xsp+4h] [xbp-6Ch] BYREF
  _QWORD v90[10]; // [xsp+8h] [xbp-68h] BYREF
  _QWORD v91[3]; // [xsp+58h] [xbp-18h] BYREF

  v91[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  if ( !of_find_property(v2, "non-removable", 0) )
    goto LABEL_9;
  v90[0] = 0;
  LODWORD(v91[0]) = 0;
  v3 = nvmem_cell_get(a1 + 16, "boot_conf");
  if ( v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_warn(a1 + 16, "nvmem cell get failed\n");
    if ( (is_bootdevice_sdhci & 1) != 0 )
      goto LABEL_9;
LABEL_80:
    dev_err(a1 + 16, "SDHCI is not boot dev.\n");
    LODWORD(v10) = 0;
    goto LABEL_22;
  }
  v4 = v3;
  v5 = nvmem_cell_read();
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_warn(a1 + 16, "nvmem cell read failed\n");
  }
  else
  {
    v6 = (unsigned __int8 *)v5;
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "boot_device_type", v91, 1, 0) & 0x80000000) != 0 )
    {
      dev_warn(a1 + 16, "boot_device_type not present\n");
    }
    else
    {
      v7 = (*v6 >> 1) & 0x1F;
      is_bootdevice_sdhci = LODWORD(v91[0]) == v7;
      if ( LODWORD(v91[0]) != v7 )
        dev_err(a1 + 16, "boot dev in reg = 0x%x boot dev in dtsi = 0x%x\n", v7, LODWORD(v91[0]));
    }
    kfree(v6);
  }
  nvmem_cell_put(v4);
  if ( (is_bootdevice_sdhci & 1) == 0 )
    goto LABEL_80;
LABEL_9:
  v8 = sdhci_pltfm_init(a1, &sdhci_msm_pdata, 768);
  v9 = v8;
  if ( v8 < 0xFFFFFFFFFFFFF001LL )
  {
    v11 = *(_QWORD *)(v8 + 72);
    *(_DWORD *)(v8 + 1264) = 0;
    *(_QWORD *)(v8 + 1536) = v11;
    *(_QWORD *)(v8 + 1408) = a1;
    group = sysfs_create_group(a1 + 16, &sdhci_msm_sysfs_group);
    if ( group )
      dev_err(a1 + 16, "%s: Failed to create qcom sysfs group (err = %d)\n", "sdhci_msm_init_sysfs", group);
    v13 = *(_QWORD *)(v9 + 72);
    v14 = *(_QWORD *)(v13 + 120);
    if ( !v14 )
      v14 = *(_QWORD *)(v13 + 8);
    v15 = ipc_log_context_create(10, v14, 0);
    *(_QWORD *)(v9 + 2160) = v15;
    if ( !v15 )
      dev_warn(a1 + 16, "IPC Log init - failed\n");
    v16 = *(_QWORD *)(v9 + 72);
    if ( *(_QWORD *)(v16 + 976) && (*(_BYTE *)(v16 + 997) & 1) == 0 )
    {
      wakeup_source_unregister(*(_QWORD *)(v16 + 976));
      *(_QWORD *)(*(_QWORD *)(v9 + 72) + 976LL) = 0;
      v16 = *(_QWORD *)(v9 + 72);
    }
    LODWORD(v10) = mmc_of_parse(v16);
    if ( (_DWORD)v10 )
      goto LABEL_21;
    v18 = *(_QWORD *)(a1 + 760);
    if ( v18 )
    {
      LODWORD(v10) = of_alias_get_id(v18, "mmc");
      if ( (v10 & 0x80000000) != 0 )
      {
        dev_err(a1 + 16, "get slot index failed %d\n", v10);
      }
      else if ( (unsigned int)v10 <= 2 )
      {
        sdhci_slot[(unsigned int)v10] = v9 + 1408;
      }
    }
    else
    {
      LODWORD(v10) = 0;
    }
    match_data = of_device_get_match_data(a1 + 16);
    if ( !match_data )
    {
      dev_err(a1 + 16, "Compatible string not found\n");
LABEL_21:
      sdhci_pltfm_free(a1);
      goto LABEL_22;
    }
    *(_BYTE *)(v9 + 1608) = *(_BYTE *)match_data;
    *(_BYTE *)(v9 + 1609) = *(_BYTE *)(match_data + 1);
    *(_QWORD *)(v9 + 1616) = *(_QWORD *)(match_data + 8);
    v20 = *(unsigned int **)(match_data + 16);
    *(_QWORD *)(v9 + 1624) = v20;
    sdhci_get_property(a1);
    v21 = *(_QWORD *)(a1 + 760);
    if ( (of_property_read_variable_u32_array(v21, "qcom,ddr-config", v9 + 2152, 1, 0) & 0x80000000) != 0 )
      *(_DWORD *)(v9 + 2152) = -2147219341;
    of_property_read_variable_u32_array(v21, "qcom,dll-config", v9 + 2148, 1, 0);
    if ( (unsigned int)of_device_is_compatible(v21, "qcom,msm8916-sdhci") )
      *(_DWORD *)(v9 + 12) |= 0x200u;
    *(_BYTE *)(v9 + 1563) = -1;
    v22 = *(_QWORD *)(a1 + 760);
    v88 = 0;
    v91[0] = 0;
    v23 = devm_kmalloc(a1 + 16, 16, 3520);
    *(_QWORD *)(v9 + 1528) = v23;
    if ( !v23 )
    {
      dev_err(a1 + 16, "failed to allocate memory for vreg data\n");
      goto LABEL_87;
    }
    if ( (unsigned int)sdhci_msm_dt_parse_vreg_info(a1 + 16, v23, &unk_105E1) )
    {
      dev_err(a1 + 16, "failed parsing vdd data\n");
      goto LABEL_87;
    }
    if ( (unsigned int)sdhci_msm_dt_parse_vreg_info(a1 + 16, *(_QWORD *)(v9 + 1528) + 8LL, "vdd-io") )
    {
      dev_err(a1 + 16, "failed parsing vdd-io data\n");
      goto LABEL_87;
    }
    if ( of_get_property(v22, "qcom,core_3_0v_support", 0) )
      *(_BYTE *)(v9 + 2025) = 1;
    *(_BYTE *)(v9 + 2040) = of_find_property(v22, "qcom,restore-after-cx-collapse", 0) != 0;
    property = of_find_property(v22, "qcom,uses_level_shifter", 0);
    *(_BYTE *)(v9 + 2145) = property != 0;
    if ( property )
      *(_BYTE *)(v9 + 2169) = of_find_property(v22, "qcom,external-fb-clk", 0) != 0;
    v25 = of_find_property(v22, "qcom,dll_lock_bist_fail_wa", 0);
    v90[0] = 0;
    *(_BYTE *)(v9 + 2146) = v25 != 0;
    v89 = 0;
    if ( !(unsigned int)sdhci_msm_dt_get_array(a1 + 16, "qcom,dll-hsr-list", v90, &v89) )
    {
      if ( v89 != 5 )
      {
        dev_err(a1 + 16, "Number of HSR entries are not matching\n");
        v26 = 0;
        if ( *(_QWORD *)(v9 + 2032) )
        {
LABEL_44:
          if ( v26 )
            goto LABEL_45;
          goto LABEL_87;
        }
LABEL_161:
        dev_info(a1 + 16, "Failed to get dll hsr settings from dt\n");
        if ( v26 )
        {
LABEL_45:
          if ( (unsigned int)sdhci_msm_dt_get_array(a1 + 16, "qcom,ice-clk-rates", v91, &v88) )
            goto LABEL_50;
          v27 = (_DWORD *)v91[0];
          if ( !v91[0] || !v88 )
            goto LABEL_50;
          if ( v88 == 2 )
          {
            *(_QWORD *)(v9 + 2120) = v91[0];
            *(_BYTE *)(v9 + 2128) = 2;
            *(_DWORD *)(v9 + 2132) = *v27;
            *(_DWORD *)(v9 + 2136) = v27[1];
LABEL_50:
            *(_BYTE *)(v9 + 2010) = of_find_property(v22, "qcom,vbias-skip-wa", 0) != 0;
            v28 = _devm_reset_control_get(a1 + 16, "core_reset", 0, 0, 0, 1);
            *(_QWORD *)(v9 + 2016) = v28;
            if ( v28 >= 0xFFFFFFFFFFFFF001LL )
            {
              dev_err(a1 + 16, "core_reset unavailable,err = %d\n", v28);
              *(_QWORD *)(v9 + 2016) = 0;
            }
            sdhci_msm_gcc_reset(a1 + 16, v9);
            v29 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,restore-after-cx-collapse", 0);
            v30 = *(_QWORD *)(v9 + 1408);
            v31 = *(_QWORD *)(v9 + 1536);
            *(_BYTE *)(v9 + 2040) = v29 != 0;
            v32 = devm_clk_get(v30 + 16, "bus");
            *(_QWORD *)(v9 + 1432) = v32;
            if ( v32 <= 0xFFFFFFFFFFFFF000LL )
            {
              LODWORD(v10) = clk_set_rate();
              if ( (_DWORD)v10 )
                goto LABEL_21;
              v41 = *(_QWORD *)(v9 + 1432);
              LODWORD(v10) = clk_prepare(v41);
              if ( (_DWORD)v10 )
                goto LABEL_21;
              v42 = clk_enable(v41);
              if ( v42 )
              {
                LODWORD(v10) = v42;
                v43 = v41;
LABEL_199:
                clk_unprepare(v43);
                goto LABEL_21;
              }
            }
            v10 = devm_clk_get(v30 + 16, "iface");
            if ( v10 >= 0xFFFFFFFFFFFFF001LL )
            {
              dev_err(v30 + 16, "Peripheral clk setup failed (%d)\n", v10);
              goto LABEL_92;
            }
            *(_QWORD *)(v9 + 1472) = v10;
            v10 = devm_clk_get(v30 + 16, "core");
            if ( v10 >= 0xFFFFFFFFFFFFF001LL )
            {
              dev_err(v30 + 16, "SDC MMC clk setup failed (%d)\n", v10);
              goto LABEL_92;
            }
            *(_QWORD *)(v9 + 1456) = v10;
            LODWORD(v10) = dev_pm_opp_of_find_icc_paths(v30 + 16, 0);
            if ( (_DWORD)v10 )
              goto LABEL_92;
            v91[0] = "core";
            v91[1] = 0;
            v90[0] = v91;
            memset(&v90[1], 0, 72);
            v33 = dev_pm_opp_set_config(v30 + 16, v90);
            *(_DWORD *)(v9 + 1544) = v33;
            if ( v33 < 1 )
            {
              LODWORD(v10) = v33;
              goto LABEL_92;
            }
            v34 = dev_pm_opp_of_add_table(v30 + 16);
            if ( v34 != -19 )
            {
              LODWORD(v10) = v34;
              if ( v34 )
              {
                dev_err(v30 + 16, "Invalid OPP table in Device tree\n");
                goto LABEL_72;
              }
              *(_BYTE *)(v9 + 1548) = 1;
            }
            if ( (unsigned int)dev_pm_opp_set_rate(v30 + 16, 0x7FFFFFFF) )
              dev_warn(v30 + 16, "core clock boost failed\n");
            *(_QWORD *)(v9 + 1488) = 0;
            v35 = devm_clk_get(v30 + 16, "ice_core");
            if ( v35 <= 0xFFFFFFFFFFFFF000LL )
            {
              *(_QWORD *)(v9 + 1488) = v35;
              v36 = clk_set_rate();
              v37 = *(_DWORD *)(v9 + 2132);
              if ( v36 )
              {
                LODWORD(v10) = v36;
                dev_err(v30 + 16, "ICE_CLK rate set failed (%d) for %u\n", v36, v37);
                goto LABEL_92;
              }
              *(_DWORD *)(v9 + 2140) = v37;
            }
            v38 = devm_clk_get(v30 + 16, "cal");
            if ( v38 <= 0xFFFFFFFFFFFFF000LL )
              v39 = v38;
            else
              v39 = 0;
            *(_QWORD *)(v9 + 1504) = v39;
            LODWORD(v10) = clk_bulk_prepare(4, v9 + 1448);
            if ( (_DWORD)v10 )
            {
LABEL_72:
              if ( *(_BYTE *)(v9 + 1548) == 1 )
                dev_pm_opp_of_remove_table(v30 + 16);
              dev_pm_opp_clear_config(*(unsigned int *)(v9 + 1544));
LABEL_92:
              v44 = *(_QWORD *)(v9 + 1432);
              if ( v44 <= 0xFFFFFFFFFFFFF000LL )
              {
                clk_disable(*(_QWORD *)(v9 + 1432));
                clk_unprepare(v44);
              }
              if ( (_DWORD)v10 )
                goto LABEL_21;
LABEL_95:
              *(_QWORD *)(v9 + 1760) = 0xFFFFFFFE00000LL;
              *(_QWORD *)(v9 + 1768) = v9 + 1768;
              *(_QWORD *)(v9 + 1776) = v9 + 1768;
              *(_QWORD *)(v9 + 1784) = sdhci_msm_clkgate_bus_delayed_work;
              init_timer_key(v9 + 1792, &delayed_work_timer_fn, 0x200000, 0, 0);
              v45 = *(_QWORD **)(v9 + 1528);
              if ( !v45 )
                goto LABEL_103;
              v46 = v45[1];
              if ( *v45 )
              {
                LODWORD(v10) = sdhci_msm_vreg_init_reg(a1 + 16);
                if ( (_DWORD)v10 || !v46 )
                {
LABEL_102:
                  if ( (_DWORD)v10 )
                  {
                    dev_err(a1 + 16, "vreg reset failed (%d)\n", v10);
                    dev_err(a1 + 16, "Regulator setup failed (%d)\n", v10);
LABEL_190:
                    if ( (*(_BYTE *)(v9 + 1641) & 1) == 0 )
                    {
                      sdhci_msm_bus_get_and_set_vote(v9, 0);
                      v85 = *(_QWORD *)(v9 + 1648);
                      if ( *(_QWORD *)(v85 + 40) )
                        icc_put();
                      if ( *(_QWORD *)(v85 + 48) )
                        icc_put();
                    }
                    clk_bulk_disable(4, v9 + 1448);
                    clk_bulk_unprepare(4, v9 + 1448);
                    if ( *(_BYTE *)(v9 + 1548) == 1 )
                      dev_pm_opp_of_remove_table(a1 + 16);
                    dev_pm_opp_clear_config(*(unsigned int *)(v9 + 1544));
                    v86 = *(_QWORD *)(v9 + 1432);
                    if ( v86 > 0xFFFFFFFFFFFFF000LL )
                      goto LABEL_21;
                    clk_disable(v86);
                    v43 = v86;
                    goto LABEL_199;
                  }
LABEL_103:
                  if ( (*(_BYTE *)(v9 + 1608) & 1) != 0
                    || (v47 = devm_platform_ioremap_resource(a1, 1),
                        *(_QWORD *)(v9 + 1416) = v47,
                        v47 < 0xFFFFFFFFFFFFF001LL) )
                  {
                    writel_relaxed(0xA9Cu, (unsigned int *)(*(_QWORD *)(v9 + 24) + v20[17]));
                    v48 = readl_relaxed((unsigned int *)(*(_QWORD *)(v9 + 24) + v20[24]));
                    writel_relaxed(v48 & 0xFFFFFBFF, (unsigned int *)(*(_QWORD *)(v9 + 24) + v20[24]));
                    if ( (*(_BYTE *)(v9 + 1608) & 1) == 0 )
                    {
                      v49 = *v20;
                      v50 = *(void (__fastcall **)(__int64, unsigned __int64, __int64))(*(_QWORD *)(v9 + 1616) + 8LL);
                      if ( *((_DWORD *)v50 - 1) != 1443578770 )
                        __break(0x8228u);
                      v50(1, v9, v49);
                      v51 = *v20;
                      v52 = **(__int64 (__fastcall ***)(unsigned __int64, __int64))(v9 + 1616);
                      if ( *((_DWORD *)v52 - 1) != -1793813973 )
                        __break(0x8228u);
                      v53 = v52(v9, v51);
                      v54 = *v20;
                      v55 = v53 | 0x2000u;
                      v56 = *(void (__fastcall **)(__int64, unsigned __int64, __int64))(*(_QWORD *)(v9 + 1616) + 8LL);
                      if ( *((_DWORD *)v56 - 1) != 1443578770 )
                        __break(0x8228u);
                      v56(v55, v9, v54);
                    }
                    if ( of_find_property(v2, "is_rumi", 0) )
                    {
                      v57 = *(_QWORD *)(v9 + 1624);
                      v58 = readl_relaxed((unsigned int *)(*(_QWORD *)(v9 + 24) + *(unsigned int *)(v57 + 88)));
                      if ( (*(_BYTE *)(*(_QWORD *)(v9 + 72) + 997LL) & 1) == 0 )
                        writel_relaxed(
                          v58 & 0xFFFFFFF8,
                          (unsigned int *)(*(_QWORD *)(v9 + 24) + *(unsigned int *)(v57 + 88)));
                    }
                    v59 = *(_QWORD *)(v9 + 1624);
                    readw_relaxed(*(_QWORD *)(v9 + 24) + 254LL);
                    v60 = *(unsigned int *)(v59 + 16);
                    v61 = **(__int64 (__fastcall ***)(unsigned __int64, __int64))(v9 + 1616);
                    if ( *((_DWORD *)v61 - 1) != -1793813973 )
                      __break(0x8228u);
                    v62 = v61(v9, v60);
                    v63 = v62 & 0xF0000000;
                    v64 = readl_relaxed((unsigned int *)(*(_QWORD *)(v9 + 24) + 64LL));
                    if ( (v62 & 0xF0000000) == 0x10000000 && (unsigned __int8)v62 <= 0x33u )
                    {
                      *(_BYTE *)(v9 + 1564) = 1;
                    }
                    else if ( v63 == 0x10000000 && (unsigned __int8)v62 >= 0x42u )
                    {
                      *(_BYTE *)(v9 + 1560) = 1;
                    }
                    if ( *(_BYTE *)(v9 + 2025) == 1 )
                    {
                      v64 |= 0x2000000u;
                      v65 = readl_relaxed((unsigned int *)(*(_QWORD *)(v9 + 24) + 64LL));
                      writel_relaxed(v65 | v64, (unsigned int *)(*(_QWORD *)(v9 + 24) + *(unsigned int *)(v59 + 84)));
                    }
                    writel_relaxed(v64, (unsigned int *)(*(_QWORD *)(v9 + 24) + *(unsigned int *)(v59 + 84)));
                    *(_DWORD *)(v9 + 1604) = v64;
                    if ( v63 == 0x10000000
                      && (unsigned int)(unsigned __int8)v62 - 110 <= 4
                      && ((1 << (v62 - 110)) & 0x19) != 0 )
                    {
                      *(_BYTE *)(v9 + 2026) = 1;
                    }
                    if ( v62 >> 28 && (unsigned int)(unsigned __int8)v62 - 19 <= 0xFFFFFFFD )
                    {
                      v66 = readl_relaxed((unsigned int *)(*(_QWORD *)(v9 + 24) + 64LL));
                      writel_relaxed(
                        v66 | 0x2040000,
                        (unsigned int *)(*(_QWORD *)(v9 + 24) + *(unsigned int *)(v59 + 84)));
                    }
                    if ( v63 == 0x10000000 && (unsigned __int8)v62 >= 0x49u )
                      *(_BYTE *)(v9 + 1640) = 1;
                    v68 = v63 == 0x10000000 && (unsigned __int8)v62 > 0x6Au;
                    if ( v68 )
                      *(_BYTE *)(v9 + 2008) = 1;
                    if ( v63 == 0x10000000 && (unsigned __int8)v62 >= 0x71u )
                      *(_BYTE *)(v9 + 2144) = 1;
                    if ( v68 )
                      *(_BYTE *)(v9 + 2008) = 1;
                    LODWORD(v10) = mmc_regulator_get_supply(*(_QWORD *)(v9 + 1536));
                    if ( !(_DWORD)v10 )
                    {
                      v69 = *(_QWORD **)(v9 + 1536);
                      v70 = v69[177];
                      if ( v70 <= 0xFFFFFFFFFFFFF000LL )
                      {
                        v72 = *(_QWORD *)(v9 + 1624);
                        is_supported_voltage = regulator_is_supported_voltage(v69[177], 1700000, 1950000);
                        v74 = regulator_is_supported_voltage(v70, 2700000, 3600000);
                        v71 = v74 ? ((is_supported_voltage != 0) << 26) | 0x2000000 : (is_supported_voltage != 0) << 26;
                        if ( v74 | is_supported_voltage )
                        {
                          v75 = *(_DWORD *)(v9 + 1572);
                          v76 = readl_relaxed((unsigned int *)(v69[227] + *(unsigned int *)(v72 + 68)));
                          if ( (v71 & 0x2000000) != 0 && (v75 & 8) != 0 )
                          {
                            v77 = v76 & 0xFFFE7FFF | 0x8000;
                          }
                          else
                          {
                            v82 = (v75 & 4) == 0 && is_supported_voltage == 0;
                            v77 = v82 ? v76 | 0x8000 : v76 | 0x18000;
                          }
                          writel_relaxed(v77, (unsigned int *)(v69[227] + *(unsigned int *)(v72 + 68)));
                        }
                        else
                        {
                          v87 = v69[15];
                          if ( !v87 )
                            v87 = v69[1];
                          printk(&unk_10D32, v87);
                          v71 = 0;
                        }
                      }
                      else
                      {
                        v71 = 0;
                      }
                      *(_DWORD *)(v9 + 1604) |= v71;
                      LODWORD(v10) = sdhci_msm_setup_pwr_irq(v9 + 1408);
                      if ( !(_DWORD)v10 )
                      {
                        *(_DWORD *)(*(_QWORD *)(v9 + 1536) + 996LL) |= 0x80u;
                        *(_DWORD *)(*(_QWORD *)(v9 + 1536) + 996LL) |= 0x400200u;
                        sdhci_msm_setup_pm(a1, v9 + 1408);
                        *(_QWORD *)(v9 + 160) = sdhci_msm_start_signal_voltage_switch;
                        *(_QWORD *)(v9 + 176) = sdhci_msm_execute_tuning;
                        v83 = alloc_workqueue("%s", (const char *)0x40008);
                        *(_QWORD *)(v9 + 1864) = v83;
                        if ( !v83 )
                          dev_err(a1 + 16, "Generic swq creation failed\n");
                        *(_QWORD *)(v9 + 2000) = 0xA000000C8LL;
                        sdhci_msm_qos_init(v9 + 1408);
                        sdhci_msm_init_sysfs_gating_qos(a1 + 16);
                        if ( of_find_property(v2, "supports-cqe", 0) )
                          v84 = sdhci_msm_cqe_add_host(v9, a1);
                        else
                          v84 = sdhci_add_host(v9);
                        LODWORD(v10) = v84;
                        if ( !v84 )
                        {
                          *(_BYTE *)(v9 + 2024) = 1;
                          *(_QWORD *)(a1 + 536) = ktime_get_mono_fast_ns();
                          _pm_runtime_suspend(a1 + 16, 13);
                          goto LABEL_22;
                        }
                        _pm_runtime_disable(a1 + 16, 1);
                        _pm_runtime_set_status(a1 + 16, 2);
                        pm_runtime_put_noidle(a1 + 16);
                      }
                    }
                  }
                  else
                  {
                    LODWORD(v10) = v47;
                  }
                  goto LABEL_190;
                }
              }
              else if ( !v46 )
              {
                goto LABEL_103;
              }
              LODWORD(v10) = sdhci_msm_vreg_init_reg(a1 + 16);
              goto LABEL_102;
            }
            v40 = clk_bulk_enable(4, v9 + 1448);
            if ( v40 )
            {
              LODWORD(v10) = v40;
LABEL_71:
              clk_bulk_unprepare(4, v9 + 1448);
              goto LABEL_72;
            }
            v78 = qcom_clk_set_flags(*(_QWORD *)(v9 + 1456), 3);
            if ( v78 )
              dev_err(v30 + 16, "Failed to set core clk NORETAIN_MEM: %d\n", v78);
            v79 = qcom_clk_set_flags(*(_QWORD *)(v9 + 1488), 2);
            if ( v79 )
              dev_err(v30 + 16, "Failed to set ice clk RETAIN_MEM: %d\n", v79);
            v80 = devm_clk_get(v30 + 16, "xo");
            *(_QWORD *)(v9 + 1440) = v80;
            if ( v80 >= 0xFFFFFFFFFFFFF001LL )
              dev_warn(v30 + 16, "TCXO clk not present (%d)\n", v80);
            v81 = sdhci_msm_bus_register(v9 + 1408, v30);
            if ( v81 )
            {
              if ( (*(_BYTE *)(v9 + 1641) & 1) == 0 )
              {
                LODWORD(v10) = v81;
                dev_err(v30 + 16, "Bus registration failed (%d)\n", v81);
                clk_bulk_disable(4, v9 + 1448);
                goto LABEL_71;
              }
            }
            else if ( (*(_BYTE *)(v9 + 1641) & 1) == 0 )
            {
              sdhci_msm_bus_voting(v31 + 1792, 1);
            }
            if ( *(_BYTE *)(v9 + 2169) == 1 )
              sdhci_enable_ext_fb_clk(v31 + 1792);
            goto LABEL_95;
          }
          dev_err(a1 + 16, "Need max and min frequencies\n");
        }
LABEL_87:
        dev_err(a1 + 16, "DT parsing error\n");
        LODWORD(v10) = 1;
        goto LABEL_21;
      }
      *(_QWORD *)(v9 + 2032) = v90[0];
    }
    v26 = 1;
    if ( *(_QWORD *)(v9 + 2032) )
      goto LABEL_44;
    goto LABEL_161;
  }
  LODWORD(v10) = v8;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v10;
}
