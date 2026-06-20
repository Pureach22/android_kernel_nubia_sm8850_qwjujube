const char *__fastcall icnss_get_wlan_str(unsigned int a1)
{
  if ( a1 > 0x71 )
    return "unknown";
  else
    return off_A84A0[a1];
}
