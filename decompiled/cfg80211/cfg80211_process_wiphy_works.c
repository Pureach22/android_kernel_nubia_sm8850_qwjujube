__int64 __fastcall cfg80211_process_wiphy_works(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x21
  _QWORD **v6; // x22
  __int64 v7; // x9
  int v8; // w23
  _QWORD *v9; // x8
  __int64 v10; // x10
  _DWORD *v11; // x8

  v4 = raw_spin_lock_irqsave(a1 + 968);
  v5 = *(_QWORD **)(a1 + 952);
  v6 = (_QWORD **)(a1 + 952);
  v7 = v4;
  if ( v5 != (_QWORD *)(a1 + 952) )
  {
    v8 = -99;
    _ReadStatusReg(SP_EL0);
    do
    {
      v9 = (_QWORD *)v5[1];
      if ( (_QWORD *)*v9 == v5 && (v10 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
      {
        *(_QWORD *)(v10 + 8) = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v5);
      }
      *v5 = v5;
      v5[1] = v5;
      raw_spin_unlock_irqrestore(a1 + 968, v7);
      v11 = (_DWORD *)v5[2];
      if ( *(v11 - 1) != 1685912259 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v11)(a1 + 992, v5);
      v7 = raw_spin_lock_irqsave(a1 + 968);
      if ( v5 == a2 )
        break;
      if ( !v8 )
      {
        __break(0x800u);
        *(_QWORD *)(a1 + 952) = a1 + 952;
        *(_QWORD *)(a1 + 960) = v6;
      }
      v5 = *v6;
      ++v8;
    }
    while ( *v6 != v6 );
  }
  return raw_spin_unlock_irqrestore(a1 + 968, v7);
}
