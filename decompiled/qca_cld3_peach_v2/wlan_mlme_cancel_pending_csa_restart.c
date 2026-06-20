__int64 __fastcall wlan_mlme_cancel_pending_csa_restart(
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
  unsigned int v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  unsigned int v23[2]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v24; // [xsp+10h] [xbp-50h]
  __int64 v25; // [xsp+18h] [xbp-48h]
  __int64 v26; // [xsp+20h] [xbp-40h]
  __int64 v27; // [xsp+28h] [xbp-38h]
  __int64 v28; // [xsp+30h] [xbp-30h]
  _QWORD v29[5]; // [xsp+38h] [xbp-28h] BYREF

  v29[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(unsigned __int8 *)(a10 + 168);
  v27 = a10;
  v28 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v23[0] = 27;
  v23[1] = v13;
  if ( (wlan_serialization_is_cmd_present_in_pending_queue(a1, a2, a3, a4, a5, a6, a7, a8, 0, v23) & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Cmd already exist in the pending queue vdev:%u",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_mlme_cancel_pending_csa_restart",
      v13);
    *a11 = 1;
  }
  v29[0] = 0x1B00000000LL;
  v29[1] = 0x600000000LL;
  v29[2] = a10;
  v29[3] = 2;
  result = wlan_serialization_cancel_request((unsigned int *)v29, v14, v15, v16, v17, v18, v19, v20, v21);
  _ReadStatusReg(SP_EL0);
  return result;
}
