__int64 __fastcall ieee80211_obss_color_collision_notify(__int64 result, __int64 a2, unsigned __int8 a3)
{
  __int64 v5; // x20
  __int64 lock; // x0
  _QWORD *v7; // x8
  __int64 v8; // x9

  if ( a3 >= 0xFu )
  {
    __break(0x800u);
  }
  else
  {
    v5 = result;
    lock = _rcu_read_lock(result, a2);
    v7 = *(_QWORD **)(v5 + 8LL * a3 - 152);
    if ( v7 )
    {
      v8 = v7[118];
      if ( (*(_BYTE *)(v8 + 840) & 1) == 0 && *(_BYTE *)(v8 + 830) != 1 && (v7[32] & 1) == 0 )
      {
        v7[45] = a2;
        lock = ieee80211_queue_delayed_work(*(_QWORD *)(v5 - 3104), v7 + 32, 125);
      }
    }
    else
    {
      __break(0x800u);
    }
    return _rcu_read_unlock(lock);
  }
  return result;
}
