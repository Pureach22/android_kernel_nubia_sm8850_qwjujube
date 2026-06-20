__int64 __fastcall lim_mlo_ap_sta_assoc_suc(
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
  __int64 v19; // x19
  __int64 session_by_vdev_id; // x0
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v23; // x21
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int16 v34; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  context = _cds_get_context(53, (__int64)"lim_mlo_ap_sta_assoc_suc", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v33 = "%s: mac ctx is null";
LABEL_11:
    result = qdf_trace_msg(0x35u, 2u, v33, v11, v12, v13, v14, v15, v16, v17, v18, "lim_mlo_ap_sta_assoc_suc");
    goto LABEL_12;
  }
  if ( !a1 )
  {
    v33 = "%s: peer is null";
    goto LABEL_11;
  }
  v19 = (__int64)context;
  session_by_vdev_id = pe_find_session_by_vdev_id(
                         (__int64)context,
                         *(_BYTE *)(*(_QWORD *)(a1 + 96) + 168LL),
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
    v33 = "%s: pe_session is NULL";
    goto LABEL_11;
  }
  v21 = session_by_vdev_id;
  v22 = dph_lookup_hash_entry(
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          (unsigned __int8 *)(a1 + 48),
          &v34,
          session_by_vdev_id + 360);
  if ( !v22 )
  {
    v33 = "%s: sta ds is null";
    goto LABEL_11;
  }
  v23 = v22;
  result = lim_send_mlm_assoc_ind(v19, v22, v21, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( (_DWORD)result )
    result = lim_reject_association(
               v19,
               (unsigned __int8 *)(v23 + 350),
               *(_BYTE *)(v23 + 32) & 1,
               1u,
               *(_DWORD *)(v23 + 12),
               *(_WORD *)(v23 + 348),
               1u,
               1u,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v21);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
