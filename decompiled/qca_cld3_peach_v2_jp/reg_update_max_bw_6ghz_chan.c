__int64 __fastcall reg_update_max_bw_6ghz_chan(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v33; // x2
  const char *v34; // x3
  _WORD *v35; // x19
  __int64 v36; // x21
  __int64 v37; // x20
  unsigned __int16 *v38; // x8
  unsigned int v39; // w9
  unsigned int v40; // w10
  unsigned int v41; // w8
  unsigned int v42; // w11
  __int16 v43; // w10
  __int16 v44; // w8
  bool v45; // cf

  pdev_obj = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !pdev_obj )
  {
    v33 = "%s: pdev priv obj null";
    v34 = "reg_update_max_bw_6ghz_chan";
LABEL_7:
    qdf_trace_msg(0x51u, 2u, v33, v13, v14, v15, v16, v17, v18, v19, v20, v34);
    return 16;
  }
  v21 = pdev_obj;
  v22 = reg_get_pdev_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !v22 )
  {
    v33 = "%s: pdev reg component is NULL";
    v34 = "reg_get_band";
    goto LABEL_7;
  }
  v23 = v22;
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: get band bitmap: %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "reg_get_band",
    *(unsigned int *)(v22 + 56756));
  if ( (*(_BYTE *)(v23 + 56756) & 4) != 0 )
  {
    v35 = (_WORD *)(a2 + 1534);
    v36 = -60;
    v37 = v21 + 19660;
    do
    {
      v38 = (unsigned __int16 *)(v37 + 36LL * (unsigned __int16)reg_convert_enum_to_6g_idx((int)v36 + 102));
      v39 = v38[11];
      v40 = v38[2171];
      v41 = v38[4331];
      if ( v39 <= v40 )
        v42 = v40;
      else
        v42 = v39;
      if ( v40 )
        v39 = v42;
      if ( v39 <= v41 )
        v43 = v41;
      else
        v43 = v39;
      if ( v41 )
        v44 = v43;
      else
        v44 = v39;
      v45 = __CFADD__(v36++, 1);
      *v35 = v44;
      v35 += 18;
    }
    while ( !v45 );
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: 6GHz band disabled",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "reg_update_max_bw_6ghz_chan");
    return 11;
  }
}
