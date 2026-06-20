__int64 rmnet_offload_unlock()
{
  return raw_spin_unlock_bh(&rmnet_offload_main_lock);
}
