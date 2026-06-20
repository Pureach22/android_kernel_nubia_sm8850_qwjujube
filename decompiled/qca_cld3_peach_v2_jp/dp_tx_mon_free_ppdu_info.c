__int64 __fastcall dp_tx_mon_free_ppdu_info(__int64 a1, __int64 a2)
{
  int v2; // w8
  unsigned __int64 v5; // x21
  unsigned int v6; // w25
  __int64 v7; // x9
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 **v15; // x9
  int i; // w8
  __int64 *v17; // x10
  __int64 v18; // x11

  v2 = *(_DWORD *)(a1 + 28);
  if ( (_BYTE)v2 )
  {
    v5 = 0;
    do
    {
      v7 = a1 + 384 + 344 * v5;
      v8 = v7 + 312;
      if ( v7 != -312 )
      {
        v9 = *(_QWORD *)v8;
        if ( *(_QWORD *)v8 )
        {
          v6 = 0;
          do
          {
            v10 = *(_QWORD *)(v8 + 8);
            --*(_DWORD *)(v8 + 16);
            if ( v9 == v10 )
            {
              v11 = 0;
              *(_QWORD *)(v8 + 8) = 0;
            }
            else
            {
              v11 = *(_QWORD *)v9;
            }
            *(_QWORD *)v8 = v11;
            v12 = *(_QWORD *)(v9 + 216);
            v13 = *(unsigned int *)(v9 + 212);
            *(_QWORD *)v9 = 0;
            v14 = v12 + v13;
            v15 = *(__int64 ***)(v14 + 8);
            for ( i = *(unsigned __int8 *)(v14 + 2); v15; i += *((unsigned __int8 *)v17 + v18 + 2) )
            {
              v17 = v15[27];
              v18 = *((unsigned int *)v15 + 53);
              v15 = (__int64 **)*v15;
            }
            v6 += i;
            _qdf_nbuf_free(v9);
            v9 = *(_QWORD *)v8;
          }
          while ( *(_QWORD *)v8 );
        }
        else
        {
          v6 = 0;
        }
        *(_QWORD *)(a2 + 184) += v6;
        v2 = *(_DWORD *)(a1 + 28);
      }
      ++v5;
    }
    while ( v5 < (unsigned __int8)v2 );
  }
  *(_DWORD *)(a1 + 28) = v2 & 0xFFFFFEFF;
  return _qdf_mem_free(a1);
}
