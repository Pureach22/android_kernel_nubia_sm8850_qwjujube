bool __fastcall hif_pci_needs_bmi(__int64 a1)
{
  return (ce_srng_based(a1) & 1) == 0;
}
