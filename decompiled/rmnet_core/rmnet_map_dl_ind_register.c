__int64 __fastcall rmnet_map_dl_ind_register(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x10
  _QWORD *v3; // x9
  char v4; // w8
  unsigned __int64 v5; // x11
  _QWORD *v7; // x13
  __int64 v8; // x12
  unsigned __int64 *v9; // x8
  unsigned __int64 v10; // x10
  unsigned __int64 *v11; // x11

  if ( !a1 || !a2 || !a2[1] || !a2[2] )
    return 4294967274LL;
  v2 = *(_QWORD **)(a1 + 2480);
  v3 = (_QWORD *)(a1 + 2480);
  if ( v2 == (_QWORD *)(a1 + 2480) )
    goto LABEL_16;
  v4 = 0;
  v5 = (unsigned __int64)(a2 + 3);
  do
  {
    if ( *(unsigned __int8 *)a2 <= (unsigned int)*((unsigned __int8 *)v2 - 24) )
    {
      v9 = (unsigned __int64 *)v2[1];
      if ( (_QWORD *)v5 == v2 || v9 == (unsigned __int64 *)v5 || (_QWORD *)*v9 != v2 )
      {
        _list_add_valid_or_report(v5, v2[1], v2);
        a2 = v7;
        a1 = v8;
        v4 = 1;
      }
      else
      {
        a2[3] = v2;
        a2[4] = v9;
        atomic_store(v5, v9);
        v4 = 1;
        v2[1] = v5;
      }
    }
    v2 = (_QWORD *)*v2;
  }
  while ( v2 != v3 );
  if ( (v4 & 1) == 0 )
  {
LABEL_16:
    v10 = (unsigned __int64)(a2 + 3);
    v11 = *(unsigned __int64 **)(a1 + 2488);
    if ( a2 + 3 == v3 || v11 == (unsigned __int64 *)v10 || (_QWORD *)*v11 != v3 )
    {
      _list_add_valid_or_report(a2 + 3, v11, v3);
    }
    else
    {
      a2[3] = v3;
      a2[4] = v11;
      atomic_store(v10, v11);
      *(_QWORD *)(a1 + 2488) = v10;
    }
  }
  return 0;
}
