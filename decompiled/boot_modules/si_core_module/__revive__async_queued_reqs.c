unsigned __int64 __fastcall _revive__async_queued_reqs(unsigned __int64 result)
{
  _QWORD *v1; // x9
  unsigned __int64 v2; // x21
  unsigned __int64 v3; // x19
  _QWORD *v4; // x8
  _QWORD *v5; // x23
  unsigned __int64 v6; // x20

  v1 = *(_QWORD **)(result + 1576);
  v2 = result + 1576;
  v3 = result;
  if ( v1 != (_QWORD *)(result + 1576) )
  {
    do
    {
      v5 = (_QWORD *)*v1;
      v4 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v4 == v1 && (_QWORD *)v5[1] == v1 )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      v6 = (unsigned __int64)(v1 - 4);
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      put_si_object((unsigned __int64)(v1 - 4));
      result = put_si_object(v6);
      v1 = v5;
    }
    while ( v5 != (_QWORD *)v2 );
  }
  *(_QWORD *)(v3 + 1576) = v2;
  *(_QWORD *)(v3 + 1584) = v2;
  return result;
}
