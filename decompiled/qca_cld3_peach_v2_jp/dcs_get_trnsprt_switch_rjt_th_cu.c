__int64 __fastcall dcs_get_trnsprt_switch_rjt_th_cu(
        __int64 a1,
        unsigned __int8 a2,
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
  const char *v12; // x2
  __int64 v14; // x8

  if ( !a1 )
  {
    v12 = "%s: psoc is null";
LABEL_7:
    qdf_trace_msg(0x74u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_dcs_get_pdev_private_obj");
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( !comp_private_obj )
  {
    v12 = "%s: dcs psoc object is null";
    goto LABEL_7;
  }
  if ( a2 < 3u )
  {
    v14 = comp_private_obj + 384LL * a2;
    if ( v14 )
      return *(unsigned int *)(v14 + 24);
  }
  else
  {
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
  }
LABEL_8:
  qdf_trace_msg(
    0x74u,
    2u,
    "%s: dcs pdev private object is null",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dcs_get_trnsprt_switch_rjt_th_cu");
  return 0;
}
