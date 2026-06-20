void __usercall __noreturn sub_76F8(atomic_ullong *a1@<X8>)
{
  unsigned int v1; // w10

  atomic_fetch_add_explicit(a1, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit(a1, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  atomic_fetch_add_explicit((atomic_uint *volatile)_ReadStatusReg(TPIDR_EL2), v1, memory_order_relaxed);
  JUMPOUT(0x7734);
}
