void sub_25E70()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &dfc_get_flow_status_req__alloc_tag_191;
  v3 = _kmalloc_cache_noprof(v2, 2336, 72);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x25D60);
  JUMPOUT(0x25C54);
}
