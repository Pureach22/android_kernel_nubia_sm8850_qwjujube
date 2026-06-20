void sub_A948()
{
  _ReadStatusReg(TPIDR_EL2);
  JUMPOUT(0x66FC);
}
