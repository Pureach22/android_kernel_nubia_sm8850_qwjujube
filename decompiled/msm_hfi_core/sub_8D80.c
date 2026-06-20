void sub_8D80()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v2 = vzalloc_noprof(1096);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x8D58);
  JUMPOUT(0x8B14);
}
