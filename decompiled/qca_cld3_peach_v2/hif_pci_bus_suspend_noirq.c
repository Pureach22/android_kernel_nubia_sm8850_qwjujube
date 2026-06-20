__int64 __fastcall hif_pci_bus_suspend_noirq(__int64 a1)
{
  if ( hif_can_suspend_link(a1) )
    *(_DWORD *)(a1 + 684) = 1;
  return 0;
}
