const char *__fastcall osif_cm_qca_reason_to_str(unsigned int a1)
{
  if ( a1 > 0x10 )
    return "Unknown";
  else
    return (const char *)*(&off_ACFBD0 + a1);
}
