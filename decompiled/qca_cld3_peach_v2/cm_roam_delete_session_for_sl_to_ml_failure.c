__int64 __fastcall cm_roam_delete_session_for_sl_to_ml_failure(
        unsigned __int8 a1,
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
  __int64 v19; // x20
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  context = _cds_get_context(53, (__int64)"cm_roam_delete_session_for_sl_to_ml_failure", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v19 = (__int64)context;
  result = pe_find_session_by_vdev_id((__int64)context, a1, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( result )
  {
    pe_delete_session(v19, result, v21, v22, v23, v24, v25, v26, v27, v28);
    return 0;
  }
  return result;
}
