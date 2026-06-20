__int64 __fastcall adreno_hwsched_start(__int64 a1)
{
  complete_all(a1 + 8720);
  return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
}
