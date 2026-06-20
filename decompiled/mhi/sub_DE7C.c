void sub_DE7C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = raw_read_unlock_bh;
  *(_QWORD *)(StatusReg + 80) = &mhi_register_controller__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 104);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xDADC);
}
