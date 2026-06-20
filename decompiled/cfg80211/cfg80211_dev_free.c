__int64 __fastcall cfg80211_dev_free(_QWORD *a1)
{
  __int64 v2; // x1
  _QWORD *v3; // x0
  _QWORD *v4; // x8
  _QWORD *v5; // x22
  _QWORD *v6; // x9
  _QWORD *v7; // x1
  _QWORD *v8; // x22

  v2 = raw_spin_lock_irqsave(a1 + 121);
  if ( (_QWORD *)a1[119] != a1 + 119 )
    __break(0x800u);
  raw_spin_unlock_irqrestore(a1 + 121, v2);
  cancel_work_sync(a1 + 115);
  rfkill_destroy(a1[309]);
  v3 = (_QWORD *)a1[18];
  if ( v3 != a1 + 18 )
  {
    do
    {
      v5 = (_QWORD *)*v3;
      v4 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v4 == v3 && (_QWORD *)v5[1] == v3 )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
        v3 = v6;
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v3);
      v3 = v5;
    }
    while ( v5 != a1 + 18 );
  }
  v7 = (_QWORD *)a1[24];
  if ( v7 != a1 + 24 )
  {
    do
    {
      v8 = (_QWORD *)*v7;
      cfg80211_put_bss(a1 + 124, v7 + 14);
      v7 = v8;
    }
    while ( v8 != a1 + 24 );
  }
  kfree(a1[172]);
  return kfree(a1);
}
