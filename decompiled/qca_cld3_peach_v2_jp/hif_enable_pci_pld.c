__int64 __fastcall hif_enable_pci_pld(__int64 a1)
{
  *(_BYTE *)(a1 + 31088) = 1;
  return 0;
}
