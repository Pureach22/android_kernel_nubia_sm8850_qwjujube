__int64 __fastcall hdd_config_fine_time_measurement(unsigned __int8 *a1, __int64 a2)
{
  unsigned int v2; // w19
  _QWORD *v4; // x22
  unsigned int v5; // w20
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v2 = *(_DWORD *)(a2 + 4);
  v4 = *(_QWORD **)(*(_QWORD *)a1 + 24LL);
  v5 = *((_DWORD *)v4 + 362);
  v6 = ucfg_mlme_set_fine_time_meas_cap(*v4, v5 & v2);
  if ( v6 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to set value, status %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_config_fine_time_measurement",
      v6);
    return 4294967274LL;
  }
  else
  {
    sme_update_fine_time_measurement_capab(v4[2], a1[8], v5 & v2);
    ucfg_wifi_pos_set_ftm_cap(*v4, v5 & v2);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: user: 0x%x, target: 0x%x, final: 0x%x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_config_fine_time_measurement",
      v2,
      v5,
      v5 & v2);
    return 0;
  }
}
