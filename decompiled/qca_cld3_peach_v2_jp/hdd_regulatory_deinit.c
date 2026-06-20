__int64 __fastcall hdd_regulatory_deinit(__int64 a1)
{
  flush_work(a1 + 6784);
  return cancel_work_sync(a1 + 6784);
}
