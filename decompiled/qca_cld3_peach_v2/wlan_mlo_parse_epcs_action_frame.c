__int64 __fastcall wlan_mlo_parse_epcs_action_frame(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w4
  __int16 v15; // w8
  unsigned __int8 *v16; // x0
  __int16 v17; // w9
  __int16 v18; // w8
  int v20; // [xsp+0h] [xbp-10h]

  v11 = a2[1];
  switch ( v11 )
  {
    case 5:
      *(_DWORD *)a1 = 5;
      qdf_trace_msg(
        0xA0u,
        4u,
        "%s: EPCS frame rcv : category:%d action:%d frmlen %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_mlo_parse_epcs_teardown_action_frame",
        *a2,
        a2[1],
        a3);
      return 0;
    case 4:
      v17 = *(unsigned __int8 *)(a1 + 7);
      *(_DWORD *)a1 = 4;
      *(_BYTE *)(a1 + 4) = a2[2];
      *(_WORD *)(a1 + 6) = v17 << 8;
      v18 = a2[3];
      *(_WORD *)(a1 + 6) = v18;
      *(_WORD *)(a1 + 6) = v18 | (a2[4] << 8);
      v20 = a2[4];
      qdf_trace_msg(
        0xA0u,
        4u,
        "%s: EPCS frame rcv : category:%d action:%d dialog_token:%d status %x %x frmlen %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_mlo_parse_epcs_response_action_frame",
        *a2,
        a2[1],
        a2[2],
        a2[3],
        v20,
        a3);
      if ( a3 >= 6 )
      {
        v15 = -5;
        v16 = a2 + 5;
        return mlo_process_ml_priorityaccess_ie(v16, (unsigned __int16)(a3 + v15), a1 + 8);
      }
      return 0;
    case 3:
      *(_DWORD *)a1 = 3;
      *(_BYTE *)(a1 + 4) = a2[2];
      qdf_trace_msg(
        0xA0u,
        4u,
        "%s: EPCS frame rcv : category:%d action:%d dialog_token:%d frmlen %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_mlo_parse_epcs_request_action_frame",
        *a2,
        a2[1]);
      if ( a3 >= 4 )
      {
        v15 = -3;
        v16 = a2 + 3;
        return mlo_process_ml_priorityaccess_ie(v16, (unsigned __int16)(a3 + v15), a1 + 8);
      }
      return 0;
  }
  qdf_trace_msg(
    0xA0u,
    2u,
    "%s: Invalid action :%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_mlo_parse_epcs_action_frame");
  return 4;
}
