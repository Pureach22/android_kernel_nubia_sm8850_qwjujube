__int64 __fastcall hdd_hostapd_chan_change_started(_DWORD *a1, int a2, const void *a3)
{
  a1[1106] = a2;
  qdf_mem_copy(a1 + 1107, a3, 0x10u);
  a1[1111] = 0;
  return queue_work_on(32, system_wq, a1 + 1112);
}
