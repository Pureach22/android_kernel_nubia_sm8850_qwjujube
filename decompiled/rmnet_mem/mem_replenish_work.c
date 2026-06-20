__int64 mem_replenish_work()
{
  unsigned __int64 StatusReg; // x8
  __int64 v1; // x20
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  v1 = raw_spin_lock_irqsave(&rmnet_mem_lock);
  rmnet_mem_cache_add(0, 1);
  rmnet_mem_cache_add(1, 1);
  rmnet_mem_cache_add(2, 1);
  rmnet_mem_cache_add(3, 1);
  v2 = raw_spin_unlock_irqrestore(&rmnet_mem_lock, v1);
  return local_bh_enable(v2);
}
