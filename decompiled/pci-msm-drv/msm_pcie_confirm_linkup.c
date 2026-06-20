__int64 __fastcall msm_pcie_confirm_linkup(__int64 a1, char a2, char a3, __int64 a4)
{
  if ( (a2 & 1) != 0 && *(_DWORD *)(a1 + 1176) != 1 )
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "DBG1:%s: PCIe: The link of RC %d is not enabled.\n",
        "msm_pcie_confirm_linkup",
        *(_DWORD *)(a1 + 1348));
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: The link of RC %d is not enabled.\n",
        "msm_pcie_confirm_linkup",
        *(unsigned int *)(a1 + 1348));
    }
  }
  else if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 904) + 128LL)) & 0x20000000) != 0 )
  {
    if ( (a3 & 1) == 0 || (pci_device_is_present(a4) & 1) != 0 )
      return 1;
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "ERR:%s: PCIe: RC%d: Config space access failed for BDF 0x%04x\n",
        "msm_pcie_confirm_linkup",
        *(_DWORD *)(a1 + 1348),
        *(_DWORD *)(a4 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a4 + 16) + 248LL) << 8));
      ipc_log_string(
        *(_QWORD *)(a1 + 1696),
        "%s: PCIe: RC%d: Config space access failed for BDF 0x%04x\n",
        "msm_pcie_confirm_linkup",
        *(_DWORD *)(a1 + 1348),
        *(_DWORD *)(a4 + 56) | (*(unsigned __int8 *)(*(_QWORD *)(a4 + 16) + 248LL) << 8));
    }
    printk(&unk_293D2);
  }
  else if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "DBG1:%s: PCIe: The link of RC %d is not up.\n",
      "msm_pcie_confirm_linkup",
      *(_DWORD *)(a1 + 1348));
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: The link of RC %d is not up.\n",
      "msm_pcie_confirm_linkup",
      *(unsigned int *)(a1 + 1348));
  }
  return 0;
}
