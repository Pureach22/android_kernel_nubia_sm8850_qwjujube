void __noreturn sub_AD84()
{
  unsigned int *v0; // x19

  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  atomic_load(v0);
  JUMPOUT(0xAD94);
}
