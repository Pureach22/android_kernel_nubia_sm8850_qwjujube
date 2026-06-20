bool __fastcall _qdf_page_pool_full_bh(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x11
  int v5; // w12
  _BOOL4 v7; // w19
  int v8; // w12
  int v9; // w13
  __int64 *v10; // x14
  __int64 v11; // x15
  __int64 v12; // x16
  __int64 v13; // x17
  _QWORD *v14; // x10
  __int64 v15; // x11

  v1 = *(_DWORD *)(a1 + 256);
  if ( v1 )
  {
    v2 = *(unsigned int *)(a1 + 1472);
    if ( (int)v2 < 1 )
    {
      v5 = 0;
    }
    else
    {
      v3 = *(_QWORD *)(a1 + 1480);
      if ( (_DWORD)v2 == 1 )
      {
        v4 = 0;
        v5 = 0;
      }
      else
      {
        v4 = v2 & 0x7FFFFFFE;
        v8 = 0;
        v9 = 0;
        v10 = (__int64 *)(v3 + 8);
        v11 = v4;
        do
        {
          v12 = *(v10 - 1);
          v13 = *v10;
          v10 += 2;
          if ( v12 )
            ++v8;
          if ( v13 )
            ++v9;
          v11 -= 2;
        }
        while ( v11 );
        v5 = v9 + v8;
        if ( v4 == v2 )
          return (_DWORD)v2 - v5 == v1;
      }
      v14 = (_QWORD *)(v3 + 8 * v4);
      v15 = v2 - v4;
      do
      {
        if ( *v14++ )
          ++v5;
        --v15;
      }
      while ( v15 );
    }
    return (_DWORD)v2 - v5 == v1;
  }
  raw_spin_lock_bh(a1 + 1348);
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 1480) + 8LL * *(int *)(a1 + 1344)) != 0;
  raw_spin_unlock_bh(a1 + 1348);
  return v7;
}
