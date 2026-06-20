__int64 ipa3_free_pkt_init()
{
  return dma_free_attrs(
           *(_QWORD *)(ipa3_ctx + 34216),
           *(unsigned int *)(ipa3_ctx + 50176),
           *(_QWORD *)(ipa3_ctx + 50160),
           *(_QWORD *)(ipa3_ctx + 50168),
           0);
}
