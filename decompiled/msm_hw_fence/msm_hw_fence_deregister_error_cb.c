__int64 __fastcall msm_hw_fence_deregister_error_cb(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x20
  __int64 result; // x0

  v7 = v5;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    raw_spin_lock(a1 + 40);
    if ( *((_QWORD *)a1 + 18) )
    {
      *((_QWORD *)a1 + 18) = 0;
      *((_QWORD *)a1 + 19) = 0;
    }
    else
    {
      printk(&unk_2154D, "msm_hw_fence_deregister_error_cb", 691, v7, *a1);
    }
    raw_spin_unlock(a1 + 40);
    return 0;
  }
  return result;
}
