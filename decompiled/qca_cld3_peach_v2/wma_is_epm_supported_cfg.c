__int64 __fastcall wma_is_epm_supported_cfg(__int64 a1)
{
  __int64 values; // x0
  unsigned int v2; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  values = cfg_psoc_get_values(*(_QWORD *)(a1 + 24));
  v2 = *(unsigned __int8 *)(values + 4000);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: EPM enable feature cfg value: %d",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wma_is_epm_supported_cfg",
    *(unsigned __int8 *)(values + 4000));
  return v2;
}
