__int64 __fastcall cnss_dereg_pci_event(__int64 a1)
{
  return msm_pcie_deregister_event(a1 + 72);
}
