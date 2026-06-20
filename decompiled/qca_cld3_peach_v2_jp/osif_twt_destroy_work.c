__int64 __fastcall osif_twt_destroy_work(__int64 a1)
{
  flush_work(a1 + 1288);
  cancel_work_sync(a1 + 1288);
  return 0;
}
