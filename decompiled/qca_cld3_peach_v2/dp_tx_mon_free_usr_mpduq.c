__int64 __fastcall dp_tx_mon_free_usr_mpduq(__int64 result, unsigned __int8 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 **v12; // x9
  int i; // w8
  __int64 *v14; // x10
  __int64 v15; // x11

  if ( result )
  {
    v4 = result + 344LL * a2;
    result = *(_QWORD *)(v4 + 696);
    if ( result )
    {
      LODWORD(v5) = 0;
      v6 = v4 + 696;
      do
      {
        v7 = *(_QWORD *)(v6 + 8);
        --*(_DWORD *)(v6 + 16);
        if ( result == v7 )
        {
          v8 = 0;
          *(_QWORD *)(v6 + 8) = 0;
        }
        else
        {
          v8 = *(_QWORD *)result;
        }
        *(_QWORD *)v6 = v8;
        v9 = *(_QWORD *)(result + 216);
        v10 = *(unsigned int *)(result + 212);
        *(_QWORD *)result = 0;
        v11 = v9 + v10;
        v12 = *(__int64 ***)(v11 + 8);
        for ( i = *(unsigned __int8 *)(v11 + 2); v12; i += *((unsigned __int8 *)v14 + v15 + 2) )
        {
          v14 = v12[27];
          v15 = *((unsigned int *)v12 + 53);
          v12 = (__int64 **)*v12;
        }
        v5 = (unsigned int)(i + v5);
        _qdf_nbuf_free(result);
        result = *(_QWORD *)v6;
      }
      while ( *(_QWORD *)v6 );
    }
    else
    {
      v5 = 0;
    }
    *(_QWORD *)(a3 + 184) += v5;
  }
  return result;
}
