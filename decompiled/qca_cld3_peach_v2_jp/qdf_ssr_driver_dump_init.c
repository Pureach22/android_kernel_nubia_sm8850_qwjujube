__int64 qdf_ssr_driver_dump_init()
{
  __int64 result; // x0

  result = qdf_mutex_create((__int64)&region_list_mutex);
  if ( !(_DWORD)result )
  {
    num_of_regions_registered = 0;
    qdf_mem_set(&dump_entry_list, 0x1560u, 0);
    return 0;
  }
  return result;
}
