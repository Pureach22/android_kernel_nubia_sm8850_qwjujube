const char *__fastcall ipa3_get_mode_type_str(unsigned int a1)
{
  if ( a1 > 3 )
    return "undefined";
  else
    return off_1E4150[a1];
}
