__int64 __fastcall sub_CAE0(__int64 a1)
{
  atomic_uint *v1; // x9
  atomic_uint *StatusReg; // x10

  StatusReg = (atomic_uint *)_ReadStatusReg(TPIDR_EL2);
  atomic_fetch_add_explicit(v1, (unsigned int)StatusReg, memory_order_relaxed);
  atomic_fetch_add_explicit(StatusReg, _ReadStatusReg(TPIDR_EL2), memory_order_relaxed);
  return rmnet_wlan_stats_update(a1);
}
