__int64 __fastcall usb_remove_redriver(__int64 *a1)
{
  unsigned int v2; // w20
  __int64 **v3; // x8
  __int64 *v4; // x9

  raw_spin_lock(&usb_rediver_lock);
  if ( (a1[10] & 1) != 0 )
  {
    v2 = -22;
  }
  else
  {
    v3 = (__int64 **)a1[1];
    if ( *v3 == a1 && (v4 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
    {
      v4[1] = (__int64)v3;
      *v3 = v4;
    }
    else
    {
      _list_del_entry_valid_or_report(a1);
    }
    v2 = 0;
    *a1 = 0xDEAD000000000100LL;
    a1[1] = 0xDEAD000000000122LL;
  }
  raw_spin_unlock(&usb_rediver_lock);
  return v2;
}
