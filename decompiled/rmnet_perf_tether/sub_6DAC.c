void sub_6DAC()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = param_ops_charp;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v2, 3520, 1);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x6CA4);
}
