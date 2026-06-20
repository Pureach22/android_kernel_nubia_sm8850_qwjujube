__int64 __fastcall msm_hw_fence_internal_signal_callback(__int64 a1, __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x21
  __int64 result; // x0

  v3 = v2;
  if ( !a1 || !a2 )
    return printk(&unk_2A893, "msm_hw_fence_internal_signal_callback", 1526, v2, a1);
  if ( (~msm_hw_fence_debug_level & 0x10040) == 0 )
    printk(&unk_26BC4, "msm_hw_fence_internal_signal_callback", 1531, *(_QWORD *)(a1 + 32), *(_QWORD *)(a1 + 40));
  result = hw_fence_signal_fence(*(_QWORD *)(a2 + 24), a1, *(_QWORD *)(a2 + 32), *(unsigned int *)(a1 + 60), 0);
  if ( (_DWORD)result )
    return printk(&unk_20BAC, "msm_hw_fence_internal_signal_callback", 1537, v3, *(_QWORD *)(a1 + 32));
  return result;
}
