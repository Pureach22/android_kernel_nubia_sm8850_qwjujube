void hif_pci_close()
{
  ((void (*)(void))hif_rtpm_close)();
  hif_ce_close();
}
