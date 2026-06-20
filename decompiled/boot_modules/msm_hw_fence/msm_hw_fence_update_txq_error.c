__int64 __fastcall msm_hw_fence_update_txq_error(
        unsigned int *a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x22
  unsigned int v9; // w21
  int v10; // w19
  __int64 result; // x0
  __int64 v12; // x4

  v8 = v5;
  v9 = a4;
  v10 = a3;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( v10 && *(unsigned int *)(hw_fence_drv_data + 80) > a2 )
    {
      if ( v9 == 1 )
      {
        hw_fence_update_existing_txq_payload(hw_fence_drv_data, a1, a2, v10, v12);
        return 0;
      }
      else
      {
        printk(&unk_25727, "msm_hw_fence_update_txq_error", 612, v8, v9);
        return 4294967274LL;
      }
    }
    else
    {
      printk(&unk_26412, "msm_hw_fence_update_txq_error", 606, v8, a2);
      return 4294967274LL;
    }
  }
  return result;
}
