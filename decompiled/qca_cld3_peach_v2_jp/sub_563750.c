__int64 sub_563750()
{
  __asm { STGP            X10, X14, [X9,#0x6C]! }
  return hif_pci_get_irq_name();
}
