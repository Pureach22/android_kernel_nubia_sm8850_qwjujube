const char *__fastcall dp_4nm_pll_get_status_name(unsigned int a1)
{
  if ( a1 > 4 )
    return "unknown";
  else
    return off_284AA8[a1];
}
