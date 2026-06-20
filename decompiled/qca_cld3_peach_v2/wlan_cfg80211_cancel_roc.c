__int64 __fastcall wlan_cfg80211_cancel_roc(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned int v13; // w0
  const char *v15; // x2

  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 216);
    if ( v11 )
    {
      v12 = *(_QWORD *)(v11 + 80);
      if ( v12 )
      {
        v13 = ucfg_p2p_roc_cancel_req(v12, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
        return qdf_status_to_os_return(v13);
      }
    }
    v15 = "%s: psoc handle is NULL";
  }
  else
  {
    v15 = "%s: invalid vdev object";
  }
  qdf_trace_msg(0x48u, 2u, v15, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_cfg80211_cancel_roc");
  return 4294967274LL;
}
