__int64 __fastcall kgsl_sync_fence_value_str(__int64 a1, char *s, int a3)
{
  return snprintf(s, a3, "%u", *(_DWORD *)(a1 + 100));
}
