const char *__fastcall dp_5nm_pll_get_status_name(unsigned int a1)
{
  if ( a1 > 4 )
    return "unknown";
  else
    return off_2845A8[a1];
}
