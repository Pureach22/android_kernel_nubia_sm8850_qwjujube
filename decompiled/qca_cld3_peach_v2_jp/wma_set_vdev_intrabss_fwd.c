_QWORD *__fastcall wma_set_vdev_intrabss_fwd(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int16 *a10)
{
  const char *v10; // x5
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 (*v29)(void); // x8

  if ( *((_BYTE *)a10 + 2) )
    v10 = "true";
  else
    v10 = "false";
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: intra_fwd:vdev(%d) intrabss_dis=%s",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wma_set_vdev_intrabss_fwd",
    *a10,
    v10);
  result = _cds_get_context(71, (__int64)"wma_set_vdev_intrabss_fwd", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !result || !*result )
    return (_QWORD *)qdf_trace_msg(
                       0x89u,
                       8u,
                       "%s: invalid instance",
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       "cdp_cfg_vdev_rx_set_intrabss_fwd");
  v28 = *(_QWORD *)(*result + 104LL);
  if ( v28 )
  {
    v29 = *(__int64 (**)(void))(v28 + 24);
    if ( v29 )
    {
      if ( *((_DWORD *)v29 - 1) != 1944199495 )
        __break(0x8228u);
      return (_QWORD *)v29();
    }
  }
  return result;
}
