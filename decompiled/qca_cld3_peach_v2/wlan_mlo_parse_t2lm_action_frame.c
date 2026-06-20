__int64 __fastcall wlan_mlo_parse_t2lm_action_frame(
        __int64 a1,
        _BYTE *a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  const char *v14; // x3
  unsigned int v15; // w0
  int v17; // w8
  unsigned int v18; // w2
  unsigned __int8 *v19; // x1
  char v20; // w8

  if ( a4 == 3 )
    return 0;
  if ( a4 == 2 )
  {
    *(_DWORD *)a1 = 2;
    if ( a3 <= 4 )
    {
      v14 = "wlan_mlo_parse_t2lm_response_action_frame";
      goto LABEL_8;
    }
    *(_BYTE *)(a1 + 4) = a2[2];
    v17 = *(unsigned __int16 *)(a2 + 3);
    *(_DWORD *)(a1 + 168) = v17;
    if ( v17 != 134 )
    {
      v15 = 0;
      return qdf_status_to_os_return(v15);
    }
    v18 = a3 - 5;
    v19 = a2 + 5;
LABEL_14:
    v15 = wlan_mlo_parse_t2lm_ie((_DWORD *)a1, v19, v18, a5, a6, a7, a8, a9, a10, a11, a12);
    return qdf_status_to_os_return(v15);
  }
  if ( a4 != 1 )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Invalid category:%d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_mlo_parse_t2lm_action_frame",
      a4,
      v12,
      v13);
    return 0;
  }
  *(_DWORD *)a1 = 1;
  if ( a3 > 2 )
  {
    v20 = a2[2];
    v18 = a3 - 3;
    v19 = a2 + 3;
    *(_BYTE *)(a1 + 4) = v20;
    goto LABEL_14;
  }
  v14 = "wlan_mlo_parse_t2lm_request_action_frame";
LABEL_8:
  qdf_trace_msg(0x99u, 2u, "%s: Action frame length %d too short", a5, a6, a7, a8, a9, a10, a11, a12, v14, v12, v13);
  v15 = 16;
  return qdf_status_to_os_return(v15);
}
