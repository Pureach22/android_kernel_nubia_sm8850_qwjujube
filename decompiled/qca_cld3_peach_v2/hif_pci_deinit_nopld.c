__int64 __fastcall hif_pci_deinit_nopld(__int64 a1)
{
  pci_disable_msi(*(_QWORD *)(a1 + 30768));
  pci_iounmap(*(_QWORD *)(a1 + 30768), *(_QWORD *)(a1 + 30720));
  pci_clear_master(*(_QWORD *)(a1 + 30768));
  pci_release_region(*(_QWORD *)(a1 + 30768), 0);
  return pci_disable_device(*(_QWORD *)(a1 + 30768));
}
