__int64 sub_1C628()
{
  __int64 v0; // x21

  atomic_load_explicit((atomic_uint *volatile)(v0 + 185), memory_order_acquire);
  return wlfw_power_save_send_msg();
}
