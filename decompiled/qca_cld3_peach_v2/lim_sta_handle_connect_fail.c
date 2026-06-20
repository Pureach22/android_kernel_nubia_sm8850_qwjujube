__int64 __fastcall lim_sta_handle_connect_fail(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  __int64 v11; // x19
  __int64 session_by_session_id; // x0
  __int64 v13; // x21
  __int64 v14; // x23
  __int64 hash_entry; // x0
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  const char *v34; // x2
  __int64 result; // x0
  __int64 v36; // x0
  unsigned int v37; // w20
  unsigned int v38; // w22
  __int64 session_by_vdev_id; // x0

  if ( !a1 )
  {
    v34 = "%s: param is NULL";
LABEL_9:
    qdf_trace_msg(0x35u, 2u, v34, a2, a3, a4, a5, a6, a7, a8, a9, "lim_sta_handle_connect_fail");
    return 4;
  }
  context = _cds_get_context(53, (__int64)"lim_sta_handle_connect_fail", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v11 = (__int64)context;
  session_by_session_id = pe_find_session_by_session_id(context, *(unsigned __int8 *)(a1 + 2));
  if ( !session_by_session_id )
  {
    v34 = "%s: session is NULL";
    goto LABEL_9;
  }
  v13 = session_by_session_id;
  v14 = session_by_session_id + 0x2000;
  hash_entry = dph_get_hash_entry(v11, 1u, session_by_session_id + 360);
  if ( hash_entry )
  {
    *(_DWORD *)(hash_entry + 24) = 1;
    v16 = hash_entry;
    *(_WORD *)(hash_entry + 34) = 7;
    *(_DWORD *)(hash_entry + 28) = *(_DWORD *)(a1 + 4);
    *(_WORD *)(hash_entry + 36) = *(_WORD *)a1;
    lim_mlo_notify_peer_disconn(v13, hash_entry);
    lim_cleanup_rx_path(v11, (__int16 *)v16, v13, 1, v17, v18, v19, v20, v21, v22, v23, v24);
    _qdf_mem_free(*(_QWORD *)(v13 + 112));
    v33 = *(unsigned __int8 *)(v14 + 445);
    *(_QWORD *)(v13 + 112) = 0;
    if ( v33 != 1 )
      return 0;
    dph_delete_hash_entry(
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v11,
      (unsigned __int8 *)(v16 + 350),
      *(_WORD *)(v16 + 348),
      v13 + 360);
  }
  else
  {
    lim_mlo_sta_notify_peer_disconn(v13);
    _qdf_mem_free(*(_QWORD *)(v13 + 112));
    *(_QWORD *)(v13 + 112) = 0;
  }
  v36 = *(unsigned __int8 *)(v13 + 10);
  *(_WORD *)(v14 + 1864) = *(_WORD *)a1;
  *(_DWORD *)(v13 + 10060) = *(_DWORD *)(a1 + 4);
  result = wma_send_vdev_stop(v36);
  if ( (_DWORD)result )
  {
    v37 = *(unsigned __int8 *)(v13 + 10);
    v38 = result;
    session_by_vdev_id = pe_find_session_by_vdev_id(v11, *(unsigned __int8 *)(v13 + 10));
    if ( session_by_vdev_id )
    {
      lim_send_sme_join_reassoc_rsp(
        v11,
        0,
        *(unsigned int *)(session_by_vdev_id + 10060),
        *(unsigned __int16 *)(session_by_vdev_id + 10056),
        session_by_vdev_id,
        v37);
      pe_delete_session(v11);
    }
    return v38;
  }
  return result;
}
