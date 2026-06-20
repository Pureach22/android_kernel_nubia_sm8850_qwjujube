void sub_19FAC()
{
  unsigned __int64 StatusReg; // x26
  __int64 v1; // x27
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _usecs_to_jiffies;
  *(_QWORD *)(StatusReg + 80) = &_fastrpc_buf_alloc__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 224);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x19EC4);
  JUMPOUT(0x19DA0);
}
