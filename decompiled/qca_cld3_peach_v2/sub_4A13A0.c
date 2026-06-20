__int64 sub_4A13A0()
{
  __int64 v0; // x17

  atomic_load_explicit((atomic_ullong *volatile)(v0 - 8), memory_order_acquire);
  return csr_convert_cb_ini_value_to_phy_cb_state();
}
