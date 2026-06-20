__int64 __fastcall wlan_dcs_get_pdev_private_obj(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: psoc is null";
LABEL_7:
    qdf_trace_msg(0x74u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dcs_get_pdev_private_obj");
    return 0;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( !comp_private_obj )
  {
    v13 = "%s: dcs psoc object is null";
    goto LABEL_7;
  }
  if ( a2 < 3 )
    return comp_private_obj + 384LL * a2;
  qdf_trace_msg(
    0x74u,
    2u,
    "%s: invalid pdev_id: %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_dcs_get_pdev_private_obj",
    a2);
  return 0;
}
