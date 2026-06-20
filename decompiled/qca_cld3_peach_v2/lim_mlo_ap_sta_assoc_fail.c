__int64 __fastcall lim_mlo_ap_sta_assoc_fail(
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
  __int64 v22; // x20
  __int64 v23; // x0
  __int64 result; // x0
  const char *v25; // x2
  __int16 v26; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  context = _cds_get_context(53, (__int64)"lim_mlo_ap_sta_assoc_fail", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v25 = "%s: mac ctx is null";
LABEL_12:
    result = qdf_trace_msg(0x35u, 2u, v25, v11, v12, v13, v14, v15, v16, v17, v18, "lim_mlo_ap_sta_assoc_fail");
    goto LABEL_13;
  }
  if ( !a1 )
  {
    v25 = "%s: peer is null";
    goto LABEL_12;
  }
  v19 = *(_QWORD *)(a1 + 96);
  if ( !v19 )
  {
    v25 = "%s: vdev is null";
    goto LABEL_12;
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
    v25 = "%s: pe_session is NULL";
    goto LABEL_12;
  }
  v22 = session_by_vdev_id;
  v23 = dph_lookup_hash_entry(
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
          &v26,
          session_by_vdev_id + 360);
  if ( !v23 )
  {
    v25 = "%s: sta ds is null";
    goto LABEL_12;
  }
  result = lim_reject_association(
             v20,
             (unsigned __int8 *)(v23 + 350),
             *(_BYTE *)(v23 + 32) & 1,
             1u,
             *(_DWORD *)(v23 + 12),
             *(_WORD *)(v23 + 348),
             1u,
             1u,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v22);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
