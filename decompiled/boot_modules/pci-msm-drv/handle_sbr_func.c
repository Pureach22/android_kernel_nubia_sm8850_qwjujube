__int64 __fastcall handle_sbr_func(__int64 a1)
{
  __int64 v2; // x23
  __int64 *v3; // x21
  _QWORD *v4; // x22
  __int64 v5; // x0
  __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x20
  int v9; // w0
  __int64 v10; // x20
  int v11; // w0
  unsigned int v12; // w20
  __int64 v13; // x22
  unsigned int v14; // w28
  unsigned int v15; // w8
  __int64 v16; // x0
  int v17; // w3
  const char *v18; // x26
  void *v19; // x20
  const char *v20; // x21

  v2 = a1 - 1392;
  if ( a1 != 1392 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 312), "DBG1:%s: PCIe: SBR work for RC%d\n", "handle_sbr_func", *(_DWORD *)(a1 - 44));
    ipc_log_string(*(_QWORD *)(a1 + 304), "%s: PCIe: SBR work for RC%d\n", "handle_sbr_func", *(_DWORD *)(a1 - 44));
  }
  v3 = (__int64 *)(a1 - 600);
  if ( *(_QWORD *)(a1 - 600) )
  {
    if ( (unsigned int)reset_control_assert() )
    {
      if ( v2 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 312),
          "ERR:%s: PCIe: RC%d failed to assert reset for %s.\n",
          "handle_sbr_func",
          *(_DWORD *)(a1 - 44),
          *(const char **)(a1 - 592));
        ipc_log_string(
          *(_QWORD *)(a1 + 304),
          "%s: PCIe: RC%d failed to assert reset for %s.\n",
          "handle_sbr_func",
          *(_DWORD *)(a1 - 44),
          *(const char **)(a1 - 592));
      }
      printk(&unk_24429);
    }
    else if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 304),
        "DBG2:%s: PCIe: RC%d successfully asserted reset for %s.\n",
        "handle_sbr_func",
        *(_DWORD *)(a1 - 44),
        *(const char **)(a1 - 592));
    }
  }
  v4 = (_QWORD *)(a1 - 576);
  if ( *(_QWORD *)(a1 - 576) )
  {
    if ( (unsigned int)reset_control_assert() )
    {
      if ( v2 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 312),
          "ERR:%s: PCIe: RC%d failed to assert reset for %s.\n",
          "handle_sbr_func",
          *(_DWORD *)(a1 - 44),
          *(const char **)(a1 - 568));
        ipc_log_string(
          *(_QWORD *)(a1 + 304),
          "%s: PCIe: RC%d failed to assert reset for %s.\n",
          "handle_sbr_func",
          *(_DWORD *)(a1 - 44),
          *(const char **)(a1 - 568));
      }
      printk(&unk_24429);
    }
    else if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 304),
        "DBG2:%s: PCIe: RC%d successfully asserted reset for %s.\n",
        "handle_sbr_func",
        *(_DWORD *)(a1 - 44),
        *(const char **)(a1 - 568));
    }
  }
  usleep_range_state(1000, 1005, 2);
  if ( !*v4 )
  {
LABEL_21:
    v5 = *v3;
    if ( !*v3 )
      goto LABEL_32;
    goto LABEL_22;
  }
  if ( !(unsigned int)reset_control_deassert(*v4) )
  {
    if ( v2 )
      ipc_log_string(
        *(_QWORD *)(a1 + 304),
        "DBG2:%s: PCIe: RC%d successfully deasserted reset for %s.\n",
        "handle_sbr_func",
        *(_DWORD *)(a1 - 44),
        *(const char **)(a1 - 568));
    goto LABEL_21;
  }
  if ( v2 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 312),
      "ERR:%s: PCIe: RC%d failed to deassert reset for %s.\n",
      "handle_sbr_func",
      *(_DWORD *)(a1 - 44),
      *(const char **)(a1 - 568));
    ipc_log_string(
      *(_QWORD *)(a1 + 304),
      "%s: PCIe: RC%d failed to deassert reset for %s.\n",
      "handle_sbr_func",
      *(_DWORD *)(a1 - 44),
      *(const char **)(a1 - 568));
  }
  printk(&unk_2C209);
  v5 = *v3;
  if ( !*v3 )
  {
LABEL_32:
    if ( v2 )
      goto LABEL_33;
    goto LABEL_34;
  }
LABEL_22:
  if ( (unsigned int)reset_control_deassert(v5) )
  {
    if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 312),
        "ERR:%s: PCIe: RC%d failed to deassert reset for %s.\n",
        "handle_sbr_func",
        *(_DWORD *)(a1 - 44),
        *(const char **)(a1 - 592));
      ipc_log_string(
        *(_QWORD *)(a1 + 304),
        "%s: PCIe: RC%d failed to deassert reset for %s.\n",
        "handle_sbr_func",
        *(_DWORD *)(a1 - 44),
        *(const char **)(a1 - 592));
    }
    printk(&unk_2C209);
    goto LABEL_32;
  }
  if ( v2 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 304),
      "DBG2:%s: PCIe: RC%d successfully deasserted reset for %s.\n",
      "handle_sbr_func",
      *(_DWORD *)(a1 - 44),
      *(const char **)(a1 - 592));
