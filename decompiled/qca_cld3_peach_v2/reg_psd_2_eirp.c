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
  __int64 result; // x0

  if ( !reg_get_pdev_obj(a1) )
  {
    qdf_trace_msg(0x51u, 2u, "%s: reg pdev private obj is NULL", v7, v8, v9, v10, v11, v12, v13, v14, "reg_psd_2_eirp");
    return 16;
  }
  if ( a3 <= 0x8Bu )
  {
    if ( a3 <= 0x3Bu )
    {
      if ( a3 == 20 )
      {
        v15 = &bw_to_10log10_map;
        goto LABEL_28;
      }
      if ( a3 == 40 )
      {
        v15 = &unk_AD2350;
        goto LABEL_28;
      }
    }
    else
    {
      switch ( a3 )
      {
        case '<':
          v15 = &unk_AD2360;
          goto LABEL_28;
        case 'P':
          v15 = &unk_AD2354;
          goto LABEL_28;
        case 'x':
          v15 = &unk_AD2368;
          goto LABEL_28;
      }
    }
LABEL_30:
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
  if ( a3 > 0xEFu )
  {
    switch ( a3 )
    {
      case 0xF0u:
        v15 = &unk_AD2370;
        goto LABEL_28;
      case 0x118u:
        v15 = &unk_AD2374;
        goto LABEL_28;
      case 0x140u:
        v15 = &unk_AD235C;
        goto LABEL_28;
    }
    goto LABEL_30;
  }
  if ( a3 == 140 )
  {
    v15 = &unk_AD2364;
    goto LABEL_28;
  }
  if ( a3 == 160 )
  {
    v15 = &unk_AD2358;
    goto LABEL_28;
  }
  if ( a3 != 200 )
    goto LABEL_30;
  v15 = &unk_AD236C;
LABEL_28:
  result = 0;
  *a4 = v15[1] + a2;
  return result;
}
