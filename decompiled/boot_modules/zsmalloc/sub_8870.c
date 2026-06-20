void sub_8870()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v2 = _kmalloc_cache_noprof(_cpuhp_remove_state, 3520, 2136);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x87D8);
  JUMPOUT(0x84A8);
}
