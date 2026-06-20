void sub_6360()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _warn_printk;
  *(_QWORD *)(StatusReg + 80) = &init_si_mem_object__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 232);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x62DC);
  JUMPOUT(0x6244);
}
