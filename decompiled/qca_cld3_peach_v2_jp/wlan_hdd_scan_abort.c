__int64 __fastcall wlan_hdd_scan_abort(unsigned __int8 *a1)
{
  wlan_abort_scan(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 8LL), -1, a1[8], 0xFFFFFFFF, 1);
  return 0;
}
