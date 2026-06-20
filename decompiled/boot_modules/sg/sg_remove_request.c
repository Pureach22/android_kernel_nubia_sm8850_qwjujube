__int64 __fastcall sg_remove_request(__int64 result, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v4; // x0
  __int64 v5; // x10
  __int64 v6; // x9
  _QWORD *v7; // x11
  _QWORD *v8; // x8

  if ( result )
  {
    if ( a2 )
    {
      v2 = result;
      if ( *(_QWORD *)(result + 144) != result + 144 )
      {
        v4 = raw_write_lock_irqsave(result + 48);
        v5 = *a2;
        v6 = v4;
        if ( (_QWORD *)*a2 != a2 )
        {
          v7 = (_QWORD *)a2[1];
          v8 = a2;
          if ( (_QWORD *)*v7 == a2 && *(_QWORD **)(v5 + 8) == a2 )
          {
            *(_QWORD *)(v5 + 8) = v7;
            *v7 = v5;
          }
          else
          {
            _list_del_entry_valid_or_report(a2);
            v8 = a2;
          }
          v8[2] = 0;
          *v8 = 0xDEAD000000000100LL;
          v8[1] = 0xDEAD000000000122LL;
        }
        result = raw_write_unlock_irqrestore(v2 + 48, v6);
        if ( *(_DWORD *)(*(_QWORD *)(v2 + 16) + 112LL) )
          return _wake_up(v2 + 24, 1, 0, 0);
      }
    }
  }
  return result;
}
