__int64 __fastcall cnss_pci_disable_bus(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *a1;
  pci_clear_master(*a1);
  pci_load_and_free_saved_state(v1, a1 + 7);
  pci_load_and_free_saved_state(v1, a1 + 8);
  if ( a1[40] )
  {
    pci_iounmap(v1);
    a1[40] = 0;
  }
  result = pci_release_region(v1, 0);
  if ( *(int *)(v1 + 2856) >= 1 )
    return pci_disable_device(v1);
  return result;
}
