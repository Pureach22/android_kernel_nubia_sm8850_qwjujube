_QWORD *__fastcall mlo_clear_connected_links_bmap(_QWORD *result)
{
  __int64 v1; // x8
  __int64 v2; // x8

  if ( result )
  {
    v1 = result[170];
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 2224);
      if ( v2 )
        return qdf_mem_set((void *)(v2 + 8), 8u, 0);
    }
  }
  return result;
}
