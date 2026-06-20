__int64 __fastcall utils_dfs_can_ignore_radar_event(__int64 a1)
{
  return policy_mgr_get_can_skip_radar_event(*(_QWORD *)(a1 + 80)) & 1;
}
