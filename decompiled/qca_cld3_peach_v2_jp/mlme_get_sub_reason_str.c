const char *__fastcall mlme_get_sub_reason_str(int a1)
{
  if ( (unsigned int)(a1 - 1) > 9 )
    return "NONE";
  else
    return off_9FDB20[a1 - 1];
}
