__int64 __fastcall cnss_pci_disable_pc(__int64 a1, char a2)
{
  __int64 v2; // x9
  __int64 v3; // x0

  v2 = *(_QWORD *)(*(_QWORD *)a1 + 16LL);
  if ( (a2 & 1) != 0 )
    v3 = 8;
  else
    v3 = 16;
  return msm_pcie_pm_control(v3, *(unsigned __int8 *)(v2 + 248));
}
