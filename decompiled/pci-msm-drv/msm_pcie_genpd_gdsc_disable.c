__int64 __fastcall msm_pcie_genpd_gdsc_disable(const char ***a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned int v4; // w0
  unsigned int v6; // w20

  if ( !a2 )
    return 0;
  v2 = *(_QWORD *)(a2 + 592);
  *(_DWORD *)(v2 + 520) &= ~4u;
  v4 = _pm_runtime_idle(a2, 4);
  if ( (v4 & 0x80000000) == 0 )
    return 0;
  v6 = v4;
  if ( a1 )
  {
    ipc_log_string(
      a1[213],
      "ERR:%s: PCIe: failed to disable %s for RC%d (%s)\n",
      "msm_pcie_genpd_gdsc_disable",
      *(const char **)(v2 + 376),
      *((_DWORD *)a1 + 337),
      **a1);
    ipc_log_string(
      a1[212],
      "%s: PCIe: failed to disable %s for RC%d (%s)\n",
      "msm_pcie_genpd_gdsc_disable",
      *(const char **)(v2 + 376),
      *((_DWORD *)a1 + 337),
      **a1);
  }
  printk(&unk_28037);
  return v6;
}
