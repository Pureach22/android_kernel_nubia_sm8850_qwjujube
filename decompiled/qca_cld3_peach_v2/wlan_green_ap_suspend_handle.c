__int64 __fastcall wlan_green_ap_suspend_handle(
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
  __int64 comp_private_obj; // x0
  __int64 v11; // x20
  __int64 result; // x0
  const char *v13; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
    if ( comp_private_obj )
    {
      v11 = comp_private_obj;
      result = wlan_green_ap_stop(a1, a2, a3, a4, a5, a6, a7, a8, a9);
      *(_BYTE *)(v11 + 8) = 2;
      return result;
    }
    v13 = "%s: green ap context obtained is NULL";
  }
  else
  {
    v13 = "%s: pdev context passed is NULL";
  }
  return qdf_trace_msg(0x5Du, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_green_ap_suspend_handle");
}
