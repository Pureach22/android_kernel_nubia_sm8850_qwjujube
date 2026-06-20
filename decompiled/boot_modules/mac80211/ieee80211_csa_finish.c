__int64 __fastcall ieee80211_csa_finish(__int64 result, __int64 a2)
{
  unsigned int v2; // w20
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 lock; // x0
  __int64 v6; // x20
  _QWORD *i; // x22

  if ( (unsigned int)a2 >= 0xF )
  {
    __break(0x800u);
  }
  else
  {
    v2 = a2;
    v3 = result;
    v4 = *(_QWORD *)(result - 3104);
    lock = _rcu_read_lock(result, a2);
    v6 = *(_QWORD *)(v3 + 8LL * v2 - 152);
    if ( v6 )
    {
      if ( *(_QWORD *)(v3 + 1168) == v3 )
      {
        for ( i = *(_QWORD **)(v4 + 4616); i != (_QWORD *)(v4 + 4616); i = (_QWORD *)*i )
        {
          if ( i != (_QWORD *)(v3 - 4720) && (i[204] & 1) != 0 && i[736] == v3 )
            wiphy_work_queue(*(_QWORD *)(i[202] + 72LL), i + 470);
        }
      }
      lock = wiphy_work_queue(*(_QWORD *)(v4 + 72), v6 + 144);
    }
    else
    {
      __break(0x800u);
    }
    return _rcu_read_unlock(lock);
  }
  return result;
}
