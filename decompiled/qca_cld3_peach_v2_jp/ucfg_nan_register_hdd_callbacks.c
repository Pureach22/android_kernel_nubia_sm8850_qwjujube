__int64 __fastcall ucfg_nan_register_hdd_callbacks(
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
      v20[5] = a2[3];
      v20[6] = a2[4];
      v20[7] = a2[5];
      v20[9] = a2[7];
      v20[8] = a2[6];
      v20[10] = a2[8];
      v20[11] = a2[9];
      v20[12] = a2[10];
      v20[14] = a2[12];
      v20[3] = a2[1];
      v20[2] = *a2;
      v20[4] = ucfg_nan_request_process_cb;
      v20[18] = a2[16];
      v20[19] = a2[17];
      v20[20] = a2[18];
      v20[25] = a2[23];
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
    "ucfg_nan_register_hdd_callbacks");
  return 4294967274LL;
}
