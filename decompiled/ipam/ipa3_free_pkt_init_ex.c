__int64 ipa3_free_pkt_init_ex()
{
  return dma_free_attrs(
           *(_QWORD *)(ipa3_ctx + 34216),
           *(unsigned int *)(ipa3_ctx + 50200),
           *(_QWORD *)(ipa3_ctx + 50184),
           *(_QWORD *)(ipa3_ctx + 50192),
           0);
}
