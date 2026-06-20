void __noreturn sub_B988()
{
  unsigned int *v0; // x19

  _ReadStatusReg(TPIDR_EL2);
  atomic_load(v0);
  atomic_load(v0);
  JUMPOUT(0xB994);
}
