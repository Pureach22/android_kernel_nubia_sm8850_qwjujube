__int64 __fastcall cnss_pci_is_device_awake(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v2; // w9
  bool v3; // cc
  int v4; // w9
  __int64 v6; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967277LL;
  v2 = *(_DWORD *)(v1 + 24) - 4353;
  v3 = v2 > 0x11;
  v4 = (1 << v2) & 0x32245;
  if ( v3 || v4 == 0 )
    return 0;
  v6 = *(_QWORD *)(v1 + 344);
  if ( v6 )
    return *(_DWORD *)(v6 + 348) == 2;
  else
    return 4294967274LL;
}
