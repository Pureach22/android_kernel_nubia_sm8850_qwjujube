void sub_116B4()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_gh_rm_setup_feature_scm_assign__alloc_tag;
  v2 = _alloc_pages_noprof(3264, 0, 0, 0);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x11650);
  JUMPOUT(0x11524);
}
