void __noreturn sub_6EF0()
{
  atomic_uint *v0; // x9

  atomic_fetch_add_explicit(v0, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  JUMPOUT(0x6F04);
}
