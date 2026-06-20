__int64 __fastcall dfs_get_debug_info(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0

  result = *(unsigned int *)(a1 + 8);
  if ( a2 )
    *a2 = result;
  return result;
}
