__int64 __fastcall msm_hw_fence_reset_client(unsigned int *a1, char a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  __int64 v8; // x4
  __int64 v9; // x0
  __int64 v10; // x22
  unsigned int v11; // w23

  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    v9 = hw_fence_drv_data;
    v10 = *(_QWORD *)(hw_fence_drv_data + 64);
    if ( (~msm_hw_fence_debug_level & 0x10002) != 0 )
    {
      if ( *(_DWORD *)(hw_fence_drv_data + 80) )
        goto LABEL_4;
    }
    else
    {
      printk(&unk_27BC2, "msm_hw_fence_reset_client", 531, *a1, v8);
      v9 = hw_fence_drv_data;
      if ( *(_DWORD *)(hw_fence_drv_data + 80) )
      {
LABEL_4:
        v11 = 0;
        do
        {
          hw_fence_utils_cleanup_fence(v9, a1, v10 + ((__int64)(int)v11 << 7), (int)v11, a2);
          v9 = hw_fence_drv_data;
          ++v11;
        }
        while ( v11 < *(_DWORD *)(hw_fence_drv_data + 80) );
      }
    }
    hw_fence_utils_reset_queues(v9, (__int64)a1);
    return 0;
  }
  return result;
}
