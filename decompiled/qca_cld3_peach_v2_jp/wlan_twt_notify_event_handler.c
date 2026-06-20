__int64 __fastcall wlan_twt_notify_event_handler(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x1
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  unsigned int bss_peer_mac; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w22
  const char *v25; // x2
  unsigned int v26; // w21
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x23
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  unsigned int peer_capabilities; // w0
  unsigned __int8 v49; // w2
  unsigned int v50; // w8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int8 v59[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v60; // [xsp+10h] [xbp-10h] BYREF
  __int16 v61; // [xsp+14h] [xbp-Ch]
  __int64 v62; // [xsp+18h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2[1] )
  {
    v4 = *a2;
    v61 = 0;
    v60 = 0;
    v59[0] = 0;
    v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v4, 94);
    if ( !v5 )
    {
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: vdev object not found",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_twt_update_peer_twt_required_bit");
      v24 = 4;
LABEL_15:
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: failed to get status",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "wlan_twt_notify_event_handler");
      goto LABEL_16;
    }
    v14 = v5;
    bss_peer_mac = wlan_vdev_get_bss_peer_mac(v5, &v60, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( bss_peer_mac )
    {
      v24 = bss_peer_mac;
      v25 = "%s: Failed to get bssid";
LABEL_10:
      qdf_trace_msg(0x96u, 2u, v25, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_twt_update_peer_twt_required_bit");
LABEL_11:
      v46 = v14;
      goto LABEL_12;
    }
    peer_capabilities = wlan_twt_get_peer_capabilities(a1, (unsigned __int8 *)&v60, v59);
    if ( peer_capabilities )
    {
      v24 = peer_capabilities;
      v25 = "%s: twt failed to get peer capabilities";
      goto LABEL_10;
    }
    v49 = v59[0];
    v50 = a2[1];
    if ( (v59[0] & 0x10) != 0 )
    {
      if ( v50 == 2 )
      {
        v49 = v59[0] & 0xEF;
        goto LABEL_22;
      }
    }
    else if ( v50 == 1 )
    {
      v49 = v59[0] | 0x10;
LABEL_22:
      v59[0] = v49;
    }
    v24 = wlan_twt_set_peer_capabilities(a1, (unsigned __int8 *)&v60, v49);
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: Update Peer TWT capabilities: %d",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "wlan_twt_update_peer_twt_required_bit",
      v59[0]);
    goto LABEL_11;
  }
  v26 = *a2;
  v27 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 94);
  if ( !v27 )
  {
    v24 = 16;
    goto LABEL_15;
  }
  v36 = v27;
  v24 = wlan_twt_set_wait_for_notify(a1, v26, 0);
  v46 = v36;
LABEL_12:
  wlan_objmgr_vdev_release_ref(v46, 0x5Eu, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  if ( v24 )
    goto LABEL_15;
  mlme_twt_osif_notify_complete_ind();
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v24;
}
