__int64 __fastcall msm_pcie_pm_suspend(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  int v4; // w0
  int v5; // w21
  unsigned int v6; // w20
  int saved_state; // w0
  unsigned int v8; // w0
  void *v9; // x0
  unsigned int v10; // w0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x21
  __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x20
  int v18; // w23
  int v19; // w21
  int v20; // w0
  __int64 v21; // x20
  int v22; // w21
  int v23; // w0
  const char *v24; // x1
  const char *v25; // x20
  __int64 v26; // x20
  _BYTE *v27; // x21
  __int64 v29; // x21
  __int64 v30; // x22
  __int64 v31; // x21
  int v32; // w0
  __int64 v33; // x21
  int v34; // w0
  int v35; // w0
  __int64 v36; // x0
  unsigned int v37; // w21
  __int64 v38; // x0
  int v39; // w21
  int v40; // w21

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL);
  if ( v2 )
  {
    ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_pm_suspend", *(_DWORD *)(v2 + 1348));
    ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d: entry\n", "msm_pcie_pm_suspend", *(_DWORD *)(v2 + 1348));
  }
  v3 = raw_spin_lock_irqsave(v2 + 1472);
  *(_BYTE *)(v2 + 1568) = 1;
  raw_spin_unlock_irqrestore(v2 + 1472, v3);
  if ( *(_BYTE *)(v2 + 1752) == 1 && (*(_QWORD *)(v2 + 1760) & 1) != 0 )
  {
    if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "DBG1:%s: RC%d: cancel link_recover_wq at pm suspend\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: RC%d: cancel link_recover_wq at pm suspend\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348));
    }
    cancel_work_sync(v2 + 1760);
  }
  if ( (*(_BYTE *)(v2 + 1692) & 1) == 0 )
  {
    if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "DBG1:%s: PCIe: power of RC%d has been turned off.\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe: power of RC%d has been turned off.\n",
        "msm_pcie_pm_suspend",
        *(unsigned int *)(v2 + 1348));
    }
    return 0;
  }
  if ( (msm_pcie_confirm_linkup(v2, 1, 1, a1) & 1) == 0 )
  {
    kfree(*(_QWORD *)(v2 + 1192));
    *(_QWORD *)(v2 + 1192) = 0;
    if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "DBG1:%s: PCIe: RC%d: load default config space\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe: RC%d: load default config space\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348));
      saved_state = pci_load_saved_state(a1, *(_QWORD *)(v2 + 1184));
      if ( !saved_state )
      {
LABEL_17:
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "DBG1:%s: PCIe: RC%d: store saved state\n",
          "msm_pcie_pm_suspend",
          *(_DWORD *)(v2 + 1348));
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d: store saved state\n",
          "msm_pcie_pm_suspend",
          *(_DWORD *)(v2 + 1348));
        goto LABEL_22;
      }
      v39 = saved_state;
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "ERR:%s: PCIe: RC%d: fail to load default state:%d.\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348),
        saved_state);
      v6 = v39;
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe: RC%d: fail to load default state:%d.\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348),
        v39);
    }
    else
    {
      v10 = pci_load_saved_state(a1, qword_4A0);
      if ( !v10 )
        goto LABEL_22;
      v6 = v10;
    }
    v9 = &unk_29455;
    goto LABEL_66;
  }
  if ( v2 )
  {
    ipc_log_string(
      *(_QWORD *)(v2 + 1704),
      "DBG1:%s: PCIe: RC%d: save config space\n",
      "msm_pcie_pm_suspend",
      *(_DWORD *)(v2 + 1348));
    ipc_log_string(
      *(_QWORD *)(v2 + 1696),
      "%s: PCIe: RC%d: save config space\n",
      "msm_pcie_pm_suspend",
      *(_DWORD *)(v2 + 1348));
    v4 = pci_save_state(a1);
    if ( v4 )
    {
      v5 = v4;
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "ERR:%s: PCIe: RC%d: fail to save state:%d.\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348),
        v4);
      v6 = v5;
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe: RC%d: fail to save state:%d.\n",
        "msm_pcie_pm_suspend",
        *(_DWORD *)(v2 + 1348),
        v5);
