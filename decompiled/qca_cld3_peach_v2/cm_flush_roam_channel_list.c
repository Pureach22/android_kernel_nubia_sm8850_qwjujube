__int64 __fastcall cm_flush_roam_channel_list(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 8);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 8) = 0;
    *(_BYTE *)a1 = 0;
  }
  return result;
}
