__int64 __fastcall msm_hw_fence_destroy_with_handle(
        unsigned int *a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x20
  __int64 result; // x0
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 v12; // x4
  unsigned int v13; // w0
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x30
  unsigned int v17; // w20

  v8 = v5;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    v11 = hw_fence_drv_data;
    v12 = *a1;
    if ( (unsigned int)v12 >= *(_DWORD *)(hw_fence_drv_data + 60) )
    {
      printk(&unk_2513C, "msm_hw_fence_destroy_with_handle", 391, v8, v12);
      return 4294967274LL;
    }
    else
    {
      if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      {
        printk(&unk_2B058, "msm_hw_fence_destroy_with_handle", 395, v10, v12);
        v11 = hw_fence_drv_data;
      }
      v13 = hw_fence_destroy_with_hash(v11, a1, a2);
      if ( v13 )
      {
        v16 = v8;
        v17 = v13;
        printk(&unk_21AF7, "msm_hw_fence_destroy_with_handle", 401, v16, a2);
        return v17;
      }
      else
      {
        if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
          printk(&unk_2388F, "msm_hw_fence_destroy_with_handle", 405, v14, v15);
        return 0;
      }
    }
  }
  return result;
}
