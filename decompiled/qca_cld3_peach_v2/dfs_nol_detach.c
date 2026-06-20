__int64 __fastcall dfs_nol_detach(__int64 a1)
{
  dfs_nol_timer_cleanup();
  flush_work(a1 + 14656);
  return cancel_work_sync(a1 + 14656);
}
