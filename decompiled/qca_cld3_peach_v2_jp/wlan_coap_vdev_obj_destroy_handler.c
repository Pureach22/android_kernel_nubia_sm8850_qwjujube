__int64 __fastcall wlan_coap_vdev_obj_destroy_handler(
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
  __int64 v11; // x19
  const char *v13; // x2

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x30u);
    if ( comp_private_obj )
    {
      v11 = comp_private_obj;
      wlan_objmgr_vdev_component_obj_detach(a1, 0x30u, comp_private_obj);
      _qdf_mem_free(v11);
      return 0;
    }
    v13 = "%s: coap_priv NULL";
  }
  else
  {
    v13 = "%s: Vdev NULL";
  }
  qdf_trace_msg(0x9Cu, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_coap_vdev_obj_destroy_handler");
  return 4;
}
