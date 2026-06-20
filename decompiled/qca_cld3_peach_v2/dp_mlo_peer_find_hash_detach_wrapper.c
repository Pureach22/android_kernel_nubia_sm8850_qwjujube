__int64 __fastcall dp_mlo_peer_find_hash_detach_wrapper(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 23448);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)(v1 + 23448) = 0;
    }
  }
  return result;
}
