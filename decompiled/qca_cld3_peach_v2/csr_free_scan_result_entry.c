__int64 __fastcall csr_free_scan_result_entry(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a2 + 32);
  if ( v2 )
    _qdf_mem_free(v2);
  return _qdf_mem_free(a2);
}
