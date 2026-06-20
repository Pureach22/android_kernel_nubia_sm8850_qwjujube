__int64 __fastcall wlan_action_oui_extension_store(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v12; // x2
  __int64 comp_private_obj; // x0
  __int64 v15; // x19
  __int64 v16; // x21

  if ( !a1 )
  {
    v12 = "%s: Invalid psoc";
LABEL_10:
    qdf_trace_msg(0x63u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_action_oui_extension_store");
    return 4;
  }
  if ( a2 < 0x1C )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
    if ( comp_private_obj )
    {
      v15 = *(_QWORD *)(comp_private_obj + 8LL * a2 + 23544);
      if ( v15 )
      {
        v16 = comp_private_obj;
        wlan_action_oui_extension_dump(a3);
        return action_oui_extension_store(v16, v15, a3);
      }
      v12 = "%s: action oui priv not allocated";
    }
    else
    {
      v12 = "%s: psoc priv is NULL";
    }
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x63u,
    2u,
    "%s: Invalid action_oui id: %u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_action_oui_extension_store",
    a2);
  return 4;
}
