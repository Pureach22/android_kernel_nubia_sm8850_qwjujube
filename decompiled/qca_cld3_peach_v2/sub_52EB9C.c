__int64 sub_52EB9C()
{
  __int64 v0; // x21

  return dp_peer_state_update(atomic_load_explicit((atomic_uint *volatile)(v0 - 112), memory_order_acquire));
}
