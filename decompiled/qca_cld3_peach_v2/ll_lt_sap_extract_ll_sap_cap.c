__int64 __fastcall ll_lt_sap_extract_ll_sap_cap(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 comp_private_obj; // x0
  __int64 v12; // x20
  __int64 result; // x0
  const char *v14; // x2

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
    if ( comp_private_obj )
    {
      v12 = comp_private_obj;
      result = wmi_service_enabled(v10, 0x132u, a2, a3, a4, a5, a6, a7, a8, a9);
      *(_BYTE *)(v12 + 209) = result & 1;
      *(_BYTE *)(v12 + 210) = 1;
      return result;
    }
    v14 = "%s: Invalid psoc ll sap priv obj";
  }
  else
  {
    v14 = "%s: Invalid WMI handle";
  }
  return qdf_trace_msg(0xA1u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "ll_lt_sap_extract_ll_sap_cap");
}
