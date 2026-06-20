const char *__fastcall dp_pll_get_revision(unsigned int a1)
{
  if ( a1 > 7 )
    return "???";
  else
    return off_2841F0[a1];
}