LABEL_33:
    v6 = *(_QWORD *)(a1 + 312);
    v7 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 - 520) + 432LL));
    ipc_log_string(v6, "DBG1:%s: post reset ltssm:%x\n", "handle_sbr_func", v7);
    v8 = *(_QWORD *)(a1 + 304);
    v9 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 - 520) + 432LL));
    ipc_log_string(v8, "%s: post reset ltssm:%x\n", "handle_sbr_func", v9);
  }
LABEL_34:
  v10 = *(_QWORD *)(a1 - 520);
  v11 = readl_relaxed_0((unsigned int *)(v10 + 432));
  writel_relaxed_0(v11 | 0x100, (unsigned int *)(v10 + 432));
  readl_relaxed_0((unsigned int *)(v10 + 432));
  v12 = 0;
  v13 = a1 - 488;
  while ( 1 )
  {
    v14 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 - 504) + 8LL));
    if ( v2 )
    {
      v15 = (v14 >> 12) & 0x3F;
      v16 = *(_QWORD *)(a1 + 312);
      v17 = *(_DWORD *)(a1 - 44);
      if ( v15 < 0x24 )
      {
        v18 = msm_pcie_ltssm_str[v15];
        ipc_log_string(v16, "DBG1:%s: PCIe RC%d: LTSSM_STATE: %x %s\n", "handle_sbr_func", v17, v14, v18);
      }
      else
      {
        ipc_log_string(v16, "DBG1:%s: PCIe RC%d: LTSSM_STATE: %x %s\n", "handle_sbr_func", v17, v14, "LTSSM_INVALID");
        v18 = "LTSSM_INVALID";
      }
      ipc_log_string(
        *(_QWORD *)(a1 + 304),
        "%s: PCIe RC%d: LTSSM_STATE: %x %s\n",
        "handle_sbr_func",
        *(_DWORD *)(a1 - 44),
        v14,
        v18);
    }
    usleep_range_state(10000, 11000, 2);
    if ( (v14 & 0x400) != 0 )
      break;
    if ( v12 > 9 )
    {
      v19 = &unk_2D877;
      if ( !v2 )
        return printk(v19);
      goto LABEL_56;
    }
LABEL_36:
    ++v12;
  }
  if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)v13 + 128LL)) & 0x20000000) != 0 )
    goto LABEL_48;
  if ( v2 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 312),
      "DBG1:%s: PCIe: The link of RC %d is not up.\n",
      "msm_pcie_confirm_linkup",
      *(_DWORD *)(a1 - 44));
    ipc_log_string(
      *(_QWORD *)(a1 + 304),
      "%s: PCIe: The link of RC %d is not up.\n",
      "msm_pcie_confirm_linkup",
      *(_DWORD *)(a1 - 44));
  }
  if ( v12 < 0xA )
    goto LABEL_36;
  v12 = 11;
LABEL_48:
  if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)v13 + 128LL)) & 0x20000000) == 0 )
  {
    if ( !v2 )
    {
      v19 = &unk_2D877;
      return printk(v19);
    }
    ipc_log_string(
      *(_QWORD *)(a1 + 312),
      "DBG1:%s: PCIe: The link of RC %d is not up.\n",
      "msm_pcie_confirm_linkup",
      *(_DWORD *)(a1 - 44));
    ipc_log_string(
      *(_QWORD *)(a1 + 304),
      "%s: PCIe: The link of RC %d is not up.\n",
      "msm_pcie_confirm_linkup",
      *(_DWORD *)(a1 - 44));
    v19 = &unk_2D877;
LABEL_56:
    v20 = "%s: PCIe RC%d link initialization failed\n";
    ipc_log_string(
      *(_QWORD *)(a1 + 312),
      "ERR:%s: PCIe RC%d link initialization failed\n",
      "handle_sbr_func",
      *(unsigned int *)(a1 - 44));
    goto LABEL_58;
  }
  *(_DWORD *)(a1 - 216) = 1;
  if ( !v2 )
  {
    v19 = &unk_2AEC2;
    return printk(v19);
  }
  ipc_log_string(*(_QWORD *)(a1 + 312), "DBG1:%s: Link is up after %d checkings\n", "handle_sbr_func", v12);
  ipc_log_string(*(_QWORD *)(a1 + 304), "%s: Link is up after %d checkings\n", "handle_sbr_func", v12);
  v19 = &unk_2AEC2;
  v20 = "%s: PCIe RC%d link initialized\n";
  ipc_log_string(
    *(_QWORD *)(a1 + 312),
    "INFO:%s: PCIe RC%d link initialized\n",
    "handle_sbr_func",
    *(unsigned int *)(a1 - 44));
LABEL_58:
  ipc_log_string(*(_QWORD *)(a1 + 304), v20, "handle_sbr_func", *(unsigned int *)(a1 - 44));
  return printk(v19);
}
