__int64 __fastcall hif_post_recv_buffers_failure(
        unsigned int *a1,
        __int64 a2,
        int *a3,
        unsigned int a4,
        const char *a5)
{
  __int64 v10; // x28
  __int64 v11; // x19
  unsigned int v12; // w25
  unsigned __int64 StatusReg; // x8
  int v14; // w27
  __int64 v15; // x8
  __int64 v16; // x7
  __int64 result; // x0
  unsigned int v18; // w8
  unsigned int v25; // w20
  unsigned int v26; // w20
  unsigned int v29; // w9
  unsigned int v32; // w10

  _X8 = a1 + 6;
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v25 = __ldxr(_X8);
    v26 = v25 + 1;
  }
  while ( __stlxr(v26, _X8) );
  __dmb(0xBu);
  v10 = *(_QWORD *)a1;
  v11 = *((_QWORD *)a1 + 2);
  v12 = *(_DWORD *)(*(_QWORD *)a1 + 8LL);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 10);
  }
  else
  {
    raw_spin_lock_bh(a1 + 10);
    *((_QWORD *)a1 + 6) |= 1uLL;
  }
  v14 = *a3 + 1;
  *a3 = v14;
  v15 = *((_QWORD *)a1 + 6);
  if ( (v15 & 1) != 0 )
  {
    *((_QWORD *)a1 + 6) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 10);
  }
  else
  {
    raw_spin_unlock(a1 + 10);
  }
  qdf_trace_msg(
    61,
    8,
    "%s: pipe_num: %d, needed: %d, err_cnt: %u, fail_type: %s",
    "hif_post_recv_buffers_failure",
    *((unsigned __int8 *)a1 + 8),
    v26,
    v14,
    a5);
  hif_record_ce_desc_event(v11, v12, a4, 0, a2, v26, 0, v16);
  if ( v26 == **(_DWORD **)(v10 + 144) - 1
    || (result = hif_get_target_info_handle(v11), v18 = *(_DWORD *)(result + 4), v18 <= 0x2B)
    && ((1LL << v18) & 0xFBFFFB00000LL) != 0
    && v26 == **(_DWORD **)(v10 + 144) - 2 )
  {
    _X8 = (unsigned int *)(v11 + 680);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 + 1, _X8) );
    result = queue_work_on(32, system_wq, v10 + 24);
    if ( (result & 1) == 0 )
    {
      _X8 = (unsigned int *)(v11 + 680);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 - 1, _X8) );
    }
  }
  return result;
}
