__int64 __fastcall create_signaled_hw_fence(__int64 a1, unsigned int a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x30
  __int64 v7; // x22
  __int64 range; // x20

  v7 = v4;
  range = hw_fence_lookup_and_create_range(
            a1,
            0xFFFFFFFD,
            a3,
            *(_QWORD *)(a3 + 32),
            *(_QWORD *)(a3 + 40),
            0,
            a4,
            0,
            *(_DWORD *)(a1 + 80),
            2);
  if ( range )
  {
    signal_fence_if_unsignaled(a1, range, *a4, *(unsigned int *)(a3 + 60), 1);
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(&unk_203BB, "_create_signaled_hw_fence", 2397, a2, *(_QWORD *)(a3 + 32));
  }
  else
  {
    printk(&unk_2874E, "_create_signaled_hw_fence", 2400, v7, a2);
  }
  return range;
}
