__int64 __fastcall kgsl_syncsource_fence_value_str(__int64 a1, char *s, int a3)
{
  return snprintf(s, a3, "%llu", *(_QWORD *)(a1 + 32));
}
