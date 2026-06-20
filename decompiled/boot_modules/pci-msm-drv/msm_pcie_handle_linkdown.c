__int64 __fastcall msm_pcie_handle_linkdown(__int64 result)
{
  char v1; // w8
  __int64 v2; // x19
  int v3; // w0
  int v4; // w20
  int v5; // w0
  unsigned int v6; // w22
  __int64 v7; // x20
  int v8; // w0
  int v9; // w20
  unsigned int v10; // w22
  int v11; // w3

  if ( *(_DWORD *)(result + 1176) != 4 )
  {
    v1 = *(_BYTE *)(result + 1568);
    v2 = result;
    *(_DWORD *)(result + 1176) = 4;
    if ( (v1 & 1) == 0 && (*(_BYTE *)(result + 3156) & 1) == 0 )
    {
      if ( result )
        ipc_log_string(
          *(_QWORD *)(result + 1712),
          "DUMP:%s: PCIe:Linkdown IRQ for RC%d Dumping PCIe registers\n",
          "msm_pcie_handle_linkdown",
          *(_DWORD *)(result + 1348));
      pcie_phy_dump(v2);
      pcie_parf_dump(v2);
      pcie_dm_core_dump(v2);
      pcie_sm_dump(v2);
      if ( *(_QWORD *)(v2 + 3128) )
      {
        v3 = crm_dump_regs("pcie_crm");
        if ( v2 )
        {
          if ( v3 )
            ipc_log_string(
              *(_QWORD *)(v2 + 1712),
              "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n",
              "pcie_crm_dump",
              *(_DWORD *)(v2 + 1348),
              v3);
        }
      }
    }
    if ( *(_BYTE *)(v2 + 1341) == 1 )
    {
      if ( v2 )
        ipc_log_string(
          *(_QWORD *)(v2 + 1712),
          "DUMP:%s: PCIe:Linkdown IRQ for RC%d attempt recovery\n",
          "msm_pcie_linkdown_recovery",
          *(_DWORD *)(v2 + 1348));
      v4 = 99;
      while ( 1 )
      {
        v5 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v2 + 872) + 560LL));
        if ( (v5 & 0x100) != 0 )
          break;
        _const_udelay(42950);
        if ( --v4 == -1 )
          goto LABEL_21;
      }
      if ( v2 )
      {
        v6 = v5;
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "DBG1:%s: flush complete (%d), status:%x\n",
          "msm_pcie_linkdown_recovery",
          v4,
          v5);
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: flush complete (%d), status:%x\n",
          "msm_pcie_linkdown_recovery",
          v4,
          v6);
        if ( !v4 )
        {
          ipc_log_string(
            *(_QWORD *)(v2 + 1704),
            "DBG1:%s: flush timeout, status:%x\n",
            "msm_pcie_linkdown_recovery",
            v6);
          ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: flush timeout, status:%x\n", "msm_pcie_linkdown_recovery", v6);
          goto LABEL_29;
        }
      }
      else if ( !v4 )
      {
        goto LABEL_29;
      }
LABEL_21:
      v7 = *(_QWORD *)(v2 + 872);
      v8 = readl_relaxed_0((unsigned int *)(v7 + 432));
      writel_relaxed_0(v8 | 0x400u, v7 + 432);
      readl_relaxed_0((unsigned int *)(v7 + 432));
      v9 = 99;
      while ( 1 )
      {
        result = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v2 + 872) + 432LL));
        if ( (result & 0x800) == 0 )
          break;
        result = _const_udelay(42950);
        if ( --v9 == -1 )
          return result;
      }
      if ( v2 )
      {
        v10 = result;
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "DBG1:%s: flush mode clear:%d, %x\n",
          "msm_pcie_linkdown_recovery",
          v9,
          result);
        result = ipc_log_string(
                   *(_QWORD *)(v2 + 1696),
                   "%s: flush mode clear:%d, %x\n",
                   "msm_pcie_linkdown_recovery",
                   v9,
                   v10);
        if ( v9 )
          return result;
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "DBG1:%s: flush-mode timeout, status:%x\n",
          "msm_pcie_linkdown_recovery",
          v10);
        ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: flush-mode timeout, status:%x\n", "msm_pcie_linkdown_recovery", v10);
      }
      else if ( v9 )
      {
        return result;
      }
    }
LABEL_29:
    v11 = *(_DWORD *)(v2 + 1348);
    if ( (((unsigned __int64)(unsigned int)msm_pcie_keep_resources_on >> v11) & 1) == 0 )
    {
      msm_pcie_config_perst(v2, 1);
      v11 = *(_DWORD *)(v2 + 1348);
    }
    if ( v2 )
    {
      ipc_log_string(*(_QWORD *)(v2 + 1704), "ERR:%s: PCIe link is down for RC%d\n", "msm_pcie_handle_linkdown", v11);
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe link is down for RC%d\n",
        "msm_pcie_handle_linkdown",
        *(_DWORD *)(v2 + 1348));
    }
    printk(&unk_2325F);
    if ( *(_BYTE *)(v2 + 1328) == 1 )
      panic("User has chosen to panic on linkdown\n");
    return msm_pcie_notify_client(v2, 1);
  }
  return result;
}
