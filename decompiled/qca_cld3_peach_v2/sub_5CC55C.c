__int64 sub_5CC55C()
{
  __asm { STGP            X10, X14, [X9,#0x6C]! }
  return hif_pci_get_irq_name();
}
