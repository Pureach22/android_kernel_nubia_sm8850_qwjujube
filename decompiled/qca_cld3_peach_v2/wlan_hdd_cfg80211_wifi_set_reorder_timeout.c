__int64 __fastcall wlan_hdd_cfg80211_wifi_set_reorder_timeout(
        __int64 *a1,
        _QWORD *a2,
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
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  int v14; // w12
  __int64 v15; // x8
  __int64 v16; // x8
  int v17; // w10
  int v18; // w9
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  _DWORD v29[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = a2[31];
  v10 = a2[32];
  if ( !v11 )
  {
    if ( !v10 && !a2[33] && !a2[34] )
    {
      result = 0;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( !v10 || (v12 = a2[33]) == 0 || (v13 = a2[34]) == 0 )
  {
LABEL_14:
    v28 = "%s: four AC timeout val are required MAC";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v28, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_cfg80211_wifi_set_reorder_timeout");
    result = 4294967274LL;
    goto LABEL_16;
  }
  v29[0] = *(_DWORD *)(v11 + 4);
  v14 = *(_DWORD *)(v10 + 4);
  v15 = *a1;
  v29[1] = v14;
  v16 = *(_QWORD *)(v15 + 24);
  v17 = *(_DWORD *)(v12 + 4);
  v29[2] = v17;
  v18 = *(_DWORD *)(v13 + 4);
  v29[3] = v18;
  if ( (unsigned int)(v29[0] - 10) > 0x3DE
    || (unsigned int)(v14 - 10) > 0x3DE
    || (unsigned int)(v17 - 10) > 0x3DE
    || (unsigned int)(v18 - 10) > 0x3DE )
  {
    v28 = "%s: one of the timeout value is not in range";
    goto LABEL_15;
  }
  result = sme_set_reorder_timeout(*(_QWORD *)(v16 + 16), v29);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set reorder timeout err %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_hdd_cfg80211_wifi_set_reorder_timeout",
      (unsigned int)result);
    result = 0xFFFFFFFFLL;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
