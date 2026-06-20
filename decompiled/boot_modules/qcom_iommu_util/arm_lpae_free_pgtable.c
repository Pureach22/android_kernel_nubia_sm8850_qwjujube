__int64 __fastcall arm_lpae_free_pgtable(__int64 a1)
{
  _arm_lpae_free_pgtable(a1, *(unsigned int *)(a1 + 204), *(_QWORD *)(a1 + 216), 0);
  qcom_io_pgtable_allocator_unregister(*(unsigned int *)(a1 + 224));
  return kfree(a1);
}
