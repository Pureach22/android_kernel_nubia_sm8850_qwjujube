__int64 freelist_shrink_count()
{
  __int64 v0; // x0
  __int64 v1; // x20

  v0 = raw_spin_lock_irqsave(&free_list_lock);
  v1 = list_nr_pages;
  raw_spin_unlock_irqrestore(&free_list_lock, v0);
  return v1;
}
