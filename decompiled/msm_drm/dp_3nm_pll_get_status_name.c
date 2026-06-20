const char *__fastcall dp_3nm_pll_get_status_name(unsigned int a1)
{
  if ( a1 > 4 )
    return "unknown";
  else
    return off_284E48[a1];
}
