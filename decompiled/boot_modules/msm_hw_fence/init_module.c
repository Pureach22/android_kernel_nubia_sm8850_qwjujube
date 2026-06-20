__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 v7; // x3
  __int64 v8; // x4
  unsigned int v9; // w19

  v6 = v5;
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    printk(&unk_2B058, "msm_hw_fence_init", 947, a4, a5);
  v9 = _platform_driver_register(msm_hw_fence_driver, &_this_module);
  if ( v9 )
  {
    printk(&unk_2221E, "msm_hw_fence_init", 952, v6, "msm_hw_fence_init");
  }
  else if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    printk(&unk_2388F, "msm_hw_fence_init", 956, v7, v8);
  }
  return v9;
}
