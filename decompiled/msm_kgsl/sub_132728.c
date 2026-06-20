__int64 __fastcall sub_132728(int a1, char *a2, __int64 a3, __int64 a4, unsigned __int64 *a5)
{
  unsigned __int64 v5; // x15

  __stxr(v5, a5);
  return kgsl_sync_fence_value_str(a1, a2);
}
