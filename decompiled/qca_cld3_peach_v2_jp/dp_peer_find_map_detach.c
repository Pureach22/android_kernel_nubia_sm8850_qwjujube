__int64 __fastcall dp_peer_find_map_detach(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  unsigned __int64 v11; // x8
  unsigned __int64 i; // x20
  __int64 v13; // x0

  result = *(_QWORD *)(a1 + 13088);
  if ( result )
  {
    v11 = *(unsigned int *)(a1 + 13276);
    if ( (_DWORD)v11 )
    {
      for ( i = 0; i < v11; ++i )
      {
        v13 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8 * i);
        if ( v13 )
        {
          dp_peer_unref_delete(v13, 0xCu, a2, a3, a4, a5, a6, a7, a8, a9);
          v11 = *(unsigned int *)(a1 + 13276);
        }
      }
      result = *(_QWORD *)(a1 + 13088);
    }
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 13088) = 0;
  }
  return result;
}
