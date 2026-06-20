__int64 __fastcall usb_cser_notify_modem(__int64 result, char a2, __int64 a3, __int64 a4)
{
  int v4; // w8

  if ( !result )
    return printk(&unk_8F9B, "usb_cser_notify_modem", a3, a4);
  v4 = 2 * (a2 & 3);
  if ( v4 != *(_DWORD *)(result + 1544) )
  {
    *(_DWORD *)(result + 1544) = v4;
    *(_BYTE *)(result + 1548) = 1;
    return _wake_up(result + 1096, 3, 1, 0);
  }
  return result;
}
