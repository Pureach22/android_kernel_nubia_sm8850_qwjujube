__int64 __fastcall usb_gsi_rw_open(__int64 a1, __int64 a2)
{
  return single_open(a2, usb_gsi_rw_show, *(_QWORD *)(a1 + 696));
}
