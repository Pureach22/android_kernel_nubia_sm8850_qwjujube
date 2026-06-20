void sub_7BFC()
{
  unsigned int *v0; // x19

  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  atomic_load(v0);
  JUMPOUT(0x7A3C);
}
