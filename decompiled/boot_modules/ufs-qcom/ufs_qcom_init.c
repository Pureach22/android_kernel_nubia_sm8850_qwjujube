__int64 __fastcall ufs_qcom_init(__int64 *a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x1
  const char *v8; // x2
  unsigned int v9; // w22
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned __int64 v12; // x0
  __int64 v13; // x22
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x1
  const char *v16; // x2
  __int64 v17; // x0
  __int64 v18; // x23
  int v19; // w0
  unsigned __int64 optional; // x0
  unsigned int v22; // w0
  __int64 v23; // x9
  __int64 v24; // x1
  __int64 v25; // x2
  _QWORD *v26; // x8
  __int64 v27; // x3
  unsigned int v28; // w0
  unsigned int v29; // w0
  unsigned int v30; // w0
  __int64 *i; // x25
  __int64 **v32; // x8
  const char *v33; // x24
  int v34; // w0
  __int64 v35; // x23
  unsigned __int64 v36; // x0
  unsigned __int64 v37; // x0
  int v38; // w0
  int v39; // w8
  int v40; // w8
  int v41; // w0
  unsigned __int64 v42; // x0
  _QWORD *v43; // x8
  __int64 v44; // x8
  __int64 v45; // x0
  int v46; // w8
  __int64 v47; // x0
  unsigned int v48; // w23
  const char *v49; // x1
  int v50; // w22
  const char *v51; // x2
  unsigned int v52; // w24
  __int64 v53; // x0
  int v54; // w22

  v1 = a1[8];
  v3 = devm_kmalloc(v1, 3216, 3520);
  if ( v3 )
  {
    v4 = v3;
    *(_QWORD *)(v3 + 16) = a1;
    if ( !a1 )
    {
      __break(0x800u);
      JUMPOUT(0xDE9C);
    }
    v5 = a1[8];
    a1[23] = v4;
    if ( *(_QWORD *)(v5 + 744) )
      *(_BYTE *)(v4 + 497) = of_find_property(*(_QWORD *)(v5 + 744), "qcom,enable-crash-on-err", 0) != 0;
    v6 = _devm_reset_control_get();
    *(_QWORD *)(v4 + 192) = v6;
    if ( v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      v7 = v6;
      v8 = "Failed to get reset control\n";
LABEL_21:
      v9 = dev_err_probe(v1, v7, v8);
      goto LABEL_22;
    }
    v10 = *(_QWORD *)(v1 + 744);
    *(_QWORD *)(v4 + 200) = &ufs_qcom_reset_ops;
    *(_QWORD *)(v4 + 256) = v10;
    v11 = *(_QWORD *)(*(_QWORD *)(v1 + 136) + 16LL);
    *(_DWORD *)(v4 + 288) = 1;
    *(_QWORD *)(v4 + 208) = v11;
    if ( (unsigned int)devm_reset_controller_register(v1) )
      dev_warn(v1, "Failed to register reset controller\n");
    v12 = devm_phy_get(v1, "ufsphy");
    *(_QWORD *)(v4 + 8) = v12;
    if ( v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      v7 = v12;
      v8 = "Failed to get PHY\n";
      goto LABEL_21;
    }
    v13 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 64LL);
    v14 = devm_of_icc_get(v13, "ufs-ddr");
    *(_QWORD *)(v4 + 136) = v14;
    if ( v14 < 0xFFFFFFFFFFFFF001LL
      && (v14 = devm_of_icc_get(v13, "cpu-ufs"), *(_QWORD *)(v4 + 144) = v14, v14 < 0xFFFFFFFFFFFFF001LL) )
    {
      v18 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 64LL);
      v19 = icc_set_bw(*(_QWORD *)(v4 + 136), 0, 7643136);
      if ( (v19 & 0x80000000) == 0 )
      {
        v19 = icc_set_bw(*(_QWORD *)(v4 + 144), 0, 819200);
        if ( (v19 & 0x80000000) == 0 )
          goto LABEL_19;
      }
      v46 = v19;
      v47 = v18;
      v48 = v46;
      dev_err(v47, "failed to set bandwidth request: %d\n", v46);
      v16 = "failed to set bandwidth request\n";
      v17 = v13;
      v15 = v48;
    }
    else
    {
      v15 = v14;
      v16 = "failed to acquire interconnect path\n";
      v17 = v13;
    }
    v9 = dev_err_probe(v17, v15, v16);
    if ( v9 )
    {
LABEL_22:
      a1[23] = 0;
      return v9;
    }
