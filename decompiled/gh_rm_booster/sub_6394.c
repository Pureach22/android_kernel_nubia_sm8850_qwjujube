void sub_6394()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x22
  __int64 (*v2)(void); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = gh_rm_register_notifier;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v2, 3520, 240);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x613C);
}