LABEL_20:
      v9 = &unk_2F95E;
LABEL_66:
      printk(v9);
      *(_BYTE *)(v2 + 1568) = 0;
      return v6;
    }
    goto LABEL_17;
  }
  v8 = pci_save_state(a1);
  if ( v8 )
  {
    v6 = v8;
    goto LABEL_20;
  }
LABEL_22:
  *(_QWORD *)(v2 + 1192) = pci_store_saved_state(a1);
  v11 = raw_spin_lock_irqsave(v2 + 1060);
  *(_QWORD *)(v2 + 1064) = v11;
  *(_BYTE *)(v2 + 1056) = 0;
  raw_spin_unlock_irqrestore(v2 + 1060, v11);
  v12 = writel_relaxed_0(0x10u, (unsigned int *)(*(_QWORD *)(v2 + 888) + 4LL));
  __dsb(0xEu);
  if ( v2 )
  {
    ipc_log_string(
      *(_QWORD *)(v2 + 1704),
      "DBG1:%s: RC%d: PME_TURNOFF_MSG is sent out\n",
      "msm_pcie_pm_suspend",
      *(_DWORD *)(v2 + 1348));
    v12 = ipc_log_string(
            *(_QWORD *)(v2 + 1696),
            "%s: RC%d: PME_TURNOFF_MSG is sent out\n",
            "msm_pcie_pm_suspend",
            *(_DWORD *)(v2 + 1348));
  }
  v13 = *(_QWORD *)(v2 + 1560);
  v14 = ktime_get(v12);
  v15 = readl(*(_QWORD *)(v2 + 872) + 40LL);
  if ( (v15 & 0x380) != 0x180 )
  {
    v16 = v14 + 1000 * v13;
    while ( !v13 || ktime_get(v15) <= v16 )
    {
      usleep_range_state(2501, 10000, 2);
      __yield();
      v15 = readl(*(_QWORD *)(v2 + 872) + 40LL);
      if ( (v15 & 0x380) == 0x180 )
        goto LABEL_30;
    }
    LOWORD(v15) = readl(*(_QWORD *)(v2 + 872) + 40LL);
  }
LABEL_30:
  if ( v2 )
  {
    v17 = *(_QWORD *)(v2 + 1704);
    v18 = v15 & 0x380;
    v19 = *(_DWORD *)(v2 + 1348);
    v20 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v2 + 872) + 40LL));
    ipc_log_string(v17, "DBG1:%s: RC%d: PCIE20_PARF_PM_STTS_1 is 0x%x.\n", "msm_pcie_pm_suspend", v19, v20);
    v21 = *(_QWORD *)(v2 + 1696);
    v22 = *(_DWORD *)(v2 + 1348);
    v23 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v2 + 872) + 40LL));
    ipc_log_string(v21, "%s: RC%d: PCIE20_PARF_PM_STTS_1 is 0x%x.\n", "msm_pcie_pm_suspend", v22, v23);
    if ( v18 == 384 )
      v24 = "DBG1:%s: RC%d: PM_Enter_L23 is received\n";
    else
      v24 = "DBG1:%s: RC%d: PM_Enter_L23 is NOT received\n";
    if ( v18 == 384 )
      v25 = "%s: RC%d: PM_Enter_L23 is received\n";
    else
      v25 = "%s: RC%d: PM_Enter_L23 is NOT received\n";
    ipc_log_string(*(_QWORD *)(v2 + 1704), v24, "msm_pcie_pm_suspend", *(unsigned int *)(v2 + 1348));
    ipc_log_string(*(_QWORD *)(v2 + 1696), v25, "msm_pcie_pm_suspend", *(unsigned int *)(v2 + 1348));
  }
  if ( *(_BYTE *)(v2 + 1720) == 1 && *(_QWORD *)(v2 + 1744) )
    pinctrl_select_state(*(_QWORD *)(v2 + 1728));
  if ( v2 )
  {
    ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_disable", *(_DWORD *)(v2 + 1348));
    ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d: entry\n", "msm_pcie_disable", *(_DWORD *)(v2 + 1348));
    v26 = v2 + 1120;
    mutex_lock(v2 + 1120);
    if ( *(_BYTE *)(v2 + 1692) != 1 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "DBG1:%s: PCIe: the link of RC%d is already power down.\n",
        "msm_pcie_disable",
        *(_DWORD *)(v2 + 1348));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe: the link of RC%d is already power down.\n",
        "msm_pcie_disable",
        *(_DWORD *)(v2 + 1348));
      mutex_unlock(v2 + 1120);
