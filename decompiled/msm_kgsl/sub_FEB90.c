void sub_FEB90()
{
  _ReadStatusReg(TPIDR_EL2);
  JUMPOUT(0xFD284);
}
