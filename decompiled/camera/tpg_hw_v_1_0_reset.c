__int64 __fastcall tpg_hw_v_1_0_reset(__int64 a1)
{
  __int64 v1; // x19
  int v3; // w0
  int v4; // w21
  __int64 v5; // x8

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x200000000LL,
             1,
             "tpg_hw_v_1_0_reset",
             193,
             "invalid argument");
  v1 = *(_QWORD *)(a1 + 40);
  cam_io_w_mb(0, *(_QWORD *)(v1 + 288) + 96LL);
  v3 = cam_io_r_mb(*(_QWORD *)(v1 + 312) + 28LL);
  v4 = 1 << *(_DWORD *)a1;
  v5 = *(_QWORD *)(v1 + 312);
  LODWORD(v1) = v3;
  cam_io_w_mb(v3 & (unsigned int)~v4, v5 + 28);
  return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           0x200000000LL,
           3,
           "tpg_hw_v_1_0_reset",
           209,
           "TPG:%d Reset Top Mux: 0x%x",
           *(_DWORD *)a1,
           (unsigned int)v1 & ~v4);
}
