__int64 __fastcall wlan_twt_enable_event_handler(__int64 a1, unsigned int *a2)
{
  __int64 comp_private_obj; // x0
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
  int v22; // w4
  const char *v24; // x2
  unsigned int v25; // w22
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: null twt psoc priv obj",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_twt_enable_event_handler");
    return 16;
  }
  v13 = comp_private_obj;
  qdf_trace_msg(
    0x96u,
    8u,
    "%s: mac_id:%d status:%d twt_role:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_twt_enable_event_handler",
    *a2,
    a2[1],
    *(unsigned int *)(comp_private_obj + 48));
  if ( a2[1] > 1 )
  {
    v24 = "%s: twt enable status:%d";
LABEL_12:
    qdf_trace_msg(0x96u, 2u, v24, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_twt_enable_event_handler");
    return mlme_twt_osif_enable_complete_ind();
  }
  v22 = *(_DWORD *)(v13 + 48);
  if ( v22 == 1 )
  {
    v25 = *(unsigned __int8 *)a2;
    if ( v25 <= 2 )
    {
      v26 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
      if ( v26 )
        *(_BYTE *)(v26 + 88) |= 1 << v25;
      else
        qdf_trace_msg(
          0x96u,
          2u,
          "%s: twt psoc priv obj is null",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "wlan_twt_cfg_set_mac_responder_flag");
    }
    return mlme_twt_osif_enable_complete_ind();
  }
  if ( v22 )
  {
    v24 = "%s: Invalid role:%d";
    goto LABEL_12;
  }
  wlan_twt_cfg_set_requestor_flag(a1, 1);
  return mlme_twt_osif_enable_complete_ind();
}
