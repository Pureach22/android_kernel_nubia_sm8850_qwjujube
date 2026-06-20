_QWORD *__fastcall cam_isp_ctx_user_dump_state_monitor_array_info(_QWORD *a1, _QWORD *a2)
{
  __int64 v2; // x8

  *a2 = a1[3];
  a2[1] = a1[4] / 1000LL;
  a2[2] = a1[2];
  v2 = a1[1];
  a2[3] = v2;
  return a2 + 4;
}
