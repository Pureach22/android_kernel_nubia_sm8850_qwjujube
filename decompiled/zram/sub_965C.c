void sub_965C()
{
  __int64 *v0; // x19
  __int64 v1; // x22
  unsigned __int64 StatusReg; // x23
  __int64 v3; // x24
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &zram_meta_alloc__alloc_tag;
  v4 = vzalloc_noprof(16 * v1);
  *(_QWORD *)(StatusReg + 80) = v3;
  *v0 = v4;
  if ( !v4 )
    JUMPOUT(0x95DC);
  JUMPOUT(0x954C);
}
