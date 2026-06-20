void __fastcall epcs_update_def_edca_param(
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
  _QWORD *context; // x0
  _BYTE *v11; // x21
  double updated; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v30) = 0;
  v28 = 0;
  v29 = 0;
  context = _cds_get_context(53, (__int64)"epcs_update_def_edca_param", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v11 = context + 2560;
    epcs_update_ac_value(&v28, &default_epcs_edca);
    BYTE4(v28) = v11[1217];
    epcs_update_ac_value((char *)&v28 + 5, &unk_68634);
    BYTE1(v29) = v11[1218];
    epcs_update_ac_value((char *)&v29 + 2, &unk_68638);
    BYTE6(v29) = v11[1219];
    updated = epcs_update_ac_value((char *)&v29 + 7, &unk_6863C);
    BYTE3(v30) = v11[1220];
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: using default edca info",
      updated,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "epcs_update_def_edca_param",
      v28,
      v29,
      v30,
      v31);
    lim_send_epcs_update_edca_params(a1, (__int64)&v28, 0, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  _ReadStatusReg(SP_EL0);
}
