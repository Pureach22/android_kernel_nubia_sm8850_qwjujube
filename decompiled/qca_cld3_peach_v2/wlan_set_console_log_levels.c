__int64 __fastcall wlan_set_console_log_levels(__int64 result)
{
  LODWORD(gwlan_logging) = result;
  return result;
}
