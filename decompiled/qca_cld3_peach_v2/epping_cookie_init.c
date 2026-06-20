__int64 __fastcall epping_cookie_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x20
  __int64 v8; // x20
  __int64 i; // x21
  __int64 v10; // x20
  __int64 j; // x21
  __int64 v12; // x20
  __int64 k; // x21
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0

  *(_QWORD *)(a1 + 408) = 0;
  *(_DWORD *)(a1 + 416) = 0;
  v2 = _qdf_mem_malloc(0xF000u, "epping_cookie_init", 55);
  *(_QWORD *)(a1 + 424) = v2;
  if ( v2 )
  {
    v3 = _qdf_mem_malloc(0xF000u, "epping_cookie_init", 55);
    *(_QWORD *)(a1 + 432) = v3;
    if ( v3 )
    {
      v4 = _qdf_mem_malloc(0xF000u, "epping_cookie_init", 55);
      *(_QWORD *)(a1 + 440) = v4;
      if ( v4 )
      {
        v5 = _qdf_mem_malloc(0xF000u, "epping_cookie_init", 55);
        *(_QWORD *)(a1 + 448) = v5;
        if ( v5 )
        {
          v6 = *(_QWORD *)(a1 + 424);
          v7 = 0;
          *(_DWORD *)(a1 + 456) = 0;
          *(_QWORD *)(a1 + 464) = 0;
          do
          {
            epping_free_cookie(a1, v6 + v7);
            v7 += 120;
          }
          while ( v7 != 61440 );
          v8 = *(_QWORD *)(a1 + 432);
          for ( i = 0; i != 61440; i += 120 )
            epping_free_cookie(a1, v8 + i);
          v10 = *(_QWORD *)(a1 + 440);
          for ( j = 0; j != 61440; j += 120 )
            epping_free_cookie(a1, v10 + j);
          v12 = *(_QWORD *)(a1 + 448);
          for ( k = 0; k != 61440; k += 120 )
            epping_free_cookie(a1, v12 + k);
          return 0;
        }
      }
    }
    v15 = *(_QWORD *)(a1 + 424);
    if ( v15 )
    {
      _qdf_mem_free(v15);
      *(_QWORD *)(a1 + 424) = 0;
    }
  }
  v16 = *(_QWORD *)(a1 + 432);
  if ( v16 )
  {
    _qdf_mem_free(v16);
    *(_QWORD *)(a1 + 432) = 0;
  }
  v17 = *(_QWORD *)(a1 + 440);
  if ( v17 )
  {
    _qdf_mem_free(v17);
    *(_QWORD *)(a1 + 440) = 0;
  }
  v18 = *(_QWORD *)(a1 + 448);
  if ( v18 )
  {
    _qdf_mem_free(v18);
    *(_QWORD *)(a1 + 448) = 0;
  }
  return 4294967284LL;
}
