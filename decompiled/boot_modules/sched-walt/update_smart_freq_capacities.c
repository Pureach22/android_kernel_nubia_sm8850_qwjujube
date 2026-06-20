__int64 update_smart_freq_capacities()
{
  __int64 *i; // x20
  __int64 result; // x0

  if ( smart_freq_init_done == 1 )
  {
    for ( i = (__int64 *)cluster_head; i != &cluster_head; i = (__int64 *)*i )
      result = ((__int64 (__fastcall *)(__int64 *))update_smart_freq_capacities_one_cluster)(i - 1);
  }
  return result;
}
