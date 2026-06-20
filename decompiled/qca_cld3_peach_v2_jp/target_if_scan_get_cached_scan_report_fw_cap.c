__int64 __fastcall target_if_scan_get_cached_scan_report_fw_cap(__int64 a1)
{
  __int64 *v1; // x8

  if ( !a1 )
    return a1 & 1;
  v1 = *(__int64 **)(a1 + 1232);
  if ( v1 )
  {
    a1 = *v1;
    if ( *v1 )
      LOBYTE(a1) = wmi_service_enabled(a1, 323);
    return a1 & 1;
  }
  return 0;
}
