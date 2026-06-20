__int64 __fastcall crm_restore_noirq(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v4; // x23
  unsigned int v5; // w24
  unsigned int v6; // w24
  unsigned int v7; // w24
  _BYTE *v8; // x8
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x20
  __int64 v12; // x21

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(int *)(v1 + 72) >= 1 )
  {
    v2 = *(_QWORD *)(v1 + 64);
    v3 = 0;
    do
    {
      v4 = v2 + 192 * v3;
      if ( *(_DWORD *)(v4 + 60) )
      {
        v5 = 0;
        do
          writel_relaxed(
            1u,
            (unsigned int *)(*(_QWORD *)(v4 + 24)
                           + **(_DWORD **)(v4 + 64)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 64) + 4LL) * *(_DWORD *)(v4 + 32)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 64) + 44LL)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 64) + 8LL) * v5++));
        while ( v5 < *(_DWORD *)(v4 + 60) );
      }
      if ( *(_DWORD *)(v4 + 100) )
      {
        v6 = 0;
        do
          writel_relaxed(
            1u,
            (unsigned int *)(*(_QWORD *)(v4 + 24)
                           + **(_DWORD **)(v4 + 104)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 104) + 4LL) * *(_DWORD *)(v4 + 32)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 104) + 44LL)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 104) + 8LL) * v6++));
        while ( v6 < *(_DWORD *)(v4 + 100) );
      }
      if ( *(_DWORD *)(v4 + 140) )
      {
        v7 = 0;
        do
          writel_relaxed(
            1u,
            (unsigned int *)(*(_QWORD *)(v4 + 24)
                           + **(_DWORD **)(v4 + 144)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 144) + 4LL) * *(_DWORD *)(v4 + 32)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 144) + 44LL)
                           + *(_DWORD *)(*(_QWORD *)(v4 + 144) + 8LL) * v7++));
        while ( v7 < *(_DWORD *)(v4 + 140) );
      }
      ++v3;
    }
    while ( v3 < *(int *)(v1 + 72) );
  }
  v8 = *(_BYTE **)(v1 + 288);
  if ( *v8 == 1 && *(int *)(v1 + 48) >= 1 )
  {
    v9 = 0;
    v10 = 0;
    do
    {
      writel_relaxed(
        1u,
        (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v9 + 24)
                       + (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v9 + 40) + 8LL)
                                      + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v9 + 40) + 12LL)
                                      * *(_DWORD *)(*(_QWORD *)(v1 + 40) + v9 + 32))));
      ++v10;
      v9 += 192;
    }
    while ( v10 < *(int *)(v1 + 48) );
    v8 = *(_BYTE **)(v1 + 288);
  }
  if ( v8[1] == 1 && *(int *)(v1 + 48) >= 1 )
  {
    v11 = 0;
    v12 = 0;
    do
    {
      writel_relaxed(
        2u,
        (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v11 + 24)
                       + (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v11 + 40) + 8LL)
                                      + *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 40) + v11 + 40) + 12LL)
                                      * *(_DWORD *)(*(_QWORD *)(v1 + 40) + v11 + 32))));
      ++v12;
      v11 += 192;
    }
    while ( v12 < *(int *)(v1 + 48) );
  }
  return 0;
}
