__int64 rmnet_shs_ep_lock_bh()
{
  return raw_spin_lock_bh(&rmnet_shs_ep_lock);
}
