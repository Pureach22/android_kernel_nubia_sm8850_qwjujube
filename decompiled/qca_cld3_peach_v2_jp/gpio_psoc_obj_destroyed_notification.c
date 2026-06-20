__int64 __fastcall gpio_psoc_obj_destroyed_notification(
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
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( a1 && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x27u)) != 0 )
  {
    v11 = comp_private_obj;
    v12 = wlan_objmgr_psoc_component_obj_detach(a1, 0x27u, comp_private_obj);
    if ( v12 )
      qdf_trace_msg(
        0x7Au,
        2u,
        "%s: gpio_obj detach failed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "gpio_psoc_obj_destroyed_notification");
    _qdf_mem_free(v11);
    return v12;
  }
  else
  {
    qdf_trace_msg(
      0x7Au,
      2u,
      "%s: gpio_obj is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "gpio_psoc_obj_destroyed_notification");
    return 5;
  }
}
