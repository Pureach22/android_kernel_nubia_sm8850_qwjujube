__int64 __fastcall wlan_regulatory_psoc_obj_destroyed_notification(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  __int64 v31; // x20

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xDu);
    if ( comp_private_obj )
    {
      v19 = comp_private_obj;
      *(_QWORD *)(comp_private_obj + 91120) = 0;
      v20 = wlan_objmgr_psoc_component_obj_detach(a1, 0xDu, comp_private_obj);
      if ( v20 )
      {
        v29 = jiffies;
        if ( wlan_regulatory_psoc_obj_destroyed_notification___last_ticks_6 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            2u,
            "%s: psoc_priv_obj private obj detach failed",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "wlan_regulatory_psoc_obj_destroyed_notification");
          wlan_regulatory_psoc_obj_destroyed_notification___last_ticks_6 = v29;
        }
      }
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: reg psoc obj detached",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_regulatory_psoc_obj_destroyed_notification");
      _qdf_minidump_remove(v19, 93992, "psoc_regulatory");
      _qdf_mem_free(v19);
      return v20;
    }
  }
  else
  {
    qdf_trace_msg(0x51u, 1u, "%s: psoc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "reg_get_psoc_obj");
  }
  v31 = jiffies;
  if ( wlan_regulatory_psoc_obj_destroyed_notification___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: NULL reg psoc priv obj",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_regulatory_psoc_obj_destroyed_notification");
    wlan_regulatory_psoc_obj_destroyed_notification___last_ticks = v31;
  }
  return 5;
}
