void sub_DEB7C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = idr_find;
  *(_QWORD *)(StatusReg + 80) = &adreno_rpmh_build_bw_votes__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 32);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xDEB2C);
  JUMPOUT(0xDE7BC);
}
