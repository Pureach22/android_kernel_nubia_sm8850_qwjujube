__int64 __fastcall ucfg_action_oui_send(
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
  __int64 v10; // x19
  unsigned int i; // w20
  unsigned int v12; // w23
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: psoc is NULL";
LABEL_9:
    qdf_trace_msg(0x63u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_action_oui_send");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Cu);
  if ( !comp_private_obj )
  {
    v13 = "%s: psoc priv is NULL";
    goto LABEL_9;
  }
  v10 = comp_private_obj;
  for ( i = 0; i != 19; ++i )
  {
    v12 = action_oui_send(v10, i, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( v12 )
      qdf_trace_msg(0x63u, 8u, "%s: Failed to send: %u", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_action_oui_send", i);
  }
  return v12;
}
