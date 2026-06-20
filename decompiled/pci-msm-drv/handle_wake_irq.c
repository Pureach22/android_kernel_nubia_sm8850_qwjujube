__int64 __fastcall handle_wake_irq(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x3
  int v5; // w0

  v3 = raw_spin_lock_irqsave(a2 + 1472);
  v4 = *(_QWORD *)(a2 + 1576) + 1LL;
  *(_QWORD *)(a2 + 1576) = v4;
  if ( a2 )
  {
    ipc_log_string(
      *(_QWORD *)(a2 + 1704),
      "DBG1:%s: PCIe: No. %ld wake IRQ for RC%d\n",
      "handle_wake_irq",
      v4,
      *(_DWORD *)(a2 + 1348));
    ipc_log_string(
      *(_QWORD *)(a2 + 1696),
      "%s: PCIe: No. %ld wake IRQ for RC%d\n",
      "handle_wake_irq",
      *(_QWORD *)(a2 + 1576),
      *(_DWORD *)(a2 + 1348));
    ipc_log_string(
      *(_QWORD *)(a2 + 1696),
      "DBG2:%s: PCIe WAKE is asserted by Endpoint of RC%d\n",
      "handle_wake_irq",
      *(_DWORD *)(a2 + 1348));
  }
  if ( (*(_BYTE *)(a2 + 1357) & 1) != 0 || (*(_BYTE *)(a2 + 1332) & 2) != 0 )
  {
    if ( a2 )
      ipc_log_string(*(_QWORD *)(a2 + 1696), "DBG2:%s: Wake up RC%d\n", "handle_wake_irq", *(_DWORD *)(a2 + 1348));
    _pm_stay_awake(*(_QWORD *)(a2 + 1200));
    _pm_relax(*(_QWORD *)(a2 + 1200));
    if ( *(_BYTE *)(a2 + 1992) == 1 && (*(_BYTE *)(a2 + 1568) & 1) == 0 && *(_DWORD *)(a2 + 1176) == 1 )
    {
      pcie_phy_dump(a2);
      pcie_parf_dump(a2);
      pcie_dm_core_dump(a2);
      pcie_sm_dump(a2);
      if ( *(_QWORD *)(a2 + 3128) )
      {
        v5 = crm_dump_regs("pcie_crm");
        if ( a2 )
        {
          if ( v5 )
            ipc_log_string(
              *(_QWORD *)(a2 + 1712),
              "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n",
              "pcie_crm_dump",
              *(_DWORD *)(a2 + 1348),
              v5);
        }
      }
    }
    msm_pcie_notify_client(a2, 4);
  }
  else
  {
    if ( a2 )
    {
      ipc_log_string(
        *(_QWORD *)(a2 + 1704),
        "DBG1:%s: Start enumerating RC%d\n",
        "handle_wake_irq",
        *(_DWORD *)(a2 + 1348));
      ipc_log_string(*(_QWORD *)(a2 + 1696), "%s: Start enumerating RC%d\n", "handle_wake_irq", *(_DWORD *)(a2 + 1348));
    }
    queue_work_on(32, system_wq, a2 + 1360);
  }
  raw_spin_unlock_irqrestore(a2 + 1472, v3);
  return 1;
}
