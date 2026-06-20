__int64 __fastcall scheduler_core_msg_free(unsigned __int64 a1)
{
  __int64 result; // x0
  unsigned int v8; // w10

  result = qdf_flex_mem_free((__int64)sched_pool, a1);
  _X9 = &_sched_queue_depth;
  __asm { PRFM            #0x11, [X9] }
  do
    v8 = __ldxr((unsigned int *)&_sched_queue_depth);
  while ( __stxr(v8 - 1, (unsigned int *)&_sched_queue_depth) );
  return result;
}
