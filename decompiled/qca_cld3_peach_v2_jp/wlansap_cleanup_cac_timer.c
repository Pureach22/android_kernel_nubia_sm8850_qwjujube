_QWORD *__fastcall wlansap_cleanup_cac_timer(
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
  _QWORD *result; // x0
  _QWORD *v11; // x20
  const char *v12; // x2
  unsigned int v13; // w1

  if ( a1 )
  {
    result = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
    if ( result )
    {
      if ( !*((_BYTE *)result + 14809) )
        return result;
      *((_BYTE *)result + 14809) = 0;
      if ( (*(_BYTE *)(a1 + 1627) & 1) == 0 )
      {
        v11 = result;
        qdf_mc_timer_stop((__int64)(result + 1830));
        qdf_mc_timer_destroy((__int64)(v11 + 1830));
      }
      v12 = "%s: sapdfs, force cleanup running dfs cac timer";
    }
    else
    {
      v12 = "%s: Invalid MAC context";
    }
    v13 = 2;
  }
  else
  {
    v12 = "%s: Invalid SAP context";
    v13 = 8;
  }
  return (_QWORD *)qdf_trace_msg(0x39u, v13, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlansap_cleanup_cac_timer");
}
