__int64 rmnet_offload_lock()
{
  return raw_spin_lock_bh(&rmnet_offload_main_lock);
}
