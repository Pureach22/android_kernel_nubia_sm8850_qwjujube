__int64 __fastcall qdf_mtrace(__int64 a1, int a2, unsigned int a3, unsigned __int8 a4, int a5)
{
  unsigned __int16 v5; // w20
  unsigned int v8; // w19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v24; // w10

  v5 = a3;
  v8 = a1;
  qdf_trace(a1, a3, a4, a5);
  if ( (qdf_mtrace_log_initialized & 1) == 0 )
  {
    qdf_mtrace_log_counter = 0;
    qdf_mtrace_log_initialized = 1;
  }
  _X9 = &qdf_mtrace_log_counter;
  __asm { PRFM            #0x11, [X9] }
  do
    v24 = __ldxr((unsigned int *)&qdf_mtrace_log_counter);
  while ( __stxr(v24 + 1, (unsigned int *)&qdf_mtrace_log_counter) );
  return qdf_trace_msg(
           v8,
           9u,
           "%x %x",
           v9,
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           (a2 << 15) | (v8 << 23) | v5,
           (unsigned __int16)qdf_mtrace_log_counter | (a4 << 16));
}
