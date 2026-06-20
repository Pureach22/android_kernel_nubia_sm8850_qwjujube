__int64 __fastcall adreno_scheduler_fault(__int64 a1, int a2)
{
  unsigned int v9; // w9

  _X8 = (unsigned int *)(a1 + 24448);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 | a2, _X8) );
  __dmb(0xAu);
  return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
}
