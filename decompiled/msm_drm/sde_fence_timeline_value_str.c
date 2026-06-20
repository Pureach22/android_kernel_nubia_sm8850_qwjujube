__int64 __fastcall sde_fence_timeline_value_str(__int64 result, char *s, int a3)
{
  __int64 v3; // x9

  if ( result && s )
  {
    v3 = *(_QWORD *)(result + 64);
    if ( v3 )
      return snprintf(s, a3, "%d", *(_DWORD *)(v3 + 4));
  }
  return result;
}
