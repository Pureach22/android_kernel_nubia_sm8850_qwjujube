void sub_7A064()
{
  _QWORD *v0; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &regdb_fw_cb__alloc_tag;
  v3 = kmemdup_noprof(v0[1], *v0, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x7A004);
  JUMPOUT(0x79FE8);
}
