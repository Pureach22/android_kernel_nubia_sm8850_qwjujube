__int64 __fastcall qcom_ipcc_mbox_xlate(__int64 a1, _DWORD *a2)
{
  int v2; // w9
  __int64 v3; // x10
  __int64 v4; // x0
  unsigned __int16 *v5; // x8
  __int64 v6; // x11
  __int64 v7; // x19
  bool v8; // zf
  __int64 v9; // x8
  _DWORD *v11; // x20
  _WORD *v12; // x0
  int v13; // w8
  int v14; // w9

  if ( a2[2] != 2 )
    return -22;
  v2 = *(_DWORD *)(a1 + 24);
  if ( v2 < 1 )
    return -16;
  v3 = *(_QWORD *)(a1 - 16);
  v4 = *(_QWORD *)(a1 - 40);
  v5 = *(unsigned __int16 **)(v3 + 240);
  if ( v5 )
  {
    v6 = 0;
    while ( 1 )
    {
      if ( a2[3] == *v5 )
      {
        v8 = a2[4] == v5[1];
        v9 = -16;
        if ( v8 )
          return v9;
        if ( (int)++v6 >= v2 )
          return v9;
      }
      else if ( (int)++v6 >= v2 )
      {
        return -16;
      }
      v7 = v3 + 248 * v6;
      v5 = *(unsigned __int16 **)(v7 + 240);
      if ( !v5 )
      {
        v11 = a2;
        goto LABEL_15;
      }
    }
  }
  v11 = a2;
  v7 = v3;
LABEL_15:
  v12 = (_WORD *)devm_kmalloc(v4, 6, 3520);
  if ( !v12 )
    return -12;
  v13 = v11[3];
  v14 = v11[4];
  *(_QWORD *)(v7 + 240) = v12;
  *v12 = v13;
  v9 = v7;
  v12[1] = v14;
  return v9;
}
