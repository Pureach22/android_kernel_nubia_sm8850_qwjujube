__int64 __fastcall wlan_hdd_twt_init(_QWORD *a1)
{
  __int64 result; // x0

  result = osif_twt_send_requestor_enable_cmd(*a1, 0);
  a1[884] = hdd_twt_update_work_handler;
  a1[880] = 0xFFFFFFFE00000LL;
  a1[885] = a1;
  a1[881] = a1 + 881;
  a1[882] = a1 + 881;
  a1[883] = _qdf_defer_func;
  return result;
}
