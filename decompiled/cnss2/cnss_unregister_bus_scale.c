__int64 __fastcall cnss_unregister_bus_scale(__int64 result)
{
  _QWORD *v1; // x9
  _QWORD *v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x21

  v1 = *(_QWORD **)(result + 344);
  v2 = (_QWORD *)(result + 344);
  if ( v1 != (_QWORD *)(result + 344) )
  {
    do
    {
      v4 = (_QWORD *)*v1;
      v3 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v3 == v1 && (_QWORD *)v4[1] == v1 )
      {
        v4[1] = v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      result = v1[3];
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      if ( result )
        result = icc_put();
      v1 = v4;
    }
    while ( v4 != v2 );
  }
  v2[2] = 0;
  v2[3] = 0;
  *v2 = 0;
  v2[1] = 0;
  return result;
}
