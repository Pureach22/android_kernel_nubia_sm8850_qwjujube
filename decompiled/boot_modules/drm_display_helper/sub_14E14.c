void sub_14E14()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &drm_dp_mst_duplicate_state__alloc_tag;
  v3 = kmemdup_noprof(v0, 80, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x14DF0);
  JUMPOUT(0x14C5C);
}
