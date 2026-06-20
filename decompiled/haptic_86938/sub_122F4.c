void sub_122F4()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x23
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _arch_copy_from_user;
  *(_QWORD *)(StatusReg + 80) = &audio_ctrl_list_ins__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 24);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x120CC);
  JUMPOUT(0x12078);
}
