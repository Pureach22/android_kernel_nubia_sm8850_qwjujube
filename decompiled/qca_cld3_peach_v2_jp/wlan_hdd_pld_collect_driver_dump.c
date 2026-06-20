__int64 __fastcall wlan_hdd_pld_collect_driver_dump(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int regions; // w0

  regions = qdf_ssr_driver_dump_retrieve_regions(a3, a4);
  return qdf_status_to_os_return(regions);
}
