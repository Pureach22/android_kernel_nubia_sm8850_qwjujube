const char *__fastcall ipa_hw_error_str(unsigned int a1)
{
  if ( a1 > 8 )
    return "INVALID ipa_hw_errors type";
  else
    return off_1B6D28[a1];
}
