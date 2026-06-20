__int64 __usercall sub_63AE38@<X0>(atomic_uint *a1@<X8>)
{
  unsigned int v1; // w11
  unsigned int v2; // w20
  atomic_uint *StatusReg; // x8

  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(a1, v1, memory_order_relaxed);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  StatusReg = (atomic_uint *)_ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(StatusReg, v2, memory_order_relaxed);
  _ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(StatusReg, v2, memory_order_relaxed);
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return wlan_dp_lb_set_default_affinity();
}
