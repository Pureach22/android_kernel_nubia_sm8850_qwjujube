__int64 __usercall sub_F7BC@<X0>(unsigned __int64 a1@<X0>, atomic_ullong *a2@<X8>)
{
  atomic_fetch_add_explicit(a2, a1, memory_order_release);
  return hw_fence_update_queue_payload(a1);
}
