__int64 __fastcall populate_dot11f_power_caps(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _BYTE *a10,
        __int64 a11,
        __int64 a12)
{
  char v13; // w9
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  int v24; // w8

  a10[1] = *(_BYTE *)(a12 + 7033);
  v13 = *(_BYTE *)(a12 + 7032);
  *a10 = 1;
  a10[2] = v13;
  result = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a12 + 16), a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !result )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: mlme_obj invalid",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "populate_dot11f_power_caps");
  v23 = *(_DWORD *)(result + 132);
  if ( v23 )
    a10[2] = v23;
  v24 = *(char *)(result + 137);
  if ( *(_BYTE *)(result + 137) )
  {
    if ( (unsigned __int8)a10[1] < v24 )
      LOBYTE(v24) = a10[1];
    a10[1] = v24;
  }
  return result;
}
