void __fastcall epcs_update_edca_param(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _BYTE *v21; // x21
  double updated; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // [xsp+0h] [xbp-20h] BYREF
  __int64 v31; // [xsp+8h] [xbp-18h] BYREF
  __int64 v32; // [xsp+10h] [xbp-10h]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v32) = 0;
  v30 = 0;
  v31 = 0;
  context = _cds_get_context(53, (__int64)"epcs_update_edca_param", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    if ( *a2 == 12 && a2[1] == 18 )
    {
      v21 = context + 2560;
      epcs_update_ac_value(&v30, a2 + 4);
      BYTE4(v30) = v21[1217];
      epcs_update_ac_value((char *)&v30 + 5, a2 + 8);
      BYTE1(v31) = v21[1218];
      epcs_update_ac_value((char *)&v31 + 2, a2 + 12);
      BYTE6(v31) = v21[1219];
      updated = epcs_update_ac_value((char *)&v31 + 7, a2 + 16);
      BYTE3(v32) = v21[1220];
      lim_send_epcs_update_edca_params(a1, (__int64)&v30, 0, updated, v23, v24, v25, v26, v27, v28, v29);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: edca info is not valid or not exist",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "epcs_update_edca_param",
        v30,
        v31,
        v32,
        v33);
    }
  }
  _ReadStatusReg(SP_EL0);
}
