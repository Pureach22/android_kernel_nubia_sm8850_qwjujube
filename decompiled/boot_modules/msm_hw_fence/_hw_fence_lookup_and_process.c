unsigned __int64 __fastcall hw_fence_lookup_and_process(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 *a5,
        __int64 (__fastcall *a6)(_QWORD))
{
  return hw_fence_lookup_and_process_range(a1, a2, a3, a4, a5, 0, *(_DWORD *)(a1 + 80), a6);
}
