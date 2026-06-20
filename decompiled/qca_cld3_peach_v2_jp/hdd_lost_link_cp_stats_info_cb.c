unsigned __int8 *__fastcall hdd_lost_link_cp_stats_info_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned __int8 *result; // x0
  unsigned __int8 v20; // w8
  unsigned int v21; // w27
  unsigned int v22; // w25
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  unsigned __int8 *v32; // x24
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x20
  __int64 v42; // [xsp+0h] [xbp-10h]

  context = _cds_get_context(51, (__int64)"hdd_lost_link_cp_stats_info_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  result = (unsigned __int8 *)_wlan_hdd_validate_context(
                                (__int64)context,
                                (__int64)"hdd_lost_link_cp_stats_info_cb",
                                v11,
                                v12,
                                v13,
                                v14,
                                v15,
                                v16,
                                v17,
                                v18);
  if ( !(_DWORD)result && *(_DWORD *)(a1 + 88) )
  {
    v20 = 0;
    do
    {
      v21 = v20;
      v22 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 96) + 104LL * v20);
      result = (unsigned __int8 *)hdd_get_link_info_by_vdev((__int64)context, v22);
      if ( result )
      {
        v31 = *(char *)(*(_QWORD *)(a1 + 96) + 104LL * v21 + 8);
        if ( !*(_BYTE *)(*(_QWORD *)(a1 + 96) + 104LL * v21 + 8) )
        {
          v41 = jiffies;
          if ( hdd_lost_link_cp_stats_info_cb___last_ticks - jiffies + 125 < 0 )
          {
            result = (unsigned __int8 *)qdf_trace_msg(
                                          0x33u,
                                          8u,
                                          "%s: Invalid RSSI value sent by FW",
                                          v23,
                                          v24,
                                          v25,
                                          v26,
                                          v27,
                                          v28,
                                          v29,
                                          v30,
                                          "hdd_lost_link_cp_stats_info_cb");
            hdd_lost_link_cp_stats_info_cb___last_ticks = v41;
          }
          return result;
        }
        v32 = result;
        *((_DWORD *)result + 605) = v31;
        result[1512] = v31;
        result = (unsigned __int8 *)hdd_adapter_get_link_mac_addr(result);
        if ( !result )
          return result;
        LODWORD(v42) = result[5];
        result = (unsigned __int8 *)qdf_trace_msg(
                                      0x33u,
                                      8u,
                                      "%s: rssi %d for %02x:%02x:%02x:**:**:%02x",
                                      v33,
                                      v34,
                                      v35,
                                      v36,
                                      v37,
                                      v38,
                                      v39,
                                      v40,
                                      "hdd_lost_link_cp_stats_info_cb",
                                      *((unsigned int *)v32 + 605),
                                      *result,
                                      result[1],
                                      result[2],
                                      v42);
      }
      else
      {
        result = (unsigned __int8 *)qdf_trace_msg(
                                      0x33u,
                                      8u,
                                      "%s: invalid vdev %d",
                                      v23,
                                      v24,
                                      v25,
                                      v26,
                                      v27,
                                      v28,
                                      v29,
                                      v30,
                                      "hdd_lost_link_cp_stats_info_cb",
                                      v22);
      }
      v20 = v21 + 1;
    }
    while ( *(_DWORD *)(a1 + 88) > (unsigned int)(unsigned __int8)(v21 + 1) );
  }
  return result;
}
