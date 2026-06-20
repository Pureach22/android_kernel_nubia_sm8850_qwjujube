__int64 __fastcall ieee80211_delayed_tailroom_dec(__int64 result, __int64 a2)
{
  int v2; // w20
  __int64 lock; // x0
  _QWORD *i; // x8

  v2 = *(_DWORD *)(a2 - 4);
  if ( *(_DWORD *)(a2 - 8) < v2 )
    __break(0x800u);
  if ( *(_DWORD *)(a2 + 3184) == 3 )
  {
    lock = _rcu_read_lock(result, a2);
    for ( i = *(_QWORD **)(a2 + 728); i != (_QWORD *)(a2 + 728); i = (_QWORD *)*i )
      *((_DWORD *)i - 184) -= v2;
    result = _rcu_read_unlock(lock);
  }
  *(_QWORD *)(a2 - 8) = (unsigned int)(*(_DWORD *)(a2 - 8) - v2);
  return result;
}
