__int64 gh_rm_heap_get_total_heap_added()
{
  if ( rm_heap_manager_enabled == 1 )
    return *(_QWORD *)(rm_heap_manager + 32) + *(_QWORD *)(rm_heap_manager + 24);
  else
    return 0;
}
