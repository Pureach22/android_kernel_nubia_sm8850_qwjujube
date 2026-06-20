__int64 __fastcall rmnet_map_cmd_exit(__int64 result)
{
  _QWORD *v1; // x10
  __int64 v2; // x12
  __int64 v3; // x9
  unsigned __int64 v4; // x11
  _QWORD *v5; // x8
  _QWORD *v6; // x13
  _QWORD *v7; // x10
  _QWORD *v8; // x9
  _QWORD *v9; // x8
  _QWORD *v10; // x12

  v1 = *(_QWORD **)(result + 2480);
  v2 = result + 2480;
  v3 = result;
  v4 = 0xDEAD000000000122LL;
  if ( v1 != (_QWORD *)(result + 2480) )
  {
    do
    {
      v6 = (_QWORD *)*v1;
      v5 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v5 == v1 && (_QWORD *)v6[1] == v1 )
      {
        v6[1] = v5;
        *v5 = v6;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v1);
      }
      v1[1] = v4;
      v1 = v6;
    }
    while ( v6 != (_QWORD *)v2 );
  }
  v7 = *(_QWORD **)(v3 + 2752);
  v8 = (_QWORD *)(v3 + 2752);
  if ( v7 != v8 )
  {
    do
    {
      v10 = (_QWORD *)*v7;
      v9 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v9 == v7 && (_QWORD *)v10[1] == v7 )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v7);
      }
      v7[1] = v4;
      v7 = v10;
    }
    while ( v10 != v8 );
  }
  return result;
}
