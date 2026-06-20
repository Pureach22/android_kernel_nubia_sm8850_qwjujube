__int64 __fastcall dfs_inc_num_radar(__int64 result)
{
  ++*(_DWORD *)(result + 88);
  return result;
}
