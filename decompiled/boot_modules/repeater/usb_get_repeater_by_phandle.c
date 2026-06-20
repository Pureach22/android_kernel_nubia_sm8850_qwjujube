__int64 __fastcall usb_get_repeater_by_phandle(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x0
  int v4; // w8
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x19
  _UNKNOWN **v8; // x9
  __int64 v9; // x20
  _QWORD v10[11]; // [xsp+8h] [xbp-58h] BYREF

  v10[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 744);
  if ( v3 )
  {
    memset(v10, 0, 80);
    v4 = _of_parse_phandle_with_args(v3, a2, 0, 0, a3, v10);
    result = -19;
    if ( !v4 )
    {
      v6 = v10[0];
      if ( v10[0] )
      {
        v7 = raw_spin_lock_irqsave(&repeater_lock);
        if ( (of_device_is_available(v6) & 1) != 0 )
        {
          v8 = &repeater_list;
          while ( 1 )
          {
            v8 = (_UNKNOWN **)*v8;
            if ( v8 == &repeater_list )
              break;
            if ( *((_QWORD *)*(v8 - 3) + 93) == v6 )
            {
              v9 = (__int64)(v8 - 3);
              goto LABEL_12;
            }
          }
          v9 = -517;
        }
        else
        {
          v9 = -19;
        }
LABEL_12:
        raw_spin_unlock_irqrestore(&repeater_lock, v7);
        result = v9;
      }
    }
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
