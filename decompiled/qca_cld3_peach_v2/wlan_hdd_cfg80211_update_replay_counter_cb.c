__int64 __fastcall wlan_hdd_cfg80211_update_replay_counter_cb(
        __int64 a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  char v30; // w8
  unsigned __int8 *v31; // x19
  unsigned int v32; // t1
  char v33; // w9
  char v34; // w10
  char v35; // w8
  char v36; // w9
  char v37; // w8
  char v38; // w9
  char v39; // w8
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // [xsp+0h] [xbp-10h] BYREF

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_cfg80211_update_replay_counter_cb",
    0,
    *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808));
  if ( a1 )
  {
    if ( a2 )
    {
      if ( !*(_DWORD *)(a2 + 4) )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: updated replay counter: %llu from fwr",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "wlan_hdd_cfg80211_update_replay_counter_cb",
          *(_QWORD *)(a2 + 16));
        v30 = *(_BYTE *)(a2 + 16);
        v32 = *(unsigned __int8 *)(a2 + 64);
        v31 = (unsigned __int8 *)(a2 + 64);
        v33 = *(v31 - 47);
        v34 = *(v31 - 46);
        HIBYTE(v51) = v30;
        v35 = *(v31 - 45);
        BYTE6(v51) = v33;
        v36 = *(v31 - 44);
        BYTE4(v51) = v35;
        v37 = *(v31 - 43);
        BYTE3(v51) = v36;
        v38 = *(v31 - 42);
        BYTE2(v51) = v37;
        v39 = *(v31 - 41);
        v40 = v31[1];
        v41 = v31[2];
        v42 = v31[5];
        BYTE5(v51) = v34;
        BYTE1(v51) = v38;
        LOBYTE(v51) = v39;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: gtk_rsp_param bssid %02x:%02x:%02x:**:**:%02x",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "wlan_hdd_cfg80211_update_replay_counter_cb",
          v32,
          v40,
          v41,
          v42,
          v51);
        cfg80211_gtk_rekey_notify(*(_QWORD *)(a1 + 32), v31, &v51, 3264);
        goto LABEL_8;
      }
      v20 = "%s: wlan Failed to get replay counter value";
    }
    else
    {
      v20 = "%s: gtk_rsp_param is Null";
    }
  }
  else
  {
    v20 = "%s: HDD adapter is Null";
  }
  qdf_trace_msg(0x33u, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_hdd_cfg80211_update_replay_counter_cb");
LABEL_8:
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: exit",
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             "wlan_hdd_cfg80211_update_replay_counter_cb");
  _ReadStatusReg(SP_EL0);
  return result;
}
