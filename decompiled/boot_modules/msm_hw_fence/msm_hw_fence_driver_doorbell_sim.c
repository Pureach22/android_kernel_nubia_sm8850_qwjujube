__int64 __fastcall msm_hw_fence_driver_doorbell_sim(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 qtime; // x0

  result = hw_fence_check_hw_fence_driver(hw_fence_drv_data, a2, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
    {
      qtime = hw_fence_get_qtime();
      printk(&unk_2519B, "msm_hw_fence_driver_doorbell_sim", 784, a1, qtime);
    }
    hw_fence_utils_process_signaled_clients_mask(hw_fence_drv_data, a1, v7, v8, v9);
    return 0;
  }
  return result;
}
