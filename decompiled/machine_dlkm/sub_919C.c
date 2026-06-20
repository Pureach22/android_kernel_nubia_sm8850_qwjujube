void sub_919C()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _stack_chk_fail;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v2, 3520, 104);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x90E0);
}
