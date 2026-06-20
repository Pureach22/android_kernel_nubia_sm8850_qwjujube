// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_610014(
        __int64 a1,
        __int64 a2,
        const char *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w24

  if ( (v20 & 0x80000000) == 0 )
    return wlan_nan_handle_pasn_peer_create_rsp(a1, a2, a3, a4);
  qdf_trace_msg(0x53u, 2u, a3, a5, a6, a7, a8, a9, a10, a11, a12);
  qdf_trace_msg(0x53u, 2u, "%s: vdev_nan_obj is null", v12, v13, v14, v15, v16, v17, v18, v19, "nan_handle_confirm");
  _ReadStatusReg(SP_EL0);
  return 0;
}
