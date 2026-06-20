__int64 __fastcall cm_remove_force_bss_on_join_fail(
        unsigned __int8 *a1,
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
  unsigned int v19; // w20
  _QWORD *v20; // x20
  _QWORD *v21; // x0
  _QWORD *v22; // x21

  context = _cds_get_context(54, (__int64)"lim_cm_remove_force_bss_on_join_fail", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = 4;
  if ( !a1 || !context )
    goto LABEL_7;
  v20 = context;
  v21 = _cds_get_context(53, (__int64)"lim_cm_remove_force_bss_on_join_fail", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !v21 )
  {
    v19 = 4;
    goto LABEL_7;
  }
  v22 = v21;
  v19 = wma_remove_bss_peer_before_join(v20, *a1, a1);
  if ( v19 != 24 )
  {
    lim_cm_send_connect_rsp(v22, 0, a1, 2, 16, 0, 0);
LABEL_7:
    cm_free_join_req((__int64)a1);
  }
  return v19;
}
