const char *__fastcall lim_sme_state_str(unsigned int a1)
{
  if ( a1 > 0x10 )
    return "INVALID SME STATE";
  else
    return off_A0A4F0[a1];
}
