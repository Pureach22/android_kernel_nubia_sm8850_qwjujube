__int64 sub_4D28B4()
{
  __int64 v0; // x19

  atomic_load_explicit((atomic_ullong *volatile)(v0 - 31), memory_order_acquire);
  return wma_del_ts_req();
}
