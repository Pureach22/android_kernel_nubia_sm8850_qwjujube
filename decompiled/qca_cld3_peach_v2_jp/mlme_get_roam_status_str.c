const char *__fastcall mlme_get_roam_status_str(unsigned int a1)
{
  if ( a1 > 2 )
    return "UNKNOWN";
  else
    return off_9FD918[a1];
}
