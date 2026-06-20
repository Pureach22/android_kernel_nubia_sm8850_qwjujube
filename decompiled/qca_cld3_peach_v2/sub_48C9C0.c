__int64 sub_48C9C0()
{
  __int64 v0; // x17

  atomic_load_explicit((atomic_ullong *volatile)(v0 - 8), memory_order_acquire);
  return sme_get_cb_phy_state_from_cb_ini_value();
}
