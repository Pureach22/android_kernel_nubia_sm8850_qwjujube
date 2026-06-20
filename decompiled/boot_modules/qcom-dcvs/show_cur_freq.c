__int64 __fastcall show_cur_freq(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x10
  char v4; // w12
  unsigned int v5; // w3
  unsigned __int64 v6; // x12
  unsigned __int64 v7; // x12
  bool v8; // cf
  __int64 v9; // x10
  char v10; // w12
  unsigned __int64 v11; // x12
  unsigned __int64 v12; // x12
  unsigned int v13; // w10
  __int64 v14; // x8
  char v15; // w11
  unsigned __int64 v16; // x11
  unsigned __int64 v17; // x11
  unsigned int v18; // w8

  v3 = a1[17];
  if ( !v3 )
  {
    v5 = 0;
    goto LABEL_11;
  }
  if ( *(_DWORD *)(v3 + 8) == 2 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = (unsigned int)(-1LL << v4) & _cpu_possible_mask;
      if ( !(_DWORD)v6 )
        break;
      v7 = __clz(__rbit64(v6));
      if ( v5 <= *(_DWORD *)(*(_QWORD *)(v3 + 40) + 4 * v7) )
        v5 = *(_DWORD *)(*(_QWORD *)(v3 + 40) + 4 * v7);
      v8 = v7 >= 0x1F;
      v4 = v7 + 1;
    }
    while ( !v8 );
LABEL_11:
    v9 = a1[18];
    if ( !v9 )
      goto LABEL_24;
    goto LABEL_14;
  }
  v5 = *(_DWORD *)(v3 + 24);
  v9 = a1[18];
  if ( !v9 )
    goto LABEL_24;
LABEL_14:
  if ( *(_DWORD *)(v9 + 8) == 2 )
  {
    v10 = 0;
    do
    {
      v11 = (unsigned int)(-1LL << v10) & _cpu_possible_mask;
      if ( !(_DWORD)v11 )
        break;
      v12 = __clz(__rbit64(v11));
      if ( v5 <= *(_DWORD *)(*(_QWORD *)(v9 + 40) + 4 * v12) )
        v5 = *(_DWORD *)(*(_QWORD *)(v9 + 40) + 4 * v12);
      v8 = v12 >= 0x1F;
      v10 = v12 + 1;
    }
    while ( !v8 );
  }
  else
  {
    v13 = *(_DWORD *)(v9 + 24);
    if ( v5 <= v13 )
      v5 = v13;
  }
LABEL_24:
  v14 = a1[19];
  if ( v14 )
  {
    if ( *(_DWORD *)(v14 + 8) == 2 )
    {
      v15 = 0;
      do
      {
        v16 = (unsigned int)(-1LL << v15) & _cpu_possible_mask;
        if ( !(_DWORD)v16 )
          break;
        v17 = __clz(__rbit64(v16));
        if ( v5 <= *(_DWORD *)(*(_QWORD *)(v14 + 40) + 4 * v17) )
          v5 = *(_DWORD *)(*(_QWORD *)(v14 + 40) + 4 * v17);
        v8 = v17 >= 0x1F;
        v15 = v17 + 1;
      }
      while ( !v8 );
    }
    else
    {
      v18 = *(_DWORD *)(v14 + 24);
      if ( v5 <= v18 )
        v5 = v18;
    }
  }
  return (int)scnprintf(a3, 4096, "%d\n", v5);
}
