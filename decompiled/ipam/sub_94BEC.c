void sub_94BEC()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_debugfs_init__alloc_tag;
  v3 = _kmalloc_large_noprof(15616, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 64) = v3;
  if ( !v3 )
    JUMPOUT(0x94BCC);
  JUMPOUT(0x94A08);
}
