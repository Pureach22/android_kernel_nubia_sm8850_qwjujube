__int64 __fastcall hdd_softap_sta_deauth(
        __int64 *a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v11; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  _BYTE v40[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v40[0] = 0;
  v11 = *(__int64 **)(v10 + 24);
  if ( v11 )
  {
    wlan_mlme_get_sap_bcast_deauth_enabled(*v11, v40);
    qdf_trace_msg(0x33u, 8u, "%s: enter", v14, v15, v16, v17, v18, v19, v20, v21, "hdd_softap_sta_deauth");
    if ( (v40[0] & 1) == 0 && (*a2 & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Vdev %d sap_bcast_deauth_enabled %d, Ignore request to deauth bc/mc station ",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_softap_sta_deauth",
        *((unsigned __int8 *)a1 + 8),
        0);
      result = 5;
    }
    else
    {
      v30 = wlansap_deauth_sta(a1[34], a2);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v31, v32, v33, v34, v35, v36, v37, v38, "hdd_softap_sta_deauth");
      result = v30;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_softap_sta_deauth");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
