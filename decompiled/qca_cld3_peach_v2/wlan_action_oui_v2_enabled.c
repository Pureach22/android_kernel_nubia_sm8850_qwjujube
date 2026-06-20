__int64 __fastcall wlan_action_oui_v2_enabled(
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
  char action_oui_v2_cap; // w0
  const char *v11; // x2

  if ( !a1 )
  {
    v11 = "%s: Invalid psoc";
LABEL_7:
    qdf_trace_msg(0x63u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_action_oui_v2_enabled");
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    v11 = "%s: psoc priv is NULL";
    goto LABEL_7;
  }
  if ( *(_BYTE *)(comp_private_obj + 8) != 2 )
  {
LABEL_8:
    action_oui_v2_cap = 0;
    return action_oui_v2_cap & 1;
  }
  action_oui_v2_cap = target_if_get_action_oui_v2_cap(*(_QWORD *)comp_private_obj);
  return action_oui_v2_cap & 1;
}
