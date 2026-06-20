const char *__fastcall qdf_dp_subtype_to_str(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x3B )
    return "invalid";
  else
    return (&off_AD0250)[a1 - 1];
}
