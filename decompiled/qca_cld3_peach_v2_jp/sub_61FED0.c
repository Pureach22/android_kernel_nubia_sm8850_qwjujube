__int64 sub_61FED0()
{
  __int64 v0; // x11

  if ( (v0 & 0x200000000LL) != 0 )
    JUMPOUT(0x6277EC);
  return dfs_find_radar_affected_channels();
}
