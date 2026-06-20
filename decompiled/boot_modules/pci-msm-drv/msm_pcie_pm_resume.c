__int64 __fastcall msm_pcie_pm_resume(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  unsigned int v4; // w21

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 232LL) + 200LL);
  if ( v2 )
  {
    ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_pm_resume", *(_DWORD *)(v2 + 1348));
    ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d: entry\n", "msm_pcie_pm_resume", *(_DWORD *)(v2 + 1348));
  }
  if ( *(_BYTE *)(v2 + 1720) == 1 && *(_QWORD *)(v2 + 1736) )
    pinctrl_select_state(*(_QWORD *)(v2 + 1728));
  v3 = raw_spin_lock_irqsave(v2 + 1060);
  *(_QWORD *)(v2 + 1064) = v3;
  *(_BYTE *)(v2 + 1056) = 1;
  raw_spin_unlock_irqrestore(v2 + 1060, v3);
  v4 = msm_pcie_enable((const char ***)v2);
  if ( v4 )
  {
    if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "ERR:%s: PCIe: RC%d fail to enable PCIe link in resume.\n",
        "msm_pcie_pm_resume",
        *(_DWORD *)(v2 + 1348));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: PCIe: RC%d fail to enable PCIe link in resume.\n",
        "msm_pcie_pm_resume",
        *(_DWORD *)(v2 + 1348));
    }
    printk(&unk_27526);
  }
  else
  {
    *(_BYTE *)(v2 + 1568) = 0;
    if ( v2 )
    {
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "DBG1:%s: dev->bus->number = %d dev->bus->primary = %d\n",
        "msm_pcie_pm_resume",
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 249LL));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: dev->bus->number = %d dev->bus->primary = %d\n",
        "msm_pcie_pm_resume",
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 248LL),
        *(unsigned __int8 *)(*(_QWORD *)(a1 + 16) + 249LL));
      ipc_log_string(
        *(_QWORD *)(v2 + 1704),
        "DBG1:%s: RC%d: restore config space\n",
        "msm_pcie_pm_resume",
        *(_DWORD *)(v2 + 1348));
      ipc_log_string(
        *(_QWORD *)(v2 + 1696),
        "%s: RC%d: restore config space\n",
        "msm_pcie_pm_resume",
        *(_DWORD *)(v2 + 1348));
      pci_set_power_state(a1, 0);
      pci_load_and_free_saved_state(a1, v2 + 1192);
      pci_restore_state(a1);
      ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_pm_resume", *(_DWORD *)(v2 + 1348));
      ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d: exit\n", "msm_pcie_pm_resume", *(_DWORD *)(v2 + 1348));
    }
    else
    {
      pci_set_power_state(a1, 0);
      pci_load_and_free_saved_state(a1, 1192);
      pci_restore_state(a1);
    }
  }
  return v4;
}
