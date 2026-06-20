__int64 __fastcall usb_get_repeater_by_node(__int64 a1)
{
  __int64 v2; // x19
  _UNKNOWN **v3; // x9
  __int64 v4; // x20

  v2 = raw_spin_lock_irqsave(&repeater_lock);
  if ( (of_device_is_available(a1) & 1) != 0 )
  {
    v3 = &repeater_list;
    while ( 1 )
    {
      v3 = (_UNKNOWN **)*v3;
      if ( v3 == &repeater_list )
        break;
      if ( *((_QWORD *)*(v3 - 3) + 93) == a1 )
      {
        v4 = (__int64)(v3 - 3);
        goto LABEL_8;
      }
    }
    v4 = -517;
  }
  else
  {
    v4 = -19;
  }
LABEL_8:
  raw_spin_unlock_irqrestore(&repeater_lock, v2);
  return v4;
}
