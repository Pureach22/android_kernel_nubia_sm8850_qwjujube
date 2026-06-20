__int64 __usercall sub_397C8@<X0>(__int64 a1@<X0>, __int64 a2@<X8>)
{
  return cnss_aop_ol_cpr_cfg_setup(a1, atomic_load_explicit((atomic_ullong *volatile)(a2 + 143), memory_order_acquire));
}
