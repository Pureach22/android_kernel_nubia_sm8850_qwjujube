__int64 sub_68DB00()
{
  __int64 v0; // x11

  if ( (v0 & 0x200000000LL) != 0 )
    JUMPOUT(0x69541C);
  return dfs_find_radar_affected_channels();
}
