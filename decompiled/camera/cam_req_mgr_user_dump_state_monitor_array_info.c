__int64 __fastcall cam_req_mgr_user_dump_state_monitor_array_info(unsigned int *a1, __int64 a2)
{
  __int64 v4; // x8
  const char *v5; // x3

  *(_QWORD *)a2 = *((_QWORD *)a1 + 1);
  scnprintf(a2 + 8, 128, "%s", (const char *)a1 + 48);
  *(_DWORD *)(a2 + 144) = 8;
  v4 = *a1;
  if ( (unsigned int)v4 > 5 )
    v5 = "INVALID_TYPE";
  else
    v5 = off_448570[v4];
  scnprintf(a2 + 152, 128, "%s", v5);
  *(_DWORD *)(a2 + 288) = 8;
  *(_QWORD *)(a2 + 296) = (int)a1[4];
  *(_QWORD *)(a2 + 304) = *((_QWORD *)a1 + 3);
  *(_QWORD *)(a2 + 312) = *((_QWORD *)a1 + 4);
  *(_QWORD *)(a2 + 320) = *((_QWORD *)a1 + 5) / 1000LL;
  return a2 + 328;
}
