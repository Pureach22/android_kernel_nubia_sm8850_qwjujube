void sub_15448()
{
  unsigned __int64 StatusReg; // x25
  __int64 v1; // x26
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &drm_dp_send_clear_payload_id_table__alloc_tag;
  v2 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 768);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x153BC);
  JUMPOUT(0x15320);
}
