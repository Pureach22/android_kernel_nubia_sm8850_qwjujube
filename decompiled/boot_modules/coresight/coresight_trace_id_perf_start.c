void coresight_trace_id_perf_start()
{
  unsigned int v6; // w9

  _X8 = &perf_cs_etm_session_active;
  __asm { PRFM            #0x11, [X8] }
  do
    v6 = __ldxr((unsigned int *)&perf_cs_etm_session_active);
  while ( __stxr(v6 + 1, (unsigned int *)&perf_cs_etm_session_active) );
}
