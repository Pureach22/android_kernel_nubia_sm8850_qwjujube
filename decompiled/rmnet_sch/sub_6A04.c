void __usercall __noreturn sub_6A04(atomic_uint *a1@<X8>)
{
  unsigned int v1; // w10
  unsigned int v2; // w20

  atomic_fetch_add_explicit(a1, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v2, memory_order_relaxed);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  JUMPOUT(0x6A58);
}
