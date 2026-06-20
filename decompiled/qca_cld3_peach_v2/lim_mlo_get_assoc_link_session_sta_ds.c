__int64 __fastcall lim_mlo_get_assoc_link_session_sta_ds(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 *a11,
        __int64 *a12)
{
  _QWORD *context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 assoc_peer; // x0
  __int64 v26; // x8
  __int64 v27; // x22
  __int64 session_by_vdev_id; // x0
  unsigned __int8 *v29; // x1
  __int64 v30; // x22
  __int64 result; // x0
  const char *v32; // x2
  __int16 v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  *a11 = 0;
  *a12 = 0;
  context = _cds_get_context(53, (__int64)"lim_mlo_get_assoc_link_session_sta_ds", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v32 = "%s: mac ctx is null";
LABEL_14:
    result = qdf_trace_msg(
               0x35u,
               2u,
               v32,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "lim_mlo_get_assoc_link_session_sta_ds");
    goto LABEL_15;
  }
  if ( !a1 )
  {
    v32 = "%s: session is NULL";
    goto LABEL_14;
  }
  v24 = (__int64)context;
  if ( !wlan_mlo_get_mlpeer_by_aid(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 1360LL)) )
  {
    v32 = "%s: mlo peer ctx is null";
    goto LABEL_14;
  }
  assoc_peer = wlan_mlo_peer_get_assoc_peer();
  if ( !assoc_peer )
  {
    v32 = "%s: peer is null";
    goto LABEL_14;
  }
  v26 = *(_QWORD *)(assoc_peer + 96);
  if ( !v26 )
  {
    v32 = "%s: vdev is null";
    goto LABEL_14;
  }
  v27 = assoc_peer;
  session_by_vdev_id = pe_find_session_by_vdev_id(v24, *(_BYTE *)(v26 + 168), v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !session_by_vdev_id )
  {
    v32 = "%s: assoc session is null";
    goto LABEL_14;
  }
  v29 = (unsigned __int8 *)(v27 + 48);
  v30 = session_by_vdev_id;
  result = dph_lookup_hash_entry(v16, v17, v18, v19, v20, v21, v22, v23, v24, v29, &v33, session_by_vdev_id + 360);
  *a12 = result;
  *a11 = v30;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
