bool __fastcall wlan_sap_get_ch_params(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x9

  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 1508);
    *a2 = *(_QWORD *)(a1 + 1500);
    a2[1] = v11;
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid SAP pointer", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_sap_get_ch_params");
  }
  return a1 != 0;
}
