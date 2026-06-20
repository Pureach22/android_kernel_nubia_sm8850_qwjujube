void sub_D184()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = kthread_create_on_node;
  *(_QWORD *)(StatusReg + 80) = &node_get__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 24);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xD110);
  JUMPOUT(0xD140);
}
