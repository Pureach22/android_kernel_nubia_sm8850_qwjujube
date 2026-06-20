__int64 sub_FBC8()
{
  unsigned __int64 *v0; // x27

  atomic_load(v0);
  return arm_32_lpae_alloc_pgtable_s2();
}
