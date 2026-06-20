__int64 __fastcall wlan_hdd_ll_stats_get(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  char v26; // w8
  unsigned int v27; // w22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x20
  unsigned int v37; // [xsp+0h] [xbp-20h] BYREF
  __int64 v38; // [xsp+4h] [xbp-1Ch]
  __int64 v39; // [xsp+Ch] [xbp-14h]
  int v40; // [xsp+14h] [xbp-Ch]
  __int64 v41; // [xsp+18h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)a1;
  v40 = 0;
  v39 = 0;
  v38 = 0;
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    v15 = jiffies;
    if ( wlan_hdd_ll_stats_get___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: Command not allowed in FTM mode",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "wlan_hdd_ll_stats_get");
      wlan_hdd_ll_stats_get___last_ticks = v15;
    }
    result = 0xFFFFFFFFLL;
  }
  else if ( hdd_cm_is_vdev_roaming(a1) )
  {
    v25 = jiffies;
    if ( wlan_hdd_ll_stats_get___last_ticks_17 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Roaming in progress, cannot process the request",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_hdd_ll_stats_get");
      wlan_hdd_ll_stats_get___last_ticks_17 = v25;
    }
    result = 4294967280LL;
  }
  else if ( (*(_BYTE *)(v6 + 42080) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_hdd_ll_stats_get",
      *(_QWORD *)(v6 + 32) + 296LL);
    v26 = *(_BYTE *)(a1 + 8);
    v37 = a2;
    HIDWORD(v38) = a3;
    LOBYTE(v38) = v26;
    v27 = ((__int64 (__fastcall *)(__int64, unsigned int *))wlan_hdd_send_ll_stats_req)(a1, &v37);
    if ( v27 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Send LL stats req failed, id:%u, mask:%d, session:%d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wlan_hdd_ll_stats_get",
        a2,
        a3,
        *(unsigned __int8 *)(a1 + 8));
    qdf_trace_msg(0x33u, 8u, "%s: exit", v28, v29, v30, v31, v32, v33, v34, v35, "wlan_hdd_ll_stats_get");
    result = v27;
  }
  else
  {
    v36 = jiffies;
    if ( wlan_hdd_ll_stats_get___last_ticks_19 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x33u, 4u, "%s: LL_STATs not set", v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_ll_stats_get");
      wlan_hdd_ll_stats_get___last_ticks_19 = v36;
    }
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
