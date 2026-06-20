__int64 __fastcall ieee80211_color_change_finish(__int64 result, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 v3; // x19
  __int64 lock; // x0
  __int64 v5; // x8

  if ( (unsigned __int8)a2 >= 0xFu )
  {
    __break(0x800u);
  }
  else
  {
    v2 = a2;
    v3 = result;
    lock = _rcu_read_lock(result, a2);
    v5 = *(_QWORD *)(v3 + 8LL * v2 - 152);
    if ( v5 )
      lock = wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v3 - 3104) + 72LL), v5 + 232);
    else
      __break(0x800u);
    return _rcu_read_unlock(lock);
  }
  return result;
}
