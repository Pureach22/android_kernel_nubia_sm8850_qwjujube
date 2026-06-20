void __noreturn sub_7F44()
{
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  JUMPOUT(0x7F50);
}
