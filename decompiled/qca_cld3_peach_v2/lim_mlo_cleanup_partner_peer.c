__int64 __fastcall lim_mlo_cleanup_partner_peer(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x21
  __int64 session_by_vdev_id; // x0
  __int64 v22; // x19
  __int16 *v23; // x0
  __int16 *v24; // x20
  __int64 result; // x0
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x21
  const char *v29; // x2
  __int16 v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  context = _cds_get_context(53, (__int64)"lim_mlo_cleanup_partner_peer", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v29 = "%s: mac ctx is null";
LABEL_13:
    result = qdf_trace_msg(0x35u, 2u, v29, v11, v12, v13, v14, v15, v16, v17, v18, "lim_mlo_cleanup_partner_peer");
    goto LABEL_14;
  }
  v19 = *(_QWORD *)(a1 + 96);
  if ( !v19 )
  {
    v29 = "%s: vdev is null";
    goto LABEL_13;
  }
  v20 = (__int64)context;
  session_by_vdev_id = pe_find_session_by_vdev_id(
                         (__int64)context,
                         *(_BYTE *)(v19 + 168),
                         v11,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18);
  if ( !session_by_vdev_id )
  {
    v29 = "%s: pe session is null";
    goto LABEL_13;
  }
  v22 = session_by_vdev_id;
  v23 = (__int16 *)dph_lookup_hash_entry(
                     v11,
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v20,
                     (unsigned __int8 *)(a1 + 48),
                     &v30,
                     session_by_vdev_id + 360);
  if ( !v23 )
  {
    v29 = "%s: sta ds is null";
    goto LABEL_13;
  }
  v24 = v23;
  result = lim_cleanup_rx_path(v20, v23, v22, 1, v11, v12, v13, v14, v15, v16, v17, v18);
  v26 = *(_QWORD *)(v22 + 384);
  if ( v26 )
  {
    v27 = (unsigned __int16)v24[174];
    v28 = *(_QWORD *)(v26 + 8 * v27);
    if ( v28 )
    {
      lim_free_assoc_req_frm_buf(*(_QWORD *)(v26 + 8 * v27));
      result = _qdf_mem_free(v28);
      v26 = *(_QWORD *)(v22 + 384);
      v27 = (unsigned __int16)v24[174];
    }
    *(_QWORD *)(v26 + 8 * v27) = 0;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
