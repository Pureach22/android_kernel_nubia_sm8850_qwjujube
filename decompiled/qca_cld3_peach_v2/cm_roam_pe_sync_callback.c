__int64 __fastcall cm_roam_pe_sync_callback(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x23
  _DWORD *v26; // x8
  __int64 v27; // x0
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  unsigned int v39; // w19

  context = _cds_get_context(54, (__int64)"cm_roam_pe_sync_callback", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
    return 4;
  v25 = context;
  if ( !pe_find_session_by_vdev_id(context[2], a2, v17, v18, v19, v20, v21, v22, v23, v24) )
  {
    v29 = lim_create_and_fill_link_session(v25[2], a2, a1, a3);
    if ( v29 )
    {
      v38 = (unsigned __int8)a2;
      v39 = v29;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: MLO ROAM: pe session creation failed vdev id %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "cm_roam_pe_sync_callback",
        v38);
      return v39;
    }
    if ( a4 )
      *a4 = 1;
  }
  v26 = (_DWORD *)v25[388];
  v27 = v25[2];
  if ( *(v26 - 1) != -478742497 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD, __int64))v26)(v27, a2, a1, a3, 1);
}
