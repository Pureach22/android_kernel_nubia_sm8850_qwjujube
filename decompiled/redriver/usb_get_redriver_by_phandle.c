__int64 __fastcall usb_get_redriver_by_phandle(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x20
  __int64 v4; // x19
  _QWORD v6[11]; // [xsp+8h] [xbp-58h] BYREF

  v6[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v6, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(a1, a2, 0, 0, a3, v6) )
    v3 = 0;
  else
    v3 = v6[0];
  v4 = 0;
  if ( (of_device_is_available(v3) & 1) != 0 )
  {
    raw_spin_lock(&usb_rediver_lock);
    v4 = (__int64)&usb_redriver_list;
    while ( 1 )
    {
      v4 = *(_QWORD *)v4;
      if ( (_UNKNOWN **)v4 == &usb_redriver_list )
        break;
      if ( *(_QWORD *)(v4 + 16) == v3 )
      {
        *(_BYTE *)(v4 + 80) = 1;
        goto LABEL_10;
      }
    }
    v4 = -517;
LABEL_10:
    raw_spin_unlock(&usb_rediver_lock);
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
