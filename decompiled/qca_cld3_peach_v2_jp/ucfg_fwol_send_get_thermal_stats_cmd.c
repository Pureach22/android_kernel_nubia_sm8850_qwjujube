__int64 __fastcall ucfg_fwol_send_get_thermal_stats_cmd(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 psoc_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD *v17; // x24
  __int64 v18; // x0
  unsigned int v19; // w23
  __int64 v20; // x0
  __int64 v21; // x5
  _DWORD *v22; // x8
  const char *v24; // x2
  const char *v25; // x3

  psoc_obj = fwol_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v24 = "%s: Failed to get FWOL Obj";
    v25 = "ucfg_fwol_send_get_thermal_stats_cmd";
LABEL_17:
    qdf_trace_msg(0x66u, 2u, v24, v9, v10, v11, v12, v13, v14, v15, v16, v25);
    return 4;
  }
  v17 = (_QWORD *)psoc_obj;
  v18 = fwol_get_psoc_obj(a1);
  if ( !v18 )
  {
    v24 = "%s: Failed to get fwol obj";
    v25 = "ucfg_fwol_get_thermal_temp";
    goto LABEL_17;
  }
  v19 = *(unsigned __int8 *)(v18 + 92);
  v20 = fwol_get_psoc_obj(a1);
  if ( !v20 )
  {
    v24 = "%s: Failed to get fwol obj";
    v25 = "ucfg_fwol_get_cap";
    goto LABEL_17;
  }
  v21 = *(unsigned __int8 *)(v20 + 1440);
  if ( !v19 || (v21 & 1) == 0 )
  {
    qdf_trace_msg(
      0x66u,
      2u,
      "%s: Command Disabled in Ini gThermalStatsTempOffset %d or not enabled in FW %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "ucfg_fwol_send_get_thermal_stats_cmd",
      v19,
      v21);
    return 4;
  }
  if ( a3 && a4 )
  {
    v17[167] = a3;
    v17[168] = a4;
  }
  v22 = (_DWORD *)v17[174];
  if ( !v22 )
    return 4;
  if ( *(v22 - 1) != 391788874 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v22)(a1, a2, v19);
}
