void sub_D7C48()
{
  __int64 v0; // x19
  __int64 v1; // x21
  unsigned __int64 StatusReg; // x24
  __int64 v3; // x25
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &wlan_msg_process__alloc_tag_72;
  v4 = kmemdup_noprof(v1, *(unsigned __int16 *)(v0 + 2), 3264);
  *(_QWORD *)(StatusReg + 80) = v3;
  if ( !v4 )
    JUMPOUT(0xD7A74);
  JUMPOUT(0xD7764);
}
