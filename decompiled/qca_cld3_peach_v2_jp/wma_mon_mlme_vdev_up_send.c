__int64 __fastcall wma_mon_mlme_vdev_up_send(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20

  if ( !_cds_get_context(54, (__int64)"wma_mon_mlme_vdev_up_send", a2, a3, a4, a5, a6, a7, a8, a9) )
    return 4;
  v18 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL);
  *(_WORD *)(a1 + 42) = 0;
  result = vdev_mgr_up_send(a1, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( (_DWORD)result )
  {
    v28 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send vdev up cmd: vdev %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_mon_mlme_vdev_up_send",
      v18);
    return v28;
  }
  return result;
}
