__int64 __fastcall cam_icp_v1_power_resume(__int64 a1, char a2)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 result; // x0
  __int16 v7; // w19
  int v8; // w0

  v2 = *(_QWORD *)(a1 + 408);
  v3 = *(_QWORD *)(a1 + 3392);
  cam_io_w_mb(512, v2 + 8);
  cam_io_w_mb(16, v2 + 4);
  if ( (a2 & 1) != 0 )
    v5 = 4215312;
  else
    v5 = 4624;
  cam_io_w_mb(v5, v2 + 8);
  result = cam_io_w_mb(*(unsigned int *)(v3 + 4), v2 + 60);
  v7 = debug_mdl;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v8 = cam_io_r_mb(v2 + 60);
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             v7 & 0x100,
             4,
             "cam_icp_v1_power_resume",
             355,
             "icp_v1 qos-val : 0x%x",
             v8);
  }
  return result;
}
