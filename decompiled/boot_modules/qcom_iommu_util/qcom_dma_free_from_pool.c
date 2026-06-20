__int64 __fastcall qcom_dma_free_from_pool(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  result = atomic_pool;
  if ( atomic_pool )
  {
    if ( (gen_pool_has_addr() & 1) != 0 )
    {
      gen_pool_free_owner(atomic_pool, a2, a3, 0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
