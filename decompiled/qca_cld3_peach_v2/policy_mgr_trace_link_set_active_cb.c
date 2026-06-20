void *__fastcall policy_mgr_trace_link_set_active_cb(__int64 a1, const void *a2, const void *a3)
{
  __int64 v4; // x21
  void *result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x21
  unsigned __int64 v8; // x8
  unsigned int v15; // w8
  unsigned int v16; // w8
  unsigned int v19; // w8
  unsigned int v20; // w8

  if ( a2 && g_trace_set_link_cmd )
  {
    _X9 = &g_trace_set_link_cmd_index;
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v15 = __ldxr((unsigned int *)&g_trace_set_link_cmd_index);
      v16 = v15 + 1;
    }
    while ( __stlxr(v16, (unsigned int *)&g_trace_set_link_cmd_index) );
    __dmb(0xBu);
    v4 = 136LL * (v16 & 7);
    result = qdf_mem_copy((void *)(g_trace_set_link_cmd + v4 + 8), a2, 0x7Cu);
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    *(_QWORD *)(g_trace_set_link_cmd + v4) = StatusReg;
  }
  if ( a3 && g_trace_set_link_evt )
  {
    _X9 = &g_trace_set_link_evt_index;
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v19 = __ldxr((unsigned int *)&g_trace_set_link_evt_index);
      v20 = v19 + 1;
    }
    while ( __stlxr(v20, (unsigned int *)&g_trace_set_link_evt_index) );
    __dmb(0xBu);
    v7 = (unsigned __int64)(v20 & 7) << 6;
    result = qdf_mem_copy((void *)(g_trace_set_link_evt + v7 + 8), a3, 0x38u);
    __isb(0xFu);
    v8 = _ReadStatusReg(CNTVCT_EL0);
    *(_QWORD *)(g_trace_set_link_evt + v7) = v8;
  }
  return result;
}
