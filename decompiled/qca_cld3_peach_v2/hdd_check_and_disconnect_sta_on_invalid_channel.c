__int64 __fastcall hdd_check_and_disconnect_sta_on_invalid_channel(__int64 a1, int a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  __int64 v13; // x25
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w26
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10

  result = hdd_get_adapter(a1, 0);
  if ( !result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: STA adapter does not exist",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "hdd_check_and_disconnect_sta_on_invalid_channel");
  v12 = result;
  if ( (*(_QWORD *)(result + 1640) & 1) != 0 && (v13 = result + 52840, result != -52840)
    || (*(_QWORD *)(result + 1640) & 2) != 0 && (v13 = result + 58928, result != -58928)
    || (*(_QWORD *)(result + 1640) & 4) != 0 && (v13 = result + 65016, result != -65016) )
  {
    do
    {
      result = hdd_get_link_info_home_channel(v13);
      if ( (_DWORD)result )
      {
        v22 = result;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: VDEV-%d STA connected on %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "hdd_check_and_disconnect_sta_on_invalid_channel",
          *(unsigned __int8 *)(v13 + 8),
          (unsigned int)result);
        result = sme_is_channel_valid(*(_QWORD *)(a1 + 16), v22);
        if ( (result & 1) == 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: chan %d not valid, issue disconnect",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "hdd_check_and_disconnect_sta_on_invalid_channel",
            v22);
          result = wlan_hdd_cm_issue_disconnect(v13, a2, 0);
        }
      }
      if ( (unsigned __int8)(73 * ((unsigned int)(v13 - *(_DWORD *)v13 - 52840) >> 3) + 1) > 2u )
        break;
      v31 = (unsigned __int8)(73 * ((unsigned int)(v13 - *(_DWORD *)v13 - 52840) >> 3) + 1);
      v13 = 0;
      v32 = v12 + 52840 + 6088LL * (unsigned int)v31;
      do
      {
        if ( v13 )
          break;
        v33 = *(_QWORD *)(v12 + 1640) >> v31++;
        v13 = (v33 << 63 >> 63) & v32;
        v32 += 6088;
      }
      while ( v31 != 3 );
    }
    while ( v13 );
  }
  return result;
}
