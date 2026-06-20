__int64 __fastcall wlan_action_oui_is_empty(
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
  const char *v11; // x2
  __int64 comp_private_obj; // x0
  char is_empty; // w0

  if ( !a1 )
  {
    v11 = "%s: Invalid psoc";
LABEL_8:
    qdf_trace_msg(0x63u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_action_oui_is_empty");
    goto LABEL_9;
  }
  if ( a2 >= 0x1C )
  {
    qdf_trace_msg(
      0x63u,
      2u,
      "%s: Invalid action_oui id: %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_action_oui_is_empty",
      a2);
LABEL_9:
    is_empty = 1;
    return is_empty & 1;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    v11 = "%s: psoc priv is NULL";
    goto LABEL_8;
  }
  is_empty = action_oui_is_empty(comp_private_obj, a2);
  return is_empty & 1;
}
