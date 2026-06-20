__int64 __fastcall osif_twt_ack_complete_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x0
  int v15; // w9
  const char *v16; // x2

  v4 = osif_request_get(a3);
  if ( !v4 )
  {
    v16 = "%s: obsolete request";
LABEL_7:
    qdf_trace_msg(0x48u, 2u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "osif_twt_ack_complete_cb");
    return 16;
  }
  v13 = v4;
  v14 = osif_request_priv(v4);
  if ( !v14 )
  {
    v16 = "%s: obsolete status_priv";
    goto LABEL_7;
  }
  if ( *(_DWORD *)(v14 + 16) == *(_DWORD *)(a2 + 16) )
  {
    *(_DWORD *)v14 = *(_DWORD *)a2;
    v15 = *(_DWORD *)(a2 + 4);
    *(_WORD *)(v14 + 8) = *(_WORD *)(a2 + 8);
    *(_DWORD *)(v14 + 4) = v15;
    *(_DWORD *)(v14 + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v14 + 20) = *(_DWORD *)(a2 + 20);
    osif_request_complete(v13);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid TWT ack. Expected cmd: %d Actual cmd: %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "osif_twt_ack_complete_cb");
  }
  osif_request_put(v13);
  return 0;
}
