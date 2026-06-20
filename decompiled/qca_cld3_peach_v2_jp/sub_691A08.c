__int64 sub_691A08()
{
  __int64 v0; // x13

  atomic_load_explicit((atomic_uint *volatile)(v0 - 148), memory_order_acquire);
  return wlan_dp_resource_mgr_phymode_update();
}
