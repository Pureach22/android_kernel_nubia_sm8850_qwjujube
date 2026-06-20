__int64 gh_rm_heap_shrink()
{
  __int64 v0; // x8
  _QWORD *v1; // x9
  _QWORD *v2; // x9
  __int64 result; // x0
  _QWORD *v4; // x20
  _QWORD *v5; // x20

  if ( rm_heap_manager_enabled == 1 )
  {
    gh_rm_remove_all_free_heap(0);
    gh_rm_remove_all_free_heap(1);
    mutex_lock(&rm_heap_lock);
    v0 = rm_heap_manager;
    v1 = *(_QWORD **)(rm_heap_manager + 40);
    if ( v1 != (_QWORD *)(rm_heap_manager + 40) )
    {
      do
      {
        v4 = (_QWORD *)*v1;
        if ( (*(_BYTE *)(v1 - 2) & 8) != 0 )
        {
          _remove_heap_parcel(v1 - 4, 0);
          v0 = rm_heap_manager;
        }
        v1 = v4;
      }
      while ( v4 != (_QWORD *)(v0 + 40) );
    }
    v2 = *(_QWORD **)(v0 + 56);
    if ( v2 != (_QWORD *)(v0 + 56) )
    {
      do
      {
        v5 = (_QWORD *)*v2;
        if ( (*(_BYTE *)(v2 - 2) & 8) != 0 )
        {
          _remove_heap_parcel(v2 - 4, 0);
          v0 = rm_heap_manager;
        }
        v2 = v5;
      }
      while ( v5 != (_QWORD *)(v0 + 56) );
    }
    return mutex_unlock(&rm_heap_lock);
  }
  return result;
}
