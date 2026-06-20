void sub_8978()
{
  unsigned int *v0; // x19

  atomic_load(v0);
  atomic_load((unsigned __int64 *)v0);
  atomic_load(v0);
  _ReadStatusReg(CNTVCTSS_EL0);
  JUMPOUT(0x82D4);
}
