const char *__fastcall mlme_get_roam_fail_reason_str(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x29 )
    return "UNKNOWN";
  else
    return off_AEF940[a1 - 1];
}
