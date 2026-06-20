__int64 __fastcall lim_handle_mlo_sta_csa_param(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        const void *a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x20
  unsigned __int8 *v21; // x0
  unsigned __int8 *v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v32; // x2

  context = _cds_get_context(53, (__int64)"lim_handle_mlo_sta_csa_param", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v20 = context;
    v21 = (unsigned __int8 *)_qdf_mem_malloc(0x24u, "lim_handle_mlo_sta_csa_param", 2553);
    if ( v21 )
    {
      v22 = v21;
      qdf_mem_copy(v21, a10, 0x24u);
      return lim_handle_sta_csa_param(v20, v22, 0, v23, v24, v25, v26, v27, v28, v29, v30);
    }
    v32 = "%s: tmp_csa_params allocation fails";
  }
  else
  {
    v32 = "%s: mac ctx is null";
  }
  return qdf_trace_msg(0x35u, 2u, v32, v12, v13, v14, v15, v16, v17, v18, v19, "lim_handle_mlo_sta_csa_param");
}
