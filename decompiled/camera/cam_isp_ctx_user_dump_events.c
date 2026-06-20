_QWORD *__fastcall cam_isp_ctx_user_dump_events(_QWORD *a1, _QWORD *a2)
{
  __int64 v4; // x0
  __int64 v6; // x1

  v4 = ns_to_timespec64(a1[1]);
  *a2 = *a1;
  a2[1] = v4;
  a2[2] = v6 / 1000;
  return a2 + 3;
}
