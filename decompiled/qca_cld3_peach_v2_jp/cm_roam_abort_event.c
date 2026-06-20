__int64 __fastcall cm_roam_abort_event(
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
  __int64 v9; // x19
  __int64 v10; // x21
  unsigned int v11; // w20
  unsigned __int8 rso_pending_disable_req_bitmap; // w0
  unsigned __int8 v13; // w22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v23; // x2

  if ( !a1 )
  {
    v23 = "%s: Vdev is NULL";
    goto LABEL_9;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v23 = "%s: Psoc is NULL";
LABEL_9:
    qdf_trace_msg(0x68u, 8u, v23, a2, a3, a4, a5, a6, a7, a8, a9, "cm_roam_abort_event");
    return 29;
  }
  v11 = *(unsigned __int8 *)(a1 + 104);
  rso_pending_disable_req_bitmap = mlme_get_rso_pending_disable_req_bitmap(
                                     *(_QWORD *)(v9 + 80),
                                     *(unsigned __int8 *)(a1 + 104));
  if ( rso_pending_disable_req_bitmap )
  {
    v13 = rso_pending_disable_req_bitmap;
    mlme_clear_rso_pending_disable_req_bitmap(v10, v11);
    wlan_cm_disable_rso(v9, v11, v13, 48, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  return 0;
}
