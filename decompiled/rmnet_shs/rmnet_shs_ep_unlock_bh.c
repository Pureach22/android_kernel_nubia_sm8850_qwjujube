__int64 rmnet_shs_ep_unlock_bh()
{
  return raw_spin_unlock_bh(&rmnet_shs_ep_lock);
}
