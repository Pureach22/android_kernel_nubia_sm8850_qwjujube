__int64 __fastcall crm_write_perf_ol(__int64 a1, int a2, int a3, _DWORD *a4)
{
  __int64 v4; // x19
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x8
  _DWORD *i; // x20
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  v4 = *(_QWORD *)(a1 + 152);
  v5 = 72;
  if ( !a2 )
    v5 = 48;
  v6 = 64;
  v7 = *(unsigned int *)(v4 + v5);
  if ( !a2 )
    v6 = 40;
  if ( (int)v7 < 1 )
    return 4294967274LL;
  for ( i = *(_DWORD **)(v4 + v6); i[8] != a3; i += 48 )
  {
    if ( !--v7 )
      return 4294967274LL;
  }
  result = 4294967274LL;
  if ( a4 && i && *a4 < i[14] && a4[1] < i[15] && a4[2] <= 7u )
  {
    crm_cache_vcd_votes(i, 0, a4);
    result = 0;
    if ( a2 == 1 )
    {
      crm_send_cmd(v4, i, 0, a4, 0);
      return 0;
    }
  }
  return result;
}
