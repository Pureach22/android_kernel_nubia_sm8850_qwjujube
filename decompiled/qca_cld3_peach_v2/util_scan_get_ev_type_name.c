const char *__fastcall util_scan_get_ev_type_name(unsigned int a1)
{
  if ( a1 <= 0x12 )
    return util_scan_get_ev_type_name_event_name[a1];
  else
    return "UNKNOWN";
}
