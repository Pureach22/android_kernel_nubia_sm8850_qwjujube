__int64 __fastcall hdd_adapter_dev_put_debug(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  __int64 v13; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x9
  unsigned int *v16; // x9
  unsigned int v17; // w12
  __int64 v18; // x9
  unsigned int v24; // w9
  unsigned int v25; // w9
  char *v26; // x4

  v11 = result;
  if ( a2 < 0x44
    || (result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: Invalid debug id: %d",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   "hdd_adapter_dev_put_debug",
                   a2),
        a2 == 68) )
  {
    _X8 = (unsigned int *)(v11 + 4LL * a2 + 52524);
  }
  else
  {
    __break(0x5512u);
  }
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v24 = __ldxr(_X8);
    v25 = v24 - 1;
  }
  while ( __stlxr(v25, _X8) );
  __dmb(0xBu);
  if ( (v25 & 0x80000000) != 0 )
  {
    if ( a2 < 0x44 )
    {
      v26 = net_dev_ref_debug_string_from_id_strings[a2];
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Debug string not found for debug id %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "net_dev_ref_debug_string_from_id",
        a2);
      v26 = (char *)&unk_98C763;
    }
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: dev_put detected without dev_hold for debug id: %s",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hdd_adapter_dev_put_debug",
               v26);
    v13 = *(_QWORD *)(v11 + 32);
    if ( !v13 )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: adapter->dev is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hdd_adapter_dev_put_debug");
  }
  else
  {
    v13 = *(_QWORD *)(v11 + 32);
    if ( !v13 )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: adapter->dev is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hdd_adapter_dev_put_debug");
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  v15 = *(_QWORD *)(v13 + 1320);
  v16 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v15);
  do
    v17 = __ldxr(v16);
  while ( __stxr(v17 - 1, v16) );
  v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v18;
  if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
    return preempt_schedule_notrace(result);
  return result;
}
