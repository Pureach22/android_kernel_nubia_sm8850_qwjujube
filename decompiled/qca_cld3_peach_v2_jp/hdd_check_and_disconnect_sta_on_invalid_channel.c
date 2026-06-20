__int64 __fastcall hdd_check_and_disconnect_sta_on_invalid_channel(__int64 a1, int a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
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

  result = hdd_get_adapter(a1, 0);
  if ( !result )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: STA adapter does not exist",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "hdd_check_and_disconnect_sta_on_invalid_channel");
  v13 = result;
  if ( (*(_QWORD *)(result + 1640) & 1) != 0 && result != -52832 )
  {
    do
    {
      result = hdd_get_link_info_home_channel(v13 + 52832);
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
          *(unsigned __int8 *)(v13 + 52840),
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
          result = wlan_hdd_cm_issue_disconnect(v13 + 52832, a2, 0);
        }
      }
    }
    while ( !(unsigned __int8)~(-910593773 * ((unsigned int)(v13 - *(_DWORD *)(v13 + 52832)) >> 4))
         && (*(_QWORD *)(v13 + 1640) & 1) != 0 );
  }
  return result;
}
