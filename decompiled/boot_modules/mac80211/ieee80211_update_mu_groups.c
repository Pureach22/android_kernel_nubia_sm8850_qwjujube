__int64 __fastcall ieee80211_update_mu_groups(__int64 a1, __int64 a2, _QWORD *a3, _QWORD *a4)
{
  unsigned int v6; // w21
  __int64 lock; // x0
  __int64 v9; // x8
  __int64 v10; // x9

  v6 = a2;
  lock = _rcu_read_lock(a1, a2);
  if ( v6 >= 0x10 )
  {
    __break(0x5512u);
    JUMPOUT(0xB460C);
  }
  v9 = *(_QWORD *)(a1 + 8LL * v6 + 960);
  if ( v9 && (*(_BYTE *)(v9 + 831) & 1) != 0 )
  {
    *(_QWORD *)(v9 + 200) = *a3;
    v10 = a4[1];
    *(_QWORD *)(v9 + 208) = *a4;
    *(_QWORD *)(v9 + 216) = v10;
  }
  else
  {
    __break(0x800u);
  }
  return _rcu_read_unlock(lock);
}
