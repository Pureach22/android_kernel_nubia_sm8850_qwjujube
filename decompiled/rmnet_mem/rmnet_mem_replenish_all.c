__int64 rmnet_mem_replenish_all()
{
  __int64 v0; // x20

  v0 = raw_spin_lock_irqsave(&rmnet_mem_lock);
  rmnet_mem_cache_add(0, 1);
  rmnet_mem_cache_add(1, 1);
  rmnet_mem_cache_add(2, 1);
  rmnet_mem_cache_add(3, 1);
  return raw_spin_unlock_irqrestore(&rmnet_mem_lock, v0);
}
