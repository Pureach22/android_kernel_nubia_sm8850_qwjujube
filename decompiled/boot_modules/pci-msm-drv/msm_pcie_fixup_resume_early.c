__int64 __fastcall msm_pcie_fixup_resume_early(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  int v3; // w0
  int v4; // w19

  v1 = result;
  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 16) + 232LL) + 200LL);
  if ( v2 )
  {
    ipc_log_string(*(_QWORD *)(v2 + 1704), "DBG1:%s: RC%d\n", "msm_pcie_fixup_resume_early", *(_DWORD *)(v2 + 1348));
    result = ipc_log_string(*(_QWORD *)(v2 + 1696), "%s: RC%d\n", "msm_pcie_fixup_resume_early", *(_DWORD *)(v2 + 1348));
  }
  if ( *(_DWORD *)(v2 + 1176) == 2 && (*(_BYTE *)(v2 + 1180) & 1) == 0 && !*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL) )
  {
    mutex_lock(v2 + 1424);
    v3 = msm_pcie_pm_resume(v1);
    if ( v3 )
    {
      v4 = v3;
      if ( v2 )
      {
        ipc_log_string(
          *(_QWORD *)(v2 + 1704),
          "ERR:%s: PCIe: RC%d got failure in resume:%d.\n",
          "msm_pcie_fixup_resume_early",
          *(_DWORD *)(v2 + 1348),
          v3);
        ipc_log_string(
          *(_QWORD *)(v2 + 1696),
          "%s: PCIe: RC%d got failure in resume:%d.\n",
          "msm_pcie_fixup_resume_early",
          *(_DWORD *)(v2 + 1348),
          v4);
      }
      printk(&unk_2E522);
    }
    return mutex_unlock(v2 + 1424);
  }
  return result;
}
