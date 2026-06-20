__int64 __fastcall msm_pcie_genpd_gdsc_enable(const char ***a1, __int64 a2)
{
  __int64 v3; // x20
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned int v6; // w21

  if ( !a2 )
    return 0;
  v3 = *(_QWORD *)(a2 + 592);
  v4 = _pm_runtime_resume(a2, 4);
  if ( (v4 & 0x80000000) != 0 )
  {
    v6 = v4;
    if ( a1 )
    {
      ipc_log_string(
        a1[213],
        "ERR:%s: PCIe: failed to enable %s for RC%d (%s)\n",
        "msm_pcie_genpd_gdsc_enable",
        *(const char **)(v3 + 376),
        *((_DWORD *)a1 + 337),
        **a1);
      ipc_log_string(
        a1[212],
        "%s: PCIe: failed to enable %s for RC%d (%s)\n",
        "msm_pcie_genpd_gdsc_enable",
        *(const char **)(v3 + 376),
        *((_DWORD *)a1 + 337),
        **a1);
    }
    printk(&unk_21F5C);
    return v6;
  }
  else
  {
    result = 0;
    *(_DWORD *)(v3 + 520) |= 4u;
  }
  return result;
}
