__int64 __fastcall sme_update_channel_list(__int64 a1)
{
  __int64 result; // x0
  unsigned int channel_and_power_list; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w21
  unsigned int v13; // w20
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x24
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int operation_chan_freq_vdev_id; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w24
  __int64 v43; // x0
  __int64 v44; // x1
  __int64 v45; // x2
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned __int64 v54; // x8
  __int64 v55; // x9
  bool v56; // w10

  result = qdf_mutex_acquire(a1 + 12776);
  if ( (_DWORD)result )
    return result;
  channel_and_power_list = csr_get_channel_and_power_list(a1);
  if ( channel_and_power_list )
  {
    v12 = channel_and_power_list;
    qdf_trace_msg(0x34u, 2u, "%s: fail to get Channels", v4, v5, v6, v7, v8, v9, v10, v11, "sme_update_channel_list");
    qdf_mutex_release(a1 + 12776);
    return v12;
  }
  csr_apply_channel_power_info_wrapper(a1);
  csr_scan_filter_results(a1);
  qdf_mutex_release(a1 + 12776);
  v13 = 0;
  while ( 1 )
  {
    if ( (wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), v13) & 0xFFFFFFFD) != 0 )
      goto LABEL_7;
    operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), v13);
    if ( !operation_chan_freq_vdev_id )
      goto LABEL_7;
    v42 = operation_chan_freq_vdev_id;
    v43 = qdf_trace_msg(
            0x34u,
            8u,
            "%s: Current Operating channel : %d, vdev_id :%d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "sme_disconnect_connected_sessions",
            operation_chan_freq_vdev_id,
            v13);
    v54 = *(unsigned __int8 *)(a1 + 16532);
    if ( *(_BYTE *)(a1 + 16532) )
    {
      v55 = 0;
      v56 = 1;
      do
      {
        if ( v55 == 100 )
        {
          __break(0x5512u);
          return sme_8023_multicast_list(v43, v44, v45);
        }
        if ( *(_DWORD *)(a1 + 16536 + 4 * v55) == v42 )
          break;
        v56 = ++v55 < v54;
      }
      while ( v54 != v55 );
      if ( !v56 )
        goto LABEL_5;
      goto LABEL_7;
    }
LABEL_5:
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Disconnect Session: %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "sme_disconnect_connected_sessions",
      v13);
    v14 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            *(_QWORD *)(a1 + 21552),
            v13,
            11);
    if ( !v14 )
      break;
    v23 = v14;
    wlan_cm_disconnect(v14, 8, 65524, nullptr);
    wlan_objmgr_vdev_release_ref(v23, 0xBu, v24, v25, v26, v27, v28, v29, v30, v31, v32);
LABEL_7:
    if ( ++v13 == 6 )
      return 0;
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: vdev object is NULL for vdev_id %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "sme_disconnect_connected_sessions",
    v13);
  return 0;
}
