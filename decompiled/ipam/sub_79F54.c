void sub_79F54()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_active_clients_log_init__alloc_tag_1323;
  _kmalloc_cache_noprof(dma_alloc_attrs, 3520, 4096);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x77C7C);
}
