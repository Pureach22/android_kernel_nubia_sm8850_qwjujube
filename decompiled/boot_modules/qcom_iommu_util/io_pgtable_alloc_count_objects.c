__int64 io_pgtable_alloc_count_objects()
{
  if ( page_pool_count )
    return page_pool_count;
  else
    return -2;
}
