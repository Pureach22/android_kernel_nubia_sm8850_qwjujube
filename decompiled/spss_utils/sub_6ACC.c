void sub_6ACC()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = alloc_chrdev_region;
  *(_QWORD *)(StatusReg + 80) = &spss_utils_create_chardev__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 136);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x63FC);
}
