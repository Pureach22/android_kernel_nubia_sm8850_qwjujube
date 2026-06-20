void sub_6F14()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _list_add_valid_or_report;
  *(_QWORD *)(StatusReg + 80) = &smem_probe__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x6EA8);
}
