__int64 __fastcall sub_8873C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return _traceiter_rdev_return_int_mesh_config(
           a1,
           a2,
           a3,
           a4,
           a5,
           atomic_load_explicit((atomic_ullong *volatile)(a6 - 28), memory_order_acquire));
}
