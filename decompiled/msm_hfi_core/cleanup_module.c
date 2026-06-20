__int64 __fastcall cleanup_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v5; // x3

  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "msm_hfi_core_exit", 219, a4);
  result = platform_driver_unregister(msm_hfi_core_driver);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    return printk(&unk_1C28B, "msm_hfi_core_exit", 223, v5);
  return result;
}
