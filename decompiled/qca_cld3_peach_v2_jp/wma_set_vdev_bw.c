__int64 __fastcall wma_set_vdev_bw(
        unsigned __int8 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  _QWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_set_vdev_bw", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v21 = *context;
    v22 = _cds_get_context(54, (__int64)"wma_is_vdev_valid", v13, v14, v15, v16, v17, v18, v19, v20);
    if ( v22 )
    {
      if ( *((unsigned __int16 *)v22 + 81) <= (unsigned int)a1 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: vdev_id: %d is invalid, max_bssid: %d",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wma_is_vdev_valid",
          a1);
      }
      else if ( (*(_BYTE *)(v22[65] + 488LL * a1 + 184) & 1) != 0 )
      {
        v31 = wmi_unified_vdev_set_param_send(v21);
        if ( !v31 )
          goto LABEL_11;
        goto LABEL_10;
      }
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev_id: %d is not active reject the req: param id %d val %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_vdev_set_param",
      a1,
      21,
      a2);
    v31 = 4;
LABEL_10:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: failed to set vdev bw, status: %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wma_set_vdev_bw",
      v31);
    goto LABEL_11;
  }
  v31 = 4;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v31;
}
