__int64 __fastcall qdf_mtrace_log(
        unsigned int a1,
        int a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v19; // w10

  if ( (qdf_mtrace_log_initialized & 1) == 0 )
  {
    qdf_mtrace_log_counter = 0;
    qdf_mtrace_log_initialized = 1;
  }
  _X9 = &qdf_mtrace_log_counter;
  __asm { PRFM            #0x11, [X9] }
  do
    v19 = __ldxr((unsigned int *)&qdf_mtrace_log_counter);
  while ( __stxr(v19 + 1, (unsigned int *)&qdf_mtrace_log_counter) );
  return qdf_trace_msg(
           a1,
           9u,
           "%x %x",
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           (a2 << 15) | (a1 << 23) | a3,
           (unsigned __int16)qdf_mtrace_log_counter | (a4 << 16));
}
