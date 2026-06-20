__int64 __fastcall cm_roam_switch_to_roam_sync(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int v4; // w19
  int roam_state; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2

  v2 = *(_QWORD *)(a1 + 80);
  v4 = a2;
  roam_state = mlme_get_roam_state(v2, a2);
  if ( roam_state == 4 )
  {
LABEL_4:
    if ( (cm_is_vdevid_active(a1, v4) & 1) != 0 )
    {
LABEL_5:
      mlme_set_roam_state(v2, v4, 5u);
      return 0;
    }
    v31 = "%s: ROAM: STA not in connected state";
    goto LABEL_11;
  }
  if ( roam_state != 3 )
  {
    if ( roam_state != 2 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: ROAM: Roam synch not allowed in [%d] state",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "cm_roam_switch_to_roam_sync");
      return 16;
    }
    goto LABEL_4;
  }
  if ( (mlme_get_supplicant_disabled_roaming(v2, v4) & 1) != 0 && (wlan_cm_roaming_in_progress(a1, v4) & 1) != 0 )
    goto LABEL_5;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: ROAM: ROAM_SYNCH received in state: %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "cm_roam_switch_to_roam_sync",
    3);
  if ( (unsigned int)cm_roam_stop_req(v2, v4, 0x35u, nullptr, 0) )
  {
    v31 = "%s: ROAM: Unable to process RSO STOP req";
LABEL_11:
    qdf_trace_msg(0x68u, 2u, v31, v14, v15, v16, v17, v18, v19, v20, v21, "cm_roam_switch_to_roam_sync");
  }
  return 16;
}
