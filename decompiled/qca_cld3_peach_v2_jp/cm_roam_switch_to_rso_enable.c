__int64 __fastcall cm_roam_switch_to_rso_enable(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 v6; // x21
  char supplicant_disabled_roaming; // w22
  unsigned __int8 rso_disabled_bitmap; // w24
  int roam_state; // w25
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  unsigned __int8 v27; // w2
  __int64 v28; // x0
  __int64 v29; // x1
  unsigned int v30; // w2
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x4
  unsigned int v41; // w19
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char v50[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 80);
  v50[0] = 0;
  wlan_mlme_get_roam_scan_offload_enabled(v6, v50);
  supplicant_disabled_roaming = mlme_get_supplicant_disabled_roaming(v6, a2);
  rso_disabled_bitmap = mlme_get_rso_disabled_bitmap(v6, a2);
  roam_state = mlme_get_roam_state(v6, a2);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: CM_RSO: vdev%d: cur_state : %d reason:%d control_bmap:0x%x sup_disabled_roam:%d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "cm_roam_switch_to_rso_enable",
    (unsigned __int8)a2,
    (unsigned int)roam_state,
    a3,
    rso_disabled_bitmap,
    supplicant_disabled_roaming & 1);
  result = 0;
  v27 = 1;
  if ( roam_state <= 2 )
  {
    if ( roam_state )
    {
      if ( roam_state != 1 )
      {
        if ( roam_state != 2 )
          goto LABEL_27;
        v27 = 4;
      }
    }
    else
    {
      result = cm_roam_switch_to_init(a1, a2, a3);
      if ( (_DWORD)result )
        goto LABEL_27;
      v27 = 1;
    }
LABEL_13:
    if ( (v50[0] & 1) != 0 )
    {
      if ( rso_disabled_bitmap )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: ROAM: RSO Disabled internally: vdev[%d] bitmap[0x%x]",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "cm_roam_switch_to_rso_enable",
          (unsigned __int8)a2,
          rso_disabled_bitmap);
LABEL_26:
        result = 16;
        goto LABEL_27;
      }
      goto LABEL_23;
    }
LABEL_25:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: ROAM: RSO disabled via INI",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "cm_roam_switch_to_rso_enable");
    goto LABEL_26;
  }
  if ( roam_state == 3 )
    goto LABEL_13;
  if ( roam_state == 4 )
  {
    v28 = v6;
    v29 = a2;
    if ( supplicant_disabled_roaming & 1 | (rso_disabled_bitmap != 0) )
      v30 = 3;
    else
      v30 = 2;
    goto LABEL_19;
  }
  if ( roam_state != 5 )
    goto LABEL_27;
  if ( a3 == 53 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Roam synch in progress, drop Roam abort",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "cm_roam_switch_to_rso_enable");
    result = 0;
    goto LABEL_27;
  }
  if ( supplicant_disabled_roaming & 1 | (rso_disabled_bitmap != 0) )
  {
    v28 = v6;
    v29 = a2;
    v30 = 3;
LABEL_19:
    mlme_set_roam_state(v28, v29, v30);
    result = 0;
    goto LABEL_27;
  }
  if ( (v50[0] & 1) == 0 )
    goto LABEL_25;
LABEL_23:
  v31 = cm_roam_send_rso_cmd(v6, a2, v27, a3);
  if ( v31 )
  {
    v40 = (unsigned __int8)a2;
    v41 = v31;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: ROAM: vdev:%d RSO start failed",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "cm_roam_switch_to_rso_enable",
      v40);
    result = v41;
  }
  else
  {
    mlme_set_roam_state(v6, a2, 2u);
    if ( (wlan_mlme_is_pmk_set_deferred(v6, a2) & 1) != 0 )
    {
      cm_roam_send_rso_cmd(v6, a2, 4u, 0x25u);
      wlan_mlme_defer_pmk_set_in_roaming(v6, a2, 0);
    }
    if ( (supplicant_disabled_roaming & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: ROAM: RSO disabled by Supplicant on vdev[%d]",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "cm_roam_switch_to_rso_enable",
        (unsigned __int8)a2);
      result = cm_roam_state_change(a1, a2, 3, 0x27u, 0, 0);
    }
    else
    {
      result = 0;
    }
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
