_QWORD *__fastcall scheduler_qdf_mc_timer_init(__int64 a1, __int64 a2)
{
  _QWORD *result; // x0

  result = (_QWORD *)_qdf_mem_malloc(0x10u, "scheduler_qdf_mc_timer_init", 469);
  if ( result )
  {
    *result = a1;
    result[1] = a2;
  }
  return result;
}
