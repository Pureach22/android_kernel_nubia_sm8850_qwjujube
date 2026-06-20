__int64 __fastcall wlan_hdd_twt_init(_QWORD *a1)
{
  __int64 result; // x0

  result = osif_twt_send_requestor_enable_cmd(*a1, 0);
  a1[887] = hdd_twt_update_work_handler;
  a1[883] = 0xFFFFFFFE00000LL;
  a1[888] = a1;
  a1[884] = a1 + 884;
  a1[885] = a1 + 884;
  a1[886] = _qdf_defer_func;
  return result;
}
