__int64 __fastcall cnss_pci_force_wake_request_sync(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned int v3; // w9
  bool v4; // cc
  int v5; // w9
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x0

  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
    return 4294967277LL;
  v3 = *(_DWORD *)(v2 + 24) - 4353;
  v4 = v3 > 0x11;
  v5 = (1 << v3) & 0x32245;
  if ( v4 || v5 == 0 )
    return 0;
  v7 = *(_QWORD *)(v2 + 344);
  if ( !v7 )
    return 4294967274LL;
  v8 = *(_QWORD *)(v2 + 8);
  if ( !v8 )
    return 4294967277LL;
  if ( (*(_QWORD *)(v8 + 552) & 0x800) != 0 )
    return 4294967285LL;
  v9 = *(_QWORD *)(v7 + 16);
  if ( (_DWORD)a2 )
    return mhi_device_get_sync_atomic(v9, a2, 0);
  else
    return mhi_device_get_sync(v9);
}
