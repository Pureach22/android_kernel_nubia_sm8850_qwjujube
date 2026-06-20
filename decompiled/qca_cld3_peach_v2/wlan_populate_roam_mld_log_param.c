__int64 __fastcall wlan_populate_roam_mld_log_param(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x22
  __int64 v15; // x4
  unsigned int v16; // w20
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  int v20; // w8

  v3 = *(_QWORD *)(a1 + 216);
  if ( !v3 )
    return 4;
  result = wlan_scan_get_mld_addr_by_link_addr(v3, a2, a2 + 57);
  if ( (_DWORD)result )
  {
    v14 = jiffies;
    if ( wlan_populate_roam_mld_log_param___last_ticks - jiffies + 125 < 0 )
    {
      v15 = *(unsigned __int8 *)(a1 + 168);
      v16 = result;
      if ( a2 )
      {
        v17 = *a2;
        v18 = a2[1];
        v19 = a2[2];
        v20 = a2[5];
      }
      else
      {
        v19 = 0;
        v17 = 0;
        v18 = 0;
        v20 = 0;
      }
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev:%d Not able to fetch MLD addr for link addr: %02x:%02x:%02x:**:**:%02x",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_populate_roam_mld_log_param",
        v15,
        v17,
        v18,
        v19,
        v20);
      wlan_populate_roam_mld_log_param___last_ticks = v14;
      return v16;
    }
  }
  return result;
}
