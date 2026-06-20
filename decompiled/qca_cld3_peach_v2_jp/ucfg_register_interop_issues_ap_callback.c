__int64 __fastcall ucfg_register_interop_issues_ap_callback(
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
  __int64 v10; // x0
  __int64 result; // x0
  const char *v13; // x2

  v10 = *(_QWORD *)(a1 + 80);
  if ( v10 )
  {
    result = wlan_objmgr_psoc_get_comp_private_obj(v10, 0x1Fu);
    if ( result )
    {
      *(_QWORD *)(result + 24) = *a2;
      return result;
    }
    v13 = "%s: interop issues ap priv obj is NULL";
  }
  else
  {
    v13 = "%s: psoc object is NULL";
  }
  return qdf_trace_msg(0x6Cu, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_register_interop_issues_ap_callback");
}
