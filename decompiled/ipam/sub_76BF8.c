void sub_76BF8()
{
  unsigned int v0; // w22
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &get_ipa_dts_configuration__alloc_tag;
  v3 = _kmalloc_noprof(4LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x7592C);
  JUMPOUT(0x74C8C);
}
