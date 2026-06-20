__int64 __fastcall cm_free_join_req(__int64 result)
{
  __int64 v1; // x20
  _QWORD *v2; // x19
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  if ( result )
  {
    v1 = *(_QWORD *)(result + 48);
    v2 = (_QWORD *)result;
    if ( v1 )
    {
      v3 = *(_QWORD *)(v1 + 1320);
      if ( v3 )
        _qdf_mem_free(v3);
      v4 = *(_QWORD *)(v1 + 1896);
      if ( v4 )
        _qdf_mem_free(v4);
      _qdf_mem_free(v1);
    }
    v5 = v2[3];
    v2[6] = 0;
    _qdf_mem_free(v5);
    _qdf_mem_free(v2[5]);
    v2[3] = 0;
    v2[5] = 0;
    return _qdf_mem_free((__int64)v2);
  }
  return result;
}
