__int64 __fastcall msm_pcie_gdsc_vreg_get(__int64 a1, const char *a2, unsigned __int64 *a3)
{
  const char **v3; // x23
  unsigned __int64 v7; // x0

  v3 = *(const char ***)a1;
  v7 = devm_regulator_get(*(_QWORD *)a1 + 16LL);
  *a3 = v7;
  if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
    return 0;
  if ( a1 )
  {
    ipc_log_string(
      *(_QWORD *)(a1 + 1704),
      "ERR:%s: PCIe: RC%d: Failed to get %s %s:%ld\n",
      "msm_pcie_gdsc_vreg_get",
      *(_DWORD *)(a1 + 1348),
      *v3,
      a2,
      v7);
    ipc_log_string(
      *(_QWORD *)(a1 + 1696),
      "%s: PCIe: RC%d: Failed to get %s %s:%ld\n",
      "msm_pcie_gdsc_vreg_get",
      *(_DWORD *)(a1 + 1348),
      *v3,
      a2,
      *a3);
  }
  printk(&unk_2BE37);
  if ( *a3 == -517 )
  {
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 1704),
        "DBG1:%s: PCIe: EPROBE_DEFER for %s %s\n",
        "msm_pcie_gdsc_vreg_get",
        *v3,
        a2);
      ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: PCIe: EPROBE_DEFER for %s %s\n", "msm_pcie_gdsc_vreg_get", *v3, a2);
      return *(unsigned int *)a3;
    }
    else
    {
      return 4294966779LL;
    }
  }
  else
  {
    *a3 = 0;
    return 0;
  }
}
