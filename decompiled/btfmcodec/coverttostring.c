const char *__fastcall coverttostring(unsigned int a1)
{
  if ( a1 > 4 )
    return "INVALID_STATE";
  else
    return off_E0E0[a1];
}
