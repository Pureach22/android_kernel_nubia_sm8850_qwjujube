void __noreturn sub_13E5C()
{
  unsigned int *v0; // x11
  unsigned int *v1; // x19

  _ReadStatusReg(TPIDR_EL2);
  atomic_load(v1);
  atomic_load(v0);
  JUMPOUT(0x13E68);
}
