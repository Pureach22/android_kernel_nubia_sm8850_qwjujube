const char *__fastcall util_scan_get_ev_reason_name(unsigned int a1)
{
  if ( a1 <= 0xA )
    return util_scan_get_ev_reason_name_reason_name[a1];
  else
    return "UNKNOWN";
}
