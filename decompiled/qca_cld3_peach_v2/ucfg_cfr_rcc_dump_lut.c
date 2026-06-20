__int64 __fastcall ucfg_cfr_rcc_dump_lut(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v36; // x2

  if ( !a1 )
  {
    v36 = "%s: vdev is NULL";
LABEL_7:
    qdf_trace_msg(0x6Au, 2u, v36, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_cfr_rcc_dump_lut");
    return 4;
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 )
  {
    v36 = "%s: pdev is NULL";
    goto LABEL_7;
  }
  if ( !(unsigned int)wlan_objmgr_pdev_try_get_ref(*(_QWORD *)(a1 + 216), 0x30u, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: LUT table:", v10, v11, v12, v13, v14, v15, v16, v17, "ucfg_cfr_rcc_dump_lut");
    tgt_cfr_dump_lut_enh(v9, v18, v19, v20, v21, v22, v23, v24, v25);
    wlan_objmgr_pdev_release_ref(v9, 0x30u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    return 0;
  }
  return 4;
}
