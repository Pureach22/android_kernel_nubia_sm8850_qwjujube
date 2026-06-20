__int64 __fastcall wlan_mlme_check_pdev_restart(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _BYTE *a11)
{
  unsigned int v12; // w20
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v23; // [xsp+10h] [xbp-30h]
  __int64 v24; // [xsp+18h] [xbp-28h]
  __int64 v25; // [xsp+20h] [xbp-20h]
  __int64 v26; // [xsp+28h] [xbp-18h]
  __int64 v27; // [xsp+30h] [xbp-10h]
  __int64 v28; // [xsp+38h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a10 + 104);
  v26 = a10;
  v27 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v22[0] = 26;
  v22[1] = v12;
  result = wlan_serialization_is_cmd_present_in_active_queue(a1, a2, a3, a4, a5, a6, a7, a8, 0, v22);
  if ( (result & 1) != 0 )
  {
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: Pdev restart already in the active queue vdev:%u",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "wlan_mlme_check_pdev_restart",
               v12);
    *a11 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
