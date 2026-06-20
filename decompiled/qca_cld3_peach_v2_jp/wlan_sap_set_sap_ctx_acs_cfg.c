__int64 __fastcall wlan_sap_set_sap_ctx_acs_cfg(
        __int64 result,
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
  __int64 v10; // x29
  __int64 v11; // x30

  if ( !result )
    return qdf_trace_msg(
             0x39u,
             2u,
             "%s: Invalid SAP pointer",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_sap_set_sap_ctx_acs_cfg",
             v10,
             v11);
  *(_QWORD *)(result + 1536) = a2 + 1136;
  return result;
}
