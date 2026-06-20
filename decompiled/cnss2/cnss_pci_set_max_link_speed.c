__int64 __fastcall cnss_pci_set_max_link_speed(__int64 a1, unsigned int a2, unsigned __int16 a3)
{
  return msm_pcie_set_target_link_speed(a2, a3, 0);
}
