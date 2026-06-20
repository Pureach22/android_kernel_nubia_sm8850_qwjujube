__int64 __fastcall kgsl_del_event_group(__int64 result, _QWORD *a2)
{
  __int64 v3; // x20
  _QWORD *v4; // x8
  _QWORD *v5; // x0
  __int64 v6; // x9

  if ( *a2 )
  {
    v3 = result;
    if ( (_QWORD *)a2[2] != a2 + 2 )
      __break(0x800u);
    raw_write_lock(result + 13168);
    v4 = (_QWORD *)a2[5];
    v5 = a2 + 4;
    if ( (_QWORD *)*v4 == a2 + 4 && (v6 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
    {
      *(_QWORD *)(v6 + 8) = v4;
      *v4 = v6;
    }
    else
    {
      _list_del_entry_valid_or_report(v5);
    }
    a2[4] = 0xDEAD000000000100LL;
    a2[5] = 0xDEAD000000000122LL;
    return raw_write_unlock(v3 + 13168);
  }
  return result;
}
