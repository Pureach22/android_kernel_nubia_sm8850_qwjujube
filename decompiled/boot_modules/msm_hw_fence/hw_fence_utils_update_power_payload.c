__int64 __fastcall hw_fence_utils_update_power_payload(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 result; // x0

  *(_QWORD *)a2 = 0x100002100000040LL;
  *(_DWORD *)(a2 + 16) = a3;
  *(_DWORD *)(a2 + 20) = a4 & 1;
  result = hw_fence_get_qtime();
  *(_QWORD *)(a2 + 52) = result;
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    return printk(
             &unk_2A39C,
             "hw_fence_utils_update_power_payload",
             765,
             *(unsigned __int16 *)(a2 + 4),
             *(unsigned __int16 *)(a2 + 6));
  return result;
}
