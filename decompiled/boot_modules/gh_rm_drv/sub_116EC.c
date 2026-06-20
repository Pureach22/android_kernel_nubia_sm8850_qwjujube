void sub_116EC()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = trace_event_buffer_reserve;
  *(_QWORD *)(StatusReg + 80) = &_gh_rm_setup_feature_scm_assign__alloc_tag_174;
  v3 = _kmalloc_cache_noprof(v2, 3520, 42);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x11644);
  JUMPOUT(0x11544);
}
