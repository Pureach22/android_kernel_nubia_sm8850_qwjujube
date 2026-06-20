__int64 __fastcall sme_set_peer_ampdu(__int64 a1, __int64 a2, unsigned __int8 *a3, unsigned __int16 a4)
{
  unsigned __int8 v6; // w20
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  unsigned int is_up; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w24
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 peer_by_mac; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x22
  const char *v47; // x2
  __int64 v48; // x5
  __int64 v49; // x6
  __int64 v50; // x7
  int v51; // w8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _QWORD *context; // x0

  v6 = a2;
  v7 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21624),
         a2,
         11);
  if ( !v7 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: vdev null", v8, v9, v10, v11, v12, v13, v14, v15, "sme_set_peer_ampdu");
    return 4294967274LL;
  }
  v16 = v7;
  is_up = wlan_vdev_is_up();
  if ( !is_up )
  {
    peer_by_mac = wlan_objmgr_vdev_find_peer_by_mac(v16, a3, 0xBu, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( !peer_by_mac )
    {
      if ( a3 )
      {
        v48 = *a3;
        v49 = a3[1];
        v50 = a3[2];
        v51 = a3[5];
      }
      else
      {
        v50 = 0;
        v48 = 0;
        v49 = 0;
        v51 = 0;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev id %d peer not found %02x:%02x:%02x:**:**:%02x",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "sme_set_peer_ampdu",
        v6,
        v48,
        v49,
        v50,
        v51);
      v26 = 16;
      goto LABEL_19;
    }
    v46 = peer_by_mac;
    if ( a4 )
    {
      if ( *(_DWORD *)(peer_by_mac + 68) != 1 )
      {
        context = _cds_get_context(54, (__int64)"sme_set_peer_param", v38, v39, v40, v41, v42, v43, v44, v45);
        if ( context )
          v26 = wma_set_peer_param(context, a3, 2, a4, v6);
        else
          v26 = 16;
        goto LABEL_18;
      }
      v47 = "%s: self peer";
    }
    else
    {
      v47 = "%s: peer ampdu count 0";
    }
    qdf_trace_msg(0x34u, 8u, v47, v38, v39, v40, v41, v42, v43, v44, v45, "sme_validate_peer_ampdu_cfg");
    v26 = 4;
LABEL_18:
    wlan_objmgr_peer_release_ref(v46, 0xBu, v52, v53, v54, v55, v56, v57, v58, v59);
    goto LABEL_19;
  }
  v26 = is_up;
  qdf_trace_msg(0x34u, 8u, "%s: vdev id %d not up", v18, v19, v20, v21, v22, v23, v24, v25, "sme_set_peer_ampdu", v6);
LABEL_19:
  wlan_objmgr_vdev_release_ref(v16, 0xBu, v27, v28, v29, v30, v31, v32, v33, v34, v35);
  return qdf_status_to_os_return(v26);
}
