__int64 __fastcall sde_power_handle_unregister_event(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x8
  __int64 *v5; // x9
  __int64 v6; // x10

  if ( !a1 || !a2 )
    return printk(&unk_221986, "sde_power_handle_unregister_event");
  if ( (*(_BYTE *)(a2 + 168) & 1) != 0 )
  {
    mutex_lock(a1 + 48);
    v4 = *(_QWORD **)(a2 + 160);
    v5 = (__int64 *)(a2 + 152);
    if ( *v4 == a2 + 152 && (v6 = *v5, *(__int64 **)(*v5 + 8) == v5) )
    {
      *(_QWORD *)(v6 + 8) = v4;
      *v4 = v6;
    }
    else
    {
      _list_del_entry_valid_or_report(a2 + 152);
    }
    *(_QWORD *)(a2 + 152) = a2 + 152;
    *(_QWORD *)(a2 + 160) = v5;
    mutex_unlock(a1 + 48);
  }
  else
  {
    printk(&unk_2219AF, "sde_power_handle_unregister_event");
  }
  return kfree(a2);
}
