__int64 __fastcall ucfg_fwol_get_all_allowlist_params(__int64 a1, _QWORD *a2)
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
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x8
  __int64 v23; // x11

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v12 = (_QWORD *)psoc_obj;
    *a2 = v12[12];
    v14 = v12[16];
    v15 = v12[13];
    v16 = v12[14];
    a2[3] = v12[15];
    a2[4] = v14;
    a2[1] = v15;
    a2[2] = v16;
    v17 = v12[20];
    v18 = v12[17];
    v19 = v12[18];
    a2[7] = v12[19];
    a2[8] = v17;
    a2[5] = v18;
    a2[6] = v19;
    v21 = v12[23];
    v20 = v12[24];
    v23 = v12[21];
    v22 = v12[22];
    a2[11] = v21;
    a2[12] = v20;
    a2[9] = v23;
    a2[10] = v22;
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
      "ucfg_fwol_get_all_allowlist_params");
    return 16;
  }
}
