const char *__fastcall sap_get_csa_reason_str(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0xF )
    return "UNKNOWN";
  else
    return off_B08F70[a1 - 1];
}
