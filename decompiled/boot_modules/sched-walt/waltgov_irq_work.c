__int64 __fastcall waltgov_irq_work(__int64 a1)
{
  return kthread_queue_work(a1 + 120, a1 + 32);
}
