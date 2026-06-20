__int64 __fastcall cm_roam_switch_to_roam_start(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned int v4; // w19
  unsigned int roam_state; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w20

  v2 = *(_QWORD *)(a1 + 80);
  v4 = a2;
  roam_state = mlme_get_roam_state(v2, a2);
  if ( roam_state == 2 )
    goto LABEL_7;
  v14 = roam_state;
  if ( roam_state != 3 )
  {
    if ( roam_state == 4 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Roam started already on vdev[%d]",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "cm_roam_switch_to_roam_start",
        (unsigned __int8)v4);
      return 0;
    }
    goto LABEL_8;
  }
  if ( (mlme_get_supplicant_disabled_roaming(v2, v4) & 1) != 0 && (wlan_cm_roaming_in_progress(a1, v4) & 1) != 0 )
  {
LABEL_7:
    mlme_set_roam_state(v2, v4, 4u);
    return 0;
  }
LABEL_8:
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: ROAM: Roaming start received in invalid state: %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "cm_roam_switch_to_roam_start",
    v14);
  return 16;
}
