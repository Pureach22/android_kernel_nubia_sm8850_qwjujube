void *__fastcall wlan_psoc_set_phy_config(
        __int64 a1,
        const void *a2,
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
  const char *v14; // x3

  if ( a2 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0);
    if ( comp_private_obj )
      return qdf_mem_copy((void *)(comp_private_obj + 2016), a2, 4u);
    v13 = "%s: PSOC MLME component object is NULL";
    v14 = "wlan_psoc_mlme_get_cmpt_obj";
  }
  else
  {
    v13 = "%s: phy_config is NUll";
    v14 = "wlan_psoc_set_phy_config";
  }
  return (void *)qdf_trace_msg(0x68u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, v14);
}
