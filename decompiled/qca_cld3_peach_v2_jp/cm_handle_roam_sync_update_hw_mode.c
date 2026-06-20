void *__fastcall cm_handle_roam_sync_update_hw_mode(
        const void *a1,
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
  _QWORD *v19; // x20
  void *result; // x0
  void *v21; // x21

  context = _cds_get_context(54, (__int64)"cm_handle_roam_sync_update_hw_mode", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return (void *)qdf_trace_msg(
                     0x36u,
                     2u,
                     "%s: invalid wma handle",
                     v11,
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     "cm_handle_roam_sync_update_hw_mode");
  v19 = context;
  result = (void *)_qdf_mem_malloc(0x54u, "cm_handle_roam_sync_update_hw_mode", 2909);
  if ( result )
  {
    v21 = result;
    qdf_mem_copy(result, a1, 0x54u);
    return (void *)((__int64 (__fastcall *)(_QWORD *, void *))wma_handle_hw_mode_trans_ind)(v19, v21);
  }
  return result;
}
