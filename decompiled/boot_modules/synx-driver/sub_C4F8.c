void sub_C4F8()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &synx_signal_offload_job__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 88);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xC4B0);
  JUMPOUT(0xC44C);
}
