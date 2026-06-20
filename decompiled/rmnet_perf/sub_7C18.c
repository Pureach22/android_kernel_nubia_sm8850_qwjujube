__int64 __fastcall sub_7C18(__int64 a1)
{
  atomic_uint *v1; // x9

  atomic_fetch_add_explicit(v1, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  return rmnet_perf_ingress_handle_tcp(a1);
}
