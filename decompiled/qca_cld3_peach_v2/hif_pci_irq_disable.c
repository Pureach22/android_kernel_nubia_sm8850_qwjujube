__int64 __fastcall hif_pci_irq_disable(__int64 a1)
{
  return hif_target_sleep_state_adjust(a1);
}
