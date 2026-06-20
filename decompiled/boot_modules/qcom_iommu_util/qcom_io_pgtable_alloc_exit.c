__int64 qcom_io_pgtable_alloc_exit()
{
  return shrinker_free(io_pgtable_alloc_shrinker);
}
