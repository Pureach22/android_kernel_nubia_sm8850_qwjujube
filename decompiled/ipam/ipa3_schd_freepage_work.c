__int64 __fastcall ipa3_schd_freepage_work(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v8; // x8

  v1 = result;
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      result = ipc_log_string(
                 result,
                 "ipa %s:%d WQ scheduled, reschedule sort tasklet\n",
                 "ipa3_schd_freepage_work",
                 1396);
  }
  _X9 = (unsigned __int64 *)(v1 + 112);
  __asm { PRFM            #0x11, [X9] }
  do
    v8 = __ldxr(_X9);
  while ( __stlxr(v8 | 1, _X9) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    return _tasklet_schedule(v1 + 104);
  return result;
}
