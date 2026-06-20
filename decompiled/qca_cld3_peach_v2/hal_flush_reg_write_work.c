__int64 __fastcall hal_flush_reg_write_work(__int64 a1)
{
  flush_work(a1 + 74472);
  return cancel_work_sync(a1 + 74472);
}
