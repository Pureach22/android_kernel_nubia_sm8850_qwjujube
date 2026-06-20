__int64 __fastcall cm_subst_roam_start_event(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char v13; // w0
  __int64 v14; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v26; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v13 = 0;
  if ( (unsigned __int16)a2 > 0x12u )
  {
    if ( (unsigned int)(unsigned __int16)a2 - 19 >= 2 )
    {
      if ( (unsigned __int16)a2 == 30 )
      {
        cm_send_roam_invoke_req(a1, a4);
        goto LABEL_16;
      }
      if ( (unsigned __int16)a2 != 31 )
        return v13 & 1;
    }
    v26 = a1;
    wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 2u, a5, a6, a7, a8, a9, a10, a11, a12);
    wlan_sm_dispatch(*(_QWORD *)(v26 + 72), a2, a3, a4, v29, v30, v31, v32, v33, v34, v35, v36);
LABEL_16:
    v13 = 1;
    return v13 & 1;
  }
  if ( (unsigned __int16)a2 <= 0xEu )
  {
    if ( (_WORD)a2 && (unsigned __int16)a2 != 13 )
      return v13 & 1;
LABEL_13:
    v13 = cm_handle_connect_disconnect_in_roam(a1);
    return v13 & 1;
  }
  switch ( (unsigned __int16)a2 )
  {
    case 0xFu:
      goto LABEL_13;
    case 0x11u:
      cm_fw_roam_start(a1);
      goto LABEL_16;
    case 0x12u:
      v14 = a1;
      wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 0xDu, a5, a6, a7, a8, a9, a10, a11, a12);
      v13 = (unsigned int)wlan_sm_dispatch(*(_QWORD *)(v14 + 72), 0x12u, a3, a4, v17, v18, v19, v20, v21, v22, v23, v24) == 0;
      break;
  }
  return v13 & 1;
}
