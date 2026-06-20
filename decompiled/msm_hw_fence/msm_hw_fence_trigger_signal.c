__int64 __fastcall msm_hw_fence_trigger_signal(unsigned int *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v7; // w19
  unsigned int v8; // w20
  __int64 result; // x0
  __int64 v10; // x4

  v7 = a4;
  v8 = a3;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(&unk_229F4, "msm_hw_fence_trigger_signal", 639, *a1, v10);
    hw_fence_ipcc_trigger_signal(hw_fence_drv_data, a2, v8, v7);
    return 0;
  }
  return result;
}
