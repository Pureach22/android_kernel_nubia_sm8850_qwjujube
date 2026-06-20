void sub_D48C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = raw_read_lock_bh;
  *(_QWORD *)(StatusReg + 80) = &mhi_init_dev_ctxt__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 48);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xD468);
  JUMPOUT(0xD188);
}
