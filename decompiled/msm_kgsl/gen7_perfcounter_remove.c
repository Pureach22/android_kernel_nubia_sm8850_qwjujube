__int64 __fastcall gen7_perfcounter_remove(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x20
  int v4; // w9
  __int64 v5; // x19
  int v6; // w8
  unsigned int v7; // w24
  __int16 v8; // w23
  __int64 v10; // x22
  unsigned int v11; // w21
  int v12; // w8
  __int64 v13; // x11
  __int64 v14; // x25
  __int64 v15; // x26
  int v16; // w27
  unsigned int v17; // w20
  __int64 v18; // x9
  __int64 *v19; // x9
  __int64 v20; // x11
  __int64 v21; // x8
  __int64 v22; // x10
  int v23; // w11

  v3 = a1 + 20480;
  v4 = *(unsigned __int16 *)(a1 + 24548);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL);
  if ( a3 <= 0x36 )
  {
    if ( ((1LL << a3) & 0x20000F4) != 0 )
    {
      v6 = 4096;
      goto LABEL_6;
    }
    if ( ((1LL << a3) & 0x78A00000000000LL) != 0 )
    {
      v6 = 0x2000;
      goto LABEL_6;
    }
  }
  v6 = 0;
LABEL_6:
  v7 = *(unsigned __int16 *)(v5 + 14);
  v8 = v7 - v4;
  if ( v7 == v4 )
    return 4294967274LL;
  v10 = v5 + 16;
  v11 = 3 * v4 + 2 * (*(unsigned __int8 *)(v5 + 13) + *(unsigned __int8 *)(v5 + 12));
  if ( (*(_BYTE *)(**(_QWORD **)(*(_QWORD *)(a1 + 14264) + 48LL) + 56LL * a3 + 24) & 2) != 0 )
  {
    if ( v7 >= 2 )
    {
      v13 = v5 + 4LL * v11;
      v14 = 0;
      v15 = v11;
      v16 = v11 + 3 * v7 - 6;
      while ( *(_DWORD *)(v13 + v14 + 20) != *(_DWORD *)(a2 + 24) || *(_DWORD *)(v13 + v14 + 16) != v6 )
      {
        v14 += 12;
        v11 += 3;
        if ( 12 * v7 - 12 == (_DWORD)v14 )
          return 4294967294LL;
      }
      if ( !(unsigned int)kgsl_hwlock(*(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL)) )
      {
        v19 = (__int64 *)(v10 + 4LL * v16);
        if ( 12 * v7 - 24 != (_DWORD)v14 )
        {
          v20 = *v19;
          v21 = v5 + 4 * v15 + v14;
          *(_DWORD *)(v21 + 24) = *((_DWORD *)v19 + 2);
          *(_QWORD *)(v21 + 16) = v20;
        }
        v22 = *(__int64 *)((char *)v19 + 12);
        v23 = *((_DWORD *)v19 + 5);
        v12 = 0;
        *(__int64 *)((char *)v19 + 12) = 0;
        *v19 = v22;
        *((_DWORD *)v19 + 2) = v23;
        *((_DWORD *)v19 + 5) = 0;
        --*(_WORD *)(v5 + 14);
        if ( v8 != 1 )
          goto LABEL_20;
        goto LABEL_11;
      }
LABEL_19:
      v12 = -16;
LABEL_20:
      v17 = v12;
      kgsl_hwunlock(v5);
      return v17;
    }
    return 4294967294LL;
  }
  else
  {
    if ( (unsigned __int16)(v7 - v4) == 1 )
    {
      if ( !(unsigned int)kgsl_hwlock(*(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL)) )
      {
LABEL_11:
        v12 = *(_DWORD *)(v3 + 3564);
        if ( v12 )
        {
          v12 = 0;
        }
        else
        {
          v18 = v10 + 4LL * v11;
          *(_DWORD *)(v18 + 8) = 0;
          *(_QWORD *)v18 = 0;
          *(_WORD *)(v5 + 14) = *(_WORD *)(v3 + 4068);
        }
        goto LABEL_20;
      }
      goto LABEL_19;
    }
    return 0;
  }
}
