void sub_11A294()
{
  _ReadStatusReg(TPIDR_EL2);
  JUMPOUT(0x11A004);
}
