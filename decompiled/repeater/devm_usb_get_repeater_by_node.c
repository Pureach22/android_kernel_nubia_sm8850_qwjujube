__int64 __fastcall devm_usb_get_repeater_by_node(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x19
  _UNKNOWN **v7; // x9
  __int64 v8; // x10
  __int64 v9; // x22

  v4 = _devres_alloc_node(
         devm_usb_repeater_release_by_node,
         88,
         3264,
         0xFFFFFFFFLL,
         "devm_usb_repeater_release_by_node");
  if ( !v4 )
    return -12;
  v5 = v4;
  v6 = raw_spin_lock_irqsave(&repeater_lock);
  if ( (of_device_is_available(a2) & 1) != 0 )
  {
    v7 = &repeater_list;
    do
    {
      v7 = (_UNKNOWN **)*v7;
      if ( v7 == &repeater_list )
      {
        v9 = -517;
        goto LABEL_12;
      }
      v8 = (__int64)*(v7 - 3);
    }
    while ( *(_QWORD *)(v8 + 744) != a2 );
    v9 = (__int64)(v7 - 3);
    if ( (unsigned __int64)(v7 - 3) >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_12;
    if ( (try_module_get(*(_QWORD *)(*(_QWORD *)(v8 + 136) + 16LL)) & 1) != 0 )
    {
      devres_add(a1, v5);
      get_device(*(_QWORD *)v9);
    }
    else
    {
      devres_free(v5);
      v9 = -19;
    }
  }
  else
  {
    v9 = -19;
LABEL_12:
    devres_free(v5);
  }
  raw_spin_unlock_irqrestore(&repeater_lock, v6);
  return v9;
}