LABEL_19:
    optional = devm_gpiod_get_optional(v1, "reset", 7);
    *(_QWORD *)(v4 + 296) = optional;
    if ( optional >= 0xFFFFFFFFFFFFF001LL )
    {
      v7 = optional;
      v8 = "Failed to acquire device reset gpio\n";
      goto LABEL_21;
    }
    v22 = readl((unsigned int *)(*a1 + 228));
    v23 = *a1;
    v24 = v22 >> 28;
    v25 = HIWORD(v22) & 0xFFF;
    v26 = (_QWORD *)a1[332];
    *(_WORD *)(v4 + 170) = v22;
    *(_BYTE *)(v4 + 174) = v24;
    *(_WORD *)(v4 + 172) = HIWORD(v22) & 0xFFF;
    *(_QWORD *)(v4 + 160) = v23 + 220;
    *(_DWORD *)(v4 + 180) = 0x4000000;
    if ( v26 )
    {
      *(_QWORD *)(v4 + 368) = ufs_qcom_vdd_hba_reg_notifier;
      devm_regulator_register_notifier(*v26, v4 + 368);
      v24 = *(unsigned __int8 *)(v4 + 174);
      v25 = *(unsigned __int16 *)(v4 + 172);
      v27 = *(unsigned __int16 *)(v4 + 170);
    }
    else
    {
      v27 = v22;
    }
    ufs_qcom_phy_save_controller_version(*(_QWORD *)(v4 + 8), v24, v25, v27);
    ufs_qcom_parse_reg_info(v4, "qcom,vddp-ref-clk", v4 + 392);
    v28 = phy_init(*(_QWORD *)(v4 + 8));
    if ( v28 )
    {
      v9 = v28;
      dev_err(a1[8], "%s: phy init failed, err %d\n", "ufs_qcom_init", v28);
      goto LABEL_22;
    }
    _mutex_init(v4 + 424, "&host->phy_mutex", &ufs_qcom_init___key);
    if ( *(_QWORD *)(v4 + 392) )
    {
      v29 = ufs_qcom_enable_vreg();
      if ( v29 )
      {
        v9 = v29;
        dev_err(v1, "%s: failed enabling ref clk supply: %d\n", "ufs_qcom_init", v29);
LABEL_92:
        phy_exit(*(_QWORD *)(v4 + 8));
        goto LABEL_22;
      }
    }
    ufs_qcom_parse_reg_info(v4, "qcom,vccq-parent", v4 + 400);
    if ( *(_QWORD *)(v4 + 400) )
    {
      v30 = ufs_qcom_enable_vreg();
      if ( v30 )
      {
        v9 = v30;
        dev_err(v1, "%s: failed enable vccq-parent err=%d\n", "ufs_qcom_init", v30);
LABEL_90:
        if ( *(_QWORD *)(v4 + 392) )
          ufs_qcom_disable_vreg();
        goto LABEL_92;
      }
    }
    for ( i = (__int64 *)a1[333]; i != a1 + 333; i = (__int64 *)*i )
    {
      v33 = (const char *)i[3];
      if ( !strcmp(v33, "core_clk_unipro") )
      {
        *((_BYTE *)i + 44) = 1;
        v32 = (__int64 **)(v4 + 696);
      }
      else
      {
        v34 = strcmp(v33, "ref_clk");
        v32 = (__int64 **)(v4 + 688);
        if ( v34 )
          continue;
      }
      *v32 = i;
    }
    v35 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 64LL);
    v36 = devm_clk_get(v35, "rx_lane0_sync_clk");
    v9 = v36;
    if ( v36 > 0xFFFFFFFFFFFFF000LL )
    {
      if ( (_DWORD)v36 == -517 || (dev_err(v35, "failed to get %s err %d\n", "rx_lane0_sync_clk", v36), v9) )
      {
        dev_err(v35, "%s: failed to get rx_lane0_sync_clk, err %d\n", "ufs_qcom_init_lane_clks", v9);
        goto LABEL_88;
      }
    }
    else
    {
      *(_QWORD *)(v4 + 96) = v36;
    }
    v37 = devm_clk_get(v35, "tx_lane0_sync_clk");
    if ( v37 > 0xFFFFFFFFFFFFF000LL )
    {
      if ( (_DWORD)v37 != -517 )
      {
        v50 = v37;
        dev_err(v35, "failed to get %s err %d\n", "tx_lane0_sync_clk", v37);
        LODWORD(v37) = v50;
      }
      v49 = "%s: failed to get tx_lane0_sync_clk, err %d\n";
    }
    else
    {
      *(_QWORD *)(v4 + 104) = v37;
      if ( *(_DWORD *)(*(_QWORD *)(v4 + 16) + 2688LL) < 2u )
        goto LABEL_50;
      v37 = devm_clk_get(v35, "rx_lane1_sync_clk");
      if ( v37 <= 0xFFFFFFFFFFFFF000LL )
      {
        *(_QWORD *)(v4 + 112) = v37;
        v37 = devm_clk_get(v35, "tx_lane1_sync_clk");
        if ( v37 < 0xFFFFFFFFFFFFF001LL )
        {
LABEL_49:
          *(_QWORD *)(v4 + 120) = v37;
LABEL_50:
          if ( (ufs_qcom_is_genpd_supported(a1) & 1) != 0 )
          {
            *(_DWORD *)(a1[7] + 2456) = 50;
            *((_DWORD *)a1 + 22) = 1;
          }
          ufs_qcom_get_device_id(v4);
          ufs_qcom_parse_pm_levels(a1);
          ufs_qcom_parse_limits(v4);
          ufs_qcom_parse_g4_workaround_flag(v4);
          ufs_qcom_parse_lpm(v4);
          if ( *(_BYTE *)(v4 + 360) == 1 )
            pm_runtime_forbid(*(_QWORD *)(*(_QWORD *)(v4 + 16) + 64LL));
          ufs_qcom_parse_wb(v4);
          ufs_qcom_parse_pbl_rst_workaround_flag(v4);
          ufs_qcom_parse_max_cpus(v4);
          ufs_qcom_parse_storage_boost_flag(v4);
          ufs_qcom_parse_broken_ahit_workaround_flag(v4);
          ufs_qcom_set_caps(a1);
          ufs_qcom_advertise_quirks(a1);
          v38 = ufs_qcom_shared_ice_init(a1);
          if ( v38 )
            dev_err(a1[8], "Shared ICE Init failed, ret=%d\n", v38);
          v9 = ufs_qcom_ice_init(v4);
          if ( v9 )
            goto LABEL_22;
          ufshcd_qti_hba_init_crypto_capabilities(a1);
          v39 = *((_DWORD *)a1 + 677);
          if ( v39 == 4 || v39 == 1 )
          {
            v40 = *((_DWORD *)a1 + 678);
            if ( v40 == 4 || v40 == 1 )
              ufs_qcom_dev_ref_clk_ctrl(v4, 1);
          }
          *(_WORD *)(v4 + 188) = 9483;
          v41 = ufs_qcom_testbus_config(v4);
          if ( v41 )
            dev_warn(v1, "%s: failed to configure the testbus %d\n", "ufs_qcom_init", v41);
          ufs_qcom_init_sysfs(a1);
          ufs_qcom_init_bus_vote_sysfs(v4);
          v42 = devm_thermal_of_cooling_device_register(v1, *(_QWORD *)(v1 + 744), "ufs", v1, ufs_thermal_ops);
          *(_QWORD *)(v4 + 480) = v42;
          if ( v42 >= 0xFFFFFFFFFFFFF001LL )
            dev_warn(v1, "Thermal mitigation registration failed.\n");
          else
            *(_QWORD *)(v4 + 488) = 0;
          ufs_qcom_save_host_ptr(a1);
          ufs_qcom_populate_cluster_info(a1);
          ufs_qcom_qos_init(a1);
          ufs_qcom_parse_irq_affinity(a1);
          v43 = (_QWORD *)a1[23];
          v43[390] = v43 + 390;
          v43[391] = v43 + 390;
          v43[242] = "gear1-4";
          v43[389] = "gear5";
          v44 = a1[23];
          *(_QWORD *)(v44 + 3200) = 0x4000000005LL;
          *(_DWORD *)(v44 + 3208) = 128;
          v45 = ipc_log_context_create(10, "ufs-qcom", 0);
          *(_QWORD *)(v4 + 656) = v45;
          if ( v45 )
          {
            if ( (msm_minidump_enabled(v45) & 1) != 0 )
              goto LABEL_68;
          }
          else
          {
            v53 = dev_warn(v1, "IPC Log init - failed\n");
            if ( (msm_minidump_enabled(v53) & 1) != 0 )
            {
LABEL_68:
              ufs_qcom_register_minidump(v4, 3216, "UFS_QHOST");
              ufs_qcom_register_minidump(a1, 5368, "UFS_HBA");
              ufs_qcom_register_minidump(a1[7], 2472, "UFS_SHOST");
              *(_QWORD *)(v4 + 3152) = ufs_qcom_panic_handler;
              *(_DWORD *)(v4 + 3168) = 2147483646;
              if ( (unsigned int)atomic_notifier_chain_register(&panic_notifier_list, v4 + 3152) )
                dev_err(*(_QWORD *)(*(_QWORD *)(v4 + 16) + 64LL), "Fail to register UFS panic notifier\n");
            }
          }
          return 0;
        }
        if ( (_DWORD)v37 == -517 )
        {
          v9 = -517;
          goto LABEL_88;
        }
        if ( (_DWORD)v37 == -2 )
        {
          v37 = 0;
          goto LABEL_49;
        }
        v49 = "failed to get %s err %d\n";
        v51 = "tx_lane1_sync_clk";
        goto LABEL_87;
      }
      if ( (_DWORD)v37 != -517 )
      {
        v54 = v37;
        dev_err(v35, "failed to get %s err %d\n", "rx_lane1_sync_clk", v37);
        LODWORD(v37) = v54;
      }
      v49 = "%s: failed to get rx_lane1_sync_clk, err %d\n";
    }
    v51 = "ufs_qcom_init_lane_clks";
LABEL_87:
    v52 = v37;
    dev_err(v35, v49, v51, (unsigned int)v37);
    v9 = v52;
LABEL_88:
    if ( *(_QWORD *)(v4 + 400) )
      ufs_qcom_disable_vreg();
    goto LABEL_90;
  }
  return (unsigned int)-12;
}
