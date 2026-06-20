__int64 __fastcall kgsl_snapshot_have_object(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  unsigned __int64 v4; // x8
  _QWORD *v5; // x10
  _QWORD *v6; // x0
  _QWORD *i; // x9
  _QWORD *v8; // t1
  __int64 v9; // x10
  unsigned __int64 v10; // x10
  __int64 *v12; // x12
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x13
  _QWORD *v16; // x12
  unsigned __int64 v17; // x13

  v4 = a4 + a3;
  v5 = *(_QWORD **)(a1 + 144);
  if ( v5 == (_QWORD *)(a1 + 144) )
  {
LABEL_2:
    v8 = *(_QWORD **)(a1 + 128);
    v6 = (_QWORD *)(a1 + 128);
    for ( i = v8; i != v6; i = (_QWORD *)*i )
    {
      v9 = *(i - 1);
      if ( v9 )
      {
        if ( *(_QWORD *)(v9 + 256) == a2 )
        {
          v10 = *(i - 5);
          if ( v10 <= a3 && v4 <= *(i - 4) + v10 )
            return 1;
        }
      }
    }
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v12 = (__int64 *)*(v5 - 1);
      if ( v12 )
      {
        v13 = *((unsigned int *)v12 + 2);
        if ( (_DWORD)v13 )
        {
          v14 = *v12;
          v15 = *(_QWORD *)(v14 + 24);
          if ( v15 )
          {
            if ( *(_QWORD *)(v15 + 256) == a2 && (int)v13 >= 1 )
              break;
          }
        }
      }
LABEL_10:
      v5 = (_QWORD *)*v5;
      if ( v5 == (_QWORD *)(a1 + 144) )
        goto LABEL_2;
    }
    v16 = (_QWORD *)(v14 + 8);
    while ( 1 )
    {
      v17 = *(v16 - 1);
      if ( v17 <= a3 && v4 <= *v16 + v17 )
        return 1;
      --v13;
      v16 += 4;
      if ( !v13 )
        goto LABEL_10;
    }
  }
}
