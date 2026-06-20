__int64 __fastcall reg_psd_2_eirp(__int64 a1, __int16 a2, unsigned __int16 a3, _WORD *a4)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _WORD *v15; // x8

  if ( !reg_get_pdev_obj(a1) )
  {
    qdf_trace_msg(0x51u, 2u, "%s: reg pdev private obj is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "reg_psd_2_eirp");
    return 16;
  }
  if ( a3 > 0x4Fu )
  {
    if ( a3 == 80 )
    {
      v15 = &unk_A2FB90;
      goto LABEL_13;
    }
    if ( a3 == 160 )
    {
      v15 = &unk_A2FB94;
      goto LABEL_13;
    }
LABEL_10:
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: Invalid input bandwidth %hd",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "reg_psd_2_eirp",
      a3);
    return 16;
  }
  if ( a3 == 20 )
  {
    v15 = &bw_to_10log10_map;
    goto LABEL_13;
  }
  if ( a3 != 40 )
    goto LABEL_10;
  v15 = &unk_A2FB8C;
LABEL_13:
  *a4 = v15[1] + a2;
  return 0;
}
