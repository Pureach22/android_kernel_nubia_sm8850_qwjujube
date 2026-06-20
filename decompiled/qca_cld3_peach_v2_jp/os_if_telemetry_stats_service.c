__int64 __fastcall os_if_telemetry_stats_service(__int64 a1, __int64 a2, unsigned int a3)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  unsigned int v14; // w20
  const char *v15; // x2
  __int64 v16; // x4
  unsigned int v17; // w21
  unsigned int v18; // w22
  __int64 v19; // [xsp+8h] [xbp-28h] BYREF
  __int64 v20; // [xsp+10h] [xbp-20h]
  __int64 v21; // [xsp+18h] [xbp-18h]
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( (unsigned int)_nla_parse(&v19, 3, a2, a3, &stats_service_policy, 31, 0) )
  {
    v12 = "%s: Invalid attr";
LABEL_3:
    qdf_trace_msg(0x48u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "os_if_telemetry_stats_service");
LABEL_4:
    result = 4;
    goto LABEL_5;
  }
  if ( v20 )
  {
    v14 = *(unsigned __int8 *)(v20 + 4);
    if ( v14 >= 3 )
    {
      v15 = "%s: Invalid stats policy type: %d";
      v16 = *(unsigned __int8 *)(v20 + 4);
LABEL_17:
      qdf_trace_msg(0x48u, 2u, v15, v4, v5, v6, v7, v8, v9, v10, v11, "os_if_telemetry_stats_service", v16);
      goto LABEL_4;
    }
  }
  else
  {
    v14 = 0;
  }
  if ( v21 )
  {
    v17 = *(unsigned __int8 *)(v21 + 4);
    if ( v17 >= 2 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid action: %d expected: %d or %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "os_if_telemetry_stats_service",
        *(unsigned __int8 *)(v21 + 4),
        0,
        1);
      goto LABEL_4;
    }
  }
  else
  {
    v17 = 0;
  }
  if ( v22 )
  {
    v18 = *(_DWORD *)(v22 + 4);
    if ( !v18 )
    {
      v15 = "%s: Invalid periodicity: %u";
      v16 = 0;
      goto LABEL_17;
    }
  }
  else
  {
    if ( !v14 )
    {
      v12 = "%s: Periodicity field (Mandatory) missing";
      goto LABEL_3;
    }
    v18 = 0;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: spt: %d action: %d periodicity: %u",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "os_if_telemetry_stats_service",
    v14,
    v17,
    v18);
  if ( v14 - 1 >= 2 )
  {
    if ( v17 )
      ucfg_telemetry_stop_opm_stats(a1);
    else
      ucfg_telemetry_start_opm_stats(a1, v18);
  }
  else
  {
    ucfg_dp_flow_stats_policy(v14, v17);
  }
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
