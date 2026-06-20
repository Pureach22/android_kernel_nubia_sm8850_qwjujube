__int64 rmnet_ll_wq_init()
{
  __int64 result; // x0

  if ( ll_wq )
    __break(0x800u);
  result = alloc_workqueue("rmnet_ll_wq", 131074, 1);
  ll_wq = result;
  return result;
}
