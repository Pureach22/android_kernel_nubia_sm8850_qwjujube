__int64 __fastcall dfs_second_segment_radar_disable(__int64 a1)
{
  *(_DWORD *)(a1 + 8) &= ~0x20000000u;
  return 0;
}
