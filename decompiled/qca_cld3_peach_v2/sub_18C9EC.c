__int64 __fastcall sub_18C9EC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19

  atomic_load_explicit((atomic_uint *volatile)(v4 - 157), memory_order_acquire);
  return _qdf_wake_lock_create(a1, a2, a3, a4);
}
