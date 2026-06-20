void sub_9768()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = gen_pool_alloc_algo_owner;
  *(_QWORD *)(StatusReg + 80) = &qcom_dma_common_pages_remap__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 40);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x9708);
  JUMPOUT(0x9684);
}
