__int64 __fastcall hw_fence_utils_reset_queues(__int64 a1, __int64 a2)
{
  return hw_fence_utils_reset_queues_helper(a1, *(_DWORD *)a2, a2 + 40, *(_BYTE *)(a2 + 176));
}
