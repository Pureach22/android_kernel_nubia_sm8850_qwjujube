__int64 __fastcall msm_pcie_show_status(__int64 a1)
{
  __int64 v2; // x0
  const char *v3; // x4
  const char *v4; // x3
  const char *v5; // x3
  const char *v6; // x3
  const char *v7; // x3
  const char *v8; // x3
  const char *v9; // x3
  const char *v10; // x3
  const char *v11; // x3
  const char *v12; // x3
  const char *v13; // x3
  const char *v14; // x3
  const char *v15; // x3
  const char *v16; // x3

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 1712);
    if ( *(_BYTE *)(a1 + 1357) )
      v3 = (const char *)&unk_24FCB;
    else
      v3 = "not";
    ipc_log_string(
      v2,
      "DBG_FS:%s: PCIe: RC%d is %s enumerated\n",
      "msm_pcie_show_status",
      *(unsigned int *)(a1 + 1348),
      v3);
    printk(&unk_2C0EB);
    if ( *(_DWORD *)(a1 + 1176) == 1 )
      v4 = "enabled";
    else
      v4 = "disabled";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: PCIe: link is %s\n", "msm_pcie_show_status", v4);
  }
  else
  {
    printk(&unk_2C0EB);
  }
  printk(&unk_29E98);
  if ( a1 )
  {
    if ( *(_BYTE *)(a1 + 1056) )
      v5 = (const char *)&unk_24FCB;
    else
      v5 = "not";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: cfg_access is %s allowed\n", "msm_pcie_show_status", v5);
    printk(&unk_3056A);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: use_pinctrl is %d\n",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1720));
    printk(&unk_2BA3D);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: aux_clk_freq is %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1324));
    printk(&unk_2265D);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: user_suspend is %d\n",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1180));
    printk(&unk_2ACB9);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: num_parf_testbus_sel is 0x%x",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1616));
    printk(&unk_2FB56);
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: phy_len is %d", "msm_pcie_show_status", *(_DWORD *)(a1 + 1620));
    printk(&unk_2ACD3);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: num_pipe_clk: %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 840));
    printk(&unk_27E76);
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: num_clk: %d\n", "msm_pcie_show_status", *(_DWORD *)(a1 + 856));
    printk(&unk_276E7);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: disable_pc is %d",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1181));
    printk(&unk_29696);
    if ( *(_BYTE *)(a1 + 1217) )
      v6 = (const char *)&unk_24FCB;
    else
      v6 = "not";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: l0s_supported is %s supported\n", "msm_pcie_show_status", v6);
    printk(&unk_2ACE7);
    if ( *(_BYTE *)(a1 + 1218) )
      v7 = (const char *)&unk_24FCB;
    else
      v7 = "not";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: l1_supported is %s supported\n", "msm_pcie_show_status", v7);
    printk(&unk_2AD0C);
    if ( *(_BYTE *)(a1 + 1219) )
      v8 = (const char *)&unk_24FCB;
    else
      v8 = "not";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: l1ss_supported is %s supported\n", "msm_pcie_show_status", v8);
    printk(&unk_2A645);
    if ( *(_BYTE *)(a1 + 1220) )
      v9 = (const char *)&unk_24FCB;
    else
      v9 = "not";
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: l1_1_pcipm_supported is %s supported\n",
      "msm_pcie_show_status",
      v9);
    printk(&unk_2D5EC);
    if ( *(_BYTE *)(a1 + 1221) )
      v10 = (const char *)&unk_24FCB;
    else
      v10 = "not";
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: l1_2_pcipm_supported is %s supported\n",
      "msm_pcie_show_status",
      v10);
    printk(&unk_23A1E);
    if ( *(_BYTE *)(a1 + 1222) )
      v11 = (const char *)&unk_24FCB;
    else
      v11 = "not";
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: l1_1_aspm_supported is %s supported\n",
      "msm_pcie_show_status",
      v11);
    printk(&unk_3058A);
    if ( *(_BYTE *)(a1 + 1223) )
      v12 = (const char *)&unk_24FCB;
    else
      v12 = "not";
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: l1_2_aspm_supported is %s supported\n",
      "msm_pcie_show_status",
      v12);
    printk(&unk_286B1);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: l1_2_th_scale is %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1224));
    printk(&unk_276FA);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: l1_2_th_value is %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1228));
    printk(&unk_22677);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: common_clk_en is %d\n",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1232));
    printk(&unk_2DEF7);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: clk_power_manage_en is %d\n",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1233));
    printk(&unk_2E69D);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: aux_clk_sync is %d\n",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1234));
    printk(&unk_27734);
    if ( *(_BYTE *)(a1 + 1235) )
      v13 = (const char *)&unk_24FCB;
    else
      v13 = "not";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: AER is %s enable\n", "msm_pcie_show_status", v13);
    printk(&unk_2B3CC);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: boot_option is 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1332));
    printk(&unk_27ED5);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: link_speed_override is 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1336));
    printk(&unk_2FB99);
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: phy_ver is %d\n", "msm_pcie_show_status", *(_DWORD *)(a1 + 1352));
    printk(&unk_2E6BE);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: driver_probed is %d\n",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1356));
    printk(&unk_2C10E);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: linkdown_panic is %d\n",
      "msm_pcie_show_status",
      *(unsigned __int8 *)(a1 + 1328));
    printk(&unk_2D699);
    if ( *(_BYTE *)(a1 + 1568) )
      v14 = (const char *)&unk_24FCB;
    else
      v14 = "not";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: the link is %s suspending\n", "msm_pcie_show_status", v14);
    printk(&unk_2C129);
    if ( *(_BYTE *)(a1 + 1692) )
      v15 = (const char *)&unk_24FCB;
    else
      v15 = "not";
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: the power of RC is %s on\n", "msm_pcie_show_status", v15);
    printk(&unk_2C80A);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: smmu_sid_base: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1236));
    printk(&unk_29ED0);
    ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: n_fts: %d\n", "msm_pcie_show_status", *(_DWORD *)(a1 + 1264));
    printk(&unk_305B5);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: ep_latency: %dms\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1268));
    printk(&unk_2F60D);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: switch_latency: %dms\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1272));
    printk(&unk_2F625);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: wr_halt_size: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1276));
    printk(&unk_28E92);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: phy_status_offset: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1280));
    printk(&unk_2D6B5);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: phy_status_bit: %u\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1284));
    printk(&unk_23A4A);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: phy_power_down_offset: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1288));
    printk(&unk_296D1);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: eq_pset_req_vec: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1292));
    printk(&unk_2673B);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: core_preset: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1296));
    printk(&unk_22CB4);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: eq_fmdc_t_min_phase23: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1300));
    printk(&unk_2FBBC);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: cpl_timeout: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1304));
    printk(&unk_2C82A);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: current_bdf: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1308));
    printk(&unk_2D6D4);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: perst_delay_us_min: %dus\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1312));
    printk(&unk_21E74);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: perst_delay_us_max: %dus\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1316));
    printk(&unk_305C6);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: tlp_rd_size: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1320));
    printk(&unk_305E6);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: linkdown_counter: %lu\n",
      "msm_pcie_show_status",
      *(_QWORD *)(a1 + 1536));
    printk(&unk_25CFA);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: wake_counter: %lu\n",
      "msm_pcie_show_status",
      *(_QWORD *)(a1 + 1576));
    printk(&unk_2CE1E);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: link_check_max_count: %u\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1240));
    printk(&unk_2C16C);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: prevent_l1: %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1528));
    printk(&unk_26EEA);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: target_link_speed: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1244));
    printk(&unk_24304);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: current_link_speed: 0x%x\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1252));
    printk(&unk_2EEBB);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: target_link_width: %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1256));
    printk(&unk_296F4);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: current_link_width: %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1260));
    printk(&unk_27F34);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: link_width_max: %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 996));
    printk(&unk_2341C);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: link_speed_max: %d\n",
      "msm_pcie_show_status",
      *(_DWORD *)(a1 + 1000));
    printk(&unk_24323);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: link_turned_on_counter: %lu\n",
      "msm_pcie_show_status",
      *(_QWORD *)(a1 + 1544));
    printk(&unk_29711);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: link_turned_off_counter: %lu\n",
      "msm_pcie_show_status",
      *(_QWORD *)(a1 + 1552));
    printk(&unk_2FBDF);
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: l23_rdy_poll_timeout: %llu\n",
      "msm_pcie_show_status",
      *(_QWORD *)(a1 + 1560));
    printk(&unk_2E6D3);
    if ( *(_QWORD *)(a1 + 3128) )
      v16 = "CESTA";
    else
      v16 = (const char *)&unk_2CE37;
    ipc_log_string(
      *(_QWORD *)(a1 + 1712),
      "DBG_FS:%s: PCIe %s is used for resource voting\n",
      "msm_pcie_show_status",
      v16);
  }
  else
  {
    printk(&unk_3056A);
    printk(&unk_2BA3D);
    printk(&unk_2265D);
    printk(&unk_2ACB9);
    printk(&unk_2FB56);
    printk(&unk_2ACD3);
    printk(&unk_27E76);
    printk(&unk_276E7);
    printk(&unk_29696);
    printk(&unk_2ACE7);
    printk(&unk_2AD0C);
    printk(&unk_2A645);
    printk(&unk_2D5EC);
    printk(&unk_23A1E);
    printk(&unk_3058A);
    printk(&unk_286B1);
    printk(&unk_276FA);
    printk(&unk_22677);
    printk(&unk_2DEF7);
    printk(&unk_2E69D);
    printk(&unk_27734);
    printk(&unk_2B3CC);
    printk(&unk_27ED5);
    printk(&unk_2FB99);
    printk(&unk_2E6BE);
    printk(&unk_2C10E);
    printk(&unk_2D699);
    printk(&unk_2C129);
    printk(&unk_2C80A);
    printk(&unk_29ED0);
    printk(&unk_305B5);
    printk(&unk_2F60D);
    printk(&unk_2F625);
    printk(&unk_28E92);
    printk(&unk_2D6B5);
    printk(&unk_23A4A);
    printk(&unk_296D1);
    printk(&unk_2673B);
    printk(&unk_22CB4);
    printk(&unk_2FBBC);
    printk(&unk_2C82A);
    printk(&unk_2D6D4);
    printk(&unk_21E74);
    printk(&unk_305C6);
    printk(&unk_305E6);
    printk(&unk_25CFA);
    printk(&unk_2CE1E);
    printk(&unk_2C16C);
    printk(&unk_26EEA);
    printk(&unk_24304);
    printk(&unk_2EEBB);
    printk(&unk_296F4);
    printk(&unk_27F34);
    printk(&unk_2341C);
    printk(&unk_24323);
    printk(&unk_29711);
    printk(&unk_2FBDF);
    printk(&unk_2E6D3);
  }
  printk(&unk_23A64);
  if ( *(_BYTE *)(a1 + 1992) == 1 )
  {
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 1712),
        "DBG_FS:%s: PCIe L1ss sleep is supported using %s\n",
        "msm_pcie_show_status",
        *(const char **)(a1 + 1984));
    return printk(&unk_28760);
  }
  else
  {
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 1712), "DBG_FS:%s: PCIe L1ss sleep is not supported\n", "msm_pcie_show_status");
    return printk(&unk_29734);
  }
}
