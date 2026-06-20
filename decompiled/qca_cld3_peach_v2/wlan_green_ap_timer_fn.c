__int64 __fastcall wlan_green_ap_timer_fn(
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
  const char *v11; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
    if ( comp_private_obj )
      return wlan_green_ap_state_mc(
               (__int64 *)comp_private_obj,
               *(_DWORD *)(comp_private_obj + 28),
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9);
    v11 = "%s: green ap context obtained is NULL";
  }
  else
  {
    v11 = "%s: pdev context passed is NULL";
  }
  return qdf_trace_msg(0x5Du, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_green_ap_timer_fn");
}
