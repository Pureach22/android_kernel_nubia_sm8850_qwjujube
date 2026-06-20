_QWORD *__fastcall cam_isp_ctx_user_dump_timer(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x19
  __int64 v8; // x1
  __int64 v10; // x1

  v3 = *(_QWORD *)(a1 + 32);
  v5 = ktime_get_with_offset(1);
  v6 = *(_QWORD *)(a1 + 24);
  v7 = v5;
  *a2 = v6;
  a2[1] = ns_to_timespec64(*(_QWORD *)(v3 + 4464));
  ns_to_timespec64(*(_QWORD *)(v3 + 4464));
  a2[2] = v8 / 1000;
  a2[3] = ns_to_timespec64(v7);
  ns_to_timespec64(v7);
  a2[4] = v10 / 1000;
  return a2 + 5;
}
