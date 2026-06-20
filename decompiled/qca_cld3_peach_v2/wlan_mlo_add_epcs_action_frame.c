__int64 __fastcall wlan_mlo_add_epcs_action_frame(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w8
  __int64 v13; // x4
  __int64 v14; // x19

  v12 = a2[1];
  v13 = *a2;
  if ( v12 == 5 )
  {
    *(_BYTE *)a1 = v13;
    *(_BYTE *)(a1 + 1) = a2[1];
    return a1 + 2;
  }
  else
  {
    if ( v12 == 4 )
    {
      *(_BYTE *)a1 = v13;
      v14 = a1 + 5;
      *(_BYTE *)(a1 + 1) = a2[1];
      *(_BYTE *)(a1 + 2) = *((_DWORD *)a2 + 1);
      *(_WORD *)(a1 + 3) = *((_DWORD *)a2 + 2);
      qdf_trace_msg(
        0xA0u,
        4u,
        "%s: EPCS response frame: category:%d action:%d dialog_token:%d status_code:%d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_mlo_add_epcs_response_action_frame",
        *a2,
        a2[1],
        *((unsigned int *)a2 + 1),
        *((unsigned int *)a2 + 2),
        v10,
        v11);
    }
    else if ( v12 == 3 )
    {
      *(_BYTE *)a1 = v13;
      v14 = a1 + 3;
      *(_BYTE *)(a1 + 1) = a2[1];
      *(_BYTE *)(a1 + 2) = *((_DWORD *)a2 + 1);
      qdf_trace_msg(
        0xA0u,
        4u,
        "%s: EPCS frame: category:%d action:%d dialog_token:%d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_mlo_add_epcs_request_action_frame",
        *a2,
        a2[1],
        *((unsigned int *)a2 + 1),
        v10,
        v11);
    }
    else
    {
      v14 = a1;
      qdf_trace_msg(
        0xA0u,
        2u,
        "%s: Invalid category:%d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_mlo_add_epcs_action_frame",
        v13,
        v10,
        v11);
    }
    return v14;
  }
}
