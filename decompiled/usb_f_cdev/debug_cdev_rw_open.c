__int64 __fastcall debug_cdev_rw_open(__int64 a1, __int64 a2)
{
  return single_open(a2, usb_cser_rw_show, *(_QWORD *)(a1 + 696));
}
