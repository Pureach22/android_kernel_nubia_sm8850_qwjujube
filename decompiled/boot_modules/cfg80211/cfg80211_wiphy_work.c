__int64 __fastcall cfg80211_wiphy_work(__int64 a1)
{
  _QWORD *v2; // x9
  _QWORD *v3; // x20
  _QWORD *v4; // x8
  __int64 v5; // x10
  _DWORD *v6; // x8

  mutex_lock(a1 + 72);
  if ( (*(_BYTE *)(a1 + 52) & 1) == 0 )
  {
    raw_spin_lock_irq(a1 + 48);
    v2 = (_QWORD *)(a1 + 32);
    v3 = *(_QWORD **)(a1 + 32);
    if ( v3 == (_QWORD *)(a1 + 32) || !v3 )
    {
      raw_spin_unlock_irq(a1 + 48);
    }
    else
    {
      v4 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v4 == v3 && (v5 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v5 + 8) = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 32));
      }
      *v3 = v3;
      v3[1] = v3;
      if ( (_QWORD *)*v2 != v2 )
        queue_work_on(32, system_unbound_wq, a1);
      raw_spin_unlock_irq(a1 + 48);
      v6 = (_DWORD *)v3[2];
      if ( *(v6 - 1) != 1685912259 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v6)(a1 + 72, v3);
    }
  }
  return mutex_unlock(a1 + 72);
}
