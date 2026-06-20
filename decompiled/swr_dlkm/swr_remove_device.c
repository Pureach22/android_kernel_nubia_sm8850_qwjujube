__int64 __fastcall swr_remove_device(__int64 result)
{
  __int64 v1; // x8
  _QWORD *v2; // x10
  _QWORD *v3; // x9
  _QWORD *v4; // x11
  _QWORD *v5; // x8

  v1 = *(_QWORD *)(result + 32);
  v2 = *(_QWORD **)(v1 + 984);
  if ( v2 != (_QWORD *)(v1 + 984) )
  {
    v3 = (_QWORD *)result;
    do
    {
      v4 = (_QWORD *)*v2;
      if ( v2 - 6 == v3 )
      {
        v5 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v5 == v2 && (_QWORD *)v4[1] == v2 )
        {
          v4[1] = v5;
          *v5 = v4;
        }
        else
        {
          result = _list_del_entry_valid_or_report(v2);
        }
        *v2 = v2;
        v2[1] = v2;
        v1 = v3[4];
      }
      v2 = v4;
    }
    while ( v4 != (_QWORD *)(v1 + 984) );
  }
  return result;
}
