void sub_25E38()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = nla_put;
  *(_QWORD *)(StatusReg + 80) = &dfc_get_flow_status_req__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 18);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x25D68);
  JUMPOUT(0x25C34);
}
