void sub_2C3A4()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _stack_chk_fail;
  *(_QWORD *)(StatusReg + 80) = &ll_send_nl_ack__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 48);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x2C390);
  JUMPOUT(0x2C314);
}
