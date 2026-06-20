// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_3AE17C(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x21

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: driver is transitioning! Using default(BE) queue.",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "__hdd_wmm_select_queue");
  *(_QWORD *)(v9 + 3792) = v10;
  *(_DWORD *)(v8 + 144) = 0;
  _ReadStatusReg(SP_EL0);
  return 13;
}
