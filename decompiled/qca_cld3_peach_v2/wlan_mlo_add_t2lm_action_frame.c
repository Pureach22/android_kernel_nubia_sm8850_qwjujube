char *__fastcall wlan_mlo_add_t2lm_action_frame(
        unsigned __int8 *a1,
        unsigned __int8 *a2,
        unsigned int *a3,
        int a4,
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
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  char *result; // x0
  char *v25; // x20

  switch ( a4 )
  {
    case 3:
      *a1 = *a2;
      a1[1] = a2[1];
      return (char *)(a1 + 2);
    case 2:
      v25 = (char *)(a1 + 5);
      *a1 = *a2;
      a1[1] = a2[1];
      a1[2] = *((_DWORD *)a2 + 1);
      *(_WORD *)(a1 + 3) = *((_DWORD *)a2 + 2);
      qdf_trace_msg(
        0x99u,
        4u,
        "%s: T2LM response frame: category:%d action:%d dialog_token:%d status_code:%d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_mlo_add_t2lm_response_action_frame",
        *a2,
        a2[1],
        *((unsigned int *)a2 + 1),
        *((unsigned int *)a2 + 2),
        v12,
        v13);
      result = v25;
      if ( *((_DWORD *)a2 + 2) != 134 )
        return result;
      return wlan_mlo_add_t2lm_ie(result, a3, 0, v16, v17, v18, v19, v20, v21, v22, v23);
    case 1:
      *a1 = *a2;
      a1[1] = a2[1];
      a1[2] = *((_DWORD *)a2 + 1);
      qdf_trace_msg(
        0x99u,
        4u,
        "%s: T2LM request frame: category:%d action:%d dialog_token:%d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "wlan_mlo_add_t2lm_request_action_frame",
        *a2,
        a2[1],
        *((unsigned int *)a2 + 1),
        v12,
        v13);
      result = (char *)(a1 + 3);
      return wlan_mlo_add_t2lm_ie(result, a3, 0, v16, v17, v18, v19, v20, v21, v22, v23);
    default:
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
        "wlan_mlo_add_t2lm_action_frame",
        v12,
        v13);
      return (char *)a1;
  }
}
