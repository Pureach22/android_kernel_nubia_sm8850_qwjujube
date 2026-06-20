__int64 __fastcall hw_fence_utils_cleanup_fence(__int64 a1, unsigned int *a2, __int64 a3, unsigned __int64 a4, char a5)
{
  __int64 v5; // x30
  __int64 v8; // x20
  __int64 v13; // x3
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 result; // x0
  __int64 v17; // x30
  unsigned int v18; // w20

  v8 = v5;
  global_atomic_store(a1, a3 + 40, 1);
  v13 = *a2;
  v14 = *(_QWORD *)(a3 + 24);
  v15 = 1LL << v13;
  if ( ((1LL << v13) & v14) != 0 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
    {
      printk(&unk_2805E, "hw_fence_utils_cleanup_fence", 2523, v13, *(_QWORD *)(a3 + 8));
      v14 = *(_QWORD *)(a3 + 24);
      v15 = 1LL << *a2;
    }
    *(_QWORD *)(a3 + 24) = v14 & ~v15;
    if ( (a5 & 2) == 0 )
    {
      hw_fence_put_and_unlock(a1, *a2, a3, a4);
      return 0;
    }
  }
  global_atomic_store(a1, a3 + 40, 0);
  result = 0;
  if ( *(_DWORD *)(a3 + 32) != *a2 )
    return result;
  signal_fence_if_unsignaled(a1, a3, a4, (a5 & 1) == 0, 1);
  if ( (a5 & 2) != 0 )
    return 0;
  result = hw_fence_destroy_with_hash(a1, a2, a4);
  if ( (_DWORD)result )
  {
    v17 = v8;
    v18 = result;
    printk(&unk_20416, "hw_fence_utils_cleanup_fence", 2545, v17, a4);
    return v18;
  }
  return result;
}
