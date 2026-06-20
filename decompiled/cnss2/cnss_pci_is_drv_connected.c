__int64 __fastcall cnss_pci_is_drv_connected(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
    return *(unsigned __int8 *)(v1 + 232);
  else
    return 4294967277LL;
}
