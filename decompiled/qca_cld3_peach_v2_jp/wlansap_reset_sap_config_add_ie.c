__int64 __fastcall wlansap_reset_sap_config_add_ie(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  if ( !a1 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid Config pointer",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlansap_reset_sap_config_add_ie");
    return 5;
  }
  if ( a2 > 2 )
  {
    if ( a2 == 3 )
      goto LABEL_12;
    if ( a2 != 6 )
      goto LABEL_5;
  }
  else
  {
    if ( a2 == 1 )
      goto LABEL_15;
    if ( a2 != 2 )
    {
LABEL_5:
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Invalid buffer type %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlansap_reset_sap_config_add_ie",
        (unsigned int)a2);
      return 0;
    }
  }
  v13 = *(_QWORD *)(a1 + 1752);
  if ( v13 )
  {
    _qdf_mem_free(v13);
    *(_WORD *)(a1 + 1744) = 0;
    *(_QWORD *)(a1 + 1752) = 0;
  }
  if ( a2 != 6 )
    return 0;
LABEL_12:
  v14 = *(_QWORD *)(a1 + 1768);
  if ( v14 )
  {
    _qdf_mem_free(v14);
    *(_WORD *)(a1 + 1760) = 0;
    *(_QWORD *)(a1 + 1768) = 0;
  }
  if ( a2 != 6 )
    return 0;
LABEL_15:
  result = *(_QWORD *)(a1 + 1784);
  if ( result )
  {
    _qdf_mem_free(result);
    *(_WORD *)(a1 + 1776) = 0;
    *(_QWORD *)(a1 + 1784) = 0;
    return 0;
  }
  return result;
}
