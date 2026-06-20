__int64 __fastcall hif_ce_msi_map_ce_to_irq(__int64 a1, unsigned int a2)
{
  if ( a2 < 0xC )
    return *(unsigned int *)(a1 + 4LL * a2 + 30848);
  __break(0x5512u);
  return hif_enable_pci_pld();
}
