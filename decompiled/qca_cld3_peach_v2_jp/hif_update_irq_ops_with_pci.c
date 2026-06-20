__int64 __fastcall hif_update_irq_ops_with_pci(_QWORD *a1)
{
  a1[34] = hif_pci_configure_grp_irq;
  a1[35] = hif_pci_deconfigure_grp_irq;
  a1[32] = hif_pci_irq_disable;
  a1[33] = hif_pci_irq_enable;
  a1[21] = hif_pci_disable_isr;
  a1[22] = hif_pci_nointrs;
  return 0;
}
