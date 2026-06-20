__int64 __fastcall gen7_hfi_send_hw_fence_feature_ctrl(__int64 a1)
{
  __int64 result; // x0

  if ( (*(_QWORD *)(a1 + 22496) & 0x10) == 0 )
    return 0;
  result = gen7_hfi_send_feature_ctrl(a1, 25, 1, 0);
  if ( (_DWORD)result == -2 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU doesn't support HW_FENCE feature\n");
    adreno_hwsched_deregister_hw_fence(a1);
    return 0;
  }
  return result;
}
