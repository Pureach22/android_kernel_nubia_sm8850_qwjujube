void sub_9C48()
{
  __int64 v0; // x28
  unsigned __int64 StatusReg; // x27
  __int64 v2; // x24
  unsigned __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &prepare_qmi_response__alloc_tag;
  v3 = *(int *)(v0 + 64);
  if ( is_mul_ok(v3, 0x50u) )
    _kmalloc_noprof(80 * v3, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x97F8);
}
