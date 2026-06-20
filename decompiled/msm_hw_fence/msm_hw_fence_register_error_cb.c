__int64 __fastcall msm_hw_fence_register_error_cb(
        unsigned int *a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x22
  __int64 result; // x0

  v8 = v5;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL && a3 && a3 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( *((_QWORD *)a1 + 18) )
      {
        printk(&unk_2AAE3, "msm_hw_fence_register_error_cb", 665, v8, *a1);
        return 4294967274LL;
      }
      else
      {
        result = 0;
        *((_QWORD *)a1 + 18) = a2;
        *((_QWORD *)a1 + 19) = a3;
      }
    }
    else
    {
      printk(&unk_22E6A, "msm_hw_fence_register_error_cb", 657, v8, a2);
      return 4294967274LL;
    }
  }
  return result;
}
