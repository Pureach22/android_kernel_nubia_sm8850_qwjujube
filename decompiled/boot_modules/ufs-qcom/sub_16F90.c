void __noreturn sub_16F90()
{
  unsigned int *v0; // x19

  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  atomic_load(v0);
  atomic_load(v0);
  JUMPOUT(0x16FB8);
}
