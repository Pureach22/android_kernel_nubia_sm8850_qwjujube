__int64 __fastcall cnss_pci_assert_perst(__int64 a1)
{
  return msm_pcie_pm_control(32, *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)a1 + 16LL) + 248LL));
}
