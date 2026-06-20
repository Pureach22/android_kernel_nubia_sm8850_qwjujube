const char *__fastcall reg_initiator_name(unsigned int a1)
{
  if ( a1 < 4 )
    return off_BE3A0[a1];
  __break(0x800u);
  return "bug";
}
