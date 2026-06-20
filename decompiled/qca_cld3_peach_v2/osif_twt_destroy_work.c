__int64 __fastcall osif_twt_destroy_work(__int64 a1)
{
  flush_work(a1 + 1368);
  cancel_work_sync(a1 + 1368);
  return 0;
}
