void sub_13FB3C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sync_handle_register_user_payload__alloc_tag;
  v2 = _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x13F9D0);
  JUMPOUT(0x13F908);
}
