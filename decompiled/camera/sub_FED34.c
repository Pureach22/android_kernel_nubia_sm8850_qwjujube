__int64 __fastcall sub_FED34(__int64 a1, __int64 a2, __int64 a3, long double a4)
{
  __int128 v4; // q13

  *(long double *)a3 = a4;
  *(_OWORD *)(a3 + 16) = v4;
  return cam_req_mgr_cb_notify_timer(a1, a2, a3 - 800);
}
