unsigned __int64 __fastcall msm_hw_fence_find(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned __int64 *a6)
{
  __int64 v6; // x30
  __int64 v7; // x21
  unsigned int v8; // w22
  unsigned __int64 result; // x0

  v7 = v6;
  if ( a2 )
    v8 = *a2;
  else
    v8 = -1;
  result = hw_fence_lookup_and_process_range(
             a1,
             a3,
             a4,
             a5,
             a6,
             0,
             *(_DWORD *)(a1 + 80),
             (__int64 (__fastcall *)(_QWORD))fence_found);
  if ( !result )
  {
    printk(&unk_291E6, "msm_hw_fence_find", 1862, v7, v8);
    return 0;
  }
  return result;
}
