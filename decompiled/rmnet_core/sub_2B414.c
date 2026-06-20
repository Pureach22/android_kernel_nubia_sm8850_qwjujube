__int64 __fastcall sub_2B414(__int64 a1, __int64 a2, __int64 a3)
{
  atomic_uint *v3; // x9

  atomic_fetch_add_explicit(v3, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  return rmnet_qmap_send(a1, a2, a3);
}
