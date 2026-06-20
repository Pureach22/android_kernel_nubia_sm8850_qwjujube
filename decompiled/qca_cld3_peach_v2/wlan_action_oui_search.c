__int64 __fastcall wlan_action_oui_search(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v12; // w0
  const char *v13; // x2
  __int64 comp_private_obj; // x0

  if ( !a1 || !a2 )
  {
    v13 = "%s: Invalid psoc or search attrs";
LABEL_6:
    qdf_trace_msg(0x63u, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_action_oui_search");
    v12 = 0;
    return v12 & 1;
  }
  if ( a3 < 0x1C )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
    if ( comp_private_obj )
    {
      v12 = action_oui_search(comp_private_obj, a2, a3);
      return v12 & 1;
    }
    v13 = "%s: psoc priv is NULL";
    goto LABEL_6;
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
    "wlan_action_oui_search",
    a3);
  v12 = 0;
  return v12 & 1;
}
