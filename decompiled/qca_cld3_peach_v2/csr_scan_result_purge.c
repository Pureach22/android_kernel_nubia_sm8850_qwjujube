__int64 __fastcall csr_scan_result_purge(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x20

  if ( !a2 )
    return 4;
  while ( 1 )
  {
    v3 = csr_ll_remove_head(a2, 0);
    if ( !v3 )
      break;
    if ( *(_QWORD *)(v3 + 32) )
    {
      v4 = v3;
      _qdf_mem_free(*(_QWORD *)(v3 + 32));
      v3 = v4;
    }
    _qdf_mem_free(v3);
  }
  csr_ll_close(a2);
  _qdf_mem_free(a2);
  return 0;
}
