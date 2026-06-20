__int64 __fastcall hdd_store_sar_config(__int64 result, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x19

  v2 = *(_QWORD *)(result + 3848);
  v3 = result;
  if ( v2 )
  {
    *(_QWORD *)(result + 3848) = 0;
    _qdf_mem_free(*(_QWORD *)(v2 + 16));
    result = _qdf_mem_free(v2);
  }
  *(_QWORD *)(v3 + 3848) = a2;
  return result;
}
