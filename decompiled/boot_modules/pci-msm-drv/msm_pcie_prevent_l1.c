__int64 __fastcall msm_pcie_prevent_l1(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v4; // x19
  int v6; // w7
  int v7; // w8
  int v8; // w21
  unsigned int v9; // w20

  if ( !a1 )
    return 4294967277LL;
  v1 = a1;
  while ( !*(_BYTE *)(v1 + 108) || (*(_WORD *)(v1 + 114) & 0xF0) != 0x40 )
  {
    if ( (*(_BYTE *)(v1 + 2851) & 0x80) != 0 )
      v1 = *(_QWORD *)(v1 + 3288);
    v2 = *(_QWORD *)(v1 + 16);
    if ( *(_QWORD *)(v2 + 16) )
    {
      v1 = *(_QWORD *)(v2 + 56);
      if ( v1 )
        continue;
    }
    return 4294967277LL;
  }
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 232LL) + 200LL);
  if ( !v4 )
    return 0;
  mutex_lock(v4 + 1120);
  mutex_lock(v4 + 1480);
  if ( *(_BYTE *)(v4 + 1216) == 1 )
  {
    ipc_log_string(
      *(_QWORD *)(v4 + 1696),
      "DBG2:%s: PCIe: RC%d: debugfs_l1 is set so no-op\n",
      "msm_pcie_prevent_l1",
      *(_DWORD *)(v4 + 1348));
  }
  else if ( (*(_BYTE *)(v4 + 1218) & 1) != 0 )
  {
    v6 = *(_DWORD *)(v4 + 1176);
    if ( v6 != 1 )
    {
      ipc_log_string(
        *(_QWORD *)(v4 + 1696),
        "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: lnk_sts %d\n",
        "msm_pcie_prevent_l1",
        *(_DWORD *)(v4 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7,
        v6);
      v9 = -22;
      goto LABEL_28;
    }
    v7 = *(_DWORD *)(v4 + 1528);
    *(_DWORD *)(v4 + 1528) = v7 + 1;
    if ( !v7 )
    {
      msm_pcie_write_mask((unsigned int *)(*(_QWORD *)(v4 + 872) + 32LL), 0, 0x20u);
      if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(v4 + 872) + 432LL)) & 0x3F) != 0x11 )
      {
        v8 = 1001;
        while ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(v4 + 872) + 432LL)) & 0x3F) != 0x12 )
        {
          if ( *(_DWORD *)(v4 + 1176) == 4 )
            goto LABEL_31;
          if ( !--v8 )
          {
            ipc_log_string(
              *(_QWORD *)(v4 + 1704),
              "ERR:%s: PCIe: RC%d: %02x:%02x.%01x: failed to transition to L0\n",
              "msm_pcie_prevent_l1",
              *(_DWORD *)(v4 + 1348),
              *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
              (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
              *(_DWORD *)(a1 + 56) & 7);
            ipc_log_string(
              *(_QWORD *)(v4 + 1696),
              "%s: PCIe: RC%d: %02x:%02x.%01x: failed to transition to L0\n",
              "msm_pcie_prevent_l1",
              *(_DWORD *)(v4 + 1348),
              *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
              (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
              *(_DWORD *)(a1 + 56) & 7);
            printk(&unk_26DD1);
            ipc_log_string(
              *(_QWORD *)(v4 + 1704),
              "ERR:%s: PCIe: RC%d: dump PCIe registers\n",
              "msm_pcie_prevent_l1",
              *(_DWORD *)(v4 + 1348));
            ipc_log_string(
              *(_QWORD *)(v4 + 1696),
              "%s: PCIe: RC%d: dump PCIe registers\n",
              "msm_pcie_prevent_l1",
              *(_DWORD *)(v4 + 1348));
            printk(&unk_2EE0C);
            msm_pcie_clk_dump(v4);
            pcie_parf_dump(v4);
            pcie_dm_core_dump(v4);
            pcie_phy_dump(v4);
            pcie_sm_dump(v4);
            pcie_crm_dump(v4);
LABEL_31:
            mutex_unlock(v4 + 1480);
            mutex_unlock(v4 + 1120);
            msm_pcie_allow_l1(a1);
            return 4294967291LL;
          }
          usleep_range_state(100, 105, 2);
          if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(v4 + 872) + 432LL)) & 0x3F) == 0x11 )
            break;
        }
      }
      msm_pcie_config_l1_disable_all(v4, *(_QWORD *)(*(_QWORD *)(v4 + 8) + 16LL));
      ipc_log_string(
        *(_QWORD *)(v4 + 1696),
        "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: exit\n",
        "msm_pcie_prevent_l1",
        *(unsigned int *)(v4 + 1348),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
        *(_DWORD *)(a1 + 56) & 7);
    }
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(v4 + 1696),
      "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: L1 not supported\n",
      "msm_pcie_prevent_l1",
      *(unsigned int *)(v4 + 1348),
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
      (unsigned __int8)*(_DWORD *)(a1 + 56) >> 3,
      *(_DWORD *)(a1 + 56) & 7);
  }
  v9 = 0;
LABEL_28:
  mutex_unlock(v4 + 1480);
  mutex_unlock(v4 + 1120);
  return v9;
}
