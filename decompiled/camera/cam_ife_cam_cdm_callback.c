__int64 __fastcall cam_ife_cam_cdm_callback(unsigned int a1, __int64 a2, int a3, __int64 *a4)
{
  __int64 v6; // x21
  char v7; // w8
  __int64 result; // x0
  void (__fastcall *v9)(__int64, __int64 *); // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x1

  if ( !a2 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_ife_cam_cdm_callback",
             5959,
             "Invalid args");
  if ( a3 == 2 )
  {
    v9 = *(void (__fastcall **)(__int64, __int64 *))(a2 + 48);
    if ( v9 )
    {
      v10 = *(_QWORD *)(a2 + 32);
      if ( *((_DWORD *)v9 - 1) != 1863972096 )
        __break(0x8228u);
      v9(v10, a4);
    }
  }
  else if ( a3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, _QWORD, _DWORD))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_cam_cdm_callback",
      5981,
      "Called by CDM hdl=0x%x, udata=%pK, status=%d, cdm_req=%llu ctx_idx: %u",
      a1,
      a2,
      a3,
      *(_QWORD *)(a2 + 9424),
      *(_DWORD *)(a2 + 56));
  }
  else
  {
    v6 = *a4;
    complete_all(a2 + 8864);
    *(_DWORD *)(a2 + 8848) = 1;
    v7 = debug_mdl;
    *(_QWORD *)(a2 + 8856) = v6;
    if ( (v7 & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, __int64, _DWORD, __int64, _DWORD, _QWORD))cam_print_log)(
        3,
        v7 & 8,
        4,
        "cam_ife_cam_cdm_callback",
        5974,
        "CDM hdl=0x%x, udata=%pK, status=%d, cookie=%u ctx_index=%u cdm_req=%llu",
        a1,
        a2,
        0,
        v6,
        *(_DWORD *)(a2 + 56),
        *(_QWORD *)(a2 + 9424));
  }
  v11 = ktime_get_with_offset(2);
  *(_QWORD *)(a2 + 9488) = ns_to_timespec64(v11);
  *(_QWORD *)(a2 + 9496) = v12;
  v13 = ktime_get_with_offset(1);
  result = ns_to_timespec64(v13);
  *(_QWORD *)(a2 + 9504) = result;
  *(_QWORD *)(a2 + 9512) = v14;
  return result;
}
