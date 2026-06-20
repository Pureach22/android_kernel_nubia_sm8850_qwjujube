__int64 __fastcall wlan_vdev_mlme_ser_remove_request(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x4
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  unsigned int v24[4]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v25; // [xsp+18h] [xbp-18h]
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(unsigned __int8 *)(a1 + 168);
  v26 = 1;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Vdev:%d remove cmd:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_vdev_mlme_ser_remove_request",
    v14,
    a3);
  v25 = a1;
  v24[0] = 0;
  v24[1] = a3;
  v24[2] = a2;
  v24[3] = 8;
  result = wlan_serialization_remove_cmd(v24, v15, v16, v17, v18, v19, v20, v21, v22);
  _ReadStatusReg(SP_EL0);
  return result;
}
