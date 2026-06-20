_DWORD *__fastcall coresight_find_sink(_DWORD *a1, int *a2)
{
  int v4; // w8
  int v5; // w22
  int v6; // w23
  _DWORD *v7; // x21
  __int64 v8; // x8
  __int64 v9; // x24
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 sink; // x0
  unsigned int v13; // w9
  unsigned int v14; // w10
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[2];
  v5 = *a2 + 1;
  if ( (v4 | 2) == 2 && a1[3] >= 2u )
  {
    v6 = *a2 + 1;
    v7 = a1;
    if ( !v4 )
    {
      v6 = *a2 + 1;
      v7 = a1;
      goto LABEL_17;
    }
  }
  else
  {
    v6 = 0;
    v7 = nullptr;
  }
  v8 = *(_QWORD *)a1;
  if ( *(int *)(*(_QWORD *)a1 + 4LL) >= 1 )
  {
    v9 = 0;
    do
    {
      v10 = *(_QWORD *)(v8 + 8);
      v16 = v5;
      v11 = *(_QWORD *)(*(_QWORD *)(v10 + 8 * v9) + 16LL);
      if ( v11 )
      {
        sink = coresight_find_sink(v11, &v16);
        if ( sink )
        {
          if ( !v7 || (v13 = *(_DWORD *)(sink + 12), v14 = v7[3], v13 > v14) || v13 == v14 && v6 > v16 )
          {
            v6 = v16;
            v7 = (_DWORD *)sink;
          }
        }
      }
      v8 = *(_QWORD *)a1;
      ++v9;
    }
    while ( v9 < *(int *)(*(_QWORD *)a1 + 4LL) );
  }
LABEL_17:
  if ( v7 )
    *a2 = v6;
  _ReadStatusReg(SP_EL0);
  return v7;
}
