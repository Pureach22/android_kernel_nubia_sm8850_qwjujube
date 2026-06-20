__int64 __fastcall sub_11FD8(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x11

  return mem_buf_get_sgl_buf_size(
           a1,
           a2,
           a3,
           a4,
           atomic_load_explicit((atomic_uint *volatile)(v4 + 209), memory_order_acquire));
}
