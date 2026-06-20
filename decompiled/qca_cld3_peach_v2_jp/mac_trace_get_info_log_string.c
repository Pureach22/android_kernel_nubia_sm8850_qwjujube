const char *__fastcall mac_trace_get_info_log_string(__int16 a1)
{
  const char *v1; // x8

  v1 = "UNKNOWN";
  if ( a1 == 1 )
    v1 = "eLOG_PROC_DEAUTH_FRAME_SCENARIO";
  if ( a1 )
    return v1;
  else
    return "eLOG_NODROP_MISSED_BEACON_SCENARIO";
}
