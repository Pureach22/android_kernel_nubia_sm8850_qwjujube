__int64 __fastcall os_if_nan_discovery_event_handler(__int64 a1)
{
  __int64 pdev_by_id; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  void (__fastcall *v21)(_QWORD); // x8
  _QWORD *v22; // x22
  _QWORD *vdev_by_id_from_pdev; // x0
  _QWORD *v24; // x8
  __int64 v25; // x21
  __int64 v26; // x0
  __int64 v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v46; // x2
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  const char *v56; // x2

  pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)a1, 0, 0x14u);
  if ( !pdev_by_id )
    return qdf_trace_msg(
             0x48u,
             2u,
             "%s: null pdev",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "os_if_nan_discovery_event_handler");
  v11 = pdev_by_id;
  if ( *(_QWORD *)a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)a1, 0xFu);
    if ( comp_private_obj )
    {
      v21 = *(void (__fastcall **)(_QWORD))(comp_private_obj + 160);
      if ( v21 )
      {
        if ( *((_DWORD *)v21 - 1) != -1334644194 )
          __break(0x8228u);
        v21(a1);
      }
      v22 = *(_QWORD **)(v11 + 24);
      if ( v22 )
        goto LABEL_9;
LABEL_18:
      v46 = "%s:  pdev osif priv is null";
      goto LABEL_20;
    }
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", v3, v4, v5, v6, v7, v8, v9, v10, "nan_get_psoc_priv_obj");
  }
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: nan psoc priv object is NULL",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "os_if_nan_handle_sr_nan_concurrency");
  v22 = *(_QWORD **)(v11 + 24);
  if ( !v22 )
    goto LABEL_18;
LABEL_9:
  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v11, *(_BYTE *)(a1 + 14), 0x14u);
  if ( vdev_by_id_from_pdev )
  {
    v24 = (_QWORD *)vdev_by_id_from_pdev[76];
    v25 = (__int64)vdev_by_id_from_pdev;
    if ( v24 )
    {
      if ( *v24 )
      {
        v26 = _cfg80211_alloc_event_skb(*v22, *v24, 103, 197, 0, 1, (unsigned int)(*(_DWORD *)(a1 + 16) + 16), 3264);
        if ( v26 )
        {
          v27 = v26;
          if ( (unsigned int)nla_put(v26, 2, *(unsigned int *)(a1 + 16), a1 + 26) )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: QCA_WLAN_VENDOR_ATTR_NAN put failed",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "os_if_nan_discovery_event_handler");
            sk_skb_reason_drop(0, v27, 2);
          }
          else
          {
            _cfg80211_send_event_skb(v27, 3264);
          }
          goto LABEL_25;
        }
        v56 = "%s: wlan_cfg80211_vendor_event_alloc failed";
      }
      else
      {
        v56 = "%s: wireless dev is null";
      }
    }
    else
    {
      v56 = "%s: osif_priv is null";
    }
    qdf_trace_msg(0x48u, 2u, v56, v13, v14, v15, v16, v17, v18, v19, v20, "os_if_nan_discovery_event_handler");
LABEL_25:
    wlan_objmgr_vdev_release_ref(v25, 0x14u, v36, v37, v38, v39, v40, v41, v42, v43, v44);
    return wlan_objmgr_pdev_release_ref(v11, 0x14u, v47, v48, v49, v50, v51, v52, v53, v54, v55);
  }
  v46 = "%s: vdev is null";
LABEL_20:
  qdf_trace_msg(0x48u, 2u, v46, v13, v14, v15, v16, v17, v18, v19, v20, "os_if_nan_discovery_event_handler");
  return wlan_objmgr_pdev_release_ref(v11, 0x14u, v47, v48, v49, v50, v51, v52, v53, v54, v55);
}
