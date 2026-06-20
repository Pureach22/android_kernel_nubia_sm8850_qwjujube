__int64 __fastcall ucfg_fwol_get_thermal_temp(__int64 a1, _QWORD *a2)
{
  __int64 psoc_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *v12; // x8
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x8
  __int64 v20; // x11

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v12 = (_QWORD *)psoc_obj;
    *a2 = v12[3];
    v14 = v12[7];
    v15 = v12[4];
    v16 = v12[5];
    a2[3] = v12[6];
    a2[4] = v14;
    a2[1] = v15;
    a2[2] = v16;
    v18 = v12[10];
    v17 = v12[11];
    v20 = v12[8];
    v19 = v12[9];
    a2[7] = v18;
    a2[8] = v17;
    a2[5] = v20;
    a2[6] = v19;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Failed to get fwol obj",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ucfg_fwol_get_thermal_temp");
    return 16;
  }
}
