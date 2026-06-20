__int64 __fastcall hdd_set_power_config(
        _QWORD *a1,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v11; // x2
  unsigned int v12; // w1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  unsigned int v24; // w4
  unsigned int v25; // w19
  __int64 result; // x0

  if ( (*(_DWORD *)(a2 + 40) | 2) == 2 )
  {
    if ( *a3 >= 3 )
    {
      v11 = "%s: invalid power value: %d";
LABEL_12:
      v12 = 2;
      goto LABEL_13;
    }
    if ( (unsigned __int8)ucfg_pmo_get_max_ps_poll(*a1) )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Disable advanced power save since max ps poll is enabled",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_set_power_config");
      *a3 = 0;
      v23 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL);
    }
    else
    {
      v24 = *a3;
      v23 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL);
      if ( *a3 < 3 )
      {
LABEL_10:
        result = wma_set_power_config(v23, v24);
        if ( !(_DWORD)result )
          return result;
        v11 = "%s: failed to configure power: %d";
        goto LABEL_12;
      }
      v25 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid opm_mode: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_convert_opm_mode");
      v23 = v25;
    }
    v24 = 0;
    goto LABEL_10;
  }
  v11 = "%s: Advanced power save only allowed in STA/P2P-Client modes:%d";
  v12 = 4;
LABEL_13:
  qdf_trace_msg(0x33u, v12, v11, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_set_power_config");
  return 4294967274LL;
}
