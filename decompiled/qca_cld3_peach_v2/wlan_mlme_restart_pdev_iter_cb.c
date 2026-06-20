__int64 __fastcall wlan_mlme_restart_pdev_iter_cb(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30[2]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v31; // [xsp+10h] [xbp-50h]
  __int64 v32; // [xsp+18h] [xbp-48h]
  __int64 v33; // [xsp+20h] [xbp-40h]
  __int64 v34; // [xsp+28h] [xbp-38h]
  __int64 v35; // [xsp+30h] [xbp-30h]
  _QWORD v36[5]; // [xsp+38h] [xbp-28h] BYREF

  v36[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a10 + 168);
  v36[0] = 0x1900000000LL;
  v36[1] = 0x600000000LL;
  v34 = a10;
  v35 = 0;
  v30[0] = 26;
  v30[1] = v12;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v36[2] = a10;
  v36[3] = 2;
  wlan_serialization_cancel_request((unsigned int *)v36, a1, a2, a3, a4, a5, a6, a7, a8);
  result = wlan_serialization_is_cmd_present_in_pending_queue(v13, v14, v15, v16, v17, v18, v19, v20, 0, v30);
  if ( (result & 1) != 0 )
  {
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: Cmd already exist in the pending queue vdev:%u",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "wlan_mlme_restart_pdev_iter_cb",
               v12);
    *a11 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
