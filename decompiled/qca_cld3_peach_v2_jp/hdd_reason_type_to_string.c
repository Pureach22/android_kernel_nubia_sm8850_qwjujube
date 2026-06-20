const char *__fastcall hdd_reason_type_to_string(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0xB )
    return "Invalid";
  else
    return off_A09158[a1 - 1];
}
