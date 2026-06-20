void sub_6334()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _stack_chk_fail;
  *(_QWORD *)(StatusReg + 80) = &send_unfreeze_event__alloc_tag;
  _kmalloc_cache_noprof(v2, 2336, 48);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x62B4);
}
