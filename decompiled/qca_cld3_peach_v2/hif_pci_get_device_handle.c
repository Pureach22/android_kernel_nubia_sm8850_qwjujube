__int64 __fastcall hif_pci_get_device_handle(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 30768);
  *a2 = v2;
  return 0;
}
