__int64 __fastcall hw_fence_interop_get_fence(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x19
  __int64 result; // x0

  v7 = v5;
  LODWORD(result) = hw_fence_check_hw_fence_driver(hw_fence_drv_data, a2, a3, a4, a5);
  if ( (_DWORD)result )
    return (int)result;
  if ( !hw_fence_is_valid_hw_fence_handle(hw_fence_drv_data, a1) )
  {
    printk(&unk_25875, "hw_fence_interop_get_fence", 372, v7, a1);
    return -22;
  }
  result = hw_fence_dma_fence_find(hw_fence_drv_data, (unsigned __int16)a1, 1);
  if ( !result )
  {
    printk(&unk_26F3B, "hw_fence_interop_get_fence", 379, v7, (unsigned __int16)a1);
    return -22;
  }
  return result;
}
