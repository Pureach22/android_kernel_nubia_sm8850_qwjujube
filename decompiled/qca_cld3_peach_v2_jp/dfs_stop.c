__int64 __fastcall dfs_stop(__int64 a1)
{
  dfs_nol_timer_cleanup();
  return dfs_nol_workqueue_cleanup(a1);
}
