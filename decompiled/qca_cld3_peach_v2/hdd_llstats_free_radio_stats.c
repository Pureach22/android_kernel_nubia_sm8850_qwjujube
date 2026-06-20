__int64 __fastcall hdd_llstats_free_radio_stats(__int64 result)
{
  __int64 v1; // x19

  v1 = result;
  if ( *(_DWORD *)(result + 48) )
  {
    result = *(_QWORD *)(result + 56);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)(v1 + 56) = 0;
    }
  }
  if ( *(_DWORD *)(v1 + 68) )
  {
    result = *(_QWORD *)(v1 + 72);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)(v1 + 72) = 0;
    }
  }
  return result;
}
