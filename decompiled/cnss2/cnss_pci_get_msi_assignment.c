__int64 __fastcall cnss_pci_get_msi_assignment(__int64 a1)
{
  *(_QWORD *)(a1 + 328) = &msi_config;
  return 0;
}
