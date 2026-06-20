__int64 __fastcall ipa3_ring_doorbell_timer_fn(__int64 a1)
{
  queue_work_on(32, *(_QWORD *)(a1 + 64), a1 - 1496);
  return 0;
}
