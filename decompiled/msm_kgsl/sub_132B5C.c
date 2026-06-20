__int64 __fastcall sub_132B5C(int a1, char *a2, __int64 a3, __int64 a4, unsigned __int64 *a5)
{
  unsigned __int64 v5; // x15

  __stxr(v5, a5);
  return kgsl_syncsource_fence_value_str(a1, a2);
}
