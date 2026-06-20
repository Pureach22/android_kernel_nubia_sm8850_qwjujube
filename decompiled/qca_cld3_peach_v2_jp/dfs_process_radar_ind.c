__int64 __fastcall dfs_process_radar_ind(__int64 a1, __int64 a2)
{
  if ( (utils_dfs_can_ignore_radar_event(*(_QWORD *)(a1 + 14936)) & 1) != 0 )
    return 0;
  else
    return dfs_process_radar_ind_on_home_chan(a1, a2);
}
