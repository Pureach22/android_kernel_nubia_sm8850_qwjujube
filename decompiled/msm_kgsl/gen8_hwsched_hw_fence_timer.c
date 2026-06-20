__int64 __fastcall gen8_hwsched_hw_fence_timer(__int64 a1)
{
  return queue_work_on(32, qword_3A900, a1 + 40);
}
