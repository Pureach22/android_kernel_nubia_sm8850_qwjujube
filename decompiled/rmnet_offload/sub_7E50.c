void sub_7E50()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(_kcfi_typeid_rmnet_offload_handle_dl_header, 3520, 5312);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x7D24);
}
