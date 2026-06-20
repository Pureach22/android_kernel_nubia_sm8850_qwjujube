__int64 __fastcall msm_pcie_fixup_suspend(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v3; // x0
  int v4; // w8
  __int64 v5; // x1
  int v6; // w0
  int v7; // w19

  v1 = result;
  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 16) + 232LL) + 200LL);
  if ( v2 )
  {
    ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d\n", "msm_pcie_fixup_suspend", *(_DWORD *)(v2 + 1348));
    result = ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d\n", "msm_pcie_fixup_suspend", *(_DWORD *)(v2 + 1348));
  }
  if ( *(_DWORD *)(v2 + 1176) == 1 && !*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL) )
  {
    v3 = raw_spin_lock_irqsave(v2 + 1060);
    v4 = *(unsigned __int8 *)(v2 + 1181);
    v5 = v3;
    *(_QWORD *)(v2 + 1064) = v3;
    if ( v4 == 1 )
    {
      if ( v2 )
      {
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "DBG1:%s: RC%d: Skip suspend because of user request\n",
          "msm_pcie_fixup_suspend",
          *(_DWORD *)(v2 + 1348));
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: RC%d: Skip suspend because of user request\n",
          "msm_pcie_fixup_suspend",
          *(_DWORD *)(v2 + 1348));
        v5 = *(_QWORD *)(v2 + 1064);
      }
      return raw_spin_unlock_irqrestore(v2 + 1060, v5);
    }
    else
    {
      raw_spin_unlock_irqrestore(v2 + 1060, v3);
      mutex_lock(v2 + 1424);
      v6 = msm_pcie_pm_suspend(v1);
      if ( v6 )
      {
        v7 = v6;
        if ( v2 )
        {
          ipc_log_string(
            *(_QWORD *)(v2 + 1704),
            "ERR:%s: PCIe: RC%d got failure in suspend:%d.\n",
            "msm_pcie_fixup_suspend",
            *(_DWORD *)(v2 + 1348),
            v6);
          ipc_log_string(
            *(_QWORD *)(v2 + 1696),
            "%s: PCIe: RC%d got failure in suspend:%d.\n",
            "msm_pcie_fixup_suspend",
            *(_DWORD *)(v2 + 1348),
            v7);
        }
        printk(&unk_3099C);
      }
      return mutex_unlock(v2 + 1424);
    }
  }
  return result;
}
