__int64 __fastcall csr_scan_result_get_first(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 result; // x0

  if ( !a2 )
    return 0;
  v3 = csr_ll_peek_head(a2, 0);
  v4 = v3;
  if ( v3 )
    result = v3 + 32;
  else
    result = 0;
  *(_QWORD *)(a2 + 88) = v4;
  return result;
}
