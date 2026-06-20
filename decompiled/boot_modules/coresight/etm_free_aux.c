__int64 __fastcall etm_free_aux(__int64 a1)
{
  return queue_work_on(32, system_wq, a1);
}
