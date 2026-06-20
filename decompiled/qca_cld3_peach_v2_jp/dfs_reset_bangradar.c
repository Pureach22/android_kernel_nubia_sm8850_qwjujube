__int64 __fastcall dfs_reset_bangradar(__int64 result)
{
  *(_DWORD *)(result + 224) = 0;
  return result;
}
