__int64 __fastcall free_one_item(unsigned int a1)
{
  __int64 v2; // x9
  _QWORD *v3; // x20
  void **v4; // x8
  _QWORD *v5; // x10
  __int64 v6; // x22
  _DWORD *v7; // x8

  v2 = raw_spin_lock_irqsave(&free_list_lock);
  v3 = free_list;
  if ( free_list == (_UNKNOWN *)&free_list )
  {
    raw_spin_unlock_irqrestore(&free_list_lock, v2);
    return 0;
  }
  else
  {
    v4 = *((void ***)free_list + 1);
    if ( *v4 == free_list && (v5 = *(_QWORD **)free_list, *(_UNKNOWN **)(*(_QWORD *)free_list + 8LL) == free_list) )
    {
      v5[1] = v4;
      *v4 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(free_list);
    }
    v6 = *(v3 - 2);
    *v3 = 0xDEAD000000000100LL;
    v3[1] = 0xDEAD000000000122LL;
    list_nr_pages -= v6;
    raw_spin_unlock_irqrestore(&free_list_lock, v2);
    v7 = (_DWORD *)*(v3 - 1);
    if ( *(v7 - 1) != 945350800 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD))v7)(v3 - 2, a1);
  }
  return v6;
}
