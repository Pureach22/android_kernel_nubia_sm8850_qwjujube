const char *__fastcall mlme_get_roam_trigger_str(unsigned int a1)
{
  if ( a1 > 0x13 )
    return "UNKNOWN";
  else
    return off_AEF8A0[a1];
}
