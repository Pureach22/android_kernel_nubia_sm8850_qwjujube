__int64 __fastcall msm_pcie_core_phy_reset(__int64 a1)
{
  __int64 v2; // x25
  unsigned int v3; // w26
  unsigned int v4; // w0
  unsigned int v5; // w8
  const char **v6; // x25
  __int64 i; // x26
  unsigned int v8; // w0
  unsigned int v9; // w27
  unsigned int v10; // w20

  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_core_phy_reset", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: entry\n", "msm_pcie_core_phy_reset", *(_DWORD *)(a1 + 1348));
  }
  v2 = 0;
  v3 = 0;
  do
  {
    if ( *(_QWORD *)(a1 + v2 + 648) )
    {
      v4 = reset_control_assert();
      if ( v4 )
      {
        v3 = v4;
        if ( a1 )
        {
          ipc_log_string(
            *(_QWORD *)(a1 + 1704),
            "ERR:%s: PCIe: RC%d failed to assert reset for %s.\n",
            "msm_pcie_core_phy_reset",
            *(_DWORD *)(a1 + 1348),
            *(const char **)(a1 + v2 + 656));
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "%s: PCIe: RC%d failed to assert reset for %s.\n",
            "msm_pcie_core_phy_reset",
            *(_DWORD *)(a1 + 1348),
            *(const char **)(a1 + v2 + 656));
        }
        printk(&unk_24429);
      }
      else
      {
        if ( a1 )
          ipc_log_string(
            *(_QWORD *)(a1 + 1696),
            "DBG2:%s: PCIe: RC%d successfully asserted reset for %s.\n",
            "msm_pcie_core_phy_reset",
            *(_DWORD *)(a1 + 1348),
            *(const char **)(a1 + v2 + 656));
        v3 = 0;
      }
    }
    v2 += 24;
  }
  while ( v2 != 120 );
  usleep_range_state(1000, 1005, 2);
  v5 = v3;
  v6 = (const char **)(a1 + 752);
  for ( i = -4; ; ++i )
  {
    if ( !*(v6 - 1) )
      goto LABEL_15;
    v8 = reset_control_deassert();
    if ( !v8 )
      break;
    v9 = v8;
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "ERR:%s: PCIe: RC%d failed to deassert reset for %s.\n",
        "msm_pcie_core_phy_reset",
        *(_DWORD *)(a1 + 1348),
        *v6);
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d failed to deassert reset for %s.\n",
        "msm_pcie_core_phy_reset",
        *(_DWORD *)(a1 + 1348),
        *v6);
    }
    printk(&unk_2C209);
    v5 = v9;
LABEL_15:
    if ( !i )
    {
      v10 = v5;
      usleep_range_state(1000, 1005, 2);
      if ( !a1 )
        return v10;
      goto LABEL_27;
    }
LABEL_16:
    v6 -= 3;
  }
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "DBG2:%s: PCIe: RC%d successfully deasserted reset for %s.\n",
      "msm_pcie_core_phy_reset",
      *(_DWORD *)(a1 + 1348),
      *v6);
    if ( !i )
    {
      usleep_range_state(1000, 1005, 2);
      v10 = 0;
LABEL_27:
      ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_core_phy_reset", *(_DWORD *)(a1 + 1348));
      ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: exit\n", "msm_pcie_core_phy_reset", *(_DWORD *)(a1 + 1348));
      return v10;
    }
    goto LABEL_23;
  }
  if ( i )
  {
LABEL_23:
    v5 = 0;
    goto LABEL_16;
  }
  usleep_range_state(1000, 1005, 2);
  return 0;
}
