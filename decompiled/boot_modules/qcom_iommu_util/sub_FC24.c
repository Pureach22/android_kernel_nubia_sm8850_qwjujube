__int64 sub_FC24()
{
  unsigned __int64 *v0; // x27

  atomic_load(v0);
  return arm_mali_lpae_alloc_pgtable();
}
