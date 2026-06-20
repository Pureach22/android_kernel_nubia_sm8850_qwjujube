__int64 __fastcall adreno_cp_callback(__int64 a1)
{
  return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
}
