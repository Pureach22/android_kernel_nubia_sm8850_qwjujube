__int64 __fastcall csr_scan_result_get_next(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v5; // x8

  if ( !a2 )
    return 0;
  if ( *(_QWORD *)(a2 + 88) )
    v3 = csr_ll_next(a2);
  else
    v3 = csr_ll_peek_head(a2, 0);
  v5 = v3 + 32;
  if ( !v3 )
    v5 = 0;
  *(_QWORD *)(a2 + 88) = v3;
  return v5;
}
