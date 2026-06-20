__int64 __fastcall sde_evtlog_destroy(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x8
  _QWORD *v5; // x22
  _QWORD *v6; // x9

  if ( result )
  {
    v1 = result;
    v2 = (_QWORD *)(result + 786480);
    v3 = *(_QWORD **)(result + 786480);
    if ( v3 != v2 )
    {
      do
      {
        v5 = (_QWORD *)*v3;
        v4 = (_QWORD *)v3[1];
        if ( (_QWORD *)*v4 == v3 && (_QWORD *)v5[1] == v3 )
        {
          v5[1] = v4;
          *v4 = v5;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
          v3 = v6;
        }
        *v3 = 0xDEAD000000000100LL;
        v3[1] = 0xDEAD000000000122LL;
        kfree(v3);
        v3 = v5;
      }
      while ( v5 != v2 );
    }
    return vfree(v1);
  }
  return result;
}
