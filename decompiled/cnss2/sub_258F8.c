__int64 __fastcall sub_258F8(__int64 a1)
{
  int v1; // w27

  if ( (v1 & 0x20000000) == 0 )
    JUMPOUT(0x27640);
  return cnss_pci_update_time_sync_period(a1);
}
