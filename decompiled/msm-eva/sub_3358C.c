void sub_3358C()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 (__fastcall *v3)(_QWORD, _QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = printk;
  *(_QWORD *)(StatusReg + 80) = &_sys_set_idle_indicator__alloc_tag;
  _kmalloc_cache_noprof(v3, 3520, 20);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !*(_QWORD *)(v0 + 2416) )
    JUMPOUT(0x33564);
  JUMPOUT(0x33538);
}
