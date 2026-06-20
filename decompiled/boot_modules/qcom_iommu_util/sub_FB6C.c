__int64 sub_FB6C()
{
  unsigned __int64 *v0; // x27

  atomic_load(v0);
  return arm_32_lpae_alloc_pgtable_s1();
}