LABEL_44:
      ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_pm_suspend", *(_DWORD *)(v2 + 1348));
      ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d: exit\n", "msm_pcie_pm_suspend", *(unsigned int *)(v2 + 1348));
      return 0;
    }
    v27 = (_BYTE *)(v2 + 1692);
LABEL_51:
    if ( (*(_BYTE *)(v2 + 1340) & 1) == 0 )
      msm_msi_config_access(*(_QWORD *)(*(_QWORD *)(v2 + 8) + 816LL), 0);
    *(_DWORD *)(v2 + 1176) = 2;
    *v27 = 0;
    ++*(_QWORD *)(v2 + 1552);
    if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "INFO:%s: PCIe: Assert the reset of endpoint of RC%d.\n",
        "msm_pcie_disable",
        *(_DWORD *)(v2 + 1348));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe: Assert the reset of endpoint of RC%d.\n",
        "msm_pcie_disable",
        *(_DWORD *)(v2 + 1348));
    }
    printk(&unk_23B65);
    msm_pcie_config_perst(v2, 1);
    v29 = *(unsigned int *)(v2 + 1288);
    if ( (_DWORD)v29 )
    {
      v30 = *(_QWORD *)(v2 + 880);
      writel_relaxed_0(0, (unsigned int *)(v30 + v29));
      readl_relaxed_0((unsigned int *)(v30 + v29));
    }
    v31 = *(_QWORD *)(v2 + 872);
    v32 = readl_relaxed_0((unsigned int *)(v31 + 64));
    writel_relaxed_0(v32 | 1, (unsigned int *)(v31 + 64));
    readl_relaxed_0((unsigned int *)(v31 + 64));
    v33 = *(_QWORD *)(v2 + 872);
    v34 = readl_relaxed_0((unsigned int *)(v33 + 708));
    writel_relaxed_0(v34 | 1, (unsigned int *)(v33 + 708));
    readl_relaxed_0((unsigned int *)(v33 + 708));
    if ( *(_QWORD *)(v2 + 3128) )
    {
      v35 = msm_pcie_cesta_map_apply(v2, 0);
      if ( v35 )
      {
        v40 = v35;
        if ( v2 )
        {
          ipc_log_string(
            *(_QWORD *)(v2 + 1704),
            "ERR:%s: Failed to move to D3 cold state %d\n",
            "msm_pcie_disable",
            v35);
          ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: Failed to move to D3 cold state %d\n", "msm_pcie_disable", v40);
        }
        printk(&unk_29487);
      }
    }
    msm_pcie_clk_deinit(v2);
    msm_pcie_gdsc_deinit((const char ***)v2);
    msm_pcie_vreg_deinit(v2);
    msm_pcie_pipe_clk_deinit(v2);
    v36 = *(unsigned int *)(v2 + 328);
    if ( (_DWORD)v36 )
    {
      v37 = 1 - *(_DWORD *)(v2 + 336);
      v38 = gpio_to_desc(v36);
      gpiod_set_raw_value(v38, v37);
    }
    mutex_unlock(v26);
    if ( !v2 )
      return 0;
    ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_disable", *(_DWORD *)(v2 + 1348));
    ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d: exit\n", "msm_pcie_disable", *(_DWORD *)(v2 + 1348));
    goto LABEL_44;
  }
  v26 = 1120;
  mutex_lock(1120);
  v27 = &byte_69C;
  if ( (byte_69C & 1) != 0 )
    goto LABEL_51;
  mutex_unlock(1120);
  return 0;
}
