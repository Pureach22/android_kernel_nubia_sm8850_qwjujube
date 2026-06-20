__int64 __fastcall adreno_dispatcher_timer(__int64 a1)
{
  return kthread_queue_work(*(_QWORD *)(a1 + 4584), a1 + 4592);
}
