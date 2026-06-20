void sub_139DC()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x25
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _mutex_init;
  *(_QWORD *)(StatusReg + 80) = &frpc_coredump__alloc_tag_116;
  v3 = _kmalloc_cache_noprof(v2, 3520, 136);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x1398C);
  JUMPOUT(0x13660);
}
