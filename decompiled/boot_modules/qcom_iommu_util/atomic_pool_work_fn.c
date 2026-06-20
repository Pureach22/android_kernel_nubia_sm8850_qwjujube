void atomic_pool_work_fn()
{
  __int64 v0; // x19
  __int64 v1; // x0

  v0 = atomic_pool;
  if ( atomic_pool )
  {
    if ( gen_pool_avail(atomic_pool) < (unsigned __int64)atomic_pool_size )
    {
      v1 = gen_pool_size(v0);
      atomic_pool_expand(v0, v1, 3264);
    }
  }
}
