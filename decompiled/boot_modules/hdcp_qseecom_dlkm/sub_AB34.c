void sub_AB34()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 (__fastcall *v3)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = qseecom_send_command;
  *(_QWORD *)(StatusReg + 80) = &hdcp2_app_start_smcinvoke__alloc_tag_36;
  v4 = _kmalloc_cache_noprof(v3, 3264, 129);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 24) = v4;
  if ( !v4 )
    JUMPOUT(0xAA7C);
  JUMPOUT(0xA9E0);
}
