__int64 __fastcall gen8_cp_callback(__int64 a1)
{
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
    gen8_preemption_trigger(a1, 1);
  return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
}
