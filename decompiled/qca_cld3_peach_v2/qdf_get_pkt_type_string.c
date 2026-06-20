const char *__fastcall qdf_get_pkt_type_string(unsigned __int8 a1, char a2)
{
  unsigned __int8 v2; // w8

  v2 = a2 - 1;
  if ( (unsigned __int8)(a2 - 1) < 0x3Cu && ((0xFFFFFFC00003FFFuLL >> v2) & 1) != 0 )
    return off_AD0030[v2];
  if ( a1 >= 8u )
    return "UNKNOWN";
  return off_AD0210[a1];
}
