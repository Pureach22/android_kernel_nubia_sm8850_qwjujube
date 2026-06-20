__int64 __fastcall hdd_config_ani(
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
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 result; // x0
  __int64 v13; // x8
  const char *v14; // x2
  unsigned int v15; // w20
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  unsigned int v26; // w19

  v10 = *(_QWORD *)(a2 + 600);
  if ( !v10 )
    return 0;
  v11 = *(unsigned __int8 *)(v10 + 4);
  if ( v11 >= 2 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: invalid ani_setting_type %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_config_ani",
      *(unsigned __int8 *)(v10 + 4));
    return 4294967274LL;
  }
  v13 = *(_QWORD *)(a2 + 608);
  if ( !v11 && v13 )
  {
    v14 = "%s: Not support to set ani level in QCA_WLAN_ANI_SETTING_AUTO";
LABEL_8:
    qdf_trace_msg(0x33u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_ani");
    return 4294967274LL;
  }
  if ( v11 == 1 )
  {
    if ( !v13 )
    {
      v14 = "%s: invalid ani_level_attr";
      goto LABEL_8;
    }
    v15 = *(_DWORD *)(v13 + 4);
    v16 = a1;
  }
  else
  {
    v16 = a1;
    v15 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: ani_setting_type %u, ani_level %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_config_ani",
    v11,
    v15);
  LODWORD(result) = wma_cli_set_command(*(unsigned __int8 *)(v16 + 8), 37, v11 ^ 1, 2);
  if ( (_DWORD)result )
  {
    v25 = "%s: Failed to set ani enable, errno %d";
LABEL_17:
    v26 = result;
    qdf_trace_msg(0x33u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "hdd_config_ani", (unsigned int)result);
    return v26;
  }
  if ( v11 != 1 )
    return 0;
  result = wma_cli_set_command(*(unsigned __int8 *)(v16 + 8), 40, v15, 2);
  if ( (_DWORD)result )
  {
    v25 = "%s: Failed to set ani level, errno %d";
    goto LABEL_17;
  }
  return result;
}
