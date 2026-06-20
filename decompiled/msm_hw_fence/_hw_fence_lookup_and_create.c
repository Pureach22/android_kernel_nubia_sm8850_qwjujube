__int64 __fastcall hw_fence_lookup_and_create(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        __int64 *a7)
{
  return hw_fence_lookup_and_create_range(a1, a2, a3, a4, a5, a6, a7, 0, *(_DWORD *)(a1 + 80), 0);
}
