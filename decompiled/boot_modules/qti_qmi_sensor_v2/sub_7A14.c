void sub_7A14()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x21
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v2 = _kmalloc_cache_noprof(qmi_response_type_v01_ei, 3520, 3180);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x79D4);
  JUMPOUT(0x778C);
}
