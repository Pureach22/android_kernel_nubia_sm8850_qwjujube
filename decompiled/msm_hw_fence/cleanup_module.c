__int64 __fastcall cleanup_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v6; // x3
  __int64 v7; // x4

  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    printk(&unk_2B058, "msm_hw_fence_exit", 963, a4, a5);
  result = platform_driver_unregister(msm_hw_fence_driver);
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    return printk(&unk_2388F, "msm_hw_fence_exit", 967, v6, v7);
  return result;
}
