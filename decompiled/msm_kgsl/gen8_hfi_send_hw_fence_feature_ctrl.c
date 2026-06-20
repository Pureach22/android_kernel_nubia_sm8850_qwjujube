__int64 __fastcall gen8_hfi_send_hw_fence_feature_ctrl(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 1544);
  if ( (*(_QWORD *)(a1 + 22496) & 0x10) == 0 )
    return 0;
  result = gen8_hfi_send_feature_ctrl(a1, 25, 1, 0);
  if ( (_DWORD)result == -2 )
  {
    dev_err(v1 + 16, "GMU doesn't support HW_FENCE feature\n");
    adreno_hwsched_deregister_hw_fence(a1);
    return 0;
  }
  return result;
}
