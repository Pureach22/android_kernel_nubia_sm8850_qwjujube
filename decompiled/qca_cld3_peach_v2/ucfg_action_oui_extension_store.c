__int64 __fastcall ucfg_action_oui_extension_store(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0

  if ( a2 )
  {
    result = wlan_action_oui_extension_store(a1, 27, a2);
    if ( !(_DWORD)result )
      return ucfg_action_oui_send_by_id(a1, 27);
  }
  else
  {
    qdf_trace_msg(0x63u, 2u, "%s: oui_ext is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_action_oui_extension_store");
    return 4;
  }
  return result;
}
