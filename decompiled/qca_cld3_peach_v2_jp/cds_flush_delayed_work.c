__int64 __fastcall cds_flush_delayed_work(__int64 a1)
{
  return cancel_delayed_work_sync(a1);
}
