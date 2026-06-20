unsigned __int64 __fastcall _release__async_queued_reqs(unsigned __int64 result)
{
  _QWORD *v1; // x9
  unsigned __int64 v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x20

  v1 = *(_QWORD **)(result + 1576);
  v2 = result + 1576;
  if ( v1 != (_QWORD *)(result + 1576) )
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
      *v1 = v1;
      v1[1] = v1;
      result = put_si_object((unsigned __int64)(v1 - 4));
      v1 = v4;
    }
    while ( v4 != (_QWORD *)v2 );
  }
  return result;
}
