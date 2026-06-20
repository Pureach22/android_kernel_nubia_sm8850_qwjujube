const char *__fastcall pld_bus_width_type_to_str(unsigned int a1)
{
  if ( a1 > 9 )
    return "SUPER_HIGH";
  else
    return off_B08E18[a1];
}
