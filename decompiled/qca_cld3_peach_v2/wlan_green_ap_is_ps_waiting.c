bool __fastcall wlan_green_ap_is_ps_waiting(
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

  if ( !a1 )
  {
    v11 = "%s: pdev context passed is NULL";
LABEL_8:
    qdf_trace_msg(0x5Du, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_green_ap_is_ps_waiting");
    return 1;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !comp_private_obj )
  {
    v11 = "%s: green ap context obtained is NULL";
    goto LABEL_8;
  }
  return *(_DWORD *)(comp_private_obj + 24) == 3 && *(_BYTE *)(comp_private_obj + 8);
}
