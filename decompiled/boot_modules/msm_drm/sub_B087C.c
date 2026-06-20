void sub_B087C()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dp_mst_duplicate_bridge_state__alloc_tag;
  v3 = kmemdup_noprof(*(_QWORD *)(v0 + 88), 40, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0xB0864);
  JUMPOUT(0xB0858);
}
