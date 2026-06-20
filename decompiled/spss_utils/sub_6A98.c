void sub_6A98()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = cdev_add;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v2, 3520, 40);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x63D8);
}
