__int64 __fastcall usb_add_repeater_dev(__int64 a1)
{
  _UNKNOWN **v2; // x0
  _QWORD *v3; // x1

  if ( a1 && *(_QWORD *)a1 )
  {
    raw_spin_lock(&repeater_lock);
    v2 = (_UNKNOWN **)(a1 + 24);
    v3 = off_78;
    if ( (_UNKNOWN **)(a1 + 24) == &repeater_list || off_78 == v2 || *off_78 != (_UNKNOWN *)&repeater_list )
    {
      _list_add_valid_or_report();
    }
    else
    {
      off_78 = (_UNKNOWN **)(a1 + 24);
      *(_QWORD *)(a1 + 24) = &repeater_list;
      *(_QWORD *)(a1 + 32) = v3;
      *v3 = v2;
    }
    raw_spin_unlock(&repeater_lock);
    return 0;
  }
  else
  {
    printk(&unk_65FA);
    return 4294967274LL;
  }
}
