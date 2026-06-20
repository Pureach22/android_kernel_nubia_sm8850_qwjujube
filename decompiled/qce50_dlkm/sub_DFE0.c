void sub_DFE0()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qce_open__alloc_tag_34;
  v3 = _kmalloc_noprof(*(int *)(v0 + 48), 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 40) = v3;
  if ( !v3 )
    JUMPOUT(0xDD64);
  JUMPOUT(0xDA68);
}
