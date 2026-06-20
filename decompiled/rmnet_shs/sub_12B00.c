__int64 __fastcall sub_12B00(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x18

  return rmnet_shs_genl_send_int_to_userspace(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           atomic_load_explicit((atomic_uint *volatile)(v6 + 254), memory_order_acquire));
}
