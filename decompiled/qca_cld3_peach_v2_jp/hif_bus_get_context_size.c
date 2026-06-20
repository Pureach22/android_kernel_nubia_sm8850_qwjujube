__int64 __fastcall hif_bus_get_context_size(__int64 a1, __int64 a2)
{
  if ( (_DWORD)a1 )
    return 0;
  else
    return hif_pci_get_context_size(a1, a2);
}
