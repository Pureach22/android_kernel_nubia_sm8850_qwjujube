__int64 md_smem_get_available_region()
{
  __int64 v0; // x0
  unsigned int v1; // w20

  v0 = raw_spin_lock_irqsave(&mdt_lock);
  v1 = 201 - md_num_regions;
  raw_spin_unlock_irqrestore(&mdt_lock, v0);
  return v1;
}
