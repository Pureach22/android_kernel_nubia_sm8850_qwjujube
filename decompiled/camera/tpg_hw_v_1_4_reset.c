__int64 __fastcall tpg_hw_v_1_4_reset(__int64 a1)
{
  __int64 v1; // x8
  int *v2; // x19
  __int64 v3; // x20
  int v5; // w0

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "tpg_hw_v_1_4_reset",
             637,
             "invalid params");
  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "tpg_hw_v_1_4_reset",
             637,
             "invalid params");
  v2 = *(int **)(v1 + 24);
  if ( !v2 )
    return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "tpg_hw_v_1_4_reset",
             637,
             "invalid params");
  v3 = *(_QWORD *)(a1 + 40);
  cam_io_w_mb(0, *(_QWORD *)(v3 + 288) + v2[25]);
  cam_io_w_mb(0, *(_QWORD *)(v3 + 288) + v2[121]);
  cam_io_w_mb(1, *(_QWORD *)(v3 + 288) + v2[122]);
  cam_io_w_mb(1, *(_QWORD *)(v3 + 288) + v2[124]);
  cam_io_w_mb(1, *(_QWORD *)(v3 + 288) + v2[125]);
  v5 = cam_io_r_mb(*(_QWORD *)(v3 + 288) + *v2);
  return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           0x200000000LL,
           3,
           "tpg_hw_v_1_4_reset",
           662,
           "TPG[%d] TPG HW version: 0x%x started",
           *(_DWORD *)a1,
           v5);
}
