__int64 __fastcall dcc_v2_restore(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v2; // w8
  _BYTE *v3; // x9
  int v4; // w19
  __int64 v5; // x8
  unsigned int v6; // w10
  unsigned __int64 v7; // x9
  __int64 v8; // x10
  unsigned int v9; // w10
  unsigned int v10; // w11
  unsigned int v11; // w8
  int v12; // w9
  _QWORD *v13; // x12
  unsigned int v14; // w12
  int v15; // w11
  unsigned int *v16; // x10
  int v17; // w10
  int v18; // w11
  __int64 v19; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
  {
    dev_err(a1, "Err: %s Invalid argument\n", "dcc_state_restore");
    return (unsigned int)-22;
  }
  v2 = *(_DWORD *)(v1 + 328);
  if ( !v2 )
    goto LABEL_28;
  v3 = *(_BYTE **)(v1 + 120);
  if ( (*v3 & 1) == 0 )
  {
    v17 = 1;
    while ( v2 != v17 )
    {
      v18 = (unsigned __int8)v3[v17++];
      if ( v18 == 1 )
      {
        if ( v17 - 1 < v2 )
          goto LABEL_4;
        break;
      }
    }
LABEL_28:
    v4 = 0;
    goto LABEL_29;
  }
LABEL_4:
  v4 = *(_DWORD *)(v1 + 356);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v1 + 368);
    if ( !v5 || !*(_QWORD *)(v1 + 360) )
    {
      dev_err(a1, "Err: Restore state is NULL\n");
      v4 = -22;
      goto LABEL_29;
    }
    v6 = *(_DWORD *)(v1 + 348);
    if ( v6 >= 4 )
    {
      v7 = 0;
      v8 = v6 & 0xFFFFFFFC;
      do
      {
        if ( v7 <= (unsigned int)(*(_DWORD *)(v1 + 80) - 4) )
          *(_DWORD *)(*(_QWORD *)(v1 + 72) + v7) = *(_DWORD *)(v5 + v7);
        v7 += 4LL;
      }
      while ( v8 != v7 );
    }
    mutex_lock(v1 + 24);
    if ( v4 >= 1 )
    {
      v9 = *(_DWORD *)(v1 + 328);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v1 + 352);
        v11 = 0;
        v12 = 0;
        do
        {
          v13 = (_QWORD *)(*(_QWORD *)(v1 + 312) + 16LL * (int)v11);
          if ( (_QWORD *)*v13 == v13 )
          {
            v12 += v10;
          }
          else if ( v10 )
          {
            v14 = 0;
            do
            {
              v15 = v12 + v14++;
              v16 = (unsigned int *)(*(_QWORD *)(v1 + 360) + 8LL * v15);
              *(_DWORD *)(*(_QWORD *)v1 + *v16) = v16[1];
              v10 = *(_DWORD *)(v1 + 352);
            }
            while ( v14 < v10 );
            v9 = *(_DWORD *)(v1 + 328);
            v12 += v14;
          }
          ++v11;
        }
        while ( v11 < v9 && v12 < v4 );
      }
    }
    mutex_unlock(v1 + 24);
    goto LABEL_28;
  }
LABEL_29:
  kfree(*(_QWORD *)(v1 + 368));
  v19 = *(_QWORD *)(v1 + 360);
  *(_QWORD *)(v1 + 368) = 0;
  kfree(v19);
  *(_QWORD *)(v1 + 360) = 0;
  return (unsigned int)v4;
}
