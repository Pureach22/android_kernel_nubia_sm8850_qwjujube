__int64 __fastcall dp_tx_mon_free_last_mpdu_q(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 *v7; // x11
  __int64 v8; // x9
  __int64 **v9; // x10
  unsigned int i; // w9
  __int64 *v11; // x11
  __int64 v12; // x12

  v3 = a2 + 344LL * a3;
  v4 = v3 + 696;
  if ( v3 == -696 )
    return result;
  v5 = *(_QWORD *)v4;
  if ( !*(_QWORD *)v4 )
    return result;
  v6 = *(_QWORD *)(v4 + 8);
  --*(_DWORD *)(v4 + 16);
  if ( v5 == v6 )
  {
    *(_QWORD *)v4 = 0;
    *(_QWORD *)(v4 + 8) = 0;
  }
  else
  {
    do
    {
      v7 = (__int64 *)v5;
      v5 = *(_QWORD *)v5;
    }
    while ( v6 != v5 );
    *(_QWORD *)(v4 + 8) = v7;
    v5 = *v7;
    if ( !*v7 )
      return result;
  }
  v8 = *(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212);
  v9 = *(__int64 ***)(v8 + 8);
  for ( i = *(unsigned __int8 *)(v8 + 2); v9; i += *((unsigned __int8 *)v11 + v12 + 2) )
  {
    v11 = v9[27];
    v12 = *((unsigned int *)v9 + 53);
    v9 = (__int64 **)*v9;
  }
  *(_QWORD *)(result + 200) += i;
  return _qdf_nbuf_free(v5);
}
