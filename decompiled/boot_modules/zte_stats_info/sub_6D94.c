void __noreturn sub_6D94()
{
  unsigned int v0; // w10

  atomic_fetch_add_explicit((atomic_uint *volatile)_ReadStatusReg(TPIDR_EL2), v0, memory_order_relaxed);
  JUMPOUT(0x6DA8);
}
