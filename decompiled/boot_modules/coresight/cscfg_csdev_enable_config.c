__int64 __fastcall cscfg_csdev_enable_config(_DWORD *a1, int a2)
{
  __int64 v3; // x13
  int v5; // w11
  __int64 i; // x8
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x12
  __int64 v10; // x13
  __int64 v11; // x14
  int v12; // w10
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x12
  __int64 v16; // x14
  int v17; // w15
  __int64 v18; // x11
  __int64 v19; // x15
  __int64 v20; // x17
  __int64 v21; // x16
  __int64 v22; // x20
  __int64 v23; // x22
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x11
  __int64 v27; // x12
  int v28; // w13
  _QWORD *v29; // x10
  int v30; // w12

  if ( a2 )
  {
    if ( a2 < 1 )
      return 4294967274LL;
    v3 = *(_QWORD *)a1;
    if ( *(_DWORD *)(*(_QWORD *)a1 + 48LL) < a2 )
      return 4294967274LL;
    v5 = a1[10];
    if ( v5 >= 1 )
    {
      v12 = *(_DWORD *)(v3 + 52);
      v13 = 0;
      v14 = 0;
      v15 = *(_QWORD *)(v3 + 56) + 8LL * v12 * (a2 - 1);
      do
      {
        v16 = *(_QWORD *)&a1[2 * v13 + 12];
        v17 = *(_DWORD *)(v16 + 40);
        if ( v17 )
        {
          if ( v17 >= 1 )
          {
            v18 = 0;
            v19 = 0;
            do
            {
              v20 = *(_QWORD *)(v16 + 48) + v18;
              v21 = *(_QWORD *)(v15 + 8LL * (v14 + (int)v19));
              if ( *(_BYTE *)(v20 + 24) == 1 )
                *(_QWORD *)(*(_QWORD *)(v20 + 8) + 8LL) = v21;
              else
                *(_DWORD *)(*(_QWORD *)(v20 + 8) + 8LL) = v21;
              ++v19;
              v18 += 32;
            }
            while ( v19 < *(int *)(v16 + 40) );
            v5 = a1[10];
            v14 += v19;
          }
          if ( v14 >= v12 )
            break;
        }
        ++v13;
      }
      while ( v13 < v5 );
LABEL_27:
      if ( v5 >= 1 )
      {
        v22 = 0;
        do
        {
          v23 = *(_QWORD *)&a1[2 * v22 + 12];
          raw_spin_lock_irqsave(*(_QWORD *)(v23 + 32));
          if ( *(int *)(v23 + 56) >= 1 )
          {
            v24 = 0;
            v25 = 0;
            do
            {
              v26 = *(_QWORD *)(v23 + 64);
              v27 = v26 + v24;
              v28 = *(_DWORD *)(v26 + v24);
              v29 = *(_QWORD **)(v26 + v24 + 16);
              if ( (v28 & 2) != 0 )
              {
                *v29 = *(_QWORD *)(v27 + 8);
              }
              else
              {
                v30 = *(_DWORD *)(v27 + 8);
                if ( (v28 & 4) != 0 )
                  v30 = *(_DWORD *)v29 & ~*(_DWORD *)(v26 + v24 + 12) | *(_DWORD *)(v26 + v24 + 12) & v30;
                *(_DWORD *)v29 = v30;
              }
              ++v25;
              v24 += 24;
            }
            while ( v25 < *(int *)(v23 + 56) );
          }
          raw_spin_unlock_irqrestore(*(_QWORD *)(v23 + 32));
          ++v22;
        }
        while ( v22 < (int)a1[10] );
      }
    }
  }
  else
  {
    v5 = a1[10];
    if ( v5 >= 1 )
    {
      for ( i = 0; i < v5; ++i )
      {
        v7 = *(_QWORD *)&a1[2 * i + 12];
        if ( *(int *)(v7 + 40) >= 1 )
        {
          v8 = 0;
          v9 = 0;
          do
          {
            v10 = *(_QWORD *)(v7 + 48) + v8;
            v11 = *(_QWORD *)(v10 + 16);
            if ( *(_BYTE *)(v10 + 24) == 1 )
              *(_QWORD *)(*(_QWORD *)(v10 + 8) + 8LL) = v11;
            else
              *(_DWORD *)(*(_QWORD *)(v10 + 8) + 8LL) = v11;
            ++v9;
            v8 += 32;
          }
          while ( v9 < *(int *)(v7 + 40) );
          v5 = a1[10];
        }
      }
      goto LABEL_27;
    }
  }
  return 0;
}
