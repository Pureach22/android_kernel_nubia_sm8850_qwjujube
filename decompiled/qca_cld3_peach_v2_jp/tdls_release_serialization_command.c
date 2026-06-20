__int64 __fastcall tdls_release_serialization_command(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x4
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  unsigned int v20[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v21 = 0;
  v20[1] = a2;
  v22 = a1;
  v23 = 0;
  if ( a2 - 13 > 2 )
    v10 = "UNKNOWN";
  else
    v10 = off_A2B9C0[a2 - 13];
  qdf_trace_msg(0, 8u, "%s: release %s", a3, a4, a5, a6, a7, a8, a9, a10, "tdls_release_serialization_command", v10);
  result = wlan_serialization_remove_cmd(v20, v11, v12, v13, v14, v15, v16, v17, v18);
  _ReadStatusReg(SP_EL0);
  return result;
}
