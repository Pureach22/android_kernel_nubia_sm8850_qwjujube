void sub_143FC4()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &rmnet_ipa_get_stats_and_update__alloc_tag;
  v2 = _kmalloc_cache_noprof(dma_alloc_attrs, 3520, 2664);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x143EA4);
  JUMPOUT(0x143E58);
}
