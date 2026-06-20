void sub_12884()
{
  unsigned __int64 StatusReg; // x27
  __int64 v1; // x28
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &drm_dp_send_up_ack_reply__alloc_tag;
  v2 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x11FE4);
  JUMPOUT(0x11FA8);
}
