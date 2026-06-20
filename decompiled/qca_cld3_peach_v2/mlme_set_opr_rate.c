__int64 __fastcall mlme_set_opr_rate(
        __int64 a1,
        const void *a2,
        unsigned __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( a1 && a2 )
  {
    ext_hdl = (_QWORD *)wlan_vdev_mlme_get_ext_hdl(a1, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( ext_hdl )
    {
      if ( ext_hdl[2964] >= a3 )
      {
        ext_hdl[2965] = a3;
        qdf_mem_copy(ext_hdl + 2966, a2, (unsigned int)a3);
        return 0;
      }
      else
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: Invalid len %zd (>%zd)",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "mlme_set_opr_rate",
          a3);
        return 4;
      }
    }
    else
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev legacy private object is NULL",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "mlme_set_opr_rate");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: invalid params", a4, a5, a6, a7, a8, a9, a10, a11, "mlme_set_opr_rate");
    return 4;
  }
}
