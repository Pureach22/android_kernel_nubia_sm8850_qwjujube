void sub_50024()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 (__fastcall *v3)(_QWORD); // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = wake_up_process;
  *(_QWORD *)(StatusReg + 80) = &sde_hdcp_1x_init__alloc_tag_5;
  v4 = _kmalloc_cache_noprof(v3, 3520, 24);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 1440) = v4;
  if ( !v4 )
    JUMPOUT(0x4FFA4);
  JUMPOUT(0x4FD7C);
}
