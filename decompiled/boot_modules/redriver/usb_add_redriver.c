__int64 __fastcall usb_add_redriver(__int64 a1)
{
  __int64 v3; // x0
  _UNKNOWN **v4; // x9
  unsigned int v5; // w19
  _QWORD *v6; // x1

  if ( !*(_QWORD *)(a1 + 16) || (*(_BYTE *)(a1 + 80) & 1) != 0 )
    return 4294967274LL;
  raw_spin_lock(&usb_rediver_lock);
  v3 = a1;
  v4 = &usb_redriver_list;
  while ( 1 )
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &usb_redriver_list )
      break;
    if ( v4 == (_UNKNOWN **)a1 )
    {
      v5 = -17;
      goto LABEL_12;
    }
  }
  v6 = off_A8;
  if ( (_UNKNOWN **)a1 == &usb_redriver_list || off_A8 == (_UNKNOWN **)a1 || *off_A8 != (_UNKNOWN *)&usb_redriver_list )
  {
    _list_add_valid_or_report(a1, off_A8, &usb_redriver_list);
    v5 = 0;
  }
  else
  {
    v5 = 0;
    off_A8 = (_UNKNOWN **)v3;
    *(_QWORD *)v3 = &usb_redriver_list;
    *(_QWORD *)(v3 + 8) = v6;
    *v6 = v3;
  }
LABEL_12:
  raw_spin_unlock(&usb_rediver_lock);
  return v5;
}
