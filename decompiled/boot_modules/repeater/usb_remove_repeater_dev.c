__int64 __fastcall usb_remove_repeater_dev(__int64 a1)
{
  __int64 v2; // x9
  _QWORD *v3; // x8
  __int64 *v4; // x0
  __int64 v5; // x10

  v2 = raw_spin_lock_irqsave(&repeater_lock);
  if ( a1 )
  {
    v3 = *(_QWORD **)(a1 + 32);
    v4 = (__int64 *)(a1 + 24);
    if ( *v3 == a1 + 24 && (v5 = *v4, *(__int64 **)(*v4 + 8) == v4) )
    {
      *(_QWORD *)(v5 + 8) = v3;
      *v3 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report();
    }
    *(_QWORD *)(a1 + 24) = 0xDEAD000000000100LL;
    *(_QWORD *)(a1 + 32) = 0xDEAD000000000122LL;
  }
  return raw_spin_unlock_irqrestore(&repeater_lock, v2);
}
