__int64 __fastcall sde_fence_value_str(__int64 result, char *s, int a3)
{
  if ( result )
  {
    if ( s )
      return snprintf(s, a3, "%llu", *(_QWORD *)(result + 40));
  }
  return result;
}
