__int64 sub_73C660()
{
  __int64 v0; // x25

  atomic_load_explicit((atomic_ullong *volatile)(v0 - 157), memory_order_acquire);
  return wmi_unified_update_fw_tdls_state_cmd();
}
