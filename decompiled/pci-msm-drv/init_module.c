__int64 init_module()
{
  unsigned __int64 dir; // x0
  unsigned __int64 file; // x8
  void *v2; // x0
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  int v13; // w20
  __int64 v14; // x2
  unsigned int *v15; // x19
  __int64 v16; // x2
  unsigned int *v17; // x19
  unsigned int v18; // w19

  pcie_drv[0] = 0;
  _mutex_init(&unk_30CD8, "&pcie_drv.drv_lock", &pcie_init___key);
  _mutex_init(&unk_30D08, "&pcie_drv.rpmsg_lock", &pcie_init___key_725);
  crc8_populate_msb(&msm_pcie_crc8_table, 7);
  rc_sel_max = 1;
  wr_mask = -1;
  dir = debugfs_create_dir("pci-msm", 0);
  dent_msm_pcie = dir;
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_29969);
  }
  else
  {
    file = debugfs_create_file("rc_sel", 436, dir, 0, &msm_pcie_debugfs_rc_select_ops);
    dfile_rc_sel = file;
    v2 = &unk_23618;
    if ( !file )
      goto LABEL_24;
    if ( file > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v3 = debugfs_create_file("case", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_case_ops);
    dfile_case = v3;
    v2 = &unk_22820;
    if ( !v3 )
      goto LABEL_24;
    if ( v3 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v4 = debugfs_create_file("base_sel", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_base_select_ops);
    dfile_base_sel = v4;
    v2 = &unk_28284;
    if ( !v4 )
      goto LABEL_24;
    if ( v4 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v5 = debugfs_create_file("linkdown_panic", 420, dent_msm_pcie, 0, &msm_pcie_debugfs_linkdown_panic_ops);
    dfile_linkdown_panic = v5;
    v2 = &unk_23D62;
    if ( !v5 )
      goto LABEL_24;
    if ( v5 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v6 = debugfs_create_file("gen_speed_sel", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_gen_speed_select_ops);
    dfile_gen_speed_sel = v6;
    v2 = &unk_2999A;
    if ( !v6 )
      goto LABEL_24;
    if ( v6 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v7 = debugfs_create_file("wr_offset", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_wr_offset_ops);
    dfile_wr_offset = v7;
    v2 = &unk_25FB4;
    if ( !v7 )
      goto LABEL_24;
    if ( v7 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v8 = debugfs_create_file("wr_mask", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_wr_mask_ops);
    dfile_wr_mask = v8;
    v2 = &unk_2B580;
    if ( !v8 )
      goto LABEL_24;
    if ( v8 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v9 = debugfs_create_file("wr_value", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_wr_value_ops);
    dfile_wr_value = v9;
    v2 = &unk_2E8E5;
    if ( !v9 )
      goto LABEL_24;
    if ( v9 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_24;
    v10 = debugfs_create_file("boot_option", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_boot_option_ops);
    dfile_boot_option = v10;
    v2 = &unk_268D9;
    if ( !v10
      || v10 > 0xFFFFFFFFFFFFF000LL
      || (v11 = debugfs_create_file("aer_enable", 436, dent_msm_pcie, 0, &msm_pcie_debugfs_aer_enable_ops),
          dfile_aer_enable = v11,
          v2 = &unk_282C6,
          !v11)
      || v11 > 0xFFFFFFFFFFFFF000LL
      || (v12 = debugfs_create_file(
                  "corr_counter_limit",
                  436,
                  dent_msm_pcie,
                  0,
                  &msm_pcie_debugfs_corr_counter_limit_ops),
          dfile_corr_counter_limit = v12,
          v2 = &unk_25151,
          !v12)
      || v12 >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_24:
      printk(v2);
      debugfs_remove(dent_msm_pcie);
    }
  }
  if ( count == 5 && dword_30B8C >= 1 )
  {
    v13 = 0;
    do
    {
      if ( arm64_use_ng_mappings )
        v14 = 0x68000000000F13LL;
      else
        v14 = 0x68000000000713LL;
      v15 = (unsigned int *)ioremap_prot(dword_30B80 + pcie_sm_regs + dword_30B88 * v13, 4, v14);
      writel_relaxed_0(1u, v15);
      readl_relaxed_0(v15);
      iounmap(v15);
      if ( arm64_use_ng_mappings )
        v16 = 0x68000000000F13LL;
      else
        v16 = 0x68000000000713LL;
      v17 = (unsigned int *)ioremap_prot(dword_30B84 + pcie_sm_regs + dword_30B88 * v13, 4, v16);
      writel_relaxed_0(1u, v17);
      readl_relaxed_0(v17);
      iounmap(v17);
      ++v13;
    }
    while ( v13 < dword_30B8C );
  }
  v18 = _pci_register_driver(&msm_pci_driver, &_this_module, "pci_msm_drv");
  if ( !v18 )
  {
    mpcie_wq = alloc_workqueue("mpcie_wq", 131098, 1);
    if ( mpcie_wq )
    {
      qword_30D38 = (__int64)msm_pcie_ssr_notifier;
      qword_30CB8 = 0xFFFFFFFE00000LL;
      qword_30CC0 = (__int64)&qword_30CC0;
      qword_30CC8 = (__int64)&qword_30CC0;
      qword_30CD0 = (__int64)msm_pcie_drv_connect_notify_all;
      msm_pcie_dev[0] = 0;
      qword_30B50 = 0;
      qword_30B58 = 0;
      qword_30B60 = 0;
      qword_30B68 = 0;
      qword_30CA8 = (__int64)msm_pcie_dev;
      v18 = _platform_driver_register(msm_pcie_driver, &_this_module);
      if ( v18 )
        destroy_workqueue(mpcie_wq);
    }
    else
    {
      return (unsigned int)-12;
    }
  }
  return v18;
}
