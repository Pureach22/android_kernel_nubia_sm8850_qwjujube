__int64 __fastcall cancel_stats_work_sync(__int64 a1)
{
  cancel_delayed_work_sync(a1 + 3816);
  return 0;
}
