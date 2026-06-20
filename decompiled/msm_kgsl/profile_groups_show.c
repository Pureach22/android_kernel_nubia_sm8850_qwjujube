__int64 __fastcall profile_groups_show(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x23
  unsigned int i; // w24
  int v5; // w4
  __int64 v6; // x8
  int v7; // w3
  signed int v8; // w10
  int v9; // w11
  int v10; // w12
  unsigned int v11; // w13
  int *v12; // x14
  int v13; // w15
  int v14; // w16
  __int64 v15; // x11

  v1 = *(_QWORD *)(a1 + 128);
  v3 = *(_QWORD *)(*(_QWORD *)(v1 + 14264) + 48LL);
  rt_mutex_lock(v1 + 11088);
  if ( *(_DWORD *)(v3 + 8) )
  {
    for ( i = 0; i < *(_DWORD *)(v3 + 8); ++i )
    {
      v6 = *(_QWORD *)v3 + 56LL * (int)i;
      v7 = *(_DWORD *)(v6 + 8);
      if ( v7 )
      {
        if ( (unsigned int)(v7 + 0x7FFFFFFF) >= 0x80000001 )
        {
          v8 = v7 & 0xFFFFFFFE;
          v9 = 0;
          v10 = 0;
          v11 = v7 & 0xFFFFFFFE;
          v12 = *(int **)v6;
          do
          {
            v13 = *v12;
            v14 = v12[12];
            v12 += 24;
            if ( v13 != -1 )
              ++v9;
            if ( v14 != -1 )
              ++v10;
            v11 -= 2;
          }
          while ( v11 );
          v5 = v10 + v9;
          if ( v7 == v8 )
            goto LABEL_4;
        }
        else
        {
          v5 = 0;
          v8 = 0;
        }
        do
        {
          v15 = 48LL * v8++;
          if ( *(_DWORD *)(*(_QWORD *)v6 + v15) != -1 )
            ++v5;
        }
        while ( v7 != v8 );
      }
      else
      {
        v5 = 0;
      }
LABEL_4:
      seq_printf(a1, "%s %d %d\n", *(const char **)(v6 + 16), v7, v5);
    }
  }
  rt_mutex_unlock(v1 + 11088);
  return 0;
}
