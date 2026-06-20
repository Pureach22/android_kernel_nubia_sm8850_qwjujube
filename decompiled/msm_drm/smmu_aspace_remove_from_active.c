__int64 __fastcall smmu_aspace_remove_from_active(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  _QWORD *v7; // x11
  _QWORD *v8; // x10

  result = mutex_is_locked(a1 + 320);
  if ( (result & 1) == 0 )
    __break(0x800u);
  v5 = *(_QWORD **)(a1 + 288);
  while ( v5 != (_QWORD *)(a1 + 288) )
  {
    v6 = v5;
    v7 = v5 - 74;
    v5 = (_QWORD *)*v5;
    if ( v7 == a2 )
    {
      v8 = (_QWORD *)v6[1];
      *((_BYTE *)v6 + 24) = 0;
      if ( (_QWORD *)*v8 == v6 && (_QWORD *)v5[1] == v6 )
      {
        v5[1] = v8;
        *v8 = v5;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v6);
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      return result;
    }
  }
  return result;
}
