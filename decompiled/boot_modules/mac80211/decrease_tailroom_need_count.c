__int64 __fastcall decrease_tailroom_need_count(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w20
  __int64 lock; // x0
  _QWORD *i; // x8

  v2 = result;
  v3 = a2;
  if ( *(_DWORD *)(result + 1528) < (int)a2 )
    __break(0x800u);
  if ( *(_DWORD *)(result + 4720) == 3 )
  {
    lock = _rcu_read_lock(result, a2);
    for ( i = *(_QWORD **)(v2 + 2264); i != (_QWORD *)(v2 + 2264); i = (_QWORD *)*i )
      *((_DWORD *)i - 184) -= v3;
    result = _rcu_read_unlock(lock);
  }
  *(_DWORD *)(v2 + 1528) -= v3;
  return result;
}
