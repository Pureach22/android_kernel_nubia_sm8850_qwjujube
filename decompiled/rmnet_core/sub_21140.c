__int64 sub_21140()
{
  __int64 v0; // x23

  atomic_load_explicit((atomic_uint *volatile)(v0 - 180), memory_order_acquire);
  return rmnet_get_ethtool_stats();
}
