__int64 rmnet_ll_wq_exit()
{
  __int64 v0; // x19

  raw_spin_lock_bh(&ll_wq_lock);
  v0 = ll_wq;
  if ( !ll_wq )
    return raw_spin_unlock_bh(&ll_wq_lock);
  ll_wq = 0;
  raw_spin_unlock_bh(&ll_wq_lock);
  return destroy_workqueue(v0);
}
