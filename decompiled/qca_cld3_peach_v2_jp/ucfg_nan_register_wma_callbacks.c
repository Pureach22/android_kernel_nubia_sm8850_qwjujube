__int64 __fastcall ucfg_nan_register_wma_callbacks(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x8

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( comp_private_obj )
    {
      v20 = (_QWORD *)comp_private_obj;
      v20[17] = a2[15];
      v20[21] = a2[19];
      v20[22] = a2[20];
      v20[23] = a2[21];
      v20[24] = a2[22];
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a3, a4, a5, a6, a7, a8, a9, a10, "nan_get_psoc_priv_obj");
  }
  qdf_trace_msg(
    0x53u,
    2u,
    "%s: nan psoc priv object is NULL",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "ucfg_nan_register_wma_callbacks");
  return 4294967274LL;
}
