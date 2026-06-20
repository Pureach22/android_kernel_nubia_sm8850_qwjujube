__int64 __fastcall cnss_auto_suspend(__int64 a1)
{
  __int64 v1; // x19
  _DWORD *v2; // x20
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  unsigned int v9; // w0
  unsigned int v10; // w20

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967277LL;
  v2 = *(_DWORD **)(v1 + 8);
  if ( !v2 )
    return 4294967277LL;
  mutex_lock(v1 + 600);
  if ( *(_DWORD *)(v1 + 236) || (v9 = cnss_pci_suspend_bus((_QWORD *)v1)) == 0 )
  {
    *(_DWORD *)(v1 + 224) = 1;
    mutex_unlock(v1 + 600);
    *(_BYTE *)(v1 + 260) = 1;
    cnss_setup_bus_bandwidth(v2, 0, 0, v3, v4, v5, v6, v7);
    return 0;
  }
  else
  {
    v10 = v9;
    mutex_unlock(v1 + 600);
    return v10;
  }
}
