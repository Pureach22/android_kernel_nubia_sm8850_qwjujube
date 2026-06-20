__int64 __fastcall sub_19A7EC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x29

  return qdf_dp_trace_dump_all(
           a1,
           a2,
           a3,
           a4,
           atomic_load_explicit((atomic_ullong *volatile)(v4 + 202), memory_order_acquire));
}
