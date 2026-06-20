__int64 __fastcall sub_413164(int a1)
{
  int v1; // w26
  __int64 v2; // x30

  *(_DWORD *)(v2 - 64) = a1;
  *(_DWORD *)(v2 - 60) = v1;
  return pld_pci_read_config_dword();
}
