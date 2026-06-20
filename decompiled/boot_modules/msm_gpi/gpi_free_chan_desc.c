__int64 __fastcall gpi_free_chan_desc(__int64 a1)
{
  __int64 v2; // x9
  _QWORD *v3; // x10
  _QWORD *v4; // x20
  _QWORD *v5; // x8
  __int64 v6; // x11

  v2 = raw_spin_lock_irqsave(a1 + 160);
  v3 = *(_QWORD **)(a1 + 200);
  if ( v3 == (_QWORD *)(a1 + 200) )
    return raw_spin_unlock_irqrestore(a1 + 160, v2);
  v4 = v3 - 19;
  if ( v3 == (_QWORD *)&unk_98 )
    return raw_spin_unlock_irqrestore(a1 + 160, v2);
  v5 = (_QWORD *)v3[1];
  if ( (_QWORD *)*v5 == v3 && (v6 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v6 + 8) = v5;
    *v5 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 200));
  }
  *v3 = 0xDEAD000000000100LL;
  v3[1] = 0xDEAD000000000122LL;
  raw_spin_unlock_irqrestore(a1 + 160, v2);
  return kfree(v4);
}
