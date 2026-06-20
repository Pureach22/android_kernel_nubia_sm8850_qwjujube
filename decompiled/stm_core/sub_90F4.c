void sub_90F4()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &get_policy_node_type__alloc_tag;
  v2 = kmemdup_noprof(&stp_policy_node_type, 40, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x90E0);
  JUMPOUT(0x90AC);
}
