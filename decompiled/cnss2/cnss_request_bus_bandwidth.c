__int64 __fastcall cnss_request_bus_bandwidth(__int64 a1, __int64 a2)
{
  int v2; // w19

  v2 = a2;
  if ( !cnss_bus_dev_to_plat_priv(a1, a2) )
    return 4294967277LL;
  if ( v2 < 0 )
    return 4294967274LL;
  return cnss_setup_bus_bandwidth();
}
