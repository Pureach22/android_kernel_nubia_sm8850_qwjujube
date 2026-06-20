void sub_6AFC()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 (__fastcall *v2)(_QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = cdev_init;
  *(_QWORD *)(StatusReg + 80) = &spss_probe__alloc_tag_8;
  _kmalloc_cache_noprof(v2, 3520, 24);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x6528);
}
