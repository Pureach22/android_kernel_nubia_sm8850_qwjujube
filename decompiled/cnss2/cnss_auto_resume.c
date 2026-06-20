__int64 __fastcall cnss_auto_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  unsigned int v4; // w0
  unsigned int v5; // w20
  unsigned int v7; // w21
  __int64 v8; // x1
  _DWORD *v9; // x0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967277LL;
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 )
    return 4294967277LL;
  mutex_lock(v1 + 600);
  v4 = cnss_pci_resume_bus(v1);
  if ( v4 )
  {
    v5 = v4;
    mutex_unlock(v1 + 600);
    return v5;
  }
  else
  {
    *(_DWORD *)(v1 + 224) = 0;
    mutex_unlock(v1 + 600);
    v7 = *(_DWORD *)(v2 + 364);
    v9 = (_DWORD *)cnss_bus_dev_to_plat_priv(a1, v8);
    if ( v9 )
    {
      if ( (v7 & 0x80000000) == 0 )
        cnss_setup_bus_bandwidth(v9, v7, 1, v10, v11, v12, v13, v14);
    }
    *(_BYTE *)(v1 + 232) = 0;
    return 0;
  }
}
