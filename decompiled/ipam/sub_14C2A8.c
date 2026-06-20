void sub_14C2A8()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_wwan_init__alloc_tag;
  _kmalloc_cache_noprof(dma_alloc_attrs, 3520, 2112);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x14BC6C);
}
