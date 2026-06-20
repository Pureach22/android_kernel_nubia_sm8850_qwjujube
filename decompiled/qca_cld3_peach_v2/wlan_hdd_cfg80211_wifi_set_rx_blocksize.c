__int64 __fastcall wlan_hdd_cfg80211_wifi_set_rx_blocksize(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x8
  __int16 v14; // w11
  int v15; // w10
  int v16; // w12
  int v17; // w9
  __int64 v18; // x0
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
  _DWORD v29[2]; // [xsp+8h] [xbp-18h] BYREF
  int v30; // [xsp+10h] [xbp-10h]
  int v31; // [xsp+14h] [xbp-Ch]
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 288);
  if ( !v10 )
  {
    result = 0;
    goto LABEL_10;
  }
  v11 = *a1;
  v12 = *(_QWORD *)(a2 + 280);
  v30 = 0;
  v13 = *(_QWORD *)(v11 + 24);
  if ( !v12 )
  {
    v28 = "%s: Both Peer MAC and windows limit required";
LABEL_9:
    qdf_trace_msg(0x33u, 2u, v28, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_cfg80211_wifi_set_rx_blocksize");
    result = 4294967274LL;
    goto LABEL_10;
  }
  v14 = *(_WORD *)(v12 + 8);
  v15 = *(_DWORD *)(v12 + 4);
  v16 = *((unsigned __int8 *)a1 + 8);
  LOWORD(v30) = v14;
  v29[0] = v16;
  v29[1] = v15;
  v17 = *(_DWORD *)(v10 + 4);
  if ( (unsigned int)(v17 - 1) > 0x3F )
  {
    v28 = "%s: window size val is not in range";
    goto LABEL_9;
  }
  v18 = *(_QWORD *)(v13 + 16);
  v31 = v17;
  result = sme_set_rx_set_blocksize(v18, v29);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set aggr sizes err %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_hdd_cfg80211_wifi_set_rx_blocksize",
      (unsigned int)result);
    result = 0xFFFFFFFFLL;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
