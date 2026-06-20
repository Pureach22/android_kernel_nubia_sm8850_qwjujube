__int64 __fastcall sub_7C5C(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  void *v8; // x17

  __arm_mte_set_tag((void *)(a8 + 3616), v8);
  return ipclite_global_test_and_clear_bit(a1, a2, a3, a4, a5, a6, a7, a8 + 3616);
}
