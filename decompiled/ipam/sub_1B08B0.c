void __noreturn sub_1B08B0()
{
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  JUMPOUT(0x1B08BC);
}
