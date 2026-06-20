void sub_8114()
{
  _QWORD *v0; // x23
  unsigned __int64 StatusReg; // x26
  __int64 v2; // x27
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qmi_invoke_handler__alloc_tag;
  v3 = _kmalloc_noprof(*v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x80E4);
  JUMPOUT(0x8094);
}
