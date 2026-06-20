__int64 __fastcall cm_roam_pe_sync_callback(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _DWORD *v32; // x8
  __int64 v33; // x0

  context = _cds_get_context(54, (__int64)"cm_roam_pe_sync_callback", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 4;
  v23 = context;
  if ( pe_find_session_by_vdev_id(context[2], a2, v15, v16, v17, v18, v19, v20, v21, v22) )
  {
    v32 = (_DWORD *)v23[388];
    v33 = v23[2];
    if ( *(v32 - 1) != -478742497 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD, __int64))v32)(v33, a2, a1, a3, 1);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: MLO ROAM: pe session creation failed vdev id %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "cm_roam_pe_sync_callback",
      (unsigned __int8)a2);
    return 11;
  }
}
