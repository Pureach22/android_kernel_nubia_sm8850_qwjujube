void sub_87BC()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _stack_chk_fail;
  *(_QWORD *)(StatusReg + 80) = &dwc3_dbg_trace_event__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 500);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x8770);
  JUMPOUT(0x83D4);
}
