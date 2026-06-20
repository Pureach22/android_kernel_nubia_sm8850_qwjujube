__int64 ipa3_free_dma_task_for_gsi()
{
  __int64 result; // x0
  _QWORD *v1; // x8

  dma_free_attrs(
    *(_QWORD *)(ipa3_ctx + 34216),
    *(unsigned int *)(ipa3_ctx + 43784),
    *(_QWORD *)(ipa3_ctx + 43768),
    *(_QWORD *)(ipa3_ctx + 43776),
    0);
  result = kfree(*(_QWORD *)(ipa3_ctx + 43792));
  v1 = (_QWORD *)(ipa3_ctx + 43768);
  *(_QWORD *)(ipa3_ctx + 43768) = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}
